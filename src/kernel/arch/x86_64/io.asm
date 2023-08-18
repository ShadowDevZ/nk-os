[bits 64]



global x64_panic
x64_panic:
    cli
    hlt

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
