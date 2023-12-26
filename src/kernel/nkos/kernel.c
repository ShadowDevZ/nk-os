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
#include "panic.h"
#include "mm/slab.h"
#include "panic.h"
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

    printf(") at %p\n",faulting_address);
    printf("%llu", faulting_address);
    x64_panic();
    
   // panicf("PAGING","Page fault");
}
void gpf_handler(isr_state_t* regs) {
    printf("General protection fault\n");
        //if it is segment related
    if (regs->error_code > 0) {
      int32_t external = (regs->error_code & 1);
      int32_t tbl = ((regs->error_code >> 1) & 0x3);
      int32_t index = ((regs->error_code >> 3) & 0x1fff);

      if (external)
          puts("External cpu exception")
       if (tbl) {
            puts("CPU table exception: \n");
         puts("\tTable: (");
         switch (tbl) {
              case 0b00:
                   puts("GDT ");
                   break;
                case 0b01:
              case 0b11:
                   puts("IDT ");
                 break;
             case 0b10:
                  puts("LDT ");
                   break;
              default:
                  puts("UNKWN ");
                  break;

            
         }

           printf(")Index: %d, Selector 0o%o\n" + index);
       }
    }


    PrintRegs(regs);

     
    x64_panic();
}

typedef void (*cab());

KERNEL_ENTRY kmain() {
    BroadcastPrintf("\n");
    clrscr();
    
    printf("Kernel main reached at 0x%x\nPhysical address: 0x%x\n", kmain, ADDR_V2P(kmain));
    ISR_RegisterHandler(14, page_fault_handler);
    ISR_RegisterHandler(13, gpf_handler);
    
    
    pmm_init(DEFAULT_PAGE_SIZE);
    
    slab_init();
   // PIT_Init(1000);
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
    
   
    
      
  
   

   IRQ_RegisterHandler(1, _keyboardcb_);
 
    KeyboardInit();
   
  //  DebugPageFault(NULL);
    
  //  kusleep(3000); 
  //printf("\n");

  
     int* a = slab_alloc(sizeof(int));
    *a = 1337;
    printf("allocated var at 0x%x with size of %llu bytes\n", a, sizeof(int));
    printf("dereferenced %d\n", *a);
    slab_free(a);
    printf("value freed\n");
    
    PIT_Init(1000);

     printf("working sleep %d\n", GetSystemTicks());
    printf("page:size %llu\n", GetKernelPageSize());
    
    
  //  BroadcastPrintf("%d\n", Fb_GetStreamType(FBDEV_DEFAULT));
   
  //  asm("int $0x3");
    UNREACHABLE();
}