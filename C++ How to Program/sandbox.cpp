// Fig 7.12
// Static arrays are initialized to zero. 
#include <iostream>
using namespace std;

void staticArrayInit(void);
void automaticArrayInit(void);
const int arraySize = 3;

int main()
{
    cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    cout << endl;
} // end main

// function to demonstrate a static local array
void staticArrayInit()
{
    // initializes the elements to 0 the first time the function is called
    static int array1[arraySize]; // static local array

    cout << "\nValues on entering staticArrayInit:\n";

    // output contents of array 1
    for (int i = 0; i < arraySize; ++i)
        cout << "array1[" << i << "] = " << array1[i] << " ";

    cout << "\nValues on exiting staticArrayInit:\n";

    // modify and output contents of array1
    for (int j = 0; j < arraySize; ++j)
        cout << "array1[" << j << "] = " << (array1[j] += 5 ) << " ";
} // end function staticArrayInit

void automaticArrayInit()
{
    // initializes  elements each time the function is called
    int array2[arraySize] = {1, 2, 3}; // automatic local array

    cout << "\nValues on entering automaticArrayInit:\n";

    // output contents of array 2
    for (int i = 0; i < arraySize; ++i)
        cout << "array2[" << i << "] = " << array2[i] << " ";

    cout << "\nValues on exiting automaticArrayInit:\n";

    // modify and output contents of array2
    for (int j = 0; j < arraySize; ++j)
        cout << "array2[" << j << "] = " << (array2[j] += 5 ) << " ";
} // end function automaticArrayInit