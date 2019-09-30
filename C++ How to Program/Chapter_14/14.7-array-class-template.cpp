// Ex 14.7: Array Class Template
// Reimplement class Array from Figs 11.10-11.11 as a class template.
// Demonstrate the new Array class template in a program.

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "Array.h" // Array class template definition

using namespace std;

void testIntArray();
void testDoubleArray();
void testCharArray();

int main()
{
    cout << "*** Testing ints ***" << endl;
    testIntArray();
    cout << "*** Testing doubles ***" << endl;
    testDoubleArray();
    cout << "*** Testing chars ***" << endl;
    testCharArray();

} // end main

void testIntArray()
{
    Array<int> intArray1(5); // size 5
    Array<int> intArray2;

    cout << "Size of intArray1 after initialization is "
         << intArray1.getSize() << "\nArray after initialization:\n"
         << intArray1;

    cout << "Size of intArray2 after initialization is "
         << intArray2.getSize() << "\nArray after initialization:\n"
         << intArray2;

    // populating intArray1 and intArray2
    int intValue = 11;
    for (int i = 0; i < intArray1.getSize(); ++i)
    {
        intArray1[i] = intValue++;
    }
    for (int i = 0; i < intArray2.getSize(); ++i)
    {
        intArray2[i] = intValue++;
    }

    cout << "After initializing, the arrays contain:\n"
         << "intArray:\n"
         << intArray1
         << "intArray2:\n"
         << intArray2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: intArray1 != intArray2" << endl;

    if (intArray1 != intArray2)
        cout << "intArray1 and intArray2 are not equal" << endl;

    // create intArray3 using intArray1 as an initializer
    Array<int> intArray3(intArray1); // invokes copy constructor

    cout << "\nSize of intArray3 is "
         << intArray3.getSize()
         << "\nArray after initialization is:\n"
         << intArray3;

    // use overloaded assignment (=) operator
    cout << "\nAssigning intArray2 to intArray1:" << endl;
    intArray1 = intArray2; // intArray1 is smaller

    cout << "intArray1:\n"
         << intArray1
         << "intArray2:\n"
         << intArray2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating: intArray1 == intArray2" << endl;

    if (intArray1 == intArray2)
        cout << "intArray1 and intArray2 are equal" << endl;

    // use overloaded  subscript operator to create rvalue
    cout << "\nintArray1[5] is " << intArray1[5] << endl;

    // use overloaded subscript operator to create lvalue
    cout << "\nAssigning 1000 to intArray1[5]" << endl;
    intArray1[5] = 1000;
    cout << "intArray1:\n"
         << intArray1;

    // attempt to use  out-of-range subscript
    try
    {
        cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
        intArray1[15] = 1000; // ERROR: subscript out of range
    }                         // end try
    catch (out_of_range &ex)
    {
        cout << "An exception occurred: " << ex.what() << endl;
    } // end catch
} // end testIntArray

void testDoubleArray()
{
    Array<double> array1(5); // size 5
    Array<double> array2;

    cout << "Size of array1 after initialization is "
         << array1.getSize() << "\nArray after initialization:\n"
         << array1;

    cout << "Size of array2 after initialization is "
         << array2.getSize() << "\nArray after initialization:\n"
         << array2;

    // populating intArray1 and intArray2
    double value = 0.5;
    for (int i = 0; i < array1.getSize(); ++i)
    {
        array1[i] = value *= -2;
    }
    for (int i = 0; i < array2.getSize(); ++i)
    {
        array2[i] = value *= -2;
    }

    cout << "After initializing, the arrays contain:\n"
         << "array:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: array1 != array2" << endl;

    if (array1 != array2)
        cout << "array1 and array2 are not equal" << endl;

    // create array3 using array1 as an initializer
    Array<double> array3(array1); // invokes copy constructor

    cout << "\nSize of array3 is "
         << array3.getSize()
         << "\nArray after initialization is:\n"
         << array3;

    // use overloaded assignment (=) operator
    cout << "\nAssigning array2 to array1:" << endl;
    array1 = array2; // array1 is smaller

    cout << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating: array1 == array2" << endl;

    if (array1 == array2)
        cout << "array1 and array2 are equal" << endl;

    // use overloaded  subscript operator to create rvalue
    cout << "\narray1[5] is " << array1[5] << endl;

    // use overloaded subscript operator to create lvalue
    cout << "\nAssigning 1000 to array1[5]" << endl;
    array1[5] = 1000;
    cout << "array1:\n"
         << array1;

    // attempt to use  out-of-range subscript
    try
    {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
        array1[15] = 1000; // ERROR: subscript out of range
    }                      // end try
    catch (out_of_range &ex)
    {
        cout << "An exception occurred: " << ex.what() << endl;
    } // end catch
} // end testDoubleArray

void testCharArray()
{
    Array<char> array1(5); // size 5
    Array<char> array2;

    cout << "Size of array1 after initialization is "
         << array1.getSize() << "\nArray after initialization:\n"
         << array1;

    cout << "Size of array2 after initialization is "
         << array2.getSize() << "\nArray after initialization:\n"
         << array2;

    // populating intArray1 and intArray2
    char value = 'a';
    for (int i = 0; i < array1.getSize(); ++i)
    {
        array1[i] = value += 2;
    }
    for (int i = 0; i < array2.getSize(); ++i)
    {
        array2[i] = value += 2;
    }

    cout << "After initializing, the arrays contain:\n"
         << "array:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: array1 != array2" << endl;

    if (array1 != array2)
        cout << "array1 and array2 are not equal" << endl;

    // create array3 using array1 as an initializer
    Array<char> array3(array1); // invokes copy constructor

    cout << "\nSize of array3 is "
         << array3.getSize()
         << "\nArray after initialization is:\n"
         << array3;

    // use overloaded assignment (=) operator
    cout << "\nAssigning array2 to array1:" << endl;
    array1 = array2; // array1 is smaller

    cout << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating: array1 == array2" << endl;

    if (array1 == array2)
        cout << "array1 and array2 are equal" << endl;

    // use overloaded  subscript operator to create rvalue
    cout << "\narray1[5] is " << array1[5] << endl;

    // use overloaded subscript operator to create lvalue
    cout << "\nAssigning 1000 to array1[5]" << endl;
    array1[5] = 'Z';
    cout << "array1:\n"
         << array1;

    // attempt to use  out-of-range subscript
    try
    {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
        array1[15] = 'Z'; // ERROR: subscript out of range
    }                     // end try
    catch (out_of_range &ex)
    {
        cout << "An exception occurred: " << ex.what() << endl;
    } // end catch
} // end testCharArray