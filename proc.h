#pragma once
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <exception>

DWORD GetProcessID(const wchar_t* procName);
uintptr_t GetModuleBaseAddress(DWORD procID, const wchar_t* modName);
MODULEENTRY32 GetModuleEntry(DWORD procID, const wchar_t* modName);