.intel_syntax noprefix

.global _exit
_exit:
  mov rax, 60
  syscall
