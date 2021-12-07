// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"

BOOL WINAPI HackThread(HMODULE hMod) {

    AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);

    
    uintptr_t moduleBaseAddress = (uintptr_t) GetModuleHandle(L"GTA5.exe");


    while (true) {

    }
    fclose(file);
    FreeConsole();
    FreeLibraryAndExitThread(hMod, 0);
    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

