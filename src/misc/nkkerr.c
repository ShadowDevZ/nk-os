#include "nkkerrr.h"

char *nkkerrstr[] = {
  [E_NKK_SUCCESS] =   "The operation was successfully completed",
  [E_NKK_FAIL] = "Unexpected error",
  [E_NKK_INTERNAL] =  "Internal error",
  [E_NKK_IOFAIL] =  "IO operation has failed",
  [E_NKK_HALFAIL] =  "HAL device failed to load correctly",
  [E_NKK_UNSPECIFIED] =  "Unspecified error",
  [E_NKK_NOMEM] =  "No memory available",
  [E_NKK_NODISK] =  "No available disks found",
  [E_NKK_DRIVER_ERROR] =  "External kernel driver encountered an error",
  [E_NKK_NULL_DESCRIPTOR] =  "Tried to access invalid descriptor",
  [E_NKK_FS_BADNAME] =  "Use of illegal characters in a filename",
  [E_NKK_ACCESS_DENIED] =  "Acess denied",
  [E_NKK_HOOK_FAIL] =  "Failed to call kernel registered hook",
  [E_NKK_MEMFAIL] =  "Memory acess error",
  [E_NKK_FUN_NI] =  "Function not implemented",
  [E_NKK_NOFILE] =  "No such file or directory",
  [E_NKK_RESVMEM] =  "Tried to acess already reserved memory region",
  [E_NKK_INVALID_ARG] =  "Invalid argument passed to a function",
  [E_NKK_OP_CANCELLED] =  "Operation cancelled by usermode",
  [E_NKK_FILE_EXISTS] =  "File already exists",
  [E_NKK_RSC_LOCKED] =  "System resource is locked by system",
  [E_NKK_DBG_BREAKPOINT] =  "Debugger breakpoint",
  [E_NKK_BADBOOT] =  "Bad information passed by bootloader",
  [E_NKK_NOSPACE] =  "No space left on a disk",
  [E_NKK_IRQ_FAIL] =  "IRQ was handled improperly",
  [E_NKK_UNHANDLED_ISR] =  "ISR was unhandled",
  [E_NKK_DESC_SYS_RESV] =  "Tried to access system file descriptor",
  [E_NKK_INVALID_ERR] =  "Invalid system error code"
    

};

nkkerr_t _nkkerr_ = E_NKK_UNSPECIFIED;

nkkerr_t NkkGetLastKernelError() {
    return _nkkerr_;
}
char* NkkTranslateError(nkkerr_t err) {
    uint64_t arlen = sizeof(nkkerrstr)/sizeof(nkkerrstr[0]);
    if (err >= arlen) {
        return "Invalid system error code";
    }
    return nkkerrstr[err];

}
bool NkkSetLastSystemError(nkkerr_t err) {
     uint64_t arlen = sizeof(nkkerrstr)/sizeof(nkkerrstr[0]);
    if (err >= arlen) {
        return false;
    }
    _nkkerr_ = err;

    
    return true;

}



