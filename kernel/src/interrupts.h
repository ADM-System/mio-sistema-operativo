#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#define ERROR_DIVIDE_BY_ZERO 0
#define ERROR_PAGE_FAULT 14

// Definizione della struttura per l'IDT
struct idt_entry {
    uint16_t base_lo;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_hi;
} __attribute__((packed));

// Definizione della struttura per la GDT
struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Funzioni principali
void idt_init(void);
void set_idt_entry(int n, uint32_t handler);
void register_interrupt_handler(int n, void (*handler)(struct registers*));

// Funzioni per la gestione degli errori
void error_handler(uint32_t error_code, const char* message);
void print_error(uint32_t error_code, const char* message);

// Struttura per i registri salvati durante l'interrotto
struct registers {
    uint32_t ds;
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t int_no;
    uint32_t err_code;
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss;
};

#endif