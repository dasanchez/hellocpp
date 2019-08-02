// Ex 11.7: Overloading the Parentheses Operator
// One nice example of overloading the function call operator()
// is to allow another form of double-array subscripting popular
// in some programming languages. Instead of saying
// chessBoard[row][column]
// for an array of objects, overload the function call operator
// to allow the alternate form
// chessBoard(row, column)
// Create a class DoubleSubscriptedArray that has similar features
// to class Array in Figs 11.10-11.11.
// At construction time, the class should be able to create an array
// of any number of rows and any number of columns.
// The  class should supply operator() to perform double-subscripting
// operations. For example, in a 3-by-5 DoubleSubscriptedArray called a,
// the user would write a(1, 3) to access the element at row 1 and 
// column 3.
// The underlying representation of the double-subscripted array
// should be a single-subscripted aray of integers with rows*columns
// number of elements.
// Function operator() should perform the proper pointer arithmetic
// to access each element of the array. There should be two versions
// of operator() - one that returns int& (so that an element of a  
// DoubleSubScriptedArray can be used as an lvalue) and one that
// returns const int &. 
// The class should also provide the following operators:
// ==, !=, =, << (for outputting the array in row and column format)
// and >> (for inputting the entire array contents).
 
#include <iostream>
#include <string>
#include "DoubleSubScriptedArray.h"
using namespace std;

int main()
{
    DoubleSubScriptedArray myArray(2, 2);
    myArray[0] = 10;
    myArray[1] = 20;
 
// << operator demonstrated throughout.

 // () operator:
 
    myArray(1, 0) = 30;
    myArray(1, 1) = 40;
    cout << "Value at (0, 1): " << myArray(0, 1) << endl;
    cout << "Value at (1, 0): " << myArray(1, 0) << endl;
    cout << "myArray: " << endl << myArray << endl; 

// == operator:
    DoubleSubScriptedArray mySecondArray(2, 2);
    mySecondArray[0] = 10;
    mySecondArray[1] = 20;
    mySecondArray[2] = 30;
    mySecondArray[3] = 40;
    cout << "mySecondArray: " << endl << mySecondArray << endl;
    cout << "myArray == mySecondArray : " << (myArray == mySecondArray) << endl;
    mySecondArray[3] = 50;
    cout << "mySecondArray: " << endl << mySecondArray << endl;
    cout << "myArray == mySecondArray : " << (myArray == mySecondArray) << endl;

// != operator:
    cout << "myArray != mySecondArray : " << (myArray != mySecondArray) << endl;
    mySecondArray[3] = 40;
    cout << "mySecondArray: " << endl << mySecondArray << endl;
    cout << "myArray != mySecondArray : " << (myArray != mySecondArray) << endl;

// = operator:
    DoubleSubScriptedArray myThirdArray(2, 5);
    myThirdArray(1, 0) = 100;
    cout << "myThirdArray: " << endl << myThirdArray << endl;
    myThirdArray = mySecondArray;
    cout << "myThirdArray: " << endl << myThirdArray << endl;

// >> operator:
    int newRows, newCols;
    cout << "How many rows do you need?" << endl;
    cin >> newRows;
    cout << "How many columns?" << endl;
    cin >> newCols;
    DoubleSubScriptedArray myFourthArray(newRows, newCols);
    cout << "Enter " << newRows*newCols << " numbers:" << endl;
    cin >> myFourthArray;

    cout << "myFourhArray:" << endl << myFourthArray << endl;

} // end main
