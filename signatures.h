#pragma once
#include <Windows.h>

LPCSTR healthPattern = "\x48\x8D\xBE\x80\x02\x00\x00\x41";
LPCSTR healthMask = "xxxxxxxx";
LPCSTR moneyPattern = "45 8B C4 48 8B C8 C6 44 24 20 01 E8 ? ? ? ? 8A 1D";
LPCSTR moneyMask = "xxxxxxxxxxxx????xx";
LPCSTR ammoPattern = "89 5F 20 48 8B 5C 24 30 48 8B 6C 24 38 48"; // \x8B\x42\x20\xEB\x02
LPCSTR ammoMask = "xxxxxxxxxxxxxx";
LPCSTR wantedPattern = "8B 90 98 00 00 00 83 EA 02 74 20";
LPCSTR wantedMask = "xxxxxxxxxxx";

LPCSTR clipPattern = "\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x37"; //0F BF 57 56 0F BF 47 54 // \x8b\x47\x00\x0f\x28\x74\x24\x00\x48\x83\x66 // \xb9\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x84\xc0\x74\x00\x41\x8b\xce
LPCSTR clipMask = "x????x????xxxx"; // xxxxxxxx // xx?xxxx?xxx // x ? ? ? ? x ? ? ? ? xxx ? xxx 

LPCSTR abilityPattern = "\xF3\x0F\x5C\xCE\xF3\x0F\x2C\xC9";
LPCSTR abilityMask = "xxxxxxxx";