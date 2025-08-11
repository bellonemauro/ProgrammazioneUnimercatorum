/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio albero binario                                        |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdlib.h>

// Struttura del nodo dell'albero binario
typedef struct Nodo {
    int valore;
    struct Nodo* sinistro;
    struct Nodo* destro;
} Nodo;

// Crea un nuovo nodo
Nodo* creaNodo(int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->valore = valore;
    nuovoNodo->sinistro = NULL;
    nuovoNodo->destro = NULL;
    return nuovoNodo;
}

// Inserisce un valore nell'albero (inserimento binario)
Nodo* inserisci(Nodo* radice, int valore) {
    if (radice == NULL) {
        return creaNodo(valore);
    }

    if (valore < radice->valore) {
        radice->sinistro = inserisci(radice->sinistro, valore);
    } else {
        radice->destro = inserisci(radice->destro, valore);
    }

    return radice;
}

// Stampa in ordine (in-order traversal)
void stampaInOrdine(Nodo* radice) {
    if (radice != NULL) {
        stampaInOrdine(radice->sinistro);
        printf("%d ", radice->valore);
        stampaInOrdine(radice->destro);
    }
}

// Libera la memoria dell'albero
void liberaAlbero(Nodo* radice) {
    if (radice != NULL) {
        liberaAlbero(radice->sinistro);
        liberaAlbero(radice->destro);
        free(radice);
    }
}

int main() {
    Nodo* radice = NULL;

    // Inserimento di alcuni valori
    radice = inserisci(radice, 50);
    radice = inserisci(radice, 30);
    radice = inserisci(radice, 70);
    radice = inserisci(radice, 20);
    radice = inserisci(radice, 40);
    radice = inserisci(radice, 60);
    radice = inserisci(radice, 80);

    // Stampa dell'albero in ordine
    printf("Albero in ordine:\n");
    stampaInOrdine(radice);
    printf("\n");

    // Pulizia della memoria
    liberaAlbero(radice);

    return 0;
}
