#include "kattributes.h"
#include "kstdio.h"
#include "ksyms.h"
#include "../arch/x86_64/include/io.h"
#include "sys/nkkerrr.h"
#include "../arch/x86_64/include/irq.h"
#include "operands.h"
#include "../hal/timer/include/uptime.h"
#include "../hal/keyboard/include/keyboard.h"
#include "../hal/keyboard/include/kbctl.h"
#include "memconv.h"
#include "mm/pmm.h"
#include "panic.h"
#include "mm/liballoc.h"
#include "limattr.h"
#include "../arch/x86_64/include/gdt.h"
#include "bitsets.h"






volatile struct limine_smbios_request smbios_request = {
    .id = LIMINE_SMBIOS_REQUEST,
    .revision = 0
};
#include "smbios.h"
#include "handlers.h"

KERNEL_ENTRY kmain() {
    BroadcastPrintf("\n");
    InitFaultHandlers();
    clrscr();
    
 
    printf("Kernel main reached at 0x%x\nPhysical address: 0x%x\n", kmain, ADDR_V2P(kmain));
    
    
     
    PmmInit(DEFAULT_PAGE_SIZE);
    
   // slab_init();
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
   
  clrscr();
    

   printf("FPU test: %f\n", 3.141592653589793);
 // asm("int $0xD");
    
   
   SMBIOS sm = {0};
    


    bool smret = InitSMBIOS(smbios_request.response, &sm);
    if (smret) {
        debugf("SMBIOS v%u.%u\n", sm.sm64.verMajor,sm.sm64.verMinor);

   // smbios_dump((SMBIOS_HEADER*)sm.sm64.tableAddr);
    

    

    SMBIOS_TABLE cputable = {0};
    GetSMBIOSTable(SMBIOS_TBL_CPU, &cputable);

    smbios_processor* cpu  = (smbios_processor*)cputable.table;
    debugf("\nManufacturer: [%s]\n", SmbiosGetStr(&cpu->hd, cpu->cpuManufacturer));
    debugf("Cpu speed %u Mhz\n", cpu->currentSpeed);
    debugf("Active cores %u\n", cpu->coreCount2);
    

   //smbios_dump((SMBIOS_HEADER*)&sm.sm64.tableAddr);
    }
    
   
    HIWORD(33333);
   IRQ_RegisterHandler(IRQ_KEYBOARD, _keyboardcb_);
 
    KeyboardInit();
   
  //  DebugPageFault(NULL);
    
  //  kusleep(3000); 
  //printf("\n");

  /**/
     uint64_t* a = kmalloc(sizeof(uint64_t));
    *a = 1337;
    printf("allocated var at 0x%x with size of %llu bytes\n", a, sizeof(a));
  
    printf("dereferenced %llu\n", *a);
    kfree(a);
    printf("value freed %llu\n ",*a);
   void* x = kmalloc(9999);
    kfree(x);
    
   // void* b = kmalloc(9999999);
   // kfree(b);
    
   int* aaa = kmalloc(sizeof(int));
    *aaa=10;
   int*  baa = kmalloc(sizeof(int));
    *baa = 11;
    SWAP(*aaa,*baa);
    printf("a:%d b:%d\nsw:\na: %db: %d\n", *aaa,*baa,*aaa,*baa);
    kfree(aaa);
    kfree(baa);
     
  

    debugf("CS: 0x%02x DS: 0x%02x TR: 0x%02x DPL: %d\n", x64_readcs(),x64_readds(),x64_readtr(), CS2DPL());
   
    
   

    // printf("working sleep %d\n", GetSystemTicks());
    printf("page size %lluKiB\n", GetKernelPageSize() / 1024);
    printf("RDTSC: %llu\n", x64_rdtsc());
   // printf("aaaaaaaaaaaaaa: %llu\n", GetSystemTicks());
   // printf("aaaaaaaaaaaaaa: %llu\n", GetSystemTicks());
   // DumpSymbolTable();
  //  BroadcastPrintf("%d\n", Fb_GetStreamType(FBDEV_DEFAULT));
   
   // asm("int $0x3");
    UNREACHABLE();
}