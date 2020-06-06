## Chapter 19: Searching and Sorting

### 19.1 Introduction

- **Big O** notation is used to characterize an algorithm's worst-case runtime- that is, how hard an algorithm may have to work to solve a problem.

### 19.2 Searching Algorithms

- A searching algorithm finds an element that matches a given search key, if such an element does, in fact, exist. The major difference between different algorithms is the amount of effort they require to complete the search. One way to describe this effort is with Big O notation. For searching and sorting algorithms, this is particularly dependent on the number of data elements.

#### 19.2.1 Efficiency of Linear Search

- If an algorithm is independent of the number of vector elements, it is said to have a **constant runtime**, represented in Big O notation as **O(1)**. The number of comparisons is constant- it does not grow as the size of the vector increases. O(1) is often pronounced "on the order of 1" or more simply "order 1".
- An algorithm that requires a total of n-1 comparisons is said to be **O(n)**, also referred to as having a **linear runtime**. O(n) is often pronounced "on the order of n" or more simply "order n".
- If an algorithm grows as the square of n, it is considered to be **O(n^2)**, which is referred to as **quadratic runtime** and pronounced "on the order of n-squared" or more simply "order n-squared". O(n^2) algorithms tend to be easy to write.
- Sometimes the simplest algorithms perform poorly. Their virtue is that they're easy to program, test, and debug. Sometimes more complex algorithms are required to realize maximum performance.

#### 19.2.2 Binary Search

- The **binary search algorithm** is more efficient than the linear search algoithm, but it requires that the vector first be sorted. Each iteration tests the _middle value_ of the remaning portion of the vector. If the element does not match the search key, the algorithm eliminates half of the remaining elements. The algorithm ends either by finding an element that matches the search key or by reducing the subvector to zero size.

**Efficiency of Binary Search**

- In the worst-case scenario, a sorted vector of 1023 elements will take only 10 comparisons when using a binary search. The maximum number of comparisons needed for the binary search of any sorted vector is the exponent of the first power of 2 greater than the number of elements in the vector, which is represented as log2 n.
- All logarithms grow at roughly the same rate, so in Big O notation the base can be omitted. This results in a Big O of **O(log n)** for a binary search, which is also known as **logarithmic runtime** and pronounced "on the order of log n" or more simply "order log n".

### 19.3 Sorting Algorithms

- An important point to understand about sorting is that the end result -the sorted vector- will be the same no matter which algorithm you use to sort the vector. The choice of algorithm affects only the runtime and memory use of the program.

#### 19.3.1 Efficiency of Selection Sort

- Selection sort is an easy-to-implement, but inefficient, sorting algorithm. It has a Big O of O(n^2).

#### 19.3.2 Efficiency of Insertion Sort

- Insertion sort is another simple, but inefficient, sorting algorithm. It also has a Big O of O(n^2).

#### 19.3.3 Merge Sort (A Recursive Implementation)

- Merge sort is an efficient sorting algorithm but is conceptually more complex than selection sort and insertion sort. 
- The merge sort algorithm sorts a vector by splittng it into two equal-sized subvectors, sorting each subvector then _merging_ them into one larger vector. With an odd number of elements, the algorithm creates the two subvectors such that one has one more elment than the other.

**Efficiency of Merge Sort**

- Merge sort is a far more efficient algorithm than either insertion sort or selection sort. It has a total efficiency of **O(n log n)**.

| Algorithm               |                 Big O                 |
|:------------------------|:-------------------------------------:|
| Searching               |                                       |
| Linear search           |                 O(n)                  |
| Binary search           |               O(log n)                |
| Recursive linear search |                 O(n)                  |
| Recursive binary search |               O(log n)                |
| Sorting                 |                                       |
| Insertion sort          |                O(n^2)                 |
| Selection sort          |                O(n^2)                 |
| Merge sort              |              O(n log n)               |
| Bubble sort             |                O(n^2)                 |
| Quicksort               | Worst case O(n^2), average O(n log n) |

| n    | O(log n) | O(n) | O(n log n) | O(n^2) |
|:-----|:---------|:-----|:-----------|:-------|
| 2^10 | 10       | 2^10 | 2^10 x 10  | 2^20   |
| 2^20 | 20       | 2^20 | 2^10 x 20  | 2^40   |
| 2^30 | 30       | 2^30 | 2^10 x 30  | 2^60   |
