/*
 * Ex 8.12: Simulation: The Tortoise and the Hare
 * Contenders begin the race at "square 1" of 70 squares.
 * Each square represents a possible  position along the
 * race course. The finish line is at square 70.
 * There is a clock that ticks once per second. With each tick
 * of the clock, the program will use functions moveTortoise
 * and moveHare to adjust the position of the animals based
 * on the following rules:
 * 
 * Animal       Move type   Percentage of the time  Actual move
 * Tortoise     Fast plod   50%                     3 forward
 *              Slip        20%                     6 back
 *              Slow plod   30%                     1 forward
 * Hare         Sleep       20%                     No move
 *              Big hop     20%                     9 forward
 *              Big slip    10%                     12 back
 *              Small hop   30%                     1 forward
 *              Small slip  20%                     2 back
 * 
 * The functions should use pointer-based pass-by-reference to 
 * modify the position of the animals.
 * Use variables to keep track of the positions of the animals.
 * Start each animal at position 1 (the starting gate). If an animal
 * slips back before square 1, move the animal to square 1.
 * Generate the percentages in the table by producing a random integer
 * i in the range 1 <= i <= 10. For the tortoise, perform a "fast plod"
 * when 1 <= i <= 5, a "slip" when 6 <= i <= 7 or a "slow plod"
 * when 8 <= i <= 10. Use a similar technique to move the hare.
 * Begin the race by printing BANG!! AND THEY'RE OFF!
 * For each tick of the clock (each repetition of the loop), print a
 * 70-position line showing the letter T in the tortoise's position
 * and the letter H in the hare's position. When both animals land
 * on the same square, the tortoise bites the hare and the program
 * prints "OUCH!!!" beginning at that position. All print positions
 * other  ahtn the T, H, or OUCH should be blank.
 * After printing each line, test whether either animal has reached
 * or passed square 70. If so, print the winner and terminate the
 * simulation. If neither animal wins, perform the loop again
 * to simulate the next tick of the clock.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void moveHare(int *);
void moveTortoise(int *);
void printTrack(int *, int *, const int);

int main()
{
    int tortoisePos = 1;
    int harePos = 1;
    const int raceLength = 70;
    srand(time(0)); // initialize random seed
    
    cout << "BANG !!!!\nAND THEY'RE OFF!!!" << endl;
    while ( tortoisePos < raceLength && harePos < raceLength )
    {
        moveHare(&harePos);
        if (harePos > raceLength)
            harePos = raceLength;
        if (harePos < 1)
            harePos = 1;
        moveTortoise(&tortoisePos);
        if (tortoisePos > raceLength)
            tortoisePos = raceLength;
        if (tortoisePos < 1)
            tortoisePos = 1;
        printTrack(&harePos, &tortoisePos, raceLength);
    }

} // end main

void moveHare(int *position)
{
    int move = 0;
    int roll = 1 + rand() % 10;
    if (roll == 3 || roll == 4)
        move = 9; // big hop
    else if (roll == 5)
        move = -12; // big slip
    else if (roll > 5 && roll < 9)
        move = 1; // small hop
    else if (roll > 8)
        move = -2; // small slip

    *position = *position + move;
}

void moveTortoise(int *position)
{
    int move = 0;
    int roll = 1 + rand() % 11;
    if (roll <= 5)
        move = 3; // fast plod
    else if (roll > 5 && roll < 8)
        move = -6; // slip
    else
        move = 1; // slow plod

    *position = *position + move;
}

void printTrack(int *harePos, int *tortPos, const int raceLength)
{
    // print a track starting with S, then blank until
    // we reach an animal, and blank until the F for finish line
    bool collision = false;
    for (int i = 0; i < raceLength+1; ++i)
    {
        if (i == *harePos && i == *tortPos)
        {
            if ( i < raceLength )
            {
                collision = true;
                cout << "*";
            }
            else
                cout << "  IT'S A TIE!!!";
                
        }
        else if (i == *harePos)
        {
            cout << "H";
            if (i == raceLength)
                cout << "  HARE WINS!!!";
        }
        else if (i == *tortPos)
        {
            cout << 'T';
            if (i == raceLength)
                cout << "  TORTOISE WINS!!!";
        }
        else if (i==0)
        {
            cout << ">";
        }
        else
        {
            if (i < raceLength)
                cout << "-";
            else
                cout << "|";
        }
    }
    if (collision)
        cout << "  OUCH!!!";
    cout << endl;
}
