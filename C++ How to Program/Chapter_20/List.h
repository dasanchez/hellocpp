// Fig 20.4: List.h
// Template List class definition
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h" // ListNode class definition
using namespace std;

template <typename NODETYPE>
class List
{
public:
    List();  // constructor
    ~List(); // destructor
    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(NODETYPE &);
    bool removeFromBack(NODETYPE &);
    bool isEmpty() const;
    void print() const;
    void printBackward() const;
    void printBackwardHelper(const ListNode<NODETYPE> *) const;
    const ListNode<NODETYPE> * searchList(const NODETYPE &) const;
    const ListNode<NODETYPE> * searchListHelper(const NODETYPE &, const ListNode<NODETYPE> *) const;
    void clear();
    size_t getSize() const;
    static void concatenate(List<NODETYPE> &, List<NODETYPE> &);
    static void merge(List<NODETYPE> &, List<NODETYPE> &, List<NODETYPE> &);
    NODETYPE at(int) const;

private:
    ListNode<NODETYPE> *firstPtr; // pointer to first node
    ListNode<NODETYPE> *lastPtr;  // pointer to last node
    unsigned int size;

    // utility function to allocate new node
    ListNode<NODETYPE> *getNewNode(const NODETYPE &);
}; // end class List

// default constructor
template <typename NODETYPE>
List<NODETYPE>::List()
    : firstPtr(0), lastPtr(0)
{
    size = 0;
} // end List constructor

// destructor
template <typename NODETYPE>
List<NODETYPE>::~List()
{
    if (!isEmpty()) // List is not empty
    {
        cout << "Destroying  nodes ...\n";
        ListNode<NODETYPE> *currentPtr = firstPtr;
        ListNode<NODETYPE> *tempPtr;

        while (currentPtr != 0) // delete remaining nodes
        {
            tempPtr = currentPtr;
            cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        } // end while
    }     // end if
    cout << "All nodes destroyed\n\n";
} // end List destructor

// insert node at front of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value); // new node
    if (isEmpty())                                  // List is empty
        firstPtr = lastPtr = newPtr;                // new list has only one node
    else                                            // List is not empty
    {
        newPtr->nextPtr = firstPtr; // point new node to previous 1st node
        firstPtr = newPtr;          // aim firstPtr at new node
    }                               // end else
    size++;
} // end function insertAtFront

// insert node at back of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value); // new node

    if (isEmpty())                   // List is empty
        firstPtr = lastPtr = newPtr; // new list has only one node
    else                             // List is not empty
    {
        lastPtr->nextPtr = newPtr; // update previous last node
        lastPtr = newPtr;          // new last node
    }                              // end else
    size++;
} // end function insertAtBack

// delete node from front of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value)
{
    if (isEmpty())    // List is empty
        return false; // delete unsuccessful
    else
    {
        ListNode<NODETYPE> *tempPtr = firstPtr; // hold tempPtr to delete
        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0; // no nodes remain after removal
        else
            firstPtr = firstPtr->nextPtr; // point to previous 2nd node

        value = tempPtr->data; // return data being removed
        delete tempPtr;        // reclaim previous front node
        size--;
        return true; // delete successful
    }                // end else
} // end function removeFrontFront

// delete node from back of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value)
{
    if (isEmpty())    // List is empty
        return false; // delete unusuccessful
    else
    {
        ListNode<NODETYPE> *tempPtr = lastPtr; // hold tempPtr to delete

        if (firstPtr == lastPtr)    // List has  one element
            firstPtr = lastPtr = 0; // no nodes remain after removal
        else
        {
            ListNode<NODETYPE> *currentPtr = firstPtr;

            // locate second-to-last element
            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr; // move to next node

            lastPtr = currentPtr;    // remove last node
            currentPtr->nextPtr = 0; // this is now the last node
        }                            // end else

        value = tempPtr->data; // return value from old last node
        delete tempPtr;        // reclaim former last node
        size--;
        return true; // delete successful
    }                // end else
} // end function removeFromBack

// is List empty?
template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
    return firstPtr == 0;
} // end function isEmpty

//return pointer to newly allocated node
template <typename NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::getNewNode(
    const NODETYPE &value)
{
    return new ListNode<NODETYPE>(value);
} // end function getNewNode

// display contents of List
template <typename NODETYPE>
void List<NODETYPE>::print() const
{
    if (isEmpty()) // list is empty
    {
        cout << "The list is empty\n\n";
        return;
    } // end if

    ListNode<NODETYPE> *currentPtr = firstPtr;

    // cout << "The list is: ";

    while (currentPtr != 0) // get element data
    {
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    } // end while

    cout << "\n";
} // end function print

template <typename NODETYPE>
void List<NODETYPE>::printBackward() const
{
    if (isEmpty()) // list is empty
    {
        cout << "The list is empty\n\n";
        return;
    } // end if

    ListNode<NODETYPE> *currentPtr = firstPtr;
    this->printBackwardHelper(currentPtr);

    cout << "\n";
} // end function printBackward

template <typename NODETYPE>
void List<NODETYPE>::printBackwardHelper(const ListNode<NODETYPE> *ptr) const
{
    // is currentPtr the last ptr?
    // yes: print
    // no: call printBackwardHelper for nextPtr, then print
    if (ptr == lastPtr)
    {
        cout << ptr->data << " ";
    }
    else
    {
        printBackwardHelper(ptr->nextPtr);
        cout << ptr->data << " ";
    }
} // end function printBackwardHelper

template<typename NODETYPE>
const ListNode<NODETYPE> * List<NODETYPE>::searchList(const NODETYPE &target) const
{
    if (isEmpty()) // list is empty
        return NULL;
    
    return searchListHelper(target, firstPtr);
} // end function searchList

template<typename NODETYPE>
const ListNode<NODETYPE> * List<NODETYPE>::searchListHelper(const NODETYPE &target, const ListNode<NODETYPE> *ptr) const
{
    if (ptr->data == target)
        return ptr;
    else if (ptr == lastPtr)
        return NULL;
    else
        return searchListHelper(target, ptr->nextPtr);    
} // end function searchListHelper


// removes all nodes from list
template <typename NODETYPE>
void List<NODETYPE>::clear()
{
    while (!isEmpty())
    {
        NODETYPE value;
        this->removeFromFront(value);
    }
}

// returns list size
template <typename NODETYPE>
size_t List<NODETYPE>::getSize() const
{
    return size;
}

// returns element at given position
template <typename NODETYPE>
NODETYPE List<NODETYPE>::at(int position) const
{
    if (position > static_cast<int>(size) || position < 0)
    {
        cout << "Position not valid. Returning first value at first node." << endl;
        return firstPtr->data;
    }
    else
    {
        ListNode<NODETYPE> *currentPtr = firstPtr;
        while (position-- > 0)
        {
            currentPtr = currentPtr->nextPtr;
        }
        return currentPtr->data;
    }
}

// concatenates contents of second argument into first
template <typename NODETYPE>
void List<NODETYPE>::concatenate(List<NODETYPE> &list1, List<NODETYPE> &list2)
{
    if (!list2.isEmpty())
    {
        ListNode<NODETYPE> *currentPtr = list2.firstPtr;

        while (currentPtr != 0)
        {
            list1.insertAtBack(currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
    }
}

// merge first two arguments into third one
template <typename NODETYPE>
void List<NODETYPE>::merge(List<NODETYPE> &l1, List<NODETYPE> &l2, List<NODETYPE> &l3)
{
    // clear list 3
    l3.clear();

    ListNode<NODETYPE> *curPtr1 = l1.firstPtr;
    ListNode<NODETYPE> *curPtr2 = l2.firstPtr;

    while (curPtr1 != 0 || curPtr2 != 0)
    {
        if (curPtr1 != 0 && curPtr2 != 0)
        {
            NODETYPE data1 = curPtr1->data;
            NODETYPE data2 = curPtr2->data;
            if (data2 > data1)
            {
                l3.insertAtBack(data1);
                curPtr1 = curPtr1->nextPtr;
            }
            else
            {
                l3.insertAtBack(data2);
                curPtr2 = curPtr2->nextPtr;
            }
        } // end if both lists have items left
        else if (curPtr1 != 0)
        {
            l3.insertAtBack(curPtr1->data);
            curPtr1 = curPtr1->nextPtr;
        } // end if only first list is not empty
        else
        {
            l3.insertAtBack(curPtr2->data);
            curPtr2 = curPtr2->nextPtr;
        } // end if only second list is not empty
    }     // end while loop
}

#endif