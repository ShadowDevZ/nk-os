#include "gdt.h"
#include "isr.h"
#include "irq.h"
#include "bitsets.h"
#include "io.h"
#include "handlers.h"
#include "kstdio.h"
#include "panic.h"
NORET void page_fault_handler(reg_state_t* regs)  {

    x64_cli();
    uint64_t faulting_address;
    asm ("movq %%cr2, %0" : "=r" (faulting_address));

    //page is present
    uint8_t present = IS_SET(regs->error_code, 0);
    //if set caused by write, otherwise read
    uint8_t write = IS_SET(regs->error_code, 1);
    //CPL=3 
    uint8_t usr = IS_SET(regs->error_code, 2);
    uint8_t reserved = IS_SET(regs->error_code, 3);
    uint8_t instructionFetch = IS_SET(regs->error_code, 4);
    uint8_t protKey = IS_SET(regs->error_code, 5);
    //shadow stack
    uint8_t ss = IS_SET(regs->error_code, 6);
    uint8_t sgx = IS_SET(regs->error_code, 15);
    printf("\n\nPAGE FAULT (");
    if (present) 
        printf(" present ");
    if (write)
        printf(" write ");
    else
        printf(" read ");

    if (usr)
        printf(" user ");
    if (reserved)
        printf(" reserved ");
    if (instructionFetch)
        printf(" fetch ");
    if (protKey)
        printf(" pkru ");
    if (ss)
        printf(" ss ");
    if (sgx)
        printf(" sgx ");
    printf(")");

    printf(") at 0x%x\n",faulting_address);
    
    PrintRegs(regs);

    x64_panic();
    UNREACHABLE();
}
   // panicf("PAGING","Page fault");

NORET void gpf_handler(reg_state_t* regs) {

/*
    31         16   15         3   2   1   0
+---+--  --+---+---+--  --+---+---+---+---+
|   Reserved   |    Index     |  Tbl  | E |
+---+--  --+---+---+--  --+---+---+---+---+
E - cpu related issue
Tbl  - which descriptor caused the fault
    0b00 - GDT
    0b01 - IDT
    0b10 - LDT
    0b11 - IDT
Index - selector index
*/
    //just in case, so we wont cause another exception
    x64_cli();

    printf("\n\nGeneral protection fault");
        //if it is segment related
    if (regs->error_code > 0) {
        uint8_t external = regs->error_code & 1;
        uint8_t tbl = BIT_INTERVAL(regs->error_code, 1, 2);
        uint16_t index = BIT_INTERVAL(regs->error_code, 3, 13);

        if (external) {
            printf(" ::EXT ");
        }
        printf(" ( ");
        switch(tbl){
            case 0b00:
                printf("GDT ");
                break;
            case 0b10:
                printf("LDT ");
                break;
            case 0b01:
            case 0b11:
                printf("IDT ");
                break;
            default:
                printf("UNKOWN ");
                break;


        }
        //gdt or ldt
        if (tbl == 0b00 || tbl == 0b10){
            if (index <= GDT_DESC_COUNT) {
                printf(" )\nSelector [0x%02x]\n", index * 8);
            }
            else {
                printf(" )\nNo valid selector found\n");
            }
        }
        //idt
        else if (tbl == 0b11 || tbl == 0b01){
            if (index < 256) {
                printf(" )\nSelector [0x%02x]\n", index);
            }
            else {
                printf(" )\nNo valid selector found\n");
            }

        }
        

        printf("\n\n");
    }

    
    PrintRegs(regs);

     
    x64_panic();
    UNREACHABLE();
}

void InitFaultHandlers() {
    ISR_RegisterHandler(ISR_PAGE_FAULT, page_fault_handler);
    ISR_RegisterHandler(ISR_GEN_PROT, gpf_handler);
}