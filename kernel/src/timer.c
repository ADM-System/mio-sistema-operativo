#include "interrupts.h"

// Contatore per il timer
static uint32_t tick_count = 0;

// Gestore dell'interruttore timer
void timer_handler(struct registers* regs) {
    tick_count++;
    // Qui potremmo aggiungere la gestione del scheduling
    asm volatile("iret");
}

// Funzione per inizializzare il timer
void timer_init(void) {
    // Setta il timer a 100 ticks al secondo (10ms)
    outb(0x43, 0x36);
    uint8_t l = (uint8_t)(1193182 / 100);
    uint8_t h = (uint8_t)((1193182 / 100) >> 8);
    outb(0x40, l);
    outb(0x40, h);
}