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


global load_gdt

load_gdt:
    lgdt [rdi]
    ret



global load_idt

load_idt:
    lidt [rdi]
    ret


[bits 64]

align 0x10

gdt:
  null_descriptor:
    dw 0x0000
    dw 0x0000
    db 0x00
    db 00000000b
    db 00000000b
    db 0x00

  kernel_code_64:
    dw 0x0000
    dw 0x0000
    db 0x00
    db 10011010b
    db 00100000b
    db 0x00

  kernel_data:
    dw 0x0000
    dw 0x0000
    db 0x00
    db 10010010b
    db 00000000b
    db 0x00

  user_data_64:
    dw 0x0000
    dw 0x0000
    db 0x00
    db 11110010b
    db 00000000b
    db 0x00

gdt_end:

global gdt_ptr

gdt_ptr:
  dw gdt_end - gdt - 1
  dq gdt


CODE_SEG equ kernel_code_64 - gdt
DATA_SEG equ kernel_data - gdt

global init_gdt
init_gdt:
  lgdt [gdt_ptr]
  mov rax, rsp
  push DATA_SEG
  push rax
  pushfq
  push CODE_SEG
  push flush
  iretq
  flush:
  mov ax, DATA_SEG
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  ret



global gdt_flush
gdt_flush:
    lgdt [rdi]
    mov ax, 0x30
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
tss_flush:
    mov ax, 0x48
    ltr ax
    ret