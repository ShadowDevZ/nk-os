#include "kstdio.h"
#include "include/gdt.h"


GDTEntry g_GDT[GTD_DESC_COUNT];
GDT_PTR g_GDT_PTR;

void SetGDTEntry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    GDTEntry *this = &g_GDT[index];

    this->LimitLow = limit & 0xFFFF;
    this->BaseLow = base & 0xFFFF;
    this->BaseMiddle = (base >> 16) & 0xFF;
    this->Access = access;

    this->FlagsLimitHi = (limit >> 16) & 0x0F;
    this->FlagsLimitHi = this->FlagsLimitHi | (gran & 0xF0);

    this->BaseHigh = (base >> 24 & 0xFF);
}


//todo implement TSS next and interrupts

void gdt_init(void) {
    printf("Pre init gdt\n");

    g_GDT_PTR.limit = sizeof(g_GDT) - 1;
    g_GDT_PTR.base_address = (uint64_t)g_GDT;
//index, base, limit, access, grann
    SetGDTEntry(0, 0, 0, 0, 0);
    SetGDTEntry(1, 0, 0xffff, 0x9a, 0x80);
    SetGDTEntry(2, 0, 0xffff, 0x92, 0x80);
    SetGDTEntry(3, 0, 0xffff, 0x9a, 0xcf);
    SetGDTEntry(4, 0, 0xffff, 0x92, 0xcf);
    SetGDTEntry(5, 0, 0, 0x9a, 0xa2);
    SetGDTEntry(6, 0, 0, 0x92, 0xa0);
    SetGDTEntry(7, 0, 0, 0xf2, 0);
    SetGDTEntry(8, 0, 0, 0xfa, 0x20
    );

    for (int i = 0; i < 8; i++) {
        printf("ENTRY[%d]:%u\n",i, g_GDT[i].BaseMiddle);
    }

    gdt_flush(&g_GDT_PTR);
    printf("It works");

    // 16-bit code descriptor (Entry 1)


}


