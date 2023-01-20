.section .text

.global _start
_start:
    movq $0x100, %rax
    syscall
    cmpq $0, %rax
    jle 1f
    mov %rax, %rsp
    mov %rsp, %rdi
    mov $main, %rsi
    call __mlibc_entry

1:
    movq $-1, %rdi
    movq $0x002, %rax
    syscall
    ud2
