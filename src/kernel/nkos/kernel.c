#include "/home/shadow/Projects/OperatingSystems/nkos/src/kernel/include/kattributes.h"
#include "kstdio.h"
KERNEL_ENTRY kmain() {
    printf("\n");
    printf("Kernel main reached at 0x%x\n", kmain);




    UNREACHABLE();
}