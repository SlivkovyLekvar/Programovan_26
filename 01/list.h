#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void Save(const char* filename, Node* head);

#endif
