#include "pch.h"
#include "hook.h"

Hooks hook;

Hooks::Hooks() {}
Hooks::~Hooks() {}

static std::unordered_map<ENameID, uint64_t*> g_MasmTrampolineTargets =
{
    //{ ENameID::placeholder, &g_FuncNamePlaceholder_Original },
};

void Hooks::createHook(const ENameID& id, uint64_t funcToHook, uint64_t detour)
{
    expectedHookCount++;
    if (!funcToHook)
    {
		Logger::AddLog(std::format("Tried creating hook for {} but pattern returned null. Skipping creation...", ENameIDStrings.at(static_cast<size_t>(id))), true);
        return;
    }
    if (hooks.contains(id))
    {
        Logger::AddLog(std::format("Tried creating hook for {} but it already existed. Skipping creation...", ENameIDStrings.at(static_cast<size_t>(id))), true);
        return;
    }
    hooks[id] = Hook();

	uint64_t* original = &hooks[id].original;
    //if this hook has a MASM stub, let PolyHook write directly to the masm global instead :)
    if (auto it = g_MasmTrampolineTargets.find(id); it != g_MasmTrampolineTargets.end())
        original = it->second;

    this->hooks[id].detour = new PLH::x64Detour(funcToHook, detour, original);
    Logger::AddLog(std::format("Hook entry created for \"{}\"", ENameIDStrings.at(static_cast<size_t>(id))));
}

void Hooks::applyHooks()
{
    int hookCount = 0;
    for (auto& [id, hookInfo] : hooks)
    {
        if (hookInfo.detour && hookInfo.detour->hook())
            hookCount++;
        else
            Logger::AddLog(std::format("Failed to apply hook for \"{}\"", ENameIDStrings.at(static_cast<size_t>(id))), true);
    }
    Logger::AddLog(std::format("Applied {}/{} hooks successfully.", hookCount, expectedHookCount));
}

void Hooks::removeHooks()
{
    for (auto& [name, hookInfo] : hooks)
    {
        if (hookInfo.detour && hookInfo.detour->isHooked())
            hookInfo.detour->unHook();
        delete hookInfo.detour;
    }
    hooks.clear();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void __fastcall SetupMusicBanger_Hook(GameManager* gm, bool loop, void* method)
{
    hook.GetOriginal<tSetupMusicBanger>(ENameID::SetupMusicBanger)(gm, loop, method);
}
PlayerOptionsData* __fastcall PlayerOptionsGetConfig_Hook(PlayerOptions* playerOptions, void* method)
{
    PlayerOptionsData* result = hook.GetOriginal<tPlayerOptionsGetConfig>(ENameID::GetConfig)(playerOptions, method);
    game::playerOptionsConfig = result;
    return result;
}
void __fastcall CharacterController_OnUpdate_Hook(CharacterController* characterController, void* method)
{
    hook.GetOriginal<tCharacterController_OnUpdate>(ENameID::CharacterController_OnUpdate)(characterController, method);
    game::isGameActive = true;
}
void __fastcall CharacterController_TakeDamage_Hook(CharacterController* characterController, float damageAmount, void* method)
{
    if (game::ToggleGodMode && damageAmount > 0.0f)
        damageAmount = 0.0f;
    hook.GetOriginal<tCharacterController_TakeDamage>(ENameID::CharacterController_TakeDamage)(characterController, damageAmount, method);
}
void __fastcall EnemyController_OnUpdate_Hook(EnemyController* enemyController, void* method)
{
	//handles ~99% of cases for one-shot kills.. other ~1% is handled in EnemyController_GetDamaged
    if (game::ToggleOneShotKills && enemyController && !enemyController->isDead && enemyController->hp > 0.0f)
        enemyController->hp = 0.0f;
    hook.GetOriginal<tEnemyController_OnUpdate>(ENameID::EnemyController_OnUpdate)(enemyController, method);
}
void __fastcall EnemyController_GetDamaged_Hook(EnemyController* enemyController, float value, int showHitVfx, float damageKb, int damageType, bool hasKb, void* method)
{
	//handles some edge cases for some enemy types
    if (game::ToggleOneShotKills && enemyController && !enemyController->isDead)
        enemyController->hp = 0.0f;//some psuedocode for what will happen now: v20 = hp - 'value'; if (v20 <= 0.0f) die();  :)
    hook.GetOriginal<tEnemyController_GetDamaged>(ENameID::EnemyController_GetDamaged)(enemyController, value, showHitVfx, damageKb, damageType, hasKb, method);
}
void __fastcall MagnetZone_RefreshSize_Hook(MagnetZone* magnetZone, void* method)
{
    hook.GetOriginal<tMagnetRefresh>(ENameID::MagnetZone_RefreshSize)(magnetZone, method);
}
void __fastcall ResetOrthographicAndRenderTextureSize_Hook(void* camera, void* method)
{
    hook.GetOriginal<tResetOrthographicAndRenderTextureSize>(ENameID::ResetOrthoAndRtSize)(camera, method);
}
void __fastcall SetOrthographicSize_Hook(void* camera, float value, void* method)
{
    if (game::wantCameraZoomChange)
    {
        game::wantCameraZoomChange = false;
        value = game::desiredCamZoom;
    }
    hook.GetOriginal<tSetOrthographicSize>(ENameID::SetOrthographicSize)(camera, value, method);
}
void* __fastcall GetMainCamera_Hook(void* method)
{
    return hook.GetOriginal<tGetMainCamera>(ENameID::GetMainCamera)(method);
}
void __fastcall ResetGameSession_Hook(GameManager* gm, bool disconnectFromCoherence, void* method)
{
    hook.GetOriginal<tResetGameSession>(ENameID::ResetGameSession)(gm, disconnectFromCoherence, method);
    game::isGameActive = false;
    game::disableMusicController = !game::songListAvailable;
    game::RemoveAllControllersButLocal();
    Logger::AddLog("Game session has ended.");
}
void __fastcall StageInit_Hook(GameManager* gm, StageType stageType, void* method)
{
    game::desiredCamZoom = game::defaultCameraZoomScaling;
    game::wantCameraZoomChange = true;
    hook.GetOriginal<tStageInit>(ENameID::StageInit)(gm, stageType, method);
    game::isGameActive = true;
    Logger::AddLog("Stage has been initialized.");
}
//updates only when in a stage
void __fastcall GameManager_OnUpdate_Hook(GameManager* gm, void* method)
{
    hook.GetOriginal<tGameManager_OnUpdate>(ENameID::GameManager_OnUpdate)(gm, method);
    game::RefreshControllerMap(gm);//logic inside runs every 1 second
    //once in game then can permanently unlock the music controller (if songs available) cause can't use SetupMusicBanger() until GameManager is setup at least once
    game::disableMusicController = !game::songListAvailable;
    game::isGameActive = true;
}
void __fastcall MainMenuPage_OnUpdate_Hook(MainMenuPage* mmp, void* method)
{
    hook.GetOriginal<tMainMenuPage_OnUpdate>(ENameID::MainMenuPage_OnUpdate)(mmp, method);
}
void __fastcall CharacterSelectionPage_OnUpdate_Hook(CharacterSelectionPage* csp, void* method)
{
    hook.GetOriginal<tCharacterSelectionPage_OnUpdate>(ENameID::CharacterSelectionPage_OnUpdate)(csp, method);
}
void __fastcall StageSelectPage_OnUpdate_Hook(StageSelectPage* ssp, void* method)
{
    hook.GetOriginal<tStageSelectPage_OnUpdate>(ENameID::StageSelectPage_OnUpdate)(ssp, method);
    game::currentSongListIndex = game::GetVectorIndexForSongListForBgmType(game::playerOptionsConfig);
    game::currentSongModifier = game::playerOptionsConfig ? game::playerOptionsConfig->bgmModType : BgmModType::Normal;
}
void __fastcall HealthBar_OnUpdate_Hook(HealthBar* hb, void* method)
{
    hook.GetOriginal<tHealthBar_OnUpdate>(ENameID::HealthBar_OnUpdate)(hb, method);
}
void __fastcall SoundManager_StopMusic_Hook(BgmType song, void* method)
{
    hook.GetOriginal<tSoundManager_StopMusic>(ENameID::SoundManager_StopMusic)(song, method);
}
//runs every frame regardless of the game's state
void __fastcall BaseUIPage_OnUpdate_Hook(BaseUIPage* ui, void* method)
{
	hook.GetOriginal<tBaseUIPage_OnUpdate>(ENameID::BaseUIPage_OnUpdate)(ui, method);
    //if we hit this part and our config happens to not be loaded yet, go ahead and do a manual call and fetch it just in case
    if (!game::playerOptionsConfig && ui && ui->Data && ui->Data->playerOptions)
    {
        if (auto config = hook.GetOriginal<tPlayerOptionsGetConfig>(ENameID::GetConfig))
            game::playerOptionsConfig = config(ui->Data->playerOptions, nullptr);
    }
    if (ui)
		game::BuildSongList(ui->Data);//will early out if already built
    //set new song on user request in here cause itll crash if we do it in our own thread
    game::OnMusicChange();
}
void __fastcall SoundManager_UpdateSfxVolume_Hook(float volume, void* method)
{
    hook.GetOriginal<tSoundManager_UpdateSfxVolume>(ENameID::SoundManager_UpdateSfxVolume)(volume, method);
}
void __fastcall SoundManager_UpdateMusicVolume_Hook(float volume, void* method)
{
    hook.GetOriginal<tSoundManager_UpdateMusicVolume>(ENameID::SoundManager_UpdateMusicVolume)(volume, method);
}