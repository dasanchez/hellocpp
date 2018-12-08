/*
 * 7.24 Knight's Tour
 * Chess question: Can the knight move around an empty chessboard and touch each of the 64 squares only one?
 * From a square in the middle of the board, the knight can make eight different moves.
 * The board is represented by an 8x8 two-dimensional array _board_. Each of the squares is initialized to zero.
 * We describe each of the eight possible moves in terms of their horizontal and vertical components:
 * a move of type 0 moves 2 to the right and one up ( horizontal[0] = 2 and vertical[0] = -1).
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int boardSide = 8;                    // standard chess board size
int board[boardSide][boardSide] = {};       // global variable for places visited
int moveH[] = {2, 1, -1, -2, -2, -1, 1, 2}; // horizontal component of move options
int moveV[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // vertical component of move options
int currentRow = 0;
int currentCol = 0;

bool moveIsValid(int move);             // check if the move will go off board and if the position has been visited
bool validMoves(bool moves[8]);         // update the array with the legal moves available
void resetMoves(bool moves[8]);         // set all array elements to zero
void resetBoard();                      // set all element arrays to zero
void printBoard();                      // print current board status
void moveKnight(int move, int counter); // perform the specified move and set the board position to the counter

int main()
{
    int moveCounter;
    bool availableMoves[8] = {};
    int maxMoves = 0;
    int maxMoveRow = 0;
    int maxMoveCol = 0;

    // Exploration: use the first move available until there are no moves left.
    // Iterate through all the available spots as starting places.
    for (int j = 0; j < 8; ++j)
    {
        for (int k = 0; k < 8; ++k)
        {
            moveCounter = 1;
            currentRow = j;
            currentCol = k;
            board[j][k] = moveCounter;
            
            while (validMoves(availableMoves)) // keep going until no more moves are left
            {
                for (int i = 0; i < 8; i++) // loop through the available moves
                {
                    if (availableMoves[i]) // use the first available move
                    {
                        moveKnight(i, ++moveCounter);
                        break;
                    }
                }
            }

            if (moveCounter > maxMoves)
            {
                maxMoves = moveCounter;
                maxMoveCol = k;
                maxMoveRow = j;
            }
            resetMoves(availableMoves);
            resetBoard();
        }
    }

    cout << "Maximum amount of moves (" << maxMoves << ") was first reached when starting at ("
         << maxMoveCol << "," << maxMoveRow << "):" << endl;

    // Run that position again to generate the board to print:
    moveCounter = 1;
    currentCol = maxMoveCol;
    currentRow = maxMoveRow;
    board[currentRow][currentCol] = 1;
    while (validMoves(availableMoves)) // keep going until no more moves are left
    {
        for (int i = 0; i < 8; i++) // loop through the available moves
        {
            if (availableMoves[i]) // use the first available move
            {
                moveKnight(i, ++moveCounter);
                break;
            }
        }
    }

    printBoard();

    return 0;
} // end main

void resetMoves(bool moves[8])
{
    for (int i = 0; i < 8; ++i)
    {
        moves[i] = 0;
    }
}

void resetBoard()
{
    for (int i = 0; i < boardSide; ++i)
    {
        for (int j = 0; j < boardSide; ++j)
        {
            board[i][j] = 0;
        }
    }
}

void moveKnight(int move, int counter)
{
    currentRow += moveV[move];
    currentCol += moveH[move];
    board[currentRow][currentCol] = counter;
}

// return array with the available moves from the current position
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
    for (int i = 0; i < boardSide; ++i)
    { // rows
        for (int j = 0; j < boardSide; ++j)
        { // columns
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}
