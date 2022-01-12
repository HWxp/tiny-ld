#ifndef __COMMON__
#define __COMMON__

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

extern void __debug(const char* buf);
extern void __error(const char* buf);

#define _debug(...)\
 do{ char buf[8192]; snprintf(buf, 8192,__VA_ARGS__);  __debug(buf);}while(0)

#define _error(...)\
 do{ char buf[8192]; snprintf(buf, 8192,__VA_ARGS__);  __error(buf);}while(0)

#define t_debug _debug
#define t_error _error

#define t_assert(x, ret)\
do{\
if(!(x)){\
	t_error("%s,%s,%d, err:%s, %s",__FILE__, __FUNCTION__, __LINE__, strerror(errno), #x);\
	return ret;\
}\
}while(0);

#define t_assert_handle(x, ret, handle)\
do{\
if(!(x)){\
	t_error("%s,%s,%d, err:%s, %s",__FILE__, __FUNCTION__, __LINE__, strerror(errno), #x);\
	handle;\
	return ret;\
}\
}while(0);


extern void* t_malloc(size_t size);
extern int t_free(void* ptr);

#define t_align(src, align_size) (((src) + align_size - 1) & ~(align_size - 1))

#endif