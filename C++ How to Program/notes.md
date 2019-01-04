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
 
 ## Chapter 9. Classes: A Deeper Look, Part 1

 ### Classes concepts
 - A "preprocessor wrapper" prevents the code in the header from being included into the same source code file more than once.
 - Client code can access a class's `public` members via three tpes of "handles": the name of an object, a reference to an object, or a pointer to an object.
 - Object names and references can be used with the dot (.) member selection operator to access a `public` member, and pointers can be  used with the arrow (->) member selection operator.
 - _Predicate functions_ are access functions that can read or display data in an object.
 - A utility function (or _helper function_) is a `private` member function that supports the operation of the class's `public` member functions, but is not intended for use by clients of the class.
 - Defaault arguments can be used in a constructor to enable client code to initialize objeccts using a variety of arguments.
 - A _destructor_ member function is part of every class and is used to perform "termination housekeeping" on an object before the object is destroyed.
 - A program's correctness depends of using properly unitialized objects that have not yet been destroyed.
- Using member functions that return a reference to `private` data is a dangerous practice. This _breaks the encapsulation of a class_.
- Ease each access specifier only once in a class definition. Place `public` members first, where they're easy to locate.
- Each element  of a class should have `private` visibility unless it can be proven that the element needs `public` visibility.
- Use #ifndef, #defne, and #endif preprocessor drectives to form a preprocessor wrapper that prevents headers from being included more than once in a program.
- You can define several _overloaded constructors_ for a class.
- With the exception of `static const int` data members, a class's data members cannot be initialized where they're declared in the class body.
- It's strongly recommended that these data members be initialized by the class's constructors as _there is no default initialization for fundamental-type data members_.
- Data members can also be assigned values by _set_ functions.
- Stream manipulator **`setfill`** specifies the **fill character** that's displayed when an integer is output in a field wider than the number of digits in the value. `setfill` is a "sticky" setting. `setw` is a "nonsticky" setting.
- Defining a member function inside the class definition inlines the member function (if the compiler chooses to do so). This can improve performance.
- Only the simplest and most stable member functions (i.e., whose implementations are unlikely to change) should be defined in the class header.
- Often, classes do not have to be created "from scratch". They can include objects or other classes as members or they may be **derived** from other classes that provide attributes and behaviours the new classes can use.
- Including class objects as members of other classes is called **composition** (or **aggregation**).
- Deriving new classes from existing classes is called **inheritance**.
- The compiler creates one copy (only) of the member functions separate from all objects of the class. All objects of the class _share_ this one copy.

### Class Scope and Accessing Class Members

- A class's data members (variables declared in the cclass definition) and member functions belong to that class's scope. Nonmeber functions are deffined at _global namespace scope_. 
- Outside a class's scope, `public` class members are referenced through one of the  **handles** on an object- an object name, a reference to an object or a pointer to an object.
- Member functions of a class can be overloaded, but only by other member functions of that class.
- To overload a member funcation, provide in the  class definition a prototype for each version of the overloaded function, and provide a separate ufunction definition for each version of the function. This also applies to the class's constructors.

### Separating Interface from Implementation

- The header for the class definition is the class's _interface_.
- The source fode file  for the class's member-function definitions is the _implementation_.

### Access Functions and Utility Functions

- **Access functions** can read or display data. **Predicate functions** are functions that test the truth or falsity of conditions.
- A **utility function** (also called a **helper function**) is _not_ part of a class's `public` interface. Rather, it's a `private` member  function that supports the operation of the class's other member functions. 

### Constructors with Default Arguments

- Constructors can specity _default arguments_.
- A constructor that defauls all its arguments is also a _default constructor_. There can be at most one default constructor per class.
- Any change to the default argument values of a function requires the client code to be recompiled.
- If a member function of a class already provides all or part of the functionality required by a constructor (or other member function) of the class, call that member function from the constructor (or other member function).

### Destructors

- The name of the destructor for a class is the **tilde character (~)** followed by the class name.
- A class's destructor is called _implicitly_ when an object is destroyed. 
- The destructor itself does not actually release the object's memory - it performs **termination housekeeping** before the object's memorey is reclaimed, so the memory may be reused to hold new objects.
- Every class has a destructor. If you do not explicitly provide a destructor, the compiler creates an "empty" destructor.

### When Constructors and Destructors are Called

- Generally, destructor calls are  made in the _reverse order_ of the corresponding constructor calls, but the storage classes of objects can alter the order in which destructors are called.

Constructors and Destructors for Objects in Global Scope

- Constructors are called for objects defined in global scope _before_ any other function (including `main`) in the file begins execution.
- The  corresponding destructors are called when `main` terminates.
- Function **`exit`** forces a program to terminate immediately and does _not_ execute the destructors of automatic objects.
- Function **`abort`** performs similarly to `exit` but forces the program to terminate _immediately_, without allowing the destructors of any objects to be called.

Constructors and Destructors for Local Automatic Objects

- The constructor for a local object is called when execution reaches the point where that object is defined. The corresponding destructor is called when execution leaves the object's scope.
- Constructors and destructors for automatic objects are called each time execution enters and leaves the scope of the object.
- Destructors are not called for automatic objects if the program terminates with a call to function `exit` or function `abort`.

Constructors and Destructors for `static` Local Objects

- The constructor for a `static` local object is called only _once_.
- The corresponding destructor is called when `maain` terminates or the program calles function `exit`.
- Global and `static` objects are destroyed in the _reverse_ order of their creation.
- Destructors are _not_ called for `static` objects if the program terminates with a call to function `abort`.

### Returning a Reference to a `private` Data Member

- (!) A `public` member function of a class  can return a reference to a `private` data member of that  class. The function call can be used in any way that the `private` data member can be used, including as an _lvalue_ in an assignment statement, thus _enabling clients of the class to clobber the class's `private` data at will!_ The  same problem would occur if a pointer to the `private` data were to be returned by the function.
- Returning a reference or a pointer to a `private` data member breaks the encapsulation of the class and makes the client code dependent on the representation of the class's data; this is a dangerous practice that should be avoided.

### Default Memberwise Assignment

- The assignment operator (`=`) can be used to assign an object to another object of the same type. By default, each data member of the object on the right of the assignment operator is assigned individually to the _same_ data member in the object on the left of the assignment  operator.
- Memberwise assignment can cause serious problems when used with a clss whose data members contain pointers to dynamically allocated memory.
- Objects may be passed as function arguments and  may be returned from functions. Such passing and returning is performed using pass-by-value by default: a copy of the object is passed or returned. In such cases, C++ creates a new object and uses a **copy constructor** to copy the original object's values into the new object. Copy constructors can case serious problems when used with a class whose data members contain pointers to dynamically allocated memory.
- Passing an object by value is good from a security standpoint, but pass-by-value can degrade performance when making a copy of a large object.
- Pass-by-`const`-reference is a safe, good-performing alternative. This can be immplemented with a `const` reference parameter or with a pointer-to-`const`-data parameter.

## Chapter 10. Classes: A Deeper Look, Part 2

### const (Constant) Objects and const Member Functions

- You masy use keyword `const` to specify that an object _is not_ modifiable and that any attempt to modify the object  should result in a compilation error. 
- The statement ```const Time noon(12, 0, 0);``` declares  a `const` object noon of class `Time` and initializes it to 12 noon.
- Declaring variables and objects `const` when appropriate can improve performance- compilers can perform optimizations that cannot be performed on variables.
- C++ disallows member function calls for `const` objects unless the member functions themselves are also declared `const`, even for _get_ functions that do not modify the object.
- A member function is specified as `const` _both_ in its prototype by inserting the keyword `const` after the  function's parameter list and, in the case of the function definition, before the left brace that begins the function body.
- A `const` member function can be overloaded with a non-const version. The compiler chooses which overloaded member function to use based on the object on which the function is invoked.
- A constructor _must_ be allowed to modify an object so that the object can be initialized properly. A destructor must be able to perform its temination housekeeping chores before an obect's memory is reclaimed by the system.
- Attempting to declare a constructor or destructor `const` is a compilation error.
- A constructor must be a non-constant member function, but it can be used to initialize a `const` object. The "constness" of a `const` object  is enforced fom the time the constructor _completes_ initialization of the object until that object's destructor is called.
- All data members _can_ be initialized using **member initializer syntax**, but `const` data members and data members that are references _must_ be initialized using member initializers.
- Member _initializers_ appear between a constructor's parameter list and  the left brace that begins the constructor's body. The member initializer list is separated from the parameter list with a colon (:). Each initializer consists of the data member name followed by parentheses containing the member's initial value. Multiple initializers are separated by commas.
- The member initializer list executes _before_ the body of the constructor executes.
- Declare as `const`  all of a class's member functions that  do not modify the object in which they operate. If the member function is inadvertently written to modify the object, the compiler will issue an error message.
- Not providing a member initializer for a `const` data member is a compilation error.

### Composition: Objects as Members of Classes

- A class can have objects of other classes as members. This is called **composition** and is sometimes referred to as a **has-a relationship**.
- An object's constructor can pass arguments to member-object constructors via  member initializers.
- Member objects  are  constructed in the  order in which they're declared in the class definition (not in the order they're listed in the constructor) and before their enclosing class objects (sometimes called host objects) are  constructed.
- If a member object is _not_ initialized through a member initializer, the member object's default constructor will be called implicitly. Values, if any, established by the default constructor can be overridden by _set_ functions.
- A compilation error occurs if a member object is not initialized with a member initializer and the member object's class does not provide a default constructor (i.e., the member object's class defines one or more constructors but none is a default constructor).
- Initialize member objects explicitly through member initializers. This eliminates the overhead of "doubly initializing" member objects.
- Member objects of class types should still be private, like all other data members.

### `friend` Functions and `friend` Classes

- A **`friend` function** of a class is defined outside that class's scope, yet has the right to access the non-public (and public) members of the class. Standalone functions, entire classes or member functions of other classes may be declared to be friends of another class. 
- Using `friend` functions can enhance performance.
- To declare a function as a friend of a class, precede the function prototype in the class definition with keyword `friend`.
- To declare all member fuctions of class `ClassTwo` as friends of class `ClassOne`, place a declaration of the form
  ```
  friend class ClassTwo;
  ```
  in the definition of class `ClassOne`.
- Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
- Member access notions of `private`, `protected`, and `public` are not relevant to `friend` declarations, so friend declarations can be placed anywhere in a class definition.
- Place all friendship declarations first inside the class definition's body and do not precede them with any access specifier.
- Friendship is granted, _not_ taken. Class A must explicitly declare that class B  is its `friend`.
- Friendship is neither symmetric nor transitive.
- It is possible to specify overloaded functions as friends of a class. Each function intended to be a friend must be explicitly declared in the class definition as a friend of the class.

### Using the `this` Pointer

- Every object has access to its own address through a pointer called `this` (a C++ keyword).
- The `this` pointer is _not_ part of the object itself. The `this` pointer is passed by the compiler as an _implicit_ argument to each of the object's non-`static` member functions.
- One interesting use of the `this` pointer is to prevent an object from being assigned to itself.
- Another use of the `this` pointer is to enable **cascaded member-function calls** -that is, invoking multiple functions in the same statement.

### 10.6 `static` Class Members

- In certain cases, only _one_ copy of a variable should be _shared_ by _all_ objects of a class. A **`static` data member** is used for these and other reasons. Such a variable represents "class-wide" information.
- Use `static` data members to save storage when a single copy of the data for all objects of a class will suffice.
- A class's `static` data members have class scope, and they can be declared `public`, `private`, or `protected`.
- A fundamental-type `static` data member is initialized by default to 0, and it can be initialized _once_.
- A `static const` data member of int or enum type can be initialized in its declaration in the class definition, but all other `static` data members must be defined _at global namespace scope_ (outside the body of the class definition) and can be initialized in those definitions.
- A class's `private` and `protected static` members are normally accessed through the class's public member functions or `friend`s. A class's `static` members exist even when no objects of that class exist. To access a `public static` class member when no objects of the class exist, simply prefix the class name and he scope resolution operator (::) to the name of the data member.
- To access a `private` or `protected static` class member when no objects of the class exist, provide a `public` **`static` member function** and call the function by prefixing its name with the class name and scope resolution operator.
- A static member function is a service of the class, not a specific object of the class.
- A class's `static` members and member functions exist and can be used even if no objects of that class have been instantiated.
- A member function should be declared `static` if it does _not_ access non-`static` data members or member functions of the class.
- A `static` member function does not have a `this` pointer, because `static` data members and member functions exist independently of any object of a class.
- Using the `this` pointer in a `static`  member function is a compilation error.
- Declaring a `static` member function `cnost` is a compliation error.

### 10.7 Proxy Classes

- A proxy class allows you to hide even the `private` data of a class from clients of the class.
- When a class definition uses only a pointer or reference to an object of another class, the class header for htat other class is _not_ required to be included with `#include`. The compiler doesn't need to reserve space for an _object_ of the class, but it _does_ need to reserve space for the _pointer_ or _reference_.
- A proxy class insulates client code from implementation changes.
