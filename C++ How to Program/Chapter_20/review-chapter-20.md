**20.1** Fill in the blanks:

a. A self-_referential_ class is used to form dynamic data structures that can grow and shrink at execution time.

b. The _new_ operator is used to dynamically allocate memory and construct an object; this operator returns a pointer to the object.

c. A _stack_ is a constrained version of a linked list in which nodes can be inserted and deleted only from the start of the list and node values are returned in last-in, first-out order.

d. A function that does not alter a linked list, but looks at the list to determine whether it's empty, is an example of a _predicate_ function.

e. A queue is referred to as a _first-in, first-out (FIFO)_ data structure, because the first nodes inserted are the first nodes removed.

f. The pointer to the next node in a linked list is referred to as a _link_.

g. The _delete_ operator is used to destroy an object and release dynamically allocated memory.

h. A _queue_ is a constrained version of a linked list in which nodes can be inserted only at the end of the list and deleted only from the start of the list.

i. A _tree_ is a nonlinear, two-dimensional data structure that contains nodes with two or more links.

j. A stack is referred to as a _last-in, first-out (LIFO)_ data structure, because the last node inserted is the first node removed.

k. The nodes of a _binary_ tree contain two link members.

l. The first node of a tree is the _root_ node.

m. Each link in a tree node points to a _child_ or _subtree_ of that node.

n. A tree node that has no children is called a _leaf_ node.

o. The four traversal algorithms we mentioned in the text for binary search trees are _preorder_, _inorder_, _postorder_ and _level order_.

**20.2** What are the differences between a linked list and a stack?
A node can be inserted and removed anywhere in a linked list, but stacks only allow insertions and removals at the top.

**20.3** What are the differences between a stack and a queue?
A queue only allows insertions at the tail and removals at the head.

**20.4** Comment on how each of the following entities or concepts contributes to the reusability of data structures:
a. classes
Classes allow us to instantiate as many objects of a class as we want.

b. class templates
Class templates allow us to instantiate related classes based on different type parameters.

c. inheritance
Inheritance enables us to reuse code from a base class in a derived class.

d. `private` inheritance
Private inheritance enables us to prevent clients of the derived-class data structure from accessing base-class member functions that do not apply to the derived class.

e. composition
Composition enables us to reuse code by making a class object data structure a member of a composed class; if we make the class object a `private` member of the composed class, then the class object's `public` member  functions are not available through the composed object's interface.

20.5 The inorder traversal is
11 18 19 28 32 40 44 49 69 71 72 83 92 97 99

The preorder traversal is
49 28 18 11 19 40 32 44 83 71 69 72 97 92 99

The postorder traversal is
11 19 18 32 44 40 28 69 72 71 92 99 97 83 49