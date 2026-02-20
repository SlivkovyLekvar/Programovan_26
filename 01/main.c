#include <stdio.h>
#include "list.h"

int main() {

    int arr[] = {5, 10, 15, 20};
    int len = sizeof(arr) / sizeof(arr[0]); // dohladane na internete, ako spocitat length of array v C
    Node* list = convert_array(arr, len);

    save_to_txt("output.txt", list);

    printf("Seznam ulozen do souboru.\n");

    return 0;
}



