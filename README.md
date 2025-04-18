# Mio Sistema Operativo

Un progetto di sistema operativo minimalista sviluppato in C e Assembly per architettura x86.

## Stato Attuale
- Bootloader funzionante che stampa un messaggio
- Kernel base che scrive caratteri a video
- Sistema di build automatizzato con Makefile
- Gestione versione con Git e GitHub

## Tecnologie
- NASM per Assembly
- QEMU per virtualizzazione
- Make per automazione build
- Git per versionamento

## Struttura

mio-sistema-operativo/
├── bootloader/
│   ├── bootloader.asm
│   └── bootloader.bin
├── kernel/
│   └── src/
│       └── kernel.c
├── build/
│   └── bootloader.bin
└── Makefile

## Prossimi Passi
1. Sistema di interruzioni
2. Gestione memoria avanzata
3. Supporto tastiera
4. Shell di base

## Sistema di Interruzioni

### Descrizione
Il sistema di interruzioni è stato implementato per gestire eventi asincroni nel sistema operativo. Include la gestione del timer e della tastiera.

### Componenti Principali

1. **IDT (Interrupt Descriptor Table)**
   - Tabella di 256 entries per gestire tutti i possibili interrutti
   - Ogni entry contiene:
     - Base address della routine di gestione
     - Selector del segmento
     - Flags per i privilegi e il tipo di interruzione

2. **Gestori di Base**
   - Timer Interrupt (0x20): Gestisce il clock del sistema
   - Keyboard Interrupt (0x21): Gestisce l'input dalla tastiera

3. **Funzionalità Implementate**
   - Gestione del timer a 10ms
   - Buffer per la tastiera
   - Sistema di gestione degli errori
   - Supporto per il multitasking (base)

### Utilizzo
Per utilizzare il sistema di interruzioni:

1. Inizializzare l'IDT: `idt_init()`
2. Inizializzare il timer: `timer_init()`
3. Inizializzare la tastiera: `keyboard_init()`

### Funzioni Principali

```c
// Inizializzazione
void idt_init(void);
void timer_init(void);
void keyboard_init(void);

// Gestione degli interrupt
void set_idt_entry(int n, uint32_t handler);
void register_interrupt_handler(int n, void (*handler)(struct registers*));

### Gestione degli Errori

Il sistema implementa la gestione di errori hardware fondamentali:

1. **Divisione per Zero (0)**
   - Gestisce tentativi di divisione per zero
   - Mostra messaggio di errore in rosso
   - Ferma il sistema in modo sicuro

2. **Page Fault (14)**
   - Gestisce errori di accesso alla memoria
   - Mostra messaggio di errore dettagliato
   - Include informazioni sul tipo di errore

3. **Sistema di Logging**
   - Visualizza messaggi di errore a video
   - Usa colore rosso per evidenziare gli errori
   - Include il tipo di errore e il messaggio

4. **Funzioni Principali**

```c
// Gestione degli errori
void error_handler(uint32_t error_code, const char* message);
void print_error(uint32_t error_code, const char* message);

// Gestori specifici
void divide_by_zero_handler(struct registers* regs);
void page_fault_handler(struct registers* regs);