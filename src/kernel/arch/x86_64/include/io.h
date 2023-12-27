#pragma once
#include <stdint.h>
#include "kattributes.h"
#include "isr.h"
typedef uint16_t port_t;




extern uint64_t x64_rdtsc();
extern void  x64_outb(port_t port, uint8_t value);
extern uint8_t  x64_inb(port_t port);
extern void  x64_insb(port_t port, void *addr, int cnt);
extern uint16_t  x64_insw(port_t port, void *addr, int cnt);
extern void  x64_outsb(port_t port, const void *addr, int cnt);
extern void  x64_outsw(port_t port, const void *addr, int cnt);

extern registers_t x64_rdump();
extern void x64_panic();
extern void x64_enable_avx();
extern void x64_enable_fpu();
extern void x64_enable_sse();
#define IRQ_OFF { asm volatile ("cli"); }
#define IRQ_RES { asm volatile ("sti"); }

extern void x64_cli();
extern void x64_sti();

#define x64_iowait() x64_outb(0x80, 0);
extern void x64_gdt_flush(void* gdt);
#include "idt.h"
extern void x64_load_idt(IDT_DESCRIPTOR64* idt);


