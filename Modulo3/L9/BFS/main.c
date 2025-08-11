/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio BFS                                                   |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Funzioni per la coda
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

// Funzioni per il grafo
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    printf("Struttura del grafo:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Nodo %c: ", 'A' + i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%c ", 'A' + temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}


void printGraphAsTreeDyn(Graph* graph) {
    printf("Struttura del grafo (vista ad albero da A):\n");

    for (int i = 0; i < graph->numVertices; i++) {
        printf("%c\n", 'A' + i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("  └── %c\n", 'A' + temp->vertex);
            temp = temp->next;
        }
    }

    printf("\n");
}


void printGraphAsTreeStatic() {
    printf("Struttura del grafo (vista ad albero):\n\n");
    printf("    A\n");
    printf("   / \\\n");
    printf("  B   C\n");
    printf("  |   |\n");
    printf("  D   E\n\n");
}



void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("Visita in ampiezza (BFS):\n");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visito nodo %c\n", 'A' + currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                printf("  Scopro nodo %c e lo metto in coda\n", 'A' + adjVertex);
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    Graph* graph = createGraph(MAX_VERTICES);

    addEdge(graph, 0, 1); // A-B
    addEdge(graph, 0, 2); // A-C
    addEdge(graph, 1, 3); // B-D
    addEdge(graph, 2, 4); // C-E

    printGraph(graph);
    printGraphAsTreeDyn(graph);
    printGraphAsTreeStatic();
    bfs(graph, 0); // Partenza da A

    return 0;
}
