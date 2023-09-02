#pragma once
#include "kstdio.h"

extern void x64_cpu_stop();

void _SystemRaiseHardError(const char* _file_, int line, const char* reason, const char* description);

void PrintReg(registers_t *reg);

#define SystemRaiseHardError(reason, desc) _SystemRaiseHardError(__FILE__, __LINE__, reason, desc);