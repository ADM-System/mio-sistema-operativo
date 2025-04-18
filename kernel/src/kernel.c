#include "interrupts.h"

void test_divide_by_zero() {
    int a = 1;
    int b = 0;
    int result = a / b;
}

void main() {
    idt_init();
    timer_init();
    keyboard_init();

    test_divide_by_zero();  // Questo dovrebbe generare un errore

    char *video_memory = (char*) 0xB8000;
    video_memory[0] = 'A';
    video_memory[1] = 0x07;

    while(1) {
        asm volatile("hlt");
    }
}

