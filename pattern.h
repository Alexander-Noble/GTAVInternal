#pragma once
#include <Windows.h>

char* Scan(char* pattern, char* mask, char* entry, uintptr_t size);
char* ScanInternal(char* pattern, char* mask, char* entry, uintptr_t size);
char* ScanInWrap();