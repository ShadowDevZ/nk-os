#include "include/panic.h"
#include "include/isr.h"
NORET void _SystemRaiseHardError(const char* _file_, int line, const char* reason, const char* description) {
    printf("\n\n===KERNEL PANIC===\n\n");
    printf("[%s]:%d\n", _file_, line);
    printf("Reason: %s\nDescription: %s\n\n", reason, description);
    printf("Debugging info: \n");

    x64_cpu_stop();

}


void PrintReg(registers_t *reg)
{
    printf("CPU Register dump:\n\n");
    printf("rax: 0x%llx, rbx:    0x%llx, rcx: 0x%llx, rdx: 0x%llx\n"
          "rsi: 0x%llx, rdi:    0x%llx, rbp: 0x%llx, r8 : 0x%llx\n"
          "r9 : 0x%llx, r10:    0x%llx, r11: 0x%llx, r12: 0x%llx\n"
          "r13: 0x%llx, r14:    0x%llx, r15: 0x%llx, ss : 0x%llx\n"
          "rsp: 0x%llx, rflags: 0x%llx, cs : 0x%llx, rip: 0x%llx\n",
          reg->rax, reg->rbx,    reg->rcx, reg->rdx,
          reg->rsi, reg->rdi,    reg->rbp, reg->r8,
          reg->r9,  reg->r10,    reg->r11, reg->r12,
          reg->r13, reg->r14,    reg->r15, reg->ss,
          reg->rsp, reg->rflags, reg->cs,  reg->rip);
}

NORET void _SystemRaiseHardErrorEx(const char* reason, const char* description, registers_t* regs);