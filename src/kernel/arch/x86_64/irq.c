#include "include/isr.h"
#include "include/idt.h"
#include "include/panic.h"
#include "include/irq.h"
#include "ports.h"
IRQ_HANDLER g_IRQ[16];

void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler) {
    g_IRQ[irq] = handler;
}
void IRQ_SendEOI(uint8_t irq) {
    if (irq >= 40) {
        x64_outb(PORT_PIC_SLAVE_CMD, PORT_PIC_MASTER_CMD);
    }
    x64_outb(PORT_PIC_MASTER_CMD,PORT_PIC_MASTER_CMD);
}
void IRQ_Handler(uint8_t intno, uint64_t rsp) {
   // printf("here beep %llu\n", intno - 32);
    reg_state_t* regs = (reg_state_t*)rsp;
    
    

    if (g_IRQ[intno - 32] != NULL) {
      //  registers_t rg = x64_rdump();
        g_IRQ[intno - 32](regs);
    }
    IRQ_SendEOI(intno);
    
    
    
}