#include "pch.h"
#include "log.h"

namespace Logger
{
	bool ToggleAutoScroll = true;
	int scrollFrames = 3;
	static size_t maxHistory = 1000u;
	static std::vector<ConsoleInfo> logHistory;

	std::vector<ConsoleInfo>& GetLogHistory()
	{
		return logHistory;
	}
	void AddLog(const std::string& message, bool error)
	{
		if (!isRunning)
			return;
		ConsoleInfo logInfo;
		logInfo.isError = error;
		logInfo.message = std::format("[{}]: {}", utils::getTimeNow(), message);
		logHistory.push_back(std::move(logInfo));
		while (logHistory.size() > maxHistory)
			logHistory.erase(logHistory.begin());

		scrollFrames = 3;
	}
	void ClearLogHistory()
	{
		logHistory.clear();
	}
}