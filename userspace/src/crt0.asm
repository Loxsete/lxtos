global _start
extern main

section .text
_start:
    xor  rbp, rbp
    pop  rdi
    mov  rsi, rsp
    and  rsp, ~0xF
    call main
    mov  rdi, rax
    mov  rax, 3
    int  0x80
    ud2