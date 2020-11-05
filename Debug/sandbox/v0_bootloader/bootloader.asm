; ****************************************
; First implementation of bootloader
; ****************************************

bits 16
start:
    jmp boot

msg db 'Welcome to my Operating System!', 0ah, 0dh, 00h

boot:
    cli ; clear interrupt flag
    cld ; all we need to init
    hlt ; halt the system

; Clear the rest of the sector with 0

times 510 - ($-$$) db 0

dw 0xAA55 ; Boot signature