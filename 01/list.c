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

    Node* new;
    Node* curr;
    new = curr = NULL;
    for (int i = 0; i < len; i++ ) {
        Node* tmp = create_node(array[i]);
        if (new == NULL) new = curr = tmp;
        else curr = curr->next = tmp;
    }
    return new;
}

int save_to_txt(const char* filename, Node* start) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Soubor nelze otevrit.\n");
        return(100);
    }

    Node* curr = start;   
    while (curr != NULL) {
        fprintf(file, "%d ", curr->value);
        curr = curr->next;
    }

    fclose(file);

    return 0;

}

int read_from_txt(const char *filename, Node **list) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Soubor nelze otevrit.\n");
        return(100);
    }

    Node* start = NULL;
    Node* curr = NULL;

    int tmp;

    while (fscanf(file, "%d", &tmp) == 1) {
        Node* new = create_node(tmp);
        if (start == NULL) start = curr = new;
        else curr = curr->next = new;
    }

    fclose(file);
    *list = start;
    return 0;
}

void print_list(Node* start) {
    Node* curr = start;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int count_occurences(Node *start, int value) {
    int count = 0;
    Node* curr = start;
    while (curr != NULL) {
        if (curr->value == value) count++;
        curr = curr->next;
    }
    return count;
}

Node *delete_last_occurrence(Node *start, int value)
{
    Node* curr = start;
    Node* last_occurrence = NULL;
    Node* prev = NULL;
    Node* prev_last = NULL;
    while (curr != NULL) {
        if (curr->value == value) {
            prev_last = prev;
            last_occurrence = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    if (last_occurrence == NULL) {
        fprintf(stderr, "Hodnota nenalezena v seznamu.\n");
        return start;
    }
    if (prev_last == NULL) start = start->next;
        else prev_last->next = last_occurrence->next;
    free(last_occurrence);
    return start;
}
