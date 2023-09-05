#pragma once

#include <stdint.h>
#include "sysdefs.h"

typedef uint64_t nkkerr_t;

enum NKKErrorCodes {
    E_NKK_SUCCESS = 0,
    E_NKK_FAIL = 1,
    E_NKK_INTERNAL= 2,
    E_NKK_IOFAIL=3,
    E_NKK_HALFAIL=4,
    E_NKK_UNSPECIFIED=5,
    E_NKK_NOMEM=6,
    E_NKK_NODISK=7,
    E_NKK_DRIVER_ERROR=8,
    E_NKK_NULL_DESCRIPTOR =9,
    E_NKK_FS_BADNAME=10,
    E_NKK_ACCESS_DENIED,
    E_NKK_HOOK_FAIL,
    E_NKK_MEMFAIL,
    E_NKK_FUN_NI,
    E_NKK_NOFILE,
    E_NKK_RESVMEM,
    E_NKK_INVALID_ARG,
    E_NKK_OP_CANCELLED,
    E_NKK_FILE_EXISTS,
    E_NKK_RSC_LOCKED,
    E_NKK_DBG_BREAKPOINT,
    E_NKK_BADBOOT,
    E_NKK_NOSPACE,
    E_NKK_IRQ_FAIL,
    E_NKK_UNHANDLED_ISR,
    E_NKK_DESC_SYS_RESV,
    E_NKK_INVALID_ERR
};

char* NkkTranslateError(nkkerr_t err);

nkkerr_t NkkGetLastKernelError();

bool NkkSetLastSystemError(nkkerr_t err);

#define NkkGetLastErrorAsString() NkkTranslateError(NkkGetLastKernelError())