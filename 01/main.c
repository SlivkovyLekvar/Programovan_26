#include <stdio.h>
#include "list.h"

int main() {

    int arr[] = {5, 10, 15, 20, 10, 25, 30, 10, 35, 40};
    int len = sizeof(arr) / sizeof(arr[0]); // dohladane na internete, ako spocitat length of array v C
    Node* list = convert_array(arr, len);
    print_list(list);

    save_to_txt("output.txt", list);
    printf("Seznam ulozen do souboru.\n");

    Node* new_list = NULL;
    read_from_txt("output2.txt", &new_list);
    printf("Seznam nacten ze souboru: ");

    print_list(new_list);

    int noOfOccurences = count_occurences(list, 10);
    printf("Hodnota 10 se v seznamu vyskytuje %d krat.\n", noOfOccurences);

    delete_last_occurrence(list, 10);    
    noOfOccurences = count_occurences(list, 10);
    printf("Hodnota 10 se v seznamu vyskytuje %d krat.\n", noOfOccurences);
    print_list(list);

    delete_max(new_list);
    print_list(new_list);

    Node* reversedList = reverse_list(new_list);
    print_list(reversedList);

    print_list(ascending_sort(reversedList));
    print_list(descending_sort(reversedList));

    return 0;
}



