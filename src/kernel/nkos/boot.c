#include <stdint.h>
#include <stddef.h>
#include <limine/limine.h>
#include "sys/version.h"
#include "kstdio.h"


static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};
static volatile struct limine_kernel_file_request kernel_request = {
    .id = LIMINE_KERNEL_FILE_REQUEST,
    .revision = 0
};
static volatile struct limine_kernel_address_request address_request = {
    .id = LIMINE_KERNEL_ADDRESS_REQUEST,
    .revision = 0
};
// Halt and catch fire function.
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}
#include "sys/version.h"
#include "dev/fbdev.h"
// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    // Ensure we got a terminal

   
    if (terminal_request.response == NULL
     || terminal_request.response->terminal_count < 1) {
        hcf();
    }

           //bool status = InitializeFramebuffers();


    // We should now be able to call the Limine terminal to print out
    // a simple "Hello World" to screen.
  //  const char *hello_msg = "Hello World";

    

  //print(terminal ,hello_msg);
  

 terminal_request.response->write(terminal_request.response->terminals[0], "\033[31mRed text\033[0m\n", strlen("\033[31mRed text\033[0m\n"));
KVER_INFO bi = GetKernelVersion();


InitializeFramebuffers(framebuffer_request, terminal_request);

printf("Kernel booted\n");
printf("0x%02x - Physical base\n\
0x%02x - Virtual base\n", address_request.response->physical_base, address_request.response->virtual_base);
printf("%s", "==KERNEL_INFO==\n");

printf("ADDR: 0x%x\n" \
"SIZE: %lluKiB\n" \
"PATH: %s\n" \
"CMD: %s\n" \
"MEDIA: %u\n" \
"PART: %u\n" \
"MBRID: %u\n" \
"PARTUUID: {%x-%x-%x-%x}\n\n",
kernel_request.response->kernel_file->address,
kernel_request.response->kernel_file->size / 1024,
kernel_request.response->kernel_file->path,
kernel_request.response->kernel_file->cmdline,
kernel_request.response->kernel_file->media_type,
kernel_request.response->kernel_file->partition_index,
kernel_request.response->kernel_file->mbr_disk_id,
kernel_request.response->kernel_file->part_uuid.a,
kernel_request.response->kernel_file->part_uuid.b,
kernel_request.response->kernel_file->part_uuid.c,
kernel_request.response->kernel_file->part_uuid.d
);

printf("Kernel Version Info\n");
printf("Version String: %s" \
"Codename: %s\n" \
"Arch (%s)\n" \
"CC: %s\n" \
"Build time %s %s\n" \
"Version: %s",
__KERNEL_FULL_NAME,
bi.codename,
(bi.archType == 64)? "x86_64" : "x86",
bi.ccVersion,
bi.buildDate,
bi.buildTime,
bi.version->versionStr);
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