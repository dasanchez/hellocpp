## Chapter 20: Custom Templatized Data Structures

### 20.1 Introduction

- This chapter introduces **dynamic data structures** that grow and shrink during execution.
- **Linked lists** are collections of data items logically "lined up in a row"- insertions and removals are made anywhere in a linked list.
- **Stacks** are  importand in compilers and operating systems: Insertions and removals are made only at one end of a stack, its top.
- **Queues** represent wwaiting lines; insertions are made at the back (also referred to as the tail) of a queue and removals are made from the fron (also referred to as the head) of a queue.
- **Binary trees** facilitate high-speed searching and sorting of data and efficient elimination of duplicate data items among other applications.

### 20.2 Self-Referential Classes

- A **self-referential class** contains a member that points to a class object of the same class type. A "`next`" pointer member in a self-referential class is referred to as a **link**.
- Self-referential class objects can be linked together to form useful data structures such as lists, queues, stacks, and trees.
- A null (0) pointer normally indicates the end of a data structure just as the null character ('\0') indicates the end of a string.
- Not setting the link in the last node of a linked data structure to null (0) is a (possibly fatal) logic error.

### 20.3 Dynamic Memory Allocation and Data Structures

- Creating and maintaining dynamic data structures requires dynamic memory allocation, which enables a program to obtain more memory at execution time to hold new nodes. When that memory is no longer needed by the program, the memory can be _released_ so that it can be reused to allocate other objects in the future. The limit for dynamic memory allocation can in theory be as large as the aount of available physical memory in the computer or the amount of available virtual memory in a virtual memory system.
- The `new` operator takes as an argument the type of the object being dynamically allocated and returns a pointer to an object of that type:
```
Node *newPtr = new Node( 10 ); // create Node with data 10
```
- The `delete` operator runs the `Node` destructor and deallocates memory allocated with `new`. To free memory dynamically allocated by the preceding `new`, use the statement
```
delete newPtr;
```
- `newPtr` itself is not deleted; rather the destructor of the `Node` object that `newPtr` points to iis called and  the object's memory is freed. If pointer `newPtr` has the null pointer value 0, the preceding statement has no effect. It is _not_ an error to delete a null pointer.

### 20.4 Linked Lists

- A linked list is a linear collection of self-referential class objects, called **nodes**, connected by **pointer links**. A linked list is accessed  via a pointer to the list's first node. Each subsequent node is accessed via the link-pointer member stored in the precious node. By convenction, the link pointer in the last node of a list is set to null (0) to mark the end of the list.
- Data is stored in a linked list dynamically - each node is created as necessary.
- A node can contain data of any type, including objects of other classes. If nodes contain base-class pointers to base-class and derived-class objects related by inheritance, we can have a linked list of such nodes and process them _polymorphically_  using `virtual` function calls.
- Stack and queues are also **linear data structures**, and  can be viewed as constrained versions of linked lists.
- Trees are **nonlinear data structures**.
- Lists of data can be stored in arrays, but linked lists provide several advantages. A linked list is appropriate when the number of data elements to be represented at one time is _unpredictable_. Lined lists are dynamic, so the length of a list can increase or decrease as necessary. The size of a "conventional" C++ array, however, cannot be altered, because th array size is fixed at compile time. "Conventional" arrays can become full. Linked lists become full only when the system has insufficient memory to satisfy additional dynamic sotrage allocation requests.
- An array can be declared to contain more elements that the number of items expected, but this can waste memory. Linked lists can provide better memory utilization in these situations. Linked lists allow the program to adapt at runtime.
- Class template `vector` implements a dynamically resizable array-based data structure.
- Linked lists can be maintained in sorted order by inserting each new wlement at the proper point in the list. Existing list elements do not need to be moved. Pointers merely need to be updated to point to the correct node.
- Insertion and deletion in a sorted array can be time consuming. A linked list allows efficient insertion operations anywhere in the list.
- THe elements of an array are stored contiguously in memory. This allows immediate access to any element. Linked lists do not afford such immediat direct access to their elements. So accessing individual elements in a linked list can be considerably more expensive than accessing individual elements in an array.
- The selection of a data structure is typically based on the performance of specific operations used by a program and the order in which the data items are maintained in the data structure.
- Using dynamic memroy allocation (instead of fixed-size arrays) for data structures that grow and shrink at execution time can save memory. Keep in mind, however, that pointers occupy space and that dynamic memory allocation incurs the overhead of function calls.
- Assign null(0) to the link member  of a new node. Pointers must be initialized before they're used.

**Circular Linked Lists and Double Linked Lists**

- A **singly linked list** begins with a pointer to the first node, and each node contains a pointer to the next node "in sequence". This list terminates with a node whose pointer member has the value 0. A singly liinked list may be traversed in only _one_ direction.
- A **circular, singly linked list** begins with a pointer to the first node, and each node contains a pointer to the next node. The "last node" does not contain a 0 pointer; rather, the pointer in the last node points back to the first node, thus closing the "circle".
- A **double linked list** allows traversals _both forward and backward_. Such a list is often implemented with two "start pointers": one that pointer to the first element of the list to allow front-to-back traversal, and one that points to the last element to allow back-to-front traversal. Each node has both a forward pointer and a backward pointer.
- In a **circular, doubly linked list**, the forward pointer of the last node points to the first node, and the backward pointer of the first node points to the last node, thus closing the "circle".

### 20.5 Stacks

- A stack data structure allows nodes to be added to the stack and removed from the stack only at the _top_. For this reason, a stack is referred to as a _last-in, first out (LIFO)_ data structure. One way to implement a stack is a constrained version of a linked list. In such an implementation, the link member in the last node of the stack is set to null (zero) to indicate the _bottom_ of the stack.
- The primary member functions used to manipulate a stack are `push` and `pop`. Function `push` _inserts_ a new node at the top of the stack. Function `pop` _removes_ a node from the top of the stack, stores the popped value in a reference variable that's passed to the calling function and returns `true` if the `pop` operation was successful (`false` otherwise).
- When we implement the `Stack`'s member functions, we then have each of these call the appropriate member function of the `List` class- this is referred to as **delegation**.
- The explicit use of `this` is required so the compiler can properly resolve identifiers in template definitions.  A **dependent name** is an identifier that depends on a template parameter. Resolution of dependent names occurs when the template is instantiated. The identifier for a function that takes no arguments in the superclass is a **non-dependent name**. Such identifiers are normallly resolved at the point where the template is defined. If the template has not yet been instantiated, then the code for the function with the non-dependent name does not yet exist and some compilers will generate compilation errors. Adding the explicit use  of `this->` makes the calls to the base class's member functions dependent on the template parameter and ensures that the code will compile properly.

### 20.6 Queues

- A **queue** similar to a supermarket checkout line- the _first_ person in line is serviced  _first_, and other customers enter the line at the _end_ and _wait_ to be serviced. Queue nodes are removed only from the head of the queue and are inserted only at the tail of the queue. For this reason, a queue is referred to as a first-in, first-out (FIFO) data structure. The insert and remove operations are known as **enqueue** and **dequeue**.

### 20.7 Trees

- Linked lists, stacks, and queues are linear data structures. A tree is a nonlinear, two-dimensional data structure. Tree nodes contain two or more links.
- Binary trees are trees whose nodes all contain two links (none, one, or both of which may be null).
- The **rot node** is the first node in a tree. Each link in the root node refers to a **child**. The **left child** is the root node of the **left subtree**. The **right child** is the root node of the **right subtree**.
- The children of a given node are called **sublings**.
- A node with no children is a **leaf node**.
- A **binary search tree** (with no duplicate node values) has the characteristic that the values in any left subtree are _less than the value_ in its **parent node**, and the values in any right subtree _are greater than_ the value in its parent node.
- A binary search tree can be walked through with an **inorder**, **preorder**, and **postorder** **traversals**.
- A node can only be inserted as a leaf node in a binary search tree.
- The inorder traversal of a binary search tree prints the node values in ascending order. The  process of creating a binary search tree actually _sorts_ the data - thus, this process is called the **binary tree sort**.
- The binary search tree facilitates **duplicate elimination**.
- Searching a binary tree for a value that matches a key value is also fast. If the tree is balanced, then each branch contains about half the number of nodes in the tree. Each comparison of a node to the search key eliminates half the nodes. This is called an O(log n) algorithm. So a binary search tree with n elements would require a maximum of log 2 n comparisons either to find a match or to determine that no match exists.
- The level-order traversal of a binary tree visits the nodes of the tree row by row, starting at the root node level. On each levvel of the tree, the nodes are visited from left to right.
