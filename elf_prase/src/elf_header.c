#include "common.h"
#include "elf_header.h"

#include <elf.h>  

struct elf_header {
	unsigned char e_ident[16];
};


elf_header_t elf_header_prase(void* address) {
	Elf64_Ehdr* header = (struct Elf64_Ehdr*)address;
	t_debug("elf_header %d", __LINE__);
	t_debug("%d", header->e_ident[0]);
	return NULL;
}

int elf_header_destory(elf_header_t header) {
	return 0;
}