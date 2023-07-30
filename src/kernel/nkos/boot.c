#include <stdint.h>
#include <stddef.h>
#include <limine/limine.h>
#include "sys/version.h"
#include "kstdio.h"


// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

// GCC and Clang reserve the right to generate calls to the following
// 4 functions even if they are not directly called.
// Implement them as the C specification mandates.
// DO NOT remove or rename these functions, or stuff will eventually break!
// They CAN be moved to a different .c file.



// Halt and catch fire function.
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}
#include "sys/version.h"

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    // Ensure we got a terminal
    if (terminal_request.response == NULL
     || terminal_request.response->terminal_count < 1) {
        hcf();
    }

              


    // We should now be able to call the Limine terminal to print out
    // a simple "Hello World" to screen.
  //  const char *hello_msg = "Hello World";

    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    #define print(terminal, str) terminal_request.response->write(terminal, str, strlen(str))
  //print(terminal ,hello_msg);


KVER_INFO bi = GetKernelVersion();
print(terminal, " Hello number 1\n");
print(terminal, " Hello number 2\n");
print(terminal, " Hello number 3\n");
print(terminal, " Hello number 4\n");
print(terminal, " Hello number 5\n");
print(terminal, " Hello number 6\n");
print(terminal, "\x1B[31mHello number 6\n\x1B[0m");
print(terminal, bi.version->versionStr);

//*(unsigned int *)(pixPtr + 0 + (8 * fb->pitch / 4)) = 0xff0000;

//for (int64_t y = 2; y < 20 + 16; y++) {
//    for (int64_t x = 1; x < 10 + 8; x++) {
//        if (x >= 0 && x < fb->width && y >= 0 && y < fb->height) {
//                      *(unsigned int *)(pixPtr + x + (y * fb->pitch / 4)) = 0xff0000;
//        }
//    }
//}



    // We're done, just hang...
    hcf();
}