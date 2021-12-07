#include "pattern.h"


char* Scan(char* pattern, char* mask, char* entry, uintptr_t size) {
	uintptr_t masklength = strlen(mask);

	for (int i = 0; i < size - masklength; i++) {
		bool found = true;

		for (int j = 0; i < masklength; j++) {

			if (mask[j] != '?' && pattern[j] != *(entry + i + j)) {
				found == false;
				break;
			}
		}

		if (found) {
			return (entry + i);
		}
	}
	return nullptr;
}

char* ScanInternal(char* pattern, char* mask, char* entry, uintptr_t size) {
	char* pattern_match{ nullptr };
	MEMORY_BASIC_INFORMATION mbi;

	for (char* current = entry; current < entry + size; current += mbi.RegionSize) {

		if (!VirtualQuery(current, &mbi, sizeof(mbi)) || mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS) continue;

		pattern_match = Scan(pattern, mask, current, mbi.RegionSize);

		if (pattern_match != nullptr) {
			break;
		}
	}
	return pattern_match;
}

char* ScanInWrap() {

}