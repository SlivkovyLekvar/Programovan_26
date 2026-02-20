#include <stdio.h>
#include "list.h"

int main() {

    int arr[] = {5, 10, 15, 20};
    int len = sizeof(arr) / sizeof(arr[0]); // dohladane na internete, ako spocitat length of array v C
    Node* list = convert_array(arr, len);

    save_to_txt("output.txt", list);
    printf("Seznam ulozen do souboru.\n");

    Node* new_list = NULL;
    read_from_txt("output2.txt", &new_list);
    printf("Seznam nacten ze souboru:\n");

    print_list(new_list);

    return 0;
}



