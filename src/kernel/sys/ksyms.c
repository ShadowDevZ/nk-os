#include "ksyms.h"
#include "kstdio.h"
#include <stddef.h>
#include "sysdefs.h"
#include <stdbool.h>

//#define BUILD_BOOTSTRAP
#ifndef BUILD_BOOTSTRAP
NATIVECALL uint64_t KsymCount() {
    uint64_t i = 0;
    for (i; __symbols__[i].addr != NULL; ++i);
    return i;
}

void* KsymFind(const char* name) {
    for (uint64_t i = 0; __symbols__[i].addr != NULL; ++i) {
        if (!strncmp(name, __symbols__[i].name, SYM_NAME_MAXLEN)) {
            return __symbols__[i].addr;
        }
    }
    return NULL;
}
const char* KsymResolveAddress(void* addr) {
    for (uint64_t i = 0; __symbols__[i].addr != NULL; ++i) {
        if (addr == __symbols__[i].addr) {
            return __symbols__[i].name;
        }
    }
    return NULL;
}


bool KsymEnumSymbol(SYM_ENUM_STATE* state) {
     for (uint64_t i = state->index; __symbols__[i].addr != NULL; ++i) {
        state->list.addr = __symbols__[i].addr;
        snprintf(state->list.name, SYM_NAME_MAXLEN, "%s", __symbols__[i].name);
        state->index++;
        return true;
    }
    return false;
}
int KsymGetSymbolIndex(uint64_t* addr) {
    for (uint64_t i = 0; __symbols__[i].addr != NULL; ++i) {
       if (__symbols__[i].addr == addr) {
        return i;
       }
    }
    return -1;
  
}

void DumpSymbolTable() {
     SYM_ENUM_STATE st = {0};
     while (KsymEnumSymbol(&st)) {
        debugf("AD: 0x%llX NM: %s()\n", st.list.addr , st.list.name); // Updated format specifiers
    }
    
}
#endif