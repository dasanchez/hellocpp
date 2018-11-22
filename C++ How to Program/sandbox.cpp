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

class Player
{
  public:
    // constructor
    Player(int startRow, int startCol, int startDir)
    {
        row = startRow;
        col = startCol;
        direction = startDir;
    }

    int getRow()
    {
        return row;
    };

    int getCol()
    {
        return col;
    };

    int getDirection()
    {
        return direction;
    };

    void rotate(bool cw)
    {
        if (cw) // clockwise
        {
            if (direction == 3)
            {
                direction = 0;
            }
            else
                direction++;
        }
        else
        {
            if (direction == 0)
            {
                direction = 3;
            }
            else
                direction--;
        }
    };

    void advance()
    {
        // move in the direction specified
        switch (direction)
        {
        case 0: // up
            row--;
            break;
        case 1: // right
            col++;
            break;
        case 2: // down
            row++;
            break;
        case 3: // left
            col--;
            break;
        default:
            break;
        }
    };

  private:
    int row;
    int col;
    int direction; // 0: up, 1: right, 2: down, 3: left
};

const int rows = 12;
const int cols = 12;
void printMaze(const bool maze[rows][cols], const int, const int, const int);
int moveOptions(const bool maze[rows][cols], Player);

int main()
{

    const bool maze[rows][cols] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
        1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1,
        0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Player player(2, 0, 1);

    printMaze(maze, player.getRow(), player.getCol(), player.getDirection());

    while (true)
    {
        switch (moveOptions(maze, player))
        {
        case 1: // go forward
            player.advance();
            break;
        case 2: // turn right and advance
            player.rotate(true);
            player.advance();
            break;
        case 3: // turn left and advance
            player.rotate(false);
            player.advance();
            break;
        case 0: // turn around
            player.rotate(true);
            player.rotate(true);
            break;
        }
        printMaze(maze, player.getRow(), player.getCol(), player.getDirection());

        if (player.getRow() == 0 || player.getRow() == 11 || player.getCol() == 0 || player.getCol() == 11)
        {
            cout << "Maze cleared!" << endl;
            break;
        }
    }
}

int moveOptions(const bool maze[rows][cols], Player player)
{
    // returns:
    // 0 if there is no way forward or sideways
    // 1 if we can go forward
    // 2 if we can go right
    // 3 if we can go left
    switch (player.getDirection())
    {
    case 0: // facing up
        if (maze[player.getRow()][player.getCol() + 1])
            return 2; // turn right
        else if (maze[player.getRow() - 1][player.getCol()])
            return 1; // go forward
        else if (maze[player.getRow()][player.getCol() - 1])
            return 3; // turn left
        break;
    case 1: // facing right
        if (maze[player.getRow() + 1][player.getCol()])
            return 2; // turn right
        else if (maze[player.getRow()][player.getCol() + 1])
            return 1; // go forward
        else if (maze[player.getRow() - 1][player.getCol()])
            return 3; // turn left
        break;
    case 2: // facing down
        if (maze[player.getRow()][player.getCol() - 1])
            return 2; // turn right
        else if (maze[player.getRow() + 1][player.getCol()])
            return 1; // go forward
        else if (maze[player.getRow()][player.getCol() + 1])
            return 3; // turn left
        break;
    case 3: // left
        if (maze[player.getRow() - 1][player.getCol()])
            return 2; // turn right
        else if (maze[player.getRow()][player.getCol() - 1])
            return 1; // go forward
        else if (maze[player.getRow() + 1][player.getCol()])
            return 3; // turn left
        break;
    default:
        break;
    }
    return 0;
}

void printMaze(const bool maze[rows][cols], const int playerRow, const int playerCol, const int playerDir)
{
    cout << "=======================" << endl;

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (row == playerRow && col == playerCol)
            {
                switch (playerDir)
                {
                case 0:
                    cout << "^ ";
                    break;
                case 1:
                    cout << "> ";
                    break;
                case 2:
                    cout << "v ";
                    break;
                case 3:
                    cout << "< ";
                    break;
                default:
                    break;
                }
            }
            else if (maze[row][col] == 0)
            {
                cout << "# ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}
