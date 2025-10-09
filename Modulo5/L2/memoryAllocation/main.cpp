#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array = (int*)malloc(10 * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione\n");
        return 0;
    }

    int* array_calloc = (int*)calloc(10, sizeof(int));
    if (array_calloc == NULL) {
        printf("Errore di allocazione\n");
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        printf("Indirizzo %p inizializzato a %d \n", &array[i], array[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("Indirizzo %p inizializzato a %d \n", &array_calloc[i], array_calloc[i]);
    }

    free(array); // Deallocazione
    free(array_calloc); // Deallocazione
}