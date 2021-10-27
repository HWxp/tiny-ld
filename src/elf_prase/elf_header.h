#ifndef __EELF_HEADER__
#define __EELF_HEADER__
typedef void* elf_header_t;
elf_header_t prase_elf_header(const char* fpath);
#endif