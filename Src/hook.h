#pragma once

typedef void(__fastcall* tSoundManager_StopMusic)(BgmType song, void* method);
typedef void(__fastcall* tResetGameSession)(GameManager* gm, bool disconnectFromCoherence, void* method);
typedef void(__fastcall* tStageInit)(GameManager* gm, StageType stageType, void* method);
typedef void(__fastcall* tMagnetRefresh)(MagnetZone* magnetZone, void* method);
typedef PlayerOptionsData* (__fastcall* tPlayerOptionsGetConfig)(PlayerOptions* playerOptions, void* method);
typedef void(__fastcall* tCharacterController_OnUpdate)(CharacterController* characterController, void* method);
typedef void(__fastcall* tEnemyController_OnUpdate)(EnemyController* enemyController, void* method);
typedef void(__fastcall* tEnemyController_InitEnemy)(EnemyController* enemyController, EnemyType enemyType, bool asRemote, void* method);
typedef void(__fastcall* tResetOrthographicAndRenderTextureSize)(void* camera, void* methodInfo);
typedef void(__fastcall* tSetOrthographicSize)(void* camera, float value, void* method);
typedef void*(__fastcall* tGetMainCamera)(void* method);
typedef void(__fastcall* tGameManager_OnUpdate)(GameManager* gm, void* method);
typedef void(__fastcall* tSetupMusicBanger)(GameManager* gm, bool loop, void* methodInfo);
typedef void(__fastcall* tMainMenuPage_OnUpdate)(MainMenuPage* mmp, void* method);
typedef void(__fastcall* tCharacterSelectionPage_OnUpdate)(CharacterSelectionPage* csp, void* method);
typedef void(__fastcall* tStageSelectPage_OnUpdate)(StageSelectPage* ssp, void* method);
typedef void(__fastcall* tHealthBar_OnUpdate)(HealthBar* hb, void* method);
typedef void(__fastcall* tCharacterController_TakeDamage)(CharacterController* characterController, float damageAmount, void* method);
typedef void(__fastcall* tEnemyController_GetDamaged)(EnemyController* enemyController, float value, int showHitVfx, float damageKb, int damageType, bool hasKb, void* method);
typedef void(__fastcall* tBaseUIPage_OnUpdate)(BaseUIPage* ui, void* method);
typedef void(__fastcall* tSoundManager_UpdateSfxVolume)(float volume, void* method);
typedef void(__fastcall* tSoundManager_UpdateMusicVolume)(float volume, void* method);
typedef void(__fastcall* tSoundManager_StopAll)(void* method);

//Note: if add/remove/reorder anything in here, make sure to reflect those changes in ENameIDStrings too.
enum class ENameID : int
{
	//functions
	MagnetZone_RefreshSize,
	GetConfig,
	CharacterController_OnUpdate,
	ResetOrthoAndRtSize,
	SetOrthographicSize,
	GetMainCamera,
	ResetGameSession,
	StageInit,
	GameManager_OnUpdate,
	SetupMusicBanger,
	MainMenuPage_OnUpdate,
	CharacterSelectionPage_OnUpdate,
	StageSelectPage_OnUpdate,
	HealthBar_OnUpdate,
	EnemyController_OnUpdate,
	CharacterController_TakeDamage,
	EnemyController_GetDamaged,
	SoundManager_StopMusic,
	BaseUIPage_OnUpdate,
	SoundManager_UpdateMusicVolume,
	SoundManager_UpdateSfxVolume,

	//variables
	UnityTime,
};

//for logging purposes. make sure the order matches ENameID.
inline std::vector<std::string> ENameIDStrings = {
	//functions
	"MagnetZone_RefreshSize",
	"GetConfig",
	"CharacterController_OnUpdate",
	"ResetOrthoAndRtSize",
	"SetOrthographicSize",
	"GetMainCamera",
	"ResetGameSession",
	"StageInit",
	"GameManager_OnUpdate",
	"SetupMusicBanger",
	"MainMenuPage_OnUpdate",
	"CharacterSelectionPage_OnUpdate",
	"StageSelectPage_OnUpdate",
	"HealthBar_OnUpdate",
	"EnemyController_OnUpdate",
	"CharacterController_TakeDamage",
	"EnemyController_GetDamaged",
	"SoundManager_StopMusic",
	"BaseUIPage_OnUpdate",
	"SoundManager_UpdateMusicVolume",
	"SoundManager_UpdateSfxVolume",

	//variables
	"UnityTime",
};

struct Hook
{
	uint64_t original;
	PLH::x64Detour* detour;
};
class Hooks
{
private:
	std::map<ENameID, Hook> hooks;
	size_t expectedHookCount = 0u;
public:
	Hooks();
	~Hooks();

	void createHook(const ENameID& name, uint64_t funcToHook, uint64_t detour);
	
	template<typename T>
	inline T GetOriginal(const ENameID& id)
	{
		return (T)this->hooks[id].original;
	}

	void applyHooks();
	void removeHooks();
};
extern Hooks hook;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PlayerOptionsData* __fastcall PlayerOptionsGetConfig_Hook(PlayerOptions* playerOptions, void* method);
void __fastcall CharacterController_OnUpdate_Hook(CharacterController* characterController, void* method);
void __fastcall CharacterController_TakeDamage_Hook(CharacterController* characterController, float damageAmount, void* method);
void __fastcall EnemyController_OnUpdate_Hook(EnemyController* enemyController, void* method);
void __fastcall EnemyController_GetDamaged_Hook(EnemyController* enemyController, float value, int showHitVfx, float damageKb, int damageType, bool hasKb, void* method);
void __fastcall MagnetZone_RefreshSize_Hook(MagnetZone* magnetZone, void* method);
void __fastcall ResetOrthographicAndRenderTextureSize_Hook(void* camera, void* method);
void __fastcall SetOrthographicSize_Hook(void* camera, float value, void* method);
void* __fastcall GetMainCamera_Hook(void* method);
void __fastcall ResetGameSession_Hook(GameManager* gm, bool disconnectFromCoherence, void* method);
void __fastcall StageInit_Hook(GameManager* gm, StageType stageType, void* method);
void __fastcall GameManager_OnUpdate_Hook(GameManager* gm, void* method);
void __fastcall SetupMusicBanger_Hook(GameManager* gm, bool loop, void* method);
void __fastcall MainMenuPage_OnUpdate_Hook(MainMenuPage* mm, void* method);
void __fastcall CharacterSelectionPage_OnUpdate_Hook(CharacterSelectionPage* csp, void* method);
void __fastcall StageSelectPage_OnUpdate_Hook(StageSelectPage* ssp, void* method);
void __fastcall HealthBar_OnUpdate_Hook(HealthBar* hb, void* method);
void __fastcall SoundManager_StopMusic_Hook(BgmType song, void* method);
void __fastcall BaseUIPage_OnUpdate_Hook(BaseUIPage* ui, void* method);
void __fastcall SoundManager_UpdateSfxVolume_Hook(float volume, void* method);
void __fastcall SoundManager_UpdateMusicVolume_Hook(float volume, void* method);
