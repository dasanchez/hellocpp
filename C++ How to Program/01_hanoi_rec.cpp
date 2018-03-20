#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void hanoi( int disksToMove, int sourcePeg, int destPeg, int tempPeg );

unsigned long moveCount;

int main()
{
    // The Towers of Hanoi by Recursion
    // Moving disks from peg 1 to peg 3
    // Exactly one disk can me moved at a time
    // A disk can only be placed on top of a larger one
    // Develop an algorithm that prints the precise sequence of peg-to-peg disk transfers.
    // Moving n disks can be viewed in terms of moving only n-1 disks:
    // a.   Move n - 1 disks from peg 1 to peg 2, using peg 3 as a temporary holding area.
    // b.   Move the last disk (the largest) from peg 1 to peg 3.
    // c.   Move the n-1 disks from peg 2 to peg 3, using peg 1 as a temporary holding area.
    int pegCount;
    
    cout << "Enter the number of disks on the starting peg: ";
    cin >> pegCount;

    moveCount = 0;
    hanoi( pegCount, 0, 2, 1);
    
    cout << moveCount << " moves were required" << endl;

    return 0; // indicate successful termination
} // end main

void hanoi( int disksToMove, int sourcePeg, int destPeg, int tempPeg )
{
    if ( disksToMove == 1 )
    {
        moveCount++;
        cout << "Move " << moveCount << ": ";
        cout << sourcePeg << " -> " << destPeg << endl;
    }

    else
    {
        // Step 1: Move n-1 to the "in-between"
        hanoi( disksToMove - 1, sourcePeg, tempPeg, destPeg);
        
        // Step 2: Move n to the destination peg
        moveCount++;
        cout << "Move " << moveCount << ": ";
        cout << sourcePeg << " -> " << destPeg << endl;

        // Step 3: Move n-1 to the destination peg
        hanoi( disksToMove - 1, tempPeg, destPeg, sourcePeg);
    }

    return;
}