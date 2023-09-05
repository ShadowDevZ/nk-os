#pragma once
#include "sysdefs.h"
#include <stdbool.h>
void HALInit();
typedef int HALSTATUS;

#define HAL_DEV_NAME_MAX 256

typedef struct {
    char devName[HAL_DEV_NAME_MAX];
    uint64_t devID; //unique id... eg 0xf0008 can be GDT
    uint64_t loadedDevID // temporary identifier for currently running kernel.
    uint flags; // eg. HALD_LOADED | HALD_LOAD_OPTIONAL | HALD_NA...
    int resv;
}HALDEVICE;
void HALPrintf(const char* fmt, ...);

HALDEVICE HALRegisterDevice(const char* devName);
bool HALUnregisterDevice(HALDEVICE hd);
bool HALQueryDevice(HALDEVICE* hd);
//one of them needs to be set, other one can be passed as NULL, in case both of them are passed the devID is ignored.
bool HALLoadDevice(const char* devName, uint64_t devID);
bool HALIsDeviceLoaded(const char* devName, uint64_t devID);
