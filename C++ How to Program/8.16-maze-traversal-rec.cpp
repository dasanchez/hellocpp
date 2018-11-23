/*
 * Ex. 8.16: Maze Traversal
 * The grid of hashes and dots is a two-dimensional array
 * representation of a mze. The hashes are the walls and the
 * dots are squares in the possible paths through the maze. 
 * Use the following algorithm: Place your right hand on the wall
 * to your right and begin walking forward. Never remove your hand
 * from the wall. If the maze turns to the right, you follow
 * the wall to the right. As long as you do not remove your
 * hand from the wall, eventually you'll arrive at the exit
 * of the maze.
 * Write recursive function mazeTraverse to walk through the maze.
 * # # # # # # # # # # # #
 * # . . . # . . . . . . #
 * . . # . # . # # # # . # 
 * # # # . # . . . . # . #
 * # . . . . # # # . # . .
 * # # # # . # . # . # . #
 * # . . # . # . # . # . #
 * # # . # . # . # . # . #
 * # . . . . . . . . # . # 
 * # # # # # # . # # # . #
 * # . . . . . . # . . . #
 * # # # # # # # # # # # # 
*/

#include <iostream>
using namespace std;

const int rows = 12;
const int cols = 12;
void printMaze(const char maze[rows][cols], int, int);
int moveOptions(const char maze[rows][cols], const int, const int, const int);
void mazeTraverse(const char maze[rows][cols], int *, int *, int *);
void oneMove(const char maze[rows][cols], int *, int *, int *);
void advance(int *, int *, int *);
void rotate(int *, bool);

int main()
{
    int posY = 2; // row
    int posX = 0; // column
    int direction = 1;

    char charMaze[rows][cols] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
        '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
        '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
        '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
        '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
        '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
        '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
        '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
        '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
        '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};

    printMaze(charMaze, posY, posX);
    mazeTraverse(charMaze, &posY, &posX, &direction);
    printMaze(charMaze, posY, posX);
}

void mazeTraverse(const char maze[rows][cols], int *row, int *col, int *dir)
{
    oneMove(maze, row, col, dir);
    printMaze(maze, *row, *col);
    if (*row == 0 || *row == rows-1 || *col ==0 || *col == cols-1)
    {
        return;
    }
    else
        mazeTraverse(maze, row, col, dir);
}

void oneMove(const char maze[rows][cols], int *row, int *col, int *dir)
{
    switch (moveOptions(maze, *row, *col, *dir))
    {
    case 1: // go forward
        advance(row, col, dir);
        break;
    case 2: // turn right and advance
        rotate(dir, true);
        advance(row, col, dir);
        break;
    case 3: // turn left and advance
        rotate(dir, false);
        advance(row, col, dir);
        break;
    case 0: // turn around
        rotate(dir, true);
        rotate(dir, true);
        break;
    }
}

void advance(int *row, int *col, int *dir)
{
    switch (*dir)
    {
    case 0: // up
        (*row)--;
        break;
    case 1: // right
        (*col)++;
        break;
    case 2: // down
        (*row)++;
        break;
    case 3: // left
        (*col)--;
        break;
    default:
        break;
    }
}

void rotate(int *direction, bool cw)
{
    if (cw) // clockwise
    {
        if (*direction == 3)
        {
            *direction = 0;
        }
        else
            (*direction)++;
    }
    else
    {
        if (*direction == 0)
        {
            *direction = 3;
        }
        else
            (*direction)--;
    }
}

int moveOptions(const char maze[rows][cols], const int row, const int col, const int dir)
{
    // returns:
    // 0 if there is no way forward or sideways
    // 1 if we can go forward
    // 2 if we can go right
    // 3 if we can go left
    switch (dir)
    {
    case 0: // facing up
        if (maze[row][col + 1]=='.')
            return 2; // turn right
        else if (maze[row - 1][col]=='.')
            return 1; // go forward
        else if (maze[row][col - 1]=='.')
            return 3; // turn left
        break;
    case 1: // facing right
        if (maze[row + 1][col]=='.')
            return 2; // turn right
        else if (maze[row][col + 1]=='.')
            return 1; // go forward
        else if (maze[row - 1][col]=='.')
            return 3; // turn left
        break;
    case 2: // facing down
        if (maze[row][col - 1]=='.')
            return 2; // turn right
        else if (maze[row + 1][col]=='.')
            return 1; // go forward
        else if (maze[row][col + 1]=='.')
            return 3; // turn left
        break;
    case 3: // left
        if (maze[row - 1][col]=='.')
            return 2; // turn right
        else if (maze[row][col - 1]=='.')
            return 1; // go forward
        else if (maze[row + 1][col]=='.')
            return 3; // turn left
        break;
    default:
        break;
    }
    return 0;
}

void printMaze(const char maze[rows][cols], int playerRow, int playerCol)
{
    cout << "=======================" << endl;

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (row == playerRow && col == playerCol)
            {
                cout << "X ";
            }
            else
            {
                cout << maze[row][col] << ' ';
            }
        }
        cout << endl;
    }
}
