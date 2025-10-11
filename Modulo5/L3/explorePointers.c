/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio uso e esplorazione dei puntatori                      |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdlib.h>

int* inizializzaArray(int* array, const int size) {
    
    if (array == NULL) {
        printf("Errore di allocazione, non posso inizializzare l'array.\n");
        return NULL;
    }
    
    // Inizializzazione dell'array con valori di esempio
    for (int i = 0; i < size; ++i) {
        array[i] = i * 2;
    }
    return array;
}

void stampaArray(const int* array, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("L'indirizzo %p contiene il valore a %d \n", &array[i], array[i]);
    }
}

int main() {
    
    int N;
    printf("Inserisci la dimensione dell'array: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Input non valido.\n");
        return 1;
    }
    getchar();
    
    int* array = malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione\n");
        return 0;
    }
    printf("Array correttamente allocato all'indirizzo %p.\n", array);
    printf("Il puntatore all'array è contenuto all'indirizzo %p.\n", &array);
    printf("Premi invio per continuare...");
    getchar();
    
    if (inizializzaArray(array, N) ==0)    {
        printf("Errore di iniializzazione\n");
        return 0;
    }
    
    printf("\nArray correttamente inizializzato.\n");
    stampaArray(array, N);
    free(array); // Deallocazione
}

