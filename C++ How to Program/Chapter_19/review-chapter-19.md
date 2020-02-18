**19.1** Fill in the blanks:

a. A selection sort application would take approximately _16_ times as long to run on a 128-element vector as on a 32-element vector.

b. The efficiency of merge sort  is  _O( n log n )_.

**19.2** What key aspect of both the binary search and the merge sort accounts for the logarithmic portion of their respective Big Os?
They both incorporate "halving". The binary search eliminates from consideration half of the vector after each comparison. The merge sort splits the vector in half each time it's called.

**19.3** In what sense is the insertion sort superior to the merge sort? In what sense is the merge sort superior to the insertion sort?
The insertion sort is easier to implement and debug. The merge sort is more efficient for larger vector sizes.

**19.4** In the text, we say that after the merge sort splits the vector into two subvectors, it then sorts these two subvectors and merges them. Why might someone be puzzled by our statement "it then sorts these two subvectors"?
Because the statement implies the reader understands that once the algorithm reaches the  one-element subvectors, it returns a "sorted" two-element one.

