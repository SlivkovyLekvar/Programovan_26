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

void print_list(Node* start);

int count_occurences(Node* start, int value);

Node* delete_last_occurrence(Node* start, int value);

Node* delete_max(Node* start);

Node* reverse_list(Node* start);

Node* ascending_sort(Node* start);

Node* descending_sort(Node* start);

void delete_list(Node* start);

Node* swap_first_last(Node* start);

Node* swap_sdecond_penultimate(Node* start);


#endif
