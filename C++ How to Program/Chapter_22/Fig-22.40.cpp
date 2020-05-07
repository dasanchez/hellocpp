// Fig 22.40: Using a bitset to demonstrate the
// Sieve of Eratosthenes.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
    const int SIZE = 1024;
    int value;
    bitset<SIZE> sieve; // create bitset of 1024 bits
    sieve.flip(); // flip all bits in bitset sieve
    sieve.reset(0); // reset first bit (number 0)
    sieve.reset(1); // reset second bit (number 1)

    // perform Sieve of Eratosthenes
    int finalBit = sqrt(static_cast<double>(sieve.size())) + 1;

    // determine all prime numbers from 2 to 1024
    for (int i=2; i<finalBit; ++i)
    {
        if (sieve.test(i)) // bit is on
        {
            for (int j=2*i; j<SIZE; j+=i)
                sieve.reset(j); // set bit j off
        } // end if
    }  // end for

    cout << "The prime numbers in the range 2 to 1023 are:\n";

    // display prime numbers in range 2-1023
    for (int k=2, counter = 1; k<SIZE; ++k)
    {
        if (sieve.test(k)) // bit k is on
        {
            cout << setw(5) << k;
            if (counter++ % 12 == 0) // counter is multiple of 12
                cout << '\n';
        } // end if
    } // end for

    cout << endl;

    // get value from user  to determine whether value is prime
    cout <<"\nEnter a value from 2 to 1023 (-1 to end): ";
    cin >> value;

    // deermine whether user input is prime
    while (value != -1)
    {
        if (sieve[value]) // prime number
            cout << value << " is a prime number\n";
        else // not a prime number
            cout << value << " is not a prime number\n";

        cout << "\nEnter a value from 2 to 1023 (-1 to end): ";
        cin >> value;
    } // end while
} // end main
