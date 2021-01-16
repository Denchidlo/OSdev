;   boot1.asm
cli

hang_loop:
    jmp hang_loop

times 510-($-$$) db 0

db 0x55
db 0xAA