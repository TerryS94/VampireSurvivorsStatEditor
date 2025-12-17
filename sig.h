#pragma once
#include "main.h"

namespace sig
{
    void SetupHooks();
    void SetupUnityTime();

    std::vector<int> ParsePattern(const std::string& pattern);
    BYTE* FindPattern(const std::string& pattern, BYTE* begin, uintptr_t size);
    BYTE* FindPattern(const std::string& pattern, const std::string& module);
}