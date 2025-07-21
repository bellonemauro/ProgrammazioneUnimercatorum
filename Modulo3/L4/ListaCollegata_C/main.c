#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo con typedef
typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

// Funzione per creare un nuovo nodo
Nodo* creaNodo(int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    nuovo->dato = valore;
    nuovo->prossimo = NULL;
    return nuovo;
}

// Inserimento in testa
void inserisciInTesta(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);
    nuovo->prossimo = *testa;
    *testa = nuovo;
}

// Inserimento in coda
void inserisciInCoda(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);
    if (*testa == NULL) {
        *testa = nuovo;
        return;
    }
    Nodo* temp = *testa;
    while (temp->prossimo != NULL) {
        temp = temp->prossimo;
    }
    temp->prossimo = nuovo;
}

// Ricerca di un valore
Nodo* cerca(Nodo* testa, int valore) {
    while (testa != NULL) {
        if (testa->dato == valore)
            return testa;
        testa = testa->prossimo;
    }
    return NULL;
}

// Eliminazione di un nodo
void elimina(Nodo** testa, int valore) {
    Nodo* temp = *testa;
    Nodo* precedente = NULL;

    while (temp != NULL && temp->dato != valore) {
        precedente = temp;
        temp = temp->prossimo;
    }

    if (temp == NULL) {
        printf("Valore %d non trovato.\n", valore);
        return;
    }

    if (precedente == NULL) {
        *testa = temp->prossimo;
    } else {
        precedente->prossimo = temp->prossimo;
    }

    free(temp);
    printf("Valore %d eliminato.\n", valore);
}

// Stampa della lista
void stampaLista(Nodo* testa) {
    printf("Lista: ");
    while (testa != NULL) {
        printf("%d -> ", testa->dato);
        testa = testa->prossimo;
    }
    printf("NULL\n");
}

// Deallocazione della lista
void liberaLista(Nodo* testa) {
    Nodo* temp;
    while (testa != NULL) {
        temp = testa;
        testa = testa->prossimo;
        free(temp);
    }
}

// Funzione main con esempi
int main() {
    Nodo* lista = NULL;

    // Inserimenti
    inserisciInTesta(&lista, 10);
    inserisciInTesta(&lista, 20);
    inserisciInCoda(&lista, 5);
    inserisciInCoda(&lista, 1);

    stampaLista(lista);

    // Ricerca
    int valore = 5;
    Nodo* trovato = cerca(lista, valore);
    if (trovato != NULL)
        printf("Valore %d trovato nella lista.\n", valore);
    else
        printf("Valore %d non presente.\n", valore);

    // Eliminazione
    elimina(&lista, 20);
    stampaLista(lista);

    elimina(&lista, 100); // valore non presente

    // Pulizia finale
    liberaLista(lista);
    return 0;
}