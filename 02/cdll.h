#ifndef CDLL_H
#define CDLL_H

typedef struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
} CDLLNode;

CDLLNode* CreateCDLLNode(int value);

typedef struct CDLL {
    CDLLNode* head;
} CDLL;

CDLL* Vypis(CDLL* head);

CDLL* Find(CDLL* head, int value);

CDLL* InsertAfter(CDLL* head, int value, int newValue);

CDLL* Delete(CDLL* head, int value);

#endif //CDLL_H