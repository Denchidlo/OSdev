BUILD_DIR=../build
OBJS_DIR=$(BUILD_DIR)/obj
BIN=$(BUILD_DIR)/bin/SampleOS.bin
LD_SCRIPT=kernel.lds

ASM_SRCS:=$(wildcard %.asm)
ASM_OBJS:=$(patsubst %.asm, $(OBJS_DIR)/%.o, $(ASM_SRCS))

all: kernel

$(ASM_OBJS): $(ASM_SRCS)
	nasm -felf32 $< -o $@

kernel: $(ASM_OBJS)
	i686-elf-gcc -T $(LD_SCRIPT) -o $(BIN) -ffreestanding -O2 -nostdlib $(ASM_OBJS) -lgcc

clean:
	rm $(OBJS_DIR)/*

remove_kernel:
	rm $(BIN_DIR)/*