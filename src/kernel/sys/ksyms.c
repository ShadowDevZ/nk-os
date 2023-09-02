#include "ksyms.h"
#include "kstdio.h"
#include <stddef.h>

#include <stdbool.h>
void KsymDebugDump() {
    for (uint64_t i = 0; symbols[i].addr != NULL && symbols[i].name != NULL; ++i) {
        printf("ADDR: 0x%x NAME: %s\n", symbols[i].addr, symbols[i].name);
    }
    printf("\n");

}
NATIVECALL uint64_t KsymCount() {
    uint64_t i = 0;
    for (i; symbols[i].addr != NULL && symbols[i].name != NULL; ++i);
    return i;
}

void* KsymFind(const char* name) {
    for (uint64_t i = 0; symbols[i].addr != NULL && symbols[i].name != NULL; ++i) {
        if (!strncmp(name, symbols[i].name, SYM_NAME_MAXLEN)) {
            return symbols[i].addr;
        }
    }
    return NULL;
}
const char* KsymResolveAddress(void* addr) {
    for (uint64_t i = 0; symbols[i].addr != NULL && symbols[i].name != NULL; ++i) {
        if (addr == symbols[i].addr) {
            return symbols[i].name;
        }
    }
    return NULL;
}


bool KsymEnumSymbol(SYM_ENUM_STATE* state) {
     for (uint64_t i = state->index; symbols[i].addr != NULL && symbols[i].name != NULL; ++i) {
        state->list.addr = symbols[i].addr;
        snprintf(state->list.name, SYM_NAME_MAXLEN, "%s", symbols[i].name);
        state->index++;
        return true;
    }
    return false;
}