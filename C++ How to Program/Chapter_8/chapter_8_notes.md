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

### Pointer Expressions and Pointer Arithmetic

- C++ enables **pointer arithmetic**- certain arithmetic operations may be performed on pointers.
- A pointer may be incremented (++) or decremented(--), an integer may be added to a pointer (+ r +=), an intege may be subtracted from a pointer (- or -=), or one pointer may be subtracted from another of the same type.
- A pointer can be assigned to another pointer if both pointers are of the _same_ type. Otherwise, a cast operator (normally a `reinterpret_cast`) must be used to convert the value of the pointer on the right of the assignment to the pointer type on the left of the assignment. The exception to this rule is the **pointer to `void`**, which is a generic pointer capable of representing _any_ pointer type.
- Nonconstant pointer arguments can be passed to constant pointer parameters.

### Relationship Between Pointers and Arrays

- Arrays and pointers are intimately related in C++ and may be used  _almost_ interchangeably. An array name can be thought of as a constant pointer. Pointers can be used to do any operation involving array subscripting.
- The array name (which is implicitly `const`) can be treated as a pointer and used in pointer arithmetic.
- Although array names are pointers to the beginning of the array, array names cannot be modified in artihmetic expressions, because array names are constant pointers. 

### Pointer-Based String Processing

- C++'s `string` class is preferred for use in new programs, because it eliminates many of the security problems and bugs that can be caused by manipulating C strings.
- A **character constant** is an integer value represented as a character in single quotes. For example, 'z' represents the integer value of z (122 in the ASCII character set), and '\n' represents the integer value of new-line (10 in the ASCII character set).
- A string is a series of characters treated as a single unit. A string may include letters, digits, and various special characters.
- **String literals**, or **string constants**, in C++ are written in double quotation marks.
- A pointer-based string is an array of characters ending with a **null character** (**'\0'**), which marks where the string terminates in memory.
- A string literal may be used as an initializer of either a character array or a variable of type `char *``.
- String literals have `static` storage class (they exist for the duration of the program).
- The effect of modifying a sstring literal is _undefined_: you should always declare a pointer to a string literal as `const char *`.
- A string can be read into a character array using stream extraction with `cin`. For example, the following statement reads a string into character array `word[20]`:
- ```cin >> word;```
- The `cin` object provides  the member function **getline**, which takes three arguments- a character array in which the line of text will be stored, a length, and a delimiter character.
- A character array representing a null-terminated string can be output with `cout` and `<<`. The characters of the string are output until a terminating null character is found.

### Arrays of Pointers

- A commun use of an array with pointers is to form an array of pointer-base strings, referred to simply as a **string array**.
- String arrays are commonly used with **command-line arguments** that are passed to function `main` when a program begins execution.

### Function Pointers

- A **pointer to a function** contains the function's address in memory. Pointers to functions can be passed to functions, returned to functions, stored in arrays, assigned to other function pointers and used to call the underlying function.
- An example of a function prototype parameter would be:
- ```bool (*)(int, int)```
- This indicates a pointer to a function that receives two integers as parameters and returns a boolean type.
