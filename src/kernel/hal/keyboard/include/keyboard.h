#pragma once
#include "io.h"
#include "kstdio.h"
#include "isr.h"

//scan set 1
//common keys
#define PS2_BACKSPACE 0x0E
#define PS2_BACKSPACE_REL 0x8E
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
void NATIVECALL _keyboardcb_(reg_state_t* regs);
NATIVECALL char KeyboardGetChar(bool echo);
typedef void (*KbListenCb)(void);
void KbListenKeyPress(uint8_t scanCode, KbListenCb lc);
static unsigned char kbd_tbl[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=',  '\b',	/* PS2_BACKSPACE */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};		

static unsigned char kbd_tbl_shift[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '_', '=', 0,	/* PS2_BACKSPACE */
  '\t',			/* Tab */
  'Q', 'W', 'E', 'R',	/* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',	/* 39 */
 '|', '~',   0,		/* Left shift */
 '\\', 'Z', 'X', 'C', 'V', 'B', 'N',			/* 49 */
  'M', '<', '>', '?',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};	
enum {
  KF_LSHIFT = 1 << 0,
  KF_LCTRL =  1 << 1,

  KF_RSHIFT = 1 << 2,
  KF_RCTRL =  1 << 3,

  KF_LALT = 1 << 4,
  KF_RALT = 1 << 5,

  KF_LSHIFT_REL = 1 << 6,
  KF_LCTRL_REL = 1 << 7,

  KF_RSHIFT_REL = 1 << 8,
  KF_RCTRL_REL = 1 << 9,
  
  KF_LALT_REL = 1 << 10,
  KF_RALT_REL = 1 << 11,

  KF_ARROW_LEFT = 1 << 12,
  KF_ARROW_RIGHT = 1 << 13,
  KF_ARROW_UP = 1 << 14,
  KF_ARROW_DOWN = 1 << 15,
  KF_CAPSLK = 1 << 16,
  KF_NUMLOCK = 1 << 17,
  KF_BACKSPACE = 1 << 18,
  KF_BACKSPACE_REL = 1 << 19


};