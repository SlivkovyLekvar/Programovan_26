#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_node(int value) {
    Node* new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

Node* convert_array(int array[], int len) {

    if (len == 0) return NULL;

    Node* vys;
    Node* akt;
    vys = akt = NULL;
    for (int i = 0; i < len; i++ ) {
        Node* tmp = create_node(array[i]);
        if (vys == NULL) vys = akt = tmp;
        else akt = akt->next = tmp;
    }
    return vys;
}

int save_to_txt(const char* filename, Node* start) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        return(100);
    }
    // Novy ukazovatel, ktory sa bude posuvat
    Node* curr = start;
    
    while (curr != NULL) {
        fprintf(file, "%d", curr->value);
        curr = curr->next;
    }

    fclose(file);

    return 0;

}