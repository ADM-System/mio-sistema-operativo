BOOTLOADER=bootloader/bootloader.asm
BUILD_DIR=build
OUTPUT=$(BUILD_DIR)/bootloader.bin

all: $(OUTPUT)

$(OUTPUT): $(BOOTLOADER)
	mkdir $(BUILD_DIR) 2> NUL || exit 0
	nasm -f bin $(BOOTLOADER) -o $(OUTPUT)

run: all
	qemu-system-i386 -fda $(OUTPUT)

clean:
	del /Q $(BUILD_DIR)\*
