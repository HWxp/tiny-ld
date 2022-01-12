#include"elf_prase.h"


#include<stdio.h>
void cmd() {
	printf("./main fpath\n");
}


int main(int argv, char** argc) {
	if (argv != 2) {
		cmd();
		return 0;
	}

	elf_prase(argc[1]);
	return 0;
}