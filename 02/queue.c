#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue Create() {
    Queue q;
    q.start = NULL;
    q.end = NULL;
    return q;
}

bool IsEmpty(Queue q) {
    return q.start == NULL;
}

int Enqueue(Queue q, int n) {
    printf("Vkládám prvek %d do fronty.\n", n);
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = n;
    newNode->next = NULL;
    if (q.start == NULL) {
        q.start = newNode;
        q.end = newNode;
    } else {
        q.end->next = newNode;
        q.end = newNode;
    }
    printf("start: %d.\n", q.start->data);
    printf("end: %d.\n", q.end->data);
    return 0;
}

int Dequeue(Queue q) {
    if (q.start == NULL) {
        printf("Fronta je prazdna, neni co vratit.");
        return -1;
    }
    Node* temp = q.start;
    int value = q.start->data;
    if (q.start->next == NULL) {
        printf("Odebrali jste posledni prvek fronty.");
        q.end = NULL;
    } else q.start = q.start->next;
    free(temp);
    return value;
}

int Front(Queue q) {
    if (q.start == NULL) {
        printf("Fronta je prazdna.");
        return -1;
    }    
    return q.start->data;
}

int Vypis(Queue q) {
    printf("Obsah fronty: start: %d.\n", q.start->data);
    if (q.start == NULL) {
        printf("Fronta je prazdna.\n");
        return -1;
    }
    Node* i = q.start;
    while (i!=q.end) {
        printf("%d ", i->data);
        i = i->next;
    } 
    printf ("%d\n", i->data);
    return 0;
}

