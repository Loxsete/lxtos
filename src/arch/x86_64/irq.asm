global irq1
extern isr_common

irq1:
    push 0
    push 33
    jmp isr_common
