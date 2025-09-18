/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Ricerca binaria                                               |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
 /**
 * @file ricerca_binaria.c
 * @brief Implementazione della ricerca binaria su array ordinati.
 */

#include <stdio.h>

/**
 * @brief Funzione di stampa dall'array.
 *
 * Stampa iterativa con ciclo for su tutti gli elementi.
 *
 * @param array Array ordinato di interi.
 * @param n Numero di elementi nell'array.
 */
void stampaArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * @brief Esegue una ricerca binaria su un array ordinato.
 *
 * La funzione cerca un valore intero all'interno di un array ordinato in modo crescente.
 * Se il valore è presente, restituisce l'indice corrispondente; altrimenti restituisce -1.
 *
 * @param array Array ordinato di interi.
 * @param n Numero di elementi nell'array.
 * @param x Valore da cercare.
 * @return Indice del valore trovato, oppure -1 se non presente.
 */
int ricerca_binaria(int array[], int n, int x) {
    int inizio = 0, fine = n - 1;
    while (inizio <= fine) {
        int medio = (inizio + fine) / 2;
        printf("Valore medio %d \n", array[medio]);
        if (array[medio] == x)  {
            printf("Il valore medio %d è il valore cercato \n", array[medio]);
            printf("Premi invio per continuare...");
            getchar();
            return medio;
        }
        else if (array[medio] < x) {
            inizio = medio + 1;
            printf("Proseguo nella metà superiore da %d a %d \n", array[inizio], array[fine]);
            printf("Premi invio per continuare...");
            getchar();
        }
        else {
            fine = medio - 1;
            printf("Proseguo nella metà inferiore da %d a %d \n", array[inizio], array[fine]);
            printf("Premi invio per continuare...");
            getchar();
        }
    }
    return -1; // elemento non trovato
}

/**
 * @brief Esempio di utilizzo della funzione di ricerca binaria.
 */
int main() {
    int dati[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(dati) / sizeof(dati[0]);
    int valore = 5;

    printf("Array iniziale = " );
    stampaArray(dati, n);
    printf("Cerco il numero  %d. \n", valore);
    printf("Premi invio per continuare...");
    getchar();
        
    int risultato = ricerca_binaria(dati, n, valore);
    if (risultato != -1)
        printf("Valore %d trovato all'indice %d. \n", valore, risultato);
    else
        printf("Valore %d non trovato. \n", valore);

    return 0;
}
