#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "limine/limine.h"
#include <sysdefs.h>
#include "dev/framebuffer.h"
#pragma region limine_requests

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

static volatile struct limine_rsdp_request rsdp_request = {
    .id = LIMINE_RSDP_REQUEST,
    .revision = 0
};

static volatile struct limine_module_request module_request = {
    .id = LIMINE_MODULE_REQUEST,
    .revision = 0
};

static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};
struct limine_kernel_address_request kernel_address_request = {
    .id = LIMINE_KERNEL_ADDRESS_REQUEST,
    .revision = 0, .response = NULL
};
struct limine_kernel_file_request kf_request = {
    .id = LIMINE_KERNEL_FILE_REQUEST,
    .revision = 0, .response = NULL
};

#pragma suffixregion



void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }

    return dest;
}

void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;

    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }

    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }

    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }

    return 0;
}

// Our quick and dirty strlen() implementation.
size_t strlen(const char *str) {
    size_t ret = 0;
    while (*str++) {
        ret++;
    }
    return ret;
}

bool CheckStringSuffix(const char* str, const char* suffix) {

     const char *_str = str;
     const char *_suffix = suffix;


    while (*str != 0)
        str++;
    str--;

    while (*suffix != 0)
        suffix++;
    suffix--;

    while (true)
    {
        if (*str != *suffix)
            return false;

        str--;
        suffix--;

        if (suffix == _suffix || (str == _str && suffix == _suffix))
            return true;

        if (str == _str)
            return false;
    }

    return true;

}

struct limine_file* GetLimineModule(const char* name) {
    struct limine_module_response* resp = module_request.response;
    for (size_t i = 0; i < resp->module_count; ++i) {
        struct limine_file* file = resp->modules[i];
        if (CheckStringSuffix(file->path, name)) {
            return file;
        }
    }
    return NULL;
}

static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}


void _start(void) {
    

    FRAMEBUFFER fb;
    struct limine_framebuffer* lfb = framebuffer_request.response->framebuffers[0];
    fb.baseAddress = lfb->address;
    fb.width = lfb->width;
    fb.height = lfb->height;
    fb.scanLinePixels = lfb->pitch / 4;
    fb.bufferSize = lfb->height * lfb->pitch;

    if (module_request.response == NULL) {
        hcf();
    }
    
    struct limine_file* file = GetLimineModule("zap-light16.psf");

    if (file == NULL) {
        hcf();
    }
    
    PSF1_FONT font;
    font.header = (PSF1_HEADER*)file->address;
    if (font.header->magic[0] != 0x36 || font.header->magic[1] != 0x04) {
        hcf();
    }
  

    font.charBuffer = (void*)(uint64_t)file->address + sizeof(PSF1_HEADER);

    struct limine_kernel_file_response *kf_response = kf_request.response;
    Print(&fb, &font, kf_response->kernel_file->cmdline);
    Print(&fb, &font,"\n");

      kmain(&fb, &font);

end:
    for (;;);

}