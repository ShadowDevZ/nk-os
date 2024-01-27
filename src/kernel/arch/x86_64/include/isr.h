#pragma once
#include <stdint.h>

typedef uint64_t reg_t;
typedef struct {
    reg_t r15;
    reg_t r14;
    reg_t r13;
    reg_t r12;
    reg_t r11;
    reg_t r10;
    reg_t r9;
    reg_t r8;
    reg_t rdi;
    reg_t rsi;
    reg_t rbp;
    reg_t rsp;
    reg_t rbx;
    reg_t rdx;
    reg_t rcx;
    reg_t rax;

}__attribute__((packed)) general_registers_t;

typedef struct {
    reg_t rip;
    reg_t cs;
    reg_t rflags;
    reg_t ss;

}__attribute__((packed)) extended_registers_t;
typedef struct
{
    general_registers_t gp;
    
    uint64_t isr_number;
    
    union {
    uint64_t error_code;
    uint64_t irq_magic;
    };
    
    extended_registers_t er;
    
    
}__attribute__((packed)) reg_state_t;


typedef enum {
    ISR_DIVIDE_ZERO = 0,
    ISR_DEBUG = 1,
    ISR_NMI = 2,
    ISR_BREAKPOINT = 3,
    ISR_OVERFLOW = 4,
    ISR_OUT_OF_BOUNDS = 5,
    ISR_INVALID_OPCODE = 6,
    ISR_DEVICE_UNAVAIL = 7,
    ISR_DOUBLE_FAULT = 8,
    ISR_COPROCESSOR = 9,
    ISR_INVALID_TSS = 10,
    ISR_SEGMENT_NP = 11,
    ISR_SS_FAULT = 12,
    ISR_GEN_PROT = 13,
    ISR_PAGE_FAULT = 14,
    
    ISR_X87_FPU = 16,
    ISR_ALIGN_CHECK = 17,
    ISR_MACHINE_CHECK = 18,
    ISR_SIMD_FPU = 19,
    ISR_VIRTUALIZATION = 20,
    ISR_CTRL_PROT = 21,
    ISR_HYPERV_INJECT =  28,
    ISR_VMM_COMM = 29,
    ISR_SECURITY = 30

}ISR_ERROR_CODES;


extern void (*X64_ISRHANDLERS[256]);
void IsrsGateSetup();
int CS2DPL();
uint64_t ISR_Handler(uint64_t rsp);
void ISR_Init();
char** GetIsrExceptionList();
char* ISRErrorToMessage(ISR_ERROR_CODES err);

typedef void (*ISR_HANDLER)(reg_state_t* regs);



void ISR_RegisterHandler(int interrupt, ISR_HANDLER handler);