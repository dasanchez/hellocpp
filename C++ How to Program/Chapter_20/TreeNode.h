// Fig 20.20: TreeNode.h
// Template TreeNode class definition.
#ifndef TREENODE_H
#define TREENODE_H

// forward devlaration of class Tree
template <typename NODETYPE>
class Tree;

// TreeNode class-template definition
template <typename NODETYPE>
class TreeNode
{
    friend class Tree<NODETYPE>;

public:
    // constructor
    TreeNode(const NODETYPE &d)
        : leftPtr(0),  // pointer to left  subtree
          data(d),     // tree node data
          rightPtr(0), // pointer to right subtree
          counter(0)
    {
        // empty body
    } // end TreeNode constructor

    // return copy of node's data
    NODETYPE getData() const
    {
        return data;
    } // end getData function
private:
    TreeNode<NODETYPE> *leftPtr; // pointer to left subtree
    NODETYPE data;
    TreeNode<NODETYPE> *rightPtr; // pointer to right subtree
    unsigned int counter;
}; // end class TreeNode

#endif