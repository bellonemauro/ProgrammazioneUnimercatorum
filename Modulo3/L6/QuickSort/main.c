/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Quick Sort                                                   |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdlib.h>

// Funzione per stampare un array
void stampaArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Funzione di partizionamento per Quick Sort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

// Funzione ricorsiva Quick Sort
void quickSort(int array[], int low, int high) {
    /**
     * Parametri:
     * - low: indice iniziale del sottoarray da ordinare
     * - high: indice finale del sottoarray da ordinare
     *
     * La condizione (low < high) garantisce che il sottoarray contenga almeno due elementi.
     * Se non è soddisfatta, la ricorsione si interrompe perché l'intervallo è già ordinato o vuoto.
     */
    if (low < high) {
        int pi = partition(array, low, high);

        printf("Array dopo partizione:\n");

        printf("  Parte sinistra: ");
        for (int i = low; i < pi; i++) {
            printf("%d ", array[i]);
        }
        
        printf("\n  Pivot: [%d]\n", array[pi]);
        
        printf("  Parte destra:  ");
        for (int i = pi + 1; i <= high; i++) {
            printf("%d ", array[i]);
        }
    
        printf("\n\nPremi invio per continuare...");
        getchar();

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Funzione main con esempio
int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    quickSort(array, 0, n - 1);

    printf("Array ordinato (quick sort): ");
    stampaArray(array, n);

    return 0;
}
