#include "include/bitsets.h"

bool IsValidFlag(uint32_t flag) {
    if (flag == 0) {
        return false;
    }
    else if ((flag & (flag - 1)) == 0){
        return true;
    }
    else {
        return false;
    }
}