#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "tinyprintf.h"

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
    struct limine_terminal_request lr;

}FBDEV;

#define FBDEV_DEFAULT 0
bool InitializeFramebuffers(struct limine_framebuffer_request lbf, struct limine_terminal_request term);

void FbPutChar(_unused_ void* putp, char c);
#define FbPutChar(c) _FbPutChar(NULL, c);