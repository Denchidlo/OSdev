[ORG 0x7c00]
   xor ax, ax  ;make it zero
   mov ds, ax
   cld
 
   mov si, msg
   call bios_print
 
hang:
   jmp hang
 
msg   db 'Hello World', 13, 10, 0
 
%include "proc.inc"
 
   times 510-($-$$) db 0
   db 0x55
   db 0xAA