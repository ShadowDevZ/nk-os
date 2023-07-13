#pragma once

#include <sysdefs.h>

#define DEFAULT_FONT_SIZE 16

#define TABSPACE 4
typedef struct  {
    void* baseAddress; //base address where framebuffer is located
    size_t bufferSize; //size of the buffer
    uint width; //screen width
    uint height; //screen height
    uint scanLinePixels; //pixels per individual line
}FRAMEBUFFER;

typedef struct {
    uchar magic[2]; //signature 36 04
    uchar mode;
    uchar size; //size of the header

}PSF1_HEADER;
#define PSF1_MAX_PATH 64
typedef struct {
    //header of the PS1 font file
    PSF1_HEADER* header;
    //stores all characters
    void* charBuffer;
   _unused_ char fontName[PSF1_MAX_PATH];
   _unused_ uint fontSize; //determined by the name in the file for example fontxxxx16.psf -> 16

}PSF1_FONT;

typedef struct {
    uint x;
    uint y;

}CURSOR_INFO;

bool SetDefaulFont(PSF1_FONT* font);
bool SetDefaultFramebuffer(FRAMEBUFFER* fb);

HEXCLR RGB2Hex(ushort r, ushort g, ushort b);

enum FrameBufferBasicColors{
    FB_CLR_WHITE = 0Xffffff,
    FB_CLR_RED = 0xff0000,
    FB_CLR_ORANGE = 0xff6600,
    FB_CLR_YELLOW = 0xffe600,
    FB_CLR_GREEN = 0x00ff00,
    FB_CLR_BLUE = 0x0000ff,
    FB_CLR_PURPLE = 0xc300ff,
    FB_CLR_BLACK = 0x0

};

void FrameBufferPutChar(char c, HEXCLR clr);
void FrameBufferPutString(const char* str);
void FrameBufferPutClrString(const char* str, HEXCLR iclr);
void FrameBufferClearScreen();
CURSOR_INFO GetCursorInfo();

void scrollFramebuffer(uint32_t rows);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);