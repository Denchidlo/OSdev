ENTRY(main);

PHDRS
{
    code PT_LOAD;
    headers PT_PHDR FILEHDR PHDRS;
}

SECTIONS
{
    .text 0x500: { *(.text) } :code
    .data : { *(.data) }
    .bss : { *(.bss) }
    /DISCARD/ : { *(.eh_frame) }
}