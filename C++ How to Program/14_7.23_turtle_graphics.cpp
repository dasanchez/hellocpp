/*
 * Turtle Graphics
 * Imagine a turtle that walks around the room under the control of a program.
 * The turtle holds a pen in one of two positions, up or down. When the pen
 * is down the turtle traces out shapes as it moves.
 * Use a 20x20 array "floor" that is initialized to false.
 * Read commands from an array that contains them. Keep track of the current
 * position of the turtle at all times and whether the pen is currently up or
 * down. Assume the turtle always starts at (0, 0) of the floor with its pen up.
 * The turtle must process the following commands:
 * Command     Meaning
 * 1            Pen up
 * 2            Pen down
 * 3            Turn right
 * 4            Turn left
 * 5,10         Move forward 10 spaces (or a number other than 10)
 * 6            Print the 20x20 array
 * 9            End of data (sentinel)
 */

#include <iostream>

using namespace std;

const int gridSide = 20;
void processCommand(int cmd, bool floor[gridSide][gridSide]);
void printFloor(bool floor[gridSide][gridSide]);

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

int main()
{
    // the "5,x" command is hard to parse with the material covered so far,
    // i will do 5 followed by the number of units to move instead
    const int commandArray[] = {5, 10, 4, 5, 5, 4, 2, 5, 8, 3, 3, 5, 4, 4, 5, 5, 4, 5, 4, 3, 3, 5, 7, // H
    1, 5, 1, 4, 5, 2, 4, 2, 5, 8, // I
    6, 9,};

    // drawing canvas
    bool floor[gridSide][gridSide] = {};

    // read array and process commands
    int index = 0;

    // read full array
    while (commandArray[index] != 9)
    {
        processCommand(commandArray[index], floor);
        index++;
    }

    return 0;
} // end main

void processCommand(int cmd, bool floor[][gridSide])
{
    static bool drawing = false;
    static Direction direction = DOWN;
    static int row = 0;
    static int col = 0;
    static bool move = false;

    if (move) // if the last command was a 5
    {
        cout << "Moving " << cmd << " units, direction: " << direction << endl;
        switch ( direction )
        {
            case UP: // decrease row
                for ( int i = cmd; i > 0; --i)
                {
                    row--;
                    if ( row < 0 )
                    {
                        row = 0;
                        break;
                    }
                    if ( drawing ) floor[ row ][ col ] = true;
                }
                break;
            case RIGHT: // increase col
                for ( int i = cmd; i > 0; --i )
                {
                    col++;
                    if ( col > gridSide-1 )
                    {
                        col = gridSide-1;
                        break;
                    }
                    if ( drawing ) floor[ row ][ col ] = true;
                }
                break;
            case DOWN: // increase row
                for ( int i = cmd; i > 0; i-- )
                {
                    row++;
                    if ( row > gridSide - 1 )
                    {
                        row = gridSide - 1;
                        break;
                    }
                    if ( drawing ) floor[ row ][ col ] = true;
                }
                break;
            case LEFT: // decrease col
                for ( int i = cmd; i > 0; --i )
                {
                    col--;
                    if ( col < 0 )
                    {
                        col = 0;
                        break;
                    }
                    if ( drawing ) floor[ row ][ col ] = true;
                }
                break;
            default:
                break;
        }
        move = false;
    }
    else
    {
        switch (cmd)
        {
        case 1:
        case 2:
            drawing = !drawing;
            cout << (drawing ? "Pen down" : "Pen up") << endl;
            break;
        case 3:
            switch (direction)
            {
            case UP:
                direction = RIGHT;
                break;
            case RIGHT:
                direction = DOWN;
                break;
            case DOWN:
                direction = LEFT;
                break;
            case LEFT:
                direction = UP;
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (direction)
            {
            case UP:
                direction = LEFT;
                break;
            case LEFT:
                direction = DOWN;
                break;
            case DOWN:
                direction = RIGHT;
                break;
            case RIGHT:
                direction = UP;
                break;
            default:
                break;
            }
            break;
        case 5:
            move = true;
            break;
        case 6:
            printFloor(floor);
            break;
        default:
            break;
        } // end switch
    }
}

void printFloor(bool floor[][gridSide])
{
    cout << "Printing floor:" << endl;
    for ( int i = 0; i < gridSide; ++i)
    {   // rows
        for ( int j = 0; j < gridSide; ++j)
        {
            if ( floor[ i ][ j ] )
                cout << "O";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}