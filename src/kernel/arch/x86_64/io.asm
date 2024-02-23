[bits 64]


; Assembly routine to enable sse support
global x64_enable_sse
x64_enable_sse:
    push rbp
    mov rbp, rsp
	mov rax, cr4
	bts rax, 9	 ;enable SSE and FXSAVE/FXRSTOR for FPU	
	bts rax, 10		;unmasked SSE excpetions
	mov cr4, rax
    mov rsp, rbp
    pop rbp
	ret 


; Assembly routine to enable fpu support
global x64_enable_fpu
x64_enable_fpu:
    push rbp
    mov rbp, rsp
	mov rax, cr0
    bts rax, 5 ;enable FPU error reporting
	bts rax, 1 ; Monitor coprocessor


	btr rax, 2 ; clear the bit 0 means FPU is present
	btr rax, 3	;allows to save FPU context during task switch even if the unit is not called before
	
    mov cr0, rax
    
	finit   ;initialize FPU

    mov rsp, rbp
    pop rbp
	ret

;global x64_enable_avx
;x64_enable_avx:
;    push rbp
;
;    push rax
;    push rcx
;    push rdx
;
;    mov rbp, rsp
;    mov rax, cr4
;
;	bts rax, 14		; safer mode extensions
;	
;
;    mov cr4, rax
;
;    xgetbv
;    or eax, 7
;    xsetbv
;    pop rdx
;    pop rcx
;    pop rax
;    mov rsp, rbp
;    pop rbp
;	ret 

global x64_cpu_stop
x64_cpu_stop:
    cli
    hlt
    jmp $ ; just in case the cpu wont stop, avoid triple fault and provide debug info

global x64_EnableInterrupts
x64_EnableInterrupts:
    sti
    ret

global x64_DisableInterrupts
x64_DisableInterrupts:
    cli
    ret

global x64_outb
x64_outb:
    push rbp
    mov rbp, rsp
    mov rax, rsi
    mov dx, di
    out dx, al
    mov rsp, rbp
    pop rbp
    ret

global x64_inb
x64_inb:
    push rbp
    mov rbp, rsp
    mov dx, di
    in al, dx
    mov rsp, rbp
    pop rbp
    ret

global x64_insb
x64_insb:
    push rbp
    mov rbp, rsp
    cld
    mov dx, di
    mov rdi, rsi
    mov rcx, rcx
    repne insb
    mov rsp, rbp
    pop rbp
    ret

global x64_insw
x64_insw:
    push rbp
    mov rbp, rsp
    cld
    mov dx, di
    mov rdi, rsi
    mov rcx, rcx
    repne insw

    mov rsp, rbp
    pop rbp
    ret

global x64_outsb
x64_outsb:
    push rbp
    mov rbp, rsp
    cld
    mov dx, di
    mov rsi, rsi
    mov rcx, rcx
    repne outsb
    
    mov rsp, rbp
    pop rbp
    ret

global x64_outsw
x64_outsw:
    push rbp
    mov rbp, rsp
    cld
    mov dx, di
    mov rsi, rsi
    mov rcx, rcx
    repne outsw

    mov rsp, rbp
    pop rbp
    ret




global x64_load_idt

x64_load_idt:
    push rbp
    mov rbp, rsp
    
    lidt [rdi]
    
    mov rsp, rbp
    pop rbp
    
    ret

;%define DS64 0x30
;%define CS64 0x28
;%define TSS64 0x48
global x64_gdt_flush
x64_gdt_flush:
    
    ;pointer to GDTR arg1
    lgdt [rdi]
   ; mov ax, DS64     ;update DS as it is not updated automatically upon GDT reload
    ;DS 64 arg2
    mov ax, si
    
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    pop rdi
    ;mov rax, CS64
    ;CS64 arg3
    mov rax, rdx
    push rax
    push rdi
    retfq   ; far return, jump to the new CS

global x64_tss_flush
x64_tss_flush:
    ;mov ax, TSS64 ;todo change later
    mov ax, di
    ltr ax
    ret

;global x64_rdump

;x64_rdump:
;    mov [rdi], rax
;    mov [rdi + 8], rbx
;    mov [rdi + 16], rcx
;    mov [rdi + 24], rdx
;    mov [rdi + 32], rsi
;    mov [rdi + 40], rdi
;   mov [rdi + 48], r8
;   mov [rdi + 56], r9
;    mov [rdi + 64], r10
;    mov [rdi + 72], r11
;    mov [rdi + 80], r12
;    mov [rdi + 88], r13
;    mov [rdi + 96], r14
;    mov [rdi + 104], r15
;    mov [rdi + 120], rsp
;    ret

global x64_panic

x64_panic:
    cli
    hlt
    jmp $x64_panic

global x64_cli
x64_cli:
    cli
    ret

global x64_sti
x64_sti:
    sti
    ret

global x64_rdtsc
x64_rdtsc:
    push rbp
    mov rbp, rsp
    cli     ;just in case so the IRQ0 doesn't mess things up
    rdtsc   ;gets TSC into EDX:EAX, so we need to combine becasuse we are unable to use 32bit registers
    sti


    shl rdx, 32
    or rax, rdx

    mov rsp, rbp
    pop rbp
    ret

global x64_readcs

x64_readcs:
    push rbp
    mov rbp, rsp
    mov rax, cs

    mov rsp, rbp
    pop rbp
    ret
global x64_readtr
x64_readtr:
    push rbp
    mov rbp, rsp
    ;store task register
    str ax
    mov rsp, rbp
    pop rbp
    ret

global x64_readds
x64_readds:
    push rbp
    mov rbp, rsp
    mov rax, ds

    mov rsp, rbp
    pop rbp
    ret




global x64_sreg
%define X64_SREG_GDT 0
%define X64_SREG_IDT 1

x64_sreg:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    cmp al, X64_SREG_GDT
    je .gdts
    cmp al, X64_SREG_IDT
    je .idts

    jmp .none


.gdts:
    sgdt [sloc]
    jmp .main
.idts:
    sidt [sloc]
    jmp .main
.none:
    mov word [rsi], 0
    mov qword [rsi+2], 0
    jmp .end


.main:

   

    
    
    mov rax, 0         

    ; Load limit (lower 2 bytes) into AX
    mov ax, word [sloc]    

   
    mov word [rsi], ax           ; Store limit at the beginning of the structure
    mov rax, qword [sloc + 2]
    mov qword [rsi + 2], rax     ; Store address after the limit
    
.end:
    mov rsp, rbp
    pop rbp
    ret


section .bss
sloc:    resb 10
