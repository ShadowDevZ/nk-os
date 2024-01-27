#include "kstdio.h"
#include "include/gdt.h"
#include "krnlcfg.h"
#include "bitsets.h"
#include "io.h"
#define GDT_SEG_NULL 0
#define GDT_SEG_CODE16 1
#define GDT_SEG_DATA16 2
#define GDT_SEG_CODE32 3
#define GDT_SEG_DATA32 4
#define GDT_SEG_CODE64 5
#define GDT_SEG_DATA64 6
#define GDT_SEG_CODEUSR 7
#define GDT_SEG_DATAUSR 8
#define GDT_SEG_TSS 9
GDT_DESCRIPTORS g_Pack;

//reserved for future use

int16_t g_GdtEntriesCount = 0;


void SetGDTEntry(int16_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {

   
    g_Pack.descriptor[index].LimitLow = LOWORD(limit);
    g_Pack.descriptor[index].BaseLow = LOWORD(base);
    g_Pack.descriptor[index].BaseMiddle = (base >> 16) & 0xFF;
    g_Pack.descriptor[index].Access = access;
    g_Pack.descriptor[index].FlagsLimitHi = ((limit >> 16) & 0x0F) | (flags & 0xF0);
    g_Pack.descriptor[index].BaseHigh = (base >> 24 & 0xFF);
    g_GdtEntriesCount++;

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

uint8_t TssStack[0xFFFFF];
uint8_t ist1Stack[0xFFFFF];
TSS g_Tss;
uint64_t rsp0;

#define GDTA_CODE_ENTRY (GDTA_CODE_R|GDTA_PRESENT|GDTA_CODE_SEGMENT|GDTA_CODE_EXE)
#define GDTA_DATA_ENTRY (GDTA_DATA_W | GDTA_PRESENT | GDTA_DATA_SEGMENT)
#define GDTA_TSS_ENTRY (GDTS_PRESENT|GDTS_SYSSEG|GDTS_TYPE_TSS_AVAIL|GDTS_RING0)
void InitializeGDT(void) {
  
#if KF_GDT_DEBUG == 1
    debugf("\n=====GDT DUMP BEGIN=====\n");
#endif
    GDT g_KGDT;
    
    g_KGDT.Limit = sizeof(g_Pack) - 1;
    g_KGDT.BaseAddress = (uint64_t)&g_Pack;
//index, base, limit, access, grann









    //DO NOT REARRANGE THE ENTRIES, THINGS WILL BREAK
    //NULL segment 0x0
    SetGDTEntry(GDT_SEG_NULL, 0, 0, 0, 0); 
    //16-bit code segment 0x8
    SetGDTEntry(GDT_SEG_CODE16, 0, UINT16_MAX, GDTA_CODE_ENTRY, GDTF_GRAN4K);
     //16-bit data segment 0x10
    SetGDTEntry(GDT_SEG_DATA16, 0, UINT16_MAX, GDTA_DATA_ENTRY, GDTF_GRAN4K);
    //32-bit code segment 0x18
    SetGDTEntry(GDT_SEG_CODE32, 0, UINT32_MAX, GDTA_CODE_ENTRY, GDTF_PROTMODE | GDTF_GRAN4K);
    //32-bit data segment 0x20
    SetGDTEntry(GDT_SEG_DATA32, 0, UINT32_MAX, GDTA_DATA_ENTRY, GDTF_PROTMODE | GDTF_GRAN4K);
    //64-bit code segment 0x28
    SetGDTEntry(GDT_SEG_CODE64, 0, 0, GDTA_CODE_ENTRY, GDTF_GRAN4K | GDTF_LONGMODE);
    //64-bit data segment 0x30
    SetGDTEntry(GDT_SEG_DATA64, 0, 0, GDTA_DATA_ENTRY, GDTF_GRAN4K | GDTF_LONGMODE);
    //user code segment  0x38
    SetGDTEntry(GDT_SEG_CODEUSR, 0, 0, GDTA_CODE_ENTRY | GDTA_RING3, GDTF_GRAN4K | GDTF_LONGMODE);
    //user data segment 0x40
    SetGDTEntry(GDT_SEG_DATAUSR, 0, 0, GDTA_DATA_ENTRY | GDTA_RING3, GDTF_GRAN4K | GDTF_LONGMODE);
    //tss system segment 0x48
    
    SetGDTEntry(GDT_SEG_TSS, (uint64_t)&g_Tss, sizeof(g_Tss), GDTA_TSS_ENTRY, 0);
    memset(&g_Tss, 0, sizeof(g_Tss));
  

    g_Tss.rsp[0] = (uint64_t)TssStack + sizeof(TssStack);
    g_Tss.ist[0] = (uint64_t)ist1Stack + sizeof(ist1Stack);
    
    rsp0 = g_Tss.rsp[0];



    x64_gdt_flush(&g_KGDT, 0x30, 0x28);
    x64_tss_flush(0x48);
#if KF_GDT_DEBUG == 1
    debugf("\n======GDT DUMP END======\n");
#endif

    // 16-bit code descriptor (Entry 1)


}


