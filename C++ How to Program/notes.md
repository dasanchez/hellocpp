## Chapter 7

- An array is a consecutive group of memory locations that all have the same _type_.
- A subscripted array name is an _lvalue_.

### Initializing Arrays
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

### Multidimensional Arrays
- Arrays with two dimensions (subscripts) often represent tables of calues consisting of information arranged in rows and columns.
- To identify a particular table element, we must specify two subscripts.
- An array with m rows and n columns is called an _m-by-n array_.
- Any elements that do not have an explicit initializer are initialized to zero.
- The size of a two-dimensional array's is not required as an argument, but all subsequent dimension sizes are required.

### Intro to C++ Standard Library Class Template `vector`
- The `vector` template is a more robust type of array featuring many additional capabilities.
- By default, all the elements of each vector object are set to 0.
- Vectors can be defined to store any data type.
- Member function `size` of class template `vector` returns the number of elements in a vector as a value of type `size_t` (which represents the type `unsigned int` on any systems).
- The assignemnt (=) operator can be use with vector objects.
- The equality (=) and inequality (!=) operators can also be used with vector objects.
- Square brackets ([]) can be used to access and modify vector elements.

### Exception handling
- Exception handling enabes you to create fault-tolerant programs that can resolve (or handle) exceptions.
- When a function detects a problem, such as an invalid array subscript or an invalid argument, it throws an exception.
- To handle an exception, place any code that might throw an exception in a `try` statement. The `try` block contains the code that might _throw_ an exception, and the `catch` block contains the code that _handles_ the exception if one occurs.
- The `vector` member function `at` provides bounds checking and throws an exception if its argument is an invalid subscript.
- An unmodifiable _lvalue_ is an expression that identifies an object in memory (such as an element in a vector), but cannot be used to modify that object.

### Bucket Sort
- The bucket sort provides better performance than an insertion sort, but requires much more memory. The insertion sort requires space for only one additional element of data, but the  bucket sort requires 10 times the size of the array being sorted. 
- The bucket sort algorithm works as follows:
1. Set up an array of empty buckets (or arrays)
2. Distribution (or scatter) pass: Go over the original array, putting each object in its bucket.
3. Sort each non-empty bucket.
4. Gather pass: Visit the buckets in order and put all elements back into the original array.

## Chapter 8

### Pointer Variable Declarations and Initialization

- Pointer variables contain _memory addresses as their values. Normally, a variable directly contains a specific value. A pointer contains the memory address of a variable that, in turn, contains a specific value. 
- A variable name **directly references a value**, and a pointer **indirectly references a value**.
- Referencing a value through a pointer is called **indirection**.
- Pointers _must_ be declared before they can be used.
- Pointers  should be initialized to 0, `NULL`, or an address of the corresponding type either when they're declared or in an assignment.
- A pointer with the value 0 or `NULL` "points to nothing" and is known as a **null pointer**.
- You should use the constant `nullptr` to initialize a pointer  instead of 0 or `NULL` in the new standard.

### Pointer Operators

- The **address operator (&)** is a unary operator that _obtains the memory address of its operand_.
- This operator is not the same as the use of & in a reference variable declaration, which is always preceded by a data-type name. When declaring a reference, the & is part of the type.
- The **\* operator**, commonly referred to as the **indirection operator** or **dereferencing operator**, _returns a synonym for the object to which its pointer operand points_.

### Pass-by-Reference with Pointers

- There are three ways in C++ to pass arguments to a function--pass-by-value, **pass-by-reference with reference arguments**, and **pass-by-reference with pointer arguments**.
- You can use  pointers and the indirection operator (*) to accomplish pass-by-reference.
- A function receiving an address as an argument must define a pointer parameter to receive the address.
- Use pass-by-value to pass arguments to a function unless the caller _explicitly_ requires that the called function directly modify the value of the argument variable in the caller. This is an example of the principle of least privilege.
- The compiler does not differentiate between a function that receives a pointer and a function that receives a one-dimensional array.

### Using `const` with Pointers

- Let the  principle of least privilege be your guide: Always give a function enough access to the data in its parameters to accomplish its specified task, _but no more_.
- If a value does not (or should not) change in the body of a function to which it's passed, the parameter should be declared `const`.
- Before using a function, check its prototype to determine the parameters that it can and cannot modify.

- There are four ways to pass a pointer to a function:

**1. Nonconstant Pointer to Nonconstant Data**

- Highest access is granted. The data can be modified through the dereferenced pointer, and the pointer can be modified to point to other data.

**2. Nonconstant Pointer to Constant Data**

- A pointer that can be modified to point to any data item of the appropriate type, but the data to which it points cannot be modified through that pointer.

- ``` const int *countPtr;```

- Pass large objects using pointers to constant daata, or references to constant data, to obtain the security of pass-by-value.

**3. Constant Pointer to Nonconstant Data**

- A pointer that always points to the same memory location; the data at that location _can_ be modified through the pointer.

- ``` int *  const ptr = &x; // const pointer  must be initialized```

- An example of such a pointer is an array name, which is a constant pointer to the beginning of the array.

**4. Constant Pointer to Constant Data**

- Minimum access privilege is granted. Such a pointer _always_ pointer so the _same_ memory location, and the data at that location cannot be modified via the pointer.
- This is how an array should be passed to a function that _only reads_ the array, using array subscipt notation, and _does not modify_ the array.

- ```const int *const ptr = &x;```

### Selection Sort Using Pass-by-Reference

- When passing an array to a function, also pass the size of the array (rather than building into th efunction knowledge of the array size) - this makes the function more usable.

### `sizeof` Operator

- The compile time unary operator `sizeof` determines the size of an array (or of any other data type, variable, or constant) in bytes during program compilation.
- When applied to the _name_ of an array, the `sizeof` operator returns the _total number of bytes in the array_ as a value of type `size_t`. 
- When applied to a pointer parameter in a function that receives an array as an argument, the `sizeof` operator returns the size of the pointer in bytes - _not_ the size of the array.
- The number of bytes used to store a particular data type may vary among systems. When writing programs that depend on data type sizes, and that will run on several computer systems, use `sizeof` to determine the number of bytes used to store the data types.
