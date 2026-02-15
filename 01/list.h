#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value);

void save_to_txt(const char* filename, Node* start);

#endif
