/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Bubble Sort                                                   |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Funzione per stampare un array
void stampaArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* allocaCopia(int array[], int n)
{
    int* copiaArray = malloc(n * sizeof(int));
    if (copiaArray == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }

    // Copia dell'array originale
    for (int i = 0; i < n; i++) {
        copiaArray[i] = array[i];
    }
    return copiaArray;
}

// Funzione che crea una copia ordinata dell'array usando Bubble Sort
int* bubbleSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);

    // Ordinamento Bubble Sort
    bool scambiato;
    int temp;
    do {
        scambiato = false;
        for (int i = 0; i < n - 1; i++) {
            if (sorted[i] > sorted[i + 1]) {
                printf("Scambio %d con %d\n", sorted[i], sorted[i + 1]);
                temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
                scambiato = true;
            }
        }
        printf("Array attuale: ");
        stampaArray(sorted, n);
        printf("Premi invio per continuare...");
        getchar();
    } while (scambiato);

    return sorted;
}


// Funzione main con esempio
int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    int* ordinato = bubbleSort(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato:  ");
        stampaArray(ordinato, n);
        free(ordinato);
    }

    return 0;
}