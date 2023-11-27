[bits 64]


; Assembly routine to enable sse support
global x64_enable_sse
x64_enable_sse:
	mov rax, cr4
	bts rax, 9		
	bts rax, 10		
	mov cr4, rax
	ret 


; Assembly routine to enable fpu support
global x64_enable_fpu
x64_enable_fpu:
	mov rax, cr0
	bts rax, 1		
	btr rax, 2		
	bts rax, 5		
	btr rax, 3		
	mov cr0, rax

	finit
	ret

global x64_enable_avx
x64_enable_avx:
    mov rax, cr4
	bts rax, 14		
	mov cr4, rax
	ret 

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
    mov rax, rsi
    mov dx, di
    out dx, al
    ret

global x64_inb
x64_inb:
    mov dx, di
    in al, dx
    ret

global x64_insb
x64_insb:
    cld
    mov dx, di
    mov rdi, rsi
    mov rcx, rcx
    repne insb
    ret

global x64_insw
x64_insw:
    cld
    mov dx, di
    mov rdi, rsi
    mov rcx, rcx
    repne insw
    ret

global x64_outsb
x64_outsb:
    cld
    mov dx, di
    mov rsi, rsi
    mov rcx, rcx
    repne outsb
    ret

global x64_outsw
x64_outsw:
    cld
    mov dx, di
    mov rsi, rsi
    mov rcx, rcx
    repne outsw
    ret




global x64_load_idt

x64_load_idt:
    push rbp
    mov rbp, rsp
    
    lidt [rdi]
    
    mov rsp, rbp
    pop rbp
    
    ret



global x64_gdt_flush
x64_gdt_flush:
    lgdt [rdi]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    pop rdi
    mov rax, 0x28
    push rax
    push rdi
    retfq

global tss_flush
x64_tss_flush:
    mov ax, 0x48
    ltr ax
    ret

global x64_rdump

x64_rdump:
    mov [rdi], rax
    mov [rdi + 8], rbx
    mov [rdi + 16], rcx
    mov [rdi + 24], rdx
    mov [rdi + 32], rsi
    mov [rdi + 40], rdi
    mov [rdi + 48], r8
    mov [rdi + 56], r9
    mov [rdi + 64], r10
    mov [rdi + 72], r11
    mov [rdi + 80], r12
    mov [rdi + 88], r13
    mov [rdi + 96], r14
    mov [rdi + 104], r15
    mov [rdi + 120], rsp
    ret

global x64_panic

x64_panic:
    cli
    hlt
    jmp $x64_panic