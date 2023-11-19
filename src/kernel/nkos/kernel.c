#include "kattributes.h"
#include "kstdio.h"
#include "ksyms.h"
#include "../arch/x86_64/include/io.h"
#include "sys/nkkerrr.h"
#include "../arch/x86_64/include/irq.h"

#include "../hal/timer/include/uptime.h"
#include "../hal/keyboard/include/keyboard.h"
#include "../hal/keyboard/include/kbctl.h"
#include "memconv.h"


KERNEL_ENTRY kmain() {
    BroadcastPrintf("\n");
    clrscr();
    printf("Kernel main reached at 0x%x\nPhysical address: 0x%x\n", kmain, ADDR_V2P(kmain));
   
    #if KF_SYM_DUMP == 1
    SYM_ENUM_STATE st = {0};
     while (KsymEnumSymbol(&st)) {
        debugf("AD: 0x%llx NM: %s\n", st.list.addr, st.list.name); // Updated format specifiers
    }
    
    #endif
    debugf("bing bong\n");
    NkkSetLastSystemError(E_NKK_SUCCESS);
    printf("%s\n",NkkGetLastErrorAsString());
    
    

  
  asm ("sti");

   printf("FPU test: %f\n", 3.141592);
 // asm("int $0xD");
 
  
  PIT_Init(1000);

   IRQ_RegisterHandler(1, _keyboardcb_);
 
    KeyboardInit();
    
    
    
    //kusleep(1000);
   
    printf("working sleep\n");
  
  x64_pgon();
    UNREACHABLE();
}