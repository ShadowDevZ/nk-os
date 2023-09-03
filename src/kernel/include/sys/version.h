#pragma once
#include <sysdefs.h>
//todo move it somewhere, maybe autopublisher
#define KMODE_DBG 1


#define macro_conc(str1, ...) #str1 " " #__VA_ARGS__
#define STR(...) #__VA_ARGS__
#define STRSTR(...) STR(__VA_ARGS__)

#define __KERNEL_BASE "nk"
#define __KERNEL_CODENAME "icefox"
#define __KERNEL_VER_MAJOR 0
#define __KERNEL_VER_MINOR 1
#define __KERNEL_VER_PATCH 1

#define __KERNEL_ARCH x86_64
#if __KERNEL_ARCH == x86_64
#define __KERNEL_ARCH_INT 64
#endif

#define __KERNEL_PREFIX_CLASS "dev"

#define __KERNEL_CROSSCC "gcc"

#define __KERNEL_COMPILER_VERSION STRSTR(__KERNEL_CROSSCC) " " __VERSION__

#define __KERNEL_SUFFIX "DEBUG"

#if KMODE_DBG == 1 
#define __KERNEL_SUFFIX "DEBUG"
#else
#define __KERNEL_SUFFIX "RELEASE"
#endif



//looks ugly but its enough for now
#define __KERNEL_VERSION_STR STRSTR(__KERNEL_VER_MAJOR.__KERNEL_VER_MINOR.__KERNEL_VER_PATCH)

#define __KERNEL_CLASS_TYPE STRSTR(__KERNEL_PREFIX_CLASS) "/" STRSTR(__KERNEL_BASE)  "-" STRSTR(__KERNEL_CODENAME) 

#define __KERNEL_BUILD_DATE __DATE__
#define __KERNEL_BUILD_TIME __TIME__



//#define __KERNEL_FULL_NAME __KERNEL_CLASS_TYPE " " "(" STRSTR(__KERNEL_ARCH) ") " "[" __KERNEL_VERSION_STR "] "  STRSTR(__KERNEL_SUFFIX) " "

#define MAX_ELEM_VERLEN 80

typedef struct {
    uint major;
    uint minor;
    uint patch;
    char versionStr[MAX_ELEM_VERLEN];
}KVER_BINFO;

typedef struct{
    char kernelBase[MAX_ELEM_VERLEN];
    char codename[MAX_ELEM_VERLEN];
    int archType;
    char prefix[MAX_ELEM_VERLEN];
    char suffix[MAX_ELEM_VERLEN];
    char ccVersion[MAX_ELEM_VERLEN];
    char buildDate[MAX_ELEM_VERLEN];
    char buildTime[MAX_ELEM_VERLEN];
    void* __reserved; 
    KVER_BINFO* version;

}KVER_INFO;

KVER_INFO GetKernelVersion();
KVER_BINFO GetBasicKernelVersion();