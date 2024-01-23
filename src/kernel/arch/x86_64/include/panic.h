#pragma once
#include "kstdio.h"
#include "isr.h"
extern void x64_cpu_stop();

void _SystemRaiseHardError(const char* _file_, int* line, const char* reason, const char* description, isr_state_t* regs);

void PrintRegs(isr_state_t *reg);

NORET UNSAFE void DebugPageFault(void* addr);

//#define SystemRaiseHardError(reason, desc) _SystemRaiseHardError(__FILE__, __LINE__, reason, desc, NULL);

static inline void SystemRaiseHardError(const char* reason, const char* desc) {
    int a = __LINE__;
    _SystemRaiseHardError(__FILE__, &a, reason, desc, NULL);
}

#define ISR_SystemRaiseHardError(desc, regs) _SystemRaiseHardError(NULL, NULL, "ISR_STOP", desc, regs);


#define DebugRaiseKernelPanic() _SystemRaiseHardError(__FILE__, NULL, "DEBUG_STOP", "Manually invoked panic", NULL)
