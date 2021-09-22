#ifndef __COMMON__
#define __COMMON__

#include<stdio.h>
#include<errno.h>
#include<linux/version.h>

inline void __debug(const char* buf) {
	printf("[debug]:%s\n", buf);
}

inline void __error(const char* buf) {
	printf("[error]:%s\n", buf);
}

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

#define __make_string(L) #L 
#define __value(s) __make_string(s)
#define __log "log: "
#define __warn "warn: "


//tld 的版本
#define VERSION "1.0"
#pragma message (__log __make_string(VERSION)"=" __value(VERSION))

#pragma message (__log __make_string(EI_NIDENT)"=" __value(EI_NIDENT))

//编译器64位 OR 32位
#if __GNUC__
#pragma message(__log "__GNUC__")

#if __x86_64__
#pragma message(__log "__x86_64__") 
#define ENV64

#else
#pragma message(__log "env 32") 
#define ENV32
#endif

#else
#pragma message(__warn "NOT __GNUC__")
#endif

//CPU架构
#if __INTEL__
#pragma message(__log "__INTEL__")

#if _M_IX86
#pragma message(__log "_M_IX86")

#elif __i386__
#pragma message(__log "__i386__")

#elif __ia64__ || __IA64__ 
#pragma message(__log "__ia64__")
#endif
#endif

#if __amd__64__
#pragma message(__log "__amd__64__")
#endif

#if LINUX_VERSION_CODE == KERNEL_VERSION(2,6,32)
#pragma message(__log "2.6.32")
#else
#pragma message(__warn "you should make sure the kernel is right version : " __value(LINUX_VERSION_CODE))
#endif