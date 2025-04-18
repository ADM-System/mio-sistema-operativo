#include "interrupts.h"

// IDT e puntatore IDT
struct idt_entry idt[256];
struct idt_ptr idtp;

// Funzione per inizializzare l'IDT
void idt_init(void) {
    memset(&idt, 0, sizeof(idt));
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;
    
    // Imposta i gestori di base
    set_idt_entry(0x20, (uint32_t)timer_handler);
    set_idt_entry(0x21, (uint32_t)keyboard_handler);
    
    // Abilita le interruzioni
    asm volatile("sti");
}

// Funzione per impostare un'entry nell'IDT
void set_idt_entry(int n, uint32_t handler) {
    idt[n].base_lo = handler & 0xFFFF;
    idt[n].base_hi = (handler >> 16) & 0xFFFF;
    idt[n].sel = 0x08; // Kernel code segment
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; // Present, Ring 0, 32-bit
}

// Funzione per registrare un gestore di interrutti
void register_interrupt_handler(int n, void (*handler)(struct registers*)) {
    // Implementazione del gestore generico
}