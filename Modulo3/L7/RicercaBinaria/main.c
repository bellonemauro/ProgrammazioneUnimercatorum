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
        if (array[medio] == x)
            return medio;
        else if (array[medio] < x)
            inizio = medio + 1;
        else
            fine = medio - 1;
    }
    return -1; // elemento non trovato
}

/**
 * @brief Esempio di utilizzo della funzione di ricerca binaria.
 */
int main() {
    int dati[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(dati) / sizeof(dati[0]);
    int valore = 7;

    int risultato = ricerca_binaria(dati, n, valore);
    if (risultato != -1)
        printf("Valore %d trovato all'indice %d.\\n", valore, risultato);
    else
        printf("Valore %d non trovato.\\n", valore);

    return 0;
}
