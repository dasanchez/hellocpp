// Ex 20.16: Allowing Duplicates in a Binary Trees
// Modify the program from Figs 20.20-20.22 to allow the binary tree object to contain duplicates.

#include <iostream>
#include <string>
#include <ctype.h>
#include <random>
#include <ctime>
#include "Tree.h"

int main()
{
    Tree<int> intTree;

    srand(time(0));

    for (int i = 0; i < 50; ++i)
    {
        intTree.insertNode(rand() % 10);
    }
    cout << "\nInorder traversal:\n";
    intTree.inOrderTraversal();
    cout << endl;
}
