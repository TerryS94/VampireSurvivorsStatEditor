#pragma once

namespace game
{
    extern bool isGameActive;
    extern bool disableMusicController;
    extern int currentSongListIndex;
    extern BgmModType currentSongModifier;
    extern bool songListAvailable;
    extern std::vector<SongData> song_list;
    extern bool wantSongChange;
    extern UnityTime** g_Time;//unityplayer.dll specific
    extern PlayerOptionsData* playerOptionsConfig;
    extern float defaultCameraZoomScaling;
    extern float* g_CameraZoomScaling;
    extern bool wantCameraZoomChange;
    extern float desiredCamZoom;
    extern std::unordered_map<CharacterController*, bool> g_ControllerMap; //bool is isLocalController
    extern std::mutex g_ControllerMutex;
    extern int selectedCharacterControllerIndex;
    extern bool ToggleOneShotKills;
    extern bool ToggleGodMode;

    void OnMusicChange();
    void OnShutdown();
    void CallCameraReset();
    void SetTimeScale(float value);
    float GetTimeScale();
    void CleanupControllers();
    void RemoveAllControllersButLocal();
    void RefreshControllerMap(GameManager* gm);
    void CallCameraReset();
    void BuildSongList(DataManager* dm);
    int GetVectorIndexForSongListForBgmType(PlayerOptionsData* config);
    void StopAllMusic();
    std::string SurvivedTimeFormatString(GameManager* gm);
}