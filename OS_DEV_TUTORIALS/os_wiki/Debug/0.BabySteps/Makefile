SRC_DIR=src
O_BIN=build/bootloader/boot.bin
DISK_IMG=disk.img

.PHONY: build

all:	build

build:
	make -C $(SRC_DIR)
	dd	if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd 	if=$(O_BIN) of=$(DISK_IMG) bs=512 count=1 seek=0

run:
	qemu-system-i386 -hda $(DISK_IMG)

debug:
	qemu-system-i386 -fda $(DISK_IMG) 

clean:
	make -C $(SRC_DIR) clean
	rm disk.img