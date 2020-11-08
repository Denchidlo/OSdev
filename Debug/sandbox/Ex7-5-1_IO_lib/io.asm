; **************************************
;           Basic io library
; **************************************

bits 16
start:
    jmp boot

msg db 'Welcome to Operating System!', 0ah, 0dh, 00h

boot:
    mov ax, 0x07c0
    mov ds, ax
    mov es, ax 
    mov bx, 1010h
    call MovCursor
    mov bx, 0404h
    call MovCursor
    mov al, '$'
    mov cx, 2
    mov bl, 0xf0
    call PutChar 
    mov bx, 0101h
    call MovCursor
    mov si, msg
    call Print

; Clear the rest of the sector with 0

; Move cursor to (bl, bh)
MovCursor:
    xchg bx, dx
    mov ah, 02h
    mov bh, 0
    int 10h
ret


; al->char | bl->color | cx->repeates
PutChar:
    mov bh, 0
    mov ah, 0ah
    int 10h
ret


Print:
    ; read current cursor position
    mov ah, 03h
    int 10h
    ; Set string buffer
    mov di, si
    ; strlen
    cld
    xor cx, cx
    strlen_loop:
        cmp byte [di], 0x00
        je end_loop
        inc di
        inc cx
        jmp strlen_loop
    end_loop:
    ; Start print
    mov bh, 0
    mov ax, 1301h
    mov bp, si
    int 10h
ret



times 510 - ($-$$) db 0

dw 0xAA55 ; Boot signature