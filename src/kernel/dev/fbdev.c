#include "sys/version.h"

#include "dev/fbdev.h"
#include "kstdio.h"
#include "limine/limine.h"
#include "limattr.h"
//FBDEV g_Fb[FB_MAX_SUPPORT];


STREAM_TYPE gStream[FB_MAX_SUPPORT];





STREAM_TYPE Fb_GetStreamType([[_unused_]]int fbIndex) {
  return gStream[FBDEV_DEFAULT];
}

bool Fb_SwitchStream(int fbIndex, int streamType) {
// if (streamType == FB_OUTPUT_DBG_E9 || streamType == FB_OUTPUT_STDIO) {
 // gStream[FBDEV_DEFAULT] = streamType;
 // return true;
// }
// return false;
  
switch(streamType) {
  case FB_OUTPUT_DBG_E9:
  case FB_OUTPUT_BROADCAST:
  case FB_OUTPUT_STDIO:
  gStream[FBDEV_DEFAULT] = streamType;
  break;
  default:
    gStream[FBDEV_DEFAULT] = FB_OUTPUT_STDIO;
    
}
return true;


}
#include "include/io.h"


void _FbPutString(const char* str) {
 // g_Fb[FBDEV_DEFAULT].lr.response->write(g_Fb[FBDEV_DEFAULT].lr.response->terminals[FBDEV_DEFAULT], str, strlen(str));
 terminal_request.response->write(terminal_request.response->terminals[FBDEV_DEFAULT], str, strlen(str));
}

void ClearFbScreen([[_unused_]]int fbIndex) {
  _FbPutString("\e[1;1H\e[2J");
}

void _putchar(char character) {
  _FbPutChar(NULL, character);
}

void _FbPutChar(_unused_ void* putp, char c) {
 char str[2];
 str[0] = c;
 str[1] = '\0';
 //if (Fb_GetStreamType(0) == FB_OUTPUT_DBG_E9) {
 // x64_outb(0xE9, c);
 // return;
 //}
 switch(Fb_GetStreamType(FBDEV_DEFAULT)) {
  case FB_OUTPUT_DBG_E9:
    x64_outb(0xE9, c);
    break;
  case FB_OUTPUT_BROADCAST:
    x64_outb(0xE9, c);
    _FbPutString(str);
    break;
  case FB_OUTPUT_STDIO:
  default:
    _FbPutString(str);
    break;

 }
 
 
 //g_Fb[FBDEV_DEFAULT].lr.response->write(g_Fb[FBDEV_DEFAULT].lr.response->terminals[FBDEV_DEFAULT], str, 2);
 //_FbPutString(str);
}



bool InitializeFramebuffers(struct limine_framebuffer_request lbf, struct limine_terminal_request term) {
   

  
  //  init_printf(NULL, _FbPutChar);

    return true;            
}
