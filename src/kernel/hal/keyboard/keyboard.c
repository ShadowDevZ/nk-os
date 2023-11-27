#include "include/keyboard.h"
#include "kattributes.h"
#include "bitsets.h"
#include "ports.h"
#include "irq.h"
#include "include/kbctl.h"
unsigned char kbd_tbl[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* PS2_BACKSPACE */
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

unsigned char kbd_tbl_shift[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '_', '=', '\b',	/* PS2_BACKSPACE */
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
  KF_NUMLOCK = 1 << 17


};

void KeyboardInit() {
  SetKbctlEvent(KBCTL_ECHO, true);
  SetKbctlEvent(KBCTL_HOOKS, true);
 //SetKbctlEvent(KBCTL_LOCK, true);
}

#define SCAN_CODE_MAX 128
#define KBD_READY 1
volatile uint32_t keyflags = 0;
#define KBD_KEYUP 128
uint32_t GetRawKeyboardFlags() {
  return keyflags;
}

#define kbputchar(c) \ 
({ \
   if (GetKbctlEvent(KBCTL_ECHO)) { \
      putchar(c); \
      } \
}) \

void NATIVECALL _keyboardcb_(registers_t* regs) {
   volatile unsigned char scanCode;
   volatile unsigned char kbdStatus;

   if (GetKbctlEvent(KBCTL_LOCK)) {
    return;
   }
    
   kbdStatus = x64_inb(PORT_KBD_CMD);

   //KEYBOARD_READY
   if (kbdStatus & KBD_READY) {


       scanCode = x64_inb(PORT_KBD_DATA);
      if ((scanCode & KBD_KEYUP) == 128) {


        switch (scanCode) {
          case PS2_LSHIFT_REL:
            SET_MASK(keyflags, KF_LSHIFT_REL);
            UNSET_MASK(keyflags, KF_LSHIFT);
            break;
          case PS2_RSHIFT_REL:
             SET_MASK(keyflags, KF_RSHIFT_REL);
             UNSET_MASK(keyflags, KF_RSHIFT);
            break;
          case PS2_LCTRL_REL:
             SET_MASK(keyflags, KF_LCTRL_REL);
             UNSET_MASK(keyflags, KF_LCTRL);
            break;
          case PS2_RCTRL_REL:
             SET_MASK(keyflags, KF_RSHIFT_REL);
             UNSET_MASK(keyflags, KF_RSHIFT);
            break;
          case PS2_LALT_REL:
            SET_MASK(keyflags, KF_LALT_REL);
            UNSET_MASK(keyflags, KF_LALT);
            break;

          default:
            break;

        }
    }
    else {


        switch (scanCode) {
          case PS2_LSHIFT:
            SET_MASK(keyflags, KF_LSHIFT);
            UNSET_MASK(keyflags, KF_LSHIFT_REL);
            break;
          case PS2_RSHIFT:
             SET_MASK(keyflags, KF_RSHIFT);
             UNSET_MASK(keyflags, KF_RSHIFT_REL);
            break;
          case PS2_LCTRL:
             SET_MASK(keyflags, KF_LCTRL);
             UNSET_MASK(keyflags, KF_LCTRL_REL);
            break;
          case PS2_RCTRL:
             SET_MASK(keyflags, KF_RSHIFT);
             UNSET_MASK(keyflags, KF_RSHIFT_REL);
            break;
          case PS2_CAPSLK:
             FLIP_MASK(keyflags, KF_CAPSLK);
            break;
          case PS2_BACKSPACE:
             printf(" \b");
            break;
          case PS2_LALT:
            SET_MASK(keyflags, KF_LALT);
            UNSET_MASK(keyflags, KF_LALT_REL);
            break;
          default:
            break;

        }
  
    }

   

   }
   

    if (scanCode > SCAN_CODE_MAX) {
      return;
    }
    

   

    if ((keyflags & KF_LSHIFT) || (keyflags & KF_CAPSLK) && (kbd_tbl[scanCode] != 0)) {
      kbputchar(kbd_tbl_shift[scanCode]);

    }
    else {
       kbputchar(kbd_tbl[scanCode]);
    }


  // IRQ_SendEOI(1);

//    keyflags = 0;

}
    
