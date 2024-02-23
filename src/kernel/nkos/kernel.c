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




void PrintSysRegs() {
  GDT gdt = {0}; 
  IDT_DESCRIPTOR64 idt = {0};
  x64_sreg(X64_SREG_GDT,&gdt);
  x64_sreg(X64_SREG_IDT, &idt);
  debugf("\nGDTR\n  Limit: %hu\n  Addr: 0x%X\n", gdt.Limit, gdt.BaseAddress);
  debugf("\nIDTR\n  Limit: %hu\n  Addr: 0x%X\n", idt.limit, idt.base);


}


volatile struct limine_smbios_request smbios_request = {
    .id = LIMINE_SMBIOS_REQUEST,
    .revision = 0
};
#include "smbios.h"
#include "handlers.h"
#include "memconv.h"
#define KF_SYM_DUMP 1
KERNEL_ENTRY kmain() {
    BroadcastPrintf("\n");
    InitFaultHandlers();
   // clrscr();
    
    
 
    printf("Kernel main reached at 0x%x\nPhysical address: 0x%x\n", kmain, PmmPhys2Virt(kmain));
    
    
     
    PmmInit(DEFAULT_PAGE_SIZE);
    
  
   // PIT_Init(1000);
    #if KF_SYM_DUMP == 1
    SYM_ENUM_STATE st = {0};
     while (KsymEnumSymbol(&st)) {
       char* sub = strstr(st.list.name, "X64_I");
       if (!sub) {
          debugf("AD: 0x%llx NM: %s\n", st.list.addr, st.list.name); // Updated format specifiers
       }

        
    }
    printf("\n");
    #endif
   
 // clrscr();
    

   printf("FPU test: %f\n", 3.141592653589793);
 // asm("int $0xD");
    
   
   SMBIOS sm = {0};
    


    bool smret = InitSMBIOS(smbios_request.response, &sm);
    if (smret) {
        debugf("====SMBIOS v%u.%u dump start====\n", sm.sm64.verMajor,sm.sm64.verMinor);

   // smbios_dump((SMBIOS_HEADER*)sm.sm64.tableAddr);
    

    

    SMBIOS_TABLE cputable = {0};
    GetSMBIOSTable(SMBIOS_TBL_CPU, &cputable);

    smbios_processor* cpu  = (smbios_processor*)cputable.table;
    debugf("::CPU0 Information\n");
    debugf("  Manufacturer: [%s]\n", SmbiosGetStr(&cpu->hd, cpu->cpuManufacturer));
    debugf("  Cpu speed [%u] Mhz\n", cpu->currentSpeed);
    debugf("  Max speed [%u] Mhz\n", cpu->maxSpeed);
    debugf("  Active cores: %u\n", cpu->coreCount2);
    debugf("  Active threads: [%u]\n", cpu->threadCount2);
    debugf("  Characteristics: [%hu]\n", cpu->cpuCharacteristics);
    debugf("  Family [%u]\n", cpu->cpuFamily2);
    debugf("  Part name [%s]\n", SmbiosGetStr(&cpu->hd, cpu->partNum));
    debugf("  Serial number [%s]\n", SmbiosGetStr(&cpu->hd, cpu->serialNumber));
    debugf("  CPU Version [%s]\n", SmbiosGetStr(&cpu->hd, cpu->cpuVer));
    debugf("  Asset tag [%s]\n", SmbiosGetStr(&cpu->hd, cpu->assetTag));
    debugf("  Part name [%s]\n", SmbiosGetStr(&cpu->hd, cpu->cpuVer));
    debugf("  Cache L1 [%huB]\n", cpu->l1cacheHandle);
    debugf("  Cache L2 [%huB]\n", cpu->l2cacheHandle);
    debugf("  Cache L3 [%huB]\n", cpu->l3cacheHandle);
    debugf("Socket designation [%s]\n", SmbiosGetStr(&cpu->hd, cpu->socketDesignation));
    
    debugf("====SMBIOS v%u.%u dump end====\n\n", sm.sm64.verMajor,sm.sm64.verMinor);
    }
   
    
   IRQ_RegisterHandler(IRQ_KEYBOARD, _keyboardcb_);
 
    KeyboardInit();
   
  //  DebugPageFault(NULL);
    
  //  kusleep(3000); 

  

    debugf("CS: 0x%02x DS: 0x%02x TR: 0x%02x DPL: %d\n", x64_readcs(),x64_readds(),x64_readtr(), CS2DPL());
   
    
   

    // printf("working sleep %d\n", GetSystemTicks());
    printf("page size %lluKiB\n", GetKernelPageSize() / 1024);
    printf("RDTSC: %llu\n", x64_rdtsc());
   
    PrintSysRegs();
   
   // DumpSymbolTable();
  //  BroadcastPrintf("%d\n", Fb_GetStreamType(FBDEV_DEFAULT));
   
   // asm("int $0x3");
    UNREACHABLE();
}