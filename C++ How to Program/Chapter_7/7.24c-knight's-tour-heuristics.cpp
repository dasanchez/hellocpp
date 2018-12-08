/*
 * 7.24: Knight's Tour with Heuristics
 * The outer squares are more troublesome than the ones nearer the centre of the board.
 * Our "accessibility heuristic" involves classifying each square according to how accessible it 
 * is, then always moving the knight to the square that is most inaccessible.
 * Label a 2D array _accessibility_ with numbers indicating from how many squares each particular
 * square is accessible.
 * Write a version of the Knight's Tour using the accesibility heuristic. In case of a tie,
 * the knight may move to any of the tied squares.
 * As the knight moves around the chessboard, the progam should reduce the accessibility numbers
 * as more and more squares become occupied.  
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int boardSide = 8;                    // standard chess board size
int board[boardSide][boardSide] = {};       // global variable for places visited
const int moveH[] = {2, 1, -1, -2, -2, -1, 1, 2}; // horizontal component of move options
const int moveV[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // vertical component of move options
int accesibility[boardSide][boardSide] = {{2, 3, 4, 4, 4, 4, 3, 2},
                                          {3, 4, 6, 6, 6, 6, 4, 3},
                                          {4, 6, 8, 8, 8, 8, 6, 4},
                                          {4, 6, 8, 8, 8, 8, 6, 4},
                                          {4, 6, 8, 8, 8, 8, 6, 4},
                                          {4, 6, 8, 8, 8, 8, 6, 4},
                                          {3, 4, 6, 6, 6, 6, 4, 3},
                                          {2, 3, 4, 4, 4, 4, 3, 2}}; // accessibility array
int currentRow = 0;
int currentCol = 0;

bool moveIsValid(int move);                          // check if the move will go off board and if the position has been visited
bool validMoves(bool moves[8]);                      // update the array with the legal moves available
void printBoard();                                   // print current board status
void moveKnight(int move, int counter);              // perform the specified move and set the board position to the counter
int rateAccessibility(bool moves[8], int firstMove); // returns the move with the lowest accessibility rating
void adjustAccessibility();                          // modify ratings based on new knight position
void printAccessibility();

int main()
{
    int moveCounter = 1;
    bool availableMoves[8] = {};

    cout << "Enter the starting column and row (0-7): ";
    cin >> currentCol >> currentRow;

    // Set up
    board[currentRow][currentCol] = moveCounter;
    adjustAccessibility();

    cout << "Starting the tour at position " << currentCol << "," << currentRow << ":" << endl;

    while (validMoves(availableMoves)) // keep going until no more moves are left
    {
        for (int i = 0; i < 8; ++i)
        {
            if (availableMoves[i]) // use the first available move
            {
                int nextMove = rateAccessibility(availableMoves, i);
                moveKnight(nextMove, ++moveCounter);
                adjustAccessibility();
                break;
            }
        }
    }

    // Display results
    cout << "Total number of moves: " << moveCounter << endl;
    printBoard();
    cout << endl;
    printAccessibility();
    cout << endl;

    return 0;
} // end main

// returns the move with the lowest accessiblity rating
int rateAccessibility(bool moves[8], int firstMove)
{
    int lowestMove = firstMove;
    int minRating = 8;
    for (int i = firstMove; i < 8; ++i)
    {
        if (moves[i]) // move is available
        {
            int rating = accesibility[currentRow + moveV[i]][currentCol + moveH[i]];
            if (rating < minRating)
            {
                lowestMove = i;
                minRating = rating;
            }
        }
    }
    return lowestMove;
}

// perform the specified move and set the board position to the counter
void moveKnight(int move, int counter)
{
    currentRow += moveV[move];
    currentCol += moveH[move];
    board[currentRow][currentCol] = counter;
}

// modify ratings based on new knight position
void adjustAccessibility()
{
    // iterate through all 8 moves:
    for (int i = 0; i < 8; ++i)
    {
        int potentialRow = currentRow + moveV[i];
        int potentialCol = currentCol + moveH[i];
        if ((potentialRow >= boardSide) || (potentialRow < 0))
            continue;
        if ((potentialCol >= boardSide) || (potentialCol < 0))
            continue;

        accesibility[potentialRow][potentialCol] = accesibility[potentialRow][potentialCol] - 1;
    }
}

// return array with the available moves from the current position and whether we should keep going
bool validMoves(bool moves[8])
{
    bool keepGoing = false;
    for (int i = 0; i < 8; ++i)
    {
        // iterate throuch each move
        if (moveIsValid(i))
        {
            moves[i] = true;
            keepGoing = true;
        }
        else
        {
            moves[i] = false;
        }
    }
    return keepGoing;
}

// return true if move can be made, false otherwise
bool moveIsValid(int move)
{
    int potentialRow = currentRow + moveV[move];
    int potentialCol = currentCol + moveH[move];
    // check if the current move will go off the board:
    if ((potentialRow >= boardSide) || (potentialRow < 0))
    {
        return false;
    }
    if ((potentialCol >= boardSide) || (potentialCol < 0))
    {
        return false;
    }

    // check if the knight has visited that square:
    if (board[potentialRow][potentialCol] != 0)
        return false;
    return true;
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

void printAccessibility()
{
    cout << "== Accessibility array ==" << endl;
    for (int i = 0; i < boardSide; ++i)
    { // rows
        for (int j = 0; j < boardSide; ++j)
        { // columns
            cout << setw(3) << accesibility[i][j];
        }
        cout << endl;
    }
}