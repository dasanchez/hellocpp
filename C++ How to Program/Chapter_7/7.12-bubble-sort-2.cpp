/****
 * Bubble sort enhancements:
 * a. Instead of making nine comparisons on every pass,
 * modify the bubble sort to make eight comparisons on every pass,
 * seven on the third pass, and so on.
 * b. Modify the sort to check at the end of each pass if any swaps
 * have been made. If none have been made, the data must already be
 * in the proper order, so the program should terminate.
 ***/

#include <iostream>
using namespace std;

int main()
{
    int arraySize = 10;

    int array[ arraySize ] = { 3, 6, 4, 5, 2, 0, 1, 7, 8, 9};

    // Loop through the array to print
    for ( int i = 0; i < arraySize; ++i )
    {
        cout << "array[ " << i << " ] : " << array[ i ] << endl;
    }  
    
    cout << endl;
    // Number of passes
    for (int pass = 0; pass < arraySize - 1; ++pass) // number of passes
    {
        bool swaps = false;
        cout << "Pass " << pass + 1 << ": " << endl;
        for ( int i = 0; i < arraySize - 1 - pass; ++i ) // number of comparisons
        {
            int bubble = array [ i+ 1];
            if ( array[ i ] > bubble ) // next element is higher
            {
                cout << "Swap " << array[ i ] << " with " << bubble << endl;
                array [ i + 1 ] = array [ i ];
                array [ i ] = bubble;
                swaps = true;
            }
        }
        if ( !swaps ) // no further passes required
        {
            cout << "Array is in order" << endl;
            break;
        }
            
    }
    
    // Loop through the array to print
    for ( int i = 0; i < arraySize; ++i )
    {
        cout << "array[ " << i << " ] : " << array[ i ] << endl;
    }  

    return 0;
} // end main

