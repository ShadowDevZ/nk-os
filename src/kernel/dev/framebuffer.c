#include <sysdefs.h>
#include <dev/framebuffer.h>

CURSOR_INFO cInfo;
FRAMEBUFFER* dFb;
PSF1_FONT* dFont;

INTERNAL void FrameBufferPutCharInternal(FRAMEBUFFER* fb, PSF1_FONT* font, char chr, uint xOff, uint yOff, HEXCLR clr) {
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
bool IsFramebufferBinded() {
  if (dFb == NULL || dFont == NULL) {
    //for now return -1. In future return. NK_FB_EBIND when we introduce error handling
    return false;
  }
  return true;
}



CURSOR_INFO GetCursorInfo() {
  return cInfo;

}
bool SetDefaultFramebuffer(FRAMEBUFFER* fb) {
  if (fb == NULL) {
    return false;
  }
  dFb = fb;
  return true;
}

bool SetDefaulFont(PSF1_FONT* font) {
  if (font == NULL) {
    return false;
  }
  dFont = font;
  return true;
}


void FrameBufferPutString(const char* str) {
  FrameBufferPutClrString(str, 0xFFFFFF);
}

void FrameBufferPutClrString(const char* str, HEXCLR iclr) {
  if (!IsFramebufferBinded()) {
    return;
  }
  

  char* chr = (char*)str;
  while (*chr != 0) {
    
        FrameBufferPutChar(*chr, iclr);
        cInfo.x += (DEFAULT_FONT_SIZE / 2);
       
    

   
    chr++;
  }
}
int FrameBufferPutChar(char c, HEXCLR clr) {
  
  if (!IsFramebufferBinded()) {
    return -1;
  }
  switch (c)
  {
  case '\n':
    cInfo.x = 0;
    cInfo.y += DEFAULT_FONT_SIZE;
    break;
  case '\t':
     cInfo.x += TABSPACE;
      break;
  case '\b':
    cInfo.x = 0;
      break;
    
  default:
     FrameBufferPutCharInternal(dFb, dFont, c, cInfo.x, cInfo.y, clr);
        
      break;
  }


  if (cInfo.x + (DEFAULT_FONT_SIZE / 2) > dFb->width) {
      cInfo.x = 0;
      cInfo.y += DEFAULT_FONT_SIZE;
    }

  return 0;

}

/*
void FrameBufferPutString(const char* str) {
  if (!IsFramebufferBinded()) {
    return;
  }
  

  char* chr = (char*)str;
  while (*chr != 0) {
    
        FrameBufferPutChar(*chr, cInfo.x, cInfo.y, 0xFFFFFFFF);
        cInfo.x += (DEFAULT_FONT_SIZE / 2);
       
    int FrameBufferPutChar(char c, uint xOff, uint yOff, HEXCLR clr)

    if (cInfo.x + (DEFAULT_FONT_SIZE / 2) > dFb->width) {
      cInfo.x = 0;
      cInfo.y += DEFAULT_FONT_SIZE;
    }
    chr++;
  }
}

*/

/*
void FrameBufferPutString(const char* str) {
  if (!IsFramebufferBinded()) {
    return;
  }
  

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
        FrameBufferPutChar(*chr, cInfo.x, cInfo.y, 0xFFFFFFFF);
        cInfo.x += (DEFAULT_FONT_SIZE / 2);
        break;
    }

    if (cInfo.x + (DEFAULT_FONT_SIZE / 2) > dFb->width) {
      cInfo.x = 0;
      cInfo.y += DEFAULT_FONT_SIZE;
    }
    chr++;
  }
}
*/