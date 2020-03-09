// Ex 20.7: Merging ordered lists
// Write a program that merges two ordered list objects of integers into
// a single ordered list object of integers. Function merge should receive
// references to each of the list objects to be merged and reference to
// a list object into which the merged elements will be placed.

#include <iostream>
#include "List.h"

int main()
{
    List<int> list1; // to be merged with list 2
    List<int> list2; // to be merged with list 1
    List<int> list3; // result list

    list1.insertAtFront(1);
    list1.insertAtBack(3);
    list1.insertAtBack(5);

    list2.insertAtFront(2);
    list2.insertAtBack(4);
    list2.insertAtBack(6);

    List<int>::merge(list1, list2, list3);
    list3.print();
}
