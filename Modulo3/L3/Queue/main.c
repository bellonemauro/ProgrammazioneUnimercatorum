/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio definizione di una coda in c                          |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
  
#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);

    printQueue(&q);

    int first = frontValue(&q);
    printf("Elemento in testa (front): %d\n", first);

    int removed = dequeue(&q);
    printf("Elemento rimosso: %d\n", removed);

    printQueue(&q);

    return 0;
}

