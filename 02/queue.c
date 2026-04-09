#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue Create() {
    Queue q;
    q.start = NULL;
    printf("Vytvářím novou frontu.\n");
    q.end = NULL;
    return q;
}

Node* Create_node(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

bool IsEmpty(Queue* q) {
    return q->start == NULL;
}

int Enqueue(Queue* q, int n) {
    Node* newNode = Create_node(n);
    if (newNode == NULL) return -1;
    if (q->start == NULL) {
        printf("Fronta je prazdna, vkladam prvni prvek.\n");
        q->start = newNode;
        q->end = newNode;
    } else {
        printf("Fronta neni prazdna, vkladam prvek %d na konec.\n", n);
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
    printf("Odebiram prvek %d ze zacatku fronty.\n", value);
    return value;
}

int Front(Queue* q) {
    if (q->start == NULL) {
        printf("Fronta je prazdna.");
        return -1;
    }    
    return q->start->data;
}

int Vypis(Queue* q) {
    printf("Obsah fronty: ");
    if (q->start == NULL) {
        printf("Fronta je prazdna.\n");
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

