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

registers_t x64_rdump();
void x64_panic();
void x64_enable_avx();
void x64_enable_fpu();
void x64_enable_sse();
#define IRQ_OFF { asm volatile ("cli"); }
#define IRQ_RES { asm volatile ("sti"); }

#define x64_iowait() x64_outb(0x80, 0);
void x64_gdt_flush(void* gdt);
#include "idt.h"
void x64_load_idt(IDT_DESCRIPTOR64* idt);
