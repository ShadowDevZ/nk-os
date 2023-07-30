#include "sysdefs.h"
#include "kattributes.h"
#include "sys/version.h"
#include "kstdio.h"
KVER_BINFO GetBasicKernelVersion() {
    KVER_BINFO kb;
    kb.major = __KERNEL_VER_MAJOR;
    kb.minor = __KERNEL_VER_MINOR;
    kb.patch = __KERNEL_VER_PATCH;
    strncpy(kb.versionStr, __KERNEL_VERSION_STR, MAX_ELEM_VERLEN - 1);
    kb.versionStr[strlen(kb.versionStr)] = '\0';
    return kb;
    
}
KVER_INFO GetKernelVersion() {
    KVER_INFO ki;
    KVER_BINFO kb = GetBasicKernelVersion();
    ki.archType = __KERNEL_ARCH_INT;
    //this sucks but we dont have heap 
    strncpy(ki.buildDate, __KERNEL_BUILD_DATE, MAX_ELEM_VERLEN - 1);
    strncpy(ki.buildTime, __KERNEL_BUILD_TIME, MAX_ELEM_VERLEN - 1);
    strncpy(ki.ccVersion, __KERNEL_COMPILER_VERSION, MAX_ELEM_VERLEN - 1);
    strncpy(ki.codename, STRSTR(__KERNEL_CODENAME), MAX_ELEM_VERLEN - 1);
    strncpy(ki.kernelBase, STRSTR(__KERNEL_BASE), MAX_ELEM_VERLEN - 1);
    strncpy(ki.prefix, STRSTR(__KERNEL_PREFIX_CLASS), MAX_ELEM_VERLEN - 1);
    strncpy(ki.suffix, STRSTR(__KERNEL_SUFFIX), MAX_ELEM_VERLEN - 1);
    ki.version = &kb;
    ki.__reserved = NULL;

    return ki;
    
}