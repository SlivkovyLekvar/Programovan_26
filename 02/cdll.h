#ifndef CDLL_H
#define CDLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
} CDLLNode;

CDLLNode* Create_cdll_node(int value);

typedef struct CDLL {
    CDLLNode* head;
    int size;
} CDLL;

void CDLLVypis(CDLL* list);

CDLLNode* Find(CDLL* list, int value);

CDLL* InsertAfter(CDLL* list, CDLLNode* after, int value);

CDLL* Delete(CDLL* list, CDLLNode* node);

CDLL* DeleteAll(CDLL* list, int value);

CDLL* ConvertArray(int array[], int len);

CDLL* Reverse(CDLL* list);

CDLL* Sort(CDLL* list);

#endif //CDLL_H