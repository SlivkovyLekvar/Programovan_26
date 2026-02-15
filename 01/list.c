#include <stdio.h>
#include "list.h"

void save_to_txt(const char* filename, Node* start) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        return("ERROR: File does not exist");
    }

    Node* curr = start;
    
    while (curr != NULL) {
        fprintf(file, "%d", curr->value);
        curr = curr->next;
    }

    fclose(file);

}