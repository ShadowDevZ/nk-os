#pragma once
#include "../arch/x86_64/include/irq.h"
#include <stdint.h>
//todo move this to hal
void _timercb_internal_(registers_t* rg);
uint64_t GetSystemTicks();
void PIT_SetFrequency(int hz);
uint64_t GetSystemUptime();
void Ksleep(uint64_t sec);