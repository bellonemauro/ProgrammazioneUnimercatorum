/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio grafo                                                 |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <string.h>

#define NUM_NODI 4

typedef struct {
    char nome[10];
} Nodo;

typedef struct {
    Nodo nodi[NUM_NODI];
    int matrice[NUM_NODI][NUM_NODI];
} Grafo;

// Inizializza il grafo con nomi e matrice vuota
void inizializzaGrafo(Grafo* g) {
    strcpy(g->nodi[0].nome, "A");
    strcpy(g->nodi[1].nome, "B");
    strcpy(g->nodi[2].nome, "C");
    strcpy(g->nodi[3].nome, "D");

    for (int i = 0; i < NUM_NODI; i++) {
        for (int j = 0; j < NUM_NODI; j++) {
            g->matrice[i][j] = 0;
        }
    }
}

// Aggiunge un arco non orientato tra due nodi
void aggiungiArco(Grafo* g, int da, int a) {
    g->matrice[da][a] = 1;
    g->matrice[a][da] = 1;
}

// Stampa la matrice di adiacenza
void stampaMatriceAdiacenza(Grafo* g) {
    printf("Matrice di adiacenza:\n");
    for (int i = 0; i < NUM_NODI; i++) {
        for (int j = 0; j < NUM_NODI; j++) {
            printf("%d ", g->matrice[i][j]);
        }
        printf("\n");
    }
}

// Stampa le connessioni tra i nodi
void stampaConnessioni(Grafo* g) {
    printf("\nConnessioni:\n");
    for (int i = 0; i < NUM_NODI; i++) {
        printf("%s è connesso con: ", g->nodi[i].nome);
        for (int j = 0; j < NUM_NODI; j++) {
            if (g->matrice[i][j]) {
                printf("%s ", g->nodi[j].nome);
            }
        }
        printf("\n");
    }
}

int main() {
    Grafo g;
    inizializzaGrafo(&g);

    // Aggiunta delle connessioni
    aggiungiArco(&g, 0, 1); // A - B
    aggiungiArco(&g, 0, 2); // A - C
    aggiungiArco(&g, 1, 3); // B - D

    // Visualizzazione
    stampaMatriceAdiacenza(&g);
    stampaConnessioni(&g);

    return 0;
}
