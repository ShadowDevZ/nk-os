#include "include/idt.h"
#include "include/io.h"
__attribute__((aligned(0x10))) 
IDT_ENTRY64 g_IDT[256];
IDT_DESCRIPTOR64 g_Desc;

void Initialize_IDT() {
    g_Desc.base = &g_IDT;
    g_Desc.limit = (256 * sizeof(IDT_ENTRY64)) -1;

    load_idt(&g_Desc);
}

void IDT_SetGate(int gate, void* handler, int flags) {
    uint16_t low_16 = (uint16_t) ((uint64_t)handler & 0xFFFF);
    uint16_t middle_16 = (uint16_t) (((uint64_t)handler >> 16) & 0xFFFF);
    uint32_t high_32 = (uint32_t) (((uint64_t)handler >> 32) & 0xFFFFFFFF);

    IDT_ENTRY64 entry = {
        .isrLow = low_16,
        .kernelCs = 0x08,
        .reserved = 0,
        //0x60 is user mode access
        .attributes = flags,
        .isrMid = middle_16,
        .isrHigh = high_32,
        .ist = 0

    };
    g_IDT[gate] = entry;

}