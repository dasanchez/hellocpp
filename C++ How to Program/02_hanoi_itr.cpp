#include <iostream>
using std::cout;
using std::cin;
using std::endl;

enum parity { ODD, EVEN };

int main()
{
    // The Towers of Hanoi by Iteration: Binary solution
    // Moving a stack of disks from peg 0 to peg 2 following two rules:
    // 1. Exactly one disk can me moved at a time
    // 2. A disk can only be placed on top of a larger one
    // From Wikipedia:
    // Source peg: ( m & (m-1) ) % 3 ,
    // Destintation peg: (( m | ( m - 1 ) ) + 1 ) % 3 ,
    // where 0 is the first peg and 1 and 2 are swapped if the total disk count is even.
    
    parity diskParity;
    int diskCount;
    unsigned long moveCount = 0;
 
    // Set number of disks to move
    cout << "Enter the number of disks on the starting peg: ";
    cin >> diskCount;
    
    // Set disk count parity
    diskParity = (diskCount % 2) ? ODD : EVEN;
    cout << "Disk count is ";
    if (diskParity == ODD) cout << "odd" << endl;
    else cout << "even" << endl;
    
    // Calculate total moves required
    for (int i = 0; i < diskCount ; i++)
    {
        moveCount |= (1 << i); // Shift a one to the left (add a disk to the stack)
    }
    cout << "Moves required: " << moveCount << endl;
    
    // Loop through each move
    for (unsigned long j = 1; j <= moveCount; j++)
    {
        unsigned src, dest;
        cout << "Move " << j << ": ";
        
        src = ( j & ( j - 1 ) ) % 3;

        dest = ( ( j | ( j - 1 ) ) + 1 ) % 3;

        if( diskParity == EVEN )
        {
            // Flip source
            if ( src == 1 ) src = 2;
            else if ( src == 2 ) src = 1;
            // Flip destination
            if ( dest == 1 ) dest = 2;
            else if ( dest == 2 ) dest = 1;
        }

        cout << src << " -> " << dest << endl;
    }

    return 0;
} // end main
