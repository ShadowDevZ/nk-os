#pragma once

#include <sysdefs.h>

#define DEFAULT_FONT_SIZE 16

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

typedef struct {
    //header of the PS1 font file
    PSF1_HEADER* header;
    //stores all characters
    void* charBuffer;
   _unused_ uint fontSize; //determined by the name in the file for example fontxxxx16.psf -> 16

}PSF1_FONT;

typedef struct {
    uint x;
    uint y;

}CURSOR_INFO;


void FrameBufferPutChar(FRAMEBUFFER* fb, PSF1_FONT* font, char chr, uint xOff, uint yOff, ICOLOR clr);
void Print(FRAMEBUFFER* fb, PSF1_FONT* psf1_font, const char* str);