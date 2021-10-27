#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "elf_header.h"






void* __read_elf_header(const char* path) {
        int fd;
        struct stat st;
        size_t mmap_size;

        fd = open(path, O_RDONLY);
        t_assert(fd > 0, NULL);
        t_assert(fstat(fd, &st) != -1, NULL);


        /*
        * mmap��read write����
        * read �� write��Ҫ��copy��page_cache�У���copy���û��ռ��buffer��
        * mmap����Ҫcopy��page_cache�У�֮���û�����ֱ�Ӳ����ⲿ�ֵ�ָ�룬������û����������л����������page_fault�ͽ���ҳ��ӳ��Ĳ�����������һ��С
        * mmap����ӳ���ϵ��������˽�У�����˽�в���дʱ���Ƶļ�������˽�л������
        */


        //mmap size ��Ҫpage����
        mmap_size = st.st_size & ~(sysconf(_SC_PAGE_SIZE) - 1);
        t_debug("%ld", sysconf(_SC_PAGE_SIZE));
        t_debug("%ld", ~(sysconf(_SC_PAGE_SIZE) - 1));
        t_debug("file_size:%ld, mmap_size:%zu", st.st_size, mmap_size);


        //if (offset >= sb.st_size) {
        //        fprintf(stderr, "offset is past end of file\n");
        //        exit(EXIT_FAILURE);
        //}

        //if (argc == 4) {
        //        length = atoi(argv[3]);
        //        if (offset + length > sb.st_size)
        //                length = sb.st_size - offset;
        //        /* Can't display bytes past end of file */

        //}
        //else {    /* No length arg ==> display to end of file */
        //        length = sb.st_size - offset;
        //}

        //addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
        //        MAP_PRIVATE, fd, pa_offset);
        //if (addr == MAP_FAILED)
        //        handle_error("mmap");

        //s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
        //if (s != length) {
        //        if (s == -1)
        //                handle_error("write");

        //        fprintf(stderr, "partial write");
        //        exit(EXIT_FAILURE);
        //}

        //munmap(addr, length + offset - pa_offset);
        //close(fd);

        //exit(EXIT_SUCCESS);

        return NULL;
}


elf_header_t prase_elf_header(const char* fpath) {
        __read_elf_header(fpath);
        return NULL;
}