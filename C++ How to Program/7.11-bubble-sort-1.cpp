/****
 * Write a program that sorts an array of 10 integers using bubble sort.
 ***/

#include <iostream>
using namespace std;

int main()
{
    int arraySize = 10;

    int array[ arraySize ] = { 3, 6, 4, 8, 2, 7, 1, 9, 0, 5};

    // Loop through the array to print
    for ( int i = 0; i < arraySize; ++i )
    {
        cout << "array[ " << i << " ] : " << array[ i ] << endl;
    }  
    
    cout << endl;
    // loop through the array to sort
    // arraySize-1 passes
    for (int j = 0; j < arraySize - 1; ++ j)
    {
        cout << "Pass " << j + 1 << ": " << endl;
        for ( int i = 0; i < arraySize - 1; ++i )
        {
            int bubble = array [ i+ 1];
            if ( array[ i ] > bubble ) // next element is higher
            {
                cout << "Swap " << array[ i ] << " with " << bubble << endl;
                array [ i + 1 ] = array [ i ];
                array [ i ] = bubble;
            }
        }
    }
    
    cout << endl;
    // Loop through the array to print
    for ( int i = 0; i < arraySize; ++i )
    {
        cout << "array[ " << i << " ] : " << array[ i ] << endl;
    }  
    return 0;
} // end main
