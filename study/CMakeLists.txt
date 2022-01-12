cmake_minimum_required (VERSION 3.8)


include_directories("include")
aux_source_directory(./src SRCS)


if(USE_STUDY)
	message("use study")
	add_executable (relocations "relocations.cc" ${SRCS})
	add_executable (sections "sections.cc" ${SRCS})
	add_executable (segments "segments.cc" ${SRCS})
	add_executable (symbols "symbols.cc" ${SRCS})
endif(USE_STUDY)