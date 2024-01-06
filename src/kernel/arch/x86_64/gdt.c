#include "kstdio.h"
#include "include/gdt.h"
#include "krnlcfg.h"
#include "bitsets.h"
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
GDT g_KGDT;
//reserved for future use
#define GDT_ENTRY_MAX 8192
int16_t g_GdtEntriesCount = 0;

//defines the ACCESS BYTE, intel volume 3a table 3.1  code and data segment types
/*
definitions from intel manual

expand down: Expand-down data segment. The flag is called the B flag and it specifies the upper bound of
the segment. If the flag is set, the upper bound is FFFFFFFFH (4 GBytes); if the flag is clear, the
upper bound is FFFFH (64 KBytes)

Code segments can be either conforming or nonconforming. A transfer of execution into a more-privileged
conforming segment allows execution to continue at the current privilege level. A transfer into a nonconforming
segment at a different privilege level results in a general-protection exception (#GP), unless a call gate or task gate
is used
*/
//there are more additional ones like data direction if segment grows downward or upward but its useless in this case
typedef enum {
  /*  
    //data
    GDTA_DATA_R = 0,             //read only
    GDTA_DATA_RA = 1,           //read only, accessed
    GDTA_DATA_RW = 2,           //read write
    GDTA_DATA_RWA = 3,          //read write, accessed
    GDTA_DATA_RE = 4,        //read, expand down
    GDTA_DATA_RE = 5,       //read expand down, accessed
    GDTA_DATA_RWE = 6,       //read write,expand down
    GDTA_DATA_RWEA = 7,      //read write expand down, accessed
    
    //code

    GDTA_CODE_X = 8,        //execute
    GDTA_CODE_XA = 9,       //execute, accessed
    GDTA_CODE_RX = 10,      //read execute
    GDTA_CODE_RXA = 11,     //read execute, accessed
    GDTA_CODE_XC = 12,      //execute, conforming      
    GDTA_CODE_XCA = 13,     //execute conforming accessed
    GDTA_CODE_RXC = 14,     //read execute, conforming
    GDTA_CODE_RXCA = 15     //read exeture, conforming, accessed
*/
    GDTA_CODE_R = 0x02,
    GDTA_DATA_W = 0x02,
    GDTA_DATA_CF = 0x04
    ,
    GDTA_DATA_SEGMENT = 0x10,
    GDTA_CODE_SEGMENT = 0x18,
    GDTA_TSS_SEGMENT = 0x0,

    GDTA_RING0 = 0x0,
    GDTA_RING1 = 0x20,
    GDTA_RING2 = 0x40,
    GDTA_RING3 = 0x60,

    GDTA_PRESENT = 0x80


}GDT_ACCESS;

typedef enum {
    GDTF_LONGMODE = 0x20,
    GDTF_PROTMODE = 0x40,
    GDTF_REALMODE = 0x0,
    GDTF_GRAN4K = 0x80

}GDT_FLAGS;

void SetGDTEntry(int16_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {

    

    GDTEntry* gdt = &g_GDT[index];
    g_GdtEntriesCount++;
    gdt->LimitLow = LOWORD(limit);
    gdt->BaseLow = LOWORD(base);
    gdt->BaseMiddle = (base >> 16) & 0xFF;
    gdt->Access = access;

    gdt->FlagsLimitHi = ((limit >> 16) & 0x0F) | (flags & 0xF0);
    gdt->BaseHigh = (base >> 24 & 0xFF);


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

void InitializeGDT(void) {
  
#if KF_GDT_DEBUG == 1
    debugf("\n=====GDT DUMP BEGIN=====\n");
#endif
    
    
    g_KGDT.limit = sizeof(g_GDT) - 1;
    g_KGDT.base_address = (uint64_t)g_GDT;
//index, base, limit, access, grann









    //DO NOT REARRANGE THE ENTRIES, THINGS WILL BREAK
    //NULL segment 0x0
    SetGDTEntry(GDT_SEG_NULL, 0, 0, 0, 0); 
    //16-bit code segment 0x8
    SetGDTEntry(GDT_SEG_CODE16, 0, UINT16_MAX, GDTA_CODE_R|GDTA_PRESENT|GDTA_CODE_SEGMENT, GDTF_GRAN4K);
     //16-bit data segment 0x10
    SetGDTEntry(GDT_SEG_DATA16, 0, UINT16_MAX, GDTA_DATA_W | GDTA_PRESENT | GDTA_DATA_SEGMENT, GDTF_GRAN4K);
    //32-bit code segment 0x18
    SetGDTEntry(GDT_SEG_CODE32, 0, UINT32_MAX, GDTA_CODE_R|GDTA_PRESENT|GDTA_CODE_SEGMENT, GDTF_PROTMODE | GDTF_GRAN4K);
    //32-bit data segment 0x20
    SetGDTEntry(GDT_SEG_DATA32, 0, UINT32_MAX, GDTA_DATA_W | GDTA_PRESENT | GDTA_DATA_SEGMENT, GDTF_PROTMODE | GDTF_GRAN4K);
    //64-bit code segment 0x28
    SetGDTEntry(GDT_SEG_CODE64, 0, 0, GDTA_CODE_R|GDTA_PRESENT|GDTA_CODE_SEGMENT, GDTF_GRAN4K | GDTF_LONGMODE);
    //64-bit data segment 0x30
    SetGDTEntry(GDT_SEG_DATA64, 0, 0, GDTA_DATA_W | GDTA_PRESENT | GDTA_DATA_SEGMENT, GDTF_GRAN4K | GDTF_LONGMODE);
    //user data segment  0x38
    SetGDTEntry(GDT_SEG_DATAUSR, 0, 0, GDTA_PRESENT | GDTA_DATA_SEGMENT | GDTA_DATA_W |GDTA_RING3, GDTF_GRAN4K | GDTF_LONGMODE);
    //user code segment 0x40
    SetGDTEntry(GDT_SEG_CODEUSR, 0, 0, GDTA_PRESENT | GDTA_CODE_SEGMENT | GDTA_DATA_W |GDTA_RING3, GDTF_GRAN4K | GDTF_LONGMODE);
    //9 IS RESERVED FOR TSS 0x48

   

    x64_gdt_flush(&g_KGDT);
#if KF_GDT_DEBUG == 1
    debugf("\n======GDT DUMP END======\n");
#endif

    // 16-bit code descriptor (Entry 1)


}


