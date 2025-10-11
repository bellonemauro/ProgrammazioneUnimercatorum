/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio creazione di un puntatore                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>


int main() {

	int valore = 7;
	int* prt_valore = &valore;

	printf("Il mio puntatore %p\n", prt_valore);
	printf("Il mio valore %d\n", valore);

	// deferenziazione 
	*prt_valore = 9;
	printf("Il mio valore %d\n", valore);
}



















//int main() {
//    int* array = (int*)malloc(10 * sizeof(int));
//    if (array == NULL) {
//        printf("Errore di allocazione\n");
//        return 0;
//    }
//
//    int* array_calloc = (int*)calloc(10, sizeof(int));
//    if (array_calloc == NULL) {
//        printf("Errore di allocazione\n");
//        return 0;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        printf("Indirizzo %p inizializzato a %d \n", &array[i], array[i]);
//    }
//
//    for (int i = 0; i < 10; i++) {
//        printf("Indirizzo %p inizializzato a %d \n", &array_calloc[i], array_calloc[i]);
//    }
//
//    free(array);  
//    free(array_calloc); 
//}