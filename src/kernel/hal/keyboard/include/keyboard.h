#pragma once
#include "io.h"
#include "kstdio.h"
#include "isr.h"

//scan set 1
//common keys
#define PS2_BACKSPACE 0x0E
#define PS2_LSHIFT 0x2A
#define PS2_RSHIFT 0x36
#define PS2_LSHIFT_REL 0xAA
#define PS2_RSHIFT_REL 0xB6
#define PS2_ARROW_UP 0x48
#define PS2_ARROW_LEFT 0x4B
#define PS2_ARROW_RIGHT 0x4D
#define PS2_ARROW_DOWN 0x50
#define PS2_ENTER 0x1C

#define PS2_LCTRL 0x1D
#define PS2_LCTRL_REL 0x9D

#define PS2_RCTRL 0xE0
#define PS2_RCTRL_REL 0xE9

#define PS2_LALT 0x38
#define PS2_LALT_REL 0xB8

#define PS2_ALTGR 0x38


#define PS2_KEY_L 0x26

//debug
#define PS2_KEY_F1 59
#define KPANIC_BUTTON KEY_F12
#define PS2_KEY_F12 88


#define PS2_CAPSLK 0x3A

void KeyboardInit();
void NATIVECALL _keyboardcb_(registers_t* regs);