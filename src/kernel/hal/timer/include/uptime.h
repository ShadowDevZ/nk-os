#pragma once
#include "../arch/x86_64/include/irq.h"
#include <stdint.h>
//todo move this to hal

//#define PIT_HZ 100 //for some reason it crashes over 100hz ?

void _timercb_internal_(registers_t* rg);
uint64_t GetSystemTicks();
void PIT_SetFrequency(int hz);
uint64_t GetSystemUptime();
void kusleep(uint64_t sec);
void PIT_Init(int hz) ;