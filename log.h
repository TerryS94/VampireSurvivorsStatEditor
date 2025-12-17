#pragma once
#include "main.h"

struct ConsoleInfo
{
	bool isError = false;
	std::string message = "";
};
namespace Logger
{
	extern bool ToggleAutoScroll;
	extern int scrollFrames;
	std::vector<ConsoleInfo>& GetLogHistory();
	void AddLog(const std::string& message, bool error = false);
	void ClearLogHistory();
}