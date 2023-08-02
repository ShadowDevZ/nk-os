#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


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


bool InitializeFramebuffers(struct limine_framebuffer_request lbf, struct limine_terminal_request term);