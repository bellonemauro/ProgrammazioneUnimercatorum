// queue.c
#include <stdio.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Errore: Queue piena\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->data[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Errore: Queue vuota\n");
        return -1;
    }
    return q->data[(q->front)++];
}

int frontValue(Queue *q) {
    if (isEmpty(q)) {
        printf("Errore: Queue vuota\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("La queue è vuota.\n");
        return;
    }
    printf("Contenuto della queue (dalla testa alla coda):\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
