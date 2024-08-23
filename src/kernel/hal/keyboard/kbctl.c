#include "include/kbctl.h"
#include <stdbool.h>
#include "bitsets.h"


volatile uint16_t kbCtl = 0;

void SetKbctlEvent(uint16_t event, bool set) {
    if (!IsValidFlag(event))
        return;

    if (set) {
        kbCtl |= event;
    }
    else {
        kbCtl &= ~(event);
    }
}

uint16_t GetKbctl() {
    return kbCtl;
}

bool GetKbctlEvent(uint32_t event) {
    if (kbCtl & event) {
        return true;
    }
    return false;
}