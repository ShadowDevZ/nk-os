#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "printf.h"
#include "limine.h"
#define FB_MAX_SUPPORT 5
#define FBDEV_MAX_LEN 10
typedef struct {
    void* addr;
    char name[FBDEV_MAX_LEN];
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
    uint64_t bpp;
    //eg. is locked, readonly, systemprotected,
    uint32_t statusFlags; 


}FBDEV;

#define FBDEV_DEFAULT 0
bool InitializeFramebuffers(volatile struct limine_framebuffer_request* lbf);

void _FbPutChar(void* putp, char c);
#define FbPutChar(c) _FbPutChar(NULL, c);

typedef int STREAM_TYPE;

bool Fb_SwitchStream(int fbIndex, int streamType);
STREAM_TYPE Fb_GetStreamType(int fbIndex);


void _FbPutString(const char* str);
void ClearFbScreen([[_unused_]]int fbIndex);


//print to the default TERM set by kernel
#define FB_OUTPUT_STDIO 0xDE5
//print to e9 debug port
#define FB_OUTPUT_DBG_E9 0xE98
//broadcast the message to all terminals, debug ports and every ouput defined by kernel
#define FB_OUTPUT_BROADCAST 0xF86
//for now, later use function to reset to previous
#define FB_OUTPUT_RESET FB_OUTPUT_STDIO

