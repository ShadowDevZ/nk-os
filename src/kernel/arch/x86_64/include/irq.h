#pragma once
#include <stdint.h>
#include "isr.h"

extern void (*irqHandlers[16]);
typedef void (*IRQ_HANDLER)(reg_state_t* regs);
void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler);
void IRQ_SendEOI(uint8_t irq);