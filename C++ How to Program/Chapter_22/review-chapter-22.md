State whether the following are true or false or fill in the blanks:

**21.1** (T/F): The STL makes abundant use of inheritance and `virtual` functions.

False. These were avoided for performance reasons. The STL uses class templates for containers, iterators, and algorithms.

**22.2** The two types of first-class STL containers are sequence containers and _associative_ containers.

**22.3** The five main iterator types are: _random-access_, _input_, _output_, _forward_, and _bidirectional.

**22.4** (T/F) An iterator acts like a pointer to an element.

True.

**22.5** (T/F) STL algorithms can operate on C-like pointer-based arrays.

True.

**22.6** (T/F) STL algorithms are encapsulated as member functions within each container class.

False. Algorithms are separate from containers and operate on iterators, and are not member functions.

**22.7** (T/F) When using the `remove` algorithm on a `vector`, the algorithm does not decrease the size of the `vector` from which elements are being removed.

True.

**22.8** The three STL container adapters are _stack_, _queue_, and _priority_queue_.

**22.9** (T/F) Container member function `end` yields the position of the container's last element.

False. It yields an iterator pointing to the position just after the end of the container.

**22.10** STL algorithms operate on contianer elements indirectly, using _iterators_.

**22.11** The `sort` algorithm requires a _random-access_ iterator.