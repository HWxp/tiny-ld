#ifndef ___EELF_PRASE__
#define ___EELF_PRASE__

#include"__elf_header.h"

typedef struct _elf {
	_elf_header_t _e_header;
}*_elf_t;

extern _elf_t _elf_prase(char* path);
extern _elf_t _elf_build();
extern int _elf_destory(_elf_t elf);
#endif