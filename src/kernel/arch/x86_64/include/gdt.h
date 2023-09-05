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
    uint16_t limit;       // limit size of all GDT segments
    uint64_t base_address;  // base address of the first GDT segment
} __attribute__((packed)) GDT_PTR;


#define GDT_DESC_COUNT 10

void SetGDTEntry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
void GDT_Init();


void gdt_init(void);
