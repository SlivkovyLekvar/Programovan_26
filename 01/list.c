#include <stdio.h>
#include "list.h"

Node* create_node(int value) {
    Node* new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

void save_to_txt(const char* filename, Node* start) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        return("ERROR: File does not exist");
    }
    // Novy ukazovatel, ktory sa bude posuvat
    Node* curr = start;
    
    while (curr != NULL) {
        fprintf(file, "%d", curr->value);
        curr = curr->next;
    }

    fclose(file);

}