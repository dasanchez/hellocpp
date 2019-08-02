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
- The corresponding destructor is called when `main` terminates or the program calles function `exit`.
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

## Chapter 11. Operator Overloagin; Class string

### 11.1 Introduction

- A process called **operator overloading** allows C++'s operators to work with class objects.
- An example of an overloaded operator built into C++ is `<<`, which is used _both_ as the stream insertion operator _and_ the bitwise left-shift operator.
- You can overload _most_ operators to be used  with class objects.

### 11.2 Using the Overloaded Operators of Standard Library Class `string`

- Class `string`  provides  member  function `empty` to determine whether a `string` is empty. Returns `true` if  the string empty and `false` otherwise.
- A string literal can be appended to a `string` object by using operator `+=`.
- Class `string` provides member function `substr` to return a portion of a string as a `string` object.
- The overloaded `=` operator handles _self-assignment_ properly. Self-assignment can be dangerous.
- Class `string`'s overloaded `[]` operator does not perform any bounds checking. Class `string` _does_ provide  bounds checking in its member function **at**, which throws an exception if its argument is an invalid subscript. If the subscript is valid, function `at` returns the character at the specified location as a modifiable _lvalue_.
- Function `at` returns the character at a specific index in a string (after checking that the index is in range).

### 11.3 Fundamentals of Operator Overloading

- C++ does not allow new operators to be created, but it allows most existing operators to be overloaded so they have meaning appropriate to the objects they are used with.
- Operator overloading is not automatic.
- An operator is overloaded by writing a non-`static` member function definition or non-member function definition, with a name starts with the keyword `operator` followed by the symbol for the operator being overloaded.
- For example, the  numfction name `operator+` would be used to overload the addition operator (`+`) for use  with objeacts of a particular class.
- When operators are overloaded as membr functions, they must be non-`static`, because they must be called on an object of the class and operate on that objects.
- To use an operator on an object of a class, the operator must be overloaded for that class, with three exceptions:
  - The assignment operator (=) may be used with _every_ class to perform memberwise assignment of the class's data members.
  - The address (&) operator returns a pointer to the object; this operator can also be overloaded.
  - The comma operator evaluates the expression to its left then the expression to its right, and retuurns the value of the latter expression. This operator also can be overloaded.
- **Rules and Restrictions on Operator Overloading**:
  - The precedence of an operator cannot be changed by overloading. Parentheses can be used to force the order of evaluation, however.
  - The associativity of an operator cannot be changed by overloading.
  - You cannot change the "arity" of an operator (i.e., the number of  operands an operator takes).
  - You cannot create new operators.
  - The meaning of how an operator works on values of fundamental types cannot be changed by operator overloading.
  - Related operators, like  `+` and `+=`, must be overloaded separately.
  - When overloading `()`, `[]`, `->`, or any of the assignment operators, the operator overloading function _must_ be declared as a class member.

### 11.4 Overloading Binary Operators

- A binary operator can be overloaded as a non-`static` member function with one parameter of as a non-member function with two parameters (one of those parameters must be either a class object or a reference to a class object).
- A non-member operator function is often declared as `friend`` of a class for performance reasons.
- **Binary Overloaded Operators as Member Functions**
  - Consider using `<` to compare two objects of a `String` class that you define. When overloading binary operator `<` as a non-`static` member function of a `String` class, if `y` and `z` are `String`-class objects, then `y < z` is treated as if `y.operator<(z)` had been written:
  ```
  class String
  {
    public:
      bool operator<( const String & ) const;
      ...
  } // end class String
  ```
  - Overloaded operator functions for binary operators can be member functions _only_ when the _left_ operand is an object of the class in which the function is a a member.
- **Binary Overloaded Operators as Non-Member Functions**
  - As a non-member function, binary operator `<` must take two arguments- one of which must be an object (or a reference to an object) of the class. If `y` and `z` are `String`-class objects or refencces to `String`-class objects, then `y < z` is treated as the call `operator<(y, z)` had been written in the program:
  ```
  bool operator<( const String  &, const String & ) const;
  ```
- It's possible to overload an operator as a non-member, non-`friend` function, but such a function requiring access to a class's `private` or `protected` data would need to use `set` or `get` functions provided in that class's `public` interface. The overhead of calling these functions would cause poor performance, so these functions can be inlined to improve performance.

### 11.5 Overloading the Binary Stream Insertion and Stream Extraction Operators

- You can input and output fundamental-type data using the stream extraction operator `>>` and the stream insertion operator `<<`. 
- The C++ class libraries overload these binary operators for each fundamental type, including pointers  and `char*` strings.
- You can also overload these operators to perform input and output for our own types.
- When used with `cin` and `string`s, `setw` restricts the number of characters read to the number of characters specified by its argument.
- `istream` member `ignore` discards the specified number of characters in the input stream (one character by default).
- Overloaded operators should mimic the functionality of their built-in counterparts- for example, the `+` operator should be overloaded to perform addition, not subtraction. 
- Avoid excessive or inconsistent use of operator overloading, as this can make a program cryptic and difficult to read.
- Returning a reference from an overloaded  << or >> operator function is typically successful because `cout`, `cin` and most stream objects are global, or at least long-lived. Returning a reference to an automatic variable or other temporary objects is dangerous- this can create "dangling references" to nonexisting objects.
- Overloaded operator functions for binary operators can be member functions only when the left operand is an object of the class in which the function is a member.
- Overloaded input and output operators are declared as `friend`s if they need to access non-`public` class members directly for performance reasons or because they class may not offfer appropriate get functions.

### 11.6 Overloading Unary Operators

- A unary operator for a class can be overloaded as a non-`static` member function with no arguments or as a non-member function with one argument that must be an object (or a reference to an object) of the class.
- Member functions that implement overloaded operators must be non-`static` so thay they can access the non-`static` data in each object of the class.
- **Unary Overloaded Operators as Member Functions**
  - When a unary operator such as `!` is overloaded as a member function with no arguments and the compiler sees the expression `!s` (in which `s` in an object of the class `String`), the  compiler generatess the function call s.operator!(). The function is declared as follows:
  ```
  class String
  {
    public:
      bool operator!() const;
  }; // end class String
  ```
- **Unary Overloaded Operators as Member Functions**
  - A unary operator such as `!` may be overloaded as a non-member function with one parameter in two different ways- either with a parameter that's an object, or with a parameter that's a reference to an object. 
  - If `s` is a `String` class object (or a reference) to a `String` class object), then `s` is treated as if the call `operator!(s)` had been written, invoking the non-member `operator~` function that's declared as follows:
  ```
  bool operator!( const  String &);
  ```

### 11.7 Overloading the Unary Prefix and Postfix ++ and -- Operators

- To overload the prefix and postfix increment operators, each overloaded operator function must have a distinct signature, so that the compiler will be able to determine which version of ++ is intended.

- **Overloading the Prefix Increment Operator**
  - Suppose we want to add 1 to the day in `Date` object `d1`. When the compiler sees the preincrementing expression `++d1`, the compiler generates the _member-function call_
  ```
  d1.operator++()
  ```
  - The prototype for this operator member function would be
  ```
  Date &operator++();
  ```
  - If the prefix increment operator is implemented as a _non-member function_, then, when the compiler sees the expression `++d1`, the compiler generates the function call
  ```
  operator++(d1)
  ```
  - The prototype for this non-member operator function would be declares as
  ```
  Date &operator++(Date &);

- **Overloading the Postfix Increment Operator**
  - The compiler must be able to distinguish between the signatures of the overloaded prefix and postfix increment operator functions. The _convention_ that has been adopted is that, when the compiler sees the postincrementing expression `d1++`, it generates the _member-function call_
  ```
  d1.operator++(0)
  ```
  - The prototype for this operator member function is
  ```
  Date operator++(int)
  ```
  - The argument 0 is strictly a "dummy value" that enables the compiler to distinguish between the prefix and postfix increment operator functions. The same syntax is used to differentiate between the prefix and postfix decrement operator functions.
  - If the postfix increment is implemented as a _non-member function_, then, when the compiler sees the expression `d1++`, the compiler generates the function call
  ```
  operator++(d1, 0)
  ```
  The prototype for this function would be
  ```
  Date operator++(Date &, int);
  ```
  - The _postfix increment operator_ returns `Date` objects by `value`, whereas the prefix increment operator returns `Date` objects _by reference_- the postfix increment operator typically returns a temporary object that contains the original value of the object before the increment occurred. C++ treats such objects as _rvalues_, which _cannot be used on the left side of an assignment_. The prefix increment operator returns the actual incremented object with its new value. Such an object _can_ be used as an _lvalue_ in a continuing expression.
- The extra object that's created by the _postfix_ increment (or decrement) operator can result in a performance problem- especially when the operator is used in a loop. For this reason, you should prefer the overloaded _prefix_ increment and decrement operators. 

### 11.8 Case Study: A `Date` Class

- The `Date` class uses  overloaded prefix and postfix increment operators to add 1 to the day in a `Date` object, while causing appropriate increments to the month and year if necessary. 
- **Date Class Prefix Increment Operator**
  - The prefix increment operator calls utility function `helpIncrement`.
  - The overloaded prefix increment operator returns a reference to the current `Date` object (the one that was just incremented). This occurs because the current object, `*this`, is returned as a `Date&`. This enables a preincremented `Date` object to be used as an _lvalue_, which is how the built-in prefix increment operator works for fundamental types.
- **Date Class Postfix Increment Operator**
  - To emulate the effect of the postincrement, we must return an unincremented copy of the `Data` object.
  - On entry to `operator++`, we save the  current object (`*this`) in `temp`. Next, we call `helpIncrement` to increment the current `Date` object. Then, we return the unincremented copy of the object previously stoored in `temp`. This function cannot return a reference to the local `Date` object `temp`, because a local variable is destroyed when the function in which it's declared exits. Thus, declaring the return type to this function as `Date&` would return a reference to an object that no longer exists.
  - Returning a reference (or a pointer) to a local variable is a common error for which most compilers will issue a warning.

### 11.9 Dynamic Memory Management

- A standard C++ array data structure is fixed in size once it's created. The size is specified with a constant at compile time.
- Sometimes it's useful to determine the size of an array _dynamically_ at execution time and then create the array.
- C++ enables you to control the allocation and deallocation oof memory in a program for objects and for arrays for any built-in or user-defined type. This is known as **dynamic memory management** and is performed with the operators **`new`** and **`delete`**. 
- You can use the `new` operator do cynamically **allocate** the exact amount of memory required to hold and object or array at execution time.
- The object or array is created in the **free store** (also called the **heap**)- a _region of memory assigned to each program for storing dynamically allocated objects_.
- Once memory is allocated in the free store, you can access it via the pointer that operator `new` returns.
- When you no longer need the memory, you can return it to the free store by using the `delete` operator to **deallocate** the memory, which can then be reused by future `new` operations.
- **Obtaining Dynnamic Memory with `new`**
  - Consider the following statement:
  ```
  Time *timePtr = new Time;
  ```
  - The `new` operator allocates storage of the proper size for an object of type Time, calls the default constructor to intialize the object, and returns a pointer to the type specified  to the right of the `new` operator (a `Time *`). If `new` is unable  to find sufficient space in memroy for the object, it indicates that a error occurred by throwing an exception.
- **Releasing Dynamic Memory with `delete`**
  - To destroy a dynamically allocated object and free the space for the object, use the `delete` operator as follows:
  ```
  delete timePtr;
  ```
  - This statemenet calls the destructor for the object to which `timePtr` points, then deallocates the memory associated wiith the object, returning the memory to the free store.
- Not releasing dynamically allocated memory when it's no longer needed can cause the system to run out of memory prematurely. This is sometimes called a "memory leak".
- **Initializing Dynamic Memory**
  - You can provide an initializer for a newly created fundamental-type variable, as in
  ```
  double *ptr = new double(3.14159);
  ```
  which initializes a newly created `double` to 3.14159 and assigns the  resulting pointer to `ptr`. The same syntax can be used to specify a comma-separated list of arguments to the constructor of an object:
  ```
  Time *timePtr = new Time(12, 45, 0);
  ```
  initializes a new `Time` object to 12:45 PM and assigns the resulting pointer to `timePtr`.
- **Dynamically Allocating Arrays with `new[]`**
  - YOu can also use the `new` operator to allocate arrays dynamically. For example, a 10-element integer array can be allocated and assigned to `gradesArray` as follows:
  ```
  int *gradesArray = new int[ 10 ];
  ```
  which declares `int` pointer `gradesArray` and assigns it to a pointer to the first element of a dynamically allocated 10-element array of `int`s.
  - The size of an array created at compile time must be specified using a constant integral expression; however, a dynamically allocated array's size can be specified using _any_ non-negative integral expression that can be evaluated at execution time.
  - When allocating an array of objects dynamically, you canot pass arguments to each object's constructor- each object is initialized by its default constructor. For fundamental types, the elements are initialized to 0 or the equivalent of 0 (`char`s are initialized to the null character, `\0`). 
  - Since an array name is a constant pointer to the array's first element, the following is not allowed for dynamically allocated memory:
  ```
  int gradesArray[] = new int[ 10 ];
  ```
- **Releasing Dynamically Allocated Arrays with `delete[]`**
  - To deallocate the memory to which `gradesArray` points, use the statement
  ```
  delete [] gradesArray;
  ```
  - If the pointer points to an array of objects, the statement first calls the destructor for every object in the array, then deallocates the memory.
  - If the preceding statement did not include the square brackets ([]) and gradesArray pointed to an array of objects, the result is _undefined_.
  - Some compilers call the destructor only for the first object in the array. Using `delete` on a null pointer (a pointer with the value of 0) has no effect.
- Using `delete` instead of `delete []` for arrays of objects can lead to runtime logic errors. To ensure that every object in the array receives a destructor ccall, always delete memory allocated as an array with operator `delete []`. Similarly, always delete memory allocated as an individual element with operator `delete`- the result of deleting a single object with operator `delete[]` is undefined.

### 11.10 Case Study: `Array` Class

- An array is not much more than a pointer to some space in memory.
- Pointer-based arrays have many problems, including:
  - A program can easily "walk off" either end of an array, because C++ does not check whether subscripts fall outside the range of an array.
  - Arrays of size n must number their elements  0, ..., n-1; alternate subscripts are not allowed.
  - An entire array cannot be input or output at once; each array element must be read or written individually (unless the array is a null-terminated `char *` string).
  - Two arrays cannot be meaningfully compared with equality or relational operators, because the array names are simply pointers to where the arrays begin in memory and to arrays will always be at different memory locations.
  - When an array is passed to a general-purpose function designed to handle arrays of any size, the array's _size_ must be passed as an additional argument.
  - One array cannot be assigned to another with the assignment operator(s), because array names are `const` pointers and a _constant_ pointer cannot be used on the left side of an assignment operator.
- In this example, we create an `Array` class that performs range checking.
- The class allows one array object to be assigned to another with the assignment operator. The size does not need to be passed separately to functions that receive `Array` parameters.
- Entire `Array`s can be input or output with the stream extraction and stream insertion operators, respectively.
- You can compare `Array`s with the equality operators `==` and `!=`.
- The C++ Standaard Library class template `vector` provides many of these capabilities as well.

#### 11.10.1 Using the `Array` Class

- The array subscript operator [] is not restricted for use only with arrays; it also can be used, for example, to select elements from other kinds of _container classes_, such as linked lists, strings, and dictionaries.
- When overloaded `operator[]` functions are defined, subscripts no longer have to be integers- characters, strings, or even objects of user-defined classes also coud be used.

#### 11.10.2 `Array` Class Definition

- Each `Array` object consists of a `size` member indicating the number of elements in the `Array` and an `int` pointer -`ptr`- that points to the dynamically allocated pointer-based array of integers managed by the `Array` object.
- **Overloading the Stream Insertion and Stream Extraction Operators as `friend`s**
  - When the compiler sees an expression like `cout << arrayObject`, it invokes non-member function `operator<<` with the call
  ```
  operator<<( cout, arrayObject )
  ```
  - When the compiler sees an expression like `cin >> arrayObject`, it invokes non-member function `operator>>` with the call
  ```
  operator>>( cin, arrayObject )
  ```
  - These stream operator functions cannot be members of class `Array`, because the `Array` object is always mentioned on the _right_ side of the stream insertion or stream extraction operator.
- `Array`s, and objects in general, should be properly initialized as they're created.

- **Array Copy Constructor**
  - The copy constructor initializes an `Array` by making a  copy of an existing `Array` object. Such copying must be done carefully to avoid the pitfall of leaving  both Array objects pointing to the same dynamically allocated memory.
  - This is the problem that would occur with default memberwise copying, if the compiler is allowed to define a default copy constructor for this class. 
  - Copy constructors are invoked whenever a copy of an object is needed, such as in:
    - passing an object by value to a function.
    - returning an object by value from a function, or
    - initializing an object with a copy of another object of the same class.
  - The copy constructor is called in a declaration when an object of class `Array` is instantiated and initialized with another object  of class `Array.
  - The copy constructor for `Array` uses a member intializer to copy the size of the initializer `Array` into data member `size`, uses `new` to obtain the memory for the internal pointer-based representation of this Array and assigns the pointer returned by `new` to data member `ptr`. Then the copy constructor uses a `for` statement to copy all the elements of the initializer `Array` into the new `Array` object.
  - An object of a class can look at the `private` data of any other object of that class (using a haaandle that indicates which object to access).
- The argument to a copy constructor should be a `const` reference to allow a `const` object to be copied.
- A  copy constructor must receive its argument by reference, not by value. Otherwise, the copy constructor call results in infinite recursion because receiiving an object by value requires the copy constructor to make a copy of the argument object.
- If the copy constructor simply copied the pointer in the source object to the target object's pointer, then both would point to the same dynamically allocated memory. The first desstructor to execute would delete the dynamically allocated memory, and the other object's `ptr` would be _undefined_, a situation called a **dangling pointer**. This woud likely result in a serious runtime error when the pointer was used.

- **Array Destructor**
  - The destructor uses `delete[]` to release the memory allocated dynamically by `new` in the constructor.
- If after deleting dynamically allocated memory, the pointer will continue to exist in memory, set the pointer's value to 0 to indicate that the pointer no longer points to memory in the free store. By setting the pointer to 0, the program loses access to that free-store space, which could be reallocated for a differenct purpose. If you do not set the pointer to 0, your code could inadvertently access the reallocated memory, ausing subtle, nonrepeatable logic errors.

- **Overloaded Assignment Operator**
  - When the compiler sees the expression `integers1 = integers2`, the compiler invokes member function `operator=` with the call
  ```
  integers1.operator=( integers2 )
  ```
  - Member function `operator=`'s implementation tests for **self-assignment** in which an `Array` object is being assigned to itself.
  - When `this` is equal to the right operand's address, a self-assignment is being attempted, so the assignment is skipped.
  - If it isn't a self-assignment, then the function determines whether the sizes of the two arrays are identical; in that case, the original array of integers in the left-side `Array` object is not reallocated. Otherwise, `operator=` uses `delete` to release the memory originally allocated to the target array, copies the `size` of the source array to the `size` of the target array, uses `new` to allocate the memory for the target array and places the pointer returned by `new` into the array's `ptr` member. Then the `for` statement copies the array elements from the source array to the target array.
  - Regardless of whether this is a self-assignment, the member function returns the current object (i.e., `*this`) as a constant reference; this enables cascaded `Array` assignments such as `x = y = z`, but prevents ones like `(x = y) = z` because `z` cannot be assigned to the `const Array` reference that's returned by `(x = y)`.
  - If self-assignment occurs, and function `operator=` did not test for this case, `operator=` would unnecessarily copy the elements of the `Array` into itself.
- A copy constructor, a destructor, and an overloaded assignment operator are usually provided as a group for any class that uses dynamically allocated  memory.
- Not providing an overloaded assignment operator and a copy constructor for a class when objects of that class contain pointers to dynamically allocated memory is a logic error.
- It's possible to prevent one object of a class from being assigned to another. This is done by declaring the assignment operator as a `private` member of the class.
- It's possible to prevent class objects from being copied; to do this, simply make both the overloaded assignment operator and the copy constructor of that class `private`.

- **Overloaded Equality and Inequality Operators**
  - When the compiler sees the expression `integers1 == integers2`, the  compiler invokes smember function `operator==` with the call
  ```
  integers1.operator==( integers2 )
  ```
  - Member function `operator==` immediately returns `false` if the `size` membrs of the arrays are not equal. Otherwise, `operator==` compares each pair of elements. If they're all equal, the function returns `true`. The first pair of elements to differ causes the function to return `false` immediately.
  - Member function `operator!=` uses the overloaded `operator==` function to determine whether one `Array` is equal to another, then returns the _opposite_ of that result. 
  - Writing `operator!=` in this manner enables you to reuse `operator==`, which reduces the amount of code that must be written in the class.
  - The full function definition for `operator!=` is in the `Array` header. This allows the compiler to _inline_ the definition of `operator!=` to eliminate the overhead of the extra function call.

- **Overloaded Subscript Operators**
  - When the compiler sees the expression `integers[5]`, it invokes the appropriate overloaded `operator[]` member function by generating the call
  ```
  integers1.operator[]( 5 )
  ```
  - The compiler creates a call to the `const` version of `operator[]` when the subscript operator is used on a `const Array` object. For examplel, if `const` object `z` is instantiated with the statement
  ```
  const Array z( 5 );
  ```
  then the `const` version of `operator[]` is requires to execute a statement such as 
  ```
  cout << z[ 3 ] << endl;
  ```
  - A program can invoke only the `const` member functions of a `const` object.
  - Each definition of `operator[]` determines whether the subscript it receives as an argument is _in range_ and if not, each throws an `out_of_range` exception. If the subscript is in range, the non-`const` version of `operator[]` returns the appropriate array element as a reference so that it may be used as a modifiable _lvalue_. If the subscript is in range, the `const` version of `operator[]` returns a copy of the appropriate element of the array. The returned character is an _rvalue_.

### 11.11 Operators as Member Functions vs Non-Member Functions

- When an operator function is implemented as a member function, the leftmost (or only) operand _must_ be an object (or a reference to an object) of the operator's class.
- If the left operand _must_ be an object of a different class or a fundamental type, this operator function_must_ be implemented as a non-member function.
- A non-member operator function can be made a `friend` of a class if that function must access `private` or `protected` members of that class directly.
- Operator member functions of a specific class are called (implicitly by the compiler) only when the _left_ operand of a binary operator is specifically an object of that class, or when the _single operand of a unary operator_ is an object of that class.
- **Commutative Operators**
  - You might choose a non-member function to overload an operator to enable the operator to be _commutative_.
  - Suppose we have a _fundamental type variable_, `number`, of type `long int`, and an _object_ `bigInteger1`, of class `HugeInteger`. The addition operator (`+`) produces a _temporary_ `HugeInteger` object as the sum of a `HugeInteger` and a `long int`, _or_ as the sum of a `long int` and a `HugeInteger`. Thus, we require the addition operator to be _commutative_.
  - The problem is that the class object _must_ appear on the _left_ of the addition operator if that operator is to be overloaded as a member function. So, we _also_ overload the operator as a non-member function to allow the `HugeInteger` to appear on the _right_ of the addition.
  - The `operator+` function that deals with the `HugeInteger` on the left can still be a member function. The non-member function can simply swap its arguments and call the member function.
  
### 11.12 Converting between Types

- The compiler knows how to perform conversions among fundamental types. You can use _cast operators_ to force conversions among fundamentaly types.
- You must specify how to convert among user-defined types, and between user-defined types and fundamental types.
- Such conversions can be performed with **conversion constructors**- single-argument constructors that turn objects of other types into objects of a particular class.
- A **conversion operator** (also called a cast operator) can be used to convert an object of one class into an object of another class or into an object of a fundamental type. Such a conversion operator must be a `non-static` member function.
- The function prototype
```
A::operator char *() const;
```
declares an overloaded cast operator function for converting an object of iser-defined type `A` into a temporary `char*` object.
- An overloaded **cast operator function** does not specify a return type- the return type is the type to whic the object is being converted. 
- If `s` is a class object, when the compiler sees the expression `static_cast<char *>( s )`, the compiler generates the call
```
s.operator char *()
```
The operand `s` is the class object `s` for twhich the member function `operator char *` is being invoked.
- Overloaded cast operator functions can be defined to convert objects of user-defined types into fundamental types or into objects of other user-defined types. The prototypes
```
A::operator int() const;
A::operator OtherClass() const;
```
declare _overloaded cast operator functions_ that can convert an object of user-defined type `A` iinto an integer or into an object of user-defined type `OtherClass`, respectively.
- One  of the nice features of cast operators and conversion constructors is that, when necessary, the compiler can call these functions implicitly to create temporary objects. For example, if an object `s` of a user-defined `String` class appears in a program at a location where an ordinary `char *` is expected, such as
```
cout << s;
```
the compiler can call the overloaded cast-operator function `operator char *` to convert the object into a `char *` and use the resulting `char *` in the expression. With this cast operator provided for a `String` class, the stream insertion operator does not have to be overloaded to output a `String` using `cout`.
- When a conversion constructor is used to perform an implicit conversion, C++ can apply only one implicit constructor call to try to match the needs of another overloaded operator. The compiler will not satisfy an overloaded operator's needs by performing a series of implicit, user-defined conversions.

### 11.13 `explicit` Constructors

- Any single-argument constructor-except a copy constructor-can be used by the compiler to perform an implicit conversion. The constructor's argument is converted to an object of the class in which the constructor is defined. The  conversion is automatic and you need not use a cast operator.
- In some situations, implicit conversions are undesirable or error-prone.
- The compiler might use implicit conversions in cases that you do not expect, resulting in ambiguous expressions that generate compilation errors or result in execution-time logic errors.
- **Preventing Implicit Conversions with Single-Argument Constructors**
  - C++ provides the keyword **explicit** to supress implicit conversions via conversion constructors when such conversions should not be allowed.
  - A constructor that's declared `explicit` cannot be used in an implicit conversion.
- Use the `explicit` keywoed on single-argument constructors that should not be used by the compiler to perform impliit conversions.

### 11.14 Building a `String` Class

- The C++ standard library includes a class `string`.
- **Overloaded Function Call Operator**
  - Overloading the **function call operator ()** is powerful, because functions can take an _arbitrary_ number of parameters.
  - In the `String` class, we overload this operator to select a substring from a `String`. The operator's two integer parameters specify the start location and the length of the substring to be selected. If the start location is out of range or the substring is negative, the operator simply returns an empty `String`. If the substring length is 0, then the substring is selected to the end of the `String` object. 
  - Suppose `string1` is a `String` object containing the string "AEIOU". When the compiler encounters the  expression `string1(2, 2)`, it genertes  the member-function call  
  `string1.operator()(2, 2)`  
  which returns a `String` containing "IO".
