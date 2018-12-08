/****
 * Duplicate Elimination
 * Use a one-dimensional array to solve the following problem.
 * Read in 20 numbers, each of which is between 10 and 100, inclusive.
 * As each number is read, validate it and store it in the array only
 * if it isn't a duplicate of a number already read.
 * After reading all the values, display only the unique values that
 * the user entered.
 ***/
#include <iostream>
using namespace std;

bool isDuplicate( int number, int arraySize, int array[] );

int main()
{
    int arraySize = 5;
    int validEntries = 0;
    int array[ arraySize ] = { };

    cout << "Enter " << arraySize << " numbers between 10 and 100:" << endl;

    for ( int i = 0; i < arraySize; ++i )
    {
        int number;
        cin >> number;
        if ( !isDuplicate( number, arraySize, array ) )
        {
            array[ validEntries ] = number;
            validEntries++;
        }
    }
    
    // Loop through the array to print
    cout << "\nUnique entries:" << endl;
    for ( int i = 0; i < validEntries; ++i )
    {
        cout << "array[ " << i << " ] : " << array[ i ] << endl;
    }  

    return 0;
} // end main

bool isDuplicate( int number, int arraySize, int array[] )
{
    for ( int i = 0; i < arraySize; ++i)
    {
        if ( number == array[ i ] )
            return true;
    }
    return false;
}
