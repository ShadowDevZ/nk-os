#include <stdint.h>
#include <stddef.h>
#include <limine/limine.h>
#include "sys/version.h"
#include "kstdio.h"
#include "../arch/x86_64/include/io.h"
#include "../arch/x86_64/include/gdt.h"
#include "../arch/x86_64/include/isr.h"
#include "../arch/x86_64/include/idt.h"
#include "../dev/flanterm/flanterm.h"
#include "../dev/flanterm/backends/fb.h"


volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};
volatile struct limine_kernel_file_request kernel_request = {
    .id = LIMINE_KERNEL_FILE_REQUEST,
    .revision = 0
};
volatile struct limine_kernel_address_request address_request = {
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
#include "include/panic.h"
#include "../hal/timer/include/uptime.h"


// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.


struct flanterm_context *ft_ctx;


void _start(void) {
    // Ensure we got a terminal
if (framebuffer_request.response->framebuffer_count < 1 || framebuffer_request.response->framebuffers[0] == NULL) {
    hcf();
} 
   
   
ft_ctx = flanterm_fb_simple_init(
    framebuffer_request.response->framebuffers[0]->address, framebuffer_request.response->framebuffers[0]->width, framebuffer_request.response->framebuffers[0]->height, \
     framebuffer_request.response->framebuffers[0]->pitch);

const char msg[] = "Hello world\n";
flanterm_write(ft_ctx, msg, sizeof(msg));

InitializeFramebuffers(&framebuffer_request);


printf("Kernel booted\n");
printf("0x%02llx - Physical base\n\
0x%02x - Virtual base\n", address_request.response->physical_base, address_request.response->virtual_base);
printf("%s", "==KERNEL_INFO==\n");

printf("ADDR: 0x%p\n" \
"SIZE: %luKiB\n" \
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
*kernel_request.response->kernel_file->part_uuid.d
);



KVER_INFO bi = GetKernelVersion();
printf("Kernel Version Info\n");
printf("Version String: %s" \
"Codename: %s\n" \
"Arch (%s) - SystemV ABI\n" \
"CC: %s\n" \
"Build time %s %s\n" \
"Version: %s",
"NK icefox",
bi.codename,
(bi.archType == 64)? "x86_64" : "x86",
bi.ccVersion,
bi.buildDate,
bi.buildTime,
bi.version->versionStr);



InitializeGDT();

InitializeIDT();


ISR_Init();
//asm("sti");

x64_enable_sse();
x64_enable_fpu();

//x64_enable_avx();
//SystemRaiseHardError("Test", "Debug");
Fb_SwitchStream(FBDEV_DEFAULT, FB_OUTPUT_BROADCAST);

int ret = kmain();
SystemRaiseHardError("KMAIN_RETURNED", "Kernel main returned, this should not be happening");


    // We're done, just hang...
    hcf();
}