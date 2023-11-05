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

volatile uint64_t secs = 0;
volatile uint64_t ticks = 0;
 void _timercb_internal_(registers_t* rg) {
    ticks++;
 

   // IRQ_SendEOI(0);

    
}

volatile uint64_t GetSystemTicks() {
 return ticks;   
}

void kusleep(uint64_t ms) {
    uint64_t ticks = GetSystemTicks();
    uint64_t saved = ticks;

    //less or equal in case the processor doesnt get the chance
    //to responds, it would loop endlessly
    while (ticks <= saved + ms) {
        ticks = GetSystemTicks();

    }

}