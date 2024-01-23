#pragma once
#include <stddef.h>

#include <stdbool.h>
#define SYM_NAME_MAXLEN 256
#include <stdint.h>
#include "sysdefs.h"
typedef struct {
    void* addr;
    char name[SYM_NAME_MAXLEN];
}KsymList;
extern const KsymList __symbols__[];
uint64_t KsymCount();
void* KsymFind(const char* name);
const char* KsymResolveAddress(void* addr);
typedef struct {
    uint64_t index;
    KsymList list;
}SYM_ENUM_STATE;

bool KsymEnumSymbol(SYM_ENUM_STATE* state);

void DumpSymbolTable();