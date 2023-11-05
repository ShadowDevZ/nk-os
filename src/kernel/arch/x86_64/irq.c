#include "include/isr.h"
#include "include/idt.h"
#include "include/panic.h"
#include "include/irq.h"

IRQ_HANDLER g_IRQ[16];

void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler) {
    g_IRQ[irq] = handler;
}
void IRQ_SendEOI(uint8_t irq) {
    if (irq >= 40) {
        x64_outb(0xA0, 0x20);
    }
    x64_outb(0x20,0x20);
}
void IRQ_Handler(uint8_t intno) {
   // printf("here beep %llu\n", intno - 32);
    
    

    if (g_IRQ[intno - 32] != NULL) {
        registers_t rg = x64_rdump();
        g_IRQ[intno - 32](&rg);
    }
    IRQ_SendEOI(intno);
    
    
    
}