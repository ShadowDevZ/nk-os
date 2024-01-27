#include "include/uptime.h"
#include "isr.h"
#include "irq.h"
#include "kstdio.h"
#include "io.h"
#include "ports.h"
void PIT_Init(int hz) {
    
    IRQ_RegisterHandler(0, _timercb_internal_);;
    PIT_SetFrequency(1000);
}

void PIT_SetFrequency(int hz) {
    int divisor = 1193180 / hz;
    x64_outb(PORT_PIT_CMD_W, 0x36);
    x64_outb(PORT_PIT_DCH0_RW , divisor & 0xFF);   // low byte
    x64_outb(PORT_PIT_DCH0_RW , divisor >> 8);     // high byte
}


volatile uint64_t ticks = 0;
NATIVECALL void _timercb_internal_(reg_state_t* rg) {
    ticks++;
 //printf(".");

   // IRQ_SendEOI(0);

    
}

uint64_t GetSystemTicks() {
 return ticks;   
}

void kusleep(uint64_t ms) {
    asm("cli");
    uint64_t ticks = GetSystemTicks();
    uint64_t saved = ticks;

    //less or equal in case the processor doesnt get the chance
    //to responds, it would loop endlessly
    while (ticks <= saved + ms) {
        asm("sti");
        ticks = GetSystemTicks();
        asm("cli");

    }
    asm("sti");

    

}