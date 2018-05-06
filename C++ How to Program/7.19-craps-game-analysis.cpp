/****
 * Play 1000 games of craps.
 * How many games are won on the 1st, 2nd, 20th, +20th roll?
 * How many games are lost on the 1st, 2nd, 20th, +20th roll?
 * What are the chances of winning at craps?
 * What's the average length of a game of craps?
 * Do the chances of winning improve with the length of the game?
 ***/

#include <iostream>
#include <iomanip>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime>

using namespace std;

enum Status { CONTINUE, WON, LOST }; 
Status oneGame( int winArray[], int loseArray[] );
double averageLength( int winArray[], int loseArray[], int rollArraySize );
int rollDice();

int main()
{
    const int rollArraySize = 22;
    const int gamesPlayed = 1000;
    int totalWins = 0;
    int totalLosses = 0;
    int winArray[ rollArraySize ] = { };
    int loseArray [ rollArraySize ] = { };

    // randomize random number generator using current time
    srand( time( 0 ) ); 

    // play 1000 games to collect data
    for ( int i = 0; i < gamesPlayed; i++ )
    {
        if ( oneGame( winArray, loseArray ) == WON )
            totalWins++;
        else
            totalLosses++;
    }

    // Output 1000 games' results
    cout << "Roll" << " Won" << " Lost" << endl;
    for ( int i = 1; i < rollArraySize; ++i )
    {
        if ( i < 21 )
            cout << setw( 4 ) << i << setw( 4 ) << winArray[ i ] << setw( 5 ) << loseArray[ i ] << endl;
        else
            cout << " 20+" << setw( 4 ) << winArray[ i ] << setw( 5 ) << loseArray[ i ] << endl;
    }
    cout << totalWins << " wins, " << totalLosses << " losses." << endl;

    // calculate chance of winning
    cout << setprecision( 1 ) << fixed << static_cast<double> (totalWins)/ 10 << "% win rate." << endl;

    // and output the average game length
    cout << "The average game length is " << averageLength( winArray, loseArray, rollArraySize ) << " rolls";
        
    return 0;
} // end main

double averageLength( int winArray[] , int loseArray[], int rollArraySize )
{
    // calculate average game length:
    // sum every element in the win & lose arrays and divide over 1000:
    // we'll cheat and not count games over 20 rolls long ;)
    int sum = 0;
    for ( int i = 1; i < rollArraySize-1; i++ )
    {
        sum += winArray[ i ] * i + loseArray[ i ] * i;
    }
    return ( sum / 1000.0 );


}
// play one game all the way to WIN or LOSE outcome
Status oneGame(int winArray[], int loseArray[] )
{
    Status gameStatus;
    int myPoint;
    int sumOfDice = rollDice(); // first roll of the dice
    int rollCount = 1;

    // determine game status and point (if needed) based on first roll
    switch ( sumOfDice )
    {
        case 7: // win with 7 on first roll
        case 11: // win with 11 on first roll
            gameStatus = WON;
            break;
        case 2: // lose with 2 on first roll
        case 3: // lose with 3 on first roll
        case 12: // lose with 12 on first roll
            gameStatus = LOST;
            break;
        default: // did not win or lose, so remember point
            gameStatus = CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
           //cout << "Point is " << myPoint << endl;
           break; // optional at end of switch
    }  // end switch


    // while game is not complete
    while ( gameStatus == CONTINUE ) // not WON or LOST
    {
        sumOfDice = rollDice(); // roll dice again
  
        // determine game status
        if ( sumOfDice == myPoint ) // win by making point
            gameStatus = WON;
        else
        if ( sumOfDice == 7 ) // lose by rolling 7 before point
             gameStatus = LOST;
        
        rollCount++;
    } // end while

    // add result to the appropriate tally array
    if ( gameStatus == WON ) 
    {
        if ( rollCount <= 20 )
            winArray[ rollCount ]++;
        else
            winArray[ 21 ]++;
    }
    else if ( gameStatus == LOST )
    {
        if ( rollCount <= 20 )
            loseArray[ rollCount ]++;
        else
            loseArray[ 21 ]++;
    }

  return gameStatus;
}

// roll dice, calculate sum and display results
int rollDice()
{
    // pick random die values
    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll

    int sum = die1 + die2; // compute sum of die values

    // display results of this roll
    //cout << "Player rolled " << die1 << " + " << die2
    //     << " = " << sum << endl;
    return sum; // end function rollDice
} // end function rollDice
