#include "il2cpp_helpers.h"

namespace il2cpp
{
	std::string GetString(const Il2CppString* s)
	{
		if (!s || s->length <= 0)
			return {};
		const wchar_t* wide = reinterpret_cast<const wchar_t*>(s->chars);
		int wideLen = s->length;
		int sizeNeeded = ::WideCharToMultiByte(CP_UTF8, 0, wide, wideLen, nullptr, 0, nullptr, nullptr);
		if (sizeNeeded <= 0)
			return {};
		std::string result(static_cast<size_t>(sizeNeeded), '\0');
		int written = ::WideCharToMultiByte(CP_UTF8, 0, wide, wideLen, result.data(), sizeNeeded, nullptr, nullptr);
		if (written <= 0)
			return {};
		return result;
	}
	std::string ReadableSaveDateString(const Il2CppString* s)
	{
		std::string raw = GetString(s);
		if (raw.empty())
			return {};

		long long ticks = 0;
		try { ticks = std::stoll(raw); }
		catch (...) { return raw; }

		const long long TICKS_PER_MILLISECOND = 10'000;
		long long millis = ticks / TICKS_PER_MILLISECOND;
		std::chrono::system_clock::time_point tp{ std::chrono::milliseconds(millis) };
		std::time_t tt = std::chrono::system_clock::to_time_t(tp);
		std::tm tm{};
		localtime_s(&tm, &tt);
		char buf[64]{};
		std::strftime(buf, sizeof(buf), "%m/%d/%Y - %H:%M:%S", &tm);
		return std::string(buf);
	}
}