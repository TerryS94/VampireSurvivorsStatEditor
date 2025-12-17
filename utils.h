#pragma once
#include "main.h"

namespace ImGui
{
	bool IsItemHoveredDelay(float delay_in_seconds = 0.25f);
};
namespace utils
{
	BYTE FloatToByte(float f);
	std::string ToLowercase(const std::string& input);
	std::string ToUppercase(const std::string& input);
	bool isStringEmptyOrWhitespaceOnly(const std::string& str);
	void ImToolTipWithTextWrap(const char* str);
    ImVec4 Lerp(const ImVec4& a, const ImVec4& b, float t);
    ImVec4 Mul(const ImVec4& c, float m, float alpha = -1.0f);
	std::string getTimeNow();
	std::string getDateNow();

	std::string ItemTypeToString(ItemType itemType);
	std::string GetStageToString(StageType stageType);
	std::string GetCharacterToString(CharacterType characterType);
	std::string BgmTypeToString(BgmType type);
	std::string CharacterRandGenStatName_ToString(CharacterRandomGeneratorStat eStat);
}