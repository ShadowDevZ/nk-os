#pragma once
#include "kattributes.h"
typedef struct {
    uint16_t isrLow;
    uint16_t kernelCs;
    uint8_t	    ist;          
	uint8_t     attributes;   
	uint16_t    isrMid;      
	uint32_t    isrHigh;    
	uint32_t    reserved; 

}PACKED IDT_ENTRY64;

typedef struct {
    uint16_t limit;
    uint64_t base;

}PACKED IDT_DESCRIPTOR64;

typedef enum
{
    IDT_FLAG_GATE_TASK              = 0x5,
    IDT_FLAG_GATE_16BIT_INT         = 0x6,
    IDT_FLAG_GATE_16BIT_TRAP        = 0x7,
    IDT_FLAG_GATE_32BIT_INT         = 0xE,
    IDT_FLAG_GATE_32BIT_TRAP        = 0xF,

    IDT_FLAG_RING0                  = (0 << 5),
    IDT_FLAG_RING1                  = (1 << 5),
    IDT_FLAG_RING2                  = (2 << 5),
    IDT_FLAG_RING3                  = (3 << 5),

    IDT_FLAG_PRESENT                = 0x80,

} IDT_FLAGS;

void IDT_SetGate(int gate, void* handler, int flags);
void Initialize_IDT();
void IDT_EnableGate(int interrupt);
void IDT_DisableGate(int interrupt) ;
void Initialize_IDT();