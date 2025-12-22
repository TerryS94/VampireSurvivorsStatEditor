#include "pch.h"
#include "game.h"

namespace game
{
    bool isGameActive = false;
    bool disableMusicController = true;
    int currentSongListIndex = -1;//vector index not BgmType index!
    BgmModType currentSongModifier = BgmModType::Normal;
    bool songListAvailable = false;
    std::vector<SongData> song_list;
    bool wantSongChange = false;
    PlayerOptionsData* playerOptionsConfig = nullptr;
    UnityTime** g_Time = nullptr;//UnityPlayer.dll specific
    float defaultCameraZoomScaling = 2.28f;
    bool wantCameraZoomChange = false;
    float desiredCamZoom = defaultCameraZoomScaling;
    std::mutex g_ControllerMutex;
    std::unordered_map<CharacterController*, bool> g_ControllerMap;//bool is isLocalController
    int selectedCharacterControllerIndex = 0;
    bool ToggleOneShotKills = false;
    bool ToggleGodMode = false;

    std::string SurvivedTimeFormatString(GameManager* gm)
    {
        if (!gm || !game::isGameActive) return "00:00";
        float survived = gm->survivedSeconds;
        if (survived < 0.0f) survived = 0.0f;
        const int secondsPassed = static_cast<int>(std::ceil(survived));
        const int minutes = secondsPassed / 60;
        const int seconds = secondsPassed % 60;
        int width = 2;
        for (int m = minutes; m >= 100; m /= 10)
            ++width;
        return std::format("{:0{}d}:{:02d}", minutes, width, seconds);
    }
    void StopAllMusic()
    {
        if (auto StopMusic = hook.GetOriginal<tSoundManager_StopMusic>(ENameID::SoundManager_StopMusic))
        {
            //their StopAll function didnt work for me so ye kinda dirty but works
            for (int i = 0; i < 2000; ++i)
                StopMusic(static_cast<BgmType>(i), nullptr);
        }
    }
    int GetVectorIndexForSongListForBgmType(PlayerOptionsData* config)
    {
        if (!config) return 0;
        for (size_t i = 0u; i < game::song_list.size(); ++i)
        {
            const SongData& song = game::song_list.at(i);
            if (song.index == config->selectedBGM)
                return static_cast<int>(i);
        }
        return 0;
    }
    void BuildSongList(DataManager* dm)
    {
        //only need to do this one time since obv song list not gonna change while the game is open
        if (game::songListAvailable || !dm || !dm->allMusicData)
            return;
        
        il2cpp::Dictionary_ForEach(dm->allMusicData, [](BgmType index, MusicData* data, int)
        {
            if (!data) return;
            data->isUnlocked = true;
            std::string title = il2cpp::GetString(data->title);
            const std::string author = il2cpp::GetString(data->author);
            const std::string source = il2cpp::GetString(data->source);
            SongData entry{};
            entry.index = index;
            const std::regex VS_Long(" - Vampire Survivors");
            const std::regex VS_Short(" - VS version");
            title = std::regex_replace(title, VS_Long,  " - VS");
            title = std::regex_replace(title, VS_Short, " - VS");
            entry.title = title;

            if (!author.empty() && !source.empty())
                entry.credits = std::format("Author: {} - Origins: {}", author, source);
            else if (!author.empty() && source.empty())
                entry.credits = std::format("Author: {}", author);
            else if (author.empty() && !source.empty())
                entry.credits = std::format("Origins: {}", source);

            song_list.push_back(std::move(entry));
        });

        songListAvailable = !song_list.empty();
    }
    void OnShutdown()
    {
        game::desiredCamZoom = game::defaultCameraZoomScaling;
        game::CallCameraReset();//needs to be above removeHooks

        game::SetTimeScale(1.0f);

        hook.removeHooks();

        //after remove hooks to avoid race condition
        game::CleanupControllers();
        game::song_list.clear();
    }
    static UnityTime* GetUnityTimeData()
    {
        if (!g_Time) return nullptr;
        UnityTime* t = *g_Time;
        return t;
    }
    float GetTimeScale()
    {
        UnityTime* t = GetUnityTimeData();
        if (!t) return 1.0f;
        return t->timeScale;
    }
    void SetTimeScale(float value)
    {
        UnityTime* t = GetUnityTimeData();
        if (!t) return;
        t->timeScale = std::clamp(value, 0.0f, 10.0f);
    }
    void CleanupControllers()
    {
        std::lock_guard<std::mutex> lock(game::g_ControllerMutex);
        g_ControllerMap.clear();
    }
    void RemoveAllControllersButLocal()
    {
        std::lock_guard<std::mutex> lock(game::g_ControllerMutex);
        for (auto it = game::g_ControllerMap.begin(); it != game::g_ControllerMap.end(); )
        {
            const bool isLocalController = it->second;
            if (!isLocalController)
                it = game::g_ControllerMap.erase(it);
            else
                ++it;
        }
    }
    void RefreshControllerMap(GameManager* gm)
    {
        if (!gm || !gm->characters || !game::playerOptionsConfig)
            return;
        //only update our map periodically
        static Timer timer;
        static bool hasBeenCalledFirstTime = false;
        if (!hasBeenCalledFirstTime || timer.Expired(1000ll))
        {
            hasBeenCalledFirstTime = true;
            timer.Reset();
        }
        else
            return;

        {
            std::lock_guard<std::mutex> lock(g_ControllerMutex);
            g_ControllerMap.clear();
            auto* list = gm->characters;
            if (!list || !list->items) return;
            int count = list->size;
            if (count <= 0) return;
            if (count > (int)list->items->max_length)
                count = (int)list->items->max_length;
            CharacterController** arr = list->items->m_Items;
            for (int i = 0; i < count; ++i)
            {
                CharacterController* cc = arr[i];
                if (!cc || !cc->isInitialized) continue;
                //should be good enough check since they don't let multiple players use the same character type.
                const bool isLocalController = (cc->characterType == game::playerOptionsConfig->selectedCharacter);
                g_ControllerMap[cc] = isLocalController;
            }
        }
        //Logger::AddLog("Controller map updated!");
    }
    void CallCameraReset()
    {
        //flag to SetOrthographicSize that we want to change the value for when we make ResetOrthographicAndRenderTextureSize call it.
        //calling SetOrthographicSize ourself on its own is not enough!
        game::wantCameraZoomChange = true;
        auto getMain = hook.GetOriginal<tGetMainCamera>(ENameID::GetMainCamera);
        auto resetFn = hook.GetOriginal<tResetOrthographicAndRenderTextureSize>(ENameID::ResetOrthoAndRtSize);
        if (getMain && resetFn)
        {
            void* camera = getMain(nullptr);
            if (camera)
                resetFn(camera, nullptr);
        }
        else if (!getMain)
            Logger::AddLog("Couldn't call GetMainCamera function!", true);
        else if (!resetFn)
            Logger::AddLog("Couldn't call ResetOrthoAndRtSize function!", true);
    }
    void OnMusicChange()
    {
        if (game::wantSongChange)
        {
            game::wantSongChange = false;
            CharacterController* local = nullptr;
            {
                std::lock_guard<std::mutex> lock(game::g_ControllerMutex);
                for (auto& [ccPtr, isLocalController] : game::g_ControllerMap)
                    if (isLocalController) { local = ccPtr; break; }
            }
            if (game::songListAvailable && local)
            {
                if (auto SetupMusicBanger = hook.GetOriginal<tSetupMusicBanger>(ENameID::SetupMusicBanger))
                    SetupMusicBanger(local->gameManager, true, nullptr);
            }
        }
    }
}