#include "interrupts.h"

// Buffer per i tasti
#define KEYBOARD_BUFFER_SIZE 128
static char keyboard_buffer[KEYBOARD_BUFFER_SIZE];
static uint32_t buffer_pos = 0;

// Gestore della tastiera
void keyboard_handler(struct registers* regs) {
    uint8_t scancode = inb(0x60);
    // Gestione del buffer della tastiera
    if (buffer_pos < KEYBOARD_BUFFER_SIZE) {
        keyboard_buffer[buffer_pos++] = scancode;
    }
    asm volatile("iret");
}

// Funzione per inizializzare la tastiera
void keyboard_init(void) {
    // Abilita il controller della tastiera
    outb(0x21, inb(0x21) & ~0x02);
}