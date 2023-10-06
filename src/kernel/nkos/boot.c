#include <stdint.h>
#include <stddef.h>
#include <limine/limine.h>
#include "sys/version.h"
#include "kstdio.h"
#include "../arch/x86_64/include/io.h"
#include "../arch/x86_64/include/gdt.h"
#include "../arch/x86_64/include/isr.h"
#include "../arch/x86_64/include/idt.h"
volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

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





void _start(void) {
    // Ensure we got a terminal

   
    if (terminal_request.response == NULL
     || terminal_request.response->terminal_count < 1) {
        hcf();
    }

           


InitializeFramebuffers(framebuffer_request, terminal_request);


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
PIT_SetFrequency(100);
//x64_enable_avx();
//SystemRaiseHardError("Test", "Debug");

int ret = kmain();
SystemRaiseHardError("KMAIN_RETURNED", "Kernel main returned, this should not be happening");


    // We're done, just hang...
    hcf();
}