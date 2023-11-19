#include "ksyms.h"
#include "kstdio.h"
#include <stddef.h>
#include "sysdefs.h"
#include <stdbool.h>

NATIVECALL uint64_t KsymCount() {
    uint64_t i = 0;
    for (i; symbols[i].addr != NULL; ++i);
    return i;
}

void* KsymFind(const char* name) {
    for (uint64_t i = 0; symbols[i].addr != NULL; ++i) {
        if (!strncmp(name, symbols[i].name, SYM_NAME_MAXLEN)) {
            return symbols[i].addr;
        }
    }
    return NULL;
}
const char* KsymResolveAddress(void* addr) {
    for (uint64_t i = 0; symbols[i].addr != NULL; ++i) {
        if (addr == symbols[i].addr) {
            return symbols[i].name;
        }
    }
    return NULL;
}


bool KsymEnumSymbol(SYM_ENUM_STATE* state) {
     for (uint64_t i = state->index; symbols[i].addr != NULL; ++i) {
        state->list.addr = symbols[i].addr;
        snprintf(state->list.name, SYM_NAME_MAXLEN, "%s", symbols[i].name);
        state->index++;
        return true;
    }
    return false;
}
void* KsymGetSymbolIndex(uint64_t* addr) {
    for (uint64_t i = 0; symbols[i].addr != NULL; ++i) {
       if (symbols[i].addr == addr) {
        return i;
       }
    }
    return NULL;
  
}