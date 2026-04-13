#include "cdll.h"

CDLLNode* Create_cdll_node(int value) {
    CDLLNode* newNode = malloc(sizeof(CDLLNode));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void CDLLVypis(CDLL* list) {
    printf("Obsah kruhoveho seznamu: ");
    if (list == NULL || list->head == NULL) {
        printf("Seznam je prazdny.\n");
        return;
    }
    CDLLNode* curr = list->head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
    printf("\n");
    return;
}

CDLLNode* Find(CDLL* list, int value) {
    if (list == NULL || list->head == NULL) {
        printf("Seznam je prazdny.\n");
        return NULL;
    }
    CDLLNode* curr = list->head;
    do {
        if (curr->data == value) {
            printf("Hodnota %d nalezena v seznamu.\n", value);
            return curr;
        }
        curr = curr->next;
    } while (curr != list->head);
    printf("Hodnota %d nenalezena v seznamu.\n", value);
    return NULL;
}

CDLL* InsertAfter(CDLL* list, CDLLNode* after, int value) {
    printf("Zacinam funkcu InsertAfter.\n");
    CDLLNode* newNode = Create_cdll_node(value);
    if (newNode == NULL) {
        printf("Nepodarilo se alokovat pamet pro novy node.\n");
        return list;
    }
    if (list == NULL) {
        printf("Seznam je prazdny.\n");
        list = malloc(sizeof(CDLL));
        if (list == NULL) return NULL;
        list->head = newNode;
        list->size = 1;
        return list;
    }
    if (after == NULL) {
        printf("Nezadany node, vkladam na konec seznamu.\n");
        after = list->head->prev;
    }
    printf("Vkladam prvek %d za prvek %d.\n", value, after->data);
    newNode->next = after->next;
    newNode->prev = after;
    after->next->prev = newNode;
    after->next = newNode;
    list->size++;
    return list;
}

CDLL* Delete(CDLLNode* node) {
    if (node == NULL) {
        printf("Node je prazdny, neni co smazat.\n");
        return NULL;
    }
    printf("Mazani prvku %d ze seznamu.\n", node->data);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return NULL;
}


