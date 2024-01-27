#include "include/isr.h"
#include "include/idt.h"
#include "include/panic.h"
#include "irq.h"
char *exception_messages[] = {
    [ISR_DIVIDE_ZERO] = "Division by Zero",
    [ISR_DEBUG] =   "Debug",
    [ISR_NMI] = "Non-Maskable Interrupt",
    [ISR_BREAKPOINT] = "Breakpoint",
    [ISR_OVERFLOW] = "Overflow",
    [ISR_OUT_OF_BOUNDS] = "Bound Range Exceeded",
    [ISR_INVALID_OPCODE] = "Invalid Opcode",
    [ISR_DEVICE_UNAVAIL] = "Device Not Available",
    [ISR_DOUBLE_FAULT] = "Double fault",
    [ISR_COPROCESSOR] = "Coprocessor Segment Overrun",
    [ISR_INVALID_TSS] = "Invalid TSS",
    [ISR_SEGMENT_NP] = "Segment Not Present",
    [ISR_SS_FAULT] = "Stack Segment Fault",
    [ISR_GEN_PROT] = "General Protection Fault",
    [ISR_PAGE_FAULT] = "Page fault",
    "Reserved",
    [ISR_X87_FPU] = "x87 FPU Exception",
    [ISR_ALIGN_CHECK] = "Alignment check",
    [ISR_MACHINE_CHECK] = "Machine check",
    [ISR_SIMD_FPU] = "SIMD FPU Exception",
    [ISR_VIRTUALIZATION] = "Virtualization exception",
    [ISR_CTRL_PROT] = "Control Protection Exception",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    
    [ISR_HYPERV_INJECT] = "Hypervisor injection",
    [ISR_VMM_COMM] = "VMM Communication Exception",
    [ISR_SECURITY] = "Security exception",
    
    "Reserved",
};

char** GetIsrExceptionList() {
    return exception_messages;
}
char* ISRErrorToMessage(ISR_ERROR_CODES err) {
    uint8_t len = sizeof(exception_messages)/sizeof(exception_messages[0]);
    if (err >= len) {
        return "<NULL>";
    }
    return exception_messages[err];
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
void SetGates(int start, int end, int flags) {
    for (int i = start; i <= end; i++) {
        IDT_SetGate(i, X64_ISRHANDLERS[i], flags, 0);
    }
}

void IsrsGateSetup() {


    //generated using vim macros
    
    SetGates(0, 31, IDT_INT0_FLAGS);

    //irq
    for (int i =0; i < 16; i++) {
        IDT_SetGate(i+32, irqHandlers[i], IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT | IDT_FLAG_PRESENT, 0);
    } 
    SetGates(48, 127, IDT_INT0_FLAGS);

    //syscall 0x80
    IDT_SetGate(128, X64_ISRHANDLERS[128],  IDT_INT3_FLAGS, 0);    
    SetGates(129, 255, IDT_INT0_FLAGS);

   

 



}


ISR_HANDLER g_ISRHandlers[256];
#include "../arch/x86_64/include/panic.h"
#include "kstdio.h"
uint64_t ISR_Handler(uint64_t rsp) {
    reg_state_t* regs = (reg_state_t*)rsp;
   
   
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


