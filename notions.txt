<Compilation>
    $ gcc _name.c_ -o _output_

<Dump of data with disasembly>
    $ objdump -z -M intel -S -D <objectFile>

<objdump options:>
    --no-show-raw-insn -> removes opcodes
    -d -> only executable sections
    -D -> content of all sections
    -M intel -> shows in intel syntax
    -M i386 -> displays content in 32bit layout

<Raw data Dump>
    $ readelf -x <.segment> <objectFile>

<Elf sprcification>
    $ man elf

<readelf flags>
    General:
        $ readelf ...
    Flags:
        -h -> returns elf header
        