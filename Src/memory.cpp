#include "pch.h"
#include "memory.h"

namespace memory
{
    void Patch(void* dst, const void* src, size_t size)
    {
        DWORD old;
        VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &old);
        memcpy(dst, src, size);
        VirtualProtect(dst, size, old, &old);
        FlushInstructionCache(GetCurrentProcess(), dst, size);
    }
    void nop(BYTE* target, size_t size)
    {
        DWORD oldprotect;
        VirtualProtect((PVOID*)target, size, PAGE_EXECUTE_READWRITE, &oldprotect);
        memset((void*)target, 0x90, size);
        VirtualProtect((PVOID*)target, size, oldprotect, &oldprotect);
        FlushInstructionCache(GetCurrentProcess(), (LPCVOID)target, size);
    }
	void replaceCall(uintptr_t address, uintptr_t functionToCall)
	{
		DWORD protection;
		uintptr_t relativeAddr = functionToCall - address - 5;
		VirtualProtect((void*)address, 5, PAGE_EXECUTE_READWRITE, &protection);
		*std::bit_cast<std::uint8_t*>(address) = (std::uint8_t)0xE8;
		*(uintptr_t*)(address + 1) = relativeAddr;
		VirtualProtect((void*)address, 5, protection, &protection);
		FlushInstructionCache(GetCurrentProcess(), (LPCVOID)address, 5);
	}
	void Wipe(BYTE* base, size_t sizeInBytes)
	{
		DWORD oldProtect;
		VirtualProtect(base, sizeInBytes, PAGE_EXECUTE_READWRITE, &oldProtect);
		memset(base, 0xCC, sizeInBytes);
		VirtualProtect(base, sizeInBytes, oldProtect, &oldProtect);
		FlushInstructionCache(GetCurrentProcess(), base, sizeInBytes);
	}
	DWORD GetModuleImageSize(std::string moduleName)
	{
		HMODULE hModule = GetModuleHandle(moduleName.c_str());
		if (hModule == nullptr)
			return 0ul;

		MODULEINFO moduleInfo = {};
		if (GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(moduleInfo)))
			return moduleInfo.SizeOfImage - 1ul;

		return 0ul;
	}
	size_t GetFunctionLength(BYTE* base)
	{
		if (base == nullptr)
			return 0u;

		const size_t max_search = 0x4000u;
		const unsigned long search_byte = strtoul("CC", nullptr, 16);
		for (size_t i = 0u; i < max_search; ++i)
		{
			if (base[i] == search_byte && base[i + 1u] == search_byte && base[i + 2u] == search_byte)
				return i;
		}
		return 0u;
	}
}