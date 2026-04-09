#include "cdll.h"

CDLLNode* Create_cdll_node(int value) {
    CDLLNode* newNode = malloc(sizeof(CDLLNode));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

CDLL* Vypis(CDLL* head) {
    printf("Obsah kruhoveho seznamu: ");
    if (head == NULL) {
        printf("Seznam je prazdny.\n");
        return head;
    }
    CDLLNode* curr = head->head;
    while (curr != head->head) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return head;
}

CDLL* Find(CDLL* head, int value) {
    if (head == NULL) {
        printf("Seznam je prazdny.\n");
        return NULL;
    }
    CDLLNode* curr = head->head;
    while (curr != head->head) {
        if (curr->data == value) {
            printf("Hodnota %d nalezena v seznamu.\n", value);
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

CDLL* InsertAfter(CDLL* head, int value, int position_value) {
    CDLLNode* newNode = Create_cdll_node(value);
    if (newNode == NULL) return NULL;
    if (head == NULL) {
        printf("Seznam je prazdny, vkladam prvni prvek.\n");
        head->head = newNode;
        head->size = 1;
        return head;
    }
    CDLLNode* curr = head->head;
    while (curr != head->head) {
        if (curr->data == position_value) {
            CDLLNode* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
            newNode->prev = curr;
            temp->prev = newNode;
            head->size++;
            printf("Vkladam prvek %d za prvek %d.\n", value, position_value);
            return head;
        }
        curr = curr->next;
    }
    printf("Prvek %d nenalezen v seznamu.\n", position_value);
    return head;
}

CDLL* Delete(CDLL* head, int value) {
   if (head == NULL) {
    printf("Seznam je prazdny, neni co smazat.\n");
    return head;
   }
   CDLLNode* curr = head->head;
   while (curr != head->head) {
    if 

   }
}
