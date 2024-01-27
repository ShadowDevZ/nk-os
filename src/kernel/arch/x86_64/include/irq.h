#pragma once
#include <stdint.h>
#include "isr.h"

//can be used to determine that the reg_state_t is obtained from IRQ stub routine
#define IRQ_MAGIC_NUMBER 0xEF85A2C

extern void (*irqHandlers[16]);
typedef void (*IRQ_HANDLER)(reg_state_t* regs);
void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler);
void IRQ_SendEOI(uint8_t irq);