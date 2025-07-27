/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Insertion Sort                                                |
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

// Funzione che crea una copia ordinata dell'array usando Insertion Sort
int* insertionSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);

    // Ordinamento Insertion Sort
    for (int i = 1; i < n; i++) {
        int chiave = sorted[i];
        int j = i - 1;

        printf("Confronto %d con la chiave %d\n", sorted[j], chiave);   
        // Sposta gli elementi maggiori di chiave a destra
        while (j >= 0 && sorted[j] > chiave) {
            printf("   Elementi spostati a destra per accomodare il nuovo elemento %d con la chiave %d\n", sorted[j], sorted[j + 1]);   
            sorted[j + 1] = sorted[j];
            j--;
        }
             
        sorted[j + 1] = chiave;

        printf("Array attuale: ");
        stampaArray(sorted, n);
        printf("Premi invio per continuare...");
        getchar();
    }

    return sorted;
}

// Funzione main con esempio
int main() {
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    int* ordinato = insertionSort(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato (insertion sort): ");
        stampaArray(ordinato, n);
        free(ordinato);
    }

    return 0;
}
