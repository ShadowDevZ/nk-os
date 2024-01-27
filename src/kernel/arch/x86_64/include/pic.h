#pragma once
#include "io.h"
#include "irq.h"
#include <stdint.h>
#include <stdbool.h>
uint32_t Pic_GetMask();
void PIC_SetMask(uint8_t mask);

#define PIC_REMAP_OFFSET 32

#define PIC_UNMASK_ALL 0x0
#define PIC_MASK_ALL 0xFF

void PIC_Initialize(uint8_t initMask);
void PIC_SendEOI(uint8_t irq);
void PIC_Disable();
void PIC_DisableIRQ(uint8_t irq);
void PIC_EnableIRQ(uint8_t irq);
bool PIC_IRQAvailable(uint8_t irq);
uint32_t Pic_GetMask();
void PIC_SetMask(uint8_t mask);