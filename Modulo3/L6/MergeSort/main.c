/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Quick Sort                                                    |
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

// Funzione per unire due sottoarray ordinati
void merge(int array[], int sinistra, int centro, int destra) {
    int n1 = centro - sinistra + 1;
    int n2 = destra - centro;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[sinistra + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[centro + 1 + j];

    int i = 0, j = 0, k = sinistra;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    printf("Array dopo merge:\n");

    printf("  Parte sinistra: ");
    for (int i = sinistra; i <= centro; i++) {
        printf("%d ", array[i]);
    }

    printf("\n  Parte destra:  ");
    for (int i = centro + 1; i <= destra; i++) {
        printf("%d ", array[i]);
    }

    printf("\n  Unito:         ");
    for (int i = sinistra; i <= destra; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nPremi invio per continuare...");
    getchar();
}

// Funzione ricorsiva Merge Sort
void mergeSort(int array[], int sinistra, int destra) {
    /**
     * Parametri:
     * - sinistra: indice iniziale del sottoarray
     * - destra: indice finale del sottoarray
     *
     * Divide l'array in due metà, le ordina ricorsivamente e poi le unisce.
     */
    if (sinistra < destra) {
        int centro = sinistra + (destra - sinistra) / 2;

        mergeSort(array, sinistra, centro);
        mergeSort(array, centro + 1, destra);
        merge(array, sinistra, centro, destra);
    }
}

// Funzione main con esempio
int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    mergeSort(array, 0, n - 1);

    printf("Array ordinato (merge sort): ");
    stampaArray(array, n);

    return 0;
}
