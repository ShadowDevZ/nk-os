#include "include/isr.h"
#include "include/idt.h"
#include "include/panic.h"
#include "irq.h"
char *exception_messages[] = {
    "Division by Zero",
    "Debug",
    "Non-Maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bat TSS",
    "Segment not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

char** GetIsrExceptionList() {
    return exception_messages;
}

#include "include/idt.h"
#include "kstdio.h"

void ISR_Init() {
    IsrsGateSetup();
    for (int i = 0; i < 256; i++) {
        IDT_EnableGate(i);
    }
  //  IDT_DisableGate(0x80);
    
}

inline void SetGates(int start, int end, int flags) {
    for (int i = start; i <= end; i++) {
        IDT_SetGate(i, X64_ISRHANDLERS[i], flags);
    }
}

void IsrsGateSetup() {


    //generated using vim macros
    
    SetGates(0, 31, IDT_INT0_FLAGS);

    //irq
    for (int i =0; i < 16; i++) {
        IDT_SetGate(i+32, irqHandlers[i], IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT | IDT_FLAG_PRESENT);
    } 
    SetGates(48, 127, IDT_INT0_FLAGS);

    //syscall 0x80
    IDT_SetGate(128, X64_ISRHANDLERS[128],  IDT_INT3_FLAGS);    
    SetGates(129, 255, IDT_INT0_FLAGS);

   

 



}


ISR_HANDLER g_ISRHandlers[256];
#include "../arch/x86_64/include/panic.h"
#include "kstdio.h"
uint64_t ISR_Handler(uint64_t rsp) {
    isr_state_t* regs = (isr_state_t*)rsp;
   
   
    //PrintRegs(regs);
    
    


    if (g_ISRHandlers[regs->isr_number] != NULL) {
         g_ISRHandlers[regs->isr_number](regs);
    }
    else if (regs->isr_number >= 32) {
        printf("Unhandled interrupt %llu!\n", regs->isr_number);
        
    }
    else {
    ISR_SystemRaiseHardError("CPU exception has occured", regs);

   printf("INT[%lu] %s\n", regs->isr_number, exception_messages[regs->isr_number]);
   // PrintRegs(regs);
    }

    return rsp;
}
void ISR_RegisterHandler(int interrupt, ISR_HANDLER handler) {
    g_ISRHandlers[interrupt] = handler;
    IDT_EnableGate(interrupt);
}


isr_state_t Regs2ISRState(registers_t* regs) {
    if (regs == NULL) {
        isr_state_t t = {0};
        return t;
    }
    isr_state_t state;
    memset(&state, 0, sizeof(state));
    state.gp.rax = regs->rax;
    state.gp.rbx = regs->rbx;
    state.gp.rcx = regs->rcx;
    state.gp.rdx = regs->rdx;
    state.gp.rsi = regs->rsi;
    state.gp.rdi = regs->rdi;
    state.gp.r8 = regs->r8;
    state.gp.r9 = regs->r9;
    state.gp.r10 = regs->r10;
    state.gp.r11 = regs->r11;
    state.gp.r12 = regs->r12;
    state.gp.r13 = regs->r13;
    state.gp.r14 = regs->r14;
    state.gp.r15 = regs->r15;
    
    return state;
}
//Converts code segment selector value to the DPL (ring level)

#define CODEUSR 64
int CS2DPL() {
    uint64_t cs = x64_readcs();
    //rings 1 and 2 are not used in the kernel at all yet
    if (cs == CODEUSR) {
        return 3;
    }
    else {
        return 0;
    }
}


