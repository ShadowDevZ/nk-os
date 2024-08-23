#include "include/keyboard.h"
#include "kattributes.h"
#include "bitsets.h"
#include "ports.h"
#include "irq.h"
#include "include/kbctl.h"
#include "mutex.h"


void KeyboardInit() {
  SetKbctlEvent(KBCTL_ECHO, true);
  SetKbctlEvent(KBCTL_HOOKS, true);
 //SetKbctlEvent(KBCTL_LOCK, true);
}

#define SCAN_CODE_MAX 128
#define KBD_READY 1

#define KBD_KEYUP 128

typedef struct {
  uint32_t keyflags;
  uint8_t kbdStatus;
  uint8_t scanCode;
  char c;
  bool init;
}KBD_RESPONSE;

volatile KBD_RESPONSE kbr = {0};



#define kbputchar(c) \
({ \
   if (GetKbctlEvent(KBCTL_ECHO)) { \
      putchar(c); \
   } \
})
mutex_t ml;



void KbListenKeyPress(uint8_t scanCode, KbListenCb lc) {
  if (lc == NULL) {
    return;
  }
  MutexLock(&ml);

  while (kbr.scanCode != scanCode) {
    x64_pause();
  }
  lc();
  MutexUnlock(&ml);
}

void TranslateKeyboard(unsigned char scanCode) {

  //uint32_t keyflags = 0;
  if ((scanCode & KBD_KEYUP) == 128) {


        switch (scanCode) {
          case PS2_LSHIFT_REL:
          
            SET_MASK(kbr.keyflags, KF_LSHIFT_REL);
            UNSET_MASK(kbr.keyflags, KF_LSHIFT);
            break;
          case PS2_RSHIFT_REL:
             SET_MASK(kbr.keyflags, KF_RSHIFT_REL);
             UNSET_MASK(kbr.keyflags, KF_RSHIFT);
            break;
          case PS2_LCTRL_REL:
             SET_MASK(kbr.keyflags, KF_LCTRL_REL);
             UNSET_MASK(kbr.keyflags, KF_LCTRL);
            break;
          case PS2_RCTRL_REL:
             SET_MASK(kbr.keyflags, KF_RSHIFT_REL);
             UNSET_MASK(kbr.keyflags, KF_RSHIFT);
            break;
          case PS2_LALT_REL:
            SET_MASK(kbr.keyflags, KF_LALT_REL);
            UNSET_MASK(kbr.keyflags, KF_LALT);
            break;
          case PS2_BACKSPACE_REL:
            SET_MASK(kbr.keyflags,  KF_BACKSPACE_REL);
            UNSET_MASK(kbr.keyflags, KF_BACKSPACE);

          default:
            break;
        }
    }
    else {
        switch (scanCode) {
          case PS2_LSHIFT:
            SET_MASK(kbr.keyflags, KF_LSHIFT);
            UNSET_MASK(kbr.keyflags, KF_LSHIFT_REL);
            break;
          case PS2_RSHIFT:
             SET_MASK(kbr.keyflags, KF_RSHIFT);
             UNSET_MASK(kbr.keyflags, KF_RSHIFT_REL);
            break;
          case PS2_LCTRL:
             SET_MASK(kbr.keyflags, KF_LCTRL);
             UNSET_MASK(kbr.keyflags, KF_LCTRL_REL);
            break;
          case PS2_RCTRL:
             SET_MASK(kbr.keyflags, KF_RSHIFT);
             UNSET_MASK(kbr.keyflags, KF_RSHIFT_REL);
            break;
          case PS2_CAPSLK:
             FLIP_MASK(kbr.keyflags, KF_CAPSLK);
            break;
          case PS2_BACKSPACE:
             SET_MASK(kbr.keyflags, KF_BACKSPACE);
             UNSET_MASK(kbr.keyflags, KF_BACKSPACE_REL);
            break;
          case PS2_LALT:
            SET_MASK(kbr.keyflags, KF_LALT);
            UNSET_MASK(kbr.keyflags, KF_LALT_REL);
            break;
          default:
            break;
        }
    }
    
}

mutex_t af;
NATIVECALL char KeyboardGetChar(bool echo) {
  MutexLock(&af);
 
  SetKbctlEvent(KBCTL_LOCK, false);
  SetKbctlEvent(KBCTL_ECHO, echo);

  while (!kbr.init) {
    x64_pause();
  }
  char c = kbr.c;


  SetKbctlEvent(KBCTL_LOCK, true);
  SetKbctlEvent(KBCTL_ECHO, false);
  kbr.init = false;
  MutexUnlock(&af);
  return c;

}
mutex_t km;
void NATIVECALL _keyboardcb_(reg_state_t* regs) {
   
  if (GetKbctlEvent(KBCTL_LOCK)) {
    return;
   }


   volatile unsigned char scanCode;
   volatile unsigned char kbdStatus;
   
   
   MutexLock(&km);
    
   kbdStatus = x64_inb(PORT_KBD_CMD);
   kbr.kbdStatus = kbdStatus;

   //KEYBOARD_READY
   if (kbdStatus & KBD_READY) {


       scanCode = x64_inb(PORT_KBD_DATA);
       kbr.scanCode = scanCode;
       TranslateKeyboard(scanCode);
      
    if (scanCode > SCAN_CODE_MAX) {
      MutexUnlock(&km);
      return;
    }
    char kbc;
    if ((kbr.keyflags & KF_LSHIFT) || ((kbr.keyflags & KF_CAPSLK) && (kbd_tbl_shift[scanCode] != 0))) {
      kbc = kbd_tbl_shift[scanCode];
      

    }
    else {
      kbc = kbd_tbl[scanCode];
       
    }
    
    switch(kbr.keyflags) {
      case KF_BACKSPACE:
        kbr.c = '\b';
        kbr.init = true;
        break;

      default:
        if ((uint8_t)kbc != 0) {
          kbr.c = kbc;
          kbr.init = true;
      }
    }
    
    
   
    
    //kbputchar(kbc);

    MutexUnlock(&km);
   }
}
    