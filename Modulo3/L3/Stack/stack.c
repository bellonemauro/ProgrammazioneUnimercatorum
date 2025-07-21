// stack.c
#include <stdio.h>
#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Errore: Stack pieno\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Errore: Stack vuoto\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Errore: Stack vuoto\n");
        return -1;
    }
    return s->data[s->top];
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Lo stack è vuoto.\n");
        return;
    }
    printf("Contenuto dello stack (dalla base alla cima):\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
