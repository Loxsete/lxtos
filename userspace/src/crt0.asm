global _start
extern main

section .text
_start:
    xor  rbp, rbp
    call main
    mov  rdi, rax
    mov  rax, 3
    int  0x80
    ud2
