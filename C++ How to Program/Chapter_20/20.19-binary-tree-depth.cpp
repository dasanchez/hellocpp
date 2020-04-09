// Ex 20.19: Depth of a Binary Tree
// Write a function depth that receives a binary tree and determmines how many
// levels it has.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Tree.h"

using std::cout;

int main()
{
    vector numbers{5, 2, 7, 1, 3, 6, 8, 4, 9, 0};
    vector numbers2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree<int> numberTree, numberTree2;

    for (int i : numbers)
        numberTree.insertNode(i);
    for (int i : numbers2)
        numberTree2.insertNode(i);

    cout << "Binary tree 1 depth: " << Tree<int>::treeDepth(numberTree) << endl;
    cout << "Binary tree 2 depth: " << Tree<int>::treeDepth(numberTree2) << endl;

}
