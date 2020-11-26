BUILD_DIR=../build/os
OS=$(BUILD_DIR)/os

CFLAGS+=-ffreestanding -nostdlib -gdwarf-4 -m32 -ggdb3

OS_SRCS:=$(wildcard *.c)
OS_OBJS:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(OS_SRCS))

all: $(OS)

$(OS_OBJS): $(OS_SRCS)
	gcc $(CFLAGS) -m32 -c $< -o $@

$(OS) : $(OS_OBJS)
	ld -m elf_i386 -T os.lds  $(OS_OBJS) -o $@

clean:
	rm $(OS_OBJS)