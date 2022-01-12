#include"elf_prase.h"
#include"elf_header.h"
#include"common.h"

#include <sys/mman.h> //PROT_READ MAP_PRIVATE
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct elf {
    elf_header_t e_header;
};


elf_t elf_build() {
    struct elf* ret = t_malloc(sizeof(struct elf));
    t_assert(ret != NULL, NULL);

    ret->e_header = NULL;
    return ret;
}

int elf_destory(elf_t elf) {
    struct elf* _elf = (struct elf*)elf;
    if (!_elf)
        return 0;
    
    //if (_elf->e_header)
    //    t_assert(elf_header_destory(_elf->e_header) == 0, -1);

    free(_elf);
    return 0;
}

void* __elf_read(const char* path, size_t* length) {
    int fd;
    struct stat st;
    size_t mmap_size;
    void* addr;

    fd = open(path, O_RDONLY);
    t_assert(fd > 0, NULL);
    t_assert(fstat(fd, &st) != -1, NULL);


    /*
    * mmap和read write区别
    * read 和 write需要先copy到page_cache中，再copy到用户空间的buffer中
    * mmap仅需要copy到page_cache中，之后用户可以直接操作这部分的指针，后面的用户操作过程中会产生大量的page_fault和建立页表映射的操作，开销不一定小
    * mmap两种映射关系，共享与私有，其中私有采用写时复制的技术进行私有化处理的
    */


    //mmap size 需要page对齐
    mmap_size = t_align(st.st_size, sysconf(_SC_PAGE_SIZE));
    t_debug("file_size:%ld, mmap_size:%zu", st.st_size, mmap_size);

    addr = mmap(NULL, mmap_size, PROT_READ, MAP_PRIVATE, fd, mmap_size);
    t_assert(addr != MAP_FAILED, NULL);

    close(fd);
    return addr;
}



elf_t elf_prase(char* path) {
    size_t length;
    void* header;
    void* addr;
    struct elf* elf;

    addr = __elf_read(path, &length);
    t_assert(addr != NULL, NULL);

    elf = elf_build();
    t_assert(elf != NULL, NULL);

    elf->e_header = elf_header_prase(addr);
    t_assert_handle(elf->e_header != NULL, NULL, elf_destory(elf));

	return elf;
}