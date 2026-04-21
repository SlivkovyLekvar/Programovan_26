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

CDLL* Delete(CDLL* list, CDLLNode* node) {
    if (list == NULL || list->head == NULL) {
        printf("Seznam je prazdny, neni co smazat.\n");
        return NULL;
    }
    if (node == NULL) {
        printf("Node je prazdny, neni co smazat.\n");
        return list;
    }
    printf("Mazani prvku %d ze seznamu.\n", node->data);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    list->size--;
    return list;
}

CDLL* DeleteAll(CDLL* list, int value) {
    if (list == NULL || list->head == NULL) {
        printf("Seznam je prazdny, neni co smazat.\n");
        return NULL;
    }
    bool found = false;
    CDLLNode* curr = list->head;
    do { 
        if (curr->data == value) {
            found = true;
            CDLLNode* toDelete = curr;
            curr = curr->next;
            Delete(list, toDelete);
        } else {
            curr = curr->next;
        }
    } while (curr != list->head);
    if (!found) {
        printf("Hodnota %d nenalezena v seznamu, neni co smazat.\n", value);
    }
    return list;
}

CDLL* ConvertArray(int array[], int len) {
    printf("Zacinam funkci ConvertArray ");
    printf("s polem o delce: %d\n", len);
    CDLL* list = NULL;
    if (len == 0 || array == NULL) {
        printf("Pole je prazdne, nelze konvertovat.\n");
        return NULL;
    }
    list = InsertAfter(list, NULL, array[0]);
    for (int i = 1; i < len; i++) {
        list = InsertAfter(list, NULL, array[i]);
    }
    return list;
}

CDLL* Reverse(CDLL* list) {
    if (list == NULL || list->head == NULL) {
        printf("Seznam je prazdny, nelze obracet.\n");
        return NULL;
    }
    printf("Zacinam funkci Reverse.\n");
    CDLLNode* curr = list->head;
    CDLLNode* temp;
    do {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    } while (curr != list->head);
    list->head = list->head->next;
    return list;
}

CDLL* Sort(CDLL* list) {
    printf("Zacinam funkci Sort.\n");
    CDLLNode* start = list->head;
    if (list == NULL || start == NULL) {
        printf("Seznam je prazdny, nelze seradit.\n");
        return NULL;
    }
    if (start->next == start) {
        printf("Seznam obsahuje pouze jeden prvek, neni co seradit.\n");
        return list;
    }
    CDLLNode* min;
    CDLLNode* curr;
    bool sorted;
    int i = 0;
    do {
        curr = min = start;
        sorted = false;
        do {
            CDLLNode* temp = curr->next;
            if (curr->data < min->data) {
                curr->next = min;
                curr->prev->next = temp;
                temp->prev = curr->prev;
                curr->prev = min->prev;
                min->prev->next = curr;
                min->prev = curr;
                min = curr;
                sorted = true;
            }
            curr = temp;
        } while (curr != list->head);
        if (i==0) {
                list->head = min;
            }
        if (!sorted) {
            start = start->next;
        }
        printf("start = %d.", start->data);
        printf("Po %d. iteraci: ", i+1);
        CDLLVypis(list);
        i++;
    } while (start->next!=list->head);
    return list;
}

