// main.c
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

// compilazione 
// gcc main.c queue.c -o queue_demo
