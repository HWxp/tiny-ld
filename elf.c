#include<unistd.h>
#include"common.h"

typedef struct elf_header{
}*elf_header_t;

struct elf{
	elf_header_t eheader;
}*elf_t;


elf_header_t elf_prase_header(unsigned char* info){
	
}


elf_t elf_prase(char* path){
}
