#pragma once
#include <stdint.h>

typedef struct {
    uint64_t rax, rbx, rcx, rdx, rsi, rdi, r8, r9, r10, r11, r12, r13, r14, r15, rsp;
}registers_t;


typedef struct {
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t r11;
    uint64_t r10;
    uint64_t r9;
    uint64_t r8;
    uint64_t rbp;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rdx;
    uint64_t rcx;
    uint64_t rbx;
    uint64_t rax;

}__attribute__((packed)) general_registers_t;

typedef struct {
    uint64_t rip;
    uint64_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t ss;

}extended_registers_t;
typedef struct
{
    general_registers_t gp;
    
    uint64_t isr_number;
    uint64_t error_code;
    extended_registers_t er;
    
    
} isr_state_t;

extern void (*X64_ISRHANDLERS[256]);
void IsrsGateSetup();
int CS2DPL();
uint64_t ISR_Handler(uint64_t rsp);
void ISR_Init();
char** GetIsrExceptionList();

typedef void (*ISR_HANDLER)(isr_state_t* regs);

isr_state_t Regs2ISRState(registers_t* regs);

void ISR_RegisterHandler(int interrupt, ISR_HANDLER handler);