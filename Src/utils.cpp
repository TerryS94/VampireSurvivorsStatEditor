#include "pch.h"
#include "utils.h"

namespace ImGui
{
    bool IsItemHoveredDelay(float delay_in_seconds)
    {
        ImGuiContext* context = ImGui::GetCurrentContext();
        return ImGui::IsItemHovered() && !context->IO.MouseDown[0] && context->HoveredIdTimer > delay_in_seconds;
    }
};
namespace utils
{
    BYTE FloatToByte(float f)
    {
        if (f <= 0.0f) return 0;
        if (f >= 1.0f) return 255;
        return static_cast<BYTE>(f * 255.0f + 0.5f);
    }
	std::string ToLowercase(const std::string& input)
	{
		std::string result = input;
		for (char& c : result)
		{
			unsigned char uc = static_cast<unsigned char>(c);
			if (std::isalpha(uc))
				c = static_cast<char>(std::tolower(uc));
		}
		return result;
	}
	std::string ToUppercase(const std::string& input)
	{
		std::string result = input;
		for (char& c : result)
		{
			unsigned char uc = static_cast<unsigned char>(c);
			if (std::isalpha(uc))
				c = static_cast<char>(std::toupper(uc));
		}
		return result;
	}
	bool isStringEmptyOrWhitespaceOnly(const std::string& str)
	{
		return str.empty() ||
			std::all_of(str.begin(), str.end(), [](unsigned char ch) {
				return std::isspace(ch);
			});
	}
	void ImToolTipWithTextWrap(const char* str)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
		ImGui::BeginTooltip();
		const ImGuiStyle& style = ImGui::GetStyle();
		const float paddingX = style.WindowPadding.x;
		ImGui::PushTextWrapPos(rendering::windowSize.x - paddingX);
		ImGui::TextUnformatted(str);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
		ImGui::PopStyleVar();
	}
    ImVec4 Lerp(const ImVec4& a, const ImVec4& b, float t)
    {
        if (t < 0.0f) t = 0.0f;
        if (t > 1.0f) t = 1.0f;
        return ImVec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
    }
    ImVec4 Mul(const ImVec4& c, float m, float alpha)
    {
        ImVec4 out;
        out.x = c.x * m;
        out.y = c.y * m;
        out.z = c.z * m;
        out.w = (alpha < 0.0f) ? c.w : alpha;
        out.x = out.x < 0.0f ? 0.0f : (out.x > 1.0f ? 1.0f : out.x);
        out.y = out.y < 0.0f ? 0.0f : (out.y > 1.0f ? 1.0f : out.y);
        out.z = out.z < 0.0f ? 0.0f : (out.z > 1.0f ? 1.0f : out.z);
        out.w = out.w < 0.0f ? 0.0f : (out.w > 1.0f ? 1.0f : out.w);
        return out;
    }
	std::string getTimeNow()
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		char buffer[100];
		int result = GetTimeFormatA(LOCALE_USER_DEFAULT, 0, &st, "hh':'mm tt", buffer, sizeof(buffer));
		if (result > 0) return std::string(buffer);
		return "";
	}
	std::string getDateNow()
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		char buffer[100];
		int result = GetDateFormatA(LOCALE_USER_DEFAULT, 0, &st, "MM'-'dd'-'yy", buffer, sizeof(buffer));
		if (result > 0) return std::string(buffer);
		return "";
	}
    std::string ItemTypeToString(ItemType itemType)
    {
        using enum ItemType;
        switch (itemType)
        {
        case NONE: return "VOID";case WHIP: return "WHIP";case COIN: return "COIN";case COINBAG1: return "COINBAG1";case COINBAG2: return "COINBAG2";case COINBAGMAX: return "COINBAGMAX";
        case GEM: return "GEM";case CLOVER: return "CLOVER";case TREASURE: return "TREASURE";case ROSARY: return "ROSARY";case VACUUM: return "VACUUM";case OROLOGION: return "OROLOGION";
        case ROAST: return "ROAST";case WEAPON: return "WEAPON";case STATS_TREASURE_1: return "STATS_TREASURE_1";case STATS_TREASURE_2: return "STATS_TREASURE_2";case STATS_TREASURE_3: return "STATS_TREASURE_3";
        case NFT: return "NFT";case LITTLEHEART: return "LITTLEHEART";case RELIC: return "RELIC";case RELIC_MAP: return "RELIC_MAP";case COFFIN: return "COFFIN";case RELIC_BANGER: return "RELIC_BANGER";
        case RELIC_TEAR: return "RELIC_TEAR";case RELIC_RANDOMAZZO: return "RELIC_RANDOMAZZO";case MOONGATE: return "MOONGATE";case RELIC_GLASSMASK: return "RELIC_GLASSMASK";case RELIC_GOLDENEGG: return "RELIC_GOLDENEGG";
        case RELIC_YELLOW: return "RELIC_YELLOW";case MERCHANT: return "MERCHANT";case ROSARYX: return "ROSARYX";case DUMMY_LIGHTSOURCE: return "DUMMY_LIGHTSOURCE";case DUMMY_BANISH: return "DUMMY_BANISH";
        case DUMMY_SKIP: return "DUMMY_SKIP";case DUMMY_REROLL: return "DUMMY_REROLL";case RELIC_NOSEGLASSES: return "RELIC_NOSEGLASSES";case RELIC_GRIMOIRE: return "RELIC_GRIMOIRE";
        case RELIC_SECRETS: return "RELIC_SECRETS";case RELIC_GOUDA: return "RELIC_GOUDA";case RELIC_GGOSPEL: return "RELIC_GGOSPEL";case GILDED: return "GILDED";case ALWAYS_COINBAG2: return "ALWAYS_COINBAG2";
        case ALWAYS_ROAST: return "ALWAYS_ROAST";case HEALER: return "HEALER";case PURIFY: return "PURIFY";case COSMO_PAVONE: return "COSMO_PAVONE";case COFFINX: return "COFFINX";
        case COFFIN_EMPTY: return "COFFIN_EMPTY";case DIRECTER: return "DIRECTER";case DUMMY_ARC: return "DUMMY_ARC";case RELIC_MIRROR: return "RELIC_MIRROR";case RELIC_TRUMPET: return "RELIC_TRUMPET";
        case DUMMY_REVIVAL: return "DUMMY_REVIVAL";case PURIFY2: return "PURIFY2";case EGGMAN: return "EGGMAN";case DUMMY_GOLDENEGG_MAX: return "DUMMY_GOLDENEGG_MAX";case RELIC_MALACHITE: return "RELIC_MALACHITE";
        case RELIC_CHARM: return "RELIC_CHARM";case RELIC_MAP_FS: return "RELIC_MAP_FS";case RELIC_MAP_MS: return "RELIC_MAP_MS";case GOLDFINGER: return "GOLDFINGER";case TELEPORTER: return "TELEPORTER";
        case RELIC_ROSALIA: return "RELIC_ROSALIA";case RELIC_TRISECTION: return "RELIC_TRISECTION";case RELIC_MAP_AS: return "RELIC_MAP_AS";case FRIENDSHIP: return "FRIENDSHIP";case RELIC_LAZULIA: return "RELIC_LAZULIA";
        case RELIC_ALTEMANNA: return "RELIC_ALTEMANNA";case RELIC_CHAOSEGG: return "RELIC_CHAOSEGG";case RELIC_ANTIDOTE: return "RELIC_ANTIDOTE";case ADVENTURE_MERCHANT: return "ADVENTURE_MERCHANT";
        case RELIC_ATLAS: return "RELIC_ATLAS";case RELIC_SPEEDUP: return "RELIC_SPEEDUP";case RELIC_BRAVESTORY: return "RELIC_BRAVESTORY";case RELIC_MAP_CHAL: return "RELIC_MAP_CHAL";case RELIC_DARKASSO: return "RELIC_DARKASSO";
        case CART_ACCEL: return "CART_ACCEL";case CART_GOAL: return "CART_GOAL";case STATS_TREASURE_4: return "STATS_TREASURE_4";case STATS_TREASURE_5: return "STATS_TREASURE_5";case CUSTOM_MERCHANT: return "CUSTOM_MERCHANT";
        case SORBETTO: return "SORBETTO";case STATIC_GOLDPILE: return "STATIC_GOLDPILE";case RELIC_PARTY: return "RELIC_PARTY";case EX_ZI_APPUNTA_PICKUP: return "EX_ZI_APPUNTA_PICKUP";
        case PICKUP_REROLL_DICE: return "PICKUP_REROLL_DICE";case RELIC_RECYCLE: return "RELIC_RECYCLE";case STATS_TREASURE_WEAPONS: return "STATS_TREASURE_WEAPONS";case STATS_TREASURE_EVOS: return "STATS_TREASURE_EVOS";
        case RELIC_SURVAROCCHI: return "RELIC_SURVAROCCHI";case SV_DRAFT1: return "SV_DRAFT1";case SV_DRAFT2: return "SV_DRAFT2";case SV_DRAFT3: return "SV_DRAFT3";case RELIC_EME_DISK: return "RELIC_EME_DISK";
        case EME_CATY: return "EME_CATY";case EME_CATB: return "EME_CATB";case EME_CATU: return "EME_CATU";case EME_CATW: return "EME_CATW";case EME_CATR: return "EME_CATR";case EME_CAT_RAINBOW: return "EME_CAT_RAINBOW";
        case EME_TELEPORTER: return "EME_TELEPORTER";case FB_RAPIDFIRE: return "FB_RAPIDFIRE";case FB_BARRIER: return "FB_BARRIER";case FB_GRENADE: return "FB_GRENADE";case RELIC_MAP_FB: return "RELIC_MAP_FB";
        case BONUS_FROZENSOUL: return "BONUS_FROZENSOUL";case TP_HEART_REFRESH: return "TP_HEART_REFRESH";case TP_WALL_CHICKEN: return "TP_WALL_CHICKEN";case TP_NEUTRON_BOMB: return "TP_NEUTRON_BOMB";
        case TP_KARMA_COIN: return "TP_KARMA_COIN";case TP_MIRROR_OF_TRUTH: return "TP_MIRROR_OF_TRUTH";case TP_SOULSTEAL_LITTLEHEART: return "TP_SOULSTEAL_LITTLEHEART";case TP_RELIC_PILEOFSECRETS: return "TP_RELIC_PILEOFSECRETS";
        case TP_RELIC_MASK_SUN: return "TP_RELIC_MASK_SUN";case TP_RELIC_MASK_MOON: return "TP_RELIC_MASK_MOON";case TP_RELIC_MASK_CITY: return "TP_RELIC_MASK_CITY";case TP_RELIC_MASK_VOLCANO: return "TP_RELIC_MASK_VOLCANO";
        case TP_RELIC_MASK_SEAWINDS: return "TP_RELIC_MASK_SEAWINDS";case TP_RELIC_MASK_STONE: return "TP_RELIC_MASK_STONE";case TP_RELIC_MASK_BLACK: return "TP_RELIC_MASK_BLACK";case TP_RELIC_BLACK_DISK: return "TP_RELIC_BLACK_DISK";
        case TP_RELIC_TELEPORT1: return "TP_RELIC_TELEPORT1";case TP_RELIC_TELEPORT2: return "TP_RELIC_TELEPORT2";case TP_RELIC_TELEPORT3: return "TP_RELIC_TELEPORT3";case TP_RELIC_TELEPORT4: return "TP_RELIC_TELEPORT4";
        case TP_RELIC_TELEPORT5: return "TP_RELIC_TELEPORT5";case TP_RELIC_TELEPORT6: return "TP_RELIC_TELEPORT6";case TP_RELIC_LIBRARIAN: return "TP_RELIC_LIBRARIAN";case TP_RELIC_CASTLEMAP: return "TP_RELIC_CASTLEMAP";
        case TP_MERCHANT_LIBRARIAN: return "TP_MERCHANT_LIBRARIAN";case TP_CYCLEGATE: return "TP_CYCLEGATE";case TP_RELIC_STONES: return "TP_RELIC_STONES";case RELIC_MASK_FATE: return "RELIC_MASK_FATE";
        case RELIC_MASK_WRATH: return "RELIC_MASK_WRATH";case RELIC_MASK_SOVEREIGN: return "RELIC_MASK_SOVEREIGN";case RELIC_MASK_IMPLACABILITY: return "RELIC_MASK_IMPLACABILITY";case RELIC_MASK_MIRTH: return "RELIC_MASK_MIRTH";
        case BONUS_CURSEDSOUL: return "BONUS_CURSEDSOUL";case CARD_B001_ANTONIO: return "CARD_B001_ANTONIO";case CARD_B002_IMELDA: return "CARD_B002_IMELDA";case CARD_B003_PASQUALINA: return "CARD_B003_PASQUALINA";
        case CARD_B004_GENNARO: return "CARD_B004_GENNARO";case RELIC_LEM_DISK: return "RELIC_LEM_DISK";
        default: return "UnknownItemType";
        }
    }
    std::string GetCharacterToString(CharacterType characterType)
    {
        using enum CharacterType;
        switch (characterType)
        {
        case NONE: return "NONE"; case ANTONIO: return "ANTONIO"; case IMELDA: return "IMELDA"; case PASQUALINA: return "PASQUALINA"; case GENNARO: return "GENNARO";
        case CRISTINA: return "CRISTINA"; case CIRO: return "CIRO"; case PORTA: return "PORTA"; case EXDASH: return "EXDASH"; case MORTACCIO: return "MORTACCIO"; case CAVALLO: return "CAVALLO";
        case CAMILLO: return "CAMILLO"; case RED: return "RED"; case LAMA: return "LAMA"; case DOMMARIO: return "DOMMARIO"; case CROCI: return "CROCI"; case GERMANA: return "GERMANA";
        case LORDO: return "LORDO"; case POPPEA: return "POPPEA"; case PUGNALA: return "PUGNALA"; case GIOVANNA: return "GIOVANNA"; case CONCETTA: return "CONCETTA"; case ASSUNTA: return "ASSUNTA";
        case DEATH: return "DEATH"; case DETH: return "DETH"; case PANINI: return "PANINI"; case GRAZIELLA: return "GRAZIELLA"; case CANTERVILLO: return "CANTERVILLO"; case TUPU: return "TUPU";
        case VERANDA: return "VERANDA"; case TATANKA: return "TATANKA"; case LATODILATO: return "LATODILATO"; case LATODISOPRO: return "LATODISOPRO"; case YOLO: return "YOLO"; case SCEMINO: return "SCEMINO";
        case DUPRE: return "DUPRE"; case LATODISOTTO: return "LATODISOTTO"; case LATOEVEST: return "LATOEVEST"; case MAREMMA: return "MAREMMA"; case FEBBRA: return "FEBBRA"; case MARIA: return "MARIA";
        case MARIANNA: return "MARIANNA"; case MARIASOFIA: return "MARIASOFIA"; case BESUGO: return "BESUGO"; case ANDRIA: return "ANDRIA"; case NOSTRO: return "NOSTRO"; case FINO: return "FINO";
        case PINO: return "PINO"; case SIGMA: return "SIGMA"; case AVATAR: return "AVATAR"; case IOLO: return "IOLO"; case PEPPE: return "PEPPE"; case PEPPINO: return "PEPPINO"; case SMITH: return "SMITH";
        case NEO: return "NEO"; case PIRIPIRI: return "PIRIPIRI"; case PINEYE: return "PINEYE"; case PENTA: return "PENTA"; case ODDEEO: return "ODDEEO"; case AMBROGIO: return "AMBROGIO"; case BOROS: return "BOROS";
        case PANTALONE: return "PANTALONE"; case PAVONE: return "PAVONE"; case DRAGOGION: return "DRAGOGION"; case ARENGIJUS: return "ARENGIJUS"; case SCOREJ: return "SCOREJ"; case MIANG: return "MIANG";
        case MENYA: return "MENYA"; case SYUUTO: return "SYUUTO"; case ONNA: return "ONNA"; case MCCOY: return "MCCOY"; case MEGAMENYA: return "MEGAMENYA"; case MEGASYUUTO: return "MEGASYUUTO";
        case TONY: return "TONY"; case NARA: return "NARA"; case ELEANOR: return "ELEANOR"; case LUMINAIRE: return "LUMINAIRE"; case GENEVIEVE: return "GENEVIEVE"; case MEGAGENEVIEVE: return "MEGAGENEVIEVE";
        case VICTOR: return "VICTOR"; case KEIRA: return "KEIRA"; case GHOUL: return "GHOUL"; case GAEA: return "GAEA"; case MARUTO: return "MARUTO"; case CTRPCAKE: return "CTRPCAKE"; case SHEMOONITA: return "SHEMOONITA";
        case SPACEDUDE: return "SPACEDUDE"; case SPACEDUDETTE: return "SPACEDUDETTE"; case SPACEALIEN: return "SPACEALIEN"; case SANTA: return "SANTA"; case AMBERBORNE: return "AMBERBORNE"; case KITTYSAN: return "KITTYSAN";
        case KIKICHAN: return "KIKICHAN"; case GYORUNTIN: return "GYORUNTIN"; case RYOMARE: return "RYOMARE"; case BELLA: return "BELLA"; case SKTOOA: return "SKTOOA"; case SKALAFACHA: return "SKALAFACHA";
        case SKLEEMEJO: return "SKLEEMEJO"; case SKDEPEEPPO: return "SKDEPEEPPO"; case BATSBATSBATS: return "BATSBATSBATS"; case ROSE: return "ROSE"; case TORINO: return "TORINO"; case MAURIZIO: return "MAURIZIO";
        case MEGALO_MORTACCIO: return "MEGALO_MORTACCIO"; case MEGALO_CAVALLO: return "MEGALO_CAVALLO"; case MEGALO_RAMBA: return "MEGALO_RAMBA"; case MEGALO_OSOLE: return "MEGALO_OSOLE"; case MEGALO_AMBROJOE: return "MEGALO_AMBROJOE";
        case C1_CREWMATE: return "C1_CREWMATE"; case C1_IMPOSTOR: return "C1_IMPOSTOR"; case C1_GHOST: return "C1_GHOST"; case C1_GUARDIAN: return "C1_GUARDIAN"; case C1_ENGINEER: return "C1_ENGINEER";
        case C1_SCIENTIST: return "C1_SCIENTIST"; case C1_SHAPESHIFTER: return "C1_SHAPESHIFTER"; case C1_HORSE: return "C1_HORSE"; case C1_PICKLE: return "C1_PICKLE"; case C1_RABBIT: return "C1_RABBIT";
        case C1_MEGAIMPOSTOR: return "C1_MEGAIMPOSTOR"; case FB_BILLRIZER: return "FB_BILLRIZER"; case FB_LANCE: return "FB_LANCE"; case FB_BRADFANG: return "FB_BRADFANG"; case FB_BROWNY: return "FB_BROWNY";
        case FB_LUCIA: return "FB_LUCIA"; case FB_PROBO: return "FB_PROBO"; case FB_SHEENA: return "FB_SHEENA"; case FB_STANLEY: return "FB_STANLEY"; case FB_ARIANA: return "FB_ARIANA"; case FB_COLONEL: return "FB_COLONEL";
        case FB_SIMONDO: return "FB_SIMONDO"; case FB_NEWT: return "FB_NEWT"; case FB_DUMMY_01: return "FB_DUMMY_01"; case FB_DUMMY_02: return "FB_DUMMY_02"; case FB_DUMMY_03: return "FB_DUMMY_03"; case FB_DUMMY_04: return "FB_DUMMY_04";
        case FB_DUMMY_05: return "FB_DUMMY_05"; case FB_DUMMY_06: return "FB_DUMMY_06"; case FB_DUMMY_07: return "FB_DUMMY_07"; case FB_DUMMY_08: return "FB_DUMMY_08"; case FB_DUMMY_09: return "FB_DUMMY_09";
        case FB_DUMMY_10: return "FB_DUMMY_10"; case FB_DUMMY_11: return "FB_DUMMY_11"; case EME_RAPIERDUAL: return "EME_RAPIERDUAL"; case EME_PUPGUN_FOLLOWER: return "EME_PUPGUN_FOLLOWER"; case EME_PUPKNIFE_FOLLOWER: return "EME_PUPKNIFE_FOLLOWER";
        case EME_PUPKATANA_FOLLOWER: return "EME_PUPKATANA_FOLLOWER"; case EME_PUPPUNCH_FOLLOWER: return "EME_PUPPUNCH_FOLLOWER"; case EME_MAGICALL: return "EME_MAGICALL"; case EME_PUNCHKICK: return "EME_PUNCHKICK"; case EME_CANNONGUN: return "EME_CANNONGUN";
        case EME_MECHKATANA: return "EME_MECHKATANA"; case EME_SWORDBITE: return "EME_SWORDBITE"; case EME_MRS: return "EME_MRS"; case EME_EXGREATSWORD: return "EME_EXGREATSWORD"; case EME_EXKNIFE: return "EME_EXKNIFE";
        case EME_EXAXE: return "EME_EXAXE"; case EME_EXSPEAR: return "EME_EXSPEAR"; case EME_PUPALL: return "EME_PUPALL"; case EME_CATS_FOLLOWER: return "EME_CATS_FOLLOWER"; case FOLLOWER_BATSBATSBATS: return "FOLLOWER_BATSBATSBATS";
        case FOLLOWER_MOONRABBIT: return "FOLLOWER_MOONRABBIT"; case FOLLOWER_MOONDUCK: return "FOLLOWER_MOONDUCK"; case EME_CATS: return "EME_CATS"; case EME_DEMON: return "EME_DEMON"; case EME_IMAKOO: return "EME_IMAKOO";
        case EME_KINA: return "EME_KINA"; case EX_CHULAREH: return "EX_CHULAREH"; case EX_ZIAPPUNTA: return "EX_ZIAPPUNTA"; case EX_GIOCARE: return "EX_GIOCARE"; case TP_ALBUS: return "TP_ALBUS";
        case TP_ALUCARD: return "TP_ALUCARD"; case TP_AXEARMOR: return "TP_AXEARMOR"; case TP_CARMILLA: return "TP_CARMILLA"; case TP_CARRIE: return "TP_CARRIE"; case TP_CHARLOTTE: return "TP_CHARLOTTE";
        case TP_CORNELL: return "TP_CORNELL"; case TP_DEATH: return "TP_DEATH"; case TP_DRACULA: return "TP_DRACULA"; case TP_ELIZABETH: return "TP_ELIZABETH"; case TP_ERIC: return "TP_ERIC"; case TP_GALAMOTH: return "TP_GALAMOTH";
        case TP_GRANT: return "TP_GRANT"; case TP_HECTOR: return "TP_HECTOR"; case TP_HENRY: return "TP_HENRY"; case TP_ISAAC: return "TP_ISAAC"; case TP_JONATHAN: return "TP_JONATHAN"; case TP_JOHN: return "TP_JOHN";
        case TP_JULIUS: return "TP_JULIUS"; case TP_JULIA: return "TP_JULIA"; case TP_JUSTE: return "TP_JUSTE"; case TP_LEON: return "TP_LEON"; case TP_LORETTA: return "TP_LORETTA"; case TP_MARIAA: return "TP_MARIAA";
        case TP_MARIAB: return "TP_MARIAB"; case TP_NATHAN: return "TP_NATHAN"; case TP_ORLOX: return "TP_ORLOX"; case TP_REINHARDT: return "TP_REINHARDT"; case TP_RICHTER: return "TP_RICHTER"; case TP_SHAFT: return "TP_SHAFT";
        case TP_SHANOA: return "TP_SHANOA"; case TP_SIMON: return "TP_SIMON"; case TP_SOMA: return "TP_SOMA"; case TP_SONIA: return "TP_SONIA"; case TP_STELLA: return "TP_STELLA"; case TP_STGERMAIN: return "TP_STGERMAIN";
        case TP_SUCCUBUS: return "TP_SUCCUBUS"; case TP_SYPHA: return "TP_SYPHA"; case TP_TREVOR: return "TP_TREVOR"; case TP_YOKO: return "TP_YOKO"; case TP_CHRISTOPHER: return "TP_CHRISTOPHER"; case TP_SARA: return "TP_SARA";
        case TP_DARIO: return "TP_DARIO"; case TP_DMITRI: return "TP_DMITRI"; case TP_CELIA: return "TP_CELIA"; case TP_RINALDO: return "TP_RINALDO"; case TP_MINA: return "TP_MINA"; case TP_QUINCY: return "TP_QUINCY";
        case TP_MAXIM: return "TP_MAXIM"; case TP_LISA: return "TP_LISA"; case TP_VINCENT: return "TP_VINCENT"; case TP_BRAUNER: return "TP_BRAUNER"; case TP_BARLOWE: return "TP_BARLOWE"; case TP_WIND: return "TP_WIND";
        case TP_ASTARTE: return "TP_ASTARTE"; case TP_LIBRARIAN: return "TP_LIBRARIAN"; case TP_HAMMER: return "TP_HAMMER"; case TP_GRAHAM: return "TP_GRAHAM"; case TP_SOLEIL: return "TP_SOLEIL"; case TP_JOACHIM: return "TP_JOACHIM";
        case TP_CAVETROLL: return "TP_CAVETROLL"; case TP_FERRYMAN: return "TP_FERRYMAN"; case TP_MALPHAS: return "TP_MALPHAS"; case TP_WALTER: return "TP_WALTER"; case TP_FROZENSHADE: return "TP_FROZENSHADE"; case TP_OLROX: return "TP_OLROX";
        case TP_SNIPER: return "TP_SNIPER"; case TP_FLEAMAN: return "TP_FLEAMAN"; case TP_BLACKMORE: return "TP_BLACKMORE"; case TP_JONATHAN_AND_CHARLOTTE: return "TP_JONATHAN_AND_CHARLOTTE"; case TP_CHARLOTTE_AND_JONATHAN: return "TP_CHARLOTTE_AND_JONATHAN";
        case TP_STELLA_AND_LORETTA: return "TP_STELLA_AND_LORETTA"; case TP_LORETTA_AND_STELLA: return "TP_LORETTA_AND_STELLA"; case TP_CORNELL_BCM: return "TP_CORNELL_BCM"; case TP_ELIZABETH_MEGA: return "TP_ELIZABETH_MEGA";
        case TP_DEATH_MEGA: return "TP_DEATH_MEGA"; case TP_KEREMET: return "TP_KEREMET"; case TP_DRACULA_MEGA: return "TP_DRACULA_MEGA"; case TP_OLROX_MEGA: return "TP_OLROX_MEGA"; case TP_FAMILIARS: return "TP_FAMILIARS";
        case TP_INNOCENT_DEVILS: return "TP_INNOCENT_DEVILS"; case TP_FOLLOWER_UKOBAK: return "TP_FOLLOWER_UKOBAK"; case TP_FOLLOWER_BITTERFLY: return "TP_FOLLOWER_BITTERFLY"; case TP_FOLLOWER_IMP: return "TP_FOLLOWER_IMP";
        case TP_FOLLOWER_GHOST: return "TP_FOLLOWER_GHOST"; case TP_FOLLOWER_WIZARD: return "TP_FOLLOWER_WIZARD"; case TP_FOLLOWER_FAIRY: return "TP_FOLLOWER_FAIRY"; case TP_FOLLOWER_PUMPKIN: return "TP_FOLLOWER_PUMPKIN";
        case TP_FOLLOWER_CARDINAL: return "TP_FOLLOWER_CARDINAL"; case TP_FOLLOWER_DRAGON: return "TP_FOLLOWER_DRAGON"; case TP_FOLLOWER_TIGER: return "TP_FOLLOWER_TIGER"; case TP_FOLLOWER_TURTLE: return "TP_FOLLOWER_TURTLE";
        case FOLLOWER_ENEMY: return "FOLLOWER_ENEMY"; case FS_FOLLOWER_HILLTROW: return "FS_FOLLOWER_HILLTROW"; case FS_FOLLOWER_BROWNIE: return "FS_FOLLOWER_BROWNIE"; case FS_FOLLOWER_LEGIONNAIRE: return "FS_FOLLOWER_LEGIONNAIRE";
        case TP_KIDDRACULA: return "TP_KIDDRACULA"; case TP_DESMOND: return "TP_DESMOND"; case TP_ZOE: return "TP_ZOE"; case TP_DOLORES: return "TP_DOLORES"; case TP_HUGH: return "TP_HUGH"; case TP_MORRIS: return "TP_MORRIS";
        case TP_ANNETTE: return "TP_ANNETTE"; case TP_TERA: return "TP_TERA"; case TP_AEON: return "TP_AEON"; case TP_PERSEPHONE: return "TP_PERSEPHONE"; case TP_GAIBON_AND_SLOGRA: return "TP_GAIBON_AND_SLOGRA";
        case TP_SLOGRA_AND_GAIBON: return "TP_SLOGRA_AND_GAIBON"; case TP_GAIBON: return "TP_GAIBON"; case TP_SLOGRA: return "TP_SLOGRA"; case TP_ACTRISE: return "TP_ACTRISE"; case TP_DROLTA: return "TP_DROLTA";
        case TP_JIANGSHI: return "TP_JIANGSHI"; case TP_WATERMAGICIAN: return "TP_WATERMAGICIAN"; case TP_SWORDRULER: return "TP_SWORDRULER"; case TP_GENYA: return "TP_GENYA"; case TP_FISHMAN: return "TP_FISHMAN";
        case TP_FAKE_TRIO: return "TP_FAKE_TRIO"; case TP_FW_FAKE_TREVOR: return "TP_FW_FAKE_TREVOR"; case TP_FW_FAKE_SYPHA: return "TP_FW_FAKE_SYPHA"; case TP_FW_FAKE_GRANT: return "TP_FW_FAKE_GRANT";
        case TP_ZEPHYR: return "TP_ZEPHYR"; case TP_STONESKULL: return "TP_STONESKULL"; case TP_CHAOS: return "TP_CHAOS"; case LEM_FOLLOWER_SABOTEUR: return "LEM_FOLLOWER_SABOTEUR"; case LEM_JIMBO: return "LEM_JIMBO";
        case LEM_CANIO: return "LEM_CANIO"; case LEM_CHICOT: return "LEM_CHICOT"; case LEM_PERKEO: return "LEM_PERKEO";
        default: return "UnknownCharacter";
        }
    }
    std::string GetStageToString(StageType stageType)
    {
        using enum StageType;
        switch (stageType)
        {
        case FOREST: return "FOREST"; case SINKING: return "SINKING"; case ENTRANCE: return "ENTRANCE"; case LIBRARY: return "LIBRARY"; case TEST: return "TEST"; case TESTONE: return "TESTONE"; case CASTLE: return "CASTLE";
        case GREENACRES: return "GREENACRES"; case WAREHOUSE: return "WAREHOUSE"; case MOLISE: return "MOLISE"; case TOWER: return "TOWER"; case BONEZONE: return "BONEZONE"; case STAGEX: return "STAGEX";
        case CHAPEL: return "CHAPEL"; case RASH: return "RASH"; case MACHINE: return "MACHINE"; case MACHINE2: return "MACHINE2"; case TOWERBRIDGE: return "TOWERBRIDGE"; case BLACK: return "BLACK";
        case WHITE: return "WHITE"; case MOONSPELL: return "MOONSPELL"; case BATCOUNTRY: return "BATCOUNTRY"; case ASTRALSTAIR: return "ASTRALSTAIR"; case FOSCARI: return "FOSCARI"; case FOSCARI2: return "FOSCARI2";
        case WHITEOUT: return "WHITEOUT"; case POLUS: return "POLUS"; case SPAZIE: return "SPAZIE"; case FB_GALUGA: return "FB_GALUGA"; case FB_HIGHWAY: return "FB_HIGHWAY"; case DEVILROOM: return "DEVILROOM";
        case LABORRATORY: return "LABORRATORY"; case COOP: return "COOP"; case CARLOCART: return "CARLOCART"; case LEGION_TEST: return "LEGION_TEST"; case BEELZEBUB_TEST: return "BEELZEBUB_TEST"; case DOPPLEGANGER_TEST: return "DOPPLEGANGER_TEST";
        case TP_CASTLE_TEST: return "TP_CASTLE_TEST"; case EMERALD: return "EMERALD"; case EX_WESTWOODS: return "EX_WESTWOODS"; case EX_MAZERELLA: return "EX_MAZERELLA"; case LEM_CHAMBER: return "LEM_CHAMBER"; case ADV_BAZAAR: return "ADV_BAZAAR";
        case ADV_M001CASTLEGROUNDS: return "ADV_M001CASTLEGROUNDS"; case ADV_M002SHRINESVALLEY: return "ADV_M002SHRINESVALLEY"; case ADV_M003FORBIDDENPEAK: return "ADV_M003FORBIDDENPEAK"; case ADV_M004HIDDENCAVE: return "ADV_M004HIDDENCAVE"; case ADV_M005FROZENLAKE: return "ADV_M005FROZENLAKE";
        case ADV_M006TANUKIFOREST: return "ADV_M006TANUKIFOREST"; case ADV_M007MOONSPELL: return "ADV_M007MOONSPELL"; case ADV_0001TEST: return "ADV_0001TEST"; case ADV_POE_1_Acres: return "ADV_POE_1_Acres"; case ADV_POE_2_Forest: return "ADV_POE_2_Forest";
        case ADV_POE_3_Woods: return "ADV_POE_3_Woods"; case ADV_POE_4_Orchard: return "ADV_POE_4_Orchard"; case ADV_POE_5_Garden: return "ADV_POE_5_Garden"; case ADV_POE_6_Molise: return "ADV_POE_6_Molise"; case ADV_IME_1_Chapel: return "ADV_IME_1_Chapel";
        case ADV_IME_2_Library: return "ADV_IME_2_Library"; case ADV_IME_3_Forest: return "ADV_IME_3_Forest"; case ADV_IME_4_Tower: return "ADV_IME_4_Tower"; case ADV_IME_5_Stair: return "ADV_IME_5_Stair";
        case ADV_IME_6_Magna: return "ADV_IME_6_Magna"; case ADV_CHAL_001_Meeting: return "ADV_CHAL_001_Meeting"; case ADV_CHAL_002_Security: return "ADV_CHAL_002_Security"; case ADV_CHAL_003_Ejected: return "ADV_CHAL_003_Ejected";
        case ADV_CHAL_004_Ghosted: return "ADV_CHAL_004_Ghosted"; case ADV_CHAL_005_Science: return "ADV_CHAL_005_Science"; case ADV_CHAL_006_Trouble: return "ADV_CHAL_006_Trouble"; case ADV_FB_001_Attack: return "ADV_FB_001_Attack";
        case ADV_FB_002_Bullet: return "ADV_FB_002_Bullet"; case ADV_FB_003_NeoCity: return "ADV_FB_003_NeoCity"; case ADV_FB_004_OperationGun: return "ADV_FB_004_OperationGun"; case ADV_FB_005_RunAndGun: return "ADV_FB_005_RunAndGun";
        case ADV_FB_006_Alien: return "ADV_FB_006_Alien"; case TP_CHAPEL: return "TP_CHAPEL"; case TP_CASTLE: return "TP_CASTLE"; case ADV_EME_001: return "ADV_EME_001"; case ADV_EME_002: return "ADV_EME_002";
        case ADV_SHEMOON_001: return "ADV_SHEMOON_001"; case ADV_SHEMOON_002: return "ADV_SHEMOON_002"; case ADV_SHEMOON_003: return "ADV_SHEMOON_003"; case ADV_SHEMOON_004: return "ADV_SHEMOON_004";
        case ADV_SHEMOON_005: return "ADV_SHEMOON_005"; case ADV_SHEMOON_006: return "ADV_SHEMOON_006"; case ADV_FOSCARI_001: return "ADV_FOSCARI_001"; case ADV_FOSCARI_002: return "ADV_FOSCARI_002";
        case ADV_FOSCARI_003: return "ADV_FOSCARI_003"; case ADV_FOSCARI_004: return "ADV_FOSCARI_004"; case ADV_FOSCARI_005: return "ADV_FOSCARI_005"; case ADV_FOSCARI_006: return "ADV_FOSCARI_006";
        case ADV_FOSCARI_007: return "ADV_FOSCARI_007"; case POE_ADV_BAZAAR: return "POE_ADV_BAZAAR"; case IMELDA_ADV_BAZAAR: return "IMELDA_ADV_BAZAAR"; case SHEMOON_ADV_BAZAAR: return "SHEMOON_ADV_BAZAAR"; case ADV_M001_ADV_BAZAAR: return "ADV_M001_ADV_BAZAAR";
        case CHALCEDONY_ADV_BAZAAR: return "CHALCEDONY_ADV_BAZAAR"; case FIRSTBLOOD_ADV_BAZAAR: return "FIRSTBLOOD_ADV_BAZAAR"; case FOSCARI_ADV_BAZAAR: return "FOSCARI_ADV_BAZAAR"; case ADV_OTC_001_001_Woods: return "ADV_OTC_001_001_Woods";
        case ADV_OTC_001_002_Entrance: return "ADV_OTC_001_002_Entrance"; case ADV_OTC_001_003_Library: return "ADV_OTC_001_003_Library"; case ADV_OTC_001_004_Clock: return "ADV_OTC_001_004_Clock"; case ADV_OTC_001_005_Throne: return "ADV_OTC_001_005_Throne";
        case ADV_OTC_001_006_Sunken: return "ADV_OTC_001_006_Sunken"; case ADV_OTC_001_007_Ecclesia: return "ADV_OTC_001_007_Ecclesia"; case ADV_OTC_001_008_Infinite: return "ADV_OTC_001_008_Infinite";
        case OTC_ADV_BAZAAR: return "OTC_ADV_BAZAAR"; case ADV_OTC_001_009_DeathFight: return "ADV_OTC_001_009_DeathFight";
        default: return "UnknownStage";
        }
    }
    std::string BgmTypeToString(BgmType type)
    {
        using enum BgmType;
        switch (type)
        {
        case BGM_Forest: return "BGM_Forest"; case BGM_Library: return "BGM_Library"; case BGM_Library_Legacy: return "BGM_Library_Legacy";
        case BGM_GreenAcres: return "BGM_GreenAcres"; case BGM_Plant: return "BGM_Plant"; case BGM_Mana: return "BGM_Mana";
        case BGM_Tower: return "BGM_Tower"; case BGM_RedBlue: return "BGM_RedBlue"; case BGM_Gatti: return "BGM_Gatti"; case BGM_Peggi: return "BGM_Peggi";
        case BGM_Chapet: return "BGM_Chapet"; case BGM_Chapel: return "BGM_Chapel"; case BGM_Water: return "BGM_Water"; case BGM_Vento: return "BGM_Vento";
        case NONE: return "NONE"; case TheEndIndeed: return "TheEndIndeed"; case TheEndIntro: return "TheEndIntro"; case TheEndMain: return "TheEndMain";
        case TheEndIndeed2: return "TheEndIndeed2"; case BGM_Bestiary: return "BGM_Bestiary"; case BGM_Secret: return "BGM_Secret";
        case BGM_BossRush: return "BGM_BossRush"; case BGM_Machine: return "BGM_Machine"; case BGM_Bones: return "BGM_Bones";
        case BGM_Solution: return "BGM_Solution"; case BGM_Glitch: return "BGM_Glitch"; case BGM_Forest_B: return "BGM_Forest_B";
        case BGM_Library_B: return "BGM_Library_B"; case BGM_Plant_B: return "BGM_Plant_B"; case BGM_Tower_B: return "BGM_Tower_B";
        case BGM_Chapel_B: return "BGM_Chapel_B"; case BGM_Pizza: return "BGM_Pizza"; case BGM_Pizza_B: return "BGM_Pizza_B";
        case BGM_Water_B: return "BGM_Water_B"; case BGM_GreenAcres_B: return "BGM_GreenAcres_B"; case BGM_Bones_B: return "BGM_Bones_B";
        case BGM_BossRush_B: return "BGM_BossRush_B"; case BGM_Cosmic: return "BGM_Cosmic"; case Phase0: return "Phase0";
        case Phase1: return "Phase1"; case Phase2: return "Phase2"; case Phase3: return "Phase3"; case Phase4: return "Phase4";
        case Phase5: return "Phase5"; case BGM_Spoopy: return "BGM_Spoopy"; case BGM_Flame: return "BGM_Flame"; case BGM_Bridge: return "BGM_Bridge";
        case BMG_Moonspell: return "BMG_Moonspell"; case BGM_Silver: return "BGM_Silver"; case BGM_FourSeasons: return "BGM_FourSeasons";
        case BGM_Night1: return "BGM_Night1"; case BGM_Night2: return "BGM_Night2"; case BGM_Mirage: return "BGM_Mirage";
        case BGM_BatCountry: return "BGM_BatCountry"; case BGM_Foscari: return "BGM_Foscari"; case BGM_Magic: return "BGM_Magic";
        case BGM_War: return "BGM_War"; case BGM_Deception: return "BGM_Deception"; case BGM_Luminaire: return "BGM_Luminaire";
        case BGM_Genevieve: return "BGM_Genevieve"; case BGM_Foscari2: return "BGM_Foscari2"; case BGM_Nature: return "BGM_Nature";
        case BGM_HB: return "BGM_HB"; case BGM_Foscari_KAZ: return "BGM_Foscari_KAZ"; case BGM_Magic_KAZ: return "BGM_Magic_KAZ";
        case BGM_War_KAZ: return "BGM_War_KAZ"; case BGM_Deception_KAZ: return "BGM_Deception_KAZ"; case BGM_AstralStair: return "BGM_AstralStair";
        case BGM_Snow: return "BGM_Snow"; case BGM_SpaceDude: return "BGM_SpaceDude"; case BGM_SpaceDude_Intro: return "BGM_SpaceDude_Intro";
        case BGM_Labor: return "BGM_Labor"; case BGM_Carts: return "BGM_Carts"; case BGM_Devil: return "BGM_Devil"; case BGM_TheCoop: return "BGM_TheCoop";
        case BGM_Westwoods: return "BGM_Westwoods"; case BGM_Mazerella: return "BGM_Mazerella"; case BGM_CAL_MainTheme: return "BGM_CAL_MainTheme";
        case BGM_CAL_HideSeek: return "BGM_CAL_HideSeek"; case BGM_CAL_NoDucks: return "BGM_CAL_NoDucks"; case BGM_CAL_NoAliens: return "BGM_CAL_NoAliens";
        case BGM_CAL_NoGhosts: return "BGM_CAL_NoGhosts"; case BGM_CAL_NoVamps: return "BGM_CAL_NoVamps"; case BGM_FB_COVER_00_Jung: return "BGM_FB_COVER_00_Jung";
        case BGM_FB_COVER_02_Wate: return "BGM_FB_COVER_02_Wate"; case BGM_FB_COVER_05_Yoro: return "BGM_FB_COVER_05_Yoro";
        case BGM_FB_COVER_06_Hard: return "BGM_FB_COVER_06_Hard"; case BGM_FB_COVER_09_Gtra: return "BGM_FB_COVER_09_Gtra";
        case BGM_FB_COVER_11_Fort: return "BGM_FB_COVER_11_Fort"; case BGM_FB_K00_Jung: return "BGM_FB_K00_Jung"; case BGM_FB_K01_Spir: return "BGM_FB_K01_Spir";
        case BGM_FB_K02_Wate: return "BGM_FB_K02_Wate"; case BGM_FB_K03_Zeph: return "BGM_FB_K03_Zeph"; case BGM_FB_K04_Blue: return "BGM_FB_K04_Blue";
        case BGM_FB_K05_Yoro: return "BGM_FB_K05_Yoro"; case BGM_FB_K06_Hard: return "BGM_FB_K06_Hard"; case BGM_FB_K07_Some: return "BGM_FB_K07_Some";
        case BGM_FB_K08_JNHD: return "BGM_FB_K08_JNHD"; case BGM_FB_K09_Gtra: return "BGM_FB_K09_Gtra"; case BGM_FB_K10_Moon: return "BGM_FB_K10_Moon";
        case BGM_FB_K11_Fort: return "BGM_FB_K11_Fort"; case BGM_FB_K12_Last: return "BGM_FB_K12_Last"; case BGM_FB_K13_Rave: return "BGM_FB_K13_Rave";
        case BGM_TP_loi_LeonsTheme: return "BGM_TP_loi_LeonsTheme"; case BGM_TP_SuccessorOfFate: return "BGM_TP_SuccessorOfFate";
        case BGM_TP_cotm_Awake: return "BGM_TP_cotm_Awake"; case BGM_TP_jud_MadForest: return "BGM_TP_jud_MadForest";
        case BGM_TP_cod_AbandonedCastle: return "BGM_TP_cod_AbandonedCastle"; case BGM_TP_cod_BaljhetMountains: return "BGM_TP_cod_BaljhetMountains";
        case BGM_TP_cod_EneomausMachineTower: return "BGM_TP_cod_EneomausMachineTower"; case BGM_TP_cod_FollowersOfDarkness: return "BGM_TP_cod_FollowersOfDarkness";
        case BGM_TP_cod_SarabandeOfHealing: return "BGM_TP_cod_SarabandeOfHealing"; case BGM_TP_dos_AfterConfession: return "BGM_TP_dos_AfterConfession";
        case BGM_TP_dos_AmberScenery: return "BGM_TP_dos_AmberScenery"; case BGM_TP_dos_DraculasTears: return "BGM_TP_dos_DraculasTears";
        case BGM_TP_dos_IntoTheDarkNight: return "BGM_TP_dos_IntoTheDarkNight"; case BGM_TP_dos_PitchBlackIntrusion: return "BGM_TP_dos_PitchBlackIntrusion";
        case BGM_TP_hod_AfterConfession: return "BGM_TP_hod_AfterConfession"; case BGM_TP_hod_AnEmptyTome: return "BGM_TP_hod_AnEmptyTome";
        case BGM_TP_hod_Aquarius: return "BGM_TP_hod_Aquarius"; case BGM_TP_hod_DanceOfIllusions: return "BGM_TP_hod_DanceOfIllusions";
        case BGM_TP_hod_DivineBloodlines: return "BGM_TP_hod_DivineBloodlines"; case BGM_TP_hod_DraculasCastle: return "BGM_TP_hod_DraculasCastle";
        case BGM_TP_hod_EbonyWings: return "BGM_TP_hod_EbonyWings"; case BGM_TP_hod_GazeUpAtTheDarkness: return "BGM_TP_hod_GazeUpAtTheDarkness";
        case BGM_TP_hod_HeartOfFire: return "BGM_TP_hod_HeartOfFire"; case BGM_TP_hod_IntoTheDarkNight: return "BGM_TP_hod_IntoTheDarkNight";
        case BGM_TP_hod_InvitationOfACrazedMoon: return "BGM_TP_hod_InvitationOfACrazedMoon"; case BGM_TP_hod_PitifulScion: return "BGM_TP_hod_PitifulScion";
        case BGM_TP_hod_PitchBlackIntrusion: return "BGM_TP_hod_PitchBlackIntrusion"; case BGM_TP_hod_SimonsTheme: return "BGM_TP_hod_SimonsTheme";
        case BGM_TP_hod_TheHiddenCurse: return "BGM_TP_hod_TheHiddenCurse"; case BGM_TP_hod_TheLostPortrait: return "BGM_TP_hod_TheLostPortrait";
        case BGM_TP_ooe_AnEmptyTome: return "BGM_TP_ooe_AnEmptyTome"; case BGM_TP_ooe_ChapelHiddenInSmoke: return "BGM_TP_ooe_ChapelHiddenInSmoke";
        case BGM_TP_ooe_EbonyWings: return "BGM_TP_ooe_EbonyWings"; case BGM_TP_ooe_JawsOfAScorchedEarth: return "BGM_TP_ooe_JawsOfAScorchedEarth";
        case BGM_TP_ooe_WanderingTheCrystalBlue: return "BGM_TP_ooe_WanderingTheCrystalBlue"; case BGM_TP_por_GazeUpAtTheDarkness: return "BGM_TP_por_GazeUpAtTheDarkness";
        case BGM_TP_por_InSearchOfTheHiddenSpell: return "BGM_TP_por_InSearchOfTheHiddenSpell"; case BGM_TP_por_InvitationOfACrazedMoon: return "BGM_TP_por_InvitationOfACrazedMoon";
        case BGM_TP_por_IronBlueIntention: return "BGM_TP_por_IronBlueIntention"; case BGM_TP_por_TheHiddenCurse: return "BGM_TP_por_TheHiddenCurse";
        case BGM_TP_por_VictorianFear: return "BGM_TP_por_VictorianFear"; case BGM_TP_sotn_DanceOfPales: return "BGM_TP_sotn_DanceOfPales";
        case BGM_TP_sotn_DanceOfIllusions: return "BGM_TP_sotn_DanceOfIllusions"; case BGM_TP_sotn_FestivalOfServants: return "BGM_TP_sotn_FestivalOfServants";
        case BGM_TP_sotn_GuardianMariaFight: return "BGM_TP_sotn_GuardianMariaFight"; case BGM_TP_sotn_LostPainting: return "BGM_TP_sotn_LostPainting";
        case BGM_TP_sotn_MoonlightNocturne: return "BGM_TP_sotn_MoonlightNocturne"; case BGM_TP_sotn_TragicPrince: return "BGM_TP_sotn_TragicPrince";
        case BGM_TP_sotn_WoodCarvingPartita: return "BGM_TP_sotn_WoodCarvingPartita"; case BGM_TP_Bloodlines_TheBeatingInDarkness: return "BGM_TP_Bloodlines_TheBeatingInDarkness";
        case BGM_TP_Bloodlines_ReincarnatedSoul: return "BGM_TP_Bloodlines_ReincarnatedSoul"; case BGM_TP_Bloodlines_TheSinkingOldSanctuary: return "BGM_TP_Bloodlines_TheSinkingOldSanctuary";
        case BGM_TP_Bloodlines_Beginning: return "BGM_TP_Bloodlines_Beginning"; case BGM_TP_Bloodlines_BloodyTears: return "BGM_TP_Bloodlines_BloodyTears";
        case BGM_TP_Bloodlines_VampireKiller: return "BGM_TP_Bloodlines_VampireKiller"; case BGM_TP_Bloodlines_IronBlueIntention: return "BGM_TP_Bloodlines_IronBlueIntention";
        case BGM_TP_Bloodlines_Pressure: return "BGM_TP_Bloodlines_Pressure"; case BGM_TP_Bloodlines_Mystery: return "BGM_TP_Bloodlines_Mystery";
        case BGM_emptyslot: return "BGM_emptyslot"; case BGM_TP_VS_VampireKiller: return "BGM_TP_VS_VampireKiller";
        case BGM_TP_VS_AnEmptyTome: return "BGM_TP_VS_AnEmptyTome"; case BGM_TP_VS_SimonTheme: return "BGM_TP_VS_SimonTheme";
        case BGM_TP_VS_DraculasCastle: return "BGM_TP_VS_DraculasCastle"; case BGM_TP_VS_SuccessorOfFate: return "BGM_TP_VS_SuccessorOfFate";
        case BGM_TP_VS_BloodyTears: return "BGM_TP_VS_BloodyTears"; case BGM_TP_VS_BlackDisk: return "BGM_TP_VS_BlackDisk";
        case BGM_TP_VS_MoonlightNocturne: return "BGM_TP_VS_MoonlightNocturne"; case BGM_TP_VS_LostPainting: return "BGM_TP_VS_LostPainting";
        case BGM_TP_VS_DanceOfPearls: return "BGM_TP_VS_DanceOfPearls"; case BGM_TP_VS_PitchBlackIntrusion: return "BGM_TP_VS_PitchBlackIntrusion";
        case BGM_TP_VS_DraculasTears: return "BGM_TP_VS_DraculasTears"; case BGM_TP_VS_AmberScenery: return "BGM_TP_VS_AmberScenery";
        case BGM_TP_VS_TragicPrince: return "BGM_TP_VS_TragicPrince"; case BGM_TP_VS_WanderingTheCrystalBlue: return "BGM_TP_VS_WanderingTheCrystalBlue";
        case BGM_TP_VS_JawsOfAScorchedEarth: return "BGM_TP_VS_JawsOfAScorchedEarth"; case BGM_TP_VS_ChapelHiddenInSmoke: return "BGM_TP_VS_ChapelHiddenInSmoke";
        case BGM_TP_VS_SarabandeOfHealing: return "BGM_TP_VS_SarabandeOfHealing"; case BGM_TP_VS_BaljhetMountaint: return "BGM_TP_VS_BaljhetMountaint";
        case BGM_TP_VS_EneomaosMachineTower: return "BGM_TP_VS_EneomaosMachineTower"; case BGM_TP_VS_TheBeginning: return "BGM_TP_VS_TheBeginning";
        case BGM_TP_VS_Aquarius: return "BGM_TP_VS_Aquarius"; case BGM_TP_VS_AbandonedCastle: return "BGM_TP_VS_AbandonedCastle";
        case BGM_TP_VS_WoodCarvingPartita: return "BGM_TP_VS_WoodCarvingPartita"; case BGM_TP_VS_LeonsTheme: return "BGM_TP_VS_LeonsTheme";
        case BGM_TP_VS_EbonyWings: return "BGM_TP_VS_EbonyWings"; case BGM_TP_VS_MadForest: return "BGM_TP_VS_MadForest";
        case BGM_TP_VS_VictorianFear: return "BGM_TP_VS_VictorianFear"; case BGM_TP_VS_BloodlinesBequeathed: return "BGM_TP_VS_BloodlinesBequeathed";
        case BGM_TP_VS_InvitationOfACrazedMoon: return "BGM_TP_VS_InvitationOfACrazedMoon"; case BGM_TP_VS_ReincarnatedSoul: return "BGM_TP_VS_ReincarnatedSoul";
        case BGM_TP_VS_TheSinkingOldSanctuary: return "BGM_TP_VS_TheSinkingOldSanctuary"; case BGM_TP_VS_Awake: return "BGM_TP_VS_Awake";
        case BGM_TP_VS_IronBlueIntention: return "BGM_TP_VS_IronBlueIntention"; case BGM_TP_VS_HeartOfFire: return "BGM_TP_VS_HeartOfFire";
        case BGM_TP_VS_AfterConfession: return "BGM_TP_VS_AfterConfession"; case BGM_TP_SOH_Credits: return "BGM_TP_SOH_Credits";
        case BGM_TP_VS_OutOfTime: return "BGM_TP_VS_OutOfTime"; case BGM_TP_VS_TreasuryRoom: return "BGM_TP_VS_TreasuryRoom";
        case BGM_TP_VS_C64Medley: return "BGM_TP_VS_C64Medley"; case BGM_TP_VS_CallingFromHeaven: return "BGM_TP_VS_CallingFromHeaven";
        case BGM_TP_VS_DiscoloredWall: return "BGM_TP_VS_DiscoloredWall"; case BGM_TP_VS_AntiSoulMysteriesLab: return "BGM_TP_VS_AntiSoulMysteriesLab";
        case BGM_TP_VS_WanderingGhosts: return "BGM_TP_VS_WanderingGhosts"; case BGM_TP_VS_DanceOfGold: return "BGM_TP_VS_DanceOfGold";
        case BGM_TP_VS_RuinedCastleCorridor: return "BGM_TP_VS_RuinedCastleCorridor"; case BGM_TP_VS_YoungNoblemanOfMadness: return "BGM_TP_VS_YoungNoblemanOfMadness";
        case BGM_TP_VS_ClockWork: return "BGM_TP_VS_ClockWork"; case BGM_TP_VS_NewMessiah: return "BGM_TP_VS_NewMessiah";
        case BGM_TP_Bloodlines_CallingFromHeaven: return "BGM_TP_Bloodlines_CallingFromHeaven"; case BGM_TP_Bloodlines_TheDiscoloredWall: return "BGM_TP_Bloodlines_TheDiscoloredWall";
        case BGM_TP_loi_AntiSoulMysteriesLab: return "BGM_TP_loi_AntiSoulMysteriesLab"; case BGM_TP_sotn_WanderingGhosts: return "BGM_TP_sotn_WanderingGhosts";
        case BGM_TP_sotn_DanceOfGold: return "BGM_TP_sotn_DanceOfGold"; case BGM_TP_hod_RuinedCastleCorridor: return "BGM_TP_hod_RuinedCastleCorridor";
        case BGM_TP_cod_YoungNoblemanOfMadness: return "BGM_TP_cod_YoungNoblemanOfMadness"; case BGM_TP_cotm_Clockwork: return "BGM_TP_cotm_Clockwork";
        case BGM_TP_reb_NewMessiah: return "BGM_TP_reb_NewMessiah"; case BGM_EME_QUICK: return "BGM_EME_QUICK"; case BGM_EME_SHOW: return "BGM_EME_SHOW";
        case BGM_EME_DESTINY: return "BGM_EME_DESTINY"; case BGM_EME_ENCHANTED: return "BGM_EME_ENCHANTED"; case BGM_EME_POLICE: return "BGM_EME_POLICE";
        case BGM_EME_BEAT: return "BGM_EME_BEAT"; case BGM_EME_DARKNESS: return "BGM_EME_DARKNESS"; case BGM_EME_FIERCE: return "BGM_EME_FIERCE";
        case BGM_EME_ODDS: return "BGM_EME_ODDS"; case BGM_EME_WORLD: return "BGM_EME_WORLD"; case BGM_LEM_CHAMBER: return "BGM_LEM_CHAMBER";
        default: return "Unknown";
        }
    }
    std::string CharacterRandGenStatName_ToString(CharacterRandomGeneratorStat eStat)
    {
        using enum CharacterRandomGeneratorStat;
        switch (eStat)
        {
		case Amount: return "Amount"; case Area: return "Area"; case Armor: return "Armor"; case Cooldown: return "Cooldown"; case Banish: return "Banish"; case Charm: return "Charm";
		case Curse: return "Curse"; case Defang: return "Defang"; case Duration: return "Duration"; case Fever: return "Fever"; case Greed: return "Greed"; case Growth: return "Growth";
		case InvulTimeBonus: return "InvulTimeBonus"; case Luck: return "Luck"; case Magnet: return "Magnet"; case MaxHp: return "MaxHp"; case MoveSpeed: return "MoveSpeed";
		case Power: return "Power"; case Recycle: return "Recycle"; case Regen: return "Regen"; case ReRolls: return "ReRolls"; case Revivals: return "Revivals"; case Shroud: return "Shroud";
		case Skips: return "Skips"; case Speed: return "Speed"; default: return "UnknownStat";
        }
    }
}