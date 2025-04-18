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

    // Gestori di errori
    set_idt_entry(ERROR_DIVIDE_BY_ZERO, (uint32_t)divide_by_zero_handler);
    set_idt_entry(ERROR_PAGE_FAULT, (uint32_t)page_fault_handler);
    
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

// Funzione per scrivere a video
void write_to_video(const char* message) {
    char* video_memory = (char*) 0xB8000;
    int pos = 0;
    
    while (*message) {
        video_memory[pos++] = *message++;
        video_memory[pos++] = 0x0C;  // Rosso su nero
    }
}

// Funzione per gestire gli errori
void error_handler(uint32_t error_code, const char* message) {
    write_to_video("ERROR: ");
    write_to_video(message);
    write_to_video("\n");
    
    while(1) {
        asm volatile("hlt");
    }
}

// Funzione per stampare il codice dell'errore
void print_error(uint32_t error_code, const char* message) {
    switch(error_code) {
        case ERROR_DIVIDE_BY_ZERO:
            error_handler(error_code, "Division by zero!");
            break;
        case ERROR_PAGE_FAULT:
            error_handler(error_code, "Page fault!");
            break;
        default:
            error_handler(error_code, "Unknown error!");
            break;
    }
}

// Gestore divisione per zero
void divide_by_zero_handler(struct registers* regs) {
    print_error(ERROR_DIVIDE_BY_ZERO, "Division by zero occurred!");
    asm volatile("iret");
}

// Gestore page fault
void page_fault_handler(struct registers* regs) {
    print_error(ERROR_PAGE_FAULT, "Page fault occurred!");
    asm volatile("iret");
}