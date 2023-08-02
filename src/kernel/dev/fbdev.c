#include "sys/version.h"

#include "dev/fbdev.h"
#include "kstdio.h"
#include "limine/limine.h"
FBDEV g_Fb[FB_MAX_SUPPORT];



bool InitializeFramebuffers(struct limine_framebuffer_request lbf, struct limine_terminal_request term) {
    
    uint64_t fbcount = lbf.response->framebuffer_count;
    if (fbcount < 1) {
        return false;
    }

   // if (fbcount > FB_MAX_SUPPORT) {
   //     //todo print using E9 debug port later
   // }


    for (uint64_t i = 0; i < fbcount; i++) {
       g_Fb[i].addr = lbf.response->framebuffers[i]->address;
       g_Fb[i].bpp = lbf.response->framebuffers[i]->bpp;
       g_Fb[i].height= lbf.response->framebuffers[i]->height;
       g_Fb[i].pitch= lbf.response->framebuffers[i]->pitch;
       g_Fb[i].statusFlags= 0;//todo implement
       g_Fb[i].width= lbf.response->framebuffers[i]->width;

     //if youre wondering why we add zero its beacuse of ascii table to convert it to string;
       char c = (char)i + '0';

       char dev[FBDEV_MAX_LEN] = "fbdev";
       dev[strlen(dev)] = c;
       dev[strlen(dev) + 1] = '\0';
      // strncpy(g_Fb[i].name, dev, strlen(dev) + 1);
       term.response->write(term.response->terminals[0], dev, strlen(dev));
       term.response->write(term.response->terminals[0], "\n", 1);
        
    }

    return true;            
}
