#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue* Create() {
    Queue* q = malloc(sizeof(Queue));
    q->start = NULL;
    return q;
}

bool IsEmpty(Queue* q) {
    return q->start == NULL;
}

int Enqueue(Queue* q, int n) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = n;
    newNode->next = NULL;
    if (q->start == NULL) {
        q->start = newNode;
        q->end = newNode;
    } else {
        q->end->next = newNode;
        q->end = newNode;
    }
    return 0;
}

