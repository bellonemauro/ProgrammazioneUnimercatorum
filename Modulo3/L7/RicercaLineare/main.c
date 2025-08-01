/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Ricerca lineare                                               |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
 /**
 * @file ricerca_lineare.c
 * @brief Esempio di implementazione di ricerca lineare in C.
 *
 * Questo file contiene una semplice funzione per cercare un elemento
 * all'interno di un array di interi. È utilizzato come esempio per introdurre
 * il concetto di documentazione del codice usando lo stile Doxygen.
 */

#include <stdio.h>

/**
 * @brief Cerca un elemento in un array usando la ricerca lineare.
 *
 * Scorre l'array elemento per elemento confrontando ciascun valore con quello cercato.
 *
 * @param arr Array di interi in cui effettuare la ricerca.
 * @param size Dimensione dell'array.
 * @param target Valore da cercare.
 * @return Indice dell'elemento se trovato, -1 altrimenti.
 */
int ricerca_lineare(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        printf("Confronto elemento %d con il target %d \n",arr[i], target);
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int dati[] = {3, 7, 1, 9, 5};
    int n = sizeof(dati) / sizeof(dati[0]);
    int valore = 9;

    int risultato = ricerca_lineare(dati, n, valore);

    if (risultato != -1) {
        printf("Elemento trovato all'indice %d\\n", risultato);
    } else {
        printf("Elemento non trovato\\n");
    }

    return 0;
}
