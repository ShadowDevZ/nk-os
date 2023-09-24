#include "kattributes.h"
#include "kstdio.h"
#include "ksyms.h"
#include "../arch/x86_64/include/io.h"
#include "sys/nkkerrr.h"

KERNEL_ENTRY kmain() {
    BroadcastPrintf("\n");
    printf("Kernel main reached at 0x%x\n", kmain);
    printf("FPU test: %f\n", 3.141592);
    #if KF_SYM_DUMP == 1
    SYM_ENUM_STATE st = {0};
     while (KsymEnumSymbol(&st)) {
        debugf("AD: 0x%llx NM: %s\n", st.list.addr, st.list.name); // Updated format specifiers
    }
    
    #endif
    debugf("bing bong\n");
    NkkSetLastSystemError(E_NKK_SUCCESS);
    printf(NkkGetLastErrorAsString());
   
    

  
    UNREACHABLE();
}