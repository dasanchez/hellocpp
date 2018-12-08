/*******************************************
A craps game simulator that allows wagering.
*******************************************/ 

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib> // contains prototypes for functions srand and rand
using std::rand;                                                      
using std::srand; 

#include <ctime>
using std::time;

enum Status { CONTINUE, WON, LOST }; 
Status oneGame();
int rollDice();

int main()
{
    int bankBalance = 1000;
    int wager;
    
    // randomize random number generator using current time
    srand( time( 0 ) ); 

    cout << "Welcome to the craps table!\nYou have $1000. Enter a wager (0 to exit):" << endl;

    // first wager entry
    do {
        cin >> wager;
        cout << "Wager: " << wager << endl;
        if ( wager > bankBalance)
            cout << "Wager must be less than or equal to your bank balance." << endl;
    } while ( wager > bankBalance );
    
    // keep playing until the player cashes out or goes broke
    while ( ( wager > 0 ) && ( bankBalance > 0 ) )
    {
        // run game
        if ( oneGame() == WON )
        {
            cout << "You won!" << endl;
            bankBalance += wager;
            cout << "You now have $" << bankBalance << "." << endl;

            // chatter
            if ( rand() % 3 == 0 )
            {
                if ( bankBalance > 5000 )
                    cout << "You're up big. Now's the time to cash in your chips!" << endl;
            }
        }
        else
        {
            cout << "You lost." << endl;
            bankBalance -= wager;
            cout << "You now have $" << bankBalance << "." << endl;

            if ( bankBalance <= 0 )
            {
                cout << "Sorry. You busted!" << endl;
                continue;
            }
        }
        // enter new wager
        cout << "Enter a wager (0 to exit):" << endl;
        do {
            cin >> wager;
            if ( wager > bankBalance)
                cout << "Wager must be less than or equal to your bank balance." << endl;
            else
            {
                // wager commentary
                if ( rand() % 5 == 0 )
                {
                    if ( wager > ( bankBalance / 2 ) )
                        cout << "Oh, you're going for broke, huh?" << endl;
                    else if ( wager < (bankBalance / 10 ) )
                        cout << "Aw cmon, take a chance!" << endl;
                }
            }
        } while ( wager > bankBalance );
    }

    cout << "You are leaving with $" << bankBalance << ". Come back soon!" << endl;
    
  return 0; // indicate successful termination
} // end main

// play one game all the way to WIN or LOSE outcome
Status oneGame(void)
{
    Status gameStatus;
    int myPoint;
    int sumOfDice = rollDice(); // first roll of the dice

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
           cout << "Point is " << myPoint << endl;
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
    } // end while

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
    cout << "Player rolled " << die1 << " + " << die2
         << " = " << sum << endl;
    return sum; // end function rollDice
} // end function rollDice