/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio definizione di uno stack in c                         |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
  
#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStack(&s);

    int topElement = peek(&s);
    printf("Elemento in cima (peek): %d\n", topElement);

    int removed = pop(&s);
    printf("Elemento rimosso: %d\n", removed);

    printStack(&s);

    return 0;
}

