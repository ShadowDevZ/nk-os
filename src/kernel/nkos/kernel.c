#include "sysdefs.h"
#include "dev/framebuffer.h"
#include "kernel.h"

KERNEL_ENTRY kmain(BOOTARGS* bp) {
    FrameBufferPutString("Hello from Fbuffer");
    CURSOR_INFO cx =  GetCursorInfo();
   // FrameBufferPutChar(' ', cx.x, cx.y, 0xFFFFFF);

end:
    for (;;);

}