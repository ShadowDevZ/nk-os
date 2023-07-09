#include "sysdefs.h"
#include "dev/framebuffer.h"


KERNEL_ENTRY kmain(FRAMEBUFFER* fb, PSF1_FONT* font) {
    Print(fb, font, "Hello from Fbuffer");


end:
    for (;;);

}