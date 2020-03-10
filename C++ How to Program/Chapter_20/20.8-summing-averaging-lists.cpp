// Ex 20.8: Summing and Averaging Elements in a List
// Write a program that inserts 25 random integers from 0 to 100
// in order in a linked list object. The program should calculate
// the sum of the elements and the floating-point average of the
// elements.

#include <iostream>
#include "List.h"

int main()
{
    List<int> list;

    list.insertAtFront(2);
    list.insertAtFront(1);
    list.insertAtBack(3);
    list.insertAtBack(5);
    list.insertAtBack(4);
    list.insertAtBack(6);

    list.print();

    // sum and average
    float sum = 0;
    float average = 0.0;
    for (unsigned int i = 0; i<list.getSize(); ++i)
        sum += list.at(i);
    average = sum / list.getSize();

    cout << "The average of the list is " << average << endl;

}
