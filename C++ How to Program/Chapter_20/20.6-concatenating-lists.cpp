// Ex 20.6: Concatenating Lists
// Write a program that concatenates two linked list objects of characters.
// The program should include function concatenate, which takes references to
// both list objects as arguments and concatenates the second list to the
// first list.

#include <iostream>
#include "List.h"

int main()
{
    List<char> list1;
    List<char> list2;

    list1.insertAtFront('H');
    list1.insertAtBack('e');
    list1.insertAtBack('l');

    list2.insertAtFront('l');
    list2.insertAtBack('o');
    list2.insertAtBack('\n');

    List<char>::concatenate(list1, list2);
    list1.print();
}
