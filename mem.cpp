#include "mem.h"
#include <vector>

void mem::Patch(BYTE* dst, BYTE* src, unsigned int size) {
	DWORD pprot; 
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &pprot);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, pprot, &pprot);

}
void mem::Nop(BYTE* dst, unsigned int size) {
	DWORD pprot;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &pprot);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, pprot, &pprot);
}

uintptr_t mem::GetDMAAddress(uintptr_t ptr, std::vector<int> offsets) {

	uintptr_t address = ptr;

	for (unsigned int i = 0; i < offsets.size(); i++) {
		address = *(uintptr_t*)address;
		address += offsets[i];
	}

	return address;
}