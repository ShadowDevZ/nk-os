#pragma once
//kernel attributes

#define KERNEL_STARTUP void
#define KERNEL_ENTRY void

#define NATIVECALL __attribute__((optimize("O0")))
#define CDECL __attribute__((cdecl))
#define PACKED __attribute__((packed))
#define NORET __attribute__((noreturn))
#define DEPRECATED __attribute__((deprecated))

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