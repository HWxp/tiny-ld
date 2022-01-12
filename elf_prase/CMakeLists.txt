cmake_minimum_required (VERSION 3.8)


include_directories("include")
aux_source_directory(./src ELF_SRCS)
add_executable (tiny-ld "main.c" ${ELF_SRCS})


if(USE_TEST)
	message("use test")
	add_executable (test_elf_prase "test_elf_prase.c" ${ELF_SRCS})
endif(USE_TEST)