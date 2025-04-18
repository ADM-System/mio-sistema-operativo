BOOTLOADER=bootloader/bootloader.asm
KERNEL_OBJ=kernel/src/kernel.o kernel/src/interrupts.o kernel/src/timer.o kernel/src/keyboard.o
BUILD_DIR=build
OUTPUT=$(BUILD_DIR)/bootloader.bin
KERNEL=$(BUILD_DIR)/kernel.bin

all: $(OUTPUT) $(KERNEL)

$(OUTPUT): $(BOOTLOADER)
	mkdir $(BUILD_DIR) 2> NUL || exit 0
	nasm -f bin $(BOOTLOADER) -o $(OUTPUT)

$(KERNEL): $(KERNEL_OBJ)
	gcc -m32 -o $(KERNEL) $(KERNEL_OBJ)

kernel/src/%.o: kernel/src/%.c
	gcc -m32 -c $< -o $@

run: all
	qemu-system-i386 -fda $(OUTPUT) -hda $(KERNEL)

clean:
	del /Q $(BUILD_DIR)\*
