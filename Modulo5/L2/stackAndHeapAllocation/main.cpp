#include <stdio.h>
#include <stdlib.h>

int* allocaArrayHeap(const int size) {
    
    int* array = (int*) malloc(size * sizeof(int));
    // Inizializzazione dell'array con valori di esempio
    for (int i = 0; i < size; ++i) {
        array[i] = i * 2;
    }
    return array;
}

void allocaArrayStack(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i * 20;
    }
}

void stampaArray(const int* array, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int main() {
    
    int N;
    printf("Inserisci la dimensione dell'array: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Input non valido.\n");
        return 1;
    }
    
    printf("\nAlloco l'array nell'heap.\n");
    int* array = allocaArrayHeap(N);
    if (array == NULL) {
        printf("Errore di allocazione\n");
        return 0;
    }
    printf("\nArray correttamente allocato nell'heap.\n");
    
    printf("\nAlloco l'array nello stack.\n");
    int arrayStack[N]; 
    allocaArrayStack(arrayStack, N);
    printf("\nArray correttamente allocato nello stack.\n");
    
    printf("\nStampa array nell'heap.\n");
    stampaArray(array, N);
    free(array); // Deallocazione
    
    printf("\nStampa array nello stack.\n");
    stampaArray(arrayStack, N);
    
}