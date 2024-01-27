#include "pic.h"
#include <stdint.h>
#include "ports.h"
#include "io.h"
#include "operands.h"
#include "bitsets.h"
typedef enum
{
 ICW1_ICW4_NEEDED = 1,

 ICW1_SINGLE = 2,
 ICW1_CASCADE = 0,
 
 ICW1_CAI4 = 4, 
 ICW1_CAI8 = 0,

 ICW1_LVL_TRIGGERED = 8,
 ICW1_EDGE_TRIGGERED = 0,

 ICW1_INITBIT = 16



}PIC_ICW1;
//master -> IRQ2 -> slave (bit 2)
#define PIC_ICW3_SLAVE_POS 4
//slave position
#define PIC_ICW3_SLAVE_ID 2


#define PIC_ICW4_8086 1
#define PIC_ICW4_AUTO_EOI 2
#define PIC_ICW4_FULLY_NESTED 16

#define PIC_EOI 0x20

void PIC_SendEOI(uint8_t irq) {
    if (irq >= PIC_REMAP_OFFSET + 8) {
        x64_outb(PORT_PIC_SLAVE_CMD, PIC_EOI);
    }
    x64_outb(PORT_PIC_MASTER_CMD,PIC_EOI);
}

inline void pic_write(port_t port, uint8_t value) {
    x64_outb(port, value);
    //timeout
    x64_outb(0, 0);
}
#include "kstdio.h"
void PIC_Initialize(uint8_t initMask) {
     
    pic_write(PORT_PIC_MASTER_CMD, ICW1_ICW4_NEEDED | ICW1_INITBIT);
    pic_write(PORT_PIC_SLAVE_CMD, ICW1_ICW4_NEEDED | ICW1_INITBIT);
    pic_write(PORT_PIC_MASTER_DATA, PIC_REMAP_OFFSET);
    pic_write(PORT_PIC_SLAVE_DATA, PIC_REMAP_OFFSET + 8);

    pic_write(PORT_PIC_MASTER_DATA, PIC_ICW3_SLAVE_POS);
    pic_write(PORT_PIC_SLAVE_DATA, PIC_ICW3_SLAVE_ID);
    pic_write(PORT_PIC_MASTER_DATA, PIC_ICW4_8086);
    pic_write(PORT_PIC_SLAVE_DATA, PIC_ICW4_8086);

    PIC_SetMask(initMask);

    
}

void PIC_DisableIRQ(uint8_t irq) {
    if (irq < 8 ) {
        uint8_t mask = x64_inb(PORT_PIC_MASTER_DATA) | (1 << irq);
        x64_outb(PORT_PIC_MASTER_DATA, mask);
    }
    else {
        uint8_t mask = x64_inb(PORT_PIC_SLAVE_DATA) | (1 << (irq - 8));
        x64_outb(PORT_PIC_SLAVE_DATA, mask);
    }

}
void PIC_EnableIRQ(uint8_t irq) {
    if (irq < 8 ) {
        uint8_t mask = x64_inb(PORT_PIC_MASTER_DATA) & ~(1 << irq);
        x64_outb(PORT_PIC_MASTER_DATA, mask);
    }
    else {
        uint8_t mask = x64_inb(PORT_PIC_SLAVE_DATA) & ~(1 << (irq - 8));
        x64_outb(PORT_PIC_SLAVE_DATA, mask);
    }
}

bool PIC_IRQAvailable(uint8_t irq) {
    if (irq < 8) {
        if (!CHECK_BIT(x64_inb(PORT_PIC_MASTER_DATA), irq)) {
            return true;
        }
     
    }
    else {
        if (!CHECK_BIT(x64_inb(PORT_PIC_SLAVE_DATA), irq)) {
            return true;
        }
        
    }
    return false;
}

void PIC_SetMask(uint8_t mask) {
    pic_write(PORT_PIC_MASTER_DATA, mask);
    pic_write(PORT_PIC_SLAVE_DATA, mask);
}

uint32_t Pic_GetMask() {
    uint16_t master = x64_inb(PORT_PIC_MASTER_DATA);
    uint16_t slave = x64_inb(PORT_PIC_SLAVE_DATA);

    return (uint32_t)master << 8 | slave;
}

void PIC_Disable() {
    pic_write(PORT_PIC_MASTER_DATA, 0xFF);
    pic_write(PORT_PIC_SLAVE_DATA, 0xFF);
}