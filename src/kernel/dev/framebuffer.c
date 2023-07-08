#include <sysdefs.h>
#include <dev/framebuffer.h>

CURSOR_INFO cInfo;

void FrameBufferPutChar(FRAMEBUFFER* fb, PSF1_FONT* font, char chr, uint xOff, uint yOff, ICOLOR clr) {
      uint* pixPtr = (uint*)fb->baseAddress;
      char* fontPtr = (char*)font->charBuffer + (chr * font->header->size);

      for (int64_t y = yOff; y < yOff + DEFAULT_FONT_SIZE;y++ ) {


         for (int64_t x = xOff; x < xOff + (DEFAULT_FONT_SIZE / 2); x++) {


             if (x >= 0 && x < fb->width && y >= 0 && y < fb->height) {


            
                if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0) {
                       *(uint*)(pixPtr + x + (y * fb->scanLinePixels)) = clr;
                }
            }
        }
    fontPtr++;
  }



}

void Print(FRAMEBUFFER* fb, PSF1_FONT* psf1_font, const char* str) {
  char* chr = (char*)str;
  while (*chr != 0) {
    switch (*chr) {
      case '\n':
        cInfo.x = 0;
        cInfo.y += DEFAULT_FONT_SIZE;
        break;
      case '\t':
        cInfo.x += (DEFAULT_FONT_SIZE / 2);
        break;
      default:
        FrameBufferPutChar(fb, psf1_font, *chr, cInfo.x, cInfo.y, 0xFFFFFFFF);
        cInfo.x += (DEFAULT_FONT_SIZE / 2);
        break;
    }

    if (cInfo.x + (DEFAULT_FONT_SIZE / 2) > fb->width) {
      cInfo.x = 0;
      cInfo.y += DEFAULT_FONT_SIZE;
    }
    chr++;
  }
}
