// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int frontValue(Queue *q);
void printQueue(Queue *q);

#endif
