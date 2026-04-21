// Tento zdrojovy kod som vypracovala samostatne bez cizi pomoci
// Nekopirovala som ani neopisovala cudzie zdrojove kody
// Nikto mi pri vypracovani neradil
// Ak niektory riadok tieto pravidla porusuje, je oznaceny komentarom
// TOTO NENI MOJE TVORBA
// Poruseni pravidel je podvod a tresta sa VYLOUCENIM ZE STUDIA
// Nicol Tomkova, 43106

#include "queue.h"
#include "cdll.h"

int main() {

    Queue f = Create();
    Enqueue(&f, 4); Enqueue(&f, 1); Enqueue(&f, 8);
    Vypis(&f);
    int i1 = Dequeue(&f); // 4 
    int i2 = Dequeue(&f);  // 1
    int i3 = Front(&f); // 8
    bool b = IsEmpty(&f); // false
    Enqueue(&f, 5); Enqueue(&f, 7);
    Vypis(&f); // 8 5 7

    CDLL* s = NULL;
    printf("Vytvarim kruhovy seznam.\n");
    s = InsertAfter(s, NULL, 5); 
    CDLLVypis(s); // 5
    s = InsertAfter(s, s->head, 7); 
    CDLLVypis(s); // 5 7
    s = InsertAfter(s, s->head, 2); 
    CDLLVypis(s); // 5 2 7
    InsertAfter(s, s->head->next, 1); // neukladame novy zacatek ??
    CDLLVypis(s); // 5 2 1 7
    s = InsertAfter(s, s->head->next, 9); 
    CDLLVypis(s); // 2 9 1 7 5
    Delete(s, s->head->next); // neukladame novy zacatek ??
    CDLLVypis(s); // 2 1 7 5
    CDLLNode* s2 = Find(s, 7);
    s = Delete(s, s2); 
    CDLLVypis(s); // 5 2 1

    int pole[] = { 1055, 2, 29, 8, 7, 15, 29, 8, 22, 6, 29 };
    CDLL* s1 = ConvertArray(pole, sizeof(pole) / sizeof(pole[0]));
    CDLLVypis(s1); // 1055 2 29 8 7 15 29 8 22 6 29
    s1 = DeleteAll(s1, 29); 
    CDLLVypis(s1); // 1055 2 8 7 15 8 22 6
    CDLL*s3 = Reverse(s1); // 6 22 8 15 7 8 2 1055
    CDLLVypis(s3); // 6 22 8 15 7 8 2 1055
    CDLL* s4 = Sort(s3); // 2 6 7 8 8 15 22 1055
    CDLLVypis(s4); // 2 6 7 8 8 15 22 1055
    return 0;

}