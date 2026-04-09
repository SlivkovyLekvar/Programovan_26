#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* Create_node(int value);

typedef struct Queue {
    Node* end;
    Node* start;
} Queue;

Queue Create();

bool IsEmpty(Queue* q);

// vloží prvek na konec fronty
int Enqueue(Queue* q, int n);
// odebere prvek ze začátku fronty a vrátí jeho hodnotu
int Dequeue(Queue* q);
// vrátí hodnotu prvku ze začátku fronty
int Front(Queue* q);

int Vypis(Queue* q);

#endif // QUEUE_H