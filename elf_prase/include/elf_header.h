#ifndef __EELF_HEADER__
#define __EELF_HEADER__
typedef void* elf_header_t;

extern elf_header_t elf_header_prase(void* address);

#endif