#pragma once
#include <stdint.h>
//kernel attributes

#define KERNEL_STARTUP void
//#define KERNEL_ENTRY void

typedef int _KERNEL_ENTRY;
#define KERNEL_ENTRY __attribute__((section(".kernel64"))) int

#define NATIVECALL __attribute__((optimize("O0")))
#define PACKED __attribute__((packed))
#define NORET __attribute__((noreturn))
#define DEPRECATED __attribute__((deprecated))
#define UNREACHABLE() for (;;);
// custom attributes
#define INTERNAL
#define EXTERNAL
#define DEBUG_ONLY
#define SYSCALL
// SAL ANNOTATIONS
#define _in_
#define _in_optional_

#define _out_
#define _out_optional_

#define _in_out_
#define _in_out_optional_

#define _unused_
#define _reserved_

KERNEL_ENTRY kmain();