#ifndef __EELF_PRASE__
#define __EELF_PRASE__
#include"_elf_prase.h"

typedef void* elf_t;
inline elf_t elf_prase(char* path) {
	return _elf_prase(path);
}
#endif
