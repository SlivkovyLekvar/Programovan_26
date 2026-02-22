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

Node *delete_max(Node *start){
    if (start == NULL) return NULL;
    Node* curr = start;
    Node* max_node = start;
    Node* prev = NULL;
    while (curr->next != NULL) {
        if (curr->next->value > max_node->value) {
            max_node = curr->next;
            prev = curr;
        }
        curr = curr->next;
    }
    if (prev == NULL) start = start->next;
        else prev->next = max_node->next;
    free(max_node);
    return start;
}

Node *reverse_list(Node *start){
    if (start == NULL) return NULL;
    Node* curr = start;
    Node* prev = NULL;
    Node* original_next = NULL;
    while (curr != NULL){
        original_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = original_next;    
    }
    return prev;
}

Node* ascending_sort(Node *start){
    if (start == NULL) return NULL;
    Node* sorted = NULL;
    while (start != NULL) {
        Node* max_node = start;
        Node* curr = start;
        Node* prev = NULL;
        while (curr->next != NULL) {
            if (curr->next->value > max_node->value) {
                max_node = curr->next;
                prev = curr;
            }
            curr = curr->next;
        } 
        if (prev == NULL) start = max_node->next;
            else prev->next = max_node->next;
        
        max_node->next = sorted;
        sorted = max_node;
    }
    return sorted;
}

Node *descending_sort(Node *start){
    return reverse_list(ascending_sort(start));
}

void delete_list(Node *start){
    Node* curr = start;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
}

Node *swap_first_last(Node *start){
    Node* penultimate = start;
    if (start == NULL || start->next == NULL) return start;
    Node* first = start;
    while (penultimate->next->next != NULL) penultimate = penultimate->next;
    start = penultimate->next;
    if (first->next->next == NULL) start->next = first;
    else {
        start->next = first->next;
        penultimate->next = first;
    }
    first->next = NULL;
    return start;
}

Node *swap_second_penultimate(Node *start){
    if (start == NULL || start->next == NULL) return start;
    if (start->next->next == NULL) return swap_first_last(start);
    if (start->next->next->next == NULL) return start;
    Node* prepenum = NULL;
    Node* penum = start;
    Node* second = start->next;
    while (penum->next->next != NULL) {
        prepenum = penum;
        penum = penum->next;
    }
    Node* temp = second->next;
    second->next = penum->next;
    start->next = penum;
    if (penum == temp) penum->next = second;
        else {
            penum->next = temp;
            prepenum->next = second;
        }
    return start;
}
