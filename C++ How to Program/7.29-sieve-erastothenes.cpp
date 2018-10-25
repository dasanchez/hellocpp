// 7.29: The Sieve of Erastothenes
// The Sieve of Erastothenes is a method of finding prime numbers.
// 1. Create an array with all alements initialized to 1 (true).
//    Array elements with prime subscripts will remain 1, and all other
//    elements will eventually be set to 0.
// 2. Starting with array subscript 2, every time an array element
//    is found whose value is 1, loop through the remainder of the array
//    and set to zero every element whose subscript is a multiple of the
//    subscript for the element with value 1.
// 3. When this process is complete, the array elements that are still
//    set to 1 indicate that the subscript is a prime number.
//    These subscripts can then be printed.

// Write a program that uses an array of 1000 elements to determine and
// print the prime numbers between 2 and 999.
#include <iostream>
using namespace std;

int main()
{
    const int arraySize = 1000;

    bool primeArray[arraySize] = {1};

    // initialize array to all ones
    for (int i = 0; i < arraySize; ++i)
        primeArray[i] = true;
    
    // loop through all elements starting with 2:
    for (int i = 2; i < arraySize; ++ i)
    {
        if (primeArray[i] == 1)
        {
            // check for multiples:
            for (int j = i+1; j < arraySize; ++j)
            {
                if (j%i == 0)
                {
                    // found a multiple
                    primeArray[j] = false;
                }
            }
        }
    }

    // print all prime numbers left:
    for (int i = 2; i < arraySize; ++i)
    {
        if (primeArray[i])
            cout << i << endl;
    }
}