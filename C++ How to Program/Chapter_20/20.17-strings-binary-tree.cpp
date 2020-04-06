// Ex 20.17: Binary Tree of Strings
// Write a program based on Figs. 20.20-20.22 that inputs aline of text,
// tokenizes the sentence into separate words (you may want to use the
// istringstream library class), inserts the words in a binary search
// tree and prints the inorder, preorder, and postorder traversals
// of the tree. Use an OOP approach.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Tree.h"

using namespace std;

int main()
{
    string token, str("goodbye forever cruel world see you never again");
    istringstream iss(str);
    Tree<string> stringTree;

    // tokenize line and populate tree
    while (getline(iss, token, ' '))
    {
        stringTree.insertNode(token);
    }

    // print tree traversals
    stringTree.inOrderTraversal();
    cout << endl;
    stringTree.preOrderTraversal();
    cout << endl;
    stringTree.postOrderTraversal();
    cout << endl;
}
