#include "include/panic.h"
#include "include/isr.h"

#define STOP_CODE_MAXLEN 60

NORET void _SystemRaiseHardError(const char* _file_, int line, const char* reason, const char* description, isr_state_t* regs) {
    printf("\n\n\033[31m===KERNEL PANIC===\033[0m\n\n");
  
    if (_file_ != NULL || line != NULL) {
        printf("[%s]:%d\n", _file_, line);
    }
    
    char stopCode[STOP_CODE_MAXLEN];
    //IKP=internal kernel panic, for kernel modules its EKP
    snprintf(stopCode, STOP_CODE_MAXLEN, "IKP_%s", reason);
    
    for (int i = 0; i < strlen(stopCode); ++i) {
        stopCode[i] = toupper(stopCode[i]);
    }
    if (!strncmp(stopCode, "IKP_ISR_STOP", STOP_CODE_MAXLEN)) {
        snprintf(stopCode, STOP_CODE_MAXLEN, "%s_%d",stopCode, regs->isr_number);
    } 
  
    printf("Reason: %s\nDescription: %s\n\n", stopCode, description);
    printf("Debugging info: \n");

    if (regs != NULL) {
        char** exception_messages = GetIsrExceptionList();
      printf("Hardware interrupt [%lu]::Interrupt description: %s\n", regs->isr_number, exception_messages[regs->isr_number]);
        PrintRegs(regs);
    }
    else {
        printf("!! No register info was provided\n");
    }
    printf("\n\n\033[31m===KERNEL PANIC===\033[0m\n\n");
   
    x64_cpu_stop();

}


void PrintRegs(isr_state_t* reg)
{
    printf("CPU Register dump:\n\n");
    printf("rax: 0x%llx, rbx:    0x%llx, rcx: 0x%llx, rdx: 0x%llx\n"
          "rsi: 0x%llx, rdi:    0x%llx, rbp: 0x%llx, r8 : 0x%llx\n"
          "r9 : 0x%llx, r10:    0x%llx, r11: 0x%llx, r12: 0x%llx\n"
          "r13: 0x%llx, r14:    0x%llx, r15: 0x%llx, ss : 0x%llx\n"
          "rsp: 0x%llx, rflags: 0x%llx, cs : 0x%llx, rip: 0x%llx\n",
          reg->gp.rax, reg->gp.rbx,    reg->gp.rcx, reg->gp.rdx,
          reg->gp.rsi, reg->gp.rdi,    reg->gp.rbp, reg->gp.r8,
          reg->gp.r9,  reg->gp.r10,    reg->gp.r11, reg->gp.r12,
          reg->gp.r13, reg->gp.r14,    reg->gp.r15, reg->er.ss,
          reg->er, reg->er.rflags, reg->er.cs,  reg->er.rip);
}

NORET void _SystemRaiseHardErrorEx(const char* reason, const char* description, isr_state_t* regs);