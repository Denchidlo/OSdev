[Makefile example]
***********************************************************
all: bootloader bootdisk

bootloader:
    nasm -f bin bootloader.asm -o bootloader.o

kernel:
    nasm -f bin sample.asm -o bootloader.o

bootdisk: bootloader.o kernel.o
    dd if=/dev/zero of=disk.img bs=512 count=2880
    dd conv=notrunc if=bootloader.o of=disk.img bs=512
        count=1 seek=0
    dd conv=notrunc if=sample.o of=disk.img bs=512 count=1
        seek=1
***********************************************************

Manual:

1)Variables
    <Variable>=<value>

2)Functions
    [wilcard] -> list all matches in a object listing
        EX| BOOTLOADER_SRCS:=$(wildcard %.asm)
    [patsubst] -> substitutes <pattern to erase> into <new pattern> among all variables in listing 
        EX| BOOTLOADER_OBJS:=$(patsubst %.asm, %.o, $(BOOTLOADER_SRCS))


Useful makefiles:


[KERNEL BULDING]
***********************************************************
BOOTLOADER=bootloader.o
OS=sample.o
DISK_IMG=disk.img

BOOTLOADER_SRCS := $(wildcard *.asm)
BOOTLOADER_OBJS := $(patsubst %.asm, %.o, $(BOOTLOADER_SRCS))

all: bootdisk

%.o: %.asm
    nasm -f bin $< -o $@

bootdisk: $(BOOTLOADER_OBJS)
dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
dd conv=notrunc if=$(BOOTLOADER) of=$(DISK_IMG) bs=512
    count=1 seek=0
dd conv=notrunc if=$(OS) of=$(DISK_IMG) bs=512 count=1
    seek=1
***********************************************************