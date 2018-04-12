/*
 * Airline Reservation System
 * Assign seats on each flight of the airline's only plane (10 seats).
 * Prompt a user to type 1 for First Class and 2 for Economy.
 * "Print" a boarding pass indicating the seat number and section.
 * Use a one-dimensional array to represent the seating chart if the airplane.
 * Never assign a seat that's already been assigned. Ask the person
 * if it's acceptable to be placed in the economy section (and vice versa).
 * If yes, make the appropriate seat assignment. If no, print
 * "Next flight leavs in 3 hours".
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int availableSeats = 10;
    bool seatArray [ availableSeats ] = { };
    int assignedSeats = 0;

    // start taking passengers
    while ( assignedSeats < availableSeats )
    {
        int requestedSeat;
        bool seatAssigned = false;
        cout << "Please type 1 for First Class or 2 for Economy Class: ";
        cin >> requestedSeat;
        if ( requestedSeat == 1 )
        {
            // try first class
            for ( int i = 0 ; i < 5 ; ++i ) // loop until an available seat is found
            {
                if ( !seatArray[i] ) // seat is available
                {
                    seatArray[ i ] = true;
                    assignedSeats++;
                    seatAssigned = true;
                    cout << "Seat " << i + 1 << ", First Class" << endl;
                    break;
                }
            }
            if ( !seatAssigned ) // a seat hasn't been found
            {
                // ask if Economy is OK
                char economy;
                cout << "First class is full, would you like to fly Economy?"
                    << " Enter y or n: ";
                cin >> economy;
                if ( economy == 'y' )
                {
                    for ( int j = 5; j < availableSeats; j++ )
                    {
                        if ( !seatArray[j] ) // seat is available
                        {
                            seatArray[ j ] = true;
                            assignedSeats++;
                            seatAssigned = true;
                            cout << "Seat " << j + 1 << ", Economy Class" << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "The next flight leaves in three hours." << endl;
                }
            }
        }
        else if ( requestedSeat == 2)
        {
            // try economy class
            for ( int i = 5 ; i < availableSeats ; ++i ) // loop until an available seat is found
            {
                if ( !seatArray[i] ) // seat is available
                {
                    seatArray[ i ] = true;
                    assignedSeats++;
                    seatAssigned = true;
                    cout << "Seat " << i + 1 << ", Economy Class" << endl;
                    break;
                }
            }
            if ( !seatAssigned ) // a seat hasn't been found
            {
                // ask if First is OK
                char first;
                cout << "Economy Class is full, would you like to fly First?"
                    << " Enter y or n: ";
                cin >> first;
                if ( first == 'y' )
                {
                    for ( int j = 0; j < 5; j++ )
                    {
                        if ( !seatArray[j] ) // seat is available
                        {
                            seatArray[ j ] = true;
                            assignedSeats++;
                            seatAssigned = true;
                            cout << "Seat " << j + 1 << ", First Class" << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "The next flight leaves in three hours." << endl;
                }
            }
        }        
    }    
    
    cout << "All seats have been assigned." << endl;

    return 0;
} // end main
