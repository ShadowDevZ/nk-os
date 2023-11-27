#include "sysdefs.h"
#include "kattributes.h"
#include "sys/version.h"
#include "kstdio.h"

#define VERCPY(dst, src) \
snprintf(dst, MAX_ELEM_VERLEN - 1, "%s", (const char*)src)

KVER_BINFO GetBasicKernelVersion() {
    KVER_BINFO kb;
    kb.major = __KERNEL_VER_MAJOR;
    kb.minor = __KERNEL_VER_MINOR;
    kb.patch = __KERNEL_VER_PATCH;

    //snprintf(kb.versionStr, MAX_ELEM_VERLEN - 1, __KERNEL_VERSION_STR);
   // VERCPY(kb.versionStr, __KERNEL_FULL_NAME);
   // strncpy(kb.versionStr, __KERNEL_VERSION_STR, MAX_ELEM_VERLEN - 1);
   // kb.versionStr[strlen(kb.versionStr)] = '\0';
    return kb;
    
}
KVER_INFO GetKernelVersion() {
    KVER_INFO ki;
   KVER_BINFO kb = GetBasicKernelVersion();
    ki.archType = __KERNEL_ARCH_INT;
    VERCPY(ki.buildDate, __KERNEL_BUILD_DATE);
    VERCPY(ki.buildTime, __KERNEL_BUILD_TIME);
    VERCPY(ki.ccVersion, __KERNEL_COMPILER_VERSION);
    VERCPY(ki.codename, __KERNEL_CODENAME);
    VERCPY(ki.kernelBase, __KERNEL_BASE);
    VERCPY(ki.prefix, __KERNEL_PREFIX_CLASS);
    VERCPY(ki.suffix, __KERNEL_SUFFIX);
   // VERCPY(ki.version->versionStr, NULLSTR);

    
    
   
    
   // snprintf(ki.buildDate, MAX_ELEM_VERLEN - 1, __KERNEL_BUILD_DATE);
    
    
    ki.version = &kb;
    ki.__reserved = NULL;

    return ki;
    
}