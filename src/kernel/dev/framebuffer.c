#include <sysdefs.h>
#include <dev/framebuffer.h>

CURSOR_INFO cInfo;
FRAMEBUFFER* dFb;
PSF1_FONT* dFont;
uint32_t numRowsUsed = 0;

void scrollFramebuffer(uint32_t rows) {
    uint32_t totalRows = dFb->height / DEFAULT_FONT_SIZE;

    if (rows >= numRowsUsed) {
        rows = numRowsUsed; // Scroll all used rows
    }

    uint32_t* dest = (uint32_t*)dFb->baseAddress;
    uint32_t* src = (uint32_t*)dFb->baseAddress + (rows * dFb->scanLinePixels * (DEFAULT_FONT_SIZE / 8));
    uint32_t pixelSize = (totalRows - rows) * dFb->scanLinePixels;
    uint32_t byteSize = pixelSize * sizeof(uint32_t);
    memmove(dest, src, byteSize);

    // Clear the newly visible portion at the bottom
    uint32_t clearStartRow = totalRows - rows;
    uint32_t clearRowCount = rows;
    uint32_t clearBytes = clearRowCount * dFb->width * sizeof(uint32_t);
    uint32_t* clearStart = (uint32_t*)dFb->baseAddress + (clearStartRow * dFb->scanLinePixels * (DEFAULT_FONT_SIZE / 8));
    memset(clearStart, 0, clearBytes);

    numRowsUsed -= rows;
}



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
HEXCLR RGB2Hex(ushort r, ushort g, ushort b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
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
void FrameBufferPutChar(char c, HEXCLR clr) {
    if (!IsFramebufferBinded()) {
        return;
    }

    switch (c) {
         case '\n':
            cInfo.x = 0;
            cInfo.y += DEFAULT_FONT_SIZE;
            numRowsUsed++;
            if (numRowsUsed > dFb->height / DEFAULT_FONT_SIZE) {
            scrollFramebuffer(numRowsUsed);
            
        }
            break;
        case '\t':
            cInfo.x += TABSPACE;
            break;
        case '\b':
            if (cInfo.x > 0) {
                cInfo.x -= (DEFAULT_FONT_SIZE / 2);
                FrameBufferPutCharInternal(dFb, dFont, ' ', cInfo.x, cInfo.y, clr);
            } else if (cInfo.y >= DEFAULT_FONT_SIZE) {
                cInfo.x = (dFb->width - (DEFAULT_FONT_SIZE / 2));
                cInfo.y -= DEFAULT_FONT_SIZE;
                FrameBufferPutCharInternal(dFb, dFont, ' ', cInfo.x, cInfo.y, clr);
            }
            break;
        default:
            if (cInfo.x >= dFb->width) {
                cInfo.x = 0;
                cInfo.y += DEFAULT_FONT_SIZE;
               // numRowsUsed++;
            }
            

            if (cInfo.y + DEFAULT_FONT_SIZE >= dFb->height) {
                uint32_t numScrollRows = (cInfo.y + DEFAULT_FONT_SIZE - dFb->height + 1) / DEFAULT_FONT_SIZE;
                scrollFramebuffer(numRowsUsed);
                
                cInfo.y -= numScrollRows * DEFAULT_FONT_SIZE;
            }

            FrameBufferPutCharInternal(dFb, dFont, c, cInfo.x, cInfo.y, clr);
            cInfo.x += (DEFAULT_FONT_SIZE / 2);
            break;
    }
}


void FrameBufferClearScreen() {
  uint* pixPtr = (uint*)dFb->baseAddress;
               
  for (int64_t x = 0; x < dFb->width; ++x) {
    for (int64_t y = 0; y < dFb->height; ++y) {
     //  FrameBufferPutCharInternal(dFb, dFont, 'g', x, y, FB_CLR_BLACK);
     *(uint*)(pixPtr + x + (y * dFb->scanLinePixels)) = 0;
    }
  }
  cInfo.x = 0;
  cInfo.y = 0;
   
 // *(uint*)(pixPtr + x + (y * fb->scanLinePixels)) = clr;
                
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