#include "interrupts.h"

void main() {
    // Inizializza il sistema di interruzioni
    idt_init();
    timer_init();
    keyboard_init();

    // Video memory in modalità testo (0xb8000 è l'indirizzo per il video memory)
    char *video_memory = (char*) 0xB8000;
    
    // Scriviamo il carattere 'A' e impostiamo il colore del testo (bianco su nero)
    video_memory[0] = 'A';
    video_memory[1] = 0x07;  // 0x07 è il colore bianco su sfondo nero

    // Il prossimo carattere va alla posizione successiva
    // video_memory[2] = 'B'; 
    // video_memory[3] = 0x07; // E così via...

    // Loop infinito per mantenere il kernel in esecuzione
    while(1) {
        asm volatile("hlt");  // Ferma la CPU fino all'interrotto successivo
    }
}
