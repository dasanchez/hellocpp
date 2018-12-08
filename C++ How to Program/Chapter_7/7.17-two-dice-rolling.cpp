/****
 * Two-Dice Rolling
 * Write a program that simulates the rolling of two dice.
 * Use rand twice with each "throw".
 * Roll the dice 36,000 times.
 * Use a one-dimensional array to tally the number of times
 * each possible sum appears.
 * Print the results in a tabular format.
 ***/

#include <iostream>
#include <iomanip>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime>
using namespace std;

int rollDice( );

int main()
{
    unsigned int totalThrows = 36000;
    int results[ 11 ] = { };
    srand( time( 0 ) );

    cout << "Rolling two dice 36,000 times: " << endl;

    for ( unsigned int i = 0; i < totalThrows; ++i )
    {
        results[ rollDice() - 2 ]++;
    }

    cout << "Sum" << "    Seen" << endl;
    for ( int i = 0; i < 11; i++ )
    {
        cout << setw(3) << i + 2 << setw ( 8 ) << results[ i ] << endl;
    }

    return 0;
} // end main

  // roll dice, calculate sum and display results
int rollDice()
{
    // pick random die values
    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll

    int sum = die1 + die2; // compute sum of die values

    return sum;
} // end function rollDice