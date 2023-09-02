#include "kattributes.h"
#include "kstdio.h"
#include "ksyms.h"
KERNEL_ENTRY kmain() {
    printf("\n");
    printf("Kernel main reached at 0x%x\n", kmain);
     SYM_ENUM_STATE st = {0};
     while (KsymEnumSymbol(&st)) {
        debugf("AD: 0x%llx NM: %s\n", st.list.addr, st.list.name); // Updated format specifiers
    }
    debugf("bing bong\n");

    UNREACHABLE();
}