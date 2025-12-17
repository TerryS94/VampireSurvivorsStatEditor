#include "render.h"
#include "masm_globals.h"
#include "interFont.h"

namespace rendering
{
    static bool ToggleOnlyShowErrorsInConsole = false;
    static ImFont* interFont = nullptr;
    ImVec4 MenuColorAccent = ImVec4(1.0f, 0.18f, 0.35f, 1.0f);
    ImVec2 windowSize = ImVec2(230, 745);

    void RenderVampireSurvivorsMenu()
    {
        ImGuiStyle& style = ImGui::GetStyle();
        CharacterController* localCharacterController = nullptr;
        std::vector<CharacterController*> controllers;
        std::vector<std::string> labels;

        //build snapshot of controllers with names for the ImGui Combo and put us at index 0 while we are at it
        {
            std::lock_guard<std::mutex> lock(game::g_ControllerMutex);
            controllers.reserve(game::g_ControllerMap.size() + 1u);
            labels.reserve(game::g_ControllerMap.size() + 1u);
            std::string localLabel;
            for (auto& [ccPtr, isLocalController] : game::g_ControllerMap)
            {
                CharacterController* cc = ccPtr;
                if (!cc || !cc->currentCharacterData || !cc->currentCharacterData->charName)
                    continue;
                const std::string name = il2cpp::GetString(cc->currentCharacterData->charName);
                char buf[64];
                if (isLocalController)
                    std::snprintf(buf, sizeof(buf), "%s (You)", name.c_str());
                else if (cc->playerIndex < 0)
                    std::snprintf(buf, sizeof(buf), "%s (NPC)", name.c_str());
                else
                    std::snprintf(buf, sizeof(buf), "%s", name.c_str());

                //dont push local controller yet.. i will be pushing it to the front when this loop is over so we are always first :)
                if (isLocalController)
                {
                    localCharacterController = cc;
                    localLabel = buf;
                }
                else
                {
                    controllers.push_back(cc);
                    labels.emplace_back(buf);
                }
            }
            //put us at index 0 always if exist
            if (localCharacterController)
            {
                controllers.insert(controllers.begin(), localCharacterController);
                labels.insert(labels.begin(), localLabel);
            }
        }

        if (controllers.empty())
            labels.insert(labels.begin(), "Waiting for data...");

        if (game::selectedCharacterControllerIndex < 0 || game::selectedCharacterControllerIndex >= static_cast<int>(controllers.size()))
            game::selectedCharacterControllerIndex = 0;

        PlayerOptionsData* config = game::playerOptionsConfig;
        float alwaysZeroFlt = 0.0f;
        double alwaysZeroDbl = 0.0;
        int alwaysZeroInt = 0;
        bool alwaysFalse = false;

        if (game::currentSongListIndex == -1 && game::songListAvailable && config)
        {
            game::currentSongListIndex = game::GetVectorIndexForSongListForBgmType(config);
            game::currentSongModifier = config->bgmModType;
        }

        const int songCount = static_cast<int>(game::song_list.size());
        if (game::currentSongListIndex >= songCount)
            game::currentSongListIndex = songCount - 1;

        auto queueSong = [&](int& vectorIndex, BgmModType modifier)
            {
                if (!game::songListAvailable)
                    return;
                if (vectorIndex < 0)
                    vectorIndex = songCount - 1;
                else if (vectorIndex >= songCount)
					vectorIndex = 0;
                const SongData& song = game::song_list.at(vectorIndex);
                config->selectedBGM = song.index;
                config->bgmModType = modifier;
                game::wantSongChange = true;
            };

        CharacterController* CC = !controllers.empty() ? controllers[game::selectedCharacterControllerIndex] : nullptr;

        static int lastLevelAmount = CC ? CC->level : 0;
        static int levelDiff = 0;
        static int lastXPAmount = CC ? static_cast<int>(CC->xp) : 0;
        static int xpDiff = 0;
        static int lastKillsAmount = config ? config->kills : 0;
        static int killsDiff = 0;
        static int lastGoldAmount = config ? static_cast<int>(config->coins) : 0;
        static int goldDiff = 0;
        static Timer Every1SecondTimer;
        if (Every1SecondTimer.Expired(1000ll))
        {
            //calc levels/sec
            const int currentLevel = CC ? CC->level : 0;
            levelDiff = currentLevel - lastLevelAmount;
            lastLevelAmount = currentLevel;

            //calc xp/sec
            const int currentXP = CC ? static_cast<int>(CC->xp) : 0;
            xpDiff = currentXP - lastXPAmount;
            lastXPAmount = currentXP;

            //calc kills/sec
            const int currentKills = config ? config->kills : 0;
            killsDiff = currentKills - lastKillsAmount;
            lastKillsAmount = currentKills;

            //calc gold/sec
            const int currentGold = config ? static_cast<int>(config->coins) : 0;
            goldDiff = currentGold - lastGoldAmount;
            lastGoldAmount = currentGold;

            Every1SecondTimer.Reset();
        }

        if (ImGui::BeginTabBar("##vampiresurvivors_tabbar", ImGuiTabBarFlags_NoCloseWithMiddleMouseButton | ImGuiTabBarFlags_Reorderable))
        {
            if (ImGui::BeginTabItem("Character"))
            {
                ImGui::Spacing();
                const char* previewLabel = labels[game::selectedCharacterControllerIndex].c_str();
                ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
                if (ImGui::BeginCombo("##CharacterControllerSelector", previewLabel, ImGuiComboFlags_HeightLargest))
                {
                    for (int i = 0; i < static_cast<int>(labels.size()); ++i)
                    {
                        ImGui::PushID(i);
                        bool isSelected = (i == game::selectedCharacterControllerIndex);
                        if (ImGui::Selectable(labels[i].c_str(), isSelected))
                            game::selectedCharacterControllerIndex = i;
                        if (isSelected)
                            ImGui::SetItemDefaultFocus();
                        ImGui::PopID();
                    }
                    ImGui::EndCombo();
                }

                if (ImGui::IsItemHoveredDelay())
                    utils::ImToolTipWithTextWrap("Choose which character attributes you would like to view/edit that are specific to their Character Controller.\n\n"
                        "Any other online players and/or NPCs will show up here if they are playing alongside you!");

                ImGui::Text("Health: %.2f", CC ? CC->hp : alwaysZeroFlt);

                if (ImGui::Checkbox("God Mode", &game::ToggleGodMode))
                    Logger::AddLog(std::format("God Mode: {}", game::ToggleGodMode ? "Enabled" : "Disabled"));

                if (ImGui::Checkbox("One Hit Kills", &game::ToggleOneShotKills))
                    Logger::AddLog(std::format("One Hit Kills: {}", game::ToggleOneShotKills ? "Enabled" : "Disabled"));

                if (ImGui::Checkbox("Random Level Up", config ? &config->selectedRandomLevels : &alwaysFalse))
                {
                    if (config)
                        Logger::AddLog(std::format("Random Level Up: {}", config->selectedRandomLevels ? "Enabled" : "Disabled"));
                }
                if (ImGui::Checkbox("Limit Break", config && CC ? &config->selectedLimitBreak : &alwaysFalse))
                {
                    if (config && CC)
                    {
                        if (config->selectedLimitBreak)
                        {
                            CC->alwaysCoinBag = false;
                            CC->alwaysRoast = false;
                        }
                        else
                            CC->alwaysRandomLimitBreak = false;

                        Logger::AddLog(std::format("Limit Break: {}", config->selectedLimitBreak ? "Enabled" : "Disabled"));
                    }
                }
                ImGui::SameLine();
                if (ImGui::Checkbox("Random##limitbreak", CC ? &CC->alwaysRandomLimitBreak : &alwaysFalse))
                {
                    if (CC)
                    {
                        //also disable random level ups if we explicitly uncheck this, otherwise it'll keep doing random levelups for the Limit Break if enabled :)
                        if (!CC->alwaysRandomLimitBreak && config->selectedRandomLevels)
                            config->selectedRandomLevels = false;
                        Logger::AddLog(std::format("Random Limit Break: {}", CC->alwaysRandomLimitBreak ? "Enabled" : "Disabled"));
                    }
                }

                ImGui::BeginDisabled(!game::isGameActive || !CC || !config || config->selectedLimitBreak || (!CC->alwaysCoinBag && !CC->alwaysRoast));
                {
                    const char* currentSelected = CC && CC->alwaysCoinBag ? "'Coin Bag'" : "'Floor Chicken'";
                    if (ImGui::Button(std::format("Reset Always {} Option", currentSelected).c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)))
                    {
                        if (CC && config)
                        {
                            config->selectedLimitBreak = false;
                            CC->alwaysRandomLimitBreak = false;
                            CC->alwaysCoinBag = false;
                            CC->alwaysRoast = false;
                            config->selectedRandomLevels = false;
                            Logger::AddLog(std::format("Always {} option has been reset.", currentSelected));
                        }
                    }
                    ImGui::EndDisabled();
                }

                ImGui::PushItemWidth(110.0f);

                ImGui::DragInt("Level", CC ? &CC->level : &alwaysZeroInt, 0.25f);
                if (levelDiff > 0)
                {
                    ImGui::SameLine();
                    ImGui::TextColored(rendering::MenuColorAccent, "(%d/sec)", levelDiff);
                }

                ImGui::DragFloat("XP", CC ? &CC->xp : &alwaysZeroFlt, 0.5f, 0.0f, 0.0f, "%.0f");
                if (xpDiff > 0)
                {
                    ImGui::SameLine();
                    ImGui::TextColored(rendering::MenuColorAccent, "(%d/sec)", xpDiff);
                }

                ImGui::DragInt("Kills", config ? &config->kills : &alwaysZeroInt, 0.5f);

                if (config && ImGui::IsItemHoveredDelay())
                    utils::ImToolTipWithTextWrap(std::format("Boss kills this session: {}", config->bossKills).c_str());

                if (killsDiff > 0)
                {
                    ImGui::SameLine();
                    ImGui::TextColored(rendering::MenuColorAccent, "(%d/sec)", killsDiff);
                }

                ImGui::DragFloat("Gold", config ? &config->coins : &alwaysZeroFlt, 0.5f, 0.0f, 0.0f, "%.0f");
                if (goldDiff > 0)
                {
                    ImGui::SameLine();
                    ImGui::TextColored(rendering::MenuColorAccent, "(%d/sec)", goldDiff);
                }

                ImGui::DragFloat("Session Gold", config ? &config->inGameCoins : &alwaysZeroFlt, 0.5f, 0.0f, 0.0f, "%.0f");

                ImGui::DragInt("Max Weapons", CC ? &CC->maxWeaponCount : &alwaysZeroInt, 0.25f, 0, 32);
                ImGui::DragInt("Max Passives", CC ? &CC->maxPassiveCount : &alwaysZeroInt, 0.25f, 0, 32);

                PlayerModifierStats* stats = CC ? CC->playerStats : nullptr;
                ImGui::DragFloat("Max Health", stats ? &stats->MaxHp->value : &alwaysZeroFlt, 0.001f);

                ImGui::SameLine();
                ImGui::SetCursorPosX(windowSize.x - 20.0f);
                ImGui::TextColored(rendering::MenuColorAccent, "(?)");
                if (ImGui::IsItemHovered())
                    utils::ImToolTipWithTextWrap("These stat numbers are only the full story for a clean run.\n\nOnce you add Eggs, PowerUps, Arcanas or Limit Break, they become only "
                        "part of the final equation, so check the in-game stats screen for the final result to help you make relative changes in this panel.");

                ImGui::DragFloat("Recovery", stats ? &stats->Regen->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Armor", stats ? &stats->Armor->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f");
                ImGui::DragFloat("Move Speed", stats ? &stats->MoveSpeed->value : &alwaysZeroFlt, 0.001f);

                ImGui::DragFloat("Might", stats ? &stats->Might->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Projectile Speed", stats ? &stats->ProjectileSpeed->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Duration", stats ? &stats->Duration->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Area", stats ? &stats->Area->value : &alwaysZeroFlt, 0.001f);

                ImGui::DragFloat("Cooldown", stats ? &stats->Cooldown->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Amount", stats ? &stats->Amount->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f");

                ImGui::DragScalar("Revivals Left", ImGuiDataType_Double, stats ? &stats->Revivals->value : &alwaysZeroDbl, 0.25f, nullptr, nullptr, "%.0f");
                ImGui::DragInt("Revivals Used", stats ? &stats->UsedRevivals : &alwaysZeroInt, 0.25f);

                if (ImGui::DragFloat("Magnet", CC && CC->magnetZone ? &CC->magnetZone->Radius->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f"))
                {
                    tMagnetRefresh origMagnetRefresh = hook.GetOriginal<tMagnetRefresh>(ENameID::MagnetZone_RefreshSize);
                    if (CC && CC->magnetZone && origMagnetRefresh)
                        origMagnetRefresh(CC->magnetZone, 0ll);//call their function directly to refresh/update Magnet radius
                }

                ImGui::SameLine();
                bool openMagnetPopup = false;
                if (imgui_ext::ButtonImage("##pickupsettings", ImVec2(16, 16), DX11::GetTextureByName(ETextureID::ICON_MENUBURGER), true, 0.8f, 0, ImVec2(4, 4), rendering::MenuColorAccent))
                    openMagnetPopup = true;
                if (ImGui::IsItemHoveredDelay())
                    utils::ImToolTipWithTextWrap("Pickup Mode Options");

                if (openMagnetPopup)
					ImGui::OpenPopup("##PickupSettingsPopup");
                
                if (ImGui::BeginPopup("##PickupSettingsPopup"))
                {
                    auto magnetButton = [&](const char* label, PickupMode pickupMode)
                        {
                            const bool isActive = CC ? CC->pickupMode == pickupMode : pickupMode == PickupMode::Normal;
                            if (isActive)
                            {
                                ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonActive]);
                                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, style.Colors[ImGuiCol_ButtonActive]);
                            }
                            ImGui::PushID(label);
                            if (ImGui::Button(label, ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)))
                            {
								if (CC)
                                    CC->pickupMode = pickupMode;
                            }
                            ImGui::PopID();
                            if (isActive)
                                ImGui::PopStyleColor(2);
                        };

                    ImGui::SeparatorText("Pickup Options");
                    magnetButton("Normal", PickupMode::Normal);
					magnetButton("Gems and Coins Only", PickupMode::GemsAndCoinsOnly);
                    magnetButton("Gems, Coins and Roasts", PickupMode::GemsCoinsRoasts);
                    magnetButton("Gems, Coins, Roasts and Souls", PickupMode::GemsCoinsRoastsSouls);
					magnetButton("Ignore All", PickupMode::IgnoreAll);

                    ImGui::EndPopup();
				}

                ImGui::DragFloat("Luck", stats ? &stats->Luck->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Growth", stats ? &stats->Growth->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Greed", stats ? &stats->Greed->value : &alwaysZeroFlt, 0.001f);
                ImGui::DragFloat("Curse", stats ? &stats->Curse->value : &alwaysZeroFlt, 0.001f);

                ImGui::DragFloat("Rerolls", stats ? &stats->ReRolls->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f");
                ImGui::DragFloat("Skips", stats ? &stats->Skips->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f");
                ImGui::DragFloat("Banishes", stats ? &stats->Banishes->value : &alwaysZeroFlt, 0.25f, 0.0f, 0.0f, "%.0f");

                ImGui::PopItemWidth();

                ImGui::EndTabItem();
            }

            static bool musicTabWasOpenLastFrame = false;
            const bool musicTabOpenThisFrame = ImGui::BeginTabItem("Music");
            if (musicTabOpenThisFrame)
            {
                ImGui::Spacing();
                static int scrollFrames = 3;
                static int lastSongIndex = game::currentSongListIndex;

                const bool justEnteredMusicTab = !musicTabWasOpenLastFrame;
                if (ImGui::IsItemClicked() || justEnteredMusicTab || lastSongIndex != game::currentSongListIndex)
                    scrollFrames = 3;

                musicTabWasOpenLastFrame = true;

                const SongData* currentSong = game::songListAvailable ? &game::song_list[game::currentSongListIndex] : nullptr;
                ImGui::BeginDisabled(game::disableMusicController || !config);
                {
                    static std::string songFilter = "";
                    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
                    ImGui::InputTextWithHint("##SongFilter", "Search songs...", &songFilter);
                    const std::string filterLowercase = utils::ToLowercase(songFilter);
                    const bool isFilterEmptyOrOnlyWhiteSpace = utils::isStringEmptyOrWhitespaceOnly(songFilter);

                    ImGui::Spacing();

                    if (ImGui::BeginChild("##SongCombo", ImVec2(ImGui::GetContentRegionAvail().x, windowSize.y - 190.0f), true))
                    {
                        if (songCount <= 0)
                            ImGui::TextWrapped("Song data not ready yet!");
                        else
                        {
                            for (int i = 0; i < songCount; ++i)
                            {
                                const SongData& s = game::song_list[i];
                                if (!isFilterEmptyOrOnlyWhiteSpace && !utils::ToLowercase(s.title).contains(filterLowercase))
                                    continue;

                                ImGui::Separator();
                                ImGui::PushID(i);
                                const bool isSelected = (i == game::currentSongListIndex);
                                if (ImGui::Selectable(s.title.c_str(), isSelected))
                                {
                                    game::currentSongListIndex = i;
                                    queueSong(i, game::currentSongModifier);
                                }
                                if (!s.credits.empty() && ImGui::IsItemHoveredDelay())
                                    utils::ImToolTipWithTextWrap(s.credits.c_str());
                                if (isSelected && scrollFrames > 0)
                                {
                                    ImGui::ScrollToItem(ImGuiScrollFlags_AlwaysCenterY);
                                    scrollFrames--;
                                }
                                ImGui::PopID();
                                if (i == songCount - 1)
                                    ImGui::Separator();
                            }
                            ImGui::Spacing();
                        }
                        ImGui::EndChild();
                    }

                    ImGui::Spacing();

                    lastSongIndex = game::currentSongListIndex;

                    const float fullWidth = ImGui::GetContentRegionAvail().x;
                    const float inner = style.ItemInnerSpacing.x;
                    float buttonWidth = (fullWidth - inner) * 0.5f;

                    ImGui::SeparatorText("Controls");

                    if (ImGui::Button("Stop Music##songlist", ImVec2(fullWidth, 0.0f)))
                        game::StopAllMusic();
                    if (ImGui::Button("Previous Track", ImVec2(buttonWidth, 0.0f)))
                    {
                        songFilter = "";
                        game::currentSongListIndex--;
                        queueSong(game::currentSongListIndex, game::currentSongModifier);
                    }
                    ImGui::SameLine(0.0f, inner);
                    if (ImGui::Button("Next Track", ImVec2(buttonWidth, 0.0f)))
                    {
                        songFilter = "";
                        game::currentSongListIndex++;
                        queueSong(game::currentSongListIndex, game::currentSongModifier);
                    }
                    if (ImGui::Button("Jump to a Random Track##songlist", ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)))
                    {
                        if (songCount > 0)
                        {
                            static std::mt19937 rng{ std::random_device{}() };
                            std::uniform_int_distribution<int> dist(0, songCount - 1);
                            int newIndex = game::currentSongListIndex;
                            if (songCount == 1)
                                newIndex = 0;
                            else
                            {
                                do
                                {
                                    newIndex = dist(rng);
                                } while (newIndex == game::currentSongListIndex);
                            }
                            songFilter = "";
                            game::currentSongListIndex = newIndex;
                            scrollFrames = 3;
                            queueSong(newIndex, game::currentSongModifier);
                        }
                    }

                    buttonWidth = (fullWidth - inner * 2.0f) / 3.0f;

                    auto modifierButton = [&](const char* label, BgmModType type)
                        {
                            bool isActive = (game::currentSongModifier == type);
                            if (isActive)
                            {
                                ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonActive]);
                                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, style.Colors[ImGuiCol_ButtonActive]);
                            }
                            ImGui::PushID(label);
                            if (ImGui::Button(label, ImVec2(buttonWidth, 0.0f)))
                            {
                                game::currentSongModifier = type;
                                queueSong(game::currentSongListIndex, game::currentSongModifier);
                            }
                            ImGui::PopID();
                            if (isActive)
                                ImGui::PopStyleColor(2);
                        };

                    ImGui::SeparatorText("Modifier");

                    modifierButton("Forsaken##songlist", BgmModType::Forsaken);
                    ImGui::SameLine(0.0f, inner);
                    modifierButton("Normal##songlist", BgmModType::Normal);
                    ImGui::SameLine(0.0f, inner);
                    modifierButton("Hyper##songlist", BgmModType::Hyper);
                }
                ImGui::EndDisabled();

                ImGui::EndTabItem();
            }
            else
                musicTabWasOpenLastFrame = false;

            if (ImGui::BeginTabItem("Engine"))
            {
                ImGui::Spacing();

                ImGui::Checkbox("Flashing VFX", config ? &config->flashingVFXEnabled : &alwaysFalse);

                ImGui::PushItemWidth(110.0f);
                ImGui::BeginDisabled(!game::isGameActive);
                {
                    if (ImGui::DragFloat("Cam Zoom", &game::desiredCamZoom, 0.01f, 0.0f, 0.0f, "%.3f"))
                        game::CallCameraReset();
                    if (ImGui::IsItemHoveredDelay())
                        utils::ImToolTipWithTextWrap("Change the orthographic size that the camera uses.\n\nNote: If you changed this and start/restart a stage the engine value behind the scenes "
                            "will get reset while this value here won't. Simply edit it again to update it!");

                    if (game::desiredCamZoom != game::defaultCameraZoomScaling)
                    {
                        ImGui::SameLine();
                        if (ImGui::Button("Reset##orthographicSize"))
                        {
                            game::desiredCamZoom = game::defaultCameraZoomScaling;
                            game::CallCameraReset();
                        }
                    }
                    ImGui::EndDisabled();
                }

                float timeScale = game::GetTimeScale();
                if (ImGui::DragFloat("Timescale", &timeScale, 0.001f, 0.0f, 10.0f, "%.3f", ImGuiSliderFlags_AlwaysClamp | ImGuiSliderFlags_NoInput))
                    game::SetTimeScale(timeScale);
                if (timeScale != 1.0f)
                {
                    ImGui::SameLine();
                    if (ImGui::Button("Reset##timescale"))
                        game::SetTimeScale(1.0f);
                }

                if (ImGui::SliderFloat("SFX Volume", config ? &config->soundsVolume : &alwaysZeroFlt, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp))
                {
                    auto updateSFXVolume = hook.GetOriginal<tSoundManager_UpdateSfxVolume>(ENameID::SoundManager_UpdateSfxVolume);
                    if (updateSFXVolume && config)
                        updateSFXVolume(config->soundsVolume, nullptr);
                }
                if (ImGui::SliderFloat("Music Volume", config ? &config->musicVolume : &alwaysZeroFlt, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp))
                {
                    auto updateMusicVolume = hook.GetOriginal<tSoundManager_UpdateMusicVolume>(ENameID::SoundManager_UpdateMusicVolume);
                    if (updateMusicVolume && config)
                        updateMusicVolume(config->musicVolume, nullptr);
                }

                const std::string timeStrFormatted = game::SurvivedTimeFormatString(CC && CC->gameManager ? CC->gameManager : nullptr);
                ImGui::DragFloat("Survived Time##stagetime", CC && CC->gameManager && game::isGameActive ? &CC->gameManager->survivedSeconds : &alwaysZeroFlt, 0.25f, 0, 0, timeStrFormatted.c_str());
                if (ImGui::IsItemHoveredDelay())
                    utils::ImToolTipWithTextWrap("Editing this manually by either double clicking or ctrl+click will be in seconds (as float).");

                ImGui::PopItemWidth();
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Misc"))
            {
                ImGui::Spacing();

                if (ImGui::ColorEdit3("Menu Primary Color", &rendering::MenuColorAccent.x, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoInputs))
                    rendering::ApplyDarkThemeWithAccent(rendering::MenuColorAccent);

                if (ImGui::Button("Clear Log"))
                    Logger::ClearLogHistory();
                if (ImGui::Checkbox("Auto Scroll", &Logger::ToggleAutoScroll))
                    Logger::AddLog(std::format("Auto Scroll: {}", Logger::ToggleAutoScroll ? "Enabled" : "Disabled"));

                if (ImGui::Checkbox("Errors Only", &rendering::ToggleOnlyShowErrorsInConsole))
                    Logger::AddLog(std::format("Errors Only: {}", rendering::ToggleOnlyShowErrorsInConsole ? "Enabled" : "Disabled"));

                static std::string filterBuffer = "";
                ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
                ImGui::InputTextWithHint("##LogFilter", "Search logs...", &filterBuffer);
                const std::string filterLowercase = utils::ToLowercase(filterBuffer);
                const bool isFilterEmptyOrOnlyWhiteSpace = utils::isStringEmptyOrWhitespaceOnly(filterBuffer);
                const ImVec2 size = ImGui::GetContentRegionAvail();

                ImGui::BeginChild("##LogHistory", size);
                {
                    const auto& history = Logger::GetLogHistory();
                    for (size_t i = 0u; i < history.size(); ++i)
                    {
                        const auto& logInfo = history[i];
                        if (rendering::ToggleOnlyShowErrorsInConsole && !logInfo.isError)
                            continue;
                        if (!isFilterEmptyOrOnlyWhiteSpace && !utils::ToLowercase(logInfo.message).contains(filterLowercase))
                            continue;

                        ImGui::PushID(static_cast<int>(i));
                        if (!logInfo.isError)
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.21f, 0.97f, 0.56f, 1.0f));
                        else
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f));

                        ImGui::TextWrapped("%s", logInfo.message.c_str());
                        if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
                            ImGui::SetClipboardText(logInfo.message.c_str());

                        ImGui::PopStyleColor();
                        ImGui::Separator();
                        ImGui::PopID();
                    }
                    if (Logger::ToggleAutoScroll && Logger::scrollFrames > 0)
                    {
                        ImGui::SetScrollHereY(1.0f);
                        Logger::scrollFrames--;
                    }
                    ImGui::EndChild();
                }
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    }
    void InitFonts()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImFontConfig fontConfig = ImFontConfig();
        fontConfig.FontDataOwnedByAtlas = false;
        fontConfig.PixelSnapH = true;
        fontConfig.OversampleH = 2;

        rendering::interFont = io.Fonts->AddFontFromMemoryCompressedTTF(Fonts::Inter_compressed_data, Fonts::Inter_compressed_size, 13.0f, &fontConfig);

        io.FontDefault = rendering::interFont;
    }
    void ApplyDarkThemeWithAccent(const ImVec4& primaryAccent)
    {
        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4 bgMain = ImVec4(0.10f, 0.11f, 0.14f, 1.0f);
        ImVec4 bgAlt = ImVec4(0.14f, 0.15f, 0.19f, 1.0f);
        ImVec4 bgDeep = ImVec4(0.06f, 0.07f, 0.10f, 1.0f);
        ImVec4 bgHover = ImVec4(0.18f, 0.20f, 0.25f, 1.0f);
        ImVec4 text = ImVec4(0.95f, 0.96f, 0.98f, 1.0f);
        ImVec4 textMuted = ImVec4(0.62f, 0.65f, 0.73f, 1.0f);
        ImVec4 accent = primaryAccent;
        ImVec4 accentHover = utils::Lerp(primaryAccent, ImVec4(1.0f, 1.0f, 1.0f, primaryAccent.w), 0.15f);
        ImVec4 accentActive = utils::Mul(primaryAccent, 0.85f);
        ImVec4 accentGreen = ImVec4(0.32f, 0.78f, 0.55f, 1.0f);
        ImVec4 accentRed = ImVec4(0.95f, 0.32f, 0.40f, 1.0f);

        style.Alpha = 1.0f;
        style.DisabledAlpha = 0.4000000059604645f;
        style.WindowPadding = ImVec2(8.0f, 8.0f);
        style.WindowRounding = 0.0f;
        style.WindowBorderSize = 0.0f;
        style.WindowMinSize = ImVec2(50.0f, 50.0f);
        style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style.WindowMenuButtonPosition = ImGuiDir_Left;
        style.ChildRounding = 4.0f;
        style.ChildBorderSize = 1.0f;
        style.PopupRounding = 4.0f;
        style.PopupBorderSize = 1.0f;
        style.FramePadding = ImVec2(5.0f, 3.0f);
        style.FrameRounding = 3.0f;
        style.FrameBorderSize = 0.0f;
        style.ItemSpacing = ImVec2(4.0f, 2.75f);//4.0f, 4.0f
        style.ItemInnerSpacing = ImVec2(3.0f, 2.0f);
        style.CellPadding = ImVec2(3.0f, 3.0f);
        style.IndentSpacing = 6.0f;
        style.ColumnsMinSpacing = 6.0f;
        const float scrollWidth = 4.0f;
        style.ScrollbarSize = scrollWidth;
        style.ScrollbarPadding = 0.0f;
        style.ScrollbarRounding = 16.0f;
        style.GrabMinSize = scrollWidth;
        style.GrabRounding = 8.0f;
        style.TabRounding = 4.0f;
        style.TabBorderSize = 1.0f;
        style.TabCloseButtonMinWidthUnselected = 0.0f;
        style.ColorButtonPosition = ImGuiDir_Right;
        style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
        style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
        style.SeparatorTextBorderSize = 2.0f;

        style.Colors[ImGuiCol_Text] = text;
        style.Colors[ImGuiCol_TextDisabled] = textMuted;
        style.Colors[ImGuiCol_WindowBg] = bgMain;
        style.Colors[ImGuiCol_ChildBg] = bgMain;
        style.Colors[ImGuiCol_PopupBg] = bgDeep;
        style.Colors[ImGuiCol_Border] = ImVec4(0.18f, 0.20f, 0.26f, 1.0f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg] = bgAlt;
        style.Colors[ImGuiCol_FrameBgHovered] = bgHover;
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.23f, 0.30f, 1.0f);
        style.Colors[ImGuiCol_TitleBg] = bgDeep;
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.09f, 0.10f, 0.14f, 1.0f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = bgDeep;
        style.Colors[ImGuiCol_MenuBarBg] = bgDeep;
        style.Colors[ImGuiCol_Button] = utils::Lerp(bgAlt, accent, 0.45f);
        style.Colors[ImGuiCol_ButtonHovered] = accentHover;
        style.Colors[ImGuiCol_ButtonActive] = accentActive;
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.04f, 0.04f, 0.06f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrab] = style.Colors[ImGuiCol_ButtonHovered];
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = style.Colors[ImGuiCol_Button];
        style.Colors[ImGuiCol_ScrollbarGrabActive] = style.Colors[ImGuiCol_Button];
        style.Colors[ImGuiCol_CheckMark] = accent;
        style.Colors[ImGuiCol_SliderGrab] = accent;
        style.Colors[ImGuiCol_SliderGrabActive] = accentActive;
        style.Colors[ImGuiCol_Header] = utils::Lerp(bgAlt, accent, 0.35f);
        style.Colors[ImGuiCol_HeaderHovered] = utils::Lerp(bgAlt, accent, 0.55f);
        style.Colors[ImGuiCol_HeaderActive] = utils::Lerp(bgAlt, accent, 0.70f);
        style.Colors[ImGuiCol_Separator] = ImVec4(0.18f, 0.20f, 0.26f, 1.0f);
        style.Colors[ImGuiCol_SeparatorHovered] = accentHover;
        style.Colors[ImGuiCol_SeparatorActive] = accentActive;
        style.Colors[ImGuiCol_ResizeGrip] = utils::Lerp(bgAlt, accent, 0.40f);
        style.Colors[ImGuiCol_ResizeGripHovered] = accentHover;
        style.Colors[ImGuiCol_ResizeGripActive] = accentActive;
        style.Colors[ImGuiCol_Tab] = utils::Lerp(bgAlt, accent, 0.25f);
        style.Colors[ImGuiCol_TabHovered] = accentHover;
        style.Colors[ImGuiCol_TabActive] = accentActive;
        style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.12f, 0.16f, 1.0f);
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.16f, 0.20f, 1.0f);
        style.Colors[ImGuiCol_PlotLines] = accent;
        style.Colors[ImGuiCol_PlotLinesHovered] = accentHover;
        style.Colors[ImGuiCol_PlotHistogram] = accentGreen;
        style.Colors[ImGuiCol_PlotHistogramHovered] = accent;
        style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.13f, 0.14f, 0.19f, 1.0f);
        style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.18f, 0.20f, 0.26f, 1.0f);
        style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.11f, 0.12f, 0.16f, 1.0f);
        style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.11f, 0.12f, 0.16f, 0.60f);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(accent.x, accent.y, accent.z, 0.40f);
        style.Colors[ImGuiCol_NavHighlight] = accent;
        style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
        style.Colors[ImGuiCol_DragDropTarget] = accent;
        style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.02f, 0.02f, 0.03f, 0.85f);
    }
}