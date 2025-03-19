section .multiboot
align 4
dd 0x1BADB002  ; magic number
dd 0           ; flags
dd -(0x1BADB002 + 0) ; checksum
