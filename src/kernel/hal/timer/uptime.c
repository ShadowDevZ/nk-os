#include "include/uptime.h"
#include "isr.h"
#include "irq.h"
#include "kstdio.h"
#include "io.h"

void PIT_SetFrequency(int hz) {
    int divisor = 1193180 / hz;
    x64_outb(0x43, 0x36);
    x64_outb(0x40, divisor & 0xFF);   // low byte
    x64_outb(0x40, divisor >> 8);     // high byte
}


static uint64_t ticks = 0;
 void _timercb_internal_(registers_t* rg) {
    ticks++;
    //works correctly and prints every new PIT tick
 //   printf("DEBUG_TICKS: %lu\n", ticks);
    
    
}

uint64_t GetSystemTicks() {
    //doesnt work correctly and displays 0
   // printf("DEBUG_TICKS: %lu\n", ticks);
 return ticks;   
}