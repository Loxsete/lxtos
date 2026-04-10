global gdt_load
global gdt_flush_segments
global tss_load

section .text

gdt_load:
    lgdt [rdi]
    pop rdi
    push 0x08
    push rdi
    retfq

gdt_flush_segments:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret

tss_load:
    ltr di
    ret
