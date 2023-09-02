#pragma once
#include <stdint.h>
#include "kattributes.h"
#include "isr.h"
typedef uint16_t port_t;





void  x64_outb(port_t port, uint8_t value);
uint8_t  x64_inb(port_t port);
void  x64_insb(port_t port, void *addr, int cnt);
uint16_t  x64_insw(port_t port, void *addr, int cnt);
void  x64_outsb(port_t port, const void *addr, int cnt);
void  x64_outsw(port_t port, const void *addr, int cnt);


#define IRQ_OFF { asm volatile ("cli"); }
#define IRQ_RES { asm volatile ("sti"); }


void gdt_flush(void* gdt);
#include "idt.h"
void load_idt(IDT_DESCRIPTOR64* idt);
