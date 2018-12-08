// 7.34: Eight queens by recursion
// Modify the Eight queens program from 7.26
// to solve the problem recursively:
// Can we place eight queens on a chess board
// in a way that none of them is attacking another one?

#include <iostream>
#include <iomanip>
using namespace std;

const int boardSize = 8;
bool queens(int[], int);    // check each element of the column looking for a valid spot
bool validSpot(int[], int); // check whether the spot is valid
void printBoard(int[]);
void clearScreen();

int main()
{
    int queensBoard[boardSize] = {0};

    // initialize board with -1
    for (int i = 0; i < boardSize; ++i)
    {
        queensBoard[i] = -1;
    }
 
    if (queens(queensBoard, 0))
    {
        cout << "Solution found:" << endl;
        printBoard(queensBoard);
    }
    else
        cout << "Solution was not found." << endl;
}

bool queens(int board[], int col)
{
    if (col == boardSize)
        return true;
    else
    {
        // go through all the rows of the column until a valid spot is found
        for (int row = 0; row < boardSize; ++row)
        {
            board[col] = row;
            if (validSpot(board, col))
            {
                // look at the next column
                if (queens(board, col + 1))
                    return true;
            }
        }
        // if no valid spots are found, return false
        return false;
    }
}

bool validSpot(int board[], int col)
{
    // check if the spot at _row_ is valid
    for (int column = 0; column < col; ++column)
    {
        // check for horizontal conflict:
        if (board[column] == board[col])
        {
            return false;
        }
        // check for upper diagonal conflict:
        if (board[column] == board[col] - (col - column))
        {
            return false;
        }
        // check for lower diagonal conflict:
        if (board[column] == board[col] + (col - column))
        {
            return false;
        }
    }
    return true;
}

void printBoard(int board[])
{
    // iterate through rows:
    for (int row = 0; row < boardSize; ++row)
    {
        // iterate through columns:
        for (int column = 0; column < boardSize; ++column)
        {
            if (row == board[column])
            {
                cout << "|Q";
            }
            else
            {
                cout << "| ";
            }
        }
        cout << "|" << endl;
    }
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}
