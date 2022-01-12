cmake_minimum_required (VERSION 3.8)


#test 仅编译测试代码
#study 仅编译study代码
option (USE_TEST "do test" ON)
option (USE_STUDY "do study" ON)

project ("tind-ld")

add_subdirectory ("elf_prase")

if(USE_STUDY)
	add_subdirectory ("study")
endif(USE_STUDY)
