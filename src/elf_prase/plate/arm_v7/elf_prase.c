#include"elf_prase.h"
#include"elf_header.h"
#include"common.h"


struct elf {

};


elf_t elf_build() {

}

int elf_destory(elf_t elf) {

}


elf_t elf_prase(char* path) {
	prase_elf_header(path);
	return NULL;
}