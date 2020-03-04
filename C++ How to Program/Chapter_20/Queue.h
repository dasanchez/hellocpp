// Fig 20.16: Gueue.h
// Template Queue class definition derived from class List.
#ifndef QUEUE_H
#define QUEUE_H

#include "List.h" // List class definition

template <typename QUEUETYPE>
class Queue : private List<QUEUETYPE>
{
public:
    // enqueue calls List member function insertAtBack
    void enqueue(const QUEUETYPE &data)
    {
        this->insertAtBack(data);
    } // end function enqueue

    // dequeue calls List member function removeFromFront
    bool dequeue(QUEUETYPE &data)
    {
        return this->removeFromFront(data);
    } // end function dequeue

    // isQueueEmpty calls List member function isEmpty
    bool isQueueEmpty() const
    {
        return this->isEmpty();
    } // end function isQueryEmpty

    // printQueue calls List member function print
    void printQueue() const
    {
        this->print();
    } // end function printQueue
};    // end class Queue

#endif