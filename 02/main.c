// Tento zdrojovy kod som vypracovala samostatne bez cizi pomoci
// Nekopirovala som ani neopisovala cudzie zdrojove kody
// Nikto mi pri vypracovani neradil
// Ak niektory riadok tieto pravidla porusuje, je oznaceny komentarom
// TOTO NENI MOJE TVORBA
// Poruseni pravidel je podvod a tresta sa VZLOUCENIM ZE STUDIA
// Nicol Tomkova, 43106

#include <stdio.h>
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
    s = InsertAfter(s, s->head, 5); 
    CDLLVypis(s); // 5
    s = InsertAfter(s, s->head, 7); 
    CDLLVypis(s); // 5 7
    s = InsertAfter(s, s->head, 2); 
    CDLLVypis(s); // 5 2 7
    InsertAfter(s, s->head->next, 1); // neukladame novy zacatek
    CDLLVypis(s); // 5 2 1 7
    s = InsertAfter(s, s->head->next, 9); 
    CDLLVypis(s); // 2 9 1 7 5
    Delete(s->head->next); // neukladame novy zacatek
    CDLLVypis(s); // 2 1 7 5
    CDLLNode* s2 = Find(s, 7);
    s = Delete(s2); 
    CDLLVypis(s); // 5 2 1



    return 0;
}