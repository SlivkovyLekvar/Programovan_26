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

    print_list(swap_first_last(list));

    Node* list3 = NULL;
    read_from_txt("output3.txt", &list3);
    print_list(swap_second_penultimate(list3));

    int p1[] = { 15, 6, 19, 25, 7, 0, 6, 1, 85 };
    int p2[] = { 15, 6, 19, 25, 7, 0 };
    Node* s1 = convert_array(p1, sizeof(p1) / sizeof(p1[0]));
    Node* s2 = convert_array(p2, sizeof(p2) / sizeof(p2[0]));

    int i = compare(s1, s2);
    printf("Porovnani seznamu: %d\n", i);

    Node* copy = copy_list(s2);
    print_list(copy);

    return 0;
}



