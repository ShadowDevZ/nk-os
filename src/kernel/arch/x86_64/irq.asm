extern IRQ_Handler

;%macro X64_IRQ 1
;global X64_IRQ%1
;X64_IRQ%1:
;    cld ; just in case the DF is set, clearing it is required by SYSVABI
;    cli
;    push rdi
;    mov rdi, %1+32 ;pass remapped address to the handler
;    call IRQ_Handler
;    pop rdi
;    sti
;    iretq
;%endmacro
%include "macros.inc"
%macro X64_IRQ 1
global X64_IRQ%1
%define IRQ_MAGIC_NUMBER 0xEF85A2C

X64_IRQ%1:
    cld
    ;IRQ_MAGIC_NUMBER means that the register dump was obtained
    ;during the IRQ call and not ISR
    push IRQ_MAGIC_NUMBER
    push %1 + 32
    PUSHAQ
    
    
    ;first argument is intno
    ;mov rdi, %1 + 32

    ;second argument are registers
    ;mov rsi, rsp
    mov rdi, rsp
    call IRQ_Handler
   
    POPAQ
    add rsp, 16

    iretq

%endmacro

X64_IRQ 0
X64_IRQ 1
X64_IRQ 2
X64_IRQ 3
X64_IRQ 4
X64_IRQ 5
X64_IRQ 6
X64_IRQ 7
X64_IRQ 8
X64_IRQ 9
X64_IRQ 10
X64_IRQ 11
X64_IRQ 12
X64_IRQ 13
X64_IRQ 14
X64_IRQ 15


global irqHandlers
irqHandlers:
    dq X64_IRQ0
    dq X64_IRQ1
    dq X64_IRQ2
    dq X64_IRQ3
    dq X64_IRQ4
    dq X64_IRQ5
    dq X64_IRQ6
    dq X64_IRQ7
    dq X64_IRQ8
    dq X64_IRQ9
    dq X64_IRQ10
    dq X64_IRQ11
    dq X64_IRQ12
    dq X64_IRQ13
    dq X64_IRQ14
    dq X64_IRQ15

