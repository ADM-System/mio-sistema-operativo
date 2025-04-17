# Mio Sistema Operativo

Obiettivo: creare un piccolo sistema operativo in C e Assembly, per architettura x86.

# Mio Sistema Operativo

Questo è un progetto in cui sto costruendo un sistema operativo da zero. L'obiettivo principale è imparare come funziona un sistema operativo a basso livello, partendo da un bootloader e poi sviluppando il kernel. 

Finora, ho completato i seguenti passi:

## Obiettivi Raggiunti

1. **Creazione del Bootloader**: 
   - Ho scritto il codice del bootloader in Assembly (`bootloader.asm`), che è il primo codice eseguito durante l'avvio del computer. Questo bootloader inizializza la CPU e carica il kernel in memoria.
   
2. **Creazione del Makefile**: 
   - Ho configurato un Makefile per automatizzare il processo di compilazione. Il Makefile permette di:
     - Compilare il bootloader in un file binario.
     - Eseguire il bootloader utilizzando **QEMU** per la virtualizzazione.
     - Pulire la cartella di build eliminando i file generati.

3. **Utilizzo di Git per Versionamento**:
   - Ho utilizzato Git per gestire il controllo versione del codice e GitHub per ospitare il repository, eseguendo commit e push regolari per tenere traccia dei progressi.

## Tecnologie e Strumenti Utilizzati

1. **NASM**: Ho utilizzato **NASM** per assemblare il codice Assembly.
2. **QEMU**: Ho usato **QEMU** per emulare il bootloader e testare il codice senza bisogno di hardware fisico.
3. **Makefile**: Ho creato un Makefile per automatizzare la compilazione e la gestione del progetto.
4. **Git & GitHub**: Ho usato **Git** per versionare il codice e **GitHub** per ospitare il repository.

## Prossimi Passi

1. **Sviluppo del Kernel**: Il prossimo passo è sviluppare un kernel minimo che possa interagire con l'hardware.
2. **Supporto per più Dispositivi**: Aggiungere il supporto per dispositivi di input/output come tastiera e schermo.
3. **Interfaccia Utente**: Creare una semplice interfaccia utente in modalità testo per interagire con il sistema operativo.

## Note e Riflessioni

- Ho imparato molto sulla gestione della memoria a basso livello e sul funzionamento di un bootloader.
- L'uso di QEMU è stato essenziale per testare il codice senza l'uso di hardware fisico.
- Un miglioramento futuro potrebbe essere l'ottimizzazione del codice di compilazione o l'aggiunta di funzionalità al bootloader per caricare moduli dinamici.

