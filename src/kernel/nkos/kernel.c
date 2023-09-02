#include "kattributes.h"
#include "kstdio.h"
KERNEL_ENTRY kmain() {
    printf("\n");
    printf("Kernel main reached at 0x%x\n", kmain);




    UNREACHABLE();
}