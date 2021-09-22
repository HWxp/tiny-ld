#include"common.h"

void __debug(const char* buf) {
	printf("[debug]:%s\n", buf);
}


void __error(const char* buf) {
	printf("[error]:%s\n", buf);
}

void* t_malloc(size_t size) {
	return malloc(size);
}

int t_free(void* ptr) {
	free(ptr);
	return 0;
}