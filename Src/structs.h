#pragma once

struct CharacterController;
struct DataManager;
struct ArcanaManager;
struct LootManager;
struct WeaponsFacade;
struct LevelUpFactory;
struct Weapon;
struct WeaponData;
struct EnemyData;

//some of these are big as fuck so forward declare them here then put them all the way at the end :nodders:
enum class SfxType;
enum class ItemType;
enum class StageType;
enum class CharacterType;
enum class EnemyType;
enum class EnemySkillType;
enum class WeaponType;
enum class BgmType;
enum class AchievementType;
enum class SecretType;
enum class AdventureAchievementType;
enum class AdventureType;
enum class SkinType;
enum class ArcanaType;
enum class MaterialType;
enum class SpawnType;
enum class CollectionsPageFilterType;
enum class BorderType;
enum class SystemPlatformTypes;
enum class BgmModType;
enum class BgmPlaybackType;
enum class AlbumType;
enum class PowerUpType;
enum class VisibleJoystickType;
enum class ContentGroupType;
enum class PropType;
enum class HitVfxType;
enum class AIType;
enum class PrizeType;
enum class DlcType;
enum class CharacterRandomGeneratorStat;
enum class PickupMode;

struct Il2CppObjectBase
{
    void* klass;
    void* monitor;
};

template<typename T>
struct Nullable
{
    bool hasValue;
private: char pad0[0x3]; public:
    T value;
};
static_assert(sizeof(Nullable<int>) == 8);

struct SoundConfig
{
    Il2CppObjectBase obj;
    bool Mute;
    Nullable<float> Volume;
    float Rate;
    float Detune;
    float Seek;
    bool Loop;
    float Delay;
    float Pan;
};

struct PowerUpLevel
{
    Il2CppObjectBase obj;
    PowerUpType PowerUp;
    int Level;
};
static_assert(offsetof(PowerUpLevel, PowerUp) == 0x10);
static_assert(offsetof(PowerUpLevel, Level) == 0x14);

struct Il2CppString
{
    Il2CppObjectBase obj;
    int length;
    char16_t chars[1];
};
struct Il2CppArrayBounds
{
    uintptr_t length;
    int lower_bound;
};
template<typename T>
struct Il2CppArrayT
{
    Il2CppObjectBase obj;
    Il2CppArrayBounds* bounds;
    uintptr_t max_length;
    T m_Items[1];
};
template<typename T>
struct Il2CppList
{
    Il2CppObjectBase obj;
    Il2CppArrayT<T>* items;
    int size;
    int version;
    void* _syncRoot;
};
template<typename TKey, typename TValue>
struct Il2CppDictionaryEntry
{
    int hashCode;
    int next;
    TKey key;
    TValue value;
};
template<typename TKey, typename TValue>
struct Il2CppDictionary
{
    Il2CppObjectBase obj;
    Il2CppArrayT<int>* buckets;
    Il2CppArrayT<Il2CppDictionaryEntry<TKey, TValue>>* entries;
    int count;
    int version;
    int freeList;
    int freeCount;
    void* comparer;
    void* keys;
    void* values;
    void* _syncRoot;
};
#pragma pack(push, 1)
struct EggFloat
{
    Il2CppObjectBase obj;
    float value;
    float eggValue;
};

struct EggDouble
{
    Il2CppObjectBase obj;
    double value;
    double eggValue;
};
#pragma pack(pop)
static_assert(offsetof(EggFloat, value) == 0x10);
static_assert(offsetof(EggDouble, value) == 0x10);

#pragma pack(push, 1)
struct BaseUIPage
{
private: char pad0[0x98]; public:
    DataManager* Data;                    
private: char pad1[0x8]; public:
    bool isWaitingForPlayersToEnterUi;   
private: char pad2[0x3]; public:
    float defaultRepeatDelay;             
    float defaultInputActionsPerSecond;   
    float maxInputActionsPerSecond;       
    float scrollAccelerationSpeed;        
private: char pad3[0x14]; public:
    Vec3 originalCanvasScale;
    float originalOrthographicSize;       
};
//constexpr int hovertrick = offsetof(BaseUIPage, originalOrthographicSize);
static_assert(offsetof(BaseUIPage, Data) == 0x98);
static_assert(offsetof(BaseUIPage, isWaitingForPlayersToEnterUi) == 0xA8);
static_assert(offsetof(BaseUIPage, defaultRepeatDelay) == 0xAC);
static_assert(offsetof(BaseUIPage, defaultInputActionsPerSecond) == 0xB0);
static_assert(offsetof(BaseUIPage, maxInputActionsPerSecond) == 0xB4);
static_assert(offsetof(BaseUIPage, scrollAccelerationSpeed) == 0xB8);
static_assert(offsetof(BaseUIPage, originalCanvasScale) == 0xD0);
static_assert(offsetof(BaseUIPage, originalOrthographicSize) == 0xDC);

struct CharacterStageData
{
    Il2CppObjectBase obj;
    int complete;
    bool hyperMode;
    bool hurryMode;
    bool inverseMode;
private: char pad1[0x1]; public:
    int survivedMinutes;
    int startedRun;
    StageType type;
};
struct CharacterData
{
private: char pad0[0x28]; public:
    Il2CppString* prefix;
    Il2CppString* charName;
    Il2CppString* surname;
    Il2CppString* textureName;
    Il2CppString* spriteName;
    Il2CppString* charSelTexture;
    Il2CppString* charSelFrame;
    Il2CppString* portraitName;
    int walkingFrames;
};
struct CoopSelections
{
    Il2CppObjectBase obj;
    CharacterType SelectedCharacter;
    ImVec4 Color;
};
struct PlayerOptionsData
{
    Il2CppObjectBase obj;
    Il2CppString* saveDate;
    Il2CppString* platform;
    bool saveSyncPlatformAchievements;
private: char pad1[0x3]; public:
    Nullable<SystemPlatformTypes> saveOriginalPlatform;
private: char pad3[0x4]; public:
    Il2CppList<SystemPlatformTypes>* saveTouchedPlatforms;
    int itemsInCollection;
    int itemsInUnlocks;
    int itemsInSecrets;
    CharacterType selectedCharacter;
    StageType selectedStage;
    bool selectedHyper;
    bool acceptedEULA;
    bool selectedHurry;
    bool selectedMazzo;
    bool selectedLimitBreak;
    bool selectedInverse;
    bool selectedEndless;
    bool selectedGoldenEggs;
    bool selectedSharePassives;
private: char pad4[0x3]; public:
    int selectedArcana;
    bool selectedSurvarots;
    bool forcedSurvarots;
private: char pad5[0x2]; public:
    int inGameFoundSurvarots;
    bool selectedRandomEvents;
    bool selectedRandomLevels;
    bool selectedBGMSave;
private: char pad6[1]; public:
    BgmType selectedBGM;
    BgmModType bgmModType;
    BgmPlaybackType bgmPlaybackType;
private: char pad7[0x4]; public:
    int selectedMaxWeapons;
    bool isFullscreen;
private: char pad8[0x3]; public:
    int version;
    float coins;
    float inGameCoins;
    int kills;
    int bossKills;
private: char pad9[0x4]; public:
    Il2CppList<ItemType>* inGamePickups;
    Il2CppList<WeaponType>* inGameWeapons;
    Il2CppList<CharacterType>* inGameCoffins;
    Il2CppList<EnemyType>* inGameBossesTypes;
    int inGameStarryHeavnes;
    int inGameWeirdSoulsPurifier;
    Il2CppDictionary<EnemyType, int>* runKillCount;
    int runPickupsCoins;
    float lifetimeCoins;
    float totalCoins;
    int beginnersLuck;
    float inGameFever;
    int inGameHunger;
    float rawInGameHeal;
    float lifetimeSurvived;
    float lifetimeHeal;
    float OwO;//???
    int completedHurries;
    float trainHazardEnemiesHit;
    int topLapsCarlo;
    int totalLapsCarlo;
    int topLapsHighway;
    int totalLapsHighway;
    bool reducePhysics;
    bool classicMusic;
    bool visuallyInvertStages;
    bool hideProgress;
    bool soundsEnabled;
    bool musicEnabled;
private: char pad10[0x2]; public:
    float soundsVolume;
    float musicVolume;
    bool flashingVFXEnabled;
private: char pad11[0x3]; public:
    VisibleJoystickType joyStickType;
    bool hideAdsButtons;
    bool damageNumbersEnabled;
    bool glimmerCarouselEnabled;
    bool streamSafeEnabled;
    bool hideXPBar;
    bool cheatCodeUsed;
    bool hasKilledTheFinalBoss;
    bool hasSeenFinalFireworks;
    Il2CppString* language;
    bool showQuitDescription;
    bool hideCompletedAchievements;
private: char pad12[0x2]; public:
    int playedRNJ;
    bool showPickups;
    bool showSmallMapIcons;
private: char pad13[0x2]; public:
    float longestGoldFever;
    float highestGoldFever;
    bool hasUsedMirror;
    bool hasUsedTrumpet;
private: char pad14[0x2]; public:
    Il2CppList<CharacterType>* boughtCharacters;
    Il2CppList<SkinType>* boughtSkins;
    Il2CppList<PowerUpLevel>* boughtPowerups;
    Il2CppList<WeaponType>* collectedWeapons;
    Il2CppList<WeaponType>* unlockedWeapons;
    Il2CppList<CharacterType>* unlockedCharacters;
    Il2CppList<CharacterType>* hostOnlyUnlockedCharacters;
    Il2CppList<CharacterType>* openedCoffins;
    Il2CppList<ItemType>* collectedItems;
    Il2CppList<AchievementType>* achievements;
    Il2CppList<SecretType>* secrets;
    Il2CppList<StageType>* unlockedStages;
    Il2CppList<StageType>* unlockedHypers;
    Il2CppList<PowerUpType>* unlockedPowerUpRanks;
    Il2CppList<ArcanaType>* unlockedArcanas;
    Il2CppList<PowerUpType>* disabledPowerups;
    Il2CppDictionary<EnemyType, int>* KillCount;
    Il2CppDictionary<ItemType, int>* pickupCount;
    Il2CppDictionary<PropType, int>* destroyedCount;
    Il2CppDictionary<CharacterType, Il2CppList<StageType>*>* stageCompletionLog;
    Il2CppDictionary<CharacterType, Il2CppList<CharacterStageData*>*>* characterStageData;
    Il2CppDictionary<CharacterType, int>* characterEnemiesKilled;
    Il2CppDictionary<CharacterType, int>* characterSurvivedMinutes;
    Il2CppDictionary<CharacterType, Il2CppList<SkinType>*>* unlockedSkins;
    Il2CppDictionary<CharacterType, Il2CppList<SkinType>*>* unlockedSkinsV2;
    Il2CppDictionary<CharacterType, int>* selectedSkins;
    Il2CppDictionary<CharacterType, SkinType>* selectedSkinsV2;
    Il2CppDictionary<StageType, BgmType>* musicSelectionPerStage;
    Il2CppString* checksum;
    Il2CppDictionary<CharacterType, Il2CppDictionary<Il2CppString*, float>*>* characterEggInfo;
    Il2CppDictionary<CharacterType, float>* characterEggCount;
    float totalEggCount;
    bool didIt;
private: char pad15[0x3]; public:
    int seals;
private: char pad16[0x4]; public:
    Il2CppList<ItemType>* SealedItems;
    Il2CppList<WeaponType>* SealedWeapons;
    Il2CppList<ItemType>* ContentGroupSealedItems;
    Il2CppList<WeaponType>* ContentGroupSealedWeapons;
    bool enableBonusAdsMechanics;
    bool screenShakeEnabled;
    bool controllerVibrationEnabled;
    bool assignControllerToPlayer1;
    bool popupsShouldFollowPriority;
    bool showPlayerIndicators;
    bool permanentCoopOutlines;
    bool tintUISelection;
    Il2CppArrayT<unsigned int>* playerColours;
    bool sequentialChestMode;
    bool hideDebugUI;
    bool hideGameUI;
    bool disableMovingBackground;
    bool disableBlood;
private: char pad17[0x3]; public:
    BorderType borderType;
    bool pixelFont;
    bool displayDefangedEnemies;
    bool stageLighting;
    bool hasSeenAdventureReveal;
    CollectionsPageFilterType collectionFilterMode;
    bool shouldPlayAdventureReveal;
    bool hideUnavailableAdventures;
    bool hasSeenAdventuresIntroTutorial;
private: char pad18[0x1]; public:
    float adventureStars;
    bool hasPlayedStage3;
    bool hasSeenDarkanaTransition;
    bool hasFixedSkinIds;
private: char pad19[0x1]; public:
    Il2CppList<ContentGroupType>* banishedContentGroups;
    bool showTPCredits;
private: char pad20[0x3]; public:
    int TP_FrozenShadesCount;
    int TP_AxeArmorCount;
    int TP_SniperCount;
    int TP_PortraitsCount;
    int libraryMerchantGoldSpent;
    bool passedGaeaEvent;
private: char pad21[0x3]; public:
    int EME_NextBossBiome;
    int WW_ZoneProgress;
    Nullable<AdventureType> selectedAdventureTypeValue;
    int adventureCompletionCount;
    Il2CppList<AdventureAchievementType>* adventureProgress;
    Il2CppDictionary<AdventureType, PlayerOptionsData*>* adventuresSaveData;
    float totalAdventurePlaytime;
    float allTimeAdventurePlaytime;
    Il2CppDictionary<PowerUpType, int>* ascensionPointsAllocation;
    Il2CppList<AdventureType>* completedAdventures;
    bool hasSeenMerchantTutorial;
private: char pad22[0x7]; public: //nothing here
    Il2CppList<AdventureType>* seenAscensionPopups;
    Il2CppDictionary<PropType, int>* runDestroyedProps;
    Il2CppDictionary<ItemType, int>* runItemsPickupCount;
    StageType nextAutoSelectStage;
private: char pad23[0x4]; public: //nothing here
    Il2CppDictionary<int, CoopSelections*>* multiplayerSelections;
    Il2CppList<CharacterType>* onlineMultiplayerSelections;
    //end
};
#pragma pack(pop)
//constexpr int hovertrick = offsetof(PlayerOptionsData, soundsVolume);
static_assert(offsetof(PlayerOptionsData, saveSyncPlatformAchievements) == 0x20);
static_assert(offsetof(PlayerOptionsData, saveOriginalPlatform) == 0x24);
static_assert(offsetof(PlayerOptionsData, itemsInCollection) == 0x38);
static_assert(offsetof(PlayerOptionsData, itemsInUnlocks) == 0x3C);
static_assert(offsetof(PlayerOptionsData, itemsInSecrets) == 0x40);
static_assert(offsetof(PlayerOptionsData, selectedCharacter) == 0x44);
static_assert(offsetof(PlayerOptionsData, selectedStage) == 0x48);
static_assert(offsetof(PlayerOptionsData, selectedHyper) == 0x4C);
static_assert(offsetof(PlayerOptionsData, selectedLimitBreak) == 0x50);
static_assert(offsetof(PlayerOptionsData, selectedSharePassives) == 0x54);
static_assert(offsetof(PlayerOptionsData, selectedArcana) == 0x58);
static_assert(offsetof(PlayerOptionsData, selectedSurvarots) == 0x5C);
static_assert(offsetof(PlayerOptionsData, forcedSurvarots) == 0x5D);
static_assert(offsetof(PlayerOptionsData, inGameFoundSurvarots) == 0x60);
static_assert(offsetof(PlayerOptionsData, selectedRandomEvents) == 0x64);
static_assert(offsetof(PlayerOptionsData, selectedBGMSave) == 0x66);
static_assert(offsetof(PlayerOptionsData, selectedBGM) == 0x68);
static_assert(offsetof(PlayerOptionsData, bgmModType) == 0x6C);
static_assert(offsetof(PlayerOptionsData, selectedMaxWeapons) == 0x78);
static_assert(offsetof(PlayerOptionsData, isFullscreen) == 0x7C);
static_assert(offsetof(PlayerOptionsData, version) == 0x80);
static_assert(offsetof(PlayerOptionsData, coins) == 0x84);
static_assert(offsetof(PlayerOptionsData, inGameCoins) == 0x88);
static_assert(offsetof(PlayerOptionsData, kills) == 0x8C);
static_assert(offsetof(PlayerOptionsData, bossKills) == 0x90);
static_assert(offsetof(PlayerOptionsData, inGamePickups) == 0x98);
static_assert(offsetof(PlayerOptionsData, inGameWeapons) == 0xA0);
static_assert(offsetof(PlayerOptionsData, inGameCoffins) == 0xA8);
static_assert(offsetof(PlayerOptionsData, inGameBossesTypes) == 0xB0);
static_assert(offsetof(PlayerOptionsData, inGameStarryHeavnes) == 0xB8);
static_assert(offsetof(PlayerOptionsData, lifetimeCoins) == 0xCC);
static_assert(offsetof(PlayerOptionsData, totalCoins) == 0xD0);
static_assert(offsetof(PlayerOptionsData, reducePhysics) == 0x108);
static_assert(offsetof(PlayerOptionsData, language) == 0x128);
static_assert(offsetof(PlayerOptionsData, showPickups) == 0x138);
static_assert(offsetof(PlayerOptionsData, longestGoldFever) == 0x13C);
static_assert(offsetof(PlayerOptionsData, highestGoldFever) == 0x140);
static_assert(offsetof(PlayerOptionsData, hasUsedMirror) == 0x144);
static_assert(offsetof(PlayerOptionsData, boughtCharacters) == 0x148);
static_assert(offsetof(PlayerOptionsData, boughtSkins) == 0x150);
static_assert(offsetof(PlayerOptionsData, boughtPowerups) == 0x158);
static_assert(offsetof(PlayerOptionsData, collectedWeapons) == 0x160);
static_assert(offsetof(PlayerOptionsData, achievements) == 0x190);
static_assert(offsetof(PlayerOptionsData, checksum) == 0x228);
static_assert(offsetof(PlayerOptionsData, totalEggCount) == 0x240);
static_assert(offsetof(PlayerOptionsData, seals) == 0x248);
static_assert(offsetof(PlayerOptionsData, screenShakeEnabled) == 0x271);
static_assert(offsetof(PlayerOptionsData, tintUISelection) == 0x277);
static_assert(offsetof(PlayerOptionsData, sequentialChestMode) == 0x280);
static_assert(offsetof(PlayerOptionsData, disableBlood) == 0x284);
static_assert(offsetof(PlayerOptionsData, borderType) == 0x288);
static_assert(offsetof(PlayerOptionsData, pixelFont) == 0x28C);
static_assert(offsetof(PlayerOptionsData, hasSeenAdventureReveal) == 0x28F);
static_assert(offsetof(PlayerOptionsData, shouldPlayAdventureReveal) == 0x294);
static_assert(offsetof(PlayerOptionsData, adventureStars) == 0x298);
static_assert(offsetof(PlayerOptionsData, hasPlayedStage3) == 0x29C);
static_assert(offsetof(PlayerOptionsData, hasFixedSkinIds) == 0x29E);
static_assert(offsetof(PlayerOptionsData, showTPCredits) == 0x2A8);
static_assert(offsetof(PlayerOptionsData, TP_FrozenShadesCount) == 0x2AC);
static_assert(offsetof(PlayerOptionsData, EME_NextBossBiome) == 0x2C4);
static_assert(offsetof(PlayerOptionsData, adventureCompletionCount) == 0x2D4);
static_assert(offsetof(PlayerOptionsData, adventureProgress) == 0x2D8);
static_assert(offsetof(PlayerOptionsData, completedAdventures) == 0x2F8);
static_assert(offsetof(PlayerOptionsData, hasSeenMerchantTutorial) == 0x300);
static_assert(offsetof(PlayerOptionsData, seenAscensionPopups) == 0x308);
static_assert(offsetof(PlayerOptionsData, nextAutoSelectStage) == 0x320);
static_assert(offsetof(PlayerOptionsData, onlineMultiplayerSelections) == 0x330);

#pragma pack(push, 1)
struct PlayerModifierStats
{
    Il2CppObjectBase obj;
    EggFloat* Might;
    EggFloat* Area;
    EggFloat* ProjectileSpeed;
    EggFloat* MoveSpeed;
    EggFloat* Growth;
    EggFloat* Luck;
    EggFloat* Duration;
    EggFloat* Cooldown;
    EggFloat* Amount;
    EggFloat* Armor;
    EggFloat* Greed;
    EggFloat* Regen;
    EggFloat* ReRolls;
    EggFloat* Skips;
    EggFloat* MaxHp;
    EggFloat* Magnet;
    EggFloat* Curse;
    EggFloat* Banishes;
    EggDouble* Revivals;
    int UsedRevivals;
    float Shroud;
    float Shields;
    int Charm;
    float Defang;
    float Thorns;
    float InvulTimeBonus;
    float Fever;
    float Recycle;
};
struct MagnetZone
{
    private: char pad0[0x68]; public:
    CharacterController* targetCharacter;
    EggFloat* Radius;
};

struct HyperMod
{
    Il2CppObjectBase obj;
    float rate;
    int detune;
};
struct ForsakenMod
{
    Il2CppObjectBase obj;
    float rate;
    int detune;
};
struct MusicData
{
    Il2CppObjectBase obj;
    Il2CppString* title;
    Il2CppString* author;
    Il2CppString* source;
private: char pad1[0x18]; public:
    bool isUnlocked;
private: char pad2[0x7]; public:
    Il2CppString* icon;
    HyperMod* hyperMod;
	ForsakenMod* forsakenMod;
};
//constexpr int hovertrick = offsetof(MusicData, allMusicData);
static_assert(offsetof(MusicData, title) == 0x10);
static_assert(offsetof(MusicData, author) == 0x18);
static_assert(offsetof(MusicData, isUnlocked) == 0x40);
static_assert(offsetof(MusicData, icon) == 0x48);

struct GameSessionData
{
    Il2CppObjectBase obj;
    CharacterController* activeCharacter;
};
//constexpr int hovertrick = offsetof(GameSessionData, activeCharacter);
static_assert(offsetof(GameSessionData, activeCharacter) == 0x10);

struct PlayerOptions
{
private: char pad0[0x30]; public:
    GameSessionData* gameSessionData;
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(PlayerOptions, gameSessionData);
static_assert(offsetof(PlayerOptions, gameSessionData) == 0x30);

struct TimeMods
{
    Il2CppObjectBase obj;
    Nullable<float> Start;
    Nullable<float> HpPerMinute;
    Nullable<float> SpeedPerMinute;
};
struct StageModifiers
{
    Il2CppObjectBase obj;
    Nullable<float> TimeLimit; // 0x10
    Nullable<float> ClockSpeed; // 0x18
    Nullable<float> PlayerPxSpeed; // 0x20
    Nullable<float> EnemySpeed; // 0x28
    Nullable<float> ProjectileSpeed; // 0x30
    Nullable<float> GoldMultiplier; // 0x38
    Nullable<float> EnemyHealthMultiplier; // 0x40
    Nullable<float> LuckBonus; // 0x48
    Nullable<float> XpBonus; // 0x50
    Nullable<float> StartingSpawns; // 0x58
    Nullable<float> EndCycles; // 0x60
    TimeMods* TimeMods; // 0x68
    bool unlocked; // 0x70
private: char pad1[0x3]; public:
    float EnemyMinimumMul; // 0x74
    float BGM_rate; // 0x78
    int BGM_detune; // 0x7C
    bool BGM_ignoreModsForNewSoundtrack; // 0x80
private: char pad2[0x3]; public:
    float BGM_new_rate; // 0x84
    int BGM_new_detune; // 0x88
    Nullable<unsigned int> tint; // 0x8C
};

struct HardBounds
{
    Il2CppObjectBase obj;
    float x;
    float y;
    float width;
    float height;
};

struct Tileset
{
    Il2CppObjectBase obj;
    Il2CppString* setKey; // 0x10
    Il2CppString* setPath; // 0x18
    Il2CppString* mapKey; // 0x20
    Il2CppString* mapPath; // 0x28
    bool isTiling; // 0x30
    bool isHorizontalRoad; // 0x31
    bool hasWallsCheckDestructibleLogic; // 0x32
private: char pad1[0x1]; public:
    Nullable<float> SizeX; // 0x34
    Nullable<float> SizeY; // 0x3C
    Nullable<float> minTreasureX; // 0x44
    Nullable<float> maxTreasureX; // 0x4C
    Nullable<float> minTreasureY; // 0x54
    Nullable<float> maxTreasureY; // 0x5C
    Nullable<unsigned int> tint; // 0x64
    Nullable<ItemType> mapRelic; // 0x6C
    Il2CppString* detailsTexture; // 0x78
    HardBounds* hardBounds; // 0x80
};

struct TreasurePrizeTypePair
{
    Il2CppObjectBase obj;
    PrizeType prizeType;
    ItemType prizeItem;
    WeaponType prizeWeapon;
    int Level;
};

struct Treasure
{
    Il2CppObjectBase obj;
    Il2CppList<float>* chances;
    int level;
private: char pad1[0x4]; public:
    Il2CppList<Nullable<PrizeType>>* prizeTypes;
    Il2CppList<WeaponType>* fixedPrizes;
    bool hasArcana;
    bool hasRandoms;
    bool QuickTreasureAnim;
private: char pad2[0x5]; public:
    CharacterController* openingPlayer;
    CharacterController* winningPlayer;
    Il2CppList<TreasurePrizeTypePair*>* prizes;
    Il2CppList<WeaponType>* accumulatedWeaponPrizes;
    float accumulatedCoinPrize;
    float quickAddedCoins;
    Il2CppList<WeaponType>* accumulatedWorldSpacePrizes;
};
//constexpr int hovertrick = offsetof(Treasure, prizeTypes);
static_assert(offsetof(Treasure, accumulatedWorldSpacePrizes) == 0x60);

struct Background
{
    Il2CppObjectBase obj;
    Il2CppString* texture;
    Nullable<StageType> stageType;
    //done
};

struct PreloadData
{
    Il2CppObjectBase obj;
    Il2CppList<CharacterType>* characters; // 0x10
    Il2CppList<Il2CppString*>* textures; // 0x18
    Il2CppList<Il2CppString*>* videos; // 0x20
    Il2CppList<BgmType>* bgm; // 0x28
};

struct CustomMerchantData
{
    Il2CppObjectBase obj;
    CharacterType MerchantCharacter;
    Il2CppString* PortraitSprite;
    Il2CppString* PortraitSpriteTexture;
    Il2CppString* StaticSprite;
    Il2CppString* StaticSpriteTexture;
    Il2CppList<DlcType>* DLC;
    bool IsAnimated;
    bool HideBackgroundParticles;
    bool HideBackgroundWindows;
    bool HideBackgroundMask;
    Nullable<float> CustomCooldown;
    Il2CppString* TextLocKey;
    Nullable<float> MerchantXPos;
    Nullable<float> MerchantYPos;
    Nullable<Vec2> BodyOffset;
private: char pad_0001[0xC]; public:
    Il2CppList<WeaponType>* MerchantInventory;
    Il2CppList<ItemType>* MerchantInventoryItems;
};
//constexpr int hovertrick = offsetof(CustomMerchantData, MerchantInventory);
static_assert(offsetof(CustomMerchantData, MerchantInventory) == 0x78);

struct FollowerData
{
    Il2CppObjectBase obj;
    CharacterType FollowerCharacter;
    AIType FollowerAI;
    bool IsFollowerInvinceable;
    bool CountsAsMainCharacterForRevivals;
    bool ManualLevelUps;
    bool TrackedByCamera;
    bool ShouldFollowMainPlayer;
    bool AllowDuplicates;
private: char pad_0001[0x2]; public:
    int EveryXLevels;
    bool ShouldSharePassives;
    bool ShouldFollowerReactToArcanas;
};
//constexpr int hovertrick = offsetof(FollowerData, MerchantInventory);
static_assert(offsetof(FollowerData, EveryXLevels) == 0x20);

struct StageData
{
    Il2CppObjectBase obj;
    int order;
    Nullable<StageType> tilesetStageType;
private: char pad_001C[0x4]; public:
    Il2CppString* stageName;
    Il2CppString* description;
    Il2CppString* uiTexture;
    Il2CppString* uiFrame;
    Il2CppString* texture;
    Il2CppString* bestiaryBG;
    Il2CppString* stageNumber;
    Il2CppString* frameName;
    Il2CppString* frameNameUnlock;
    bool unlocked;
private: char pad_0069[0x3]; public:
    BgmType BGM;
    Nullable<BgmType> sideBBGM;
    Il2CppString* legacyBGM;
    Il2CppString* tips;
    Il2CppString* hyperTips;
    bool validForCharcaterData;
    bool hidden;
    bool alwaysHidden;
private: char pad_0093[0x5]; public:
    StageModifiers* mods;
    StageModifiers* _hyper;
    StageModifiers* inverse;
    Tileset* tileset;
    Background* background;
private: char pad_6666[0x8]; public:
    Il2CppString* spawnType;
    int startingSpawns;
    int minute;
    bool randomMinutes;
private: char pad_00D9[0x7]; public:
    Il2CppString* destructibleType;
    float destructibleFreq;
    float destructibleChance;
    float destructibleChanceMax;
    int maxDestructibles;
    Il2CppString* BGTextureName;
    Il2CppString* Extra_Texture;
    BgmType Extra_Audio;
    bool isMerchantBanned;
    bool isSpeedupBanned;
    bool hasLights;
    bool disableGlobalLight;
    bool hasCharacterSpotlight;
    bool dayNight;
private: char pad_0112[0x2]; public:
    unsigned int DayColor;
    unsigned int NightColor;
    unsigned int InverseDayColor;
    unsigned int InverseNightColor;
private: char pad_0124[0x1C]; public:
    int minimum;
    float frequency;
    Nullable<float> zoom;
    Il2CppList<Nullable<EnemyType>>* enemies;
    Il2CppList<Nullable<EnemyType>>* bosses;
    Treasure* treasure;
    Nullable<EnemyType> arcanaHolder;
    Treasure* arcanaTreasure;
    private: char pad_1232[0x8]; public:
    private: char pad_122231[0x8]; public:
    Nullable<CharacterType> cff;
    Il2CppList<ItemType>* LootTable;
    Il2CppList<ItemType>* relics;
    Il2CppList<ItemType>* relics2;
    Il2CppList<ItemType>* yellowRelics;
    PreloadData* preload;
    Il2CppList<CustomMerchantData>* adventureMerchants;
    Il2CppList<FollowerData>* defaultFollowers;
    Nullable<float> adventurePriceMarkup;
    bool isRacingStage;
    bool skipVisualInversion;
    bool allowVisualInversion;
private: char pad_01D3[0x5]; public:
    Il2CppString* biome;
    Il2CppList<Il2CppString*>* biomes;
};
//constexpr int hovertrick = offsetof(StageData, minimum);
static_assert(offsetof(StageData, order) == 0x10);
static_assert(offsetof(StageData, tilesetStageType) == 0x14);
static_assert(offsetof(StageData, stageName) == 0x20);
static_assert(offsetof(StageData, description) == 0x28);
static_assert(offsetof(StageData, uiTexture) == 0x30);
static_assert(offsetof(StageData, uiFrame) == 0x38);
static_assert(offsetof(StageData, texture) == 0x40);
static_assert(offsetof(StageData, bestiaryBG) == 0x48);
static_assert(offsetof(StageData, stageNumber) == 0x50);
static_assert(offsetof(StageData, frameName) == 0x58);
static_assert(offsetof(StageData, frameNameUnlock) == 0x60);
static_assert(offsetof(StageData, unlocked) == 0x68);
static_assert(offsetof(StageData, BGM) == 0x6C);
static_assert(offsetof(StageData, sideBBGM) == 0x70);
static_assert(offsetof(StageData, legacyBGM) == 0x78);
static_assert(offsetof(StageData, tips) == 0x80);
static_assert(offsetof(StageData, hyperTips) == 0x88);
static_assert(offsetof(StageData, validForCharcaterData) == 0x90);
static_assert(offsetof(StageData, hidden) == 0x91);
static_assert(offsetof(StageData, alwaysHidden) == 0x92);
static_assert(offsetof(StageData, mods) == 0x98);
static_assert(offsetof(StageData, _hyper) == 0xA0);
static_assert(offsetof(StageData, inverse) == 0xA8);
static_assert(offsetof(StageData, tileset) == 0xB0);
static_assert(offsetof(StageData, background) == 0xB8);
static_assert(offsetof(StageData, spawnType) == 0xC8);
static_assert(offsetof(StageData, startingSpawns) == 0xD0);
static_assert(offsetof(StageData, minute) == 0xD4);
static_assert(offsetof(StageData, randomMinutes) == 0xD8);
static_assert(offsetof(StageData, destructibleType) == 0xE0);
static_assert(offsetof(StageData, destructibleFreq) == 0xE8);
static_assert(offsetof(StageData, destructibleChance) == 0xEC);
static_assert(offsetof(StageData, destructibleChanceMax) == 0xF0);
static_assert(offsetof(StageData, maxDestructibles) == 0xF4);
static_assert(offsetof(StageData, BGTextureName) == 0xF8);
static_assert(offsetof(StageData, Extra_Texture) == 0x100);
static_assert(offsetof(StageData, Extra_Audio) == 0x108);
static_assert(offsetof(StageData, isMerchantBanned) == 0x10C);
static_assert(offsetof(StageData, isSpeedupBanned) == 0x10D);
static_assert(offsetof(StageData, hasLights) == 0x10E);
static_assert(offsetof(StageData, disableGlobalLight) == 0x10F);
static_assert(offsetof(StageData, hasCharacterSpotlight) == 0x110);
static_assert(offsetof(StageData, dayNight) == 0x111);
static_assert(offsetof(StageData, DayColor) == 0x114);
static_assert(offsetof(StageData, NightColor) == 0x118);
static_assert(offsetof(StageData, InverseDayColor) == 0x11C);
static_assert(offsetof(StageData, InverseNightColor) == 0x120);
static_assert(offsetof(StageData, minimum) == 0x140);
static_assert(offsetof(StageData, frequency) == 0x144);
static_assert(offsetof(StageData, zoom) == 0x148);
static_assert(offsetof(StageData, enemies) == 0x150);
static_assert(offsetof(StageData, bosses) == 0x158);
static_assert(offsetof(StageData, treasure) == 0x160);
static_assert(offsetof(StageData, arcanaHolder) == 0x168);
static_assert(offsetof(StageData, arcanaTreasure) == 0x170);
static_assert(offsetof(StageData, cff) == 0x188);
static_assert(offsetof(StageData, LootTable) == 0x190);
static_assert(offsetof(StageData, relics) == 0x198);
static_assert(offsetof(StageData, relics2) == 0x1A0);
static_assert(offsetof(StageData, yellowRelics) == 0x1A8);
static_assert(offsetof(StageData, preload) == 0x1B0);
static_assert(offsetof(StageData, adventureMerchants) == 0x1B8);
static_assert(offsetof(StageData, defaultFollowers) == 0x1C0);
static_assert(offsetof(StageData, adventurePriceMarkup) == 0x1C8);
static_assert(offsetof(StageData, isRacingStage) == 0x1D0);
static_assert(offsetof(StageData, skipVisualInversion) == 0x1D1);
static_assert(offsetof(StageData, allowVisualInversion) == 0x1D2);
static_assert(offsetof(StageData, biome) == 0x1D8);
static_assert(offsetof(StageData, biomes) == 0x1E0);

struct PowerUpData
{
    Il2CppObjectBase obj;
    int level;
    bool hidden;
private: char pad1[0x3]; public:
    Il2CppString* bulletType;
    Il2CppString* name;
    Il2CppString* description;
    Il2CppString* texture;
    Il2CppString* frameName;
    bool isPowerUp;
    bool isAnUnlockable;
private: char pad2[0x2]; public:
    int price;
    int unlockedRank;
    bool isSpecial;
    bool specialBG;
};
//constexpr int hovertrick = offsetof(PowerUpData, level);
static_assert(offsetof(PowerUpData, level) == 0x10);
static_assert(offsetof(PowerUpData, bulletType) == 0x18);
static_assert(offsetof(PowerUpData, price) == 0x44);
static_assert(offsetof(PowerUpData, specialBG) == 0x4D);

struct DataManager
{
private: char pad0[0x18]; public:
    PlayerOptions* playerOptions;
    Il2CppDictionary<CharacterType, Il2CppList<CharacterData*>*>* characterData;
    Il2CppDictionary<PowerUpType, Il2CppList<PowerUpData*>*>* powerUpData;
    Il2CppDictionary<StageType, Il2CppList<StageData*>*>* stageData;
    Il2CppDictionary<WeaponType, Il2CppList<WeaponData*>*>* weaponData;
    Il2CppDictionary<EnemyType, Il2CppList<EnemyData*>*>* enemyData;
    bool characterDataChangedForOnline;
    bool powerUpDataChangedForOnline;
    bool stageDataChangedForOnline;
    bool weaponDataChangedForOnline;
    bool enemyDataChangedForOnline;
private: char pad1[0x3]; public:
    Il2CppDictionary<DlcType, Il2CppDictionary<CharacterType, Il2CppList<CharacterData*>*>*>* dlcCharacterData;
    Il2CppDictionary<DlcType, Il2CppDictionary<PowerUpType, Il2CppList<PowerUpData*>*>*>* dlcPowerUpData;
    Il2CppDictionary<DlcType, Il2CppDictionary<StageType, Il2CppList<StageData*>*>*>* dlcStageData;
    Il2CppDictionary<DlcType, Il2CppDictionary<WeaponType, Il2CppList<WeaponData*>*>*>* dlcWeaponData;
    Il2CppDictionary<DlcType, Il2CppDictionary<EnemyType, Il2CppList<EnemyData*>*>*>* dlcEnemyData;
    Il2CppDictionary<DlcType, Il2CppDictionary<BgmType, MusicData*>*>* dlcMusicData;
private: char pad2[0x118]; public:
    Il2CppDictionary<BgmType, MusicData*>* allMusicData;
};
//constexpr int hovertrick = offsetof(DataManager, allMusicData);
static_assert(offsetof(DataManager, playerOptions) == 0x18);
static_assert(offsetof(DataManager, dlcCharacterData) == 0x50);
static_assert(offsetof(DataManager, allMusicData) == 0x198);

struct MainMenuPage
{
private: char pad0[0x248]; public:
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(MainMenuPage, dataManager);
static_assert(offsetof(MainMenuPage, dataManager) == 0x248);

struct CharacterSelectionPage
{
private: char pad0[0x238]; public:
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(struct CharacterSelectionPage
static_assert(offsetof(CharacterSelectionPage, dataManager) == 0x238);

struct StageSelectPage
{
private: char pad0[0x1F0]; public:
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(StageSelectPage, dataManager);
static_assert(offsetof(StageSelectPage, dataManager) == 0x1F0);

struct PausePage
{
private: char pad0[0x1B0]; public:
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(PausePage, dataManager);
static_assert(offsetof(PausePage, dataManager) == 0x1B0);

struct Stage
{
private: char pad0[0x40]; public:
    StageType stageType;
    int currentMinute;
    int maxStageDataMinute;
    int maximum;
    int lastMinimum;
    int lastMaximum;
    int defaultMaximum;
    float minMultiplier;
    float onlineEnemyMultiplier;
    float effectiveSpawnFrequency;
private: char pad1[0x20]; public:
    bool hasTileSet;
private: char pad2[0x3]; public:
    SpawnType spawnType;
    bool hasAttachedTreasure;
    bool compressTime;
private: char pad3[0x2]; public:
    float pizzaDelay;
private: char pad4[0x30]; public:
    Il2CppList<Vec2>* cartLocations;
    Il2CppList<Vec2>* windowLocations;
    Il2CppList<Vec2>* pizzaLocations;
private: char pad5[0x8]; public:
    Il2CppList<Vec2>* tiledPositions;
private: char pad6[0x10]; public:
    bool shadowsVisible;
private: char pad7[0xA0]; public:
    bool isCharmApplied;
    bool disableMinueteSpawning;
private: char pad8[0xD]; public:
    void* mainCamera;
private: char pad9[0x8]; public:
    DataManager* dataManager;
};
//constexpr int hovertrick = offsetof(Stage, dataManager);
static_assert(offsetof(Stage, hasTileSet) == 0x88);
static_assert(offsetof(Stage, spawnType) == 0x8C);
static_assert(offsetof(Stage, pizzaDelay) == 0x94);
static_assert(offsetof(Stage, cartLocations) == 0xC8);
static_assert(offsetof(Stage, tiledPositions) == 0xE8);
static_assert(offsetof(Stage, shadowsVisible) == 0x100);
static_assert(offsetof(Stage, isCharmApplied) == 0x1A1);
static_assert(offsetof(Stage, mainCamera) == 0x1B0);
static_assert(offsetof(Stage, dataManager) == 0x1C0);

struct PlayerStat
{
    Il2CppObjectBase obj;
    PowerUpType type;
    int level; 
    Il2CppList<PowerUpData*>* data;
    double value;
};
struct PlayerStats
{
    Il2CppObjectBase obj;
    DataManager* dataManager;
    PlayerOptions* playerOptions;
    void* signalBus;
    int totalPowerUpCount;
private: char pad0[0x4]; public:
    Il2CppDictionary<PowerUpType, PlayerStat*>* stats;
};
//constexpr int hovertrick = offsetof(PlayerStats, stats);
static_assert(offsetof(PlayerStats, stats) == 0x30);

struct GameManager
{
private: char pad0[0x30]; public:
    MagnetZone* magnetZonePrefab;
private: char pad1[0x68]; public:
    LootManager* lootManager;
    WeaponsFacade* weaponsFacade;
private: char pad2[0x8]; public:
    Stage* stage;
private: char pad3[0x20]; public:
    GameSessionData* gameSessionData;
    LevelUpFactory* levelUpFactory;
private: char pad4[0x18]; public:
    DataManager* dataManager;
    PlayerStats* playerStats;
    ArcanaManager* arcanaManager;
private: char pad6[0x178]; public:
    Il2CppList<CharacterController*>* characters;
    Il2CppList<CharacterController*>* mainCharacters;
    Il2CppList<CharacterController*>* charactersLevelingUp;
private: char pad7[0x130]; public:
    float survivedSeconds;
};
//constexpr int hovertrick = offsetof(GameManager, survivedSeconds);
static_assert(offsetof(GameManager, lootManager) == 0xA0);
static_assert(offsetof(GameManager, stage) == 0xB8);
static_assert(offsetof(GameManager, gameSessionData) == 0xE0);
static_assert(offsetof(GameManager, dataManager) == 0x108);
static_assert(offsetof(GameManager, arcanaManager) == 0x118);
static_assert(offsetof(GameManager, characters) == 0x298);
static_assert(offsetof(GameManager, charactersLevelingUp) == 0x2A8);
static_assert(offsetof(GameManager, survivedSeconds) == 0x3E0);

struct ArcadeBodyBounds
{
private: char pad0[0x20]; public:
    float x; // 0x20
    float y; // 0x24
    float width; // 0x28
    float height; // 0x2C
};
struct CharacterController
{
private: char pad0[0x58]; public://nothing useful up to here
    Vec2 currentDefaultMapPosition;
    unsigned int randomEnemyPickerSeed;
    int playerIndex;
private: char pad1[0x20]; public:
    GameManager* gameManager;
private: char pad1a[0x28]; public:
    void* cachedTransform;
private: char pad1b[0x50]; public:
    CharacterData* currentCharacterData;
    CharacterData* currentSkinData;
    CharacterData* levelZeroCharacterData;
    Il2CppList<WeaponType>* weaponSelection;
    WeaponType startingWeaponType;
    CharacterType characterType;
    SkinType skinType;
private: char pad2[0x1C]; public:
    bool receivingDamage;
    bool playDamageSFX;
private: char pad3[0x2]; public:
    float invincibilityTimer;
    bool hasWalkingAnimation;
    bool hasIdleAnimation;
private: char pad4[0xE]; public:
    Vec2 currentDirection;
    Vec2 currentDirectionRaw;
    Vec2 lastMovementDirection;
    bool actionButtonPressed;
private: char pad5[0xF]; public:
    ArcadeBodyBounds* worldBoxCollider;
    ArcadeBodyBounds* coopMovementBoxCollider;
private: char pad5a[0x38]; public:
    bool followPlayerOne;
private: char pad6[0x3]; public:
    float defaultSpriteWidth;
private: char pad7[0x8]; public:
    bool useWorldSpaceMovementLimits;
private: char pad8[0x27]; public:
    PlayerModifierStats* playerStats;
    float slowMultiplier;
    bool isSlow;
private: char pad9[0x3]; public:
    float hp;
    int level;
    float walked;
    Vec2 lastFacingDirection;
    float xp;
    bool isAnimForced;
    bool canFlip;
    bool isFlipped;
private: char pad10[0x1]; public:
    float shieldInvulTime;
    MagnetZone* magnetZone;
private: char pad11[0x28]; public:
    float slowTime;
    float goldFeverMultiplier;
private: char pad12[0x8]; public:
    bool isInFinalStage;
    bool isDead;
    bool isInvulnerable;
    bool isSendingDeath;
    bool isInitialized;
    bool isLastBreathEnabled;
    bool hasLastBreath;
private: char pad13[0x9]; public:
    bool isCriticalHPEnabled;
    bool hasAnyCriticalHPSkill;
private: char pad14[0xE]; public:
    float criticalHPThreshold;
    bool hasThorns;
private: char pad15[0x3]; public:
    int maxWeaponCount;
    int maxPassiveCount;
    int maxWeaponBonus;
    int maxAccessoryBonus;
private: char pad16[0x40]; public:
    float debuffSlow;
private: char pad17[0x2C]; public:
    bool multiplayerRevivalAllowed;
private: char pad18[0x17]; public:
    PickupMode pickupMode;
    bool permanentInvulnerability;
    bool blockInput;
    bool trackedByCamera;
private: char pad19[0x1]; public:
    float moveSpeedMultiplier;
    float armorManualIncrease;
    Il2CppList<WeaponType>* glimmeredTechniques;
private: char pad20[0x30]; public:
    float skillCardsMultiplier;
    float tempCurse;
    unsigned int followerLevelUpShuffleSeed;
    bool alwaysCoinBag;
    bool alwaysRoast;
    bool alwaysRandomLimitBreak;
    bool isFollowerSharingPassives;
    bool isFollowerReactingToArcanas;
private: char pad21[0x3]; public:
    Vec2 externalVelocity;
    bool CountsAsMainCharacterForRevivals;
private: char pad22[0x3]; public:
    float silentCooldown;
    float silentMight;
    Il2CppString* currentWalkAnimName;
    bool isPlatformMovementActive;
private: char pad23[0x3]; public:
    float rapidFireLife;
    float barrierNumber;
private: char pad24[0xC]; public:
    bool hasFourthLevelUpOption;
private: char pad25[0x7]; public:
    Il2CppList<Weapon*>* HeldShieldSlots;
    SfxType damageSound;
    float damageVolume;
    float damageBaseDetune;
    bool hasForcedSortingOrder;
private: char pad26[0x3]; public:
    int forcedSortingOrder;
};
//constexpr int hovertrick = offsetof(CharacterController, pickupMode);
static_assert(offsetof(CharacterController, currentDefaultMapPosition) == 0x58);
static_assert(offsetof(CharacterController, playerIndex) == 0x64);
static_assert(offsetof(CharacterController, gameManager) == 0x88);
static_assert(offsetof(CharacterController, cachedTransform) == 0xB8);
static_assert(offsetof(CharacterController, receivingDamage) == 0x158);
static_assert(offsetof(CharacterController, playDamageSFX) == 0x159);
static_assert(offsetof(CharacterController, invincibilityTimer) == 0x15C);
static_assert(offsetof(CharacterController, hasWalkingAnimation) == 0x160);
static_assert(offsetof(CharacterController, hasIdleAnimation) == 0x161);
static_assert(offsetof(CharacterController, currentDirection) == 0x170);
static_assert(offsetof(CharacterController, currentDirectionRaw) == 0x178);
static_assert(offsetof(CharacterController, lastMovementDirection) == 0x180);
static_assert(offsetof(CharacterController, actionButtonPressed) == 0x188);
static_assert(offsetof(CharacterController, worldBoxCollider) == 0x198);
static_assert(offsetof(CharacterController, coopMovementBoxCollider) == 0x1A0);
static_assert(offsetof(CharacterController, followPlayerOne) == 0x1E0);
static_assert(offsetof(CharacterController, defaultSpriteWidth) == 0x1E4);
static_assert(offsetof(CharacterController, useWorldSpaceMovementLimits) == 0x1F0);
static_assert(offsetof(CharacterController, playerStats) == 0x218);
static_assert(offsetof(CharacterController, slowMultiplier) == 0x220);
static_assert(offsetof(CharacterController, isSlow) == 0x224);
static_assert(offsetof(CharacterController, hp) == 0x228);
static_assert(offsetof(CharacterController, level) == 0x22C);
static_assert(offsetof(CharacterController, walked) == 0x230);
static_assert(offsetof(CharacterController, lastFacingDirection) == 0x234);
static_assert(offsetof(CharacterController, xp) == 0x23C);
static_assert(offsetof(CharacterController, isAnimForced) == 0x240);
static_assert(offsetof(CharacterController, canFlip) == 0x241);
static_assert(offsetof(CharacterController, isFlipped) == 0x242);
static_assert(offsetof(CharacterController, shieldInvulTime) == 0x244);
static_assert(offsetof(CharacterController, magnetZone) == 0x248);
static_assert(offsetof(CharacterController, slowTime) == 0x278);
static_assert(offsetof(CharacterController, goldFeverMultiplier) == 0x27C);
static_assert(offsetof(CharacterController, isInFinalStage) == 0x288);
static_assert(offsetof(CharacterController, isDead) == 0x289);
static_assert(offsetof(CharacterController, isInvulnerable) == 0x28A);
static_assert(offsetof(CharacterController, isSendingDeath) == 0x28B);
static_assert(offsetof(CharacterController, isInitialized) == 0x28C);
static_assert(offsetof(CharacterController, isLastBreathEnabled) == 0x28D);
static_assert(offsetof(CharacterController, hasLastBreath) == 0x28E);
static_assert(offsetof(CharacterController, isCriticalHPEnabled) == 0x298);
static_assert(offsetof(CharacterController, hasAnyCriticalHPSkill) == 0x299);
static_assert(offsetof(CharacterController, criticalHPThreshold) == 0x2A8);
static_assert(offsetof(CharacterController, hasThorns) == 0x2AC);
static_assert(offsetof(CharacterController, maxWeaponCount) == 0x2B0);
static_assert(offsetof(CharacterController, maxPassiveCount) == 0x2B4);
static_assert(offsetof(CharacterController, maxWeaponBonus) == 0x2B8);
static_assert(offsetof(CharacterController, maxAccessoryBonus) == 0x2BC);
static_assert(offsetof(CharacterController, debuffSlow) == 0x300);
static_assert(offsetof(CharacterController, multiplayerRevivalAllowed) == 0x330);
static_assert(offsetof(CharacterController, pickupMode) == 0x348);
static_assert(offsetof(CharacterController, permanentInvulnerability) == 0x34C);
static_assert(offsetof(CharacterController, blockInput) == 0x34D);
static_assert(offsetof(CharacterController, moveSpeedMultiplier) == 0x350);
static_assert(offsetof(CharacterController, armorManualIncrease) == 0x354);
static_assert(offsetof(CharacterController, tempCurse) == 0x394);
static_assert(offsetof(CharacterController, rapidFireLife) == 0x3C4);
static_assert(offsetof(CharacterController, barrierNumber) == 0x3C8);
static_assert(offsetof(CharacterController, hasFourthLevelUpOption) == 0x3D8);
static_assert(offsetof(CharacterController, damageSound) == 0x3E8);
static_assert(offsetof(CharacterController, damageVolume) == 0x3EC);
static_assert(offsetof(CharacterController, damageBaseDetune) == 0x3F0);
static_assert(offsetof(CharacterController, hasForcedSortingOrder) == 0x3F4);
static_assert(offsetof(CharacterController, forcedSortingOrder) == 0x3F8);

struct ColliderOverride
{
    Il2CppObjectBase obj;
    float radius;
    float offsetX;
    float offsetY;
    bool updateBasedOnFlipX;
    float offsetXWhenFlipped;
};

struct EnemyData
{
    Il2CppObjectBase obj;
    int level;
    float maxHp;
    float speed;
    float maxSpeed;
    float power;
private: char pad1[0x4]; public:
    Il2CppList<EnemySkillType>* skills;
    Nullable<int> minimumHpScalingLevel;
    Nullable<int> maximumHpScalingLevel;
    float shieldDuration;
    float knockback;
    float maxKnockback;
    float deathKB;
    Nullable<unsigned int> tint;
    float xp;
    int moreX;
    int moreY;
    float alpha;
    Nullable<float> scale;
    Nullable<float> res_Freeze;
    Nullable<float> res_Rosary;
    Nullable<float> res_Debuffs;
    Nullable<float> res_Knockback;
    Nullable<float> res_Corridor;
    Nullable<float> res_Defang;
    bool passThroughWalls;
    bool CannotBeFollower;
private: char pad2[0x6]; public:
    ColliderOverride* colliderOverride;
    Nullable<float> weakFire;
    bool skipCredits;
private: char pad3[0x3]; public:
    int idleFrameCount;
    float killedAmount;
private: char pad4[0x4]; public:
    Il2CppString* textureName;
    int end;
private: char pad5[0x4]; public:
    Il2CppList<Il2CppString*>* frameNames;
    float patrolDuration;
    Nullable<float> fireDelay;
    Nullable<float> fireDelayRandomness;
    Nullable<float> firingRangeMin;
    Nullable<float> firingRangeMax;
    Nullable<EnemyType> bulletType;
    Nullable<int> lives;
private: char pad6[0x4]; public:
    Il2CppString* flagName;
    EnemyData* alias;
    float feverValue;
private: char pad7[0x4]; public:
    Il2CppString* bName;
    Il2CppString* bDesc;
    Il2CppList<StageType>* bPlaces;
    bool bInclude;
    bool bIgnore;
    bool bHighlight;
private: char pad8[0x5]; public:
    Il2CppList<EnemyType>* bVariants;
    bool bIncludeColorVariants;
private: char pad9[0x3]; public:
    MaterialType materialType;
    Il2CppList<Il2CppString*>* Internal_FrameNamesAnim;
    Il2CppList<Il2CppList<Il2CppString*>*>* Internal_IdleAnimFrameNames;
    Il2CppList<Il2CppList<Il2CppString*>*>* Internal_DeathAnimFrameNames;
};
//constexpr int hovertrick = offsetof(EnemyData, skills);
static_assert(offsetof(EnemyData, level) == 0x10);
static_assert(offsetof(EnemyData, maxHp) == 0x14);
static_assert(offsetof(EnemyData, speed) == 0x18);
static_assert(offsetof(EnemyData, maxSpeed) == 0x1C);
static_assert(offsetof(EnemyData, power) == 0x20);
static_assert(offsetof(EnemyData, skills) == 0x28);
static_assert(offsetof(EnemyData, minimumHpScalingLevel) == 0x30);
static_assert(offsetof(EnemyData, shieldDuration) == 0x40);
static_assert(offsetof(EnemyData, xp) == 0x58);
static_assert(offsetof(EnemyData, passThroughWalls) == 0xA0);
static_assert(offsetof(EnemyData, CannotBeFollower) == 0xA1);
static_assert(offsetof(EnemyData, colliderOverride) == 0xA8);
static_assert(offsetof(EnemyData, weakFire) == 0xB0);
static_assert(offsetof(EnemyData, textureName) == 0xC8);
static_assert(offsetof(EnemyData, flagName) == 0x118);
static_assert(offsetof(EnemyData, bVariants) == 0x150);
static_assert(offsetof(EnemyData, materialType) == 0x15C);

struct EnemyController
{
private: char pad0[0x60]; public:
    bool killedByAuthority;
private: char pad1[0x2F]; public:
    GameSessionData* gameSessionData;
    GameManager* gameManager;
    DataManager* dataManager;
private: char pad2[0x8]; public:
    EnemyData* currentEnemyData;
    bool hasInitializedData;
private: char pad3[0x7]; public:
    PlayerOptions* playerOptions;
private: char pad4[0x38]; public:
    bool receivingDamage;
    bool passThroughWalls;
private: char pad5[0xA]; public:
    bool selfDestruct;
    bool isSelfDestructionTriggered;
private: char pad6[0x6]; public:
    float startingAngle;
private: char pad7[0xC]; public:
    bool hasATreasure;
private: char pad8[0xB]; public:
    float wiggleProgress;
    bool wiggleForward;
    bool wiggleInit;
private: char pad9[0x4A]; public:
    Vec2 spritePivot;
    bool canBeDamagedByBloodline;
private: char pad10[0xF]; public:
    bool allowAnimationPauseResume;
private: char pad11[0x3]; public:
    EnemyType enemyType;
    float damageKb;
    float defaultSpeed;
    float scaleMul;
    bool hpXLevel;
    bool fixedDirection;
    bool medusa;
private: char pad12[0x1]; public:
    float medusaElapsed;
private: char pad13[0xC]; public:
    float alpha;
    Il2CppString* defaultName;
    float damageWeakness;
    float maxDamageWeakness;
    int multiplayerCorpseFeedingCounter;
    bool isImmuneToModification;
private: char pad14[0x7]; public:
    Vec2 currentDirection;
    float hp;
    float maxHp;
    float distance;
    float speed;
    bool isTeleportOnCull;
    bool isBoss;
    bool dontTeleportOnFreeRoam;
    bool ignoreNetworkError;
private: char pad15[0xC]; public:
    bool isCullable;
    bool isStatic;
private: char pad16[0x2A]; public:
    float weakFire;
    float slow;
    bool isPatrolling;
private: char pad17[0x3]; public:
    float knockBack;
    bool isDefanged;
    bool isTimeStopped;
    bool isTimeSlowed;
private: char pad18[0x1]; public:
    float selfDestDistance;
    int stageEventId;
    bool conditionalCanMove;
    bool ignoreMovementFreezeFromTimeStop;
private: char pad19[0xE]; public:
    bool isDead;
};
//constexpr int hovertrick = offsetof(EnemyController, isDead);
static_assert(offsetof(EnemyController, gameSessionData) == 0x90);
static_assert(offsetof(EnemyController, currentEnemyData) == 0xB0);
static_assert(offsetof(EnemyController, playerOptions) == 0xC0);
static_assert(offsetof(EnemyController, receivingDamage) == 0x100);
static_assert(offsetof(EnemyController, passThroughWalls) == 0x101);
static_assert(offsetof(EnemyController, startingAngle) == 0x114);
static_assert(offsetof(EnemyController, hasATreasure) == 0x124);
static_assert(offsetof(EnemyController, wiggleProgress) == 0x130);
static_assert(offsetof(EnemyController, wiggleForward) == 0x134);
static_assert(offsetof(EnemyController, wiggleInit) == 0x135);
static_assert(offsetof(EnemyController, spritePivot) == 0x180);
static_assert(offsetof(EnemyController, allowAnimationPauseResume) == 0x198);
static_assert(offsetof(EnemyController, enemyType) == 0x19C);
static_assert(offsetof(EnemyController, medusaElapsed) == 0x1B0);
static_assert(offsetof(EnemyController, alpha) == 0x1C0);
static_assert(offsetof(EnemyController, hp) == 0x1E8);
static_assert(offsetof(EnemyController, distance) == 0x1F0);
static_assert(offsetof(EnemyController, isCullable) == 0x208);
static_assert(offsetof(EnemyController, weakFire) == 0x234);
static_assert(offsetof(EnemyController, isDead) == 0x260);

struct HealthBar
{
private: char pad0[0x30]; public:
    CharacterController* character;
};

struct LevelUpFactory
{
    Il2CppObjectBase obj;
    float defaultXPFactor;
    float currentXpFactor;
    float previousXpFactor;
    float chanceForExistingPowerUp;
    int levelUpOptions;
    int accumulatedWeight;
    bool useDebugLog;
private: char pad1[0x7]; public:
    GameSessionData* gameSessionData; // 0x30
    void* signalBus; // 0x38
    DataManager* dataManager; // 0x40
    PlayerOptions* playerOptions; // 0x48
    void* coopConfig;//CoopConfig* 0x50
    Il2CppList<WeaponType>* unlockedWeapons; // 0x58
    Il2CppList<CharacterController*>* cachedPlayerList; // 0x60
    Il2CppList<bool>* coopAmuletBag; // 0x68
};
//constexpr int hovertrick = offsetof(LevelUpFactory, gameSessionData);
static_assert(offsetof(LevelUpFactory, gameSessionData) == 0x30);
static_assert(offsetof(LevelUpFactory, coopConfig) == 0x50);

struct WeaponsFacade
{
    Il2CppObjectBase obj;
    void* weaponFactory;//dont care for this object
    void* signalBus;//dont care for this object
    LevelUpFactory* levelUpFactory;
    PlayerOptions* playerOptions;
    ArcanaManager* arcanaManager;
    //done
};

struct WeightedItem
{
    Il2CppObjectBase obj;
    ItemType itemType;
    float weight;
    //done
};
struct LootManager
{
    Il2CppObjectBase obj;
    DataManager* dataManager;
    GameSessionData* gameSessionData;
    Stage* stage;
    float accumulatedWeight;
    Il2CppList<WeightedItem*>* weightedStore;
    Il2CppList<ItemType>* forcedLootTable;
    Il2CppList<ItemType>* addedLoot;
    //done
};

struct WickedSeason
{
    Il2CppObjectBase obj;
    void* signalBus;//dont care for this object
    bool hasWickedSeason;
private: char pad1[0x3]; public:
    float seasonTime;
    float seasonDuration;
    int seasonIndex;
    float curse;
    float growth;
    float luck;
    float greed;
    Il2CppList<Il2CppString*>* wickedSeasonAttributes;
    Il2CppList<Il2CppString*>* seasonColors;
    Il2CppList<Il2CppString*>* seasonIcons;
    Il2CppList<SfxType>* seasonSfx;
};
//constexpr int hovertrick = offsetof(WickedSeason, seasonTime);
static_assert(offsetof(WickedSeason, seasonTime) == 0x1C);

struct ArcanaManager
{
    Il2CppObjectBase obj;
    GameSessionData* gameSessionData;
    PlayerOptions* playerOptions;
    WeaponsFacade* weaponsFacade;
    DataManager* dataManager;
    void* signalBus;//dont care for this object
    GameManager* gameManager;
    LootManager* lootManager;
private: char pad1[0x28]; public:
    WickedSeason* wickedSeason;
private: char pad2[0x18]; public:
    bool hasWickedSeason;
    bool hasSilentSanctuary;
    bool hasAstronomia;
    bool hasSapphireMist;
    bool hasBreadAnathema;
    bool hasMoonlightBolero;
    bool hasHailFromTheFuture;
    bool hasJetBlackWeapon;
    bool hasCrystalCries;
    bool hasMadMoon;
    bool hasVictorianHorror;
private: char pad3[0x1]; public:
    float silentCooldown;
    float silentMight;
    float heartOfFireStartingPower;
    Il2CppDictionary<CharacterController*, Il2CppList<WeaponType>*>* beginning;
    Il2CppList<ArcanaType>* activeArcanas;
    bool healOnCoins;
    bool coinFever;
    bool madGroove;
    bool canGather;
private: char pad4[0x4]; public:
    Il2CppList<WeaponType>* heartOfFireWeapons;
    float xpMultiplier;
    float divineBloodlineHpBonusUnit;
    bool hasDivineBloodline;
private: char pad5[0x3]; public:
    int minTreasureChestLevel;
    bool pewPew;
private: char pad6[0x3]; public:
    int maxArcanasPerRun;
    //Il2CppList<Destructible*>* newDestructibles;
};
//constexpr int hovertrick = offsetof(ArcanaManager, heartOfFireWeapons);
static_assert(offsetof(ArcanaManager, wickedSeason) == 0x70);
static_assert(offsetof(ArcanaManager, hasWickedSeason) == 0x90);
static_assert(offsetof(ArcanaManager, silentCooldown) == 0x9C);
static_assert(offsetof(ArcanaManager, heartOfFireWeapons) == 0xC0);
static_assert(offsetof(ArcanaManager, maxArcanasPerRun) == 0xDC);

//dunno the real name but this is UnityPlayer.dll specific
struct UnityTime
{
private: char pad0[0x1AC]; public:
       float timeScale;//todo: find out what else we can access nearby to add to this struct
};

struct Projectile
{
private: char pad0[0x58]; public:
    bool bounceOffWalls;
private: char pad1[0xF]; public:
    Weapon* weapon;
    int indexInWeapon;
private: char pad2[0x14]; public:
    GameSessionData* gameSessionData;
private: char pad3[0x10]; public:
    float pauseWallChecksTimer;
    float speed;
    int penetrating;
    int bounces;
    bool isCullable;
    bool bounceActivated;
};
//constexpr int hovertrick = offsetof(Projectile, pauseWallChecksTimer);
static_assert(offsetof(Projectile, weapon) == 0x68);
static_assert(offsetof(Projectile, gameSessionData) == 0x88);
static_assert(offsetof(Projectile, pauseWallChecksTimer) == 0xA0);

struct WeaponData
{
    Il2CppObjectBase obj;
    bool hidden;
    bool alwaysHidden;
private: char pad_0012[0x2]; public:
    int level;
    WeaponType bulletType;
private: char pad_001C[0x4]; public:
    Il2CppString* name;
    Il2CppString* description;
    Il2CppString* tips;
    Il2CppString* texture;
    Il2CppString* frameName;
    Il2CppString* collectionFrame;
    Il2CppString* evoInto;
private: char pad_6666[0x8]; public:
    bool isEvolution;
    bool isSpecialOnly;
private: char pad_0062[0x6]; public:
    Il2CppList<WeaponType>* evolvesFrom;
    Il2CppList<WeaponType>* _requires;
    Il2CppList<WeaponType>* requiresMax;
    Il2CppList<WeaponType>* evolutionLine;
    bool isUnlocked;
private: char pad_0089[0x3]; public:
    Nullable<float> volume;
    Nullable<int> poolLimit;
    int rarity;
    float interval;
    Nullable<float> duration;
    float repeatInterval;
    float power;
    float secondaryPower;
    Nullable<float> knockback;
    Nullable<float> hitBoxDelay;
    float area;
    float speed;
    int amount;
    float critChance;
    bool hitsWalls;
private: char pad_00D9[0x3]; public:
    float critMul;
    bool seen;
private: char pad_00E1[0x3]; public:
    Nullable<WeaponType> addEvolvedWeapon;
    Nullable<WeaponType> addNormalWeapon;
    Nullable<WeaponType> excludeWeapon;
    int charges;
    bool intervalDependsOnDuration;
    bool isPowerUp;
private: char pad_0102[0x2]; public:
    int penetrating;
    HitVfxType hitVFX;
private: char pad_010C[0x4]; public:
    Il2CppList<WeaponType>* forcedSynergyWeapons;
    bool skipRemovingBaseWeapon;
    bool hasUniqueRequirements;
private: char pad_011A[0x2]; public:
    float cooldown;
    float maxHp;
    float moveSpeed;
    float growth;
    float magnet;
    float luck;
    float armor;
    float greed;
    float regen;
    float revivals;
    float rerolls;
    float skips;
    float chance;
    Il2CppString* bgm;
    Nullable<float> shieldInvulTime;
    float curse;
private: char pad_0164[0x4]; public:
    Il2CppString* desc;
    float charm;
    float fever;
    float invulTimeBonus;
    Nullable<float> customDesc;
private: char pad_0184[0x4]; public:
    Il2CppString* customDescValue;
    bool unexcludeSelf;
    bool dropRateAffectedByLuck;
    bool sealable;
private: char pad_0193[0x1]; public:
    Nullable<float> price;
    bool appliesOnlyToOwner;
    bool allowDuplicates;
    bool despawnOnUnavailable;
private: char pad_019F[0x1]; public:
    ContentGroupType contentGroup;
    CharacterType followerType;
    AIType followerAI;
};
//constexpr int hovertrick = offsetof(WeaponData, hidden);
static_assert(offsetof(WeaponData, hidden) == 0x10);
static_assert(offsetof(WeaponData, level) == 0x14);
static_assert(offsetof(WeaponData, name) == 0x20);
static_assert(offsetof(WeaponData, isUnlocked) == 0x88);
static_assert(offsetof(WeaponData, volume) == 0x8C);
static_assert(offsetof(WeaponData, poolLimit) == 0x94);
static_assert(offsetof(WeaponData, rarity) == 0x9C);
static_assert(offsetof(WeaponData, desc) == 0x168);
static_assert(offsetof(WeaponData, followerAI) == 0x1A8);

struct LimitBreakData
{
    Il2CppObjectBase obj;
    int rarity;
    Nullable<float> power;
    Nullable<float> area;
    Nullable<float> speed;
    Nullable<int> max;
    Nullable<int> penetrating;
    Nullable<int> amount;
    Nullable<float> chance;
    Nullable<int> duration;
    Nullable<float> critChance;
    Nullable<float> cooldown;
    Nullable<WeaponType> addEvolvedWeapon;
};

struct Weapon
{
private: char pad0[0x68]; public:
    Projectile* projectile;
    GameManager* gameMan;
    PlayerOptions* playerOptions;
    GameSessionData* gameSessionData;
    WeaponData* currentWeaponData;
    bool skipAddingEvolution;
private: char pad1[0x7]; public:
    Il2CppList<Projectile*>* spawnedProjectiles;
private: char pad2[0x30]; public:
    int critIndex;
private: char pad3[0x4]; public:
    Il2CppList<float>* critChancesArray;
    int bounces;
    int bonusBounces;
    float lastFiringInterval;
    bool beginningArcana;
private: char pad4[0x3]; public:
    int beginningAmount;
private: char pad5[0xC]; public:
    bool isVisible;
private: char pad6[0x3]; public:
    WeaponType explosionType;
    bool explodeOnExpire;
private: char pad7[0x17]; public:
    WeaponType secondaryOvarlapDamageType;
private: char pad8[0x4]; public:
    LimitBreakData* accumulatedLimitBreaks;
    bool isHoming;
    bool isAdept;
    bool hasCooldownSpeedBonus;
private: char pad9[0x1]; public:
    float statsInflictedDamage;
    float statsLifetime;
    bool canCrit;
private: char pad10[0x3]; public:
    float freezeChance;
    float defangChance;
    float totalTime;
    int limitBreakLevel;
    bool skipAddingNormalWeapon;
};
//constexpr int hovertrick = offsetof(Weapon, critIndex);
static_assert(offsetof(Weapon, spawnedProjectiles) == 0x98);
static_assert(offsetof(Weapon, critIndex) == 0xD0);
static_assert(offsetof(Weapon, critChancesArray) == 0xD8);
static_assert(offsetof(Weapon, beginningAmount) == 0xF0);
static_assert(offsetof(Weapon, isVisible) == 0x100);
static_assert(offsetof(Weapon, explodeOnExpire) == 0x108);
static_assert(offsetof(Weapon, secondaryOvarlapDamageType) == 0x120);
static_assert(offsetof(Weapon, accumulatedLimitBreaks) == 0x128);
static_assert(offsetof(Weapon, statsInflictedDamage) == 0x134);
static_assert(offsetof(Weapon, freezeChance) == 0x140);
static_assert(offsetof(Weapon, skipAddingNormalWeapon) == 0x150);

#pragma pack(pop)

//custom struct for convenience for my song list in imgui
struct SongData
{
    BgmType index{};//the index where the song lives.. (can't just iterate a vector and use that index cause it's not contiguous)
    std::string title{};//just the song name. ill be modifying them a bit to gid rid of endings like " - Vampire Survivors" and " - VS version"
    std::string credits{};//both author and origins on same line (if both strings exists)
};

enum class SfxType : int
{
    None = 0, Treasure1 = 1, Treasure2 = 2, Treasure3 = 3, ThingFound = 4, BGM_GameOver = 5, BGM_Intro = 6, ClickIn = 7, ClickOut = 8, Holywater = 9, Lightning = 10, Shot = 11,
    MagicMissile = 12, Whip = 13, LevelUp = 14, Hit = 15, Coin = 16, Gem = 17, Roast = 18, Vacuum = 19, Rosary = 20, Orologion = 21, PentagramSFX = 22, LossSFX = 23,
    Explosion = 24, Explosion2 = 25, Alert = 26, LittleHeart = 27, Fireloop = 28, Whistle = 29, Pizza = 30, Brakes = 31, Song = 32, Piano = 33, Lid = 34, Wind = 35,
    MoonStarter = 36, MoonBeat = 37, MoonFinisher = 38, Banish = 39, Guns1 = 40, Guns2 = 41, Guns3 = 42, Carrello = 43, ExploGH = 44, ExploGH2 = 45, PAN = 46, CAT1 = 47,
    CAT2 = 48, CAT3 = 49, CAT5 = 50, CATE = 51, FireExplosion = 52, CATI = 53, STEP1 = 54, STEP2 = 55, STEP3 = 56, STEP4 = 57, Ringing = 58, Corridor = 59, Shroud = 60,
    Bell = 61, Haha = 62, Clap = 63, CFF4 = 64, CFF2 = 65, Rose = 66, Window = 67, Deathscream = 68, Groove = 69, Lightning2 = 70, CFF3 = 71, CFFX = 72, AutoLV = 73,
    AutoLB = 74, Flare = 75, Noise = 76, Secret = 77, Victory1 = 78, Victory2 = 79, SoleSAnti = 80, SoleSFirst = 81, SoleSSecond = 82, Treasure1B = 83, Treasure2B = 84,
    Treasure3B = 85, ThingFoundB = 86, BGM_GameOverB = 87, BGM_IntroB = 88, LevelUpB = 89, Crystal12 = 90, Key1 = 91, Key2 = 92, Key3 = 93, Key4 = 94, Key5 = 95,
    KeyWrong = 96, Lucky = 97, LittleHit = 98, Magic2 = 99, ExploSoft = 100, ExploNight = 101, Clones = 102, Bubbles = 103, Seasons1 = 104, Seasons2 = 105, Seasons3 = 106,
    Seasons4 = 107, Seasons5 = 108, Seasons6 = 109, Morph = 110, Bangu = 111, Blade1 = 112, Crystal6 = 113, Crystal8 = 114, SpellString = 115, SpellStrom = 116,
    SpellStrike = 117, Bumper = 118, Magic3 = 119, Attack2 = 120, Attack1 = 121, Giant = 122, Scream = 123, Bumper2 = 124, Pot = 125, WorldEater = 126, Party = 127,
    Ophion1 = 128, Ophion2 = 129, Ophion3 = 130, Cheers = 131, SnowmanHit = 132, SnowmanBreak = 133, Glass01 = 134, Glass02 = 135, Glass03 = 136, Glass04 = 137,
    Glass05 = 138, Glass06 = 139, Glass07 = 140, Glass08 = 141, Glass09 = 142, Glass10 = 143, Glass11 = 144, Glass12 = 145, Glass13 = 146, Glass14 = 147, Glass15 = 148,
    Glass16 = 149, Glass17 = 150, Glass18 = 151, Glass19 = 152, Glass20 = 153, Glass21 = 154, Glass22 = 155, Glass23 = 156, Glass24 = 157, Glass25 = 158,
    OrologionEcho = 159, Naplow = 160, StarryStart = 161, StarryAttack = 162, DLC3_Lick1 = 163, DLC3_Lick2 = 164, DLC3_CardOut = 165, DLC3_CardMove1 = 166,
    DLC3_CardMove2 = 167, DLC3_CardMove3 = 168, DLC3_CardAccept = 169, DLC3_CardDeny = 170, DLC3_FixWireOpen = 171, DLC3_FixWireClose = 172, DLC3_FixWire1 = 173,
    DLC3_FixWire2 = 174, DLC3_FixWire3 = 175, DLC3_VentOpen = 176, DLC3_GarbageStart = 177, DLC3_GarbageEnd = 178, DLC3_GarbageGrab = 179, DLC3_DoorOpen = 180,
    DLC3_DoorClose = 181, DLC3_EjectText = 182, DLC3_ImpostorDiscovered = 183, DLC3_ImpostorKill = 184, DLC3_MedicalScan = 185, DLC3_ReportWeapon = 186,
    DLC3_EmergencyMeeting = 187, DLC3_VoteScreenPlayerDead = 188, DLC3_BodyReported = 189, DLC3_PanelWeaponFire = 190, DLC3_PanelWeaponHit1 = 191,
    DLC3_PanelWeaponHit2 = 192, DLC3_PanelWeaponHit3 = 193, DLC3_TaskComplete = 194, DLC3_SampleDrop1 = 195, DLC3_SampleDrop2 = 196, DLC3_SampleDrop3 = 197,
    DLC3_SampleDrop4 = 198, DLC3_SamplePickup1 = 199, DLC3_SamplePickup2 = 200, DLC3_SamplePickup3 = 201, DLC3_SamplePickup4 = 202, DLC3_AlarmSabotage = 203,
    WinnerSFX = 204, Jump14 = 205, DLC3_TongueTrueFull = 206, DLC3_TongueTrueHitt = 207, Synth3 = 208, WingsA = 209, WingsB = 210, DLC4_BigFuzzBomb = 211,
    DLC4_BigFuzzClaws = 212, DLC4_BigFuzzHeadChop = 213, DLC4_CrushShot = 214, DLC4_EnemyHit = 215, DLC4_Explosion1 = 216, DLC4_ExplosionLong = 217,
    DLC4_FlameShot = 218, DLC4_FullAutoShot = 219, DLC4_Helicopter = 220, DLC4_LaserShot = 221, DLC4_LaserShotSustain = 222, DLC4_MenuConfirm = 223,
    DLC4_MenuSelect = 224, DLC4_PlayerDeath = 225, DLC4_PlayerDeath2 = 226, DLC4_Powerup = 227, DLC4_SpreadShot = 228, DLC4_HomingShot = 229, DLC4_BigFuzzDoors = 230,
    DLC4_BossExplosions = 231, sfx_paradoxMist = 248, sfx_forbiddenSpell = 249, sfx_flikA = 250, sfx_javelin = 251, sfx_javelin2 = 252, Darkasso_Open = 253,
    Darkasso_Jingle = 254, sfx_geiger1 = 255, sfx_geiger2 = 256, sfx_powerUp12 = 257, sfx_evilGong = 258, sfx_mlightning1 = 259, sfx_mwind1 = 260, sfx_death_4 = 261,
    sfx_geiger3 = 262, sfx_geiger4 = 263, sfx_crystal_quick = 264, TP_sfx_Bomb = 265, TP_sfx_Candle = 266, TP_sfx_DarkInferno = 267, TP_sfx_Fireball = 268,
    TP_sfx_Flail = 269, TP_sfx_Flame = 270, TP_sfx_HeartMaxUp = 271, TP_sfx_Hit = 272, TP_sfx_ImpactHeavy = 273, TP_sfx_LifeMaxUp = 274, TP_sfx_LittleHeart = 275,
    TP_sfx_MagicCharge = 276, TP_sfx_MagicChargeHeavy = 277, TP_sfx_MagicRegen = 278, TP_sfx_MagicShot = 279, TP_sfx_Pickup = 280, TP_sfx_PickupRelic = 281,
    TP_sfx_Recovery = 282, TP_sfx_Rod = 283, TP_sfx_Shuriken = 284, TP_sfx_SkeletonDeath = 285, TP_sfx_Slide = 286, TP_sfx_Spinning = 287, TP_sfx_Swing = 288,
    TP_sfx_SwingFire = 289, TP_sfx_SwordBrothers1 = 290, TP_sfx_SwordBrothers2 = 291, TP_sfx_SwordFire = 292, TP_sfx_SwordMagic = 293, TP_sfx_SwordMultiple = 294,
    TP_sfx_SwordRune = 295, TP_sfx_SwordSimple = 296, TP_sfx_SwordSwing = 297, TP_sfx_SwordThrow = 298, TP_sfx_Teleport = 299, TP_sfx_Whip = 300, TP_sfx_WhipFire = 301,
    TP_sfx_Acerbatus = 302, TP_sfx_Arcus = 303, TP_sfx_Confodere = 304, TP_sfx_Culter = 305, TP_sfx_DominusAnger = 306, TP_sfx_DominusHatred = 307, TP_sfx_Fio = 308,
    TP_sfx_Globus = 309, TP_sfx_Grando = 310, TP_sfx_Hasta = 311, TP_sfx_Kick = 312, TP_sfx_Luminatio = 313, TP_sfx_Macir = 314, TP_sfx_Pneuma = 315, TP_sfx_Torpor = 316,
    TP_sfx_Umbra = 317, TP_sfx_UnionDominus = 318, TP_sfx_UnionFulgur = 319, TP_sfx_UnionLuminatio = 320, TP_sfx_UnionNull = 321, TP_sfx_UnionUmbra = 322,
    TP_sfx_VolFulgur = 323, TP_sfx_VolGrando = 324, TP_sfx_VolLuminatio = 325, TP_sfx_VolUmbra = 326, TP_sfx_AlucardShield1 = 327, TP_sfx_AlucardShield2 = 328,
    TP_sfx_BatAttack = 329, TP_sfx_Boomerang = 330, TP_sfx_BreakVase = 331, TP_sfx_BwakaKnife = 332, TP_sfx_CaveTroll = 333, TP_sfx_Chakram = 334, TP_sfx_Diamond = 335,
    TP_sfx_Dodge = 336, TP_sfx_Door = 337, TP_sfx_Dynamite = 338, TP_sfx_EnemyDeath = 339, TP_sfx_FireBoomerang = 340, TP_sfx_FireDemon = 341,
    TP_sfx_FireDemonDeath1 = 342, TP_sfx_FireDemonDeath2 = 343, TP_sfx_GrandCross = 344, TP_sfx_HeartRefresh1 = 345, TP_sfx_HeartRefresh2 = 346,
    TP_sfx_HeartRefresh3 = 347, TP_sfx_HeavenSword = 348, TP_sfx_HeavenSwordSpecial1 = 349, TP_sfx_HeavenSwordSpecial2 = 350, TP_sfx_HeavenSwordSpecial3 = 351,
    TP_sfx_Hellfire1 = 352, TP_sfx_Hellfire2 = 353, TP_sfx_HighMagic = 354, TP_sfx_HitArmor = 355, TP_sfx_HitEnemy = 356, TP_sfx_HolyBook = 357, TP_sfx_HolyRod = 358,
    TP_sfx_IceBrand = 359, TP_sfx_IronBall = 360, TP_sfx_Javelin = 361, TP_sfx_KarmaCoin1 = 362, TP_sfx_KarmaCoin2 = 363, TP_sfx_KarmaCoin3 = 364,
    TP_sfx_KarmaCoin4 = 365, TP_sfx_LibraryCard = 366, TP_sfx_Mace = 367, TP_sfx_MagicMissile1 = 368, TP_sfx_MagicMissile2 = 369, TP_sfx_MenuMove = 370,
    TP_sfx_MenuSelect = 371, TP_sfx_Mist = 372, TP_sfx_MonsterVial1 = 373, TP_sfx_MonsterVial2 = 374, TP_sfx_MonsterVial3 = 375, TP_sfx_MoonRod = 376,
    TP_sfx_NeutronBomb = 377, TP_sfx_Nightmare = 378, TP_sfx_Nitesco1 = 379, TP_sfx_Nitesco2 = 380, TP_sfx_Nitesco3 = 381, TP_sfx_Pentagram = 382,
    TP_sfx_PickupGold = 383, TP_sfx_PocketWatch1 = 384, TP_sfx_PocketWatch2 = 385, TP_sfx_PocketWatch3 = 386, TP_sfx_Potion1 = 387, TP_sfx_Potion2 = 388,
    TP_sfx_Potion3 = 389, TP_sfx_PowerOfSire = 390, TP_sfx_Punch = 391, TP_sfx_SaveData1 = 392, TP_sfx_SaveData2 = 393, TP_sfx_SaveData3 = 394, TP_sfx_SaveData4 = 395,
    TP_sfx_SaveData5 = 396, TP_sfx_ShieldDark1 = 397, TP_sfx_ShieldDark2 = 398, TP_sfx_ShieldDark3 = 399, TP_sfx_ShieldFire1 = 400, TP_sfx_ShieldFire2 = 401,
    TP_sfx_ShieldFire3 = 402, TP_sfx_ShieldFire4 = 403, TP_sfx_ShieldMedusa1 = 404, TP_sfx_ShieldMedusa2 = 405, TP_sfx_ShieldMedusa3 = 406, TP_sfx_ShieldRod = 407,
    TP_sfx_StarFlail = 408, TP_sfx_SummonSpirit = 409, TP_sfx_SwordAlucard = 410, TP_sfx_TNT = 411, TP_sfx_Ukoback = 412, TP_sfx_BlackDisk_FX = 413,
    TP_sfx_ThroneRoom = 414, TP_sfx_Coffin1 = 415, TP_sfx_Death = 416, TP_sfx_StageClear = 417, TP_sfx_Coffin2 = 418, TP_sfx_Shuriken2 = 419, TP_sfx_BwakaKnife2 = 420,
    TP_sfx_GlobusBounce = 421, TP_sfx_MemoryWhip1 = 422, TP_sfx_MemoryWhip2 = 423, TP_sfx_MemoryWhip3 = 424, TP_sfx_Aurablast = 425, TP_sfx_Discus1 = 426,
    TP_sfx_Discus2 = 427, TP_sfx_Grenade1 = 428, TP_sfx_Grenade2 = 429, TP_sfx_Lapiste = 430, TP_sfx_UnionLapiste = 431, TP_sfx_Universitas = 432, TP_sfx_Custos1 = 433,
    TP_sfx_AcidicBubbles1 = 434, TP_sfx_AcidicBubbles2 = 435, TP_sfx_RockRiot = 436, TP_sfx_Hex = 437, TP_sfx_Nightmare2 = 438, TP_sfx_RagingFire = 439,
    TP_sfx_Salamander = 440, TP_sfx_IceFang = 441, TP_sfx_GaleForce = 442, TP_sfx_Fulgur = 443, TP_sfx_VolFulgur2 = 444, TP_sfx_Heal = 445, TP_sfx_DivineStorm = 446,
    TP_sfx_Cocytus = 447, TP_sfx_NitescoStart = 448, TP_sfx_NitescoLoop = 449, DLC6_Glimmer = 450, DLC6_ShowtimeTsunanoriVO = 451, sfx_bell2 = 452, Sfx_eme_Punch1 = 453,
    Sfx_eme_Punch2 = 454, Sfx_eme_punch3 = 455, Eme_sfx_chaosDisaster = 456, Eme_sfx_hypergravity = 457, Eme_sfx_thunder1 = 458, Eme_sfx_thunder2 = 459,
    Eme_sfx_thunder3 = 460, Eme_sfx_vermillionmove = 461, Eme_sfx_vermillionsands = 462, Eme_sfx_wave1 = 463, Eme_sfx_wave2 = 464, Sfx_eme_backstab = 465,
    Sfx_eme_kaleidoscope = 466, Sfx_eme_moonfall = 467, Sfx_eme_boundshot = 468, Sfx_eme_boundshotend = 469, Sfx_eme_delta = 470, Sfx_eme_deltaStart = 471,
    Sfx_eme_hellfury = 472, Sfx_eme_hellmid = 473, Sfx_eme_hellstart = 474, Sfx_eme_cosmicrave = 475, Sfx_eme_enemydeath = 476, Sfx_eme_gale = 477, Sfx_eme_sfSlash = 478,
    Sfx_eme_sprink = 479, Sfx_eme_standardattack = 480, Sfx_eme_swallow = 481, Sfx_eme_aiming = 482, Sfx_eme_aiming2 = 483, Sfx_eme_enemypunch = 484,
    Sfx_eme_explofour = 485, Sfx_eme_gunshot = 486, Sfx_eme_aquasphere = 487, Sfx_eme_chaosdisaster = 488, Sfx_eme_sunlight = 489, Sfx_eme_machinegun = 490,
    Sfx_eme_shockwave = 491, Sfx_eme_gravedigger = 492, Sfx_eme_katana = 493, Sfx_eme_scatteredpetals1 = 494, Sfx_eme_scatteredpetals2 = 495,
    Sfx_eme_scatteredpetals3 = 496, Sfx_eme_scatteredpetals4 = 497, Sfx_eme_divinelancer = 498, Sfx_eme_spear = 499, Sfx_eme_stardust = 500, Sfx_eme_stardust_long = 501,
    Sfx_eme_absetzen = 502, Sfx_eme_bullcrush = 503, Sfx_eme_greatsword_land = 504, Sfx_eme_greatsword_throw = 505, Sfx_eme_vandalize = 506,
    Sfx_eme_bombardingfire1 = 507, Sfx_eme_bombardingfire2 = 508, Sfx_eme_bombardingfire3 = 509, Sfx_eme_bombardingfire4 = 510, Sfx_eme_sunlightshower1 = 511,
    Sfx_eme_sunlightshower2 = 512, Sfx_eme_sunlightshower3 = 513, Sfx_eme_artificialhailstorm = 514, Sfx_eme_ballisticmissile = 515, Sfx_eme_mechexplosion = 516,
    Sfx_eme_mechmissile = 517, Sfx_dice_roll = 518, EX_Ammo_BulletSound = 519, Sfx_magistone = 520, EX_Ammo2_Gunastrophe_SFX = 521, EX_AMMO_SINGLESHOT = 522,
    Sfx_wheelOfFortuneTick = 523, Sfx_wheelOfFortuneFanfare = 524, Sfx_steal1 = 525, Sfx_steal2 = 526, TP_sfx_Frog = 527, Magic4 = 528, LEM_sfx_chips1 = 529,
    LEM_sfx_coin1 = 530, LEM_sfx_coin2 = 531, LEM_sfx_coin3 = 532, LEM_sfx_coin4 = 533, LEM_sfx_coin5 = 534, LEM_sfx_coin6 = 535, LEM_sfx_coin7 = 536,
    LEM_sfx_multhit1 = 537, LEM_sfx_negative = 538, LEM_sfx_explosion_release = 539, LEM_sfx_explosion_buildup1 = 540, LEM_sfx_glass1 = 541, LEM_sfx_banana_bounce = 542,
    LEM_sfx_banana_explosion = 543, LEM_sfx_banana_throw1 = 544, LEM_sfx_banana_throw2 = 545, LEM_sfx_fibonacci_flush = 546, LEM_sfx_fibonacci_stream = 547,
    LEM_sfx_fibonacci_throw = 548, TP_sfx_SoulAbsorb1 = 549, TP_sfx_SoulAbsorb2 = 550, Sfx_exp45 = 551, Sfx_exp5 = 552, Sfx_magic_charge4 = 553
};
enum class ItemType : int
{
    NONE = 0, WHIP = 1, COIN = 2, COINBAG1 = 3, COINBAG2 = 4, COINBAGMAX = 5, GEM = 6, CLOVER = 7, TREASURE = 8, ROSARY = 9, VACUUM = 10, OROLOGION = 11, ROAST = 12, WEAPON = 13, STATS_TREASURE_1 = 14,
    STATS_TREASURE_2 = 15, STATS_TREASURE_3 = 16, NFT = 17, LITTLEHEART = 18, RELIC = 19, RELIC_MAP = 20, COFFIN = 21, RELIC_BANGER = 22, RELIC_TEAR = 23, RELIC_RANDOMAZZO = 24, MOONGATE = 25, RELIC_GLASSMASK = 26,
    RELIC_GOLDENEGG = 27, RELIC_YELLOW = 28, MERCHANT = 29, ROSARYX = 30, DUMMY_LIGHTSOURCE = 31, DUMMY_BANISH = 32, DUMMY_SKIP = 33, DUMMY_REROLL = 34, RELIC_NOSEGLASSES = 35, RELIC_GRIMOIRE = 36, RELIC_SECRETS = 37,
    RELIC_GOUDA = 38, RELIC_GGOSPEL = 39, GILDED = 40, ALWAYS_COINBAG2 = 41, ALWAYS_ROAST = 42, HEALER = 43, PURIFY = 44, COSMO_PAVONE = 45, COFFINX = 46, COFFIN_EMPTY = 47, DIRECTER = 48, DUMMY_ARC = 49,
    RELIC_MIRROR = 50, RELIC_TRUMPET = 51, DUMMY_REVIVAL = 52, PURIFY2 = 53, EGGMAN = 54, DUMMY_GOLDENEGG_MAX = 55, RELIC_MALACHITE = 56, RELIC_CHARM = 57, RELIC_MAP_FS = 58, RELIC_MAP_MS = 59, GOLDFINGER = 60,
    TELEPORTER = 61, RELIC_ROSALIA = 62, RELIC_TRISECTION = 63, RELIC_MAP_AS = 64, FRIENDSHIP = 65, RELIC_LAZULIA = 66, RELIC_ALTEMANNA = 67, RELIC_CHAOSEGG = 68, RELIC_ANTIDOTE = 69, ADVENTURE_MERCHANT = 70,
    RELIC_ATLAS = 71, RELIC_SPEEDUP = 72, RELIC_BRAVESTORY = 73, RELIC_MAP_CHAL = 74, RELIC_DARKASSO = 75, CART_ACCEL = 76, CART_GOAL = 77, STATS_TREASURE_4 = 78, STATS_TREASURE_5 = 79, CUSTOM_MERCHANT = 80,
    SORBETTO = 81, STATIC_GOLDPILE = 82, RELIC_PARTY = 83, EX_ZI_APPUNTA_PICKUP = 84, PICKUP_REROLL_DICE = 85, RELIC_RECYCLE = 86, STATS_TREASURE_WEAPONS = 87, STATS_TREASURE_EVOS = 88, RELIC_SURVAROCCHI = 89,
    SV_DRAFT1 = 90, SV_DRAFT2 = 91, SV_DRAFT3 = 92, RELIC_EME_DISK = 100, EME_CATY = 101, EME_CATB = 102, EME_CATU = 103, EME_CATW = 104, EME_CATR = 105, EME_CAT_RAINBOW = 106, EME_TELEPORTER = 107,
    FB_RAPIDFIRE = 200, FB_BARRIER = 201, FB_GRENADE = 202, RELIC_MAP_FB = 203, BONUS_FROZENSOUL = 204, TP_HEART_REFRESH = 205, TP_WALL_CHICKEN = 206, TP_NEUTRON_BOMB = 207, TP_KARMA_COIN = 208,
    TP_MIRROR_OF_TRUTH = 209, TP_SOULSTEAL_LITTLEHEART = 210, TP_RELIC_PILEOFSECRETS = 211, TP_RELIC_MASK_SUN = 212, TP_RELIC_MASK_MOON = 213, TP_RELIC_MASK_CITY = 214, TP_RELIC_MASK_VOLCANO = 215,
    TP_RELIC_MASK_SEAWINDS = 216, TP_RELIC_MASK_STONE = 217, TP_RELIC_MASK_BLACK = 218, TP_RELIC_BLACK_DISK = 219, TP_RELIC_TELEPORT1 = 220, TP_RELIC_TELEPORT2 = 221, TP_RELIC_TELEPORT3 = 222,
    TP_RELIC_TELEPORT4 = 223, TP_RELIC_TELEPORT5 = 224, TP_RELIC_TELEPORT6 = 225, TP_RELIC_LIBRARIAN = 226, TP_RELIC_CASTLEMAP = 227, TP_MERCHANT_LIBRARIAN = 228, TP_CYCLEGATE = 229, TP_RELIC_STONES = 230,
    RELIC_MASK_FATE = 231, RELIC_MASK_WRATH = 232, RELIC_MASK_SOVEREIGN = 233, RELIC_MASK_IMPLACABILITY = 234, RELIC_MASK_MIRTH = 235, BONUS_CURSEDSOUL = 236,
    CARD_B001_ANTONIO = 300, CARD_B002_IMELDA = 301, CARD_B003_PASQUALINA = 302, CARD_B004_GENNARO = 303, RELIC_LEM_DISK = 400,
};
enum class StageType : int
{
    FOREST = 0, SINKING = 1, ENTRANCE = 2, LIBRARY = 3, TEST = 4, TESTONE = 5, CASTLE = 6, GREENACRES = 7, WAREHOUSE = 8, MOLISE = 9, TOWER = 10, BONEZONE = 11, STAGEX = 12, CHAPEL = 13,
    RASH = 14, MACHINE = 15, MACHINE2 = 16, TOWERBRIDGE = 17, BLACK = 18, WHITE = 19, MOONSPELL = 20, BATCOUNTRY = 21, ASTRALSTAIR = 22, FOSCARI = 23, FOSCARI2 = 24, WHITEOUT = 25, POLUS = 26,
    SPAZIE = 27, FB_GALUGA = 28, FB_HIGHWAY = 29, DEVILROOM = 30, LABORRATORY = 31, COOP = 32, CARLOCART = 33, LEGION_TEST = 34, BEELZEBUB_TEST = 35, DOPPLEGANGER_TEST = 36, TP_CASTLE_TEST = 37,
    EMERALD = 38, EX_WESTWOODS = 39, EX_MAZERELLA = 40, LEM_CHAMBER = 41, ADV_BAZAAR = 1000, ADV_M001CASTLEGROUNDS = 1001, ADV_M002SHRINESVALLEY = 1002, ADV_M003FORBIDDENPEAK = 1003, ADV_M004HIDDENCAVE = 1004,
    ADV_M005FROZENLAKE = 1005, ADV_M006TANUKIFOREST = 1006, ADV_M007MOONSPELL = 1007, ADV_0001TEST = 1010, ADV_POE_1_Acres = 1011, ADV_POE_2_Forest = 1012, ADV_POE_3_Woods = 1013, ADV_POE_4_Orchard = 1014,
    ADV_POE_5_Garden = 1015, ADV_POE_6_Molise = 1016, ADV_IME_1_Chapel = 1021, ADV_IME_2_Library = 1022, ADV_IME_3_Forest = 1023, ADV_IME_4_Tower = 1024, ADV_IME_5_Stair = 1025, ADV_IME_6_Magna = 1026,
    ADV_CHAL_001_Meeting = 1031, ADV_CHAL_002_Security = 1032, ADV_CHAL_003_Ejected = 1033, ADV_CHAL_004_Ghosted = 1034, ADV_CHAL_005_Science = 1035, ADV_CHAL_006_Trouble = 1036, ADV_FB_001_Attack = 1041,
    ADV_FB_002_Bullet = 1042, ADV_FB_003_NeoCity = 1043, ADV_FB_004_OperationGun = 1044, ADV_FB_005_RunAndGun = 1045, ADV_FB_006_Alien = 1046, TP_CHAPEL = 1047, TP_CASTLE = 1048, ADV_EME_001 = 1050,
    ADV_EME_002 = 1051, ADV_SHEMOON_001 = 1052, ADV_SHEMOON_002 = 1053, ADV_SHEMOON_003 = 1054, ADV_SHEMOON_004 = 1055, ADV_SHEMOON_005 = 1056, ADV_SHEMOON_006 = 1057, ADV_FOSCARI_001 = 1058, ADV_FOSCARI_002 = 1059,
    ADV_FOSCARI_003 = 1060, ADV_FOSCARI_004 = 1061, ADV_FOSCARI_005 = 1062, ADV_FOSCARI_006 = 1063, ADV_FOSCARI_007 = 1064, POE_ADV_BAZAAR = 1065, IMELDA_ADV_BAZAAR = 1066, SHEMOON_ADV_BAZAAR = 1067,
    ADV_M001_ADV_BAZAAR = 1068, CHALCEDONY_ADV_BAZAAR = 1069, FIRSTBLOOD_ADV_BAZAAR = 1070, FOSCARI_ADV_BAZAAR = 1071, ADV_OTC_001_001_Woods = 1080, ADV_OTC_001_002_Entrance = 1081, ADV_OTC_001_003_Library = 1082,
    ADV_OTC_001_004_Clock = 1083, ADV_OTC_001_005_Throne = 1084, ADV_OTC_001_006_Sunken = 1085, ADV_OTC_001_007_Ecclesia = 1086, ADV_OTC_001_008_Infinite = 1087, OTC_ADV_BAZAAR = 1088, ADV_OTC_001_009_DeathFight = 1089,
};
enum class CharacterType : int
{
    NONE = 0, ANTONIO = 1, IMELDA = 2, PASQUALINA = 3, GENNARO = 4, CRISTINA = 5, CIRO = 6, PORTA = 7, EXDASH = 8, MORTACCIO = 9, CAVALLO = 10, CAMILLO = 11, RED = 12, LAMA = 13, DOMMARIO = 14, CROCI = 15,
    GERMANA = 16, LORDO = 17, POPPEA = 18, PUGNALA = 19, GIOVANNA = 20, CONCETTA = 21, ASSUNTA = 22, DEATH = 23, DETH = 24, PANINI = 25, GRAZIELLA = 26, CANTERVILLO = 27, TUPU = 28, VERANDA = 29,
    TATANKA = 30, LATODILATO = 31, LATODISOPRO = 32, YOLO = 33, SCEMINO = 34, DUPRE = 35, LATODISOTTO = 36, LATOEVEST = 37, MAREMMA = 38, FEBBRA = 39, MARIA = 40, MARIANNA = 41, MARIASOFIA = 42,
    BESUGO = 43, ANDRIA = 44, NOSTRO = 45, FINO = 46, PINO = 47, SIGMA = 48, AVATAR = 49, IOLO = 50, PEPPE = 51, PEPPINO = 52, SMITH = 53, NEO = 54, PIRIPIRI = 55, PINEYE = 56, PENTA = 57, ODDEEO = 58,
    AMBROGIO = 59, BOROS = 60, PANTALONE = 61, PAVONE = 62, DRAGOGION = 63, ARENGIJUS = 64, SCOREJ = 65, MIANG = 66, MENYA = 67, SYUUTO = 68, ONNA = 69, MCCOY = 70, MEGAMENYA = 71, MEGASYUUTO = 72,
    TONY = 73, NARA = 74, ELEANOR = 75, LUMINAIRE = 76, GENEVIEVE = 77, MEGAGENEVIEVE = 78, VICTOR = 79, KEIRA = 80, GHOUL = 81, GAEA = 82, MARUTO = 83, CTRPCAKE = 84, SHEMOONITA = 85, SPACEDUDE = 86, SPACEDUDETTE = 87,
    SPACEALIEN = 88, SANTA = 89, AMBERBORNE = 90, KITTYSAN = 91, KIKICHAN = 92, GYORUNTIN = 93, RYOMARE = 94, BELLA = 95, SKTOOA = 96, SKALAFACHA = 97, SKLEEMEJO = 98, SKDEPEEPPO = 99, BATSBATSBATS = 100, ROSE = 101,
    TORINO = 102, MAURIZIO = 103, MEGALO_MORTACCIO = 104, MEGALO_CAVALLO = 105, MEGALO_RAMBA = 106, MEGALO_OSOLE = 107, MEGALO_AMBROJOE = 108, C1_CREWMATE = 109, C1_IMPOSTOR = 110, C1_GHOST = 111, C1_GUARDIAN = 112,
    C1_ENGINEER = 113, C1_SCIENTIST = 114, C1_SHAPESHIFTER = 115, C1_HORSE = 116, C1_PICKLE = 117, C1_RABBIT = 118, C1_MEGAIMPOSTOR = 119, FB_BILLRIZER = 120, FB_LANCE = 121, FB_BRADFANG = 122, FB_BROWNY = 123,
    FB_LUCIA = 124, FB_PROBO = 125, FB_SHEENA = 126, FB_STANLEY = 127, FB_ARIANA = 128, FB_COLONEL = 129, FB_SIMONDO = 130, FB_NEWT = 131, FB_DUMMY_01 = 132, FB_DUMMY_02 = 133, FB_DUMMY_03 = 134, FB_DUMMY_04 = 135,
    FB_DUMMY_05 = 136, FB_DUMMY_06 = 137, FB_DUMMY_07 = 138, FB_DUMMY_08 = 139, FB_DUMMY_09 = 140, FB_DUMMY_10 = 141, FB_DUMMY_11 = 142, EME_RAPIERDUAL = 143, EME_PUPGUN_FOLLOWER = 144, EME_PUPKNIFE_FOLLOWER = 145,
    EME_PUPKATANA_FOLLOWER = 146, EME_PUPPUNCH_FOLLOWER = 147, EME_MAGICALL = 148, EME_PUNCHKICK = 149, EME_CANNONGUN = 150, EME_MECHKATANA = 151, EME_SWORDBITE = 152, EME_MRS = 153, EME_EXGREATSWORD = 154, EME_EXKNIFE = 155,
    EME_EXAXE = 156, EME_EXSPEAR = 157, EME_PUPALL = 158, EME_CATS_FOLLOWER = 159, FOLLOWER_BATSBATSBATS = 160, FOLLOWER_MOONRABBIT = 161, FOLLOWER_MOONDUCK = 162, EME_CATS = 163, EME_DEMON = 164, EME_IMAKOO = 165,
    EME_KINA = 166, EX_CHULAREH = 167, EX_ZIAPPUNTA = 168, EX_GIOCARE = 169, TP_ALBUS = 201, TP_ALUCARD = 202, TP_AXEARMOR = 203, TP_CARMILLA = 204, TP_CARRIE = 205, TP_CHARLOTTE = 206, TP_CORNELL = 207,
    TP_DEATH = 208, TP_DRACULA = 209, TP_ELIZABETH = 210, TP_ERIC = 211, TP_GALAMOTH = 212, TP_GRANT = 213, TP_HECTOR = 214, TP_HENRY = 215, TP_ISAAC = 216, TP_JONATHAN = 217, TP_JOHN = 218, TP_JULIUS = 219,
    TP_JULIA = 220, TP_JUSTE = 221, TP_LEON = 222, TP_LORETTA = 223, TP_MARIAA = 224, TP_MARIAB = 225, TP_NATHAN = 226, TP_ORLOX = 227, TP_REINHARDT = 228, TP_RICHTER = 229, TP_SHAFT = 230, TP_SHANOA = 231,
    TP_SIMON = 232, TP_SOMA = 233, TP_SONIA = 234, TP_STELLA = 235, TP_STGERMAIN = 236, TP_SUCCUBUS = 237, TP_SYPHA = 238, TP_TREVOR = 239, TP_YOKO = 240, TP_CHRISTOPHER = 241, TP_SARA = 242, TP_DARIO = 243, TP_DMITRI = 244,
    TP_CELIA = 245, TP_RINALDO = 246, TP_MINA = 247, TP_QUINCY = 248, TP_MAXIM = 249, TP_LISA = 250, TP_VINCENT = 251, TP_BRAUNER = 252, TP_BARLOWE = 253, TP_WIND = 254, TP_ASTARTE = 255, TP_LIBRARIAN = 256,
    TP_HAMMER = 257, TP_GRAHAM = 258, TP_SOLEIL = 259, TP_JOACHIM = 260, TP_CAVETROLL = 261, TP_FERRYMAN = 262, TP_MALPHAS = 263, TP_WALTER = 264, TP_FROZENSHADE = 265, TP_OLROX = 266, TP_SNIPER = 267, TP_FLEAMAN = 268,
    TP_BLACKMORE = 269, TP_JONATHAN_AND_CHARLOTTE = 270, TP_CHARLOTTE_AND_JONATHAN = 271, TP_STELLA_AND_LORETTA = 272, TP_LORETTA_AND_STELLA = 273, TP_CORNELL_BCM = 274, TP_ELIZABETH_MEGA = 275, TP_DEATH_MEGA = 276,
    TP_KEREMET = 277, TP_DRACULA_MEGA = 278, TP_OLROX_MEGA = 279, TP_FAMILIARS = 298, TP_INNOCENT_DEVILS = 299, TP_FOLLOWER_UKOBAK = 300, TP_FOLLOWER_BITTERFLY = 301, TP_FOLLOWER_IMP = 302, TP_FOLLOWER_GHOST = 303, TP_FOLLOWER_WIZARD = 304,
    TP_FOLLOWER_FAIRY = 305, TP_FOLLOWER_PUMPKIN = 306, TP_FOLLOWER_CARDINAL = 307, TP_FOLLOWER_DRAGON = 308, TP_FOLLOWER_TIGER = 309, TP_FOLLOWER_TURTLE = 310, FOLLOWER_ENEMY = 311, FS_FOLLOWER_HILLTROW = 312, FS_FOLLOWER_BROWNIE = 313, FS_FOLLOWER_LEGIONNAIRE = 314,
    TP_KIDDRACULA = 315, TP_DESMOND = 316, TP_ZOE = 318, TP_DOLORES = 319, TP_HUGH = 320, TP_MORRIS = 321, TP_ANNETTE = 322, TP_TERA = 323, TP_AEON = 324, TP_PERSEPHONE = 325, TP_GAIBON_AND_SLOGRA = 326, TP_SLOGRA_AND_GAIBON = 327, TP_GAIBON = 328,
    TP_SLOGRA = 329, TP_ACTRISE = 330, TP_DROLTA = 331, TP_JIANGSHI = 332, TP_WATERMAGICIAN = 333, TP_SWORDRULER = 334, TP_GENYA = 335, TP_FISHMAN = 336, TP_FAKE_TRIO = 337, TP_FW_FAKE_TREVOR = 338, TP_FW_FAKE_SYPHA = 339, TP_FW_FAKE_GRANT = 340, TP_ZEPHYR = 341,
    TP_STONESKULL = 342, TP_CHAOS = -1, LEM_FOLLOWER_SABOTEUR = 400, LEM_JIMBO = 401, LEM_CANIO = 402, LEM_CHICOT = 403, LEM_PERKEO = 404,
};
enum class EnemyType : int
{
    BAT1 = 0, BAT2 = 1, BAT3 = 2, BAT4 = 3, BAT5 = 4, BAT6 = 5, BATSWARM = 6, ZOMBIE = 7, SKELETON = 8, SKELETON2 = 9, SKELETON3 = 10, SKELETON4 = 11, WEREWOLF = 12, GHOST = 13, GHOST2 = 14,
    GHOSTSWARM = 15, FLOWER = 16, MUDMAN1 = 17, MUDMAN2 = 18, TRINACRIA = 19, BOSS_WEREWOLF = 20, MUD = 21, BUER = 22, MUMMY = 23, ECTO1 = 24, ECTO2 = 25, WITCH1 = 26, WITCH2 = 27,
    MEDUSA1 = 28, MEDUSA2 = 29, MEDUSA2_AGGRO = 30, DULL0 = 31, DULL1 = 32, DULL2 = 33, SKULL2_SCALING = 34, SKULL2_EASY = 35, SKULL2_SWARM = 36, BOSS_SKULL2 = 37, SHADEBLUE = 38,
    SHADERED = 39, SKULLNOAURA = 40, PILE4 = 41, PILE4_SCALED = 42, XLSKELETON = 43, BOSS_XLSKELETON = 44, SKELEPANTHER = 45, SKELEGLOW = 46, SKELETONE = 47, SKELEWING_ZONE = 48,
    SKELENIN_ZONE = 49, XLMAGIO = 50, XLBAT = 51, XLMUMMY = 52, XLMANTIS = 53, XLFLOWER = 54, XLMEDUSA = 55, BOSS_XLMUMMY = 56, BOSS_XLBAT = 57, BOSS_XLMANTIS = 58, BOSS_XLFLOWER = 59,
    BOSS_XLDEATH = 60, BOSS_XLSTALKER = 61, BOSS_XLDROWNER = 62, BOSS_ECTO = 63, BOSS_MUD = 64, BOSS_BUER = 65, BOSS_XLMEDUSA = 66, BOSS_COUNT1 = 67, BOSS_COUNT2 = 68, BOSS_MEDUSA1 = 69,
    BOSS_WITCH2 = 70, BOSS_XLLEDA = 71, SKULLINO = 72, SKULOROSSO = 73, SKELANGUE = 74, DEVIL1 = 75, DEVIL3 = 76, ARMOR1 = 77, ARMOR2 = 78, SKELEWING_INO = 79, BOSS_HARPY = 80, IMP = 81,
    HARPY = 82, HARPYV = 83, PANTHER = 84, POLTER_DEST = 85, POLTER = 86, BOSS_PANTHER = 87, XLDRAGON1 = 88, XLDRAGON2 = 89, XLDRAGON1_FLAG = 90, XLDRAGON2_FLAG = 91, XLDRAGON3_FLAG = 92,
    BOSS_XLDRAGON1 = 93, BOSS_XLDRAGON2 = 94, BOSS_XLARMOR1 = 95, BOSS_XLARMOR2 = 96, XLARMOR1 = 97, XLARMOR2 = 98, BOSS_XLCRAB = 99, BOSS_XLPINCER = 100, BOSS_GALLO = 101, MILK = 102,
    FISHMAN_1 = 103, LIZARD1_2 = 104, LIZARD2_3 = 105, ARMOR_6 = 106, ARMORSPEAR_6 = 107, MERMA1_3 = 108, MERMA2_4 = 109, BOSS_MERMAN = 110, MIGNO1_5 = 111, MIGNO3_5 = 112,
    MIGNO_3_5SWARM = 113, JELLYFISH = 114, JELLYFISH2 = 115, JELLYFISH2_SWARM = 116, PILE1 = 117, PILE2 = 118, PILE3 = 119, SKELENIN1 = 120, SKELENIN2 = 121, SKELEWING = 122,
    XLARMOR_SWORD = 123, XLTRITON = 124, BULLET_1 = 125, BULLET_2 = 126, BULLET_3 = 127, BULLET_W = 128, BULLET_Z = 129, PATROL_XLARMOR_SWORD = 130, PATROL_XLARMOR_1 = 131,
    PATROL_SKELEWING = 132, PATROL_MIGNO_3_5SWARM = 133, PATROL_ARMOR_6 = 134, PATROL_SKELEWING_BIG = 135, PATROL_WITCH = 136, GOLEM1 = 137, XLCHIMERA = 138, XLCOCKATRICE = 139,
    XLGOLEM1 = 140, XLGOLEM2 = 141, XLGOLEM3 = 142, XLGOLEM4 = 143, BOSS_XLTRITON = 144, BOSS_PILE3 = 145, BOSS_MIGNO2_5 = 146, BOSS_MIGNO2_5_L = 147, BOSS_ARMOR1 = 148,
    BOSS_XLCOCKATRICE = 149, BOSS_XLGOLEM1 = 150, BOSS_XLGOLEM2 = 151, BOSS_XLARMOR = 152, BOSS_XLGOLEM1_29 = 153, BOSS_XLGOLEM2_29 = 154, MOLISANO_BASE = 155, MOLISANO_SECCO = 156,
    MOLISANO_BELLO = 157, MOLISANO_GROSSO = 158, MOLISANO_GIALLO = 159, MOLISANO_ROSSO = 160, MOLISANO_FAGIOLO = 161, MOLISANO_COLONNA = 162, MOLISANO_VECCHIO = 163, MOLISANO_ANFORA = 164,
    MOON_ANFORA = 165, MOON_JELLYFISH = 166, MOON_CRABBINO = 167, MOON_BOSS_CRABBINO = 168, MOON_SNEK = 169, MOON_SNEK_GREEN = 170, MOON_SNEK_RED = 171, MOON_GHOST = 172,
    MOON_SHADEBLUE = 173, MOON_FISHMAN = 174, MOON_XLTRITON = 175, MOON_MEDUSA1 = 176, MOON_MEDUSA2 = 177, MOON_NIGHTSHADE = 178, MOON_GARLIC = 179, MOON_BOSS_NIGHTSHADE = 180,
    MOON_BOSS_GARLIC = 181, MOON_EYE1 = 182, MOON_EYE2 = 183, MOON_EYE3 = 184, MOON_EYE1S = 185, MOON_EYE2S = 186, MOON_EYE3S = 187, MOON_TRINACRIA = 188, MOON_TRINACRIA_X = 189,
    MOON_MASK1 = 190, MOON_MASK2 = 191, MOON_MASK3 = 192, MOON_MASK4 = 193, MOON_MASK5 = 194, MOON_BAT = 195, MOON_BAT_PROJECTILE = 196, MOON_SHADE = 197, BOSS_XLMADDENER = 198,
    MASK_GOLD = 199, MASK_SILVER = 200, MASK_LEFT = 201, MASK_RIGHT = 202, BOSS_NOOB = 203, BOSS_WEREWOLF2 = 204, BOSS_MADDENER_NORMAL = 205, TRAINEE_Y = 206, FANGEL1 = 207, FANGEL2 = 208,
    FANGEL3 = 209, BOSS_FANGEL3 = 210, BOSS_DROWNER_NORMAL = 211, TRAINEE_B = 212, KALI1 = 213, KALI2 = 214, KALI2_FAST = 215, SUCCUBUS = 216, BOSS_SUCCUBUS = 217,
    BOSS_STALKER_NORMAL = 218, TRAINEE_G = 219, ARMOR_FIRE = 220, ARMOR_SWORD = 221, XLARMOR_GOLD = 222, XLARMOR_GREEN = 223, BOSS_XLARMOR_GREEN = 224, BOSS_TRICKSTER_NORMAL = 225,
    TRAINEE_P = 226, DEMON = 227, DEMON_FAST = 228, XLDEMON = 229, XLDEMON2 = 230, XLARCHDEMON = 231, BOSS_XLARCHDEMON = 232, POLTER_GEM = 233, POLTER_GEM_STATIC = 234, STAGEKILLER = 235,
    STAGEKILLER2 = 236, TRAINEE = 237, TRAINEE_R = 238, BOSS_TRINACRIA = 239, ANGEL1 = 240, ANGEL2 = 241, ANGEL3 = 242, BOSS_EYE2 = 243, TRAINEE_ANY = 244, BOSS_XLDEATH2 = 245, test = 246,
    BOSS_ENDER = 247, BULLET_SCYTHE = 248, BOSS_XLTRICKSTER = 249, BOSS_XLCHIMERA = 250, BOSS_ENDER_RASH = 251, BOSS_DROWNER_RASH = 252, BOSS_DRAGOGION = 253, BOSS_XLCRAB_RASH = 254,
    SKETAMARI = 255, BOSS_XLDETH = 256, BOSS_GIANT_MIMIC1 = 257, BOSS_GIANT_MIMIC2 = 258, BOSS_GIANT_MIMIC3 = 259, XXLBAT = 260, UNDEADHEAD = 261, UNDEADEYES = 262, D_CLUSTER_COINS = 263,
    D_CLUSTER_GEMS = 264, D_MASK_SUN = 265, D_MASK_MOON = 266, D_MASK_CITY = 267, D_MASK_VOLCANO = 268, D_MASK_WINDS = 269, D_MASK_GREED = 270, D_MASK_VOID = 271, D_SKULL = 272,
    DIRECTER = 273, BULLET_EGG = 274, BULLET_EYE = 275, D_WEAK_REAPER_A = 276, D_WEAK_REAPER_B = 277, D_WEAK_REAPER_C = 278, D_WEAK_REAPER_D = 279, D_WEAK_REAPER_E = 280, D_EYE = 281,
    D_WEAK_EYE = 282, BOSS_SHARD_INFERNAS = 283, MILK2 = 284, XLCOCKATRICE_GOLD = 285, XLSWORDIAN_V = 286, XLSWORDIAN_AGGRO = 287, BRIDGE_MINION = 288, BRIDGE_TETRA = 289, BRIDGE_ARMOR = 290,
    BRIDGE_TRAINEE = 291, BRIDGE_BOSS = 292, BOSS_XLSWORDIAN = 293, BOSS_XLSWORDIAN_2 = 294, MEDUSA1_FAST = 295, MEDUSA2_FAST = 296, MS_HITOT = 297, MS_KAPPA = 298, MS_MIKOS = 299,
    MS_ONI1 = 300, MS_ONI2 = 301, MS_ONIWIND = 302, MS_ONITHUNDER = 303, MS_SPIRIT1 = 304, MS_SPIRIT2 = 305, MS_TANUKI = 306, MS_TENGU = 307, MS_TSUCHIGUMO = 308, MS_TSUCHINOKO = 309,
    MS_YAMAMBA1 = 310, MS_YAMAMBA2 = 311, MS_KAMAITACHI = 312, MS_RAIJU = 313, MS_OROCHIMARIO = 314, MS_NINETYNINE = 315, MS_GOSHADOKURO = 316, MS_BOSS_SPIRIT = 317, MS_BOSS_SPIRIT2 = 318,
    MS_BOSS_RAIJU = 319, MS_BOSS_KAMAITACHI = 320, MS_BOSS_TENGU = 321, MS_BOSS_TANUKI = 322, MS_BOSS_ONIWIND = 323, MS_BOSS_ONITHUNDER = 324, MS_BOSS_TSUCHIGUMO = 325, MS_FLOWER1 = 326,
    MS_FLOWER2 = 327, MS_SPIRIT1_SWARM = 328, MS_SPIRIT2_SWARM = 329, MS_EVILSPIRIT = 330, MS_OROCHIHEAD = 331, EX_SCALING_BAT1 = 332, EX_SCALING_BAT2 = 333, EX_SCALING_BAT3 = 334,
    EX_AXE_BAT3 = 335, EX_DIAMOND_AXE = 336, EX_DIAMOND = 337, EX_SCALING_BAT3_YELLOW = 338, EX_SCALING_BAT3_GREEN = 339, EX_SCALING_BAT3_PURPLE = 340, EX_SCALING_XLBAT = 341,
    EX_SCALING_XXLBAT = 342, FS_GOBLIN = 343, FS_GEF = 344, FS_SALMON = 345, FS_WULVER = 346, FS_LAMB = 347, FS_HTROW = 348, FS_STROW = 349, FS_CLOWN = 350, FS_BROWN = 351, FS_GREEN = 352,
    FS_CAKE = 353, FS_MARI = 354, FS_AILLEN = 355, FS_BALOR = 356, FS_AGAEA = 357, FS_DUERG = 358, FS_NJUGG = 359, FS_CAULD = 360, FS_GLORY = 361, FS_WORM = 362, FS_HAG = 363,
    FS_HORAILLEN = 364, FS_HORDUERG = 365, FS_HORNJUGG = 366, FS_HORMARI = 367, FS_HORCAULD = 368, FS_HORGLORY = 369, FS_HORWORM = 370, FS_EDNA = 371, FS_FSKULL = 372, FS_UGUL = 373,
    FS_HEMO = 374, FS_MEAT = 375, FS_USKULL = 376, FS_NJUGGB = 377, FS_WORMB = 378, FS_GOBLIN_RED = 379, FS_SALMON2 = 380, FS_SALMON_PINK = 381, FS_GREEN_RED = 382, FS_SELKIE = 383,
    FS_BOSS_SELKIE = 384, FS_BOSS_NJUGGLES = 385, FS_BOSS_CLOWN = 386, FS_BOSS_WULVER = 387, FS_BOSS_LAMB = 388, FS_BOSS_WORM = 389, FS_BOSS_WORMB = 390, FS_BOSS_GREEN_GREEN = 391,
    FS_BOSS_GREEN_28 = 392, FS_BOSS_GREEN_GREEN_28 = 393, FS_BOSS_GREEN_RED_28 = 394, FS_BOSS_AGAEA = 395, FS_BOSS_JENEVIV = 396, FS_WORM2 = 397, FS_SNAK1 = 398, FS_SNAK2 = 399,
    FS_SNAK3 = 400, FS_SNAK4 = 401, FS_FMBALOR = 402, FS_FLAMINGSKULL = 403, FS_ROTGHOUL = 404, FS_MEATY = 405, FS_MEATBALL = 406, BOSS_XLBLINDER = 407, FS_SHOOTER1 = 408, FS_SHOOTER2 = 409,
    HEMO = 410, HEMO2 = 411, REDUSA = 412, FS_FMCETHLENN = 413, FS_FMINDECH = 414, FS_FMCONAND = 415, FS_FMELATHA = 416, FS_SALMON_DUSA = 417, FS_CLOWN_SWARM = 418, FS_MUSH_PATROL = 419,
    FS_BROWN_HP = 420, FS_SALMON_HP = 421, FS_MUSH_HP = 422, FS_NJUGGB_HP = 423, FS_STROW_HP = 424, FS_HTROW_HP = 425, FS_SNAK_SWARM = 426, FS_GGHOST = 427, FS_GGGHOST = 428, RELLYFISH = 429,
    FS_SNAKBOMB = 430, FS_SNAKSHIELD = 431, FS_COCKATRICE_BOSS1 = 432, FS_COCKATRICE_BOSS2 = 433, FS_COCKATRICE_BOSS3 = 434, FS_XLMANTIS_HP = 435, FS_XLFLOWER_HP = 436, FS_CRATE_HP = 437,
    FS_POT_HP = 438, FS_FLOWER = 439, FS_ROTGHOUL_SWARM = 440, RELLYFISH_SWARM = 441, FS_BLINDER_PATROL = 442, FS_BOSS_REDUSA = 443, FS_BOSS_FLAMINGSKULL = 444, FS_BOSS_MEATY = 445,
    FS_BOSS_MEATBALL = 446, FS_BOSS_EDNA = 447, FS_BOSS_HORWORM = 448, FS_BOSS_HORMARI = 449, FS_BOSS_HORCAULD = 450, FS_BOSS_MEATY_29 = 451, FS_BOSS_MEATBALL_29 = 452, FS_ANFORA_HP = 453,
    STARDUST_ELEMENTAL = 454, STARDUST_SKULL = 455, STARDUST_GHOUL = 456, STARDUST_GOLEM = 457, STARDUST_MUMMY = 458, STARDUST_JOE = 459, STARDUST_CHAIR = 460, STARDUST_HEAD = 461,
    STARDUST_EYES = 462, STARDUST_EYES2 = 463, STARDUST_PORTRAIT_A = 464, STARDUST_PORTRAIT_B = 465, STARDUST_PORTRAIT_C = 466, STARDUST_GHOST = 467, COSMIC_EGG = 468, STARDUST_GHOST_R = 469,
    STARDUST_GHOST_B = 470, STARDUST_XLMUMMY = 471, STARDUST_MUD = 472, STARDUST_CLOAK = 473, STARDUST_BLINDER_PATROL = 474, STARDUST_HEMO = 475, STARDUST_RELLYFISH = 476, STARDUST_REDUSA = 477,
    STARDUST_RELLYFISH_SWARM = 478, BOSS_STARDUST_XLMUMMY = 479, EX_SPIRIT1 = 480, EX_SNOWMAN = 481, EX_SNOWMAN_HAUNTED = 482, EX_SNOWMAN_HAUNTED2 = 483, EX_SNOWMAN_HAUNTED3 = 484,
    EX_SNOWELEM = 485, EX_SNOWELEM2 = 486, EX_FROST = 487, EX_ILLUSION = 488, EX_ILLUSION2 = 489, EX_GOLEM_SNOW = 490, EX_GOLEM_ICE = 491, EX_BOSS_KITSUNE = 492, EX_BOSS_KITSUNE_TAIL = 493,
    EX_FOXFIRE = 494, COOP_CHICKEN = 495, COOP_COCK = 496, COOP_CHIK = 497, COOP_EGG = 498, COOP_SPICYCHICKEN = 499, COOP_COCKATRICE = 500, COOP_EGG_H = 501, SPACE_ANT = 502, SPACE_ANT_2 = 503,
    SPACE_ANTBRAIN = 504, SPACE_PICKLE = 505, SPACE_RABBIT = 506, SPACE_ANTBRAIN_BOSS = 507, SPACE_PICKLE_BOSS = 508, SPACE_RABBIT_BOSS = 509, SPACE_BATT_A = 510, SPACE_BATT_B = 511,
    SPACE_BATT_C = 512, SPACE_BATT_D = 513, SPACE_DUCK = 514, CHAL_MOLO = 515, CHAL_BRIA = 516, CHAL_FRIGGI = 517, CHAL_MARTIA = 518, CHAL_OTTERR = 519, CHAL_ROBOTT = 520, CHAL_NDROID = 521,
    CHAL_MONKEY = 522, CHAL_CREATU = 523, CHAL_TRIPOD = 524, CHAL_BINNN = 525, CHAL_BRICK = 526, CHAL_NUGGE = 527, CHAL_GHOST = 528, CHAL_LAVAA = 529, CHAL_MEATT = 530, CHAL_SNOWW = 532,
    CHAL_SHIFT = 533, CHAL_ANIMEXXL = 534, CHAL_ANIMEXXL_TENTACLE_LEFT = 535, CHAL_ANIMEXXL_TENTACLE_RIGHT = 536, CHAL_MOLO1 = 537, CHAL_MOLO2 = 538, BOSS_CHAL_MARTIA = 539,
    BOSS_CHAL_TRIPOD = 540, BOSS_CHAL_NDROID = 541, BOSS_CHAL_CREATU = 542, CHAL_GHOSTSWARM = 543, CHAL_BRIASWARM = 544, CHAL_BATS = 545, CHAL_BRICK_SUS = 546, CHAL_NUGGE_SUS = 547,
    CHAL_BINNN_SUS = 548, SPACE_DUCKSWARM = 549, SPACE_RABBITSWARM = 550, CHAL_ROBOTT2 = 551, CHAL_BATSSWARM = 552, CHAL_GHOST_EXP = 553, CHAL_SUS_COUNTER = 554, ADV_BIG_IMPOSTOR = 555,
    ADV_BIG_SHIFT = 556, ADV_CHAL_NUGGE_SUS_GOLEM = 557, ADV_CHAL_NUGGE_SUS_GOLEM_ARM = 558, ADV_TRIPOD_GUN = 559, ADV_NDROID_GUN = 560, ADV_BIG_TRIPOD = 561, ADV_SPACE_DUCK = 562,
    ADV_SPACE_RABBIT = 563, ADV_BIG_SPACE_DUCK = 564, ADV_MINI_SPACE_RABBIT = 565, ADV_MINI_SPACE_ANT = 566, ADV_SPACE_ANTBRAIN_SWORDIAN = 567, CHAL_ANIMEXXL_TENTACLE_LEFT2 = 568,
    CHAL_ANIMEXXL_TENTACLE_RIGHT2 = 569, CHAL_SNOWW_SUS = 570, BOSS_IMPOSTOR_PATROL = 571, CHAL_IMPOSTOR_SMALL = 572, ADV_IMPOSTOR = 573, CHAL_BRICK_AGGRO = 574, CHAL_NUGGE_AGGRO = 575,
    CHAL_BINNN_AGGRO = 576, SPACE_PICKLE_AGGRO = 577, CHAL_PICKLE_CIRCLE = 578, SPACE_DUCKSWARM_H = 579, SPACE_CUBE = 580, EX_BATS_COUNTER = 581, EX_BATSPACE_ALL4 = 582, EX_BATSPACE_A = 583,
    EX_BATSPACE_B = 584, EX_BATSPACE_C = 585, EX_BATSPACE_D = 586, EX_BATSPACE_SWARM = 587, EX_RABBIT_SWARM = 588, EX_RABBIT_SWARM_H = 589, EX_DUCK_SWARM = 590, EX_DUCK_SWARM_H = 591,
    EX_BROCCOLI_SCALE = 592, EX_ANT = 593, EX_ANT_SCALE = 594, EX_ANTBRAIN = 595, EX_ANTBRAIN_SCALE = 596, EX_PICKLE = 597, EX_PICKLE_SCALE = 598, EX_CUBE_HITS_STATIC = 599,
    BOSS_MEGASYUUTO = 600, MS_OROCHIMARIO_INVUL = 601, MS_ADV_MADDONNAS1 = 602, MS_ADV_MADDONNAS2 = 603, MS_ADV_MADDONNAS3 = 604, MS_ADV_TANUKIS1 = 605, MS_ADV_TANUKIS2 = 606,
    MS_ADV_TANUKIS3 = 607, BOSS_THICKTREE = 608, ADV_MOLISANI = 609, ADV_MOLISANI_MOVING = 610, ADV_MOLISANI_SWARM = 611, MS_OROCHIHEAD_INVUL = 612, ADV_XLFLOWER_SMALL = 613,
    ADV_MOON_GARLIC_SMALL = 614, ADV_MOLISANI_MOVING2 = 615, ADV_MOLISANI_MOVING3 = 616, EX_CUBE_HITS_AXE = 617, EX_CUBE_HITS_AGGRO = 618, EX_CUBE_HITS_MEDUSA = 619, EX_CUBE_HITS_FACING = 620,
    EX_PHALIEN_XL = 621, EX_PHALIEN_L = 622, EX_PHALIEN = 623, EX_CUBE_HITS_STERILE = 624, EX_PHALIEN_XL_BOSS = 625, EX_PHALIEN_L_BOSS = 626, EX_PHALIEN_BOSS = 627, EX_CUBE_HITS_PATH = 628,
    EX_BATSPACE_HP = 629, DEVIL_HP_1 = 630, DEVIL_HP_2 = 631, DEVIL_HP_3 = 632, DEVIL_HP_4 = 633, DEVIL_HP_5 = 634, DEVIL_HP_6 = 635, DEVIL_HP_7 = 636, DEVIL_HP_8 = 637, DEVIL_HP_9 = 638,
    DEVIL_HP_10 = 639, DEVIL_HP_11 = 640, DEVIL_HP_12 = 641, DEVIL_HP_13 = 642, DEVIL_HP_14 = 643, DEVIL_HP_15 = 644, COOP_ABRAXAS = 645, COOP_ABRAXASCROWN = 646, COOP_ABRAXASHALO = 647,
    EX_HELLPUP = 648, EX_ER2000 = 649, EX_RETROBOT = 650, EX_BOUNTYHUNTER = 651, EX_CONSTABLEBOT = 652, EX_TDCCC = 653, EX_IMPERIALPULP = 654, EX_APEX = 655, FB_BUGGER = 656,
    FB_HUMANFACEDDOG = 657, FB_LEDDER = 658, FB_POISONOUSINSECTGEL = 659, FB_GREEDER = 660, FB_BUNDLE = 661, FB_WARLORD = 662, FB_GARTH = 663, FB_ZAKOALIEN = 664, FB_HELLRIDER = 665,
    FB_JUNKYARDCAR = 666, FB_FLIGHTZAKO = 667, FB_KIMKOH = 668, FB_CHICKEN = 669, FB_M78 = 670, FB_METALALIEN = 671, BOSS_FB_WARLORD = 672, BOSS_FB_RETROBOT = 673, BOSS_FB_JUNKYARDCAR = 674,
    BOSS_FB_KIMKOH = 675, BOSS_FB_HELLPUP = 676, BOSS_FB_CHICKEN = 677, BOSS_FB_M78 = 678, BOSS_FB_METALALIEN = 679, BOSS_FB_TAKA = 680, FB_BUGGER_SWARM = 681,
    FB_FB_POISONOUSINSECTGEL_SWARM = 682, FB_MUTANTCRAWLER = 683, FB_MOSQUITO = 684, FB_WALKINGBALL = 685, FB_GORDEA = 686, BOSS_FB_BIGFUZZ = 687, FB_BULLET_FIREBALL = 688,
    FB_BULLET_EYELASER = 689, FB_BULLET_BOMB = 690, FB_GIGAFLY_SWARM = 691, FB_BULLET = 692, FB_ALIENCENTIPEDE = 693, FB_EVILSNOWMAN = 694, BOSS_FB_FLIGHTZAKO = 695, FB_HELLRIDER_SWARM = 696,
    FB_WINGLIZARD_FLYING = 697, FB_BUNDLE_FLYING = 698, FB_MOSQUITO_FLYING = 699, FB_FLIGHTZAKO_FLYING = 700, BOSS_FB_FLIGHTZAKO_FLYING = 701, FB_METALALIEN_FLYING = 702,
    BOSS_FB_METALALIEN_FLYING = 703, FB_ALIENCENTIPEDE_FLYING = 704, FB_HELLRIDER_RACING = 705, FB_MUTANTCRAWLER_RACING = 706, FB_WALKINGBALL_RACING = 707, BOSS_FB_WALKINGBALL_RACING = 708,
    FB_EVILSNOWMAN_RACING = 709, FB_JUNKYARDCAR_RACING = 710, BOSS_FB_JUNKYARDCAR_RACING = 711, FB_CHICKEN_RACING = 712, BOSS_FB_CHICKEN_RACING = 713, FB_M78_RACING = 714,
    BOSS_FB_M78_RACING = 715, FB_GORDEA_RACING = 716, BOSS_FB_TAKA_RACING = 717, FB_HELLRIDER2_RACING = 718, FB_LEDDER_UNARMED = 719, FB_GIGAFLY = 720, BOSS_FB_MUTANTCRAWLER = 721,
    FB_SIMONDO = 722, FB_PATROL_WARLORD = 723, FB_PATROL_FLIGHTZAKO = 724, FB_PATROL_GIGAFLY = 725, BOSS_DIVANO = 800, BOSS_MILKMAG = 801, EX_COSMICEYE = 802, EX_CART_REAPER = 803,
    EX_CART_TRICKSTER = 804, EX_CART_STALKER = 805, EX_CART_DROWNER = 806, EX_CART_MADDENER = 807, EX_GYORUNTIN = 808, EX_BOSSGYORUNTIN = 809, EX_RACING_BAT3 = 810, EX_RACING_XLBAT = 811,
    EX_RACING_RETRO = 812, EX_RACING_FISHMAN_1 = 813, EX_CONSTABLEBOT_RANGED = 814, EX_TDCCC_RANGED = 815, EX_BOUNTYHUNTER_RANGED = 816, EX_ER2000_RANGED = 817, BULLET_SM1 = 818,
    BULLET_SM2 = 819, EX_FISHMAN_1GREEN = 820, EX_RETROBOT_SWARM = 821, EX_GYORUNTIN_SWARM = 822, EX_YTRAINEE_SWARM = 823, EX_EXPLOANGEL_SWARM = 824, EX_TRINA_SWARM = 825,
    EX_COSMICEYE_SWARM = 826, EX_MUD_FASTSWARM = 827, EX_ECTO2_FASTSWARM = 828, EX_JELLYFISH2_FASTSWARM = 829, EX_RACING_LIZARD2_3 = 830, EX_RACING_LIZARD1_2 = 831, EX_RACING_MERMA1_3 = 832,
    EX_RACING_MERMA2_4 = 833, EX_RACING_PILE1 = 834, EX_RACING_PILE2 = 835, EX_RACING_PILE3 = 836, EX_RACING_BOSS_PILE3 = 837, EX_RACING_BOSS_MERMAN = 838, EX_RACING_BUER = 839,
    EX_RACING_IMP = 840, EX_RACING_XLDRAGON1 = 841, EX_CART_BLINDER = 842, EX_RACING_BOSS_MIGNO2_5 = 843, EX_BOSSGYORUNTIN_SOLID = 844, EX_TRUEDEVIL = 845, EX_OGREHEAD = 846,
    EX_KINGHEAD = 847, EX_VICIOUSHUNGER = 848, EX_BATGOBLIN = 849, EX_BATGOBLIN2 = 850, EX_BOSS_TRUEDEVIL = 851, EX_BOSS_OGREHEAD = 852, EX_BOSS_KINGHEAD = 853, EX_BOSS_VICIOUSHUNGER = 854,
    EX_TREASURE_VICIOUSHUNGER = 855, EX_DEMON_RED = 856, COOP_CHICKEN_H = 857, COOP_COCK_H = 858, COOP_CHIK_H = 859, COOP_ABRAXAS_H = 860, COOP_ABRAXASCROWN_H = 861, COOP_ABRAXASHALO_H = 862,
    COOP_BOSS_ABRAXAS = 863, COOP_BOSS_ABRAXASCROWN = 864, COOP_BOSS_ABRAXASHALO = 865, COOP_CHICKEN_SWARM = 866, COOP_COCK_SWARM = 867, COOP_CHIK_SWARM = 868, COOP_EGG_SWARM = 869,
    COOP_CHICKEN_SPECIAL = 870, COOP_ROAST_CHICKEN = 871, COOP_ROAST_CHICKEN_H = 872, COOP_ROAST_CHICKEN_SWARM = 873, COOP_BOSS_COCK = 874, COOP_CHICKEN_SLOW = 875, COOP_PATROL = 876,
    COOP_CHICKEN_COUNTER = 877, FS_MUSH_BOSSMINION = 891, FS_MUSH_BOSS = 892, FS_FLAMINGSKULL_FLYING = 893, FS_MEATY_FLYING = 894, FS_HORMARI_FLYING = 895, FS_HORGLORY_FLYING = 896,
    FS_MEATBALL_FLYING = 897, FS_HORCAULD_FLYING = 898, FOSCARI_COUNTER = 899, EME_CALAMITY_B = 900, EME_CALAMITY_U = 901, EME_CALAMITY_R = 902, EME_CALAMITY_W = 903, EME_CALAMITY_Y = 904,
    EME_ALRAUNE = 905, EME_ANT = 906, EME_BALL = 907, EME_BAT = 908, EME_BIRD = 909, EME_BOAR = 910, EME_DOG = 911, EME_FROG = 912, EME_GOBLIN = 913, EME_KELPIE = 914, EME_MOCH = 915,
    EME_OGRE = 916, EME_RASCAL = 917, EME_SKELETON = 918, EME_SLIME = 919, EME_WEREWOLF = 920, EME_ALRAUNE_BOMB = 921, EME_RASCAL_SWARM = 922, EME_CALAMITY_SWARM = 923, EME_ANT2 = 930,
    EME_BALL2 = 931, EME_BIRD2 = 932, EME_BIRD3 = 933, EME_BOAR2 = 934, EME_DOG2 = 935, EME_DOG3 = 936, EME_FROG2 = 937, EME_FROG3 = 938, EME_GOBLIN2 = 939, EME_KELPIE2 = 940, EME_OGRE2 = 941,
    EME_RASCAL2 = 942, EME_SPECTERHEAD_PINK = 943, EME_SPECTERHEAD_BLUE = 944, EME_PATROL_BAT = 945, EME_PATROL_CALAMITY = 946, EME_SUSPICIOUS_OGRE = 947, EME_BOSS_CURSEDMONARCH = 948,
    EME_BOSS_ALRAUNE = 960, EME_BOSS_ANT = 961, EME_BOSS_BALL = 962, EME_BOSS_BAT = 963, EME_BOSS_BIRD = 964, EME_BOSS_BOAR = 965, EME_BOSS_DOG = 966, EME_BOSS_FROG = 967, EME_BOSS_GOBLIN = 968,
    EME_BOSS_KELPIE = 969, EME_BOSS_MOCH = 970, EME_BOSS_OGRE = 971, EME_BOSS_RASCAL = 972, EME_BOSS_SKELETON = 973, EME_BOSS_SLIME = 974, EME_BOSS_WEREWOLF = 975, EME_GATEBOSS_DRAGON = 990,
    EME_GATEBOSS_SPIRITBEAST = 991, EME_GATEBOSS_SPECTER = 992, EME_GATEBOSS_IRONMAIDEN = 993, EME_GATEBOSS_FINALEMPEROR = 994, EME_GATEBOSS_LIVINGANGUISH = 995, TP_BOSS_LEGION = 1000,
    TP_BOSS_LEGION_SECTION = 1001, TP_BOSS_LEGION_ZOMBIE = 1002, TP_BOSS_BEELZEBUB = 1003, TP_BOSS_BEELZEBUB_SECTION = 1004, TP_BOSS_BEELZEBUB_BEE = 1005, TP_FLEARIDER = 1006,
    TP_FROZENSHADE = 1007, TP_GAIBON = 1008, TP_HARPY = 1009, TP_IMP = 1010, TP_BOSS_MINOTAUR = 1011, TP_BOSS_MINOTAUR_SECTION = 1012, TP_KNIGHT = 1013, TP_MIMIC = 1014, TP_OWL = 1015,
    TP_PANTHER = 1016, TP_RHINO = 1017, TP_SIREN = 1018, TP_SKELETON = 1019, TP_SLOGRA = 1020, TP_SPIRIT = 1021, TP_SPIDER = 1022, TP_SWARM = 1023, TP_MECH = 1024, TP_DEATH_PORTAL = 1025,
    TP_DEATH = 1026, TP_BOSS_CARMILLA = 1027, TP_BOSS_CARMILLA_SECTION = 1028, TP_FLOATER = 1029, TP_BOSS_DRACULA1 = 1030, TP_BOSS_DRACULA1_SECTION = 1031, TP_BOSS_DRACULA2_GHOST = 1032,
    TP_BOSS_DRACULA2 = 1033, TP_BOSS_DRACULA2_SECTION = 1034, TP_BOSS_DRACULA1_DRAC_ULT = 1035, TP_BOSS_DRACULA2_GHOST_ULT = 1036, TP_BOSS_DRACULA2_ULT = 1037,
    TP_BOSS_DRACULA2_SECTION_ULT = 1038, TP_BULLET_DRACULA = 1039, TP_BULLET_DRACULA2 = 1040, TP_BULLET = 1041, TP_BULLET_DRACULA_ULT = 1042, TP_BULLET_DRACULA2_ULT = 1043, TP_SUMMONER = 1044,
    TP_OWL_SWARM = 1045, TP_SWARM_SWARM = 1046, TP_SPIDER_SWARM = 1047, TP_SPIRIT_SWARM = 1048, TP_PATROL_SLOGRA = 1049, TP_PATROL_GAIBON = 1050, TP_PATROL_MIMIC = 1051, TP_PATROL_OWL = 1052,
    TP_KNIGHT_AXEXL = 1053, TP_FROZENSHADE_FAST = 1054, TP_IMP_TINY = 1055, TP_PANTHER_BIG = 1056, TP_PATROL_SPIDER = 1057, TP_RHINO_HP = 1058, TP_MIMIC_HP = 1059, TP_SLOGRA_HP = 1060,
    TP_KNIGHT_HP = 1061, TP_KNIGHT_AXEXL_HP = 1062, TP_OWL_SWARM_FLYING = 1063, TP_SLOGRA_FLYING = 1064, TP_GAIBON_FLYING = 1065, TP_PANTHER_RACING = 1066, TP_PATROL_FROZENSHADE_RACING = 1067,
    TP_KNIGHT_RACING = 1068, TP_RHINO_RACING = 1069, TP_DEATH_RACING = 1070, TP_SLOGRA_RACING = 1071, TP_BOSS_RHINODUSA_RACING = 1072
};
enum class EnemySkillType : int
{
    HP_x_Level = 0, Fixed_Direction = 1, Self_Destruct = 2, Medusa = 3, _0x2fe496 = 4, _0x2fe497 = 5, _0x2fe498 = 6, _0x2fe499 = 7, _0x2fe49a = 8, _0x2fe49b = 9, _0x2fe49c = 10,
    _0x2fe49d = 11, _0x2fe49e = 12, _0x2fe49f = 13,
};
enum class WeaponType : int
{
    NONE = 0, MAGIC_MISSILE = 1, HOLY_MISSILE = 2, WHIP = 3, VAMPIRICA = 4, AXE = 5, SCYTHE = 6, KNIFE = 7, THOUSAND = 8, HOLYWATER = 9, BORA = 10, DIAMOND = 11, FIREBALL = 12,
    HELLFIRE = 13, HOLYBOOK = 14, VESPERS = 15, CROSS = 16, HEAVENSWORD = 17, GARLIC = 18, VORTEX = 19, LAUREL = 20, THORNS = 21, LIGHTNING = 22, LOOP = 23, PENTAGRAM = 24,
    ROSARY = 25, SIRE = 26, SILF = 27, SILF2 = 28, SILF3 = 29, BONE = 30, LANCET = 31, SONG = 32, MANNAGGIA = 33, CHERRY = 34, CART = 35, CART2 = 36, GATTI = 37, STIGRANGATTI = 38,
    GATTI_SCRATCH = 39, GATTI_SCUFFLE = 40, FLOWER = 41, GUNS = 42, GUNS2 = 43, GUNS3 = 44, TRAPANO = 45, TRAPANO2 = 46, SARABANDE = 47, FIREEXPLOSION = 48, NDUJA = 49, POWER = 50,
    AREA = 51, SPEED = 52, COOLDOWN = 53, DURATION = 54, AMOUNT = 55, MAXHEALTH = 56, ARMOR = 57, MOVESPEED = 58, MAGNET = 59, GROWTH = 60, LUCK = 61, GREED = 62, REVIVAL = 63,
    SHIELD = 64, REGEN = 65, CURSE = 66, SILVER = 67, GOLD = 68, ROCHER = 69, ROCHEREXP = 70, LEFT = 71, RIGHT = 72, CORRIDOR = 73, SHROUD = 74, COLDEXPLOSION = 75, WINDOW = 76,
    PANDORA = 77, VENTO = 78, VENTO2 = 79, VENTO2_EXPLO = 80, VENTO2_EXTRA = 81, ROBBA = 82, WINDOW2 = 83, SILF_COUNTER = 85, SILF2_COUNTER = 86, RAYEXPLOSION = 87, CANDYBOX = 88,
    GUNS_COUNTER = 89, GUNS2_COUNTER = 90, JUBILEE = 91, VICTORY = 92, SOLES = 93, GATTI_COUNTER = 94, NDUJA_COUNTER = 95, TRIASSO1 = 96, TRIASSO2 = 97, TRIASSO3 = 98, BLOODLINE = 99,
    CANDYBOX2 = 100, BUBBLES = 101, ASTRONOMIA = 102, BLOOD_GARLIC = 103, BLOOD_SONG = 104, BLOOD_PENTAGRAM = 105, BLOOD_LANCET = 106, BLOOD_LAUREL = 107, JUBILEE_RAYS = 108,
    MISSPELL = 109, MISSPELL2 = 110, SILVERWIND = 111, SILVERWIND2 = 112, FOURSEASONS = 113, FOURSEASONS2 = 114, SUMMONNIGHT = 115, SUMMONNIGHT2 = 116, MIRAGEROBE = 117,
    MIRAGEROBE2 = 118, BUBBLES2 = 119, NIGHTSWORD = 120, NIGHTSWORD2 = 121, BOCCE = 122, BOCCE_COUNTER = 123, SPELL_STRING = 124, SPELL_STREAM = 125, SPELL_STRIKE = 126,
    SPELL_STROM = 127, BONE2 = 128, BONE_ARM = 129, TETRAFORCE = 130, SHADOWSERVANT = 131, SHADOWSERVANT2 = 132, PRISMATICMISS = 133, PRISMATICMISS2 = 134, FLASHARROW = 135,
    FLASHARROW2 = 136, SEC_MILLIONAIRE = 137, SWORD = 138, SWORD2 = 139, PARTY = 140, SWORD_FINISHER = 141, LEGIONNAIRE = 142, PHASER = 143, SHADOWSERVANT_COUNTER = 144,
    PARTY_COUNTER = 145, ACADEMYBADGE = 146, INSATIABLE = 147, CHERRY2 = 148, CHERRY_STAR_EXPLO = 149, CHERRY_STAR = 150, ICELANCE = 151, ICELANCE2 = 152, ZODIAC = 153, CART2EVO = 154,
    FLOWER2 = 155, LAROBBA2 = 156, ULTIMAX = 157, ARMADIO = 158, BOOMBALL = 159, PHASER2 = 160, BATTILIA = 161, BATTILIA2 = 162, EX_MAGISTONE1 = 163, EX_MAGISTONE2 = 164,
    STARRYHEAVENDAMAGE = 165, C1_REPORT1 = 166, C1_REPORT2 = 167, C1_SWIPECARD1 = 168, C1_SWIPECARD2 = 169, C1_MEDICAL1 = 170, C1_MEDICAL2 = 171, C1_VENT1 = 172, C1_VENT2 = 173,
    C1_GARBA1 = 174, C1_GARBA2 = 175, C1_TONGUE1 = 176, C1_TONGUE2 = 177, C1_SAMPLES1 = 178, C1_SAMPLES2 = 179, C1_HATCOLLECTION1 = 180, C1_HATCOLLECTION_EXPLO = 181,
    C1_SHRINK_CREWMA = 182, C1_SHRINK_ENGINE = 183, C1_SHRINK_GHOSTT = 184, C1_SHRINK_SHAPES = 185, C1_SHRINK_GUARDI = 186, C1_SHRINK_IMPOST = 187, C1_SHRINK_SCIENT = 188,
    C1_SHRINK_HORSEE = 189, C1_SWIPECARD1_SPARK = 190, C1_TONGUE1_COUNTER = 191, C1_SAMPLES1_EXPLOSION = 192, C1_SAMPLES2_EXPLOSION = 193, C1_SAMPLES2_REACTOR = 194, PARMA = 201,
    DOMINION = 202, NOVA_FIRE = 203, NOVA_ICEE = 204, NOVA_FEAR = 205, FLIK = 206, FLIK2 = 207, TRAINHAZARD = 208, SANTAJAVELIN = 209, SANTAJAVELIN2 = 210, PURIFYWEIRDSOULS = 211,
    SANTAJAVELINCOUNTER = 212, SANTAJAVELIN2EXPLO = 213, CONEOFCOLD = 214, FLOOD = 215, CONEOFCOLD_COUNTER = 216, FOLLOWER_GARLIC = 217, EX_AMMO1 = 218, EX_AMMO2 = 219,
    EX_AMMO1_COUNTER = 220, EX_TOHILSTATUE = 221, EX_GROUNDHIT = 222, FB_FULLAUTO = 300, FB_RAPIDFIRE = 301, FB_SPREAD = 302, FB_SONIC = 303, FB_BLADECROSSBOW = 304, FB_WAVE = 305,
    FB_LASER = 306, FB_FIREARM = 307, FB_METALCLAW = 308, FB_CRUSH = 309, FB_HOMING = 310, FB_PRISMCUTLASS = 311, FB_PROTOTYPE = 312, FB_PROTONBEAM = 313, FB_FIREWALL = 314,
    FB_BIGFUZZYFIST = 315, FB_MULTISTAGE = 316, FB_TIMEWARP = 317, FB_WEAPONPU = 318, FB_DEATHRAY = 319, FB_SOLAR = 320, FB_CROSSBOT = 321, FB_PROTOTYPE_B = 322, FB_PROTOTYPE_B_PLANE = 323,
    FB_PROTOTYPE_B_EXPLOSION = 333, FB_PROTOTYPE_A = 334, FB_PROTOTYPE_C = 335, FB_PROTOTYPE_C_EXPLOSION = 336, FB_CROSSBOWCRASH = 337, FB_CROSSBOWCRASH_SWORD = 338, FB_DIVERMINES = 339,
    FB_PLANES = 340, FB_FIREEXPLOSION = 341, FB_EXPLOCARHAZARD = 342, FB_EXPLOBARRELHAZARD = 343, FB_PRISMCUTLASS_COUNTER = 344, EME_RAPIER1 = 361, EME_RAPIER2 = 362, EME_RAPIER3 = 363,
    EME_DUAL1 = 364, EME_DUAL2 = 365, EME_PUNCH1 = 366, EME_PUNCH2 = 367, EME_PUNCH3 = 368, EME_KICK1 = 369, EME_KICK2 = 370, EME_CANNON1 = 371, EME_CANNON2 = 372, EME_CANNON3 = 373,
    EME_PISTOL1 = 374, EME_PISTOL2 = 375, EME_MAGIC1 = 376, EME_MAGIC2 = 377, EME_MAGIC3 = 378, EME_MAGIC4 = 379, EME_MAGIC5 = 380, EME_MAGIC6 = 381, EME_MECH1 = 382, EME_MECH2 = 383,
    EME_MECH3 = 384, EME_KATANA1 = 385, EME_KATANA2 = 386, EME_LONGSWORD1 = 387, EME_LONGSWORD2 = 388, EME_LONGSWORD3 = 389, EME_BLOOD1 = 390, EME_BLOOD2 = 391, EME_KNIFE1 = 392,
    EME_KNIFE2 = 393, EME_KNIFE3 = 394, EME_AXE1 = 395, EME_AXE2 = 396, EME_AXE3 = 397, EME_SPEAR1 = 398, EME_SPEAR2 = 399, EME_SPEAR3 = 400, EME_GREATSWORD1 = 401, EME_GREATSWORD2 = 402,
    EME_GREATSWORD3 = 403, EME_SELECTOR = 404, EME_WAVE = 405, EME_WAVE2 = 406, EME_RING_WOOD = 407, EME_RING_METAL = 408, EME_RING_FIRE = 409, EME_RING_WATER = 410, EME_RING_EARTH = 411,
    EME_RING_CHAOS = 412, EME_SWORD_SWALLOW = 413, EME_AXE_HELLFURY = 414, EME_MECH_RAVE = 415, EME_MECH_BALLMISS = 416, EME_BLOOD_BLOODRAGE = 417, EME_SWORD_GALE = 418, BLOOD_STREAM = 499,
    D20_JETBLACK = 500, D20_JETBLACK_EXPLOSION = 501, EX_GAEA1 = 502, EX_GAEA2 = 503, EX_SUMM1 = 504, EX_SUMM2 = 505, D13_MADMOON = 506, EX_COINTOSS1 = 507, EX_COINTOSS2 = 508,
    EX_RUMBA1 = 509, FOLLOWER_KNIFE1 = 510, FOLLOWER_KNIFE2 = 511, TP_EVANESCERE = 1401, TP_CONFODERE1 = 1402, TP_CONFODERE2 = 1403, TP_CONFODERE3 = 1404, TP_ALCHEMYWHIP1 = 1405,
    TP_ALCHEMYWHIP2 = 1406, TP_COATOFARMS = 1407, TP_MORNINGSTAR = 1408, TP_SPELLBOOK = 1409, TP_DIABOLOGUE = 1410, TP_ALUCARDSWORD1 = 1411, TP_ALUCARDSWORD2 = 1412, TP_IRONBALL1 = 1413,
    TP_IRONBALL2 = 1414, TP_ALUCARDSPEAR1 = 1415, TP_ALUCARDSPEAR2 = 1416, TP_MACE1 = 1417, TP_MACE2 = 1418, TP_CHAUVE1 = 1419, TP_CHAUVE2 = 1420, TP_JAVELIN1 = 1421, TP_JAVELIN2 = 1422,
    TP_BWAKA1 = 1423, TP_BWAKA2 = 1424, TP_SHURIKEN1 = 1425, TP_SHURIKEN2 = 1426, TP_LIGHT1 = 1427, TP_LIGHT2 = 1428, TP_DARK1 = 1429, TP_DARK2 = 1430, TP_DISCUS1 = 1431, TP_DISCUS2 = 1432,
    TP_WINEGLASS1 = 1433, TP_WINEGLASS2 = 1434, TP_MARTIALWHIP1 = 1435, TP_MARTIALWHIP2 = 1436, TP_CUSTOS1 = 1437, TP_CUSTOS2 = 1438, TP_CUSTOS3 = 1439, TP_CUSTOS4 = 1440,
    TP_WINDWHIP1 = 1441, TP_WINDWHIP2 = 1442, TP_PLATINUMWHIP1 = 1443, TP_PLATINUMWHIP2 = 1444, TP_DRAGONWATER1 = 1445, TP_DRAGONWATER2 = 1446, TP_SOULSTEAL_WEAPON = 1447, TP_RPG1 = 1449,
    TP_RPG2 = 1450, TP_ALUCARDSHIELD = 1451, TP_RAPIDUS1 = 1452, TP_RAPIDUS2 = 1453, TP_PNEUMA_SPIKES = 1454, TP_FIRE1 = 1455, TP_FIRE2 = 1456, TP_ICE1 = 1457, TP_ICE2 = 1458,
    TP_WIND1 = 1459, TP_WIND2 = 1460, TP_EARTH1 = 1461, TP_EARTH2 = 1462, TP_ELEC1 = 1463, TP_ELEC2 = 1464, TP_ACID1 = 1465, TP_ACID2 = 1466, TP_EVIL1 = 1467, TP_EVIL2 = 1468,
    TP_HOLY1 = 1469, TP_HOLY2 = 1470, TP_SPITE1 = 1471, TP_SPITE2 = 1472, TP_ENERGY1 = 1473, TP_ENERGY2 = 1474, TP_FIRE1_COUNTER = 1475, TP_ICE1_COUNTER = 1476, TP_EARTH1_COUNTER = 1477,
    TP_WIND1_COUNTER = 1478, TP_ELEC1_COUNTER = 1479, TP_ACID1_COUNTER = 1480, TP_EVIL1_COUNTER = 1481, TP_HOLY1_COUNTER = 1482, TP_SPITE1_COUNTER = 1483, TP_ENERGY1_COUNTER = 1484,
    TP_DCUSTOS_FIRE = 1485, TP_DCUSTOS_EXPLOSION = 1486, TP_SCUSTOS_MIRAGE = 1487, TP_SCUSTOS_EXPLOSION = 1488, TP_SONICWHIP2 = 1489, TP_HOLYWHIP1 = 1490, TP_HOLYWHIP2 = 1491,
    TP_GUN1 = 1492, TP_GUN2 = 1493, TP_SLASH1 = 1494, TP_SLASH2 = 1495, TP_UNIVERSITAS = 1496, TP_DOMINUS1 = 1497, TP_DOMINUS2 = 1498, TP_DOMINUS3 = 1499, TP_DOMINUS4 = 1500,
    TP_SACREDBEASTS1 = 1501, TP_SACREDBEASTS2 = 1502, TP_STARFLAIL1 = 1503, TP_STARFLAIL2 = 1504, TP_LEMURIA1 = 1505, TP_LEMURIA2 = 1506, TP_SPECTRALSWORD = 1507, TP_SHIELD1 = 1508,
    TP_SHIELD2 = 1509, TP_RPG1_EXPLOSION = 1510, TP_WINEGLASS1_SHARD = 1511, TP_NEUTRON_PICKUP = 1512, TP_NEUTRON_WEAPON = 1513, TP_SOULSTEAL_PICKUP = 1514, TP_ALUCARDSPEAR1_BODY = 1515,
    TP_SACREDBEASTS1_BIRD = 1516, TP_SACREDBEASTS1_TURTLE = 1517, TP_SACREDBEASTS1_DRAGON = 1518, TP_SACREDBEASTS1_CAT = 1519, BLANK_PROJECTILE = 1520, TP_HOLYWHIP1_SMOKE = 1521,
    TP_WINDWHIP1_FIRE = 1522, TP_WINDWHIP1_EXPLOSION = 1523, TP_GEARS_WEAPON = 1524, TP_PENDULUM_WEAPON = 1525, TP_SHURIKEN1_EXPLOSION = 1526, TP_GUN1_GUN = 1527, TP_MACE1_CRIT = 1528,
    TP_LIGHT2_ORBIT = 1529, TP_SAVROG_WEAPON = 1530, TP_SHIELD1_BLADE = 1531, TP_STARFLAIL1_BLADE = 1532, TP_CHAUVE2_BEAM = 1533, TP_CUSTOS3_BITE = 1534, TP_RPG2_EXPLOSION = 1535,
    TP_MACE2_CRIT = 1536, TP_ALUCARDSPEAR_POMMEL = 1537, TP_GUN1_SHRAPNEL = 1538, TP_MACE1_LINGER = 1539, TP_MACE1_CRIT_LINGER = 1540, TP_MACE2_INVIS = 1541, TP_MACE2_STANDARD = 1542,
    TP_STARFLAIL1_BODY = 1543, TP_HOLYWHIP1_NODE = 1544, TP_CUSTOS4_FIREBALL = 1545, TP_SONICWHIP1 = 1546, TP_WINDWHIP1_NODE = 1547, TP_DRAGONWATER1_NODE = 1548, TP_unused1_node = 1549,
    TP_LEMURIA1_NODE = 1550, TP_LEMURIA1_SPIKE = 1551, TP_unused1_slam = 1552, TP_STARFLAIL2_BLADE = 1553, TP_GOTH_MISSILE = 1554, TP_GOTH_MISSILE_HOLYWHIP2 = 1555, TP_HYDROSTORM = 1556,
    TP_HYDROSTORM_WATERDRAGONWHIP = 1557, TP_SONICWHIP1_NODE = 1558, TP_FIRE2_TAIL = 1559, TP_DARKRIFT = 1560, TP_DARKRIFT_JETBLACKWHIP = 1561, TP_SUMMON_SPIRIT = 1562,
    TP_SWORD_BROTHERS = 1563, TP_VALMANWAY = 1564, TP_VALMANWAY_SONICWHIP = 1565, TP_WHIPMEMORY = 1566, TP_GRANDCROSS = 1567, TP_GRANDCROSS_PLATINUMWHIP = 1568, TP_SPIRITTORNADO = 1569,
    TP_SPIRITTORNADO_WINDWHIP = 1570, TP_unused_earth2_counter = 1571, TP_DIAMOND3 = 1572, TP_ELEVATOR_WEAPON = 1573, TP_HEADS_WEAPON = 1574, TP_CLOCKTOWER_WEAPON = 1575,
    TP_unused_energy2_counter = 1576, TP_SHIELD2_METEORS = 1577, TP_AURABLAST_WEAPON = 1578, TP_BLUEFIRE_WEAPON = 1579, TP_AURABLAST_MARTIALWHIP = 1580, TP_SHAFTORB = 1581,
    TP_ACC_FAMILIAR_UKOBACK = 1582, TP_ACC_FAMILIAR_BITTERFLY = 1583, TP_ACC_FAMILIAR_IMP = 1584, TP_ACC_FAMILIAR_ALLEGEDGHOST = 1585, TP_ACC_FAMILIAR_WIZARD = 1586,
    TP_ACC_FAMILIAR_FAIRY = 1587, TP_ACC_FAMILIAR_PUMPKIN = 1588, TP_FAMILIARFORGE = 1589, TP_ACC_FAMILIAR_CARDINAL = 1590, TP_ACC_FAMILIAR_DRAGON = 1591, TP_ACC_FAMILIAR_TIGER = 1592,
    TP_ACC_FAMILIAR_TURTLE = 1593, TP_ICEBRAND = 1594, TP_FROG = 1595, BLOOD_RAPIDUS = 1596, TP_DEATHHAND = 1597, TP_DRACULAHAND = 1598, TP_POWEROFLIRE = 1599, TP_NEUTRON_WEAPON2 = 1600,
    TP_SAVROG_WEAPON2 = 1601, TP_HYDROSTORM2 = 1602, TP_GRANDCROSS2 = 1603, TP_GOTH_MISSILE2 = 1604, TP_ICEBRAND2 = 1605, TP_VALMANWAY2 = 1606, TP_AURABLAST_WEAPON2 = 1607,
    TP_SOULSTEAL_WEAPON2 = 1608, TP_DARKRIFT2 = 1609, TP_SWORD_BROTHERS2 = 1610, TP_SUMMON_SPIRIT2 = 1611, TP_SPIRITTORNADO2 = 1612, TP_FROG2 = 1613, TP_FROG_COUNTER = 1614,
    TP_POCKET1 = 1615, TP_POCKET2 = 1616, TP_LAPISTE1 = 1617, TP_LAPISTE2 = 1618, TP_RULERSWORD_BODY = 1619, LEM_ACC_SABOTEUR = 1700, LEM_INFERNO1 = 1701, LEM_INFERNO2 = 1702,
    LEM_BANANA1 = 1703, LEM_BANANA2 = 1704, LEM_FIBONACCI1 = 1705, LEM_FIBONACCI2 = 1706, LEM_PLANETS1 = 1707, LEM_PLANETS2 = 1708, LEM_BANANA2_HIDDEN = 1709, EME_RAPIER_TECH_01 = 2361,
    EME_RAPIER_TECH_02 = 2362, EME_RAPIER_TECH_03 = 2363, EME_DUAL_TECH_01 = 2364, EME_DUAL_TECH_02 = 2365, EME_PUNCH_TECH_01 = 2366, EME_PUNCH_TECH_02 = 2367, EME_PUNCH_TECH_03 = 2368,
    EME_KICK_TECH_01 = 2369, EME_KICK_TECH_02 = 2370, EME_CANNON_TECH_01 = 2371, EME_CANNON_TECH_02 = 2372, EME_CANNON_TECH_03 = 2373, EME_PISTOL_TECH_01 = 2374, EME_PISTOL_TECH_02 = 2375,
    EME_MECH_TECH_01 = 2376, EME_MECH_TECH_02 = 2377, EME_MECH_TECH_03 = 2378, EME_KATANA_TECH_01 = 2379, EME_KATANA_TECH_02 = 2380, EME_LONGSWORD_TECH_01 = 2381, EME_LONGSWORD_TECH_02 = 2382,
    EME_LONGSWORD_TECH_03 = 2383, EME_BLOOD_TECH_01 = 2384, EME_BLOOD_TECH_02 = 2385, EME_SPEAR_TECH_01 = 2386, EME_SPEAR_TECH_02 = 2387, EME_SPEAR_TECH_03 = 2388, EME_AXE_TECH_01 = 2389,
    EME_AXE_TECH_02 = 2390, EME_KNIFE_TECH_01 = 2391, EME_KNIFE_TECH_02 = 2392, EME_GREATSWORD_TECH_01 = 2393, EME_GREATSWORD_TECH_02 = 2394, EME_GREATSWORD_TECH_03 = 2395,
    EME_MAGIC_TECH_01 = 2396, EME_MAGIC_TECH_02 = 2397, EME_MAGIC_TECH_03 = 2398, EME_MAGIC_TECH_04 = 2399, EME_MAGIC_TECH_05 = 2400, EME_MAGIC_TECH_06 = 2401
};
enum class BgmType : int
{
    BGM_Forest = 0, BGM_Library = 1, BGM_Library_Legacy = 2, BGM_GreenAcres = 3, BGM_Plant = 4, BGM_Mana = 5, BGM_Tower = 6, BGM_RedBlue = 7, BGM_Gatti = 8, BGM_Peggi = 9,
    BGM_Chapet = 10, BGM_Chapel = 11, BGM_Water = 12, BGM_Vento = 13, NONE = 14, TheEndIndeed = 15, TheEndIntro = 16, TheEndMain = 17, TheEndIndeed2 = 18, BGM_Bestiary = 19,
    BGM_Secret = 20, BGM_BossRush = 21, BGM_Machine = 22, BGM_Bones = 23, BGM_Solution = 24, BGM_Glitch = 25, BGM_Forest_B = 26, BGM_Library_B = 27, BGM_Plant_B = 28,
    BGM_Tower_B = 29, BGM_Chapel_B = 30, BGM_Pizza = 31, BGM_Pizza_B = 32, BGM_Water_B = 33, BGM_GreenAcres_B = 34, BGM_Bones_B = 35, BGM_BossRush_B = 36, BGM_Cosmic = 37,
    Phase0 = 38, Phase1 = 39, Phase2 = 40, Phase3 = 41, Phase4 = 42, Phase5 = 43, BGM_Spoopy = 44, BGM_Flame = 45, BGM_Bridge = 46, BMG_Moonspell = 47, BGM_Silver = 48,
    BGM_FourSeasons = 49, BGM_Night1 = 50, BGM_Night2 = 51, BGM_Mirage = 52, BGM_BatCountry = 53, BGM_Foscari = 54, BGM_Magic = 55, BGM_War = 56, BGM_Deception = 57,
    BGM_Luminaire = 58, BGM_Genevieve = 59, BGM_Foscari2 = 60, BGM_Nature = 61, BGM_HB = 62, BGM_Foscari_KAZ = 63, BGM_Magic_KAZ = 64, BGM_War_KAZ = 65, BGM_Deception_KAZ = 66,
    BGM_AstralStair = 67, BGM_Snow = 68, BGM_SpaceDude = 69, BGM_SpaceDude_Intro = 70, BGM_Labor = 71, BGM_Carts = 72, BGM_Devil = 73, BGM_TheCoop = 74, BGM_Westwoods = 75,
    BGM_Mazerella = 76, BGM_CAL_MainTheme = 1001, BGM_CAL_HideSeek = 1002, BGM_CAL_NoDucks = 1003, BGM_CAL_NoAliens = 1004, BGM_CAL_NoGhosts = 1005, BGM_CAL_NoVamps = 1006,
    BGM_FB_COVER_00_Jung = 1100, BGM_FB_COVER_02_Wate = 1101, BGM_FB_COVER_05_Yoro = 1103, BGM_FB_COVER_06_Hard = 1102, BGM_FB_COVER_09_Gtra = 1104, BGM_FB_COVER_11_Fort = 1105,
    BGM_FB_K00_Jung = 1106, BGM_FB_K01_Spir = 1107, BGM_FB_K02_Wate = 1108, BGM_FB_K03_Zeph = 1109, BGM_FB_K04_Blue = 1110, BGM_FB_K05_Yoro = 1111, BGM_FB_K06_Hard = 1112,
    BGM_FB_K07_Some = 1113, BGM_FB_K08_JNHD = 1114, BGM_FB_K09_Gtra = 1115, BGM_FB_K10_Moon = 1116, BGM_FB_K11_Fort = 1117, BGM_FB_K12_Last = 1118, BGM_FB_K13_Rave = 1119,
    BGM_TP_loi_LeonsTheme = 1120, BGM_TP_SuccessorOfFate = 1125, BGM_TP_cotm_Awake = 1155, BGM_TP_jud_MadForest = 1178, BGM_TP_cod_AbandonedCastle = 1140,
    BGM_TP_cod_BaljhetMountains = 1144, BGM_TP_cod_EneomausMachineTower = 1154, BGM_TP_cod_FollowersOfDarkness = 1145, BGM_TP_cod_SarabandeOfHealing = 1137,
    BGM_TP_dos_AfterConfession = 1149, BGM_TP_dos_AmberScenery = 1142, BGM_TP_dos_DraculasTears = 1121, BGM_TP_dos_IntoTheDarkNight = 1133, BGM_TP_dos_PitchBlackIntrusion = 1123,
    BGM_TP_hod_AfterConfession = 1139, BGM_TP_hod_AnEmptyTome = 1150, BGM_TP_hod_Aquarius = 1122, BGM_TP_hod_DanceOfIllusions = 1129, BGM_TP_hod_DivineBloodlines = 1126,
    BGM_TP_hod_DraculasCastle = 1143, BGM_TP_hod_EbonyWings = 1151, BGM_TP_hod_GazeUpAtTheDarkness = 1161, BGM_TP_hod_HeartOfFire = 1127, BGM_TP_hod_IntoTheDarkNight = 1160,
    BGM_TP_hod_InvitationOfACrazedMoon = 1135, BGM_TP_hod_PitifulScion = 1157, BGM_TP_hod_PitchBlackIntrusion = 1128, BGM_TP_hod_SimonsTheme = 1124, BGM_TP_hod_TheHiddenCurse = 1130,
    BGM_TP_hod_TheLostPortrait = 1162, BGM_TP_ooe_AnEmptyTome = 1131, BGM_TP_ooe_ChapelHiddenInSmoke = 1156, BGM_TP_ooe_EbonyWings = 1132, BGM_TP_ooe_JawsOfAScorchedEarth = 1138,
    BGM_TP_ooe_WanderingTheCrystalBlue = 1152, BGM_TP_por_GazeUpAtTheDarkness = 1141, BGM_TP_por_InSearchOfTheHiddenSpell = 1146, BGM_TP_por_InvitationOfACrazedMoon = 1159,
    BGM_TP_por_IronBlueIntention = 1173, BGM_TP_por_TheHiddenCurse = 1174, BGM_TP_por_VictorianFear = 1134, BGM_TP_sotn_DanceOfPales = 1148, BGM_TP_sotn_DanceOfIllusions = 1175,
    BGM_TP_sotn_FestivalOfServants = 1158, BGM_TP_sotn_GuardianMariaFight = 1153, BGM_TP_sotn_LostPainting = 1136, BGM_TP_sotn_MoonlightNocturne = 1147, BGM_TP_sotn_TragicPrince = 1176,
    BGM_TP_sotn_WoodCarvingPartita = 1177, BGM_TP_Bloodlines_TheBeatingInDarkness = 1163, BGM_TP_Bloodlines_ReincarnatedSoul = 1164, BGM_TP_Bloodlines_TheSinkingOldSanctuary = 1165,
    BGM_TP_Bloodlines_Beginning = 1167, BGM_TP_Bloodlines_BloodyTears = 1168, BGM_TP_Bloodlines_VampireKiller = 1169, BGM_TP_Bloodlines_IronBlueIntention = 1170,
    BGM_TP_Bloodlines_Pressure = 1171, BGM_TP_Bloodlines_Mystery = 1172, BGM_emptyslot = 1179, BGM_TP_VS_VampireKiller = 1300, BGM_TP_VS_AnEmptyTome = 1301, BGM_TP_VS_SimonTheme = 1302,
    BGM_TP_VS_DraculasCastle = 1303, BGM_TP_VS_SuccessorOfFate = 1304, BGM_TP_VS_BloodyTears = 1305, BGM_TP_VS_BlackDisk = 1306, BGM_TP_VS_MoonlightNocturne = 1310,
    BGM_TP_VS_LostPainting = 1311, BGM_TP_VS_DanceOfPearls = 1312, BGM_TP_VS_PitchBlackIntrusion = 1313, BGM_TP_VS_DraculasTears = 1314, BGM_TP_VS_AmberScenery = 1315,
    BGM_TP_VS_TragicPrince = 1343, BGM_TP_VS_WanderingTheCrystalBlue = 1320, BGM_TP_VS_JawsOfAScorchedEarth = 1321, BGM_TP_VS_ChapelHiddenInSmoke = 1322, BGM_TP_VS_SarabandeOfHealing = 1323,
    BGM_TP_VS_BaljhetMountaint = 1324, BGM_TP_VS_EneomaosMachineTower = 1325, BGM_TP_VS_TheBeginning = 1326, BGM_TP_VS_Aquarius = 1327, BGM_TP_VS_AbandonedCastle = 1328,
    BGM_TP_VS_WoodCarvingPartita = 1329, BGM_TP_VS_LeonsTheme = 1330, BGM_TP_VS_EbonyWings = 1331, BGM_TP_VS_MadForest = 1332, BGM_TP_VS_VictorianFear = 1333,
    BGM_TP_VS_BloodlinesBequeathed = 1334, BGM_TP_VS_InvitationOfACrazedMoon = 1335, BGM_TP_VS_ReincarnatedSoul = 1336, BGM_TP_VS_TheSinkingOldSanctuary = 1337, BGM_TP_VS_Awake = 1338,
    BGM_TP_VS_IronBlueIntention = 1339, BGM_TP_VS_HeartOfFire = 1340, BGM_TP_VS_AfterConfession = 1341, BGM_TP_SOH_Credits = 1342, BGM_TP_VS_OutOfTime = 1344, BGM_TP_VS_TreasuryRoom = 1345,
    BGM_TP_VS_C64Medley = 1346, BGM_TP_VS_CallingFromHeaven = 1347, BGM_TP_VS_DiscoloredWall = 1348, BGM_TP_VS_AntiSoulMysteriesLab = 1349, BGM_TP_VS_WanderingGhosts = 1350,
    BGM_TP_VS_DanceOfGold = 1351, BGM_TP_VS_RuinedCastleCorridor = 1352, BGM_TP_VS_YoungNoblemanOfMadness = 1353, BGM_TP_VS_ClockWork = 1354, BGM_TP_VS_NewMessiah = 1355,
    BGM_TP_Bloodlines_CallingFromHeaven = 1356, BGM_TP_Bloodlines_TheDiscoloredWall = 1166, BGM_TP_loi_AntiSoulMysteriesLab = 1357, BGM_TP_sotn_WanderingGhosts = 1358,
    BGM_TP_sotn_DanceOfGold = 1359, BGM_TP_hod_RuinedCastleCorridor = 1360, BGM_TP_cod_YoungNoblemanOfMadness = 1361, BGM_TP_cotm_Clockwork = 1362, BGM_TP_reb_NewMessiah = 1363,
    BGM_EME_QUICK = 1400, BGM_EME_SHOW = 1401, BGM_EME_DESTINY = 1402, BGM_EME_ENCHANTED = 1403, BGM_EME_POLICE = 1404, BGM_EME_BEAT = 1405, BGM_EME_DARKNESS = 1406,
    BGM_EME_FIERCE = 1407, BGM_EME_ODDS = 1408, BGM_EME_WORLD = 1409, BGM_LEM_CHAMBER = 1500
};
enum class AchievementType : int
{
    ReachLV5 = 0, ReachLV10 = 1, Have6DifferentWeapons = 2, GetFireWandToLevel4 = 3, GetHolyBookToLevel4 = 4, GetHolyWaterToLevel4 = 5, GetLightningRingToLevel4 = 6, GetMagicMissileToLevel7 = 7, GetPeachoneToLevel7 = 8, GetRunetracerToLevel7 = 9,
    Survive1Minute = 10, Survive5MinutesWithDiamond = 11, Survive10Minutes = 12, Survive20Minutes = 13, Destroy20Candles = 14, Eat5PotRoast = 15, FindAClover = 16, FindAVacuum = 17, FindAnOrologion = 18, FindARosary = 19, Defeat5000Enemies = 20,
    Defeat3000Skeletons = 21, DefeatBossMadForest = 22, ReachLV20InMadForest = 23, DefeatBossLibrary = 24, Survive5MinutesWithKnife = 25, FindAStoneMask = 26, GetGarlicToLevel7 = 27, EvolveWhip = 28, EvolveMagicWand = 29, EvolveKnife = 30,
    EvolveAxe = 31, EvolveCross = 32, EvolveKingBible = 33, EvolveFireWand = 34, EvolveGarlic = 35, UniteBirds = 36, Recover1000HP = 37, Earn5000CoinsInASingleRun = 38, Unlock2Hypers = 39, Survive20MinutesWithCross = 40, Defeat100KEnemies = 41,
    EvolveSantaWater = 42, EvolveLightning = 43, ReachLV100WithMortaccio = 44, Survive30MinutesInGreenAcres = 45, Survive30MinutesWithAxe = 46, Survive20MinutesWithCurse = 47, Defeat3000Buers = 48, ReachLV100WithCavallo = 49,
    ReachLV40InLibrary = 50, DefeatBossPlant = 51, FindMilkyWayMap = 52, FindCoffinStage3 = 53, Survive15MinutesWithSong = 54, EvolveSongOfMana = 55, GetPentagramToLevel7 = 56, Unlock3Hypers = 57, Survive15MinutesInMolise = 58, EvolvePentagram = 59,
    See50Items = 60, FindCoffinStage1 = 61, Survive10MinutesWithGuns = 62, Survive15MinutesWithGuns = 63, EvolveGuns = 64, ReachLV60InDairyPlant = 65, FindSorceressTears = 66, DefeatBossTower = 67, See60Items = 68, ReachLV100WithRamba = 69,
    Defeat3000Milk = 70, EvolveRunetracer = 71, See70Items = 72, FindRandomazzo = 73, ReachLV99WithGiovanna = 74, ReachLV99WithKroci = 75, FindRandomazzoT06 = 76, ReachLV99WithLama = 77, ReachLV99WithPoppea = 78, ReachLV99WithArca = 79,
    Survive15MinutesWithGatti = 80, FindCoffinStage2 = 81, Defeat3000Hydra = 82, Unlock3Hypers_Correct = 83, Survive30MinutesInBoneZone = 84, ReachLV100WithOsole = 85, ReachLV99WithImelda = 86, ReachLV99WithGennaro = 87, FindCoffinStage4 = 88,
    ReachLV99WithConcetta = 89, Survive15MinutesWithShadow = 90, EvolveGatti = 91, EvolveShadow = 92, Survive31MinutesInLibrary = 93, See80Items = 94, FindMagicBanger = 95, Unlock4Hypers = 96, Survive15MinutesInMoongolow = 97, BuyGlassMask = 98,
    ReachLV99WithPasqualina = 99, Survive31MinutesInTower = 100, See90Items = 101, FindYellowSign = 102, ObtainTheInfiniteCorridor = 103, ObtainTheCrimsonShroud = 104, ReachLV99WithAntonio = 105, Survive31MinutesInForest = 106,
    Have6Evolutions = 107, GetTorroneToLevel9 = 108, FindYellowSignS5 = 109, FindCoffinStage5 = 110, Survive15MinutesWithWind = 111, EvolveWind = 112, DefeatBossChapel = 113, Defeat6000StageKillers = 114, ReachLV99WithPorta = 115,
    Survive31MinutesInDairyPlant = 116, See100Items = 117, ReachLV100WithAmbrojoe = 118, FindGrimoire = 119, FindGouda = 120, FindGGospel = 121, DefeatBossChapel2 = 122, Unlock5Hypers = 123, Survive15MinutesInBossRash = 124,
    ReachLV99WithDommario = 125, ReachLV99WithPugnala = 126, ReachLV99WithChristine = 127, FindForbiddenScroll = 128, CompleteCollection = 129, Defeat100kWithSigma = 130, ReachLV99WithClerici = 131, ReachLV99WithPoe = 132, GalloDivano = 133,
    EvolveBracelet = 134, EvolveAll = 135, ObtainAllRelics = 136, ObtainSeventhTrumpet = 137, ObtainGraciasMirror = 138, GreatestJubilee = 139, Banish10Items = 140, ReachLV80InverseTower = 141, Unlock20BasePowerUps = 142, MOON01_FindCoffin = 143,
    MOON02_Survive15Miang = 144, MOON03_EvolveSilverWind = 145, MOON04_Survive15Menya = 146, MOON05_EvolveFourSeasons = 147, MOON06_Survive15Syuuto = 148, MOON07_EvolveSummonNight = 149, MOON08_Survive15BabiOnna = 150, MOON09_EvolveMirageRobe = 151,
    MOON10_Survive15McCoy = 152, MOON11_Defeat100kVanya = 153, MOON12_Defeat100kVadjouel = 154, MOON13_Defeat6kWater = 155, MOON14_FindNightSword = 156, MOON15_EvolveNightSword = 157, MOON16_DefeatBossRuins = 158, MOON17_EvolveBubbles = 159,
    ReachLV80InverseForest = 160, FindChaosMalachite = 161, FindApoplexy = 162, Banish20Items = 163, FOSC01_FindCoffin = 164, FOSC02_Survive15Eleanor = 165, FOSC03_GetStreamToLevel6 = 166, FOSC04_GetStrikeToLevel6 = 167, FOSC05_UniteSpells = 168,
    FOSC06_Survive15Viktor = 169, FOSC07_EvolveEskizzibur = 170, FOSC08_Survive15Keira = 171, FOSC09_EvolveFlashArrow = 172, FOSC10_BreakSeal1 = 173, FOSC11_BreakSeal2 = 174, FOSC12_BreakSeal3 = 175, FOSC13_Survive15Luminaire = 176,
    FOSC14_EvolvePrismatic = 177, FOSC15_Survive15Genevieve = 178, FOSC16_EvolveShadow = 179, FOSC17_Defeat100kGenevieve = 180, FOSC18_Defeat6kFairy = 181, FOSC19_Defeat6kHorror = 182, FOSC20_DefeatBossLake = 183, FOSC21_DefeatBossAbyss = 184,
    ReachLV80InverseLibrary = 185, FindChaosRosalia = 186, FindTrisection = 187, MOON18_FindMap_Moonspell = 188, FOSC22_FindMap_Foscari = 189, FindMap_AstralStair = 190, FindManyOrologions = 191, GetGlassFandangoToLevel7 = 192,
    EvolveGlassFandango = 193, SurviveUntilTheEndOfWhiteout = 194, FindAntidote = 195, FindChaosAltemanna = 196, FindAtlas = 197, CHAL01_FindCoffin = 198, CHAL02_Survive15Red = 199, CHAL03_EvolveReport = 200, CHAL04_Survive15Purple = 201,
    CHAL05_EvolveTongue = 202, CHAL06_Survive15Orange = 203, CHAL07_EvolveSwipe = 204, CHAL08_ReachLv50Pink = 205, CHAL09_EvolveSamples = 206, CHAL10_Survive15Green = 207, CHAL11_EvolveVent = 208, CHAL12_GetMedicalToLevel7 = 209,
    CHAL13_EvolveMedical = 210, CHAL14_KillOneWithYellow = 211, CHAL15_ReachLv50Blue = 212, CHAL16_EvolveGarbage = 213, CHAL17_Defeat6000Cute = 214, CHAL18_Defeat100kPurple = 215, CHAL19_DefeatBoss25 = 216, CHAL20_FindMap = 217,
    DefeatManyBats = 218, FindManyGoldenFinger = 219, GetPhas3rToLevel7 = 220, EvolvePhas3r = 221, Survive20MinutesInSpace54 = 222, FindBraveStory = 223, EvolveBattilia = 224, Banish40Items = 225, CompleteAdv_AGarlicParadise = 226,
    CompleteAdv_WorldOfLightAndDark = 227, MOON19_CompleteAdv = 228, FOSC23_CompleteAdv = 229, CHAL21_CompleteAdv = 230, CompleteAdv_OdeToCastlevania = 231, FindManyRosaries = 232, GetJavelinToLevel7 = 233, EvolveJavelin = 234,
    Survive20MinutesInLaborratory = 235, FindAnArmaDio = 236, HitManyEnemiesWithTrain = 237, FB_01_Find__Coffin = 238, FB_02_SurvivLong = 239, FB_03_EvolveLong = 240, FB_04_SurvivShort = 241, FB_05_EvolveShort = 242, FB_06_SurvivSpread = 243,
    FB_07_EvolveSpread = 244, FB_08_SurvivLaser = 245, FB_09_EvolveLaser = 246, FB_10_Find__Coffin = 247, FB_11_SurvivFire = 248, FB_12_EvolveFire = 249, FB_13_SurvivSonic = 250, FB_14_EvolveSonic = 251, FB_15_SurvivCross = 252,
    FB_16_EvolveCross = 253, FB_17_Find__Barrier = 254, FB_18_SurvivPrism = 255, FB_19_EvolvePrism = 256, FB_20_Find__Rapid = 257, FB_21_SurvivHoming = 258, FB_22_EvolveHoming = 259, FB_23_Find__Grenade = 260, FB_24_SurvivMines = 261,
    FB_25_EvolveMines = 262, FB_26_DefeatSpecial = 263, FB_27_SurvivClaw = 264, FB_28_EvolveClaw = 265, FB_29_DefeatBoss = 266, FB_30_Find__Map = 267, CastForbiddenBox = 268, ObtainDarkasso = 269, Dark_06Darkasso = 270, Dark_01SpaceDude = 271,
    Dark_10Santa = 272, Dark_12Shemoon = 273, Dark_21Robert = 274, TP_Leon_FindCoffin1 = 275, TP_Sonia_HeartRefresh = 276, TP_Trevor_Boss1 = 277, TP_Sypha_EvoDragonwater = 278, TP_Grant_Boss2 = 279, TP_Alucard_Boss3 = 280,
    TP_Hector_KarmaCoins = 281, TP_Christopher_EvoSworb = 282, TP_Simon_EvoLemuria = 283, TP_Juste_EvoCurse = 284, TP_Julius_FindCoffin2 = 285, TP_Yoko_Boss4 = 286, TP_Soma_Boss5 = 287, TP_Jonhathan_EvoRPG = 288, TP_Charlotte_Mirrors = 289,
    TP_John_EvoSpells = 290, TP_Eric_EvoJavelin = 291, TP_Shanoa_EvoTwo = 292, TP_Maria_unlock = 293, TP_Richter_EvoBeasts = 294, TP_Dracula_FindCoffin3 = 295, TP_Elizabeth = 296, TP_Shaft = 297, TP_Lisa = 298, TP_Quincy = 299, TP_Mina = 300,
    TP_Vincent = 301, TP_Celia = 302, TP_Sara = 303, TP_Rinaldo = 304, TP_Maxim = 305, TP_Albus = 306, TP_Isaac = 307, TP_Julia = 308, TP_StGermain = 309, TP_Nathan = 310, TP_Reinhardt_FindCoffin4 = 311, TP_Henry = 312, TP_Carrie = 313,
    TP_Cornell = 314, TP_Selector_MorningStar = 315, TP_Selector_SpectralSword = 316, TP_Selector_CoatOfArms = 317, TP_Selector_Spellbook = 318, TP_Selector_Diabologue = 319, TP_Teleport1 = 320, TP_Teleport2 = 321, TP_Teleport3 = 322,
    TP_Teleport4 = 323, TP_Teleport5 = 324, TP_Teleport6 = 325, TP_Weapon_WHIP_1 = 326, TP_Weapon_WHIP_2 = 327, TP_Weapon_WHIP_3 = 328, TP_Weapon_WHIP_4 = 329, TP_Weapon_WHIP_5 = 330, TP_Weapon_WHIP_6 = 331, TP_Weapon_WHIP_7 = 332,
    TP_Weapon_WHIP_8 = 333, TP_Weapon_PROJECTILE_1 = 334, TP_Weapon_PROJECTILE_2 = 335, TP_Weapon_PROJECTILE_3 = 336, TP_Weapon_PROJECTILE_4 = 337, TP_Weapon_PROJECTILE_5 = 338, TP_Weapon_PROJECTILE_6 = 339, TP_Weapon_PROJECTILE_7 = 340,
    TP_Weapon_PROJECTILE_8 = 341, TP_Weapon_SPELL_1 = 342, TP_Weapon_SPELL_2 = 343, TP_Weapon_SPELL_3 = 344, TP_Weapon_SPELL_4 = 345, TP_Weapon_SPELL_5 = 346, TP_Weapon_SPELL_6 = 347, TP_Weapon_SPELL_7 = 348, TP_Weapon_SPELL_8 = 349,
    TP_Weapon_WEAPON_1 = 350, TP_Weapon_WEAPON_2 = 351, TP_Weapon_WEAPON_3 = 352, TP_Weapon_WEAPON_4 = 353, TP_Weapon_WEAPON_5 = 354, TP_Weapon_WEAPON_6 = 355, TP_Weapon_WEAPON_7 = 356, TP_Weapon_WEAPON_8 = 357, TP_Weapon_GLYPH_1 = 358,
    TP_Weapon_GLYPH_2 = 359, TP_Weapon_GLYPH_3 = 360, TP_Weapon_GLYPH_4 = 361, TP_Weapon_GLYPH_5 = 362, TP_Weapon_GLYPH_6 = 363, TP_Weapon_GLYPH_7 = 364, TP_Weapon_GLYPH_8 = 365, TP_Weapon_GLYPH_9 = 366, TP_Weapon_GLYPH_10 = 367,
    TP_Weapon_GLYPH_11 = 368, TP_Weapon_GLYPH_12 = 369, TP_Relic_LibrarianCard = 370, TP_Relic_BlackDisk = 371, TP_Relic_PileOfSecrets = 372, TP_Relic_CastleMap = 373, TP_Lisa_WineGlass = 374, TP_Shaft_Light = 375, TP_Elizabeth_Dark = 376,
    TP_Vincent_Spells = 377, TP_Mina_Shield = 378, TP_Albus_Confodere = 379, TP_Barlowe_Spite = 380, TP_Isaac_Mace = 381, TP_SaintGermain_Chauve = 382, TP_Julia_Energy = 383, TP_Sara_AlchemyWhip = 384, TP_Rinaldo_Flail = 385,
    TP_Quincy_PlatinumWhip = 386, TP_Maxim_HolyWhip = 387, TP_Nathan_SonicWhip = 388, TP_Henry_Slash = 389, TP_Cornell_Gun = 390, TP_Carrie_Custos = 391, TP_Selector_Candybox = 392, TP_Hyper_Castle = 393, TP_Selector_FamiliarForge = 394,
    TP_Relic_EbonyCrimsonStone = 395, FindAParmAegis = 396, FindManyChickens = 397, FindChickenClock = 398, Defeat0EnemiesInCoop = 399, EvolveOfGaea = 400, Dark_02Gazebo = 401, Dark_03Gazebo = 402, Banish80Items = 403,
    CompleteAdv_ToEndAnIceAge = 404, EvolveShawlOfGaea = 405, EME_FindEmeraldDisk = 406, EME_FindCoffin1 = 407, EME_GetRapierToLV6 = 408, EME_AllAttacksRapier = 409, EME_GetDualSwordsToLV6 = 410, EME_AllAttacksDualSwords = 411,
    EME_GetPunchToLV6 = 412, EME_AllAttacksPunch = 413, EME_GetKickToLV6 = 414, EME_AllAttacksKick = 415, EME_GetCannonToLV6 = 416, EME_AllAttacksCannon = 417, EME_GetPistolToLV6 = 418, EME_AllAttacksPistol = 419, EME_GetMechToLV6 = 420,
    EME_AllAttacksMech = 421, EME_GetKatanaToLV6 = 422, EME_AllAttacksKatana = 423, EME_GetSpiritRingToLV6 = 424, EME_EvolveMagic = 425, EME_FindCoffin2 = 426, EME_GetLongSwordToLV6 = 427, EME_AllAttacksLongSword = 428, EME_GetBloodToLV6 = 429,
    EME_AllAttacksBlood = 430, EME_AllAttacksSpear = 431, EME_AllAttacksGreatSword = 432, EME_AllAttacksAxe = 433, EME_AllAttacksKnife = 434, EME_DefeatBoss25m = 435, EME_DefeatBoss1Inverse = 436, EME_DefeatBoss2Inverse = 437,
    EME_DefeatBoss3Inverse = 438, EME_DefeatBoss4Inverse = 439, EME_DefeatBoss5Inverse = 440, EME_DefeatBoss6Inverse = 441, EME_MechSkinT = 442, EME_MechSkinM = 443, EME_MechDefeatAllBosses = 444, EME_MechDefeatAllBossesInverse = 445,
    EME_EvolveSecretWeapon = 446, FindManyClovers = 447, GetMagiStoneToLevel7 = 448, EvolveMagiStone = 449, Survive20minutesInWestwoods = 450, FindMasquerade = 451, Dark_13Chula = 452, DefeatShootingEnemies = 453, EvolveAmmoAppalate = 454,
    Dark_05Appunta = 455, ReachLV80InverseWarehouse = 456, FindChaosLazulia = 457, FindRecycle = 458, EvolveOfGaea_Fix = 459, FindKaromasMana = 460, Dark_18Challenge = 461, LEM_FindJokerDisc = 462, LEM_FindCoffin1 = 463, LEM_HighScore = 464,
    LEM_GetInfernolatroToLevel6 = 465, LEM_EvolveInfernolatro = 466, LEM_GetFibonacciToLevel6 = 467, LEM_EvolveFibonacci = 468, LEM_GetGrosMichelToLevel6 = 469, LEM_EvolveGrosMichel = 470, LEM_GetRichRocketToLevel6 = 471, LEM_EvolveRichRocket = 472,
    LEM_DefeatBoss = 473,
};
enum class SecretType : int
{
    none = 1665, CastThiefSpell = 0, UppercutReaper = 1, SpamSpamSpam = 2, UnderTheCoffin = 3, KissMe = 4, CheeseAccident = 5, BringMeBackThere = 6, BeAGoodBoy = 7, SlumsFlowers = 8, Master16 = 9, BossRashBoss = 10, KillThaReapa = 11,
    PureHeart = 12, RelaxEnjoyLife = 13, Honesty = 14, DotGoGreenAcres = 15, RottingPizza = 16, PeakGameDesign = 17, ExdashExOneViiq = 18, Tramezzini = 19, NonELaDonna = 20, VivaLaDonna = 21, SuperLaDonna = 22, StrongestCharacter = 23,
    Bioparco = 24, FaSchiuma = 25, Accidenti = 26, CrystalMakeUp = 27, YattaPanda = 28, Carramba = 29, Reset = 30, Languorino = 31, FettinePanate = 32, FoldInTheCheese = 33, IWillNeverLetYouForgetAboutMe = 34, LHoVistoIo = 35, PinoCiampino = 36,
    EArrivatoLArrotino = 37, HighFive = 38, SecondEvolution = 39, ABlasphemousMockery = 40, ThisShouldHaveBeenUnlockedByDefault = 41, ThisTooShouldHaveBeenUnlockedByDefault = 42, ThankElrond = 43, LeadMeToTheCheese = 44, TimeCompression = 45,
    EggsEggsEggs = 46, TeleportUsToMars = 47, Randomazzami = 48, IHaveSeenIt = 49, ICanHearTheCriesOfCaptainPlanet = 50, Spinnn = 51, Everything = 52, Everywhere = 53, IlMatto = 54, IlBagatto = 55, LaPapessa = 56, LImperatrice = 57,
    LImperatore = 58, IlPapa = 59, IlCarro = 60, LaForza = 61, LEremita = 62, LaRuota = 63, LaGiustizia = 64, LAppeso = 65, LaMorte = 66, LaTemperanza = 67, IlDiavolo = 68, LaTorre = 69, LaStella = 70, LaLuna = 71, IlSole = 72, IlGiudizio = 73,
    IlMondo = 74, FlyMeToTheMoon = 75, TheTwoAssassins = 76, Feldschlacht = 77, IFeelLoveVenus = 78, WaitReaction = 79, QuandoLoDiceLui = 80, ParadigmShift = 81, AllAtOnce = 82, MaybeImAStallion = 83, IGottaGetToTheEdgeOfSoul = 84, PopTheCorn = 85,
    IWantToSeeItAgain = 86, LostNumber = 87, EdgeOfTheWorld = 88, MaFaiPianooo = 89, KalVasFlam = 90, FreezeArrow = 91, DootDoot = 92, Festival = 93, Jupiter = 94, Mars = 95, HearTheThunder = 96, Halloween = 97, RecycleTheTower = 98,
    NotSureItsThunder = 99, ShounenHeroine = 100, YoungAtHeart = 101, ItsNotAnEclipse = 102, Vogue = 103, IonicoIonico = 104, Elamadonna = 105, TakeAShower = 106, CheVolano = 107, RecycleTheForest = 108, GottaGoFast = 109, TengilleSBalm = 110,
    SpellWhatever = 111, SpellSomething = 112, SpellWhichever = 113, AnimeIsMyPassion = 114, OopsIStoleOneAgain = 115, DeusExMachina = 116, BasicWitch = 117, TheWorldEater = 118, SoulOfTheParty = 119, HappyBirthday = 120, RecycleTheLibrary = 121,
    ColdWaterHotWater = 122, HaeralisPloy = 123, DuraisTruth = 124, ChapaTribe = 125, CygnusMagnus = 126, BuriedInTheSnow = 127, ToLoveToShine = 128, PrincessShadow = 129, RescueFromTheShadows = 130, RedIsSus = 131, ISawOrangeVent = 132,
    FoundYellowInMedical = 133, GreenIsRedYouIsMe = 134, FoundBlueInStorage = 135, YouAreTheImpostor = 136, SciencePink = 137, SelfReport = 138, HaaayImpasta = 139, BimBumBam = 140, LugriansTale = 141, TheGoodGuy = 142, JumpTheShark = 143,
    RunAndRizer = 144, BeanMachineGun = 145, AlwaysArmedNeverShaved = 146, MetallicBakedGoods = 147, AmITheOriginal = 148, RDOOEight = 149, BattlefieldFlower = 150, MoreThanAMechSuit = 151, ProtectorOfGaluga = 152, BadBetrayerBahamut = 153,
    ChiefSalamander = 154, HonouringMasato = 155, HardCorpsHighSpeed = 156, WinCarloCart = 157, BlunderingFool = 158, SheSawIt = 159, DivineAssault = 160, TheNextStopIs = 161, ApritiSedano = 162, WhyDItHaveToBeBats = 163, GetRingOfRings = 164,
    ForbiddenBox = 165, UnblindImelda = 166, RetirePoe = 167, StarPupil = 168, Darkassami = 169, ottaMlI = 170, ottagaBlI = 171, assepaPaL = 172, ecirtarepmIL = 173, erotarepmIL = 174, apaPlI = 175, orraClI = 176, azroFaL = 177, atimerEL = 178,
    atouRaL = 179, aizitsuiGaL = 180, oseppAL = 181, etroMaL = 182, aznarepmeTaL = 183, olovaiDlI = 184, erroTaL = 185, alletSaL = 186, anuLaL = 187, eloSlI = 188, oiziduiGlI = 189, odnoMlI = 190, tp_stella = 191, tp_loretta = 192,
    tp_galamoth = 194, tp_chaos = 195, tp_clocktower = 196, tp_death = 197, tp_arsenal = 198, tp_malphas = 199, tp_sniper = 200, tp_axearmor = 201, tp_familiar = 202, tp_innocent = 203, tp_mariab = 204, tp_jandc = 205, tp_candj = 206,
    tp_sandl = 207, tp_lands = 208, tp_librarian = 209, tp_hammer = 210, tp_cavetroll = 211, tp_olrox = 212, tp_soleil = 213, tp_elizabethmega = 214, tp_bluecornell = 215, tp_fleaman = 216, tp_frozenshade = 217, tp_joachim = 218, tp_carmilla = 219,
    tp_wind = 220, tp_succubus = 221, tp_walter = 222, tp_brauner = 223, tp_graham = 224, tp_deathmega = 225, tp_dario = 226, tp_dmitri = 227, tp_celia = 228, tp_ferryman = 229, tp_blackmore = 230, tp_draculamega = 231, tp_olroxmega = 232,
    tp_keremet = 233, AdrianFahrenheit = 234, NotAChild = 235, LeCardigan = 236, ActuallyQuiteNice = 237, DeckBrush = 238, MorissSon = 239, BeefBBQ = 240, OmniaVanitas = 241, FatefulFusion = 242, LamentedGenesis = 243, HolyGlasses = 244,
    DoesntHaveUno = 245, MorningSun = 246, PeterDante = 247, TechnicallyNotAVampire = 248, LegendMother = 249, BlueCipher = 250, WallChickenEnjoyer = 251, NotASuccubus = 252, FirstToDoItTwice = 253, ShoutLoud = 254, CandleBane = 255,
    KitchenSink = 256, BelnadesBookworm = 257, WordsThatStartWithS = 258, BlackrockScroll = 259, EntityOfChaos = 260, HorseDoor = 261, HeadsOrTails = 262, WalkIntoTheMirror = 263, KingOfTheFlies = 264, PieceOfTime = 265, BeastlyBowels = 266,
    DisobeyAlucard = 267, ReadersPartita = 268, BigBrother = 269, PolygonalBelnades = 270, EmeryBoard = 271, NotInThisGame = 272, TheLizardQueen = 273, SilverBullet = 274, GuiltyDevil = 275, BotheredByBrother = 276, CardSharp = 277,
    UpstartWeakling = 278, TimeOrRatherFate = 279, BondedSoul = 280, AlchemistsLament = 281, EnshrinedHeart = 282, NonPlayerCharacter = 283, StellarFan = 284, Mourned = 285, NoFreebies = 286, PitiableMadman = 287, VladsBiggestFan = 288,
    IsThisWhatAManIs = 289, BecomeAnVampiyre = 290, YourFaultForBeingSoMean = 291, hehhehheh = 292, RockingChair = 293, WhatWouldYouSpendItOn = 294, NoSpoilers = 295, Twinnado = 296, CoolTwin = 297, EveryonesACritic = 298, ProdigalSon = 299,
    AguniInAgony = 300, MenacingHaircut = 301, WithLight = 302, UmbralEclipse = 303, CantHoldThemAll = 304, WeepingMask = 305, DontDisturbDinner = 306, Chupacabra = 307, FinalBoss = 308, MissAxalotl = 309, ColdShoulder = 310, ThatsNotLisa = 311,
    CauldronKing = 312, GothAngel = 313, BizarreShadeAdventure = 314, Karasuman = 315, SewardZead = 316, SizeMatters = 317, PetrifyinglyEvil = 318, TheOtherCount = 319, EmbraceTheReaper = 320, MathiasCronqvist = 321,
    IIIIIIIVVVIVIIVIIIIXXXIXIIXIIIXIVXVXVIXVIIXVIIIXIXXXXXI = 322, GreatUseOfTime = 323, DraculasDungeon = 324, ForgemasterFriends = 325, Friendlevania = 326, AzureCroissant = 327, ItsAllHisFault = 328, LoudShout = 329, LoveKnowsNoBounds = 330,
    BreakSpaceBounds = 331, SkipOneDay = 332, CoopWhen = 333, YeOldeShoppe = 334, DeerHeadlights = 335, AllegedCannibal = 336, CheFaccioLascio = 337, RebirdShemoon = 338, _cheat_EME_EMERALDDISK = 339, _cheat_EME_RAPIERDUAL = 340,
    _cheat_EME_MAGICALL = 341, _cheat_EME_PUNCHKICK = 342, _cheat_EME_CANNONGUN = 343, _cheat_EME_MECHKATANA = 344, _cheat_EME_SWORDBITE = 345, _cheat_EME_MRS = 346, _cheat_EME_EXGREATSWORD = 347, _cheat_EME_EXKNIFE = 348, _cheat_EME_EXAXE = 349,
    _cheat_EME_EXSPEAR = 350, _cheat_EME_PUPALL = 351, _cheat_EME_CATS = 352, _cheat_EME_DEMON = 353, _cheat_EME_IMAKOO = 354, _cheat_EME_WAVE = 355, EME_CATS = 356, EME_DEMON = 357, EME_IMAKOO = 358, EME_KINA = 359,
    _cheat_EME_MECHKATANA_virginia = 360, _cheat_EME_MECHKATANA_skins = 361, RecycleThePlant = 370, ReReRecycle = 371, ShoppingCartTheory = 372, OneBranchBandit = 373, Malcomtent = 374, FrozenButler = 375, AreFriendsElectric = 376,
    WanderingColossus = 377, SilentLaugh = 378, BreakMazerellaWall = 379, WestwoodsPreorder = 380, differenttypeofstake = 400, forkliftcertified = 401, knockknock = 402, butdoctoriamcanio = 403, doublenegative = 404, bloodisthicker = 405,
    enviousblade = 406, vaccuumproserpina = 407, nomancandefy = 408, skelenun = 409, aljibarian = 410, odakira = 411, hophophophophophophophophophophophophop = 412, rulersword = 413, inadvertentresurrector = 414, dampmage = 415,
    gemstonelegacy = 416, abouttimeyoushowedup = 417, ismycontrollerbroken = 418, theysmelldifferent = 419, platonicpartners = 420,
};
enum class AdventureAchievementType : int
{
    MS001_ACH001 = 0, MS001_ACH002 = 1, MS001_ACH003 = 2, MS001_ACH004 = 3, MS001_ACH005 = 4, MS001_ACH006 = 5, MS001_ACH007 = 6, MS001_ACH008 = 7, MS001_ACH009 = 8, MS001_ACH010 = 9, MS001_ACH011 = 10, MS001_ACH012 = 11, MS001_ACH013 = 12,
    MS001_ACH014 = 13, POES_ACH001 = 14, POES_ACH002 = 15, POES_ACH003 = 16, POES_ACH004 = 17, POES_ACH005 = 18, POES_ACH006 = 19, POES_ACH007 = 20, POES_ACH008 = 21, POES_ACH009 = 22, POES_ACH010 = 23, POES_ACH011 = 24, POES_ACH012 = 25,
    POES_ACH013 = 26, POES_ACH014 = 27, IMEL_ACH001 = 28, IMEL_ACH002 = 29, IMEL_ACH003 = 30, IMEL_ACH004 = 31, IMEL_ACH005 = 32, IMEL_ACH006 = 33, IMEL_ACH007 = 34, IMEL_ACH008 = 35, IMEL_ACH009 = 36, IMEL_ACH010 = 37, IMEL_ACH011 = 38,
    IMEL_ACH012 = 39, IMEL_ACH013 = 40, IMEL_ACH014 = 41, IMEL_ACH015 = 42, IMEL_ACH016 = 43, IMEL_ACH017 = 44, TEST001_ACH001 = 45, CHAL_ACH001 = 46, CHAL_ACH002 = 47, CHAL_ACH003 = 48, CHAL_ACH004 = 49, CHAL_ACH005 = 50, CHAL_ACH006 = 51,
    CHAL_ACH007 = 52, CHAL_ACH008 = 53, CHAL_ACH009 = 54, CHAL_ACH010 = 55, CHAL_ACH011 = 56, CHAL_ACH012 = 57, CHAL_ACH013 = 58, CHAL_ACH014 = 59, CHAL_ACH015 = 60, CHAL_ACH016 = 61, CHAL_ACH017 = 62, CHAL_ACH018 = 63, CHAL_ACH019 = 64,
    FB_ACH001 = 65, FB_ACH002 = 66, FB_ACH003 = 67, FB_ACH004 = 68, FB_ACH005 = 69, FB_ACH006 = 70, FB_ACH007 = 71, FB_ACH008 = 72, FB_ACH009 = 73, FB_ACH010 = 74, FB_ACH011 = 75, FB_ACH012 = 76, FB_ACH013 = 77, FB_ACH014 = 78, FB_ACH015 = 79,
    FB_ACH016 = 80, FB_ACH017 = 81, FB_ACH018 = 82, FB_ACH019 = 83, FB_ACH020 = 84, FB_ACH021 = 85, FB_ACH022 = 86, FB_ACH023 = 87, FB_ACH024 = 88, FB_ACH025 = 89, FB_ACH026 = 90, FB_ACH027 = 91, FB_ACH028 = 92, SHEMOON_ACH001 = 93,
    SHEMOON_ACH002 = 94, SHEMOON_ACH003 = 95, SHEMOON_ACH004 = 96, SHEMOON_ACH005 = 97, SHEMOON_ACH006 = 98, SHEMOON_ACH007 = 99, SHEMOON_ACH008 = 100, SHEMOON_ACH009 = 101, SHEMOON_ACH010 = 102, SHEMOON_ACH011 = 103, SHEMOON_ACH012 = 104,
    SHEMOON_ACH013 = 105, SHEMOON_ACH014 = 106, SHEMOON_ACH015 = 107, FS001_ACH001 = 108, FS001_ACH002 = 109, FS001_ACH003 = 110, FS001_ACH004 = 111, FS001_ACH005 = 112, FS001_ACH006 = 113, FS001_ACH007 = 114, FS001_ACH008 = 115,
    FS001_ACH009 = 116, FS001_ACH010 = 117, FS001_ACH011 = 118, FS001_ACH012 = 119, FS001_ACH013 = 120, FS001_ACH014 = 121, OTC_001_ACH001 = 122, OTC_001_ACH002 = 123, OTC_001_ACH003 = 124, OTC_001_ACH004 = 125, OTC_001_ACH005 = 126,
    OTC_001_ACH006 = 127, OTC_001_ACH007 = 128, OTC_001_ACH008 = 129, OTC_001_ACH009 = 130, OTC_001_ACH010 = 131, OTC_001_ACH011 = 132, OTC_001_ACH012 = 133, OTC_001_ACH013 = 134, OTC_001_ACH014 = 135, OTC_001_ACH015 = 136,
    OTC_001_ACH016 = 137, OTC_001_ACH017 = 138, OTC_001_ACH018 = 139, OTC_001_ACH019 = 140, OTC_001_ACH020 = 141, OTC_001_ACH021 = 142, OTC_001_ACH022 = 143, OTC_001_ACH023 = 144, OTC_001_ACH024 = 145, OTC_001_ACH025 = 146,
    OTC_001_ACH026 = 147, OTC_001_ACH027 = 148, OTC_001_ACH028 = 149, OTC_001_ACH029 = 150, OTC_001_ACH030 = 151, OTC_001_ACH031 = 152, OTC_001_ACH032 = 153, OTC_001_ACH033 = 154, OTC_001_ACH034 = 155, OTC_001_ACH035 = 156,
    OTC_001_ACH036 = 157, OTC_001_ACH037 = 158, OTC_001_ACH038 = 159, OTC_001_ACH039 = 160, OTC_001_ACH040 = 161, OTC_001_ACH041 = 162, OTC_001_ACH042 = 163, OTC_001_ACH043 = 164, OTC_001_ACH044 = 165, OTC_001_ACH045 = 166,
    OTC_001_ACH046 = 167, OTC_001_ACH047 = 168, OTC_001_ACH048 = 169, OTC_001_ACH049 = 170, OTC_001_ACH050 = 171, OTC_001_ACH051 = 172, OTC_001_ACH052 = 173, OTC_001_ACH053 = 174, OTC_001_ACH054 = 175, OTC_001_ACH055 = 176,
    OTC_001_ACH056 = 177, OTC_001_ACH057 = 178, OTC_001_ACH058 = 179, OTC_001_ACH059 = 180, OTC_001_ACH060 = 181, OTC_001_ACH061 = 182, OTC_001_ACH062 = 183, OTC_001_ACH063 = 184, OTC_001_ACH064 = 185, OTC_001_ACH065 = 186,
    OTC_001_ACH066 = 187, OTC_001_ACH067 = 188, OTC_001_ACH068 = 189, OTC_001_ACH069 = 190, OTC_001_ACH070 = 191, OTC_001_ACH071 = 192, OTC_001_ACH072 = 193, OTC_001_ACH073 = 194, OTC_001_ACH074 = 195, OTC_001_ACH075 = 196,
    OTC_001_ACH076 = 197, OTC_001_ACH077 = 198, OTC_001_ACH078 = 199, OTC_001_ACH079 = 200, OTC_001_ACH080 = 201, OTC_001_ACH081 = 202,
};
enum class AdventureType : int
{
    ADV_LMS_001 = 0, ADV_POES_001 = 1, ADV_LIB_001 = 2, ADV_IMEL_001 = 3, ADV_EMER_001 = 4, ADV_FBLOOD_001 = 5, ADV_SHEMOON_001 = 6, ADV_TIDES_001 = 7, ADV_OTC_001 = 8,
};
enum class SkinType : int
{
    DEFAULT = 0, LEGACY = 1, DEFAULT2 = 2, EMPTY = 3, HALLOWS = 4, XMAS = 5, ADVENTURE1 = 6, CROCI_NOCROSS = 7, FINO_DARK = 8, FINO_EYE = 9, C1_HORSE_PINK = 10, C1_HORSE_PURPLE = 11, C1_HORSE_BLUE = 12, C1_HORSE_GREEN = 13, C1_HORSE_YELLOW = 14,
    C1_HORSE_ORANGE = 15, C1_HORSE_RED = 16, C1_HORSE_RAINBOW = 17, POE_TEST = 18, SKIN_DUALSWORDSMAN = 20, SKIN_EME_KOM = 21, SKIN_EME_BOH = 22, SKIN_EME_SUK = 23, SKIN_EME_B_KICK = 24, SKIN_EME_F_PISTOL = 25, SKIN_EME_D_KATANA = 26,
    SKIN_EME_D_TANK = 27, SKIN_EME_S_BLOOD = 30, SKIN_EME_MUS = 31, SKIN_EME_SOLO_FLEURET = 32, SKIN_EME_SOLO_DUAL = 33, SKIN_EME_SOLO_PUNCH = 34, SKIN_EME_SOLO_KICK = 35, SKIN_EME_SOLO_CANNON = 36, SKIN_EME_SOLO_PISTOL = 37, SKIN_EME_D_PARA = 38,
    SKIN_EME_D_MOVE = 39, SKIN_EME_D_SHAN = 40, SKIN_EME_SELECT = 41, SKIN_EME_D_RETRO = 42, SKIN_ELEANOR_AREA = 99, SKIN_ELEANOR_MIGHT = 100, SKIN_IMELDA_UNBLINDED = 101, SKIN_POE_RETIRED = 108, SKIN_SHEMOON_REBORN = 142,
    SKIN_TP_CHARLOTTE_2 = 1000, SKIN_TP_SOMA_2 = 1001, SKIN_TP_JONHATHAN_MORNINGSTAR = 1002, SKIN_TP_JONHATHAN_COATOFARMS = 1003, SKIN_TP_JONHATHAN_SPECTRALSWORD = 1004, SKIN_TP_CORNELL_B = 1005, SKIN_TP_LEON_MORNINGSTAR = 1006,
    SKIN_TP_SONIA_MORNINGSTAR = 1007, SKIN_TP_TREVOR_MORNINGSTAR = 1008, SKIN_TP_CHRISTOPHER_MORNINGSTAR = 1009, SKIN_TP_SIMON_MORNINGSTAR = 1010, SKIN_TP_JUSTE_MORNINGSTAR = 1011, SKIN_TP_RICHTER_MORNINGSTAR = 1012,
    SKIN_TP_JULIUS_MORNINGSTAR = 1013, SKIN_TP_JUSTE_SPELLBOOK = 1014, SKIN_TP_SHANOA_2 = 1015, SKIN_TP_SYPHA_2 = 1016, SKIN_TP_JULIA_2 = 1017, SKIN_TP_CARRIE_2 = 1018, SKIN_TP_YOKO_2 = 1019, SKIN_TP_RINALDO_2 = 1020, SKIN_TP_MINA_2 = 1021,
    SKIN_TP_ELIZABETH_2SB = 1022, SKIN_TP_ELIZABETH_3DB = 1023, SKIN_TP_ALUCARD_2 = 1024, SKIN_TP_ALUCARD_3 = 1025, SKIN_TP_ALUCARD_4 = 1026, SKIN_TP_REINHARDT_2SW = 1027, SKIN_TP_REINHARDT_3CA = 1028, SKIN_TP_ISAAC_2SW = 1029,
    SKIN_TP_ISAAC_3DB = 1030, SKIN_TP_ERIC_2SW = 1031, SKIN_TP_ERIC_3CA = 1032, SKIN_TP_MARIA_2SW = 1033, SKIN_TP_MARIA_3SB = 1034, SKIN_TP_MARIA_4SW = 1035, SKIN_TP_MARIA_5SB = 1036, SKIN_TP_VINCENT_2CA = 1037, SKIN_TP_HECTOR_2SW = 1038,
    SKIN_TP_HECTOR_3CA = 1039, SKIN_TP_SARA_2SB = 1040, SKIN_TP_JOHN_2CA = 1041, SKIN_TP_JOHN_3MS = 1042, SKIN_TP_GRANT_2CA = 1043, SKIN_TP_QUINCY_2CA = 1044, SKIN_TP_HENRY_2CA = 1045, SKIN_TP_MAXIM_2CA = 1046, SKIN_TP_DRACULA_2DB = 1047,
    SKIN_TP_LISA_2SB = 1048, SKIN_TP_SHAFT_2DB = 1049, SKIN_TP_ALBUS_2DB = 1050, SKIN_TP_STGERMAIN_2DB = 1051, SKIN_TP_STGERMAIN_2SW = 1052, SKIN_TP_NATHAN_2MS = 1053, SKIN_TP_NATHAN_2SB = 1054, SKIN_TP_CORNELL_2 = 1055, SKIN_TP_CORNELL_2DB = 1056,
    SKIN_TP_BARLOWE_2 = 1057, SKIN_TP_BARLOWE_3DB = 1058, SKIN_TP_BARLOWE_4SB = 1059, SKIN_TP_ID_2 = 1060, SKIN_TP_ID_3 = 1061, SKIN_TP_ID_4 = 1062, SKIN_TP_ID_5 = 1063, SKIN_TP_ID_6 = 1064, SKIN_TP_FAM_1 = 1065, SKIN_TP_FAM_2 = 1066,
    SKIN_TP_FAM_3 = 1067, SKIN_TP_FAM_4 = 1068, SKIN_TP_ELIZABETH_MED_SB = 1070, SKIN_TP_ELIZABETH_MED_DB = 1071, SKIN_TP_OLROX_MED_DB = 1072, SKIN_TP_DEATH_MED_DB = 1073, SKIN_TP_DRACULA_MED_DOM = 1074, SKIN_TP_DRACULA_MED_DB = 1075,
    SKIN_TP_REINHARDT_4MS = 1076, SKIN_TP_SIMON_CHRONICLES = 1077, SKIN_TP_SOMA_DARKLORD = 1078, SKIN_TP_STONESKULL_BULL = 1079, SKIN_TP_ANNETTE_PENDULUM = 1080, SKIN_TP_ANNETTE_ELEVATOR = 1081, SKIN_TP_ANNETTE_HEADS = 1082,
    SKIN_TP_GAIBON_AND_SLOGRA = 1083, SKIN_TP_SLOGRA_AND_GAIBON = 1084, SKIN_TP_FAKE_TRIO_SYPHA = 1085, SKIN_TP_FAKE_TRIO_GRANT = 1086, SKIN_TP_MORRIS_COATOFARMS = 1087, SKIN_TP_ZEPHYR_BWAKA = 1088,
};
enum class ArcanaType : int
{
    NONE = -1, T00_KILLER = 0, T01_AQUARIUS = 1, T02_TWILIGHT = 2, T03_TRAGIC = 3, T04_AWAKE = 4, T05_CRASH = 5, T06_SARABANDE = 6, T07_IRON_BLUE = 7, T08_MAD_FOREST = 8, T09_DIVINE = 9, T10_BEGINNING = 10, T11_PEARLS = 11, T12_OUT_OF_TIME = 12,
    T13_WICKED = 13, T14_JEWELS = 14, T15_GOLD = 15, T16_SLASH = 16, T17_PAINTING = 17, T18_ILLUSIONS = 18, T19_FIRE = 19, T20_SINKING = 20, T21_BLOODY = 21, D00_STAKE_TO_YOUR_HEART = 22, D01_SAPPHIRE_MIST = 23, D02_EMERALD_ELEGY = 24,
    D03_BREAD_ANATHEMA = 25, D04_TOWERING_DOLL = 26, D05_PALE_DIAMOND = 27, D06_BOLERO = 28, D07_tbd_bouncy = 29, D08_EDGE_OF_THE_EARTH = 30, D09_HEIR_OF_FATE = 31, D10_FROM_THE_FUTURE = 32, D11_HIDDEN_IN_SMOKE = 33, D12_CRYSTAL_CRIES = 34,
    D13_MAD_MOON = 35, D14_JAWS_SCORCHED_SKY = 36, D15_EVERYTHING_TO_LOSE = 37, D16_TINKER_PARTITA = 38, D17_SIGN_OF_BLOOD = 39, D18_VICTORIAN_HORROR = 40, D19_RIPPING_SILENCE = 41, D20_FANTASIA = 42, D21_JETBLACK = 43, B001_ANTONIO = 101,
    B002_IMELDA = 102, B003_PASQUALINA = 103, B004_GENNARO = 104, B005_ARCA = 105, B006_PORTA = 106, B007_LAMA = 107, B008_POE = 108, B009_CLERICI = 109, B010_DOMMARIO = 110, B011_KROCHI = 111, B012_CHRISTINE = 112, B013_PUGNALA = 113,
    B014_GIOVANNA = 114, B015_POPPEA = 115, B016_CONCETTA = 116, B017_MORTACCIO = 117, B018_CAVALLO = 118, B019_RAMBA = 119, B020_OSOLE = 120, B021_AMBROJOE = 121, B022_GALLO = 122, B023_DIVANO = 123, B024_ZIASSUNTA = 124,
    SUB_ADDWEAPON_BONE2 = 1000, SUB_ADDWEAPON_CART2EVO = 1001, SUB_ADDWEAPON_CHERRY2 = 1002, SUB_ADDWEAPON_FLOWER2 = 1003, SUB_XLEVEL_MAXHP5 = 1100, SUB_XLEVEL_GROWTH1 = 1101, SUB_XLEVEL_MIGHT1 = 1102, SUB_XLEVEL_SPEED1 = 1103,
    SUB_XLEVEL_DURATION1 = 1104, SUB_XLEVEL_AREA1 = 1105, SUB_XLEVEL_SKIP1 = 1106, SUB_XLEVEL_REROLL1 = 1107, SUB_XLEVEL_BANISH1 = 1108, SUB_SKIP_COOLDOWNDOWN = 1200, SUB_SKIP_FULLRECOVERHP = 1201, SUB_SKIP_ROSARY = 1202, SUB_SKIP_TIMEFREEZE = 1203,
    SUB_ONREVIVE_ROSARY = 2000, SUB_ONREVIVE_VACUUM = 2001, SUB_ONREVIVE_RAPIDFIRE = 2002, SUB_ONREVIVE_TIMEFREEZE = 2003, SUB_ONREVIVE_CURSEDOWN = 2004, SUB_ONREVIVE_TIMESKIP = 2005, SUB_ONDAMAGED_ARMORUP = 3000, SUB_ONDAMAGED_RECOVERYUP = 3001,
    SUB_ONDAMAGED_ADDCOINS = 3002, SUB_ONDAMAGED_GROUNDHIT = 3003, SUB_PASSIVE_CRITICALUP = 4000, SUB_PASSIVE_GUARDIANAURA = 4001, SUB_PASSIVE_DEFANGUP = 4002, SUB_PASSIVE_CHARMUP = 4003, SUB_PASSIVE_DISABLE = 4004,
    SUB_ENEMIESCOUNT_ADDREVIVES = 5000, SUB_ENEMIESCOUNT_ADDAMOUNT = 5001, SUB_ENEMIESCOUNT_ADDARMOR = 5002, SUB_ENEMIESCOUNT_ADDCOINS = 5003, SUB_ENEMIESCOUNT_GOLDFEVER = 5004, SUB_HPCRITICAL_RECOVERHP = 6000, SUB_HPCRITICAL_FIREBREATH = 6001,
    SUB_HPCRITICAL_MAXARMOR = 6002, SUB_OVERHEAL_ICEBREATH = 7000, SUB_OVERHEAL_MIGHTUP = 7001, SUB_OVERHEAL_FEVERUP = 7002, SUB_OVERHEAL_REROLLUP = 7003, SUB_GOLDCOUNT_LIGHTSOURCES = 8000, SUB_GOLDCOUNT_THORNSUP = 8001,
    SUB_GOLCOUNT_ADDREVIVES = 8002, SUB_GOLDCOUNT_ADDPASSIVESLOTS = 8003, SUB_FAMILIAR_BROWNIE = 9000,
};
enum class MaterialType : int
{
    Particles = 0, ParticlesAdditive = 1, Trail = 2, TrailAdditive = 3, Vfx = 4, Character = 5, Blitter = 6, BlitterAdditive = 7, DefaultSprite = 8, Pentagram = 9, ScrollableSprite = 10,
    ScrollableSpriteAdditive = 11, ScrollableSpriteLit = 12, Inversion = 13, Galaxy = 14, FourCornerTintAdditive = 15, FourCornerTint = 16, Video = 17, VfxScreen = 18, VfxNormal = 19,
    DefaultSpriteVariableTintFill = 20, DefaultSpriteLit = 21, DefaultSpriteTintHue = 22, ColourReplacement = 23, ScrollPerspective = 24,
};
enum class SpawnType : int
{
    STANDARD = 0, HORIZONTAL = 1, VERTICAL = 2, SCRIPTED = 3, TILED = 4, MAPPED = 5, HORIZONTAL_SMOOTHED = 6,
};
enum class CollectionsPageFilterType : int
{
    DEFAULT = 0,
    BY_TYPE = 1,
    BY_VERSION = 2,
    ADVENTURE = 3,
};
enum class BorderType : int
{
    SOLID = 0,
    _TRANSPARENT = 1,
};
enum class SystemPlatformTypes : int
{
    ANDROID = 0,
    IOS = 1,
    PS4 = 2,
    PS5 = 3,
    STANDALONE = 4,
    STEAM = 5,
    SWITCH = 6,
    XBOX = 7,
    EPIC_GAMES = 8,
};
enum class BgmModType : int
{
    Normal = 0,
    Hyper = 1,
    Forsaken = 2,
};
enum class BgmPlaybackType : int
{
    Lock_Selected = 0,
    Shuffle = 1,
    Play_All = 2,
    None = 3,
};
enum class AlbumType : int
{
    VampireSurvivorsA = 0,
    VampireSurvivorsB = 1,
    VampireSurvivorsC = 2,
    LegacyOfTheMoonspell = 3,
    TidesOfTheFoscari = 4,
    HOTI = 5,
    EmergencyMeeting = 6,
    OperationGuns = 7,
    OdeToCastlevaniaA = 8,
    OdeToCastlevaniaB = 9,
    EmeraldDiorama = 10,
    Lemon = 11,
};
enum class PowerUpType : int
{
    POWER = 0, REGEN = 1, MAXHEALTH = 2, ARMOR = 3, AREA = 4, SPEED = 5, COOLDOWN = 6, DURATION = 7, AMOUNT = 8, MOVESPEED = 9, MAGNET = 10, LUCK = 11, GROWTH = 12,
    GREED = 13, CURSE = 14, TIME = 15, SHIELD = 16, REVIVAL = 17, LEVELUP = 18, INVUL = 19, REROLL = 20, SKIP = 21, BANISH = 22, PANDORA = 23, SEAL = 24, CHARM = 25,
    SEAL2 = 26, DEFANG = 27, SEAL3 = 28, SEAL4 = 29, RECYCLE = 30,
};
enum class VisibleJoystickType : int
{
    Legacy = 0,
    Default = 1,
};
enum class ContentGroupType : int
{
    BASE = 0, EXTRA = 1, MOONSPELL = 2, FOSCARI = 3, CHALCEDONY = 4, FIRST_BLOOD = 5, EMERALDS = 6, THOSE_PEOPLE = 7, LEMON = 8,
};
enum class PropType : int
{
    CANDLE = 0, CANDELABRA = 1, BRAZIER = 2, BRAZIER2 = 3, LAMPOST = 4, CART = 5, WINDOW = 6, LANTERN = 7, FOSCARI_SEAL_1 = 8, FOSCARI_SEAL_2 = 9, FOSCARI_SEAL_3 = 10, LANTERN_INVERSE = 11,
    WEATHERNODE = 12, TRAINLEVER = 13, LABORATORYLEVER2 = 14, LABORATORYLEVER3 = 15, LABORATORYLEVER4 = 16, LAB_DOOR_A = 17, LAB_DOOR_B = 18, LAMPOST_SINGLE = 19, EX_TOHILSTATUE = 20,
    FB_CAPSULE = 101, FB_EXPLOCAR = 102, FB_EXPLOBARREL = 103, TP_DOOR = 104,
};
enum class HitVfxType : int
{
    None = 0, Default = 1, TimeFreeze = 2, Fire = 3, Dark = 4, Light = 5, Push = 6, Prism = 7, Red = 8, Blue = 9, Beam = 10, Evil = 11, Wind = 12, Explo = 13, Yellow = 14, Water = 15, Count = 16,
};
enum class AIType : int
{
    None = 0, Aggressive = 1, Defensive = 2, ChaoticAF = 3, MirrorInput = 4, DelayedInputCopy = 5, DelayedPositionCopy = 6, GreedyForPickups = 7, StandsStill = 8, Masochistic = 9,
    AlwaysRight = 10, AngleDistance = 11, DeathSequence = 12, AngleDistanceMirrorInput = 13, Conga = 14,
};
enum class PrizeType : int
{
    POWERUP = 0, EXISTING_WEAPON = 1, EXISTING_ANY = 2, FILLER = 3, RANDOM = 4, FIXED = 5, EVOLUTION = 6, EVO_ARCANA = 7, NEW_WEAPON = 8, SURVAROT = 9,
};
enum class DlcType : int
{
    Moonspell = 0, Foscari = 1, Chalcedony = 2, FirstBlood = 3, Emeralds = 4, ThosePeople = 5, Lemon = 6,
};
enum class CharacterRandomGeneratorStat : int
{
    Amount = 0, Area = 1, Armor = 2, Cooldown = 3, Banish = 4, Charm = 5, Curse = 6, Defang = 7, Duration = 8, Fever = 9, Greed = 10, Growth = 11, InvulTimeBonus = 12, Luck = 13,
    Magnet = 14, MaxHp = 15, MoveSpeed = 16, Power = 17, Recycle = 18, Regen = 19, ReRolls = 20, Revivals = 21, Shroud = 22, Skips = 23, Speed = 24,
};
enum class PickupMode : int
{
    Normal = 0, GemsAndCoinsOnly = 1, GemsCoinsRoasts = 2, GemsCoinsRoastsSouls = 3, IgnoreAll = 4,
};