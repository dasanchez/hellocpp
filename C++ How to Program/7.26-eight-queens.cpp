/*
 * 7.26: Eight Queens
 * Is it possible to place eight queens on an empty chessboard so that no queen
 * is "attacking" any other?
 * It's possible to assign a value to each square of the chessboard indicating how many
 * squares of an empty chessboard are "eliminated" if a queen is placed in that square.
 * An appropriate heuristic would then be: Place the next queen in the square with the
 * smallest elimination number.  
 * Answer: Yes, it is possible. The current algorithm doesn't find a solution for every single
 * starting position, but it works when starting at (0, 0).
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int boardSide = 8;                    // standard chess board size
int board[boardSide][boardSide] = {};       // global variable for places visited
int moveH[] = {0, 1, 1, 1, 0, -1, -1, -1};  // horizontal component of move options
int moveV[] = {-1, -1, 0, 1, 1, 1, 0, -1};  // vertical component of move options
int elimination[boardSide][boardSide] = {}; // elimination array

void printBoard();                              // print current board status
void placeQueen(int row, int col, int counter); // perform the specified move and set the board position to the counter
bool nextMove(int &row, int &col);
void generateElimination();
void printElimination();

int main()
{
    int queenCounter = 1;
    int nextRow, nextCol;

    // generate elimination array
    generateElimination();
    printElimination();

    cout << "Enter the starting column and row (0-7): ";
    cin >> nextCol >> nextRow;

    // start placing queens around the board:
    placeQueen(nextRow, nextCol, queenCounter);
    printBoard();
    generateElimination();
    // printElimination();

    while (nextMove(nextRow, nextCol))
    {
        queenCounter++;
        placeQueen(nextRow, nextCol, queenCounter);
        printBoard();
        generateElimination();
        // printElimination();
    }

    cout << "Placed " << queenCounter << " queens on the board." << endl;

    return 0;
} // end main

bool nextMove(int &row, int &col)
{
    int minRating = 30;
    bool moveAvailable = false;
    // loop through the whole board
    // if a spot is available, check the rating
    // if the rating is lower, mark it
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            if (board[i][j] == 0)
            {
                if (!moveAvailable)
                {
                    moveAvailable = true;
                    row = i;
                    col = j;
                }
                // spot is available
                if (elimination[i][j] < minRating)
                {
                    minRating = elimination[i][j];
                    row = i;
                    col = j;
                }
            }
        }
    }
    return moveAvailable;
}

void generateElimination()
{
    // step through each spot in the first quadrant:
    for (int row = 0; row <= 3; ++row)
    {
        for (int col = 0; col <= 3; ++col) // columns
        {
            elimination[row][col] = 0;
            // check each move and multiply it by multiplier, until we go off bounds
            if (board[row][col] == 0)
            {
                elimination[row][col]++;
            }
            for (int move = 0; move <= 7; ++move) // iterate through each direction the queen can move in
            {
                int multiplier = 1;
                while (true)
                {
                    int potentialRow = row + moveV[move] * multiplier;
                    int potentialCol = col + moveH[move] * multiplier;
                    if (potentialRow < 0 || potentialRow > 7)
                    {
                        break;
                    }
                    if (potentialCol < 0 || potentialCol > 7)
                    {
                        break;
                    }
                    else
                    {
                        multiplier++;
                        if (board[potentialRow][potentialCol] == 0)
                        {
                            elimination[row][col]++;
                        }
                    }
                }
            }
        }
    }

    // mirror first quadrant to other 3:
    for (int row = 0; row <= 3; ++row)
    {
        for (int col = 0; col <= 3; ++col)
        {
            elimination[row][7 - col] = elimination[row][col];
        }
    }

    for (int row = 0; row <= 3; ++row)
    {
        for (int col = 0; col <= 7; ++col)
        {
            elimination[7 - row][col] = elimination[row][col];
        }
    }
}

void placeQueen(int row, int col, int counter)
{
    // place queen at the specified coordinates and populate open places
    board[row][col] = counter;

    for (int move = 0; move <= 7; ++move) // iterate through each direction the queen can move in
    {
        int multiplier = 1;
        while (true)
        {
            int potentialRow = row + moveV[move] * multiplier;
            int potentialCol = col + moveH[move] * multiplier;
            if (potentialRow < 0 || potentialRow > 7)
            {
                break;
            }
            if (potentialCol < 0 || potentialCol > 7)
            {
                break;
            }
            else
            {
                multiplier++;
                if (board[potentialRow][potentialCol] == 0)
                    board[potentialRow][potentialCol] = counter;
            }
        }
    }
}

void printBoard()
{
    cout << "====== Game board ======" << endl;
    for (int i = 0; i < boardSide; ++i)
    { // rows
        for (int j = 0; j < boardSide; ++j)
        { // columns
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}

void printElimination()
{
    cout << "== Elimination array ==" << endl;
    for (int i = 0; i < boardSide; ++i)
    { // rows
        for (int j = 0; j < boardSide; ++j)
        { // columns
            cout << setw(3) << elimination[i][j];
        }
        cout << endl;
    }
}