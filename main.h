#pragma once

#define NOMINMAX
#include <windows.h>
#include <thread>
#include <atomic>
#include <memory>
#include <chrono>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <format>
#include <psapi.h>
#include <d3d11.h>
#include <dxgi1_2.h>
#include <TlHelp32.h>
#include <map>
#include <unordered_map>
#include <dwmapi.h>
#include <random>
#include <regex>
#include <set>
#include <unordered_set>
#include <array>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui.h"
#include "Imgui/imgui_internal.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "Dwmapi.lib")

#include "polyhook2/Detour/x64Detour.hpp"

#include "resource.h"
#include "timer.h"
#include "memory.h"
#include "dx11stuff.h"
#include "vectors.h"
#include "structs.h"
#include "il2cpp_helpers.h"
#include "utils.h"
#include "log.h"
#include "hook.h"
#include "game.h"
#include "sig.h"
#include "imgui_ext.h"
#include "render.h"

extern bool isRunning;