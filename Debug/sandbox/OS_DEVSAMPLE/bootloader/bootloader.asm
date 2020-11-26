;******************************************
;
;              bootloader.asm
;       
;          Developed by denchidlo
;
;******************************************

bits 16
start: 
    jmp boot

msg db 'Bootloader is being loaded!'

boot:
    cli
    cld

    mov ax, 50h

    mov es, ax
    xor bx, bx

    mov al, 2   ;read 2 sectors
    mov ch, 0   ;it is on track 0
    mov cl, 2   ;sector to read (The second sector)
    mov dh, 0   ;head number
    mov dl, 0   ;drive number

    mov ah, 02  ;special bios routine
    int 13h

    jmp [500h + 18h]

    hlt         ;stop computer

    times 510 - ($-$$) db 0

    ;boot_label
    dw 0xaa55
