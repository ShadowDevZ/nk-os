#pragma once
#include <stdint.h>
typedef struct {
    uint64_t ds;
    uint64_t rdi, rsi, rbp, rsp, rdx, rcx, rbx, rax;
    uint64_t int_no, err_code;
    uint64_t rip, cs, eflags, useresp, ss;
} registers_t;

void ISR_Handler(registers_t* regs);
void ISR_Init();

typedef void (*ISR_HANDLER)(registers_t* regs);