#pragma once

namespace memory
{
	void Patch(void* dst, const void* src, size_t size);
	void nop(BYTE* target, size_t size);
	void replaceCall(uintptr_t address, uintptr_t functionToCall);
	void Wipe(BYTE* base, size_t sizeInBytes);
	DWORD GetModuleImageSize(std::string moduleName);
	size_t GetFunctionLength(BYTE* base);

	template<typename T>
	inline void Write(T* dst, const T& value)
	{
		if (!dst)
			return;
		memory::Patch(dst, &value, sizeof(T));
	}
}