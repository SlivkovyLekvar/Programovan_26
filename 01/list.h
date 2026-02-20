#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value);

Node* convert_array(int array[], int len);

int save_to_txt(const char* filename, Node* start);

int read_from_txt(const char* filename, Node** start);

#endif
