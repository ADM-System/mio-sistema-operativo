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