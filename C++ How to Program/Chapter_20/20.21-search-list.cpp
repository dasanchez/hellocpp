// Ex 20.21: Recursively Search a List
// Write a member function searchList that recursively searches a
// linked list object for a specified value.
// The function should return a pointer to the value if it’s found;
// otherwise, null should be returned. Use your function in a test program
// that creates a list of integers.
// The program should prompt the user for a value to locate in the list.

#include <iostream>
#include "List.h"

using std::cout;

int main()
{
    List<int> numbers;
    for (int i = 0; i < 10; ++i)
        numbers.insertAtBack(i);

    numbers.print();

    cout << "Looking for number 6..." << endl;
    const ListNode<int> *number = numbers.searchList(6);
    if (number != NULL)
        cout << "Number found: " << number->getData() << endl;
    else
        cout << "Number not found" << endl;

    number = numbers.searchList(11);
    cout << "Looking for number 11..." << endl;
    if (number != NULL)
        cout << "Number found: " << number->getData() << endl;
    else
        cout << "Number not found" << endl;
}
