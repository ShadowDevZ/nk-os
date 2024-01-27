#pragma once 

#include <stdint.h>

typedef struct
{
    uint16_t LimitLow;                  // limit (bits 0-15)
    uint16_t BaseLow;                   // base (bits 0-15)
    uint8_t BaseMiddle;                 // base (bits 16-23)
    uint8_t Access;                     // access
    uint8_t FlagsLimitHi;               // limit (bits 16-19) | flags
    uint8_t BaseHigh;                   // base (bits 24-31)
} __attribute__((packed)) GDTEntry;

typedef struct {
    uint16_t Limit;       // limit size of all GDT segments
    uint64_t BaseAddress;  // base address of the first GDT segment
} __attribute__((packed)) GDT;

typedef struct {
    uint16_t Length;
    uint16_t BaseLow;
    uint8_t  BaseMid;
    uint8_t  Flags1;
    uint8_t  Flags2;
    uint8_t  BaseHigh;
    uint32_t BaseTop;
    uint32_t _reserved;
}__attribute__((packed))TSSDescriptor;

#define GDT_DESC_COUNT 10

typedef struct {
    GDTEntry descriptor[GDT_DESC_COUNT];
    TSSDescriptor tss;
}__attribute__((packed))GDT_DESCRIPTORS;

typedef struct {
    uint32_t reserved0;
    uint64_t rsp[3];
    uint64_t reserved1;
    uint64_t ist[7];
    uint64_t reserved2;
    uint16_t reserved3;
    uint16_t iopbOffset;
}__attribute__((packed))TSS;



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

/* 

     7   	 6   5    	4    	3    	2    	1 	0
     P 	      DPL 	    S 	    E    	DC   	RW 	A
*/
//FOR CODE/DATA SEGMENTS
typedef enum {


    //**ACCESS BIT**//
    //A: bit 0
    GDTA_ACCESSED = 0x01,
    
    //**R/W BIT**//
    //RW: bit 1
    GDTA_CODE_R = 0x02,
    GDTA_DATA_W = 0x02,

    //**DIRECTION FLAG/CONFORMING FLAG**///
    //DC: bit 2
    GDTA_DATA_CF = 0x04,
    //**EXECUTE BIT**//
    //E: bit 3
    GDTA_CODE_EXE = 0x08,

    //**DESCRIPTOR TYPE**//
    //S: bit 4
    GDTA_DATA_SEGMENT = 0x10,
    GDTA_CODE_SEGMENT = 0x10,    
    GDTA_TSS_SEGMENT = 0x0,


    //**DPL**//
    //DPL: bits 5-6
    GDTA_RING0 = 0x0,
    GDTA_RING1 = 0x20,
    GDTA_RING2 = 0x40,
    GDTA_RING3 = 0x60,

    //**PRESENT**//
    //P: bit 7
    GDTA_PRESENT = 0x80


}GDT_ACCESS;



/*
    7 	6 	5 	4 	3 	2 	1 	0
    P    	DPL 	S 	Type

*/
//FOR SYSTEM SEGMENT USE (TSS)
typedef enum {

    //SYSSEG TYPE
    //bits 0-3
    

    //following entries are valid only in protected mode
    //probably useless in this case, left for backward compatibility
    GDTS_TYPE_TSS16_AVAIL = 0x1,
    GDTS_TYPE_TSS16_BUSY = 0x3,

    //available for protected/long mode use
    GDTS_TYPE_TSS_AVAIL = 0x9,
    GDTS_TYPE_TSS_BUSY = 0xB,
    GDTS_TYPE_LDT = 0x2,






    //**DECRIPTOR TYPE**//
    //S: bit 4
    //probably useless to define beacuse TSS is SYSSEG anyway
    GDTS_SYSSEG = 0x0,
    GDTS_CODE = 0x10,
    GDTS_DATA = 0x10,

    //**DPL**//
    //bits 5-6
    GDTS_RING0 = 0x0,
    GDTS_RING1 = 0x20,
    GDTS_RING2 = 0x40,
    GDTS_RING3 = 0x60,
    //**PRESENT BIT**//
    //bit 7
    GDTS_PRESENT = 0x80


}GDT_SYSSEG_ACCESS;

typedef enum {
    GDTF_LONGMODE = 0x20,
    GDTF_PROTMODE = 0x40,
    GDTF_REALMODE = 0x0,
    GDTF_GRAN4K = 0x80

}GDT_FLAGS;






extern void x64_gdt_flush(GDT* gdt, uint16_t soData, uint64_t soCode);
void SetGDTEntry(int16_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);



void InitializeGDT(void);
