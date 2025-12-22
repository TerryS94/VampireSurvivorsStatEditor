#pragma once

namespace rendering
{
	extern ImVec4 MenuColorAccent;
	extern ImVec2 windowSize;

	void RenderVampireSurvivorsMenu();
	void InitFonts();
	void ApplyDarkThemeWithAccent(const ImVec4& primaryAccent);
}