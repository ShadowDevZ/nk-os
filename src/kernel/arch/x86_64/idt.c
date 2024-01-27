#include "include/idt.h"
#include "include/io.h"
#include "krnlcfg.h"
__attribute__((aligned(0x10))) 
IDT_ENTRY64 g_IDT[256];
IDT_DESCRIPTOR64 g_Desc;
#include "kstdio.h"
#include "pic.h"
#include "bitsets.h"
#include "operands.h"
void InitializeIDT() {
    g_Desc.base = (uint64_t)&g_IDT;
    g_Desc.limit = (256 * sizeof(IDT_ENTRY64)) -1;
    memset(g_IDT, 0, sizeof(IDT_ENTRY64) * 256);

    PIC_Initialize(PIC_UNMASK_ALL);
    
    uint32_t mask = Pic_GetMask();
    uint16_t low = LOWORD(mask);
    uint16_t high = HIWORD(mask);
    
  
    debugf("PIC_MASK\n  master: 0x%02X\n  slave: 0x%02X\n", high,low); 

    x64_load_idt(&g_Desc);
}

void IDT_SetGate(int gate, void* handler, int flags, uint8_t ist) {
    uint16_t low_16 = (uint16_t) ((uint64_t)handler & 0xFFFF);
    uint16_t middle_16 = (uint16_t) (((uint64_t)handler >> 16) & 0xFFFF);
    uint32_t high_32 = (uint32_t) (((uint64_t)handler >> 32) & 0xFFFFFFFF);

    IDT_ENTRY64 entry = {
        .isrLow = low_16,
        .kernelCs = 0x28,
        .reserved = 0,
        //0x60 is user mode access
        .attributes = flags,
        .isrMid = middle_16,
        .isrHigh = high_32,
        .ist = ist

    };
    g_IDT[gate] = entry;
#if KF_IDT_DEBUG == 1
debugf("Setting IDT Gate %d\n", gate);
debugf("HANDLER: 0x%llx FLAGS: 0x%x IST: 0x%x COD_SEG: 0x%x\n", (uint64_t)handler, flags, entry.ist, entry.kernelCs);
#endif

   

}

void IDT_SetIST(int interrupt, uint8_t ist) {
    g_IDT[interrupt].ist =  ist;
}
void IDT_DisableIST(int interrupt) {
    g_IDT[interrupt].ist =  0;
}

void IDT_EnableGate(int interrupt) {
    FLAG_SET(g_IDT[interrupt].attributes, IDT_FLAG_PRESENT);
}
void IDT_DisableGate(int interrupt) {
    FLAG_UNSET(g_IDT[interrupt].attributes, IDT_FLAG_PRESENT);
}