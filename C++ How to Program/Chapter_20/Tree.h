// Fig 20.21: Tree.h
// Template Tree class definition.
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

// Tree class-template definition
template <typename NODETYPE>
class Tree
{
public:
    Tree(); // constructor
    void insertNode(const NODETYPE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    static int treeDepth(Tree<NODETYPE>);

private:
    TreeNode<NODETYPE> *rootPtr;

    // utility functions
    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
    void preOrderHelper(TreeNode<NODETYPE> *) const;
    void inOrderHelper(TreeNode<NODETYPE> *) const;
    void postOrderHelper(TreeNode<NODETYPE> *) const;
    int depthHelper(TreeNode<NODETYPE> *) const;
}; // end class Tree

// constructor
template <typename NODETYPE>
Tree<NODETYPE>::Tree()
{
    rootPtr = 0; // indicate tree is initially empty
} // end Tree constructor

template <typename NODETYPE>
int Tree<NODETYPE>::treeDepth(Tree<NODETYPE> tree)
{
    if (tree.rootPtr != 0)
        return tree.depthHelper(tree.rootPtr);
    return 0;
}

template <typename NODETYPE>
int Tree<NODETYPE>::depthHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0)
        return 1 + max(depthHelper(ptr->leftPtr), depthHelper(ptr->rightPtr));
    return 0;
}

// insert node in Tree
template <typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value)
{
    insertNodeHelper(&rootPtr, value);
} // end function insertNode

// utility function called by insertNode; receives a pointer
// to a pointer so that the function can modify pointer's value
template <typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(
    TreeNode<NODETYPE> **ptr, const NODETYPE &value)
{
    // subtree is  empty; create new TreeNode containing value
    if (*ptr == 0)
    {
        *ptr = new TreeNode<NODETYPE>(value);
        (*ptr)->counter++;
    }
    else // subtree is not empty
    {
        // data to insert is less than data in current node
        if (value < (*ptr)->data)
            insertNodeHelper(&((*ptr)->leftPtr), value);
        else
        {
            // data to insert is greater than data in current node
            if (value > (*ptr)->data)
                insertNodeHelper(&((*ptr)->rightPtr), value);
            else // duplicate data value increases counter
            {
                cout << value << " dup" << endl;
                (*ptr)->counter++;
            }
        } // end else
    }     // end else
} // end function insertNodeHelper

// begin preorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const
{
    preOrderHelper(rootPtr);
} // end function preOrderTraversal

// utility function to perform preorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0)
    {
        cout << ptr->data << '(' << ptr->counter << ')' << ' '; // process node
        preOrderHelper(ptr->leftPtr);                           // traverse left subtree
        preOrderHelper(ptr->rightPtr);                          // traverse right subtree
    }                                                           // end if
} // end function preOrderHelper

// begin inorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const
{
    inOrderHelper(rootPtr);
} // end fucntion inOrderTraversal

// utility function to perform inorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0)
    {
        inOrderHelper(ptr->leftPtr);                            // traverse left subtree
        cout << ptr->data << '(' << ptr->counter << ')' << ' '; // process node
        inOrderHelper(ptr->rightPtr);                           // traverse right subtree
    }                                                           // end if
} // end function inOrderHelper

// begin postorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversal() const
{
    postOrderHelper(rootPtr);
} // end function postOrderTraversal

// utility function to perform postorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(
    TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0)
    {
        postOrderHelper(ptr->leftPtr);                          // traverse left subtree
        postOrderHelper(ptr->rightPtr);                         // traverse right subtree
        cout << ptr->data << '(' << ptr->counter << ')' << ' '; // process node
    }                                                           // end if
} // end functipn postOrderHelper

#endif