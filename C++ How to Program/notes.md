## Chapter 7

- An array is a consecutive group of memory locations that all have the same _type_.
- A subscripted array name is an _lvalue_.

### Initializing
- Automatic arrays are not implicitly initialized to zero, but static arrays are.
- Elements of an array can be initialized in the array declaration by following the array name with an equals sign and a brace-delimited comma-separated list of _initializers_.
- If there are fewer initializers than array elements, the remaining elements are initialized to 0.
- If the array size is omitted from a declaration with an initializer list, the compiler sizes the array automatically.
- Constant variables _must_ be initialized when they are declared and  _cannot_ be modified thereafter.
- Only constant variables can be used to declare the size of automatic and static arrays.
- C++ has no array bounds checking to prevent the computer from referring to an element that does not exist. 
- A `static` local variable in a function definition exists for the duration of the program but is visible only in the function's body.
- A `static` local variable is not created  and initialized each time the program calls the function. This can improve performance, especially with large arrays.
- A `static` array's elements are initialized to zero if they are not explicitly initialized.

### Passing Arrays to Functions
- Specify the name of the array without any brackets.
- For array  
`int hourlyTemperatures[24]`  
  the function call `modifyArray(hourlyTemperatures, 24)`  
passes the array and its size to function `modifyArray`.
- C++ passes arrays to functions by reference. The value of the name of the array is the address in the computer's memory of the first element of the array.
- Passing arrys  by value would require copying each element (impacting performance).
- It's possible to pass an array by value by simply embedding it as a data member of a class and passing an object of the class, which defaults to pass-by-value.
- The function's parameter list must specify that the function expects to receive an array:  
`void modifyArray(int b[], int arraySize)`
- When a function specifies an array parameter that's preceded by the `const` qualifier, the elements of the array become constant in the function body and any attempt to modify an element of the array in the function body results in a compilation error.
- Data members in a class: each object of a class maintains its own copy of an attribute.
- _Static_ data members (class variables): all objects of a class share one copy of the data member.

### Linear Search
- The linear search compares each element of an array with a search key.
- On average, the program must compare the search key with half the  elements of the array.
- To determine that a value is not in the array, the program must compare the search key to every element of the array.
- Linear search works well for small arrays or for unsorted arrays.

### Insertion Sort
- Sorting data is one of the most important computing applications.
- Insertion sort is a simple but inefficient sorting algorithm (easy to program, but runs slowly).
