#include "kstdio.h"
#include "include/gdt.h"
#include "krnlcfg.h"
#define GDT_SEG_NULL 0
#define GDT_SEG_CODE16 1
#define GDT_SEG_DATA16 2
#define GDT_SEG_CODE32 3
#define GDT_SEG_DATA32 4
#define GDT_SEG_CODE64 5
#define GDT_SEG_DATA64 6
#define GDT_SEG_DATAUSR 7
#define GDT_SEG_CODEUSR 8
#define GDT_SEG_TSS 9
GDTEntry g_GDT[GDT_DESC_COUNT];
GDT_PTR g_GDT_PTR;
//reserved for future use
int g_GdtEntriesCount = 0;
void SetGDTEntry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {

    

    GDTEntry *this = &g_GDT[index];
    g_GdtEntriesCount++;
    this->LimitLow = limit & 0xFFFF;
    this->BaseLow = base & 0xFFFF;
    this->BaseMiddle = (base >> 16) & 0xFF;
    this->Access = access;

    this->FlagsLimitHi = (limit >> 16) & 0x0F;
    this->FlagsLimitHi = this->FlagsLimitHi | (gran & 0xF0);

    this->BaseHigh = (base >> 24 & 0xFF);


#if KF_GDT_DEBUG == 1
    switch (index)
    {
    case GDT_SEG_NULL:
        debugf("\tNULL segment ");
        break;
    case GDT_SEG_CODE16:
        debugf("\t16-bit code segment  ");
        break;    
    case GDT_SEG_DATA16:
        debugf("\t16-bit data segment  ");
        break;
    case GDT_SEG_CODE32:
        debugf("\t32-bit code segment  ");
        break;
    case GDT_SEG_DATA32:
        debugf("\t32-bit data segment  ");
        break;
    case GDT_SEG_CODE64:
        debugf("\t64-bit code segment  ");
        break;
    case GDT_SEG_DATA64:
        debugf("\t64-bit data segment  ");
        break;
    case GDT_SEG_CODEUSR:
        debugf("\tuser code segment    ");
        break;
    case GDT_SEG_DATAUSR:
        debugf("\tuser data segment    ");
        break;
    case GDT_SEG_TSS:
        debugf("\tTSS segment  ");
        break;
    
    default:
        break;
    } 

    debugf("GDT[%d]: BASE: 0x%x LIMIT: 0x%x ACCESS: 0x%x GRAN: 0x%x\n", index,
            base, limit, access, gran);

#endif 
}


//todo implement TSS next and interrupts

void gdt_init(void) {
  
#if KF_GDT_DEBUG == 1
    debugf("\n=====GDT DUMP BEGIN=====\n");
#endif
    
    
    g_GDT_PTR.limit = sizeof(g_GDT) - 1;
    g_GDT_PTR.base_address = (uint64_t)g_GDT;
//index, base, limit, access, grann


    //NULL segment
    SetGDTEntry(0, 0, 0, 0, 0); 
    //16-bit code segment
    SetGDTEntry(1, 0, 0xFFFF, 0x9a, 0x80);
     //16-bit data segment
    SetGDTEntry(2, 0, 0xFFFF, 0x92, 0x80);
    //32-bit code segment
    SetGDTEntry(3, 0, 0xFFFFFFFF, 0x9a, 0xcf);
    //32-bit data segment
    SetGDTEntry(4, 0, 0xFFFFFFFF, 0x92, 0xcf);
    //64-bit code segment
    SetGDTEntry(5, 0, 0, 0x9a, 0xa2);
    //64-bit data segment
    SetGDTEntry(6, 0, 0, 0x92, 0xa0);
    //user data segment 
    SetGDTEntry(7, 0, 0, 0xf2, 0);
    //user code segment
    SetGDTEntry(8, 0, 0, 0xfa, 0x20);
    //9 IS RESERVED FOR TSS

   

    gdt_flush(&g_GDT_PTR);
#if KF_GDT_DEBUG == 1
    debugf("\n======GDT DUMP END======\n");
#endif

    // 16-bit code descriptor (Entry 1)


}


