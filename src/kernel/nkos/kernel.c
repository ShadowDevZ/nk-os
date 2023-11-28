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
#include "mm/pmm.h"

#include "mm/slab.h"
void page_fault_handler(isr_state_t* regs)
{
    uint64_t faulting_address;
    __asm__ __volatile__("movq %%cr2, %0" : "=r" (faulting_address));

    int32_t present = !(regs->error_code & 0x1);
    int32_t rw = regs->error_code & 0x2;
    int32_t us = regs->error_code & 0x4;
    int32_t reserved = regs->error_code & 0x8;
    int32_t id = regs->error_code & 0x10;

    puts("Page fault! ( ");
    if (present)
        puts("present ");
    if (rw)
        puts("read-only ");
    if (us)
        puts("user-mode ");
    if (reserved)
        puts("reserved ");
    puts(") at ");
    printf("%p",faulting_address);
    puts("\n");
    x64_panic();
    
   // panicf("PAGING","Page fault");
}


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
    ISR_RegisterHandler(14, page_fault_handler);
    

  
  asm ("sti");

   printf("FPU test: %f\n", 3.141592);
 // asm("int $0xD");
  pmm_init();
   // slab_init();
   // int* a = slab_alloc(sizeof(int));
   // *a = 1337;
   // printf("%d\n", *a);
  //  slab_free(a);
  
   PIT_Init(1000);

   IRQ_RegisterHandler(1, _keyboardcb_);
 
    KeyboardInit();
   
    
    
    kusleep(3000); 
    
     printf("working sleep %d\n", GetSystemTicks());
   
   
   
   // BroadcastPrintf("%d\n", Fb_GetStreamType(FBDEV_DEFAULT));
   
  //  asm("int $0x3");
    UNREACHABLE();
}