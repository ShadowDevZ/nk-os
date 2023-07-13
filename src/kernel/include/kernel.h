#pragma once
#include <sysdefs.h>
#include <kattributes.h>
#include "limine/limine.h"
#include <dev/framebuffer.h>

typedef struct {
  struct limine_framebuffer* fbInfo;
  struct limine_memmap_response* memMap;
}EXBOOTARGS;

typedef struct {
    PSF1_FONT defFont;
    FRAMEBUFFER* fb;
   struct limine_module_response* modules;
   struct limine_kernel_file_response* kernelInfo;
   struct limine_kernel_address_response* kernelAddr;



}BOOTARGS;




KERNEL_ENTRY kmain(BOOTARGS* bp);