// Ex 20.9: Copying a List in Reverse Order
// Write a program that creates a linked list object of 10 characters
// and creates a second list object containing a copy of the first list, 
// but in reverse order.

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "List.h"

int main()
{
    List<int> list;

    srand(time(0)); // seed random

    // populate list with 10 numbers between 0 and 99:
    for (int i=0; i< 10; ++i)
    {
        int value = rand() % 100;
        list.insertAtBack(value);
    }

    list.print();

    // create new list and insert all numbers in reverse order
    List<int> reverseList;
    
    for (unsigned int i = 0; i < list.getSize(); ++i)
    {
        reverseList.insertAtFront(list.at(i));
    }

    reverseList.print();

}
