#include "include/panic.h"
#include "include/isr.h"
#include "sysdefs.h"
#include "kattributes.h"
#define STOP_CODE_MAXLEN 60

NORET void DebugPageFault(void* addr) {
    uint64_t* v;
    if (addr != NULL) {
        v = (uint64_t*)addr;
    }
    else {
        v = (uint64_t*)(KERNEL_LOAD_ADDR + 111111111111111UL);
    }

   
   printf("%d", *v);
   UNREACHABLE();
}

NORET void _SystemRaiseHardError(const char* _file_, int* line, const char* reason, const char* description, reg_state_t* regs) {
    printf("\n\n\033[31m===KERNEL PANIC===\033[0m\n\n");
    //line can be set to NULL if the function is called manually without macro
    

    if (_file_ != NULL || line != NULL) {

        printf("[%s]:%d\n", _file_, *line);
    }
    
    char stopCode[STOP_CODE_MAXLEN];
    //IKP=internal kernel panic, for kernel modules its EKP
    snprintf(stopCode, STOP_CODE_MAXLEN, "IKP_%s", reason);
    
    for (size_t i = 0; i < strlen(stopCode); ++i) {
        stopCode[i] = toupper(stopCode[i]);
    }
    if (!strncmp(stopCode, "IKP_ISR_STOP", STOP_CODE_MAXLEN)) {
        snprintf(stopCode, STOP_CODE_MAXLEN, "%s_%ld",stopCode, regs->isr_number);
    } 
  
    printf("Reason: %s\nDescription: %s\n\n", stopCode, description);
    printf("Debugging info: \n");

    if (regs != NULL) {
        char** exception_messages = GetIsrExceptionList();
      printf("Hardware interrupt [0x%02x]::Interrupt description: %s\n", regs->isr_number, exception_messages[regs->isr_number]);
        PrintRegs(regs);
    }
    else {
        printf("!! No register info was provided\n");
    }
    printf("\n\n\033[31m===KERNEL PANIC===\033[0m\n\n");
   
    x64_cpu_stop();
    UNREACHABLE();

}


void PrintRegs(reg_state_t* reg)
{

    if (reg == NULL) {
        printf("<NULL>\n");
    }


    printf("CPU Register dump:\n\n");
    //todo make it print in columns
    printf("     rax: 0x%04X  rbx: 0x%04X rcx: 0x%04X  rdx: 0x%04X \n \
    rsp: 0x%04X  rbp: 0x%04X  rsi: 0x%04x \n \
    rdi: 0x%04X  r8: 0x%04X  r9: 0x%04X  r10: 0x%04X \n \
    r11: 0x%04X  r12: 0x%04X r13: 0x%04X  r14: 0x%04X \n \
    r15: 0x%04X  ss: 0x%04X  rflag: 0x%04X  cs: 0x%04X \n \
    rip: 0x%04x  err: 0x%04X  isr: 0x%04X",
    reg->gp.rax, reg->gp.rbx, reg->gp.rcx, reg->gp.rdx,
    reg->gp.rsp, reg->gp.rbp, reg->gp.rsi, reg->gp.rdi,
    reg->gp.r8, reg->gp.r9, reg->gp.r10, reg->gp.r11,
    reg->gp.r12, reg->gp.r13, reg->gp.r14, reg->gp.r15,
    reg->er.ss, reg->er.rflags, reg->er.cs, reg->er.rip,
    reg->error_code, reg->isr_number);

}

NORET void _SystemRaiseHardErrorEx(const char* reason, const char* description, reg_state_t* regs);