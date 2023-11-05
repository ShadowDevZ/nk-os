#pragma once
#include <stdint.h>
#include "isr.h"
typedef void (*IRQ_HANDLER)(registers_t* regs);
void IRQ_RegisterHandler(uint8_t irq, IRQ_HANDLER handler);
void IRQ_SendEOI(uint8_t irq);