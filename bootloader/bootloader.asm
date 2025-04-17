[BITS 16]         ; Modalità reale, 16-bit
[ORG 0x7C00]      ; Dove il BIOS carica il bootloader in memoria

start:
    ; Stampa carattere per carattere il messaggio
    mov si, message      ; Puntatore alla stringa
.print_loop:
    lodsb                ; Carica il prossimo byte da [SI] in AL, SI++
    cmp al, 0            ; Fine stringa?
    je done
    mov ah, 0x0E         ; Funzione BIOS: teletype output
    int 0x10             ; Stampa carattere in AL
    jmp .print_loop

done:
    cli                  ; Disabilita interruzioni
    hlt                  ; Ferma la CPU

message db "Hello from bootloader!", 0

; Padding fino a 510 byte
times 510 - ($ - $$) db 0
; Firma di boot (necessaria!)
dw 0xAA55
