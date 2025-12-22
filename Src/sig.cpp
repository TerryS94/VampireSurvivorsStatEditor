#include "pch.h"
#include "sig.h"

namespace sig
{
    void SetupHooks()
    {
        const std::string MagnetZone_RefreshSizePattern = "40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 43 ? 48 8b 4b ? 48 85 c0 0f 84";
        BYTE* MagnetZone_RefreshSizeAddr = FindPattern(MagnetZone_RefreshSizePattern, "GameAssembly.dll");
        hook.createHook(ENameID::MagnetZone_RefreshSize, reinterpret_cast<uint64_t>(MagnetZone_RefreshSizeAddr), reinterpret_cast<uint64_t>(&MagnetZone_RefreshSize_Hook));

        const std::string PlayerOptionsGetConfigPattern = "40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 83 7b ? ? 75 ? 48 83 7b ? ? 75 ? 48 83 7b";
        BYTE* PlayerOptionsGetConfigAddr = FindPattern(PlayerOptionsGetConfigPattern, "GameAssembly.dll");
        hook.createHook(ENameID::GetConfig, reinterpret_cast<uint64_t>(PlayerOptionsGetConfigAddr), reinterpret_cast<uint64_t>(&PlayerOptionsGetConfig_Hook));

        const std::string characterControllerOnUpdatePattern = "40 53 57 48 81 ec ? ? ? ? 80 3d ? ? ? ? ? 48 8b f9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 9f";
        BYTE* CharacterController_OnUpdateAddr = FindPattern(characterControllerOnUpdatePattern, "GameAssembly.dll");
        hook.createHook(ENameID::CharacterController_OnUpdate, reinterpret_cast<uint64_t>(CharacterController_OnUpdateAddr), reinterpret_cast<uint64_t>(&CharacterController_OnUpdate_Hook));

        const std::string ResetOrthoAndRtSizePattern = "40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 33 d2";
        BYTE* ResetOrthoAndRtSizeAddr = FindPattern(ResetOrthoAndRtSizePattern, "GameAssembly.dll");
        hook.createHook(ENameID::ResetOrthoAndRtSize, reinterpret_cast<uint64_t>(ResetOrthoAndRtSizeAddr), reinterpret_cast<uint64_t>(&ResetOrthographicAndRenderTextureSize_Hook));

        const std::string SetOrthographicSizePattern = "40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 0f 29 74 24 ? 0f 28 f1 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 0f 28 ce 48 8b cf 48 8b 7c 24 ? 0f 28 74 24 ? 48 83 c4 ? 5b 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc 40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 48 8b cf 48 8b 7c 24 ? 48 83 c4 ? 5b 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc 48 89 5c 24 ? 56 48 83 ec ? 80 3d ? ? ? ? ? 0f b6 f2 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 40 0f b6 d6 48 8b cf 48 8b 7c 24 ? 48 8b 5c 24 ? 48 83 c4 ? 5e 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc 40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 48 8b cf 48 8b 7c 24 ? 48 83 c4 ? 5b 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc 48 89 5c 24 ? 56 48 83 ec ? 80 3d ? ? ? ? ? 8b f2 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 8b d6 48 8b cf 48 8b 7c 24 ? 48 8b 5c 24 ? 48 83 c4 ? 5e 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc 40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 48 8b cf 48 8b 7c 24 ? 48 83 c4 ? 5b 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc 48 89 5c 24 ? 56 48 83 ec ? 80 3d ? ? ? ? ? 8b f2 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 85 db 74 ? 48 89 7c 24 ? 48 8b 7b ? 48 85 ff 74 ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? 8b d6 48 8b cf 48 8b 7c 24 ? 48 8b 5c 24 ? 48 83 c4 ? 5e 48 ff e0 e8 ? ? ? ? cc 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc 33 d2 48 8b cb e8 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc 48 89 5c 24";
        BYTE* SetOrthographicSizeAddr = FindPattern(SetOrthographicSizePattern, "GameAssembly.dll");
        hook.createHook(ENameID::SetOrthographicSize, reinterpret_cast<uint64_t>(SetOrthographicSizeAddr), reinterpret_cast<uint64_t>(&SetOrthographicSize_Hook));

        const std::string GetMainCameraPattern = "48 83 ec ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? ff d0 48 8b 15 ? ? ? ? 48 8b c8 48 83 c4 ? e9 ? ? ? ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc cc 48 83 ec ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 05 ? ? ? ? 48 85 c0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 85 c0 74 ? 48 89 05 ? ? ? ? ff d0 48 8b 15 ? ? ? ? 48 8b c8 48 83 c4 ? e9 ? ? ? ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 48 8b c8 33 d2 e8 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc cc 40 53 48 83 ec ? 80 3d";
        BYTE* GetMainCameraAddr = FindPattern(GetMainCameraPattern, "GameAssembly.dll");
        hook.createHook(ENameID::GetMainCamera, reinterpret_cast<uint64_t>(GetMainCameraAddr), reinterpret_cast<uint64_t>(&GetMainCamera_Hook));

        const std::string ResetGameSessionPattern = "48 89 5c 24 ? 88 54 24 ? 48 89 4c 24 ? 56 57 41 56 48 83 ec ? 44 0f b6 f2 48 8b d9";
        BYTE* ResetGameSessionAddr = FindPattern(ResetGameSessionPattern, "GameAssembly.dll");
        hook.createHook(ENameID::ResetGameSession, reinterpret_cast<uint64_t>(ResetGameSessionAddr), reinterpret_cast<uint64_t>(&ResetGameSession_Hook));

        const std::string StageInitPattern = "48 89 5c 24 ? 57 48 83 ec ? 80 3d ? ? ? ? ? 8b fa 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 8b ? ? ? ? 48 85 c9 0f 84 ? ? ? ? 45 33 c0";
        BYTE* StageInitAddr = FindPattern(StageInitPattern, "GameAssembly.dll");
        hook.createHook(ENameID::StageInit, reinterpret_cast<uint64_t>(StageInitAddr), reinterpret_cast<uint64_t>(&StageInit_Hook));

        const std::string GameManagerOnUpdatePattern = "48 8b c4 48 89 58 ? 48 89 70 ? 48 89 48 ? 57 41 56 41 57 48 81 ec ? ? ? ? 0f 29 70 ? 48 8b f1";
        BYTE* GameManagerOnUpdateAddr = FindPattern(GameManagerOnUpdatePattern, "GameAssembly.dll");
        hook.createHook(ENameID::GameManager_OnUpdate, reinterpret_cast<uint64_t>(GameManagerOnUpdateAddr), reinterpret_cast<uint64_t>(&GameManager_OnUpdate_Hook));

        const std::string SetupMusicBangerPattern = "48 89 5c 24 ? 57 48 83 ec ? 80 3d ? ? ? ? ? 0f b6 fa 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 48 8b 05 ? ? ? ? 33 d2";
        BYTE* SetupMusicBangerAddr = FindPattern(SetupMusicBangerPattern, "GameAssembly.dll");
        hook.createHook(ENameID::SetupMusicBanger, reinterpret_cast<uint64_t>(SetupMusicBangerAddr), reinterpret_cast<uint64_t>(&SetupMusicBanger_Hook));

        //both unused at the moment but works
        //const std::string MainMenuPage_OnUpdatePattern = "48 83 ec ? 48 8b 89 ? ? ? ? 48 85 c9 74 ? 48 8b 01 48 8b 90 ? ? ? ? 48 83 c4 ? 48 ff a0 ? ? ? ? e8 ? ? ? ? cc cc cc cc cc cc 40 55";
        //BYTE* MainMenuPage_OnUpdateAddr = FindPattern(MainMenuPage_OnUpdatePattern, "GameAssembly.dll");
        //hook.createHook(ENameID::MainMenuPage_OnUpdate, reinterpret_cast<uint64_t>(MainMenuPage_OnUpdateAddr), reinterpret_cast<uint64_t>(&MainMenuPage_OnUpdate_Hook));
        //
        //const std::string CharacterSelectionPage_OnUpdatePattern = "40 53 48 83 ec ? 80 3d ? ? ? ? ? 48 8b d9 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 89 6c 24 ? 33 d2 48 89 74 24 ? 48 8b cb 48 89 7c 24 ? e8 ? ? ? ? 48 8b 8b ? ? ? ? 48 85 c9";
        //BYTE* CharacterSelectionPage_OnUpdateAddr = FindPattern(CharacterSelectionPage_OnUpdatePattern, "GameAssembly.dll");
        //hook.createHook(ENameID::CharacterSelectionPage_OnUpdate, reinterpret_cast<uint64_t>(CharacterSelectionPage_OnUpdateAddr), reinterpret_cast<uint64_t>(&CharacterSelectionPage_OnUpdate_Hook));
        
        const std::string StageSelectPage_OnUpdatePattern = "40 53 48 83 ec ? 33 d2 48 8b d9 e8 ? ? ? ? 48 8b 8b ? ? ? ? 48 85 c9 0f 84 ? ? ? ? 48 8b 01";
        BYTE* StageSelectPage_OnUpdateAddr = FindPattern(StageSelectPage_OnUpdatePattern, "GameAssembly.dll");
        hook.createHook(ENameID::StageSelectPage_OnUpdate, reinterpret_cast<uint64_t>(StageSelectPage_OnUpdateAddr), reinterpret_cast<uint64_t>(&StageSelectPage_OnUpdate_Hook));

        //unused at the moment but works
        //const std::string HealthBar_OnUpdatePattern = "48 89 5c 24 ? 57 48 83 ec ? 48 8b 59 ? 48 8b 79 ? 0f 29 74 24";
        //BYTE* HealthBar_OnUpdateAddr = FindPattern(HealthBar_OnUpdatePattern, "GameAssembly.dll");
        //hook.createHook(ENameID::HealthBar_OnUpdate, reinterpret_cast<uint64_t>(HealthBar_OnUpdateAddr), reinterpret_cast<uint64_t>(&HealthBar_OnUpdate_Hook));

        const std::string EnemyController_OnUpdatePattern = "48 8b c4 48 89 58 ? 48 89 48 ? 56 57 41 56 48 81 ec ? ? ? ? 0f 29 70 ? 0f 29 78 ? 44 0f 29 40 ? 44 0f 29 48 ? 44 0f 29 50 ? 44 0f 29 58 ? 48 8b f1";
        BYTE* EnemyController_OnUpdateAddr = FindPattern(EnemyController_OnUpdatePattern, "GameAssembly.dll");
        hook.createHook(ENameID::EnemyController_OnUpdate, reinterpret_cast<uint64_t>(EnemyController_OnUpdateAddr), reinterpret_cast<uint64_t>(&EnemyController_OnUpdate_Hook));

        const std::string CharacterController_TakeDamagePattern = "40 53 56 48 83 ec ? 80 3d ? ? ? ? ? 48 8b f1 0f 29 7c 24";
        BYTE* CharacterController_TakeDamageAddr = FindPattern(CharacterController_TakeDamagePattern, "GameAssembly.dll");
        hook.createHook(ENameID::CharacterController_TakeDamage, reinterpret_cast<uint64_t>(CharacterController_TakeDamageAddr), reinterpret_cast<uint64_t>(&CharacterController_TakeDamage_Hook));

        const std::string EnemyController_GetDamagedPattern = "48 89 5c 24 ? 41 56 48 81 ec ? ? ? ? 80 3d ? ? ? ? ? 45 8b f0 0f 29 74 24 ? 48 8b d9 44 0f 29 44 24 ? 0f 28 f1 44 0f 28 c3 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05";
        BYTE* EnemyController_GetDamagedAddr = FindPattern(EnemyController_GetDamagedPattern, "GameAssembly.dll");
        hook.createHook(ENameID::EnemyController_GetDamaged, reinterpret_cast<uint64_t>(EnemyController_GetDamagedAddr), reinterpret_cast<uint64_t>(&EnemyController_GetDamaged_Hook));

		const std::string SoundManager_StopMusicPattern = "48 83 ec ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 80 3d ? ? ? ? ? 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 48 8b 0d ? ? ? ? 33 d2 48 83 c4 ? e9 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc cc cc 48 83 ec";
        BYTE* SoundManager_StopMusicAddr = FindPattern(SoundManager_StopMusicPattern, "GameAssembly.dll");
        hook.createHook(ENameID::SoundManager_StopMusic, reinterpret_cast<uint64_t>(SoundManager_StopMusicAddr), reinterpret_cast<uint64_t>(&SoundManager_StopMusic_Hook));

        const std::string BaseUIPage_OnUpdatePattern = "40 57 48 83 ec ? 80 3d ? ? ? ? ? 48 8b f9 0f 85 ? ? ? ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 8f ? ? ? ? 48 89 5c 24";
        BYTE* BaseUIPage_OnUpdateAddr = FindPattern(BaseUIPage_OnUpdatePattern, "GameAssembly.dll");
        hook.createHook(ENameID::BaseUIPage_OnUpdate, reinterpret_cast<uint64_t>(BaseUIPage_OnUpdateAddr), reinterpret_cast<uint64_t>(&BaseUIPage_OnUpdate_Hook));

        const std::string SoundManager_UpdateSfxVolumePattern = "48 83 ec ? 80 3d ? ? ? ? ? 0f 29 74 24 ? 0f 28 f0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 33 d2 0f 28 c6 0f 28 74 24 ? 48 83 c4 ? e9 ? ? ? ? cc cc cc cc cc cc cc cc cc cc cc 40 53";
        BYTE* SoundManager_UpdateSfxVolumeAddr = FindPattern(SoundManager_UpdateSfxVolumePattern, "GameAssembly.dll");
        hook.createHook(ENameID::SoundManager_UpdateSfxVolume, reinterpret_cast<uint64_t>(SoundManager_UpdateSfxVolumeAddr), reinterpret_cast<uint64_t>(&SoundManager_UpdateSfxVolume_Hook));

        const std::string SoundManager_UpdateMusicVolumePattern = "48 83 ec ? 80 3d ? ? ? ? ? 0f 29 74 24 ? 0f 28 f0 75 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? f0 83 0c 24 ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? 83 b9 ? ? ? ? ? 75 ? e8 ? ? ? ? 48 8b 0d";
        BYTE* SoundManager_UpdateMusicVolumeAddr = FindPattern(SoundManager_UpdateMusicVolumePattern, "GameAssembly.dll");
        hook.createHook(ENameID::SoundManager_UpdateMusicVolume, reinterpret_cast<uint64_t>(SoundManager_UpdateMusicVolumeAddr), reinterpret_cast<uint64_t>(&SoundManager_UpdateMusicVolume_Hook));

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        hook.applyHooks();
        SetupUnityTime();
    }
    void SetupUnityTime()
    {
        if (BYTE* inst = FindPattern("48 8B 05 ? ? ? ? F3 0F 10 80 AC 01 00 00 C3", "UnityPlayer.dll"))
        {
            int rel = *(int*)(inst + 3);
            uintptr_t addrOfGlobal = (uintptr_t)(inst + 7 + rel);
            game::g_Time = reinterpret_cast<UnityTime**>(addrOfGlobal);
            if (game::g_Time)
                Logger::AddLog("UnityTime data structure found in UnityPlayer.dll! Timescale is now functional.");
            else
				Logger::AddLog("Failed to dereference UnityTime struct address in UnityPlayer.dll!", true);
        }
        else
            Logger::AddLog("No pattern found for UnityTime struct in UnityPlayer.dll!", true);
    }
    std::vector<int> sig::ParsePattern(const std::string& pattern)
    {
        std::vector<int> bytes;
        std::string token;
        for (size_t i = 0u; i < pattern.size(); ++i)
        {
            char c = pattern[i];
            if (c == ' ')
            {
                if (!token.empty())
                {
                    if (token == "?")
                        bytes.push_back(-1);
                    else
                        bytes.push_back(static_cast<int>(strtoul(token.c_str(), nullptr, 16)));
                    token.clear();
                }
                continue;
            }
            token.push_back(c);
        }
        if (!token.empty())
        {
            if (token == "?")
                bytes.push_back(-1);
            else
                bytes.push_back(static_cast<int>(strtoul(token.c_str(), nullptr, 16)));
        }
        return bytes;
    }
    BYTE* FindPattern(const std::string& pattern, BYTE* begin, uintptr_t size)
    {
        if (!begin || size == 0) return nullptr;
        std::vector<int> bytePattern = ParsePattern(pattern);
        if (bytePattern.empty())
            return nullptr;
        MEMORY_BASIC_INFORMATION memInfo;
        BYTE* maxAddr = begin + size;
        for (BYTE* addr = begin; addr < maxAddr; addr += memInfo.RegionSize)
        {
            if (VirtualQuery(addr, &memInfo, sizeof(memInfo)) == 0)
                break;
            if (memInfo.State != MEM_COMMIT) continue;
            if (memInfo.Protect == PAGE_NOACCESS) continue;
            if (memInfo.Protect & PAGE_GUARD) continue;
            BYTE* regionStart = static_cast<BYTE*>(memInfo.BaseAddress);
            SIZE_T regionSize = memInfo.RegionSize;
            if (regionStart + regionSize > maxAddr)
                regionSize = static_cast<SIZE_T>(maxAddr - regionStart);
            if (regionSize < bytePattern.size())
                continue;
            for (SIZE_T offset = 0; offset + bytePattern.size() <= regionSize; ++offset)
            {
                bool matched = true;
                for (SIZE_T pi = 0; pi < bytePattern.size(); ++pi)
                {
                    const int pat = bytePattern[pi];
                    BYTE b = *(regionStart + offset + pi);
                    if (pat != -1 && static_cast<BYTE>(pat) != b)
                    {
                        matched = false;
                        break;
                    }
                }
                if (matched)
                    return regionStart + offset;
            }
        }
        return nullptr;
    }
    BYTE* FindPattern(const std::string& pattern, const std::string& module)
    {
        HMODULE modHandle = GetModuleHandleA(module.c_str());
        if (!modHandle) return nullptr;
        MODULEINFO moduleInfo{};
        if (!GetModuleInformation(GetCurrentProcess(), modHandle, &moduleInfo, sizeof(moduleInfo))) return nullptr;
        return FindPattern(pattern, static_cast<BYTE*>(moduleInfo.lpBaseOfDll), moduleInfo.SizeOfImage);
    }
}