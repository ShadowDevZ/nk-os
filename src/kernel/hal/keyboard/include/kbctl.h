#pragma once
#include "keyboard.h"
#include <stdint.h>
#include <stdbool.h>


void SetKbctlEvent(uint16_t event, bool set);
uint16_t GetKbctl();
bool GetKbctlEvent(uint32_t event);

enum KEYBOARD_CTL{
    KBCTL_RESET = 1 << 0,
    KBCTL_ECHO = 1 << 1,
    KBCTL_LOCK = 1 << 2,
    KBCTL_SCAN_ECHO = 1 << 3,
    KBCTL_HOOKS = 1 << 4

};

//void RegisterKeyCallback(uint16_t keyCombination, unsigned char key) { }

//vkl virtual key lowercase
//vku virtual key uppercase
//enum VIRTUAL_KEYS {
//    VKL_A
//};