# Progetto Didattico C++ – Giocatore

Questo progetto è pensato per introdurre i concetti fondamentali di **classi** e **librerie** in C++ attraverso un esempio pratico. 
L'applicazione simula un giocatore che si muove in uno spazio bidimensionale, controllato da input da tastiera.

## 📁 Struttura del progetto

. ├── CMakeLists.txt ├── apps/ │ └── main/ │ └── main.cpp └── libs/ └── Giocatore/ ├── include/ │ └── Giocatore.h └── src/ └── Giocatore.cpp

- `apps/buttonTest/main.cpp`: contiene il punto di ingresso dell'applicazione.
- `libs/Giocatore/include/Giocatore.h`: definizione della classe `Giocatore`.
- `libs/Giocatore/src/Giocatore.cpp`: implementazione della classe `Giocatore`.

##  Compilazione

Assicurati di avere installato CMake (versione ≥ 3.10) e un compilatore C++ compatibile con C++17.


### Passaggi:

```bash
mkdir build
cd build
cmake ..
make 
```

L'eseguibile verrà generato nella cartella build/ con il nome main.

### Utilizzo
Una volta compilato, puoi eseguire il programma con:

```bash
main.exe
```

Il programma ti permette di controllare il giocatore con i tasti:

- W: su
- A: sinistra
- S: giù
- D: destra
- Q: esci

La posizione del giocatore viene aggiornata e mostrata ad ogni input.

### Obiettivi Didattici
Comprendere la separazione tra interfaccia (.h) e implementazione (.cpp)
Usare CMake per organizzare e compilare un progetto multi-file
Introdurre il concetto di modularità e riutilizzo del codice
