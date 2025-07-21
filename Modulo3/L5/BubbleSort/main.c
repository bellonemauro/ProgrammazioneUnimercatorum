#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Funzione che crea una copia ordinata dell'array usando Bubble Sort
int* bubbleSortCopy(int array[], int n) {
    int* sorted = malloc(n * sizeof(int));
    if (sorted == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }

    // Copia dell'array originale
    for (int i = 0; i < n; i++) {
        sorted[i] = array[i];
    }

    // Ordinamento Bubble Sort
    bool scambiato;
    int temp;
    do {
        scambiato = false;
        for (int i = 0; i < n - 1; i++) {
            if (sorted[i] > sorted[i + 1]) {
                temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
                scambiato = true;
            }
        }
    } while (scambiato);

    return sorted;
}

// Funzione per stampare un array
void stampaArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Funzione main con esempio
int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    int* ordinato = bubbleSortCopy(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato:  ");
        stampaArray(ordinato, n);
        free(ordinato);
    }

    return 0;
}