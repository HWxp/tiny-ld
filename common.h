#ifndef __COMMON__
#define __COMMON__
#include<linux/version.h>

#define __make_string(L) #L 
#define __value(s) __make_string(s)
#define __$line __value(__LINE__)

#define __log "log: "
#define __warn "warn: "


//tld 的版本
#define VERSION "1.0"
#pragma message (__log __make_string(VERSION)"=" __value(VERSION))

//elf header e_ident[EI_NIDENT]
#pragma message (__log __make_string(EI_NIDENT)"=" __value(EI_NIDENT))


//编译器64位OR 32位
#if __GNUC__
#pragma message(__log "gnu c")

#if __x86_64__
#pragma message(__log "__x86_64__") 
#define ENV64

#else
#pragma message(__log "env 32") 
#define ENV32
#endif
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

//linux 版本
#if LINUX_VERSION_CODE == KERNEL_VERSION(2,6,32)
#pragma message(__log "2.6.32")
#else
#pragma message(__warn "you should make sure the kernel is right version")
#endif

#include<stdio.h>
inline void _ldebug(char* buf) {
	printf("Debug %s\n", buf);
}

inline void _lerror(char* buf) {
	printf("Error %s\n", buf);
}

#define lerror(...)\
 do{ char buf[8192]; snprintf(buf, 8192,__VA_ARGS__);  _lerror(buf);}while(0)

#define ldebug(...)\
 do{ char buf[8192]; snprintf(buf, 8192,__VA_ARGS__);  _ldebug(buf);}while(0)

#define e_error lerror
#define e_debug ldebug

#include<errno.h>
#include<string.h>
#define e_assert(x, ret)\
do{\
if(!(x)){\
	e_error("%s,%s,%d, err:%s, %s",__FILE__, __FUNCTION__, __LINE__, strerror(errno), #x);\
	return ret;\
}\
}while(0);

#define e_assert_handle(x, ret, handle)\
do{\
if(!(x)){\
	e_error("%s,%s,%d, err:%s, %s",__FILE__, __FUNCTION__, __LINE__, strerror(errno), #x);\
	handle;\
	return ret;\
}\
}while(0);
#endif
