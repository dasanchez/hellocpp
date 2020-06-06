## Chapter 22: Standard Template Library (STL)

### 22.1 Introduction to the Standard Template Library (STL)

- The Standard Template Library (STL) defines powerful, template-based, reusable components that implement many common data structures and algorithms used to process those data structures.
- The STL has three key components: **containers** (popular templatized data structures), **iterators**, and **algorithms**. The STL containers are data structures capable of storing objects of almost any data type.
- There are three styles of container classes: **first-class containers**, **adapters**, and **near containers**.
- Each STL container has associated member functions. A subset of these member functions is defined in all STL containers.
- STL iterators, which have properties similar to those of pointers, are used by programs to manipulate the STL-container elements.
- STL algorithms are functions that perform such common data manipulations as searching, sorting, and comparing elements or entire containers. Most of them use iterators to access container elements.
- The STL approach allows programs to be written so that the code does not depend on the underlying container. Such a programming style is called generic programming.
- Avoid reinventing the wheel; program with the reusable components of the C++ Standard Library.
- The prepackaged, templatized containers of the STL are sufficient for most applications. Using the STL helps you reduce testing and debugging time.

### 22.2 Introduction to Containers

- The containers are divided into three major categories: **sequence containers**, **associative containers**, and **container adapters**.

**Sequence containers**

- `vector`: Rapid insertions and deletions at back. Direct access to any element.
- `deque`: Rapid insertions and deletions at front or back. Direct acces to any element.
- `list`: Doubly linked list, rapid insertion and deletion anywhere.

**Associative containers**

- `set`: Rapid lookup, no duplicates allowed.
- `multiset`: Rapid lookup, duplicates allowed.
- `map`: One-to-one mapping, no duplicates allowed, rapid-key based lookup.
- `multimap`: One-to-many mapping, duplicates allowed, rapid key-based lookup.

**Container adapters**
- `stack`: Last-in, first-out (LIFO).
- `queue`: First-in, first-out (FIFO).
- `priority_queue`: Highest-priority element is always the first element out.

- The sequence containers represent linear data structures, such as vectors and linked lists. Associative containers are nonlinear containers that typically can locate elements stored in the containers quickly. Such containers can store sets of values or **key/value pairs**. The sequence containers and associative containers are collectively referred to as first-class containers.
- STL implements stacks and queues as container adapters that enable a program to view a sequential container in a constrained manner.

**STL Container Common Functions**

- default constructor: A constructor that initializes an empty container. Normally, each container has several constructors that provide different initialization methods for the container.
- copy constructor: A constructor that initializes the container to be a copy of an existing container of the same type.
- destructor: Destructor function for cleanup after a container is no longer needed.
- `empty`: Returns `true` if there are no elements in the container; otherwise, returns `false`.
- `insert`: Inserts an item in the  container.
- `size`: Returns the nnumber of elements currently in the container.
- `operator=`: Assigns one container to another.
- `operator<`: Returns `true` if the contents of the first container is less than the second; otherwise, returns `false`.
- `operator<=`: Returns `true` if the contents of the first container is less than or equal to the second; otherwise, returns `false`.
- `operator>`: Returns `true` if the contents of the first container is greater than the second; otherwise, returns `false`.
- `operator>=`: Returns `true` if the contents of the first container is greater than or equal to the second; otherwise, returns `false`.
- `operator==`: Returns `true` if the contents of the first container is equal to the second; otherwise, returns `false`.
- `operator!=`: Returns `true` if the contents of the first container is not equal to the second; otherwise, returns `false`.
- `swap`: Swap the elements of two containers.

_Functions found only in first-class containers_

- `max_size`: Returns the maximum number of elements for a container.
- `begin`: The two versions of this function return either an `iterator` or a `const_iterator` that refers to the first element of the container.
- `end`: The two versions of this function return either an `iterator` or a `const_iterator` that refers to the next position after the end of the container.
- `rbegin`: The two versions of this function retun either a `reverse_iterator` or a `const_reverse_iterator` that refers to the last element of the container.
- `rend`: The two versions of this function return either a `reverse_iterator` or a `const_reverse_iterator` that refers to the next position after the last element of the container.
- `erase`: Erases one or more elment from the container.
- `clear`: Erases all elements from the container.

**STL Container Headers**

- `<vector>`
- `<list>`
- `<deque>`
- `<queue>`: Contains both `queue` and `priority_queue`.
- `<stack>`
- `<map>`: Contains both `map` and `multimap`.
- `<set>`: Contains both `set` and `multiset`.
- `<valarray>`
- `<bitset>`

**First-Class Container Common `typedef`s**

- `allocator_type`: The type of the object used to allocate the container's memory.
- `value_type`: The type of element stored in the container.
- `reference`: A reference for the container's element type.
- `const_reference`: A constant reference for the container's element type. Such a reference can be used only for reading elements in the container and for performing `const` operations.
- `pointer`: A pointer for the container's element type.
- `const_pointer`: A pointer for a constant of the container's element type.
- `iterator`: An iterator that points to an element of the container's element type.
- `const_iterator`: A constant iterator that points to an element of the container's element type and can be used only to read elements.
- `reverse_iterator`: A reverse iterator that points to an element of the container's element type. This type of iterator is for iterating through a container in reverse.
- `const_reverse_iterator`
- `difference_type`: The type of result of subtracting two iterators that refer to the same container (operator `-` is not defined for iterators of `lists` and associative containers).
- `size_type`: The type used to count items in a container and index through a sequence container (cannot index through a `list`).

- When preparing to use an STL container, it's important to ensure that the type of element being stored in the containeer supports a minimum set of functionality. When an element is inserted into a container, a copy of that element is made. The element type should provide its own copy constructor and assignment operator. 
- The associative containers and many algorithms require elements to be compared. The element type should provide an equality operator and a less-than operator.

### 22.3 Introduction to Iterators

- Iterators are used to point to first-class container elements.
- Iterators hold state information sensitive to the particular containers on which they operate; ths, they are implemented appropriately ffor each type of container.
- Certain iterator operations are uniform across containers.
- The deferencing operator (`*`) dereferences an iterator so that you can use the element to which it points. The ++ operation on an iterator moves it to the container's next element.
- STL first-class containers provide member functions `begin` and `end`. Function `begin` returns an iterator pointing to the first element of the container. Function `end` returns an iterator pointing to the first element past the end of the container.
- An object of type `iterator` refers to a container element that can be modified. An object of type `const_iterator` refers to a container element that _cannot_ be modified.
- The `*` (dereferencing) operator of any `const` iterator returns a `const` reference to the container element, disallowing the use of non-`const` member functions.
- Attempting to create a non-`const` iterator for a `const` container results in a compilation error.

**Iterator Categories**

- input: Used to read an element from a container. An input iterator can move only in the forward direction (from the beginning of the container to the end) one element at a time. Input iterators support only one-pass algorithms- the same input iterator cannot be used to pass through a sequence twice.
- output: Used to write an element to a container. An output iterator can move only in the forward direction one element at a time. Output iterators support only one-pass algorithms.
- forward: Combines the capabilities of input and output iterators and retains their position in the container (as state information).
- bidirectional: Conbines the capabilities of a forward iterator with the ability to move in the backward direction. Bidirectional iterators support multipass algorithms.
- random access: Combines the capabilities of a bidirectional iterator with the ability to directly access any element of the container (i.e., no jump forward or backward by an arbitrary number of elements).

- The iterator category that each container supports determines whether that container can be used with specific algorithms in the STL.
- Containers that support random-access iterators can be used with all algorithms in the STl.
- Pointers into arrays can be used in place of iterators in most STl algorithms, including those that require random-access iterators.
- The first-clas containers (`vector`s, `deque`s, `list`s, `set`s, `multiset`s, and `multimap`s), `string`s, and arrays are all traversable with iterators.
- Using the "weakest iterator" that yields acceptable performance helps produce maximally reusable components. For example, if an algorithm requires only forward iterators, it can be used with any container that supports forward iterators, bidirectional iterators, or random-access iterators. However, an algorithm that requires random-access iterators can be used only with containers that have random-access iterators.

| Container                            | iterator supported     |
|:-------------------------------------|------------------------|
| Sequence containers (first class)    |                        |
| `vector`                             | random access          |
| `deque`                              | random access          |
| `list`                               | bidirectional          |
| Associative containers (first class) |                        |
| `set`                                | bidirectional          |
| `multiset`                           | bidirectional          |
| `map`                                | bidirectional          |
| `multimap`                           | bidirectional          |
| Container adapters                   |                        |
| `stack`                              | no iterators supported |
| `queue`                              | no iterators supported |
| `priority_queue`                     | no iterators supported |

**Predefined Iterator `typedef`s**

- Not every `typedef` is defined for every container.
- We use `const` versions of the iterators for traversing read-only containers.
- `iterator`: ++ moves in forward direction, read/write capability.
- `const_iterator`: ++ moves in forward direction, read capability.
- `reverse_iterator`: ++ moves in backward direction, read/write capability.
- `const_reverse_iterator`: ++ moves in backward direction, read capability.
- Operations performed on a `const_iterator` return `const` references to prevent modification to elements of the container being manipulated. Using `const_iterators` where appropriate is another example of the principle of least privilege.

**Iterator Operations**

| Iterator operation      | Description                                                                                         |
|:------------------------|:----------------------------------------------------------------------------------------------------|
| All iterators           |                                                                                                     |
| `++p`                   | Preincrement an iterator                                                                            |
| `p++`                   | Postincrement an iterator                                                                           |
| Input iterators         |                                                                                                     |
| `*p`                    | Dereference an iterator                                                                             |
| `p = p1`                | Assign one iterator to another                                                                      |
| `p == p1`               | Compare iterators for equality                                                                      |
| `p != p1`               | Compare iterators for inequality                                                                    |
| Output iterators        |                                                                                                     |
| `*p`                    | Dereference an iterator                                                                             |
| `p = p1`                | Assign one iterator to another                                                                      |
| Forward iterators       | Forward iterators provide all the functionaliry of both input iterators and output iterators        |
| Bidirectional iterators |                                                                                                     |
| `--p`                   | Predecrement an iterator                                                                            |
| `p--`                   | Postdecrement an iterator                                                                           |
| Random-access iterators |                                                                                                     |
| `p += i`                | Increment the iterator `p` by i positions                                                           |
| `p -= i`                | Decrement the iterator `p` by i positions                                                           |
| `p + i` or `i + p`      | Expression value is an iterator positioned at `p` incremented by `i` positions                      |
| `p - i`                 | Expression value is an iterator positioned at `p` decremented by `i` positions                      |
| `p - p1`                | Expression value is an integer representing the distance between two elements in the same container |
| `p[i]`                  | Return a reference to the element offset from `p` by `i` positions                                  |
| `p < p1`                | Return `true` if iterator `p` is less than or equal to iterator `p1`, otherwise return `false       |
| `p <= p1`               |                                                                                                     |
| `p > p1`                |                                                                                                     |
| `p >= p1`               |                                                                                                     |

### 22.4 Introduction to Algorithms

- STL algorith,s can be used generically across a variety of containers.
- Inserting, deleting, searching, sorting, and others are appropriate for some or all of the STL containers.
- The algorithms operate on container elements only indirectly through iterators.
- Algorithms often return iterators that indicate the results of the algorithms. Algorithm `find`, for example, locates an element and returns an iterator to that element.
- The STL is extensible. It's straightforward to add new algorithms and to do so without changes to STL containers.
- The STL is implemented concisely. The algorithms are separated from the containers and operate on elements of the containers only indirectly through iterators. This separation makes it easier to write generic algorithms applicable to many container classes.
- STL algorithms can operate on STL containers and on pointer-based C-like arrays.
- Tere are mutating-sequence algorithms (those that can modify the container), and nonmodifying sequence algorithms (those that do not result in modifications to the container).

### 22.5 Sequence Containers

- The C++ STL provides three sequence containers: `vector`, `list`, and `deque`.
- `vector` and `deque` are based on arrays, and `list` implements a linked-list data structure.
- Insertion at the back of a `vector` is efficient. The `vector` simply frows, if necessary, to accommodate the new item. It's expensive to insert (or delete) an element in the middle of a `vector`: the entire portion of the `vector` after the insertion (or deletion) point must be moved, because `vector` elements occupy contiguous cells in memory just as C or C++ "raw" arrays do.
- Applications that require frequent insertions and deletions at both ends of a container normally use a `deque` rather than a vector. Class `deque` is more efficient than `vector` for doing insertions and deletions at the front.
- Applications with frequent insertions and deletions in the middle and/or at the extremes of a container normally use a `list`, due to its efficient implementations of insertion and deletion anywhere in the data structure.
- Sequence containers have several other common operations: `front` returns a reference to the first element in a non-empty container, `back` returns a reference to the last element in a non-empty container. `push_back` inserts a new element at the end of the container and `pop_back` removes the last element of the container.

#### 22.5.1 `vector` Sequence Container

- Class template `vector` provides a data structure with contiguous memory locations. It's most commonly used when the data in the container must be easily accessible via a subscript or will be sorted.
- When a `vector`'s memory is exhausted, the `vector` allocates a larger contiguous area of memory, _copies_ the original elements into the new memory and _deallocates_ the old memory.
- Choose the `vector` container for the best random-access performance.
- Object of class template `vector` provide rapid indexed access with the overloaded subscript operator `[]` because they're stored in contiguous memory like a C or C++ raw array.
- It's faster to insert many elmeents into a container at once than one at a time.
- A `vector` supports random-access iterators. All STL algorithms can operate on a `vector`.
- Function `push_back` is available in all sequence containers and is used to add an element to the  end of the `vector`.
- If an element is added to a full `vector`, the `vector` increases its size- some STL implementations have the `vector` double its capacity.
- It can be wasteful to double a `vector`'s size when more space is needed. For example, a full `vector` of 1,000,000 elements resizes to accommodate 2,000,000 elements when a new element is added. This leaves 999,999 unused elements. You can use  `resize` and `reserve` to control space usage better.
- Use prefix increment when appied to STL iterators because the prefix increment operator does not have the overhead of returning a value that must be stored in a temporary object.
- Only random-access iterators support `<`. It's better to use != and `end` to test for the end of a container.
- Attempting to dereference an iterator positioned outside its container is a runtime logic error. In particular, the iterator returned by `end` cannot be dereferenced or incremented.
- For performance reasons, capture the loop ending value before the loop and compare against that, rather than having aa (potentially expensive) function call for each iteration.

**Vector Element-Manipulation Functions**

- `ostream_iterator` can be used to output integers separated by single spaces via `cout`.
- Algorithm `copy` from the Standard Librar can be used to output the entire contents of `vector`s to the standard output. 
- Functions `front` and `back` are available for all sequence containers and are used to determing a `vector`s first and last elements, respectively. The `vector` must not be empty, otherwise the results of `front` and `back` functions are undefined.
- `insert` function inserts the value at the location specified by the first argument.
- `erase` function indicates that the element at the location specified by the iterator argument should be removed from the container.
- Function `empty` is used to check whether the container has any elements.
- Erasing an element that contains a pointer to a dynamically allocated object does not `delete` that object; this can lead to a memory leak.
- Function `clear` is found in all first-class containers, and is used to remove all elements at once.

#### 22.5.2 `list` Sequence Container

- The `list` sequence container provides an efficient implementation for insertion and deletion operations at any locaation in the container. If most of the insertions and deletions occur at the ends of the container, the `deque` data structure provides a more efficient implementation.
- Class template `list` is implemented as a _doubly linked list_: every node in the `list` contains a pointer to the previous node in the `list` and to the next node in the `list`.
- Any iterator that requires input, output, forward or bidirectional iterators can operate on a `list`.
- Many `list` member functions manipulate the elements of the container as an ordered set of elements.
- Class template `list` provides additional member functions: `splice`, `push_front`, `pop_front`, `remove`, `remove_if`, `unique`, `merge`, `reverse`, and `sort`.
- Function `push_front` is specific classes `list` and `deque` (not to `vector`). Function `push_back` is common to all sequence containers.
- The `list` member function `sort` arranges the elements in ascending order. This is different from the `sort` in the STL algorithms.
- Function `splice` removes the elements from a list and inserts them into another one.
- Function `merge` removes all elements from a list and inserts them into another one in sorted order. Both lists must be sorted in the same order before this operation is performed. 
- Function `pop_front` removes the first element in the `list`. `pop_back` is available to all sequence containers.
- Function `unique` removes duplicate elements in the `list`. The `list` should be in sorted order before this operations is performed, to guarantee that all duplicates are eliminated.
- `swap` exchanges the contents of two `lists`.
- Function `assign` (available to all sequence containers) replaces the contents of a `list` with another's using specified ranges.
- Function `remove` deletes all copies of the specified value from a `list`.

#### 22.5.3 `deque` Sequence Container

- Class `deque` provides many of the benefits of a `vector` and a `list` in one container.
- The term `deque` is  short for "double-ended queue". Class `deque` is implemented to provide efficient indexed access (using subscripting) for reading and modifying its elements.
- Class `deque` is also implemented for _efficient insertion and deletion operations at its front and back_.
- Class `deque` provides support for random-access iterators, so `deque`s can be used with all STL algorithms.
- One of the  most common uses of a `deque` is to maintain a first-in, first-out queue of elements. In fact a `deque` is the default underlying implementation for the `queue` adaptor.
- In genertal, `deque` has  higher ovdrhead than `vector`.
- Insertions and deletions in the  middle of a `deque` are optimized to minimize the number of elements copied, so it's more efficient than `vector` but less efficient than a `list` for this kind of modification.

### 22.6 Associative Containers

- The STL's associative containers provide _direct access_ to store and retrieve elements via **keys** (often called **search keys**).
- The four associative containers are `multiset`, `set`, `multimap`, and `map`.
- Each associative container maintains its keys in _sorted order_.
- Iterating through an associative container traverses in the sort order for that container.
- Classes `multiset` and `set` provide operations for manipulating sets of values where the values are the keys- there s not a separate value associated with each key.
- The primary difference between a `multiset` and a `set` is that  a `multiset` allows duplicate keys and a `se` does not.
- Classes `multimap` and `map` provide operations for manipulating values associated with keys (those values are sometimes referred to as **mapped values**).
- The primary difference between a `multimap` and a `map` is that a `multimap` allows duplicate keys with associated values to be stored and a `map` allows only unique keys with associated values.

#### 22.6.1 `multiset` Associative Container

- The `multiset` associative container provides fast storage and retrieval keys and allows duplicate keys. The ordering of the elements is determined by a **comparator function object**.
- The data type of the keys in all associative containers must support comparison properly based on the comparator function object specified - keys sorted with `less<T>` must support comparison with `operator<`.
- A `multiset` supports bidirectional iterators (but not random-access iterators).
- Use `typedef`s to make code with long type names (such as `multiset`s) easier to read.
- Function `find` (available to all associative containers) to locate a value.
- `lower_bound` locates the earliest occurrence of a value, and `upper_bound` locates the element _after_ the last occurrence of a value.
- Function `equal_range` returns a `pair` containing the results of both a `lower_bound` and an `upper_bound` operation. Type `pair` contains two `public` data members called `first` and `second`.

#### 22.6.2 `set` Associative Container

- The `set` associative container is used for fast storage and retrieval of unique keys. The implementation of a `set` is identical to that of a `multiset`, except that a `set` must have unique keys.
- If an attempt is made to insert a duplicate key into a `set`, the duplicate is ignored.
- A `set` supports bidirectional iterators, but not random-access iterators.

#### 22.6.3 `multimap` Associative Container

- The `multimap` associative container is used for fast storage and  retrieval of keys and associated values (often called key/value pairs).
- Many of the functions used with `multiset`s and `set`s are also used with `multimap`s and `map`s.
- The elements of `multimap`s and `map`s are `pair`s of keys and values instead of individual values. When inserting into a `multimap` or `map`, a `pair` object that contains the key and value is used.
- The ordering of the keys is determined by a comparator function object. For example, in a `multimap` that uses integers as the key type, keys can be sorted in ascending order by ordering them with comparator function object`less<int>`.
- Duplicate keys are allowed in a `multimap`, so multiple values can be associated with a single key. This is called a **one-to-many relationship**.
- A `multimap` supports bidirectional iterators, but not random-access iterators.
- A `multimap` is implemented to efficiently locate all values paired with a given key.

#### 22.6.4 `map` Associative Container

- The `map` associative container performs fast storage and retrieval of unique keys and associated values. Duplicates are not allowed. This is called a **one-to-one mapping**.
- A `map` is also known as an **associative array**. Providing the key in a `map`'s subscript operator `[]` locates the value associated with that key in the `map`.
- Insertions and deletions can be made anywhere in a `map`.

### 22.7 Container Adapters

- The STL provides three **container adapters**- `stack`, `queue`, and `priority_queue`.
- Adapters are not first-class containers, because they do not provide the actual data-structure implementation in which elements can be stored and because adapters do not support iterators.
- The benefit of an adapter class is that you can choose an appropriate underlying data structure.
- All three adapter classes provide member functions **push** and **pop** that properly insert an element into each adapter data structure and properly remove an element from each adapter data structure.

#### 22.7.1 `stack` Adapter

- Class `stack` enables insertions into and deletions from the underlying data structure at one end (commonly referred to as a last-in, first-out data structure).
- A `stack` can be implemented with any of the sequence containers: `vector`, `list`, and `deque`.
- By default, a `stack` is implemented with a `deque`.
- Each of the common operations of a `stack` is implemented as an `inline` function that calls the appropriate function of the  underying container. This avoids the overhead of a second function call.
- For the best performance, use class `vector` as the underlying container for a `stack`.
- Function `top` does not remove the top element.

#### 22.7.2 `queue` Adapter

- Class `queue` enables insertions at the back of the underlying data structure and deletions from the front (commonly referred to as a first-in, first-out data structure).
- A `queue` can be implemented with STL data structure `list` or `deque`.
- By default, a `queue` is implemented with a `deque`.
- The common `queue` operations are `push` to insert an element at the back of the `queue`, `pop` to remove the element at the front of the `queue`, `front` to get a reference to the first element in the `queue`, `back` to get a reference to the last element in the `queue`, `empty` to determine whether the `queue` is empty, and `size` to get the number of elements in the `queue`.
- For the best performance, use class `deque` as the underlying container for a `queue`.
- Each of the common operations of a `queue` is implemented as an `inline` function that calls the appropriate function of the underlying container. This avoids the overhead of a second function call.

#### 22.7.3 `priority_queue` Adapter

- Class `priority_queue` provides functionality that enables insertions in sorted order into the underlying data sstructure and deletiosn from the front of the underlying data structure.
- A `priority_queue` can be implemented with STL sequence containers `vector` or `deque` (the default).
- When elements are added to a `priority_queue`, they're inserted in priority order, such that the highest-priority element (i.e., the largest value) will be the first element removed from the  `priority_queue`. This is usually accomplishedd by arranging the elements in a binary tree structure called a **heap** that always maintains the largest value at the front of the data structure.
- For the best performance, use class `vector` as the underlying container for a `priority_queue`.

### Algorithms

- Until the STL, class libraries of containers and algorithms were essentially incompatible among vendors. Early container libraries generally used inheritance and polymorphism, with the associated overhead of `virtual` function calls. Early libraries built the algorithms into the container classes as class behaviours.
- The STL separates the algorithms from the containers. This makes it much easier to add new algorithms.
- With the STL, the elements of containers are accessed through iterators.
- STL algorithms do not depend on the implementation details of the containers on which they operate. As long as the container's (or array's) iterators satisfy the requirements of the algorithm, STL algorithms can work on C-style pointer-based arrays, STL containers, and user-defined data structures.

#### 22.8.1 `fill`, `fill_n`, `generate`, and `generate_n`

- Functions `fill` and `fill_n` set every element in a range of container elements to a specific value.
- Functions `generate` and `generate_n` use a **generator function** to create values for every element in a range of container elements. The generator function takes no arguments and returns a value that can be placed in an element of the container.

#### 22.8.2 `equal`, `mismatch`, and `lexicographical_compare`

- Function `equal` compares two sequences of values for equality.
- Function `mismatch` compares two sequences of values and returns a `pair` of iterators indicating the location in each sequence of the mismatched elements. If all the elements match, the two iterators in the `pair` are equal to the last iterator for each sequence.
- Function `lexicographical_compare` compares the contents of two character arrays.

#### 22.8.3 `remove`, `remove_if`, `remove_copy`, and `remove_copy_if`

- Function `remove` eliminates all elements with the specified value in the given range. This function does not modify the number of elements in the `vector` or destroy the eliminated elements, but it does move all elements that are not eliminated toward the beginning of the `vector`.
- Function `remove_copy` copies all elements that do not have a specified value in a gven range to another container.
- Function `remove_if` deletes elements in a range when the given predicate function returns `true`.

#### 22.8.4 `replace`, `replace_if`, `replace_copy`, and `replace_copy_if`

- Function `replace` replaces all elements with a given value in a specified range with a second value.
- Function `replace_copy` copies all elements in a specified range, replacing them with a second value.

#### 22.8.5 Mathematical Algorithms

- Function `random_shuffle` reorders randomly the elements in the range. This function takese two random-access iterator arguments.
- Function `count` counts the elements with a specified value in the range. This function requires its two iterator arguments to be at least input iterators.
- Function `min_element` locates the smallest element in the range. The function's two iterator arguments must be at least input iterators.
- It is good practice to check that the range specified in a call to `min_element` is not empty and that the return alue is not the "past the end" iterator.
- Function `max_element` locates the largest element in the range. The function returns an input iterator at the largest element.
- Function `accumulate` to sum the values in the range. The two iterator arguments must be at least input iterators and the third arfument represents the initial value of the total.
- Function `for_each` applies a general function to every element in the range. The general function takes the current element as an argument and may modify that element if it's received by reference. This function requires its two iterator arguments to be at least input iterators.
- Function `transform` applies a general function to every element in the range and puts the result in a container specified by an iterator. The general function should take the current element as an argument, should not modify the element, and should return the tranformed value.

#### 22.8.6 Basic Searching and Sorting Algorithms

- Function `find` locates a given value in a range. It returns an input iterator that either is positioned at the first elemenet containing the value or indicates the end of the sequence.
- Function `find_if` locates the first value in a range for which a unary predicate function returns `true`.
- Function `sort` arranges the elements in a range in ascending order. A second version of this function takes a third argument that's a binary predicate function taking two arguments that are values in the sequence and returning a `bool` indicating the sorting order. If the return value is `true`, the two elements being compared are in sorted order.
- Attempting to `sort` a container by using an iretator other htan a random-access iterator is a compilation error. Function `sort` requires a random-access iterator.
- Function `binary_search` determins whether a value is in a given range. The sequence of values must be sorted in ascending order first.

#### 22.8.7 `swap`, `iter_swap`, and `swap_ranges`

- Function `swap` exchanges two values.
- Function `iter_swap` exchanges two elements. The function takes two forward iterator arguments.
- Function `swap_ranges` exchanges elements between specified ranges.

#### 22.8.8 `copy_backward`, `merge`, `unique`, and `reverse`

- Function `copy_backward` copies elements in a range by starting from the last element up to the beginning of the range. This function requires three bidirectional iterator arguments. One difference between `copy_backward` and `copy` is that the iterator returned from `copy` is positioned after the last element copied and the one returned from `copy_backward` is positioned `at` the last element copied.
- `copy_backward` can manipulate overlapping ranges of elements in a container as long as the first element to copy is not in the destination range of elements.
- Function `merge` combines two soerted ascending sequences of values into a third sorted ascending sequence.
- `back_inserter` calls the container's default `push_back` functionn to insert an element at the end of the container. If an element is inserted into a container that has no more space available, the container grows in size.
- Function `unique` removes duplicate entries in a sorted sequence.
- Function `reverse` reverses all the elements in a given range.

#### 22.8.9 `inplace_merge`, `unique_copy`, and `reverse_copy`

- Function `inplace_merge` merges two sorted sequences in the same container.
- Function `uinque_copy` copies all the unique elements in a sorted sequence.
- Function `reverse_copy` makes a reversed copy of the elements in a given range.

#### 22.8.10 Set Operations

- Function `includes` compares two sets of sorted values to determine whether everly element of the  second set is in the first set.
- Function `set_difference` finds the elements from the first set of sorted values that are not in the second set of soerted values (must sets of values must be in ascending order).
- Function `set_intersect` determines the elements from the first set of sorted values that are in the second set of sortev values (both sets of values must be in ascending order).
- Functions `set_symmetric_difference` determines the elements in the first set that are not in the second set and the elements in the second set that are not in the first set.
- Function `set_union` creates a set of all the elements that are in either or both of the two sorted sets (both sets of values must be in ascending order).

#### 22.8.11 `lower_bound`, `upper_bound`, and `equal_range`

- Function `lower_bound` finds the first location in a sorted sequence of values at which the third argument could be in the sequence such that the sequence would still be sorted in ascending order.
- Function `upper_bound` finds the last location in a sorted sequence of values at which the third argument could be in the sequence such that the sequence would still be sorted in ascending order.
- Function `equal_range` returns a `pair` of forward iterators containing the results of performing both a `lower_bound` and an `upper_bound` operation.

#### 22.8.12 Heapsort

- Heapsort is a sorting algorithm in which an array of elements is arranged into a special binary tree called a _heap_. The key features of a heap are that the largest element is always at the top of the heap and the values of the children of any node in the binary tree are always less han or equal to that node's value. A heap arranged in this manner is often called a **maxheap**.
- Function `sort_heap` sorts a sequence of values in a given range that are already in a heap.
- Function `push_heap` adds a new value into a heap.
- Function `pop_heap` removes the top heap element.

#### 22.8.13 `min` and `max`

- Algorithms `min` and `max` determine the minimum and the maximum of two elements, repsectively.

#### 22.8.14 Other STL Algorithms

- `inner_product`: Calculate the sum of the products of two sequences.
- `adjacent_difference`: Beginning with the second element in a sequence, calculate the differencce between the current and previous elements, and store the results.
- `partial_sum`: Calculate a running total of the values in a sequence.
- `nth_element`: Use three random-access to partition a range of elements. After this algorithm executes, all elements before the partitioning element are less than that element and all elements after the partitioning element are greater than or equal to that element.
- `partition`: Similar to the `nth_element`, but requires less powerful bidirectional iterators, making it more flexible.
- `stable_partition`: Similar to `partition` except that this algorithm guarantees that equivalent elements will be maintained in their original order.
- `next_permutation`: Next lexicographical permutation of a sequence.
- `prev_permutation`: Previous lexicographical permutation of a sequence.
- `rotate`: Use three forward iterator arguments to rotate the sequence indicated by the first and last argument by the number of positions indicated by subtracting the first argument from the second argument.
- `rotate_copy`: The results are stored in a separate sequence indicated by the fourth argument. The two sequences must have the same number of elements.
- `adjacent_find`: Returns an input iterator indicating the first of two identical adjacent elements in a sequence.
- `search`: Searches for a subsequence of elements within a sequence of elements.
- `search_n`: Searches a sequence of elements looking for a subsequence in which the values of a specified number of elements have a particular value.
- `partial_sort`: Use three random-access iterators to sort part of a sequence.
- `partial_sort_copy`: Use two input iterators and two random-access iterators to sort part of the sequence indicated by the two input iteraor arguments.
- `stable_sort`: The algorithm is similar to `sort` except that all equivalent elements are maintained in their original order.

### 22.9 Class `bitset`

- Class `bitset` makes it easy to create and manipulate **bit sets**. `bitset`s are fixed in size at compile time.
- `bitset<size> b;` creates `bitset b`, in which every bit is initially 0.
- `b.set(butNumber);` sets bit `bitNumber` of `bitset b` "on".
- `b.set();` sets all bits in `b` "on".
- `b.reset(bitNumber);` sets bit `bitNumber` "off".
- `b.reset();` sets all bits in `bitNumber` "off".
- `b.flip(bitNumber);` "flips" bit `bitNumber`.
- `b.flip();` "flips" all bits in `bitNumber`.

### 22.10 Function Objects

- Many STL algorithms allow you to pass a function pointer into the algorithm to help the algorithm perform its task.
- The STL's designers made the algorithms more flexible by allowing any algorithm that can receive a function pointer to receive an object of a class that overloads the parentheses operator with a function named `operator()`, provided that the overloaded operator meets the requirements of the algorithm. An object of such a class is known as a **function object** and can be used syntactically and semantically like a function or function pointer.
- Together, function objects and functions are known as **functors**. Most algorithms can use function objects and functions interchangeably.
- Function objects  provide several advantages over function pointers. Since function objects are commonly implemented as class templates that are included into each source code file that uses them, the compiler can inline an overloaded `operator()` to improve performance.
- Many predefined function objects can be found in the header `<functional>`:

| STL function object |    Type    |
|:--------------------|:----------:|
| `divides<T>`        | arithmetic |
| `equal_to<T>`       | relational |
| `greater<T>`        | relational |
| `greater_equal<T>`  | relational |
| `less<T>`           | relational |
| `less_equal<T>`     | relational |
| `logical_and<T>`    |  logical   |
| `logical_not<T>`    |  logical   |
| `logical_or<T>`     |  logical   |
| `minus<T>`          | arithmetic |
| `modulus<T>`        | arithmetic |
| ` negate<T>`        | arithmetic |
| `not_equal_to<T>`   | relational |
| `plus<T>`           | arithmetic |
| `multiplies<T>`     | arithmetic |

