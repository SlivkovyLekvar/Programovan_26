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

int Dequeue(Queue* q) {
    if (q->start == NULL) {
        printf("Fronta je prazdna, neni co vratit.");
        return -1;
    }
    Node* temp = q->start;
    int value = q->start->data;
    if (q->start->next == NULL) {
        printf("Odebrali jste posledni prvek fronty.");
        q->end = NULL;
    } else q->start = q->start->next;
    free(temp);
    return value;
}

int Front(Queue* q) {
    if (q == NULL) {
        printf("Fronta je prazdna.");
        return -1;
    }    
    return q->start->data;
}

int Vypis(Queue* q) {
    if (q == NULL) {
        printf("Fronta je prazdna.");
        return -1;
    }
    Node* i = q->start;
    while (i!=q->end) {
        printf("%d ", i->data);
        i = i->next;
    } 
    printf ("%d\n", i->data);
    return 0;
}

