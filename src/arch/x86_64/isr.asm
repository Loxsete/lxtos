global isr0
global isr128
global isr_common
extern isr_handler
extern syscall_handler

isr0:
    push 0
    push 0
    jmp isr_common

isr128:
    push 0
    push 128
    jmp isr_common

isr_common:
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11

    mov rdi, rsp
    call isr_handler

    pop r11
    pop r10
    pop r9
    pop r8
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax

    add rsp, 16
    iretq
