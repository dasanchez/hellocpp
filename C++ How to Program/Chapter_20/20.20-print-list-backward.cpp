// Ex 20.20: Recursively Print a List Backward
// Write a member function printListBackward that recursively outputs
// the items in a linked list object in reverse order.
// Write a test program that creates a sorted list of integers
// and prints the list in reverse order.

#include <iostream>
#include <string>
#include <sstream>
// #include <vector>
#include "List.h"

using std::cout;

int main()
{
    List<int> numbers;
    for (int i = 0; i < 10; ++i)
        numbers.insertAtBack(i);

    numbers.print();
    numbers.printBackward();
}
