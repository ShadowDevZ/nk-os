#pragma once
#include <stdint.h>
#include "isr.h"

//can be used to determine that the reg_state_t is obtained from IRQ stub routine
#define IRQ_MAGIC_NUMBER 0xEF85A2C
#include "pic.h"
typedef enum {
    IRQ_PIT,
    IRQ_KEYBOARD,
    IRQ_CASCADE,
    IRQ_COM2,
    IRQ_COM1,
    IRQ_LPT2,
    IRQ_FLOPPY,
    IRQ_LPT1,
    IRQ_CMOS_RTC,
    IRQ_PERIPHERAL1,
    IRQ_PERIPHERAL2,
    IRQ_PERIPHERAL3,
    IRQ_PS2_MOUSE,
    IRQ_FPU,
    IRQ_ATA_MASTER,
    IRQ_ATA_SLAVE

}IRQ_ISA_CODES;

extern void (*irqHandlers[16]);
typedef void (*IRQ_HANDLER)(reg_state_t* regs);
void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler);
void IRQ_SendEOI(uint8_t irq);