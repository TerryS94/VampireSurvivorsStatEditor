#pragma once
#include "main.h"

namespace imgui_ext
{
	void AddRectFilledMultiColorRounded(const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, bool filled, ImDrawFlags flags);
	ImColor ColorScale(const ImColor& color, float brightnessFactor);
	bool ButtonImage(const char* label, const ImVec2& size_arg = ImVec2(0, 0), void* texture = nullptr, bool hideBG = false, float minTextureAnimTint = 0.9f, ImGuiButtonFlags flags = 0, ImVec2 padding = ImVec2(4, 4), ImVec4 tintColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
}