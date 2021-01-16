SRC_DIR=src
O_BIN=build/bootloader/boot.bin

.PHONY: build

all:	build

build:
	make -C $(SRC_DIR)

upload:
	qemu-system-i386 -hda $(O_BIN)

clean:
	make -C $(SRC_DIR) clean