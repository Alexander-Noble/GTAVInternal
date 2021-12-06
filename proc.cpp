#include "proc.h"


DWORD GetProcessID(const wchar_t* procName) {

	HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32, 0);
	DWORD id = 0;

	if (ss == INVALID_HANDLE_VALUE) {
		throw "Invalid Handle Value";
	}

	PROCESSENTRY32 proc; 
	proc.dwSize = sizeof(proc);

	if (Process32First(ss, &proc)) {
		do {

			if (!_wcsicmp(procName, proc.szExeFile)) {

				id = proc.th32ProcessID;
				break;
			}

		} while (Process32Next(ss, &proc));
	}

	CloseHandle(ss);
	return id;
}

uintptr_t GetModuleBase(DWORD procID, const wchar_t* modName) {

	HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);
	uintptr_t base = 0;

	if (ss == INVALID_HANDLE_VALUE) {
		throw "Invalid Handle Value";
	}

	MODULEENTRY32 mod;
	mod.dwSize = sizeof(mod);

	if (Module32First(ss, &mod)) {
		do {

			if (!_wcsicmp(modName, mod.szModule)) {

				base = (uintptr_t)mod.modBaseAddr;
				break;

			} 
		} while (Module32First(ss, &mod));
	}

	CloseHandle(ss);
	return base;

}