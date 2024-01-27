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
   PIC_SendEOI(irq);
}
void IRQ_Handler(uint64_t* rsp) {
   // printf("here beep %llu\n", intno - 32);
    reg_state_t* regs = (reg_state_t*)rsp;
    if (regs->irq_magic != IRQ_MAGIC_NUMBER) {
        SystemRaiseHardError("IRQ_HANDLER", "Magic number not found");
    }
   
    
    
   //printf("isr: %llu\n", regs->isr_number);

    if (g_IRQ[regs->isr_number - PIC_REMAP_OFFSET] != NULL) {
      //  registers_t rg = x64_rdump();
        g_IRQ[regs->isr_number - PIC_REMAP_OFFSET](regs);
    }
    IRQ_SendEOI(regs->isr_number);
    
    
    
}