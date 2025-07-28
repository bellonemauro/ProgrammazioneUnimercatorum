/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Selection Sort                                                |
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


// Funzione di ordinamento tramite Selection Sort
int* selectionSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);

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

    int* ordinato = selectionSort(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato (insertion sort): ");
        stampaArray(ordinato, n);
        free(ordinato);
    }

    return 0;
}