#include <stdio.h>
#include <stdlib.h>

int* selectionSortCopy(int array[], int n) {
    int* sorted = malloc(n * sizeof(int));
    if (sorted == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }

    // Copia dell'array originale
    for (int i = 0; i < n; i++) {
        sorted[i] = array[i];
    }

    // Algoritmo Selection Sort
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (sorted[j] < sorted[minIndex]) {
                minIndex = j;
            }
        }
        // Scambia il minimo con l'elemento in posizione i
        temp = sorted[i];
        sorted[i] = sorted[minIndex];
        sorted[minIndex] = temp;
        printf("Scambio %d con %d\n", sorted[i], sorted[minIndex]);
        printf("Array attuale: ");
        for (int i = 0; i < n; i++) printf("%d ", sorted[i]);
        printf("\n");
        printf("Premi invio per continuare...");
        getchar();
    }

    return sorted;
}

int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    int* ordinato = selectionSortCopy(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato:  ");
        for (int i = 0; i < n; i++) printf("%d ", ordinato[i]);
        printf("\n");
        free(ordinato);
    }

    return 0;
}