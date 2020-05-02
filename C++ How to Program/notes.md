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
- Pass-by-`const`-reference is a safe, good-performing alternative. This can be implemented with a `const` reference parameter or with a pointer-to-`const`-data parameter.

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

## Chapter 11. Operator Overloading; Class string

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

## Chapter 12. Object-Oriented Programming: Inheritance

### 12.1 Introduction

- **Inheritance** is a form of software reuse in which you create a class that absorbs an existing class's capabilities, then _customizes_ or enhances them.
- Software reuse saves time during program development by taking advantage of proven, high-quality software.
- You can specify that a new class should **inherit** the members of an existing class. This existing class is called the **base class**, and the new class is called the  **derived class**. A derived class represents a more specialized group of objects.
- C++ offers `public`, `protected`, and `private` inheritance.
- With `public` inheritance, every object of a derived class is also an object of that derived class's base class. 
- We distinguish betwween the **_is-a_ relationship** and the _has-a_ relationship. The is-a relationship represents inheritance. The has-a relationship represents composition.

### 12.2 Base Classes and Derived Classes

- Base classes tenfd to be _more general_ and derived classes tend to be _more specific_.
- Base classes: Student, Shape, Account; Derived classes: GraduateStudent, UndergraduateStudent, Circle, Triangle, Rectangle, Sphere, Cube, CheckingAccount, SavingsAccount.
- Inheritance relationships form **class hierarchies**. A base class exists in a hierarchical relationship with its derived classes. A class becomes either a base class, a derived class, or both.
- With **single inheritance**, a class is derived from _one_base class. With **multiple inheritance**, a derived class inherits from _two or more_ (possibly unrelated) base classes.
- To specify that class `TwoDimensionalShape` is derived from (or inherits from) class `Shape`, the definition could begin as follows:
```
class TwoDimensionalShape : public Shape
```
- This is an example of **`public` inheritace, the most commonly used form.**
- With all forms of inheritance, `private` members of a base class are _not_ accessible directly from that class's derived classes, but these `private` base-class members are still inherited.
- With `public` inheritance, all other base-class members retain their original member access when they become members of the derived class. Through these inherited base-class members, the derived class can manipulate `private` members of  the base class. `friend` functions are _not_ inherited.

### 12.3 `protected` Members

- A base class's `public` members are accessible within its body and anywhere the program has a handle (i.e, a name, reference, or pointer) to an object of that class or one of its derived classes.
- A base class's `private` members are accessible only within its body and to the `friends` of that base class.
- Using `protected` access offers an intermediate level of protection between `public` and `private` access.
- A base class's `protected` members can be accessed within the body of that base class, by members and `friend`s of that base class, and by members and `friend`s of any classes derived from that base class.
- When a derived-class member function _redefines_ a base-class member function, the  base-class member can still be accessed from the derived class by preceding the base-class member name with the base-class name and the scope resolution operator (::).

### 12.4 Relationship between Base Classes and Derived Classes

- Copying and pasting code from one clas to another can spread many physical copies of the same code and can spread errors throughout a system, creating a code-maintenance nightmare.
- To avoid duplicating code, use inheritance, rather than the "copy and paste" approach, in situations where you want one class to "absorb" the data members and member functions of another class.
- With inheritance, the common data members and member functions of all the classes the hierarchy are declared in a base class. When changes are required for these common features, you need to make the changes only in the case class- derived classes then inherit the changes.
- The **base-class initializer syntax** uses a member initializer to pass arguments to the base-class constructor. C++ requires that a derived-class constructor call its base-class constructor to initialize the base-class data members that are inherited into the derived class.
- THe base class's header must be incluses in the derived class's header.
- When base-class data members are decclared as `protected`, derived classes can modify the data directly. 
- Inheriting `protected` data members slightly improves performance, because we can directly access the members without incurring the overhead of calls to set or get member functions.
- In most cases, it's better to use `private` data members to encourage proper software engineering, and leave code optimization issues to the compiler.
- It's appropriate to use the `protected` access specifier when a base class should provide a service only to its derived classes and friends.
- Declaring base-class data members `private`` enables you to change the base-class implementation without having to change derived-class implementations.
- Using a member function to access a data member's value can be slightly slower than accessing the data directly. However, today's optimizing compilers are carefully designed to perform many optimizations implicitly.
- Write code that adheres to proper software engineering principles, and leave optimization to the compiler: "Do not second-guess the compiler".
- The syntax to invoke a redefined base-class member function from a derived class is the base-class name and the scope resolution operator (::) before the base-class member-function name. 
- When a base-class member function is redefined in a derived class, the derived-class version often calls the base-class version to do additional work. Failure to use the :: operator prefixed with the name of the base class when referencing the base class's member function causes infinite recursion.

### 12.5 Constructos and Destructors in Derived Classes

- When a program creates a derived-class object, the derived-class constructor immediately calls the base-class constructor, the base-class constructor executes, then the derived class's member initializers execute and finally the derived-class constructor's body executes. This process cascades up the hierarchy if it contains more than two levels.
- Destructors for derived-class objects are called in the reverse order in which their corresponding constructors are called.
- Base-class constructors, destructors and overloaded assignment operators are _not_ inherited by derived classes. Derived-class constructors, destructors and overloaded assignment operators, however, can call base-class versions.

### 12.6 `public`, `protected` and `private` Inheritance.

| Base-lass member access specifier | public inheritance         | protected inheritance      | private inheritance      |  |
|-----------------------------------|----------------------------|----------------------------|--------------------------|--|
| public                            | public in derived class    | protected in derived class | private in derived class |  |
| protected                         | protected in derived class | protected in derived class | private in derived class |  |
| private                           | hidden in derived class    | hidden in derived class    | hidden in derived class  |  |

- `private` and `protected` inheritance are not _is-a_ relatonships.

### 12.7 Software Engineering with Inheritance

- At the design stage of an object-oriented system, the designer determines that certain classes are closely related. The designer should "factor out" common attributes and behaviours and place these in a base class, then use inheritance to form derived classes.
- Creating a derived class does not affect its base class's source code. Inheritane preserves the integrity of a base class.

## Chapter 13: Polymorphism

### 13.1 Introduction

- Polymorphism enables you to "program in the general" rather than "program in the specific"- it enables you to write programs that process objects of classes that are part of the same class hierarchy as if they were all objects of they hierarchy's base class.
- Polymorphism works off base-class pointer handles and base-class reference handles, but not name handles.
- You can design systems that are easily _extensible_: new classes can be added with little or no modification to the general portions of the program, as long as the new classes are part of the inheritance hierarchy theat the program processes generically.

### 13.2 Introduction to Polymorphism: Polymorphic Video Game

- A polymorphic screen manager facilitates adding new classes to a syste with minimal modifications to its code.
- Suppose we want to add objects of class `Mercurian` to our video game: we must build a class `Mercurian` that inherits from `SpaceObject` , but provides its own definition of member function `draw`.
- You can use polymorphism to accomodate additional classes, including ones that were not even envisioned when then system was created.
- Polymorphism enables you to deal in generalities and let the execution-time environment concern itself with the specifics.

### 13.3 Relationships Among Objects in an Inheritance Hierarchy

- If we assign the address of a derived-class object to a base-class pointer, invoking a function via that pointer invokes the base-class functionality in the derived-class object: the type of the handle determines which function is called.
- Assigning the address of a base-class object to a derived-class pointer results in a compilation error.
- If we assign  the address of a derived-class object to a base-class pointer, the base-class pointer  can be used to invoke only the base-class functionality. 
- With public inheritance, an object of a derived class can be treated as an object of its base class. Howerver, we cannot treat a base-class object as an object of any of its derived classes.
- The invoked functionality depends on the  type of the pointer  (or reference) used to invoke the function, not the type of object for which the member function is called.

#### 13.3.3 Derived-Class Member Function Calls via Base-Class Pointers

- The compiler allows us to invoke _only_ base-class member functions off a base-class pointer. If a base-class pointer is aimed at a derived-class object and an attempt is made to acces a derived-class-only-member function, a compilation error will occur.
- The compiler will allow access to derived-class-only members from a base-class pointer that's aimed at a derived-class object _if_ we explicitly cast the base-class pointer to a derived-class pointer: this is known as **downcasting**.
- Downcasting is a potentially dangerous operation.

#### 13.3.4 Virtual Functions

- With `virtual` functions, the type of the object, not the type of the handle used to invoke the member function, determines which version of a `virtual` function to invoke.
- Declare the function in the base class as a `virtual` function, and then override it in each of the derived classes to obtain the desired functionality.
- An overridden function in a derived class has the same signature and return type (prototype) as  the function it overrides in its base class.
- We declare a `virtual` function by preceding the function's prototype with the keyword `virtual` in the base class.
- Once a function is declared `virtual`, it remains `virtual` all the way down the inheritance hierarchy from that point, even if that function is not explicitly declared `virtual` when a derived class overrides it.
- Even though certain functions  are implicitly virtual because of a declaration made higher in the class hierarchy, explicitly declare these functions `virtual` at every level of the class hierarchy to promote program clarity.
- When a derived class chooses not to override a `virtual` function from its base class, the derived class simply inheirts its base class's `virtual` function implementation.
- Choosing the appropriate function to call at execution time (rather than at compile time) is known ad **dynamic binding** or **late binding**.
- When a `virtual` function is called by referencing a specific object by name and using the dot member-selection operator, the function invocation is resolved at compile time (this is called **static binding**) and the `virtual` function that's called is the one defined for (or inherited by) the  class of that particular object- this is not polymorphic behaviour.

### 13.4 Type Fields and `switch` Statements

- One way to determine the type of an object is to use a `switch` statement to check the value of a field in the object. This allows us to distinguish among object types, then invoke an appropriate action for a particular object.
- Using `switch` logic exposes programs to a variety of potential problems.
- Polymorphic programming can eliminate the need for `switch` logic.
- An interesting consequence of using polymorphism is that programs take on a simplified appearance. This simplification facilitiates testing, debugging, and program maintenance.

### 13.5 Abstract Classes and Pure `virtual` Functions

- There are cases in which it's useful to define classes from which you never intend to instantiate any objects. Such classes are called **abstract classes**. We refer to them as **abstract base classes** because they are normally used as base classes in inheritance hierarchies.
- These classes cannot be ussed to instantiate objects, because they are incomplete- derived classes must define the "missing pieces" before objects of these classes can be instantiated.
- Classes that can be used to instantiate objects are called **concrete classes**.

**Pure Virtual Functions** 

A class is made abstract by declaring one or more of its `virtual` functions to be "pure". A **pure virtual function** is specified by placing "= 0" in its declaration, as in

```
virtual void draw() const = 0; // pure virtual function
```

The "=0" is a **pure specifier**. Pure `virtual` functions do not provide implementation.
- A pure virtual function _requires_ the derived class to override the function for that derived class to be concrete; otherwise the derived class remains abstract.
- An abstract class defines a common public interface for the various classes in a class hierarchy. An abstract class contains one or more pure `virtual` functions that concrete derived classes must override. An abstract class also can have data members and concrete functions (including constructors and destructors), which are subject to the normal rules of inheritance by derived classes.
- Although we canot instantiate objects of an abstract base class, we can use the abstract base class to declare pointers and references that can refer to objects of any concrete classes derived from the abstract class.

**Device Drivers and Polymorphism**

- An object-oriented operating system might use an abstract base class to provide an interface appropriate for all device drivers. Then, through inheritance from that abstract base class, derived classes are formed that all operate similarly.
- This architecture allows new devices to be added to a system easily, even after the operating system has been defined.

**Iterators and Polymorphism**

- It's common in object-oriented programming to define an **iterator class** that can traverse all the objects in a container (such as an array). Iterators often are used in polymorphic programming to traverse an array or a linked list of pointers to objects from various levels of a hierarchy. The pointers in such a list are all base-class pointers.

### 13.6 Case Study: Payroll System Using Polymorphism

- We use an abstract class and polymorphism to perform payroll calculations based on the type of employee.
- A derived class can inherit interface and/or implementation from a base class. Hierarchies designed for **implementation inheritance** tend to have their functionality high in the hierarchy, and hierarchies designed for **interface inheritance** tend to have their functionaliity lower in the hierarchy.

### 13.7 Polymorphism, Virtual Functions and Dynamic Binding "Under the Hood"

- The STL components were implemented without polymorphism and virtual functions to avoid the associated execution-time overhead and achieve optimal performance.
- Polymorphism is accomplished through three levels of pointers, i.e., triple indirection. 
- When C++ compiles a class that has one or more `virtual` functions, it buils a **virtual function table (vtable)** for that  class. An executing program uses the _vtable_ to select the proper function implementation each time a `virtual` function of that class is called.
- Any class that has one or more null pointers in its _vtable_ is an abstract class.
- Classes without any null _vtable_ pointers are concrete classes. 

**Three Levels of Pointers to Implement Polymorphism**

- One level is the function pointers in the _vtable_. These point to the actual functions that execute whtn a `virtual` function is invoked.
- Whenever an object of a class with one or more `virtual` functions is instantiated, the compiler attaches to the object a pointer to the _vtable_ for that class. This is the second level of pointers.
- The third level of pointers simply contains the handles to the objects that receive the `virtual` function calls. The handles in this level may also be references.
- The pointer dereferencing operations and memory accesses that occur on every `virtual` function call require some additional execution time. The _vtables_ and the _vtable_ pointers added to the objects require some additional memory.
- Polymorphism, as typically implemented with `virtual` functions and dynamic binding in C++, is efficient. You can use these capabilities with nominal impact on performance.
- Polymorphism's overhead is acceptable for most applications. But in some situations, such as real-time applications with stringent performance requirements, polymorphism's overhead may be too high.

### 13.8 Case Study: Payroll System Using Polymorphism and Runtime Type Information with Downcasting, `dynamic_cast`, `typeid` and `type_info`

- **Runtime type information (RTTI)** and **dynamic casting** enable a program to determine the type of an object at execution time and act on that object accordingly.
= Operator `typeid` returns a reference to ab object of class `type_info` that contains the information about the type of its operand, including the name of that type.
- When invoked, `type_info` member function **name** returns a pointer-based string that contains the type name of the argument passed to `typeid`. The string returned by `type_info` member function `name` may vary by compiler.

### 13.9 Virtual Destructors

- If a derived-class object with a nonvirtual destructor is destroyed explicitly by applying the `delete` operator to a base-class pointer to the object, the C++ standard specifies that the behaviour is undefined.
- The simple solution to this problem is to create a **`virtual` destructor** in the base class. This makes all derived-class destructors `virtual` even they do not have the same name as the base-class destructor.
- The base-class destructor automatically executes after the derived-class destructor.
- If aa class has `virtual` functions, provide a `virtual` destructor, even if one is not required for the class. This ensures that a custom derived-class destructor if there is one) will be invoked when a derived-class object is deleted via a base class pointer.
- Constructors cannot be virtual. Declaring a constructor `virtual` is a compilation error.

## Chapter 14: Templates

### 14.1 Introduction

- **Function templates** and **class templates** enable you to specify, with a single code segment, an entire range of related (overloaded) functions - called **function-template specializations** - or an entire range of related classes - called **class-template specializations**. This technique is called **generic programming**.
- We might write a single function template for an array-sort function, then have C++ generate separate function=template specializations that will sort `int` arrays, `float` arrays, `string` arrays and so on.
- We might write a single class template for a stack class, then have C++ generate separate class-template specializations, such as a stack-of-`int` class, a stack-of-`float` class, a stack-of-`string` class and so on.
- Most C++ compilers require the complete definition of a template to appear in the client source-code file that uses the template. For this reason and for reusability, templates are often defined in headers, which are then `#include`d in the appropriate client source-code files. For class templates, this means that the member functions are also defined in the header.

### 14.2 Function Templates

- Overloaded functions normally perform _similar_ or _identical_ operations on _different_ types of data. If the operations are _identical_ for each type, they can be expressed more compactly and conveniently using function templates.
- Function templates, like, macros, enable software reuse. Unlike macros, function templates eliminate many types of errors through the scrutiny of full C++ type checking.
- All **function-template definitions** begin with keyword **`template`** followed by a list of **template parameters** to the function template enclosed in **angle brackets**; each template parameter that represents a type _must_ be preceded by either of the interchangeable keywords `class` or **`typename`**:
```
template< typename T >
template< class ElementType >
template< typename BorderType, typename FillType >
```

- Keywords `typename` and `class` used to specify function-template parameters actually mean "any fundamental type or user-defined type".
- Not placing keyword `class` or keyword `typename` before each type template parameter of a function template is a syntax error.
- If a template is invoked with a user-defined type, and if that template uses functions ot operators (e.g. ==, +, <=) with objects of that class type, then those functions and operators must be overloaded for the user-defined type. Forgetting to overload such operators causes compilation errors.
- Multiple function-template specializations and class-template specializations are instantiated in a program (at compile time), despite the fact that the templates are written only once. These copies con consume considerable memory. This is not normally an issue, because the code generated by the template is the same size as the code you'd have written to produce the separate overloaded functions.

### 14.3 Overloading Function Templates

- We can provide other function templates that specify the same function name but with different function parameters.
- We can also overload a function template by providing nontemplate functions with the same function name but different function arguments.
- A compilation error occurs if no matching function definition can be found for a particular function call or if there are multiple matches that the compiler considers ambiguous.

### 14.4 Class Templates

- It's possible to understand the concept of a "stack" independent of the type of the items being placed in it. However, to instantiate a stack, a data type must be specified. We need the means for describing the notion of a stack _generically_ and instantiating classes that are _type-specific_ versions of this generic stack class. C++ provides this capability through **class templates**.
- Class templates encourage software reusability by enabling type-specific versions of generic classes to be instantiated.
- Class templates are called **parameterized types**, because they require one or more type parameters to specify how to customize a "generic class" template to form a class-template specialization.
- A class-template definition is preceded by the header:
```
template< typename T >
```
- to specify a class-template definition with type parameter T which acts as sa placeholder for the type of the class to be created. You need not specifically use identifier T, any valid identifier can be used.
- The member-function definitions of a class template are function templates. The member-function definitions that appear outside the class template definition each befin with the header `template< typename T >`.

### 14.5 Nontype Parameters and Default Types for Class Templates

- It's possible to use **non-type template parameters**, which can have default arguments and are treated as `const`s. The template header could be modified to take an `int` elements parameter as follows:
```
template< typename T, int elements > // nontype parameter elements
```
- In addition, a type parameter can specify a **default type**. For example:
```
template< typename T = string> // defaults to type string
```
- Default type parameters must be the _rightmost_ (trailing) parameters in a template's type-parameter list.
- When appropriate, specify the size of a container class (such as an array or a stack class) at compile time (possibly through a nontype template parameter). This eliminates the execution-time overhead of using `new` to create the space dynamically.
- Specifying the size of a container at compile time avoids the potentially fatal execution-time error if `new` is unable to obtain the needed memory.
- In some cases, it may not be possible to use a particular type with a class template. If a particular user-defined type will not work with the template or requires customized processing, you can define an ****explicit specialization** of the class template for a particular type:
```
template<>
class Stack< Employee >
{
  // body of class definition
};
```
- The `Stack<Employee>` explicit specialization is a complete replacement for the `Stack` class template that is specific to type `Employee`- it does not use anything from the original class template and can even have different members.

## Chapter 15: Stream Input/Output

### 15.1 Introduction

- Many of the I/O features that we'll discuss are object-oriented. This styeof I/O makes use of other C++ features, such as references, function overloading and operator overloading.
- C++ uses **type-safe I/O**. Each I/O operation is executed in a manner sensitive to the data type. Improper data cannot "sneak" through the system.
- Uses can specity how to perform I/O for objects of user-defined types by overloading the stream insertion operator (<<) and the stream extraction operator (>>). This extensibility is one of C++'s most valuable features.

### 15.2 Streams

- C++ I/O occurs in **streams**, which are sequences of bytes. In input operations, the bytes flow from a device to main memory. In output operations, bytes flow from main memory to a device.
- C++ provides both "low-level" and "high-level" I/O capabilities. Low-level I/O capabilities (**unformatted I/O**) specify that some number of bytes should be transferred device-to-memory or memory-to-device. In such transfers, the individual byte is the item of interest. Such low-level capabilities provide high-speed, high-volume transfers but are not particularly convenient.
- Programmers generally prefer a higher-level vew of I/O (**formatted I/O**) in which bytes are grouped into meaningful units, such as integers, floating-point numbers, character strings and user-defined bytes. These type-oriented capabilities are satisfactory for most I/O other than high-volume file processing.
- Using unformatted I/O can lead to portability problems, because unformatted data is not portable across all platforms.

#### 15.2.1 Classic Streams vs. Standard Streams
- In the past, the C++ **classic stream libraries** enabled input and output of `char`s. Because a `char` normally occupies one byte, it can only represent a limited set of characters (such as the ASCII character set).
- C++ includes the **standard stream libraries**, which enable developers to build systems capable of performing I/O operations with Unicode characters. For this purpose, C++ includes an additional character type caled **wchar_t**, which among other uses can store Unicode characters.
- The C++ standard also redesigned the classic C++ stream classses as class templates with separate specializations for processing characters of types `char` and `wchar_t`, respectively.

#### 15.2.2 `iostream` Library Headers

- The C++ `iostream` library provides hundres of I/O capabilities. Several headers contain portions of the library interface.
- The `<iostream>` declares basic services required for all stream-I/O operations. It defines the `cin`, `cout`, `cerr` and `clog` objects, which correspond to the standard input stream, standard output stream, unbuffered standard error stream, and the buffered standard error stream. Both unformatted and formatted I/O services are provided.
- The `<iomanip>` header declares services useful for performing formatted I/O with so-called **paameterized stream manipulators**, such as `setw` and `setprecision`.
- The `<fstream>` headers declares services for file processing.
- C++ implementations generaly contain other I/O-related libraries that provide system-specific capabilities, such as the controlling of special-purpose devices for audio and video I/O.

### 15.2.3 Stream Input/Output Classes and Objects

- The `iostream` library provides many templates for handling common I/O operations.
- Class template **basic_istream** supports stream-input operations, class template, class tempalte **basic_ostream** supports stream-output operations, and class template **basic_iostream** supports both stream-input and stream-output operations.
- Each template has a predefined template specialization that enables `char` I/O.
- In addition, the `iostream` library provides a set of `typedef`s that provide aliases or these template specializations.
- The `typedef` specified declares synonyms (aliases) for data types. You'll sometimes use `typedef` to create shorter or more readable types. For example, the statement `typedef Card *CardPtr;` defines an additional type name, CardPtr, as a synonym for type `Card *`. Creating a name using `typedef` does not create a data type, only a type name.
- The `typedef` **istream** represents a specialization of `basic_istream` that enables `char` input.
- The `typedef` **ostream** represents a specialization of `basic_ostream` that enables `char` output.
- The `typedef` **iostream** represents a specialization of `basic_ostream` that enables both `char` input and output.


**Stream-I/O Template Hierarchy and Operator Overloading**

- Templates `basic_istream` and `basic_ostream` both derive through single ingeritance from basic template `basic_ios`. 
- Template `basic_iostream` derives through multiple inheritance from templates `basic_istream` and `basic_ostream`.
- Operator overloading provides a convenient notation for performing input/output.

**Standard Stream Objects `cin`, `cout`, `cerr` and `clog`**

- Prefefined object `cin` is a `istream` instance and is said to be "connected to" the stadard input device, which is usually the keyboard. The stream extraction operator (>>) as used in the following statement causes a value for integer variable `grade` to be input from `cin` to memory:

```
cin >> grade; // data "flows" in the direction of the arrows
```

The compiler determines the data type of `grade` and selects the appropriate overloaded stream extraction operator. Assuming that `grade` has been declared properly, the stream extraction operator does not require additional type information. The `>>` operator is overloaded to input data items of fundamental data types, strings, and pointer values.
- The predefined object `cout` is an `ostream` instance and is said to be "connected to" the standard output device, which usually is the display screen. The stream insertion operator (`<<`), as used in the following statement, causes the value of variable `grade` to be output from memory to the standard output device:

```
cout << grade; // data "flows" in the direction of the arrows
```

- The predefined object `cerr` is an `ostream` instance and is said to be "connected to" the standard error device, normally the screen. Outputs to object `cerr` are **unbuffered**, implying that each stream insertion to `cerr` causes its output to appear immediately-- this is appropriate for notifying a user promptly about errors.
- The predefined object `clog` is an instance of the `ostream` class and is said to be "connected to" the standard error device. Outputs to `clog` are **buffered**. This means that each insertion to `clog` could cause its output to be held in a buffer (an area in memory) until the buffer is filled or until the buffer is flushed.
- Bufferin is an I/O performance-technique discussed in operating-systems courses.

**File-Processing Templates**

- C++ file processing uses class templates `basic_ifstream` (for file input), `basic_ofstream` (for file output) and `basic_fstream` (for file input and output).
- typedef `ifstream` represents a specialization of `basic_ifstream` that enables `char` input from a file.
- typedef `ofstream` represents a specialization of `basic_ofstream` that enables `char` output to a file.

### 15.3 Stream Output

- Formatted and unformatted output capabilities are provided by `ostream`. These include:
  - output of standard odata types with the stream insertion operator (`<<`)
  - output of characters via the `put` member function
  - unformatted output via the `write` member function
  - output of integers in decimal, octal, and hexadecimal formats
  - output of floating-point values with various precision, with forced decimal points, in scientific notation, and in fixed notation
  - output of data justified in fields of designated widths
  - output of data in fields padded with specified characters
  - output of uppercase letters in scientific notation and hexadecimal notation

#### 15.3.1 Output of `char*` Variables

- C++ determines data types automatically, but this sometimes gets in the way.
- Suppose we want to print the address stored in a `char*` pointer. The `<<` operator has been overloaded to output a `char*` as a _null-terminated string_. To output the _address_, you can cast the `char*` to a `void*` (this can be done to any pointer variable).

#### 15.3.2 Character Output Using Member Function `put`

- We can use the `put` member function to output characters. For example, the statement `cout.put( 'A' );` displays a single character A. Calls to `put` may be cascaded, as in the  statement `cout.put('A').put('\n');` which outputs the  letter A followed by a newline character.
- The dot operator (`.`) associates from left to right, and the `put` member function returns a reference to the `ostream` object that received the `put` call.
- The `put` function also may be called with a numeric expression that represents an ASCII value, as in the following statement, which also outputs A: `cout.put(65);`

### 15.4 Stream Input

- Formatted and unformatted input capabilities are provided by `istream`.
- The strea extraction operator (`>>`) normally skips **white-space characters** in the input stream.
- After each input, the stream extraction operator returns a _reference_ to the stream object that received the extraction message (e.g. `cin`). If that reference is used as a condition, the stream's overloaded `void *` cast operator function is implicitly invoked to convert the reference into a non-null pointer value or the null pointer based on the success or failure of the last input operation.
- A non-null pointer converts to the `bool` value `true` to indicate success and the null pointer converts to the `bool` value `false` to indicate failure.
- When an attempt to read past the end of a stream, the stream's overloaded `void *` cast operator returns the null pointer to indicate end-of-file.
- Each stream object contains a set of **state bits** used to control the stream's state. These bits are used by the stream's overloaded `void *` cast operator to determine whether to return a non-null pointer or the null pointer. Stream extraction causes the stream's **failbit**  to be set if data of the wrong type is input and causes the stream's **badbit** to be set if the  operation fails.

#### 15.4.1 `get` and `getline`  Member  Functions

- The `get`  member function with no arguments inputs one character from the designated stream and returns is as the value of the function call. This version of `get`  returns `EOF` when end-of-file is encountered on the stream.

**Using Member Functions `eof`, `get` and `put`**

- The value of `cin.eof()` is `false` (`0` on the output).
- The `get` member function with a character-reference arguments inputs the next character from the input stream (even white-space characters) and stores it in the character argument.
- When `get` is used with three arguments, these are a character array, a size limit and a delimiter. It either reads one fewer than the specified maximum number of characters and terminates or terminates as soon as the delimiter is read. A null character is inserted to terminate the input string in the character array used as a buffer by the program.
- The delimiter is not placed in the character array but does remain in the input stream (the delimiter will be the next character read).

**Comparing `cin` and `cin.get`

- The call to `cin.get` does not specify a delimiter, so the default '\n' character is used.

**Using Member Function `getline`**

- Member function `getline` operates similarly to the third version of the `get` member function and inserts a null character after the line in the character array.
- The `getline` function removes the delimiter from the stream, but does not store it in the character array.

#### 15.4.2 `istream` Member Functions `peek`, `putback` and `ignore`

- The `ignore` member function of `istream` reads and discards a designated number of characters (the default is one) or terminates upon encountering a designated delimiter.
- The `putback` member function places the previous character obtained by a `get` from an input stream back into that stream. This is useful for applications that scan an input stream looking for a field beginning with a specific character.
- The `peek` member functinoo returns the next character from an input stream but does not remove the character from the stream.

#### 15.4.3 Type-Safe I/O

- C++ Offers _type-safe I/O_. The << and >> operators are overloaded to accept data items of specific types. If unexpected data is processed, various error bits are set, which the user may test to determine whether an I/O operation succeeded or failed.
- If operators << and >> have not been overloaded for a user-defined type and you attempt to input into or output the contents of an object of that user-defined type, the compiler returns an error. This enables to program to "stay in control".

### 15.5 Unformatted I/O Using `read`, `write` and `gcount`

- Unformatted input/output is performed using the `read` and `write` member functions of `istream` and `ostream`, respectively. `read` inputs bytes to a character array in memory; `write` outputs bytes from a character array. These bytes are not formatted in any way.
- The call
```
char buffer[] = "HAPPY BIRTHDAY";
cout.write( buffer, 10);
```
outputs the first 10 bytes of buffer.
- The `read` member function inputs a designated number of characters into a character array. If fewer than the designated number of characters are read, `failbit` is set. Member function `gcount` reports the number of characters read by the last input operation.

### 15.6 Introduction to Stream Manipulators

- The stream manipulators provide capabilities such as setting field widths, setting precision, setting and unsetting format state, setting the fill character in fields, flushing streams, inserting a newline into the output sstream, inserting a null character into the output stream and skipping white space in the input stream.

#### 15.6.1 Integral Stream Base: dec, oct, hex and setbase

- Integers are interpreted normally as decimal values.
- To change the base in which integers are interpreted on a stream,
  - insert the `hex` manipulator to set the base to hexadecimal
  - insert the `oct` manipulator to set the base to octal
  - insert the `dec` manipulator to reset the stream decimal
- A stream's base also may be changed by the `setstream` manupulator, which takes an `int` argument of 10, 8, or 16. Using `setbase` (or any other parameterized manipulator) requires the inclusion of the `<iomanip>` header.
- The stream base value remains the same until changed explicitly; `setbase` settings are "sticky".

#### 15.6.2 Floating-Point Precision (`precision`, `setprecision`)

- We can control the **precision** of floating-point numbers by using either the `setprecision` stream manipulator or the `precision` member function of `ios_base`. A call to either of these sets the precision for all subsequenct output operations until the next precision-setting call.
- A call to member function `precision` with no argument returns the current precision setting.

#### 15.6.3 Field Width (width, setw)

- The `width` member function (of base class `ios_base`) sets the field width and returns the previous width.
- If values output are narrower than the field width, **fill characters** are inserted as **padding**.
- A value wider than the designated width will not be truncated - the full number will be printed.
- The `width` function with no argument returns the current setting.
- The width setting applies only for the next insertion or extraction (the width setting is not sticky). Afterward, the width is set implicitly to 0.
- When a field is not sufficiently wide to handle outputs, the outputs print as wide as necessary.
- The `setw` stream manipulator also may be used to set the field width.

#### 15.6.4 User-Defined Output Stream Manipulators

- You can create your own manipulators.
- For output stream manipulators, the return type and parameter must be of type `ostream &`.

### 15.7 Stream Format States and Stream Manipulators

| Manipulator  | Description                                                                                                                                                                                                                                                                      |
|--------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `skipws`     | Skip white-space characters on an input stream. This setting is reset with stream manipulator `noskipws`                                                                                                                                                                         |
| `left`       | Left justify output in a field. Padding characters appear to the right if necessary.                                                                                                                                                                                             |
| `right`      | Right justify output in a field. Padding characters appear to the left if necessary.                                                                                                                                                                                             |
| `internal`   | Indicate that a number's sign should be left justified in a field and a number's magnitude should be right justified in that same field.                                                                                                                                         |
| `boolalpha`  | Specify that `bool` values should be displayed as the word `true` or `false`. The manipulator `noboolalpha` sets the stream back to displaying `bool` values as 1 and 0.                                                                                                         |
| `showbase`   | Specify that the base of a number is to be output ahead of the number. This setting is reset with stream manipulator `noshowbase`.                                                                                                                                               |
| `showpoint`  | Specify that floating-point numbers should be output with a decimal point. This is used normally with `fixed` to guarantee a certain number of digits tot he right of the decimal point, even if they're zeroes.s This setting is reset with sstream manuipulator `noshowpoint`. |
| `uppercase`  | Specify that uppercase letters should be used in a hex integer and that uppercase E should be used when representing a floating-point value in scientific notation. This setting is reset with stream manipulator `nouppercase`.                                                 |
| `showpos`    | Specify that positive numbers should be preceded by a plus sign. This setting is reset with stream manupulator `noshowpos`.                                                                                                                                                      |
| `scientific` | Specify output of a plloating-point value in scientific notation.                                                                                                                                                                                                                |
| `fixed`      | Specify output of a floating-point value in fixed-point notation with a specific number of digits to the right of the decimal point.                                                                                                                                             |

- The `fill` member function speciifes the fill character to be used with justified fields; spaces are used for padding by default. The function returns the prior padding character.
- The `set-fill` manipulator also ssets the padding character.

#### 15.7.8 Setting and Resetting the Format State ia Member Function `flags`

- Member function `flags` without an argument returns the current format settings as a `fmtflags` fata type (of class `ios_base`), which represents the **format state**.
- Member function `flags` with a `fmtflags` argument sets the format state as specified by the argument and returns the prior state settings.

### 15.8 Stream Error States

- The state of a stream may be tested through bts in class `ios_base`.

- The `eofbit` is set for an input stream after end-of-life is encountered. A program can use member function `eof` to determine whether end-of-file has been encountered on a stream after an attempt to extract data beyond the end of the stream.
- The `failbit` is set for a stream when a format error occurs on the stream and no characters are input. Usually, recovering from such errors is possible.
- The `badbit` is set for a stream when an error occurs that results in the loss of data. Generally, such serious failures are nonrecoverable.
- The `goodbit` is set for a stream if non of the bits `eofbit`, `failbit` or `badbit` is set for the stream.
- The `rdtstate` member function returns the stream's error state.
- the `clear` member function is uses to restore a stream's state to "good", so that I/O can process on that stream.
- The statement `cin.clear(ios::failbit)` **sets** the failbit.

### 15.9 Tying an Output Stream to an Input Stream

- C++ provides member function `tie` to synchronize the operation of an `istream` and an `ostream` to ensure that outputs appear before their subsequent inputs.
- The call `cin.tie(&cout);` ties cout to cin. To untie an input stream`inputStream`, from an output stream, use the call `inputStream.tie(0);`.

## Chapter 16: Exception Handling: A Deeper Look

### 16.1 Introduction

- An exception is an indication of a problem that occurs during a program's execution
- Exception handling enables you to create appliccations that can resolve (or handle) exceptions.
- Robust, fault-tolerant programs that can deal with problems continue executing or terminate gracefully.
- Exception handling provides a standard mechanism for processing errors. This is especially important when working on a project with a large team of programmers.

### 16.2 Example: Handling an Attempt to Divide by Zero

- In C++, division by zero using integer arithmentic typically causes a program to terminate prematurely. In floating-point arithmentic, some implementations allow it, which results in INF or -INF.
- Class `runtime_error` is a derived class of Standard Library class `exception`, and is the C++ standard base class for representing runtime errors.
- A typical exception class that derives from the `runtime_error` class defines only a constructor that passes an error-message string to the base-class `runtime_error` constructor.
- Every exception class that derives directly or indirectly from `exception` containst the `virtual` function `what`, which returns an exception object's error message.
- You are not required to derive a custom exception class, but doing so allows you to use the `virtual` function `what` to obtain an appropriate error message.
- A `try` block encloses statements that might cause exceptions and statements that would be skipped if an exception occurs.
- Exceptions may surface through explicily mentioned code in a `try` block, through calls to other functions and through deeply nested function calls initiated by code in a `try` block.
- At least one `catch` handler must immediately follow each `try` block. The exception parameter is declared as a _reference_ to the type of exception the `catch` handler can process.
- When an exception occurs in a `try` block, the `catch` handler that executes is the one whose type matches the thrown exception that occurred. If an exception paramenter includes an optional parameter name, the `catch` handler can use that parameter name to interact with the caught exception in the body of the `catch` handler.
- A `catch` handler typically reports the error to the user, logs it to a file, terminates the program gracefully or tries an alternate strategy to accomplish the failed task.
- It's a syntax error to place code between a `try` block and its corresponding `catch` handlers or between its `catch` handlers.
- Each `catch` handler can have only a single parameter.
- It's a logic error to catch the same type in two different `catch` handlers following a single `try` block.

** Termination Model of Exception Handling **

- When a `catch` handler finishes processing by reaching its closing right brace, the exception is considered handled and the local variables defined within the `catch` handler go out of scope. Program control does not  eturn to the point at which the exception occurred (known as the **throw point**), because the `try` block has expired. This is  known as the **termination model of exception handling**. Some languages use the  **resumption model of exception handling**, in which control resumes just after the throw point.
- If the `try` block completes its execution successfully, then the program ignores the `catch` handlers and program control continues with the first statement after the last `catch` following that `try` block.
- If an exception that occurs in a `try` block has no matching `catch` handler, or if an exception occurs in a statement that is not in a `try` block, the function that contains the  statement terminates immediately, and the program attempts to locate an enclosing `try` block in the calling function. This process is called **stack unwinding**.
- Normally, a `throw` statement specifies one operand. The operand of a `throw` can be of any type. If the operand is an object, we call it an **exception object**. However, a `throw` operand also can assume other values, such as the value of an expression that does not result  in an object of a classs (`throw x > 5`), or the value  of an `int` (`throw 5`).

- Use caution when throwing the result of a conditional expression (`?:`)- promotion rules could cause the value to be of a type different fromt the one expected.
- **A function should throw an exception before the error has an opportunity to occur**.
- Catching an exception object by reference eliminates the overhead of copying the object that represents the thrown exception.
- Associating each type of runtime error with an appropriately named exception object improves program clarity.

### 16.3 When to Use Exception Handling

- Exception handling is designed to process **synchronous errors**, which  occur when a statement executes, such as out-of-range subscripts, arithmetic over flow, division by zero, invalid function parameters, and unsuccessful memory allocation.
- Exception handling is not designed to process errors associated ith **asynchronous events** (disk I/O completions, network message arrivals, mouse clicks and keystrokes), which occur in parallel with, and independent of, the program's flow of control.
- Exception handling provides a single, uniform technique for processing problems. This helps programmers on large projects understand each other's error-processing code.
- Avoid using exceltion handling as an alternate form of flow of control.
- Exception handling enables predefined software components to communicate problems to application-specific components, which can then process the problems in an application-specific manner.
- When no exception occurs, exception-handling code incurs little or no performance penalty. Thus, programs that implement exception handling operate more efficiently than do programs that intermix error-handling code with program logic.
- Functions with common error conditions should return 0 or NULL (or other appropriate values, such as `bool`s) rather than throw exceptions. A program calling such a function can check the return value to determine success or failure of the function call.
- When a predefined component encounters a problem, that component needs a mechanism to communicate the problem to the application-specific compnent- the predefined component cannot know in advance how each application processes a problem that occurs.

### 16.4 Rethrowing an Exception

- It's possible that an exception handler, upon receiving an exception, might decide either that it cannot process that exception or that it can process the exception only partially. In such cases, the handler can *defer the exception handline (or a portion of it) to antoher exception handler*. In either case, you achieve this by **rethrowing the exception** via the statement `throw;`.
- The next enclosing `try` block detects the rethrown exception, which a `catch` handler listed  after that enclosing `try` block attempts to handle.
- Executing an empty `throw` statement outside a `catch` handler calls function `terminate`, which abandons exception processing and terminates the program immediately.

### 16.6 Processing Unexpected Exceptions

- Function `unexpected` calls the function registered with function `set_unexpected` (defined in header `<exception>`). If no function has been registered in this manner, function `terminate` is called by default. Cases in which function `terminate` is called include:
  1. the exception mechanism cannot find a matching `catch` for a thrown exception
  2. a destructor attemprs to `throw` an exception during sstack unwinding
  3. an attempt is made to rethrow an exception when ther's no exception currently being handled
  4. a call to function `unexpected` defaults to calling function `terminate`

- Function `set_terminate` can specify the function to invoke when `terminate` is called. Otherwise, `terminate` calls `abort`, which terminates the program without calling the destructors of any remaining objects of automatic or static storage class. This could lead to resource leaks when a program terminates prematurely.
- Aborting a program component due to an uncaught exception could leave a resource - such as a file stream or an I/O device - in a state in which other programs are unable to acquire the resource. This is known as a **resource leak**.
- Function `set_terminate` and function `set_unexpected` each return a pointer to the last function called by `terminate` and `unexpected`. This enables you to save the function pointer so it can be restored later.
- Functions `set_terminate` and `set_unexpected` take as arguments pointers to functions with `void` return types and no arguments.

### 16.7 Stack Unwinding


- When an exception is thrown but not cuaght in a particular scope, the function call stack is "unwound", and an attempt is made to `catch` the exception in the next outer `try...catch` block.
- Unwinding the function call stacck means that the function in which the exception was not caught terminates, all local variables in that  function are destroyed and control returns to the statement that originally invoked that function.
- If no `catch` handler ever catches this exception, function `terminate` is called to terminate the program.

### 16.8 Constructors, Destructors and Exception Handling

- How should an object's constructor respond when `new` fails because it was unable to allocate required memory for storing that object's internal representation? 
- The preferred method is to require the constructor to `throw` an exception that contains the error information, thus offering an opportunity for the program to handle the failure.
- Before an exception is thrown by a constructor, destructors are called for any member  objects built as part of the object being constructed. Destructors are called for every automatic object constructed in a `try` block before an exception is thrown.
- An exception could preclude the operation of code that would normally release a resource, causing a resource leak. One technique to resolve this problem is to initialize a local object to acquire the resource. When an exception occurs, the destructor for that object will be invoked and can free the resource.
- When an exception is thrown from the constructor for an object that's created in a `new` expression, the dynamically allocated memory for that object is released.

### 16.9 Exceptions and Inheritance

- Various exception classes can be derived from a common base class.
- If a `catch` handler catches a pointer or reference to an exception object of a base-class type, it also can `catch` a pointer or reference to all objects of classes publicly derived from that base class - this allows for polymorphic processing of related errors.
- Using inheritance with exceptions enables an exception handler to `catch` related errors with concise notation. One approach is to `catch` each type of pointer or reference to a derived-class exception object individually, but a more concise approach is to `catch` pointers or references to base-class exception objects instead.
- Catching pointers or references to derived-class exception objects individually is error prone, especiallly if you forget to test explicitly for one or more of the derived-class pointer or reference types.

### 16.10 Processing `new` Failures

- The C++ standard specifies that, when operator `new` fails, it `throw`s a **bad_alloc** exception (defined in header `<new>`).
- The C++ standard specifies that compilers can use an older version of `new` that returns 0 upon failure. For this purpose, header `<new>` defines object `nothrow`, which is uses as follows:
```
double *ptr = new( nothrow ) double[50000000];
```
- The preceding statement uses the version of `new` that does not throw `bad_alloc` exceptions to allocate an array of 50,000,000 `double`s.
- To make programs more robust, use the version of `new` that throws `bad_alloc` exceptions on failure.
- An additional feature for handling `new` failures is function `set_new_handler`. This function takes as its argument a pointer to a function that takes no arguments aand returns void. This pointer points to the function that will be called if `new` fails. This provides you with a uniform approach to handling all `new` failures, regardless of where a failure occurs in the program.
- Once `set_new_handler` register s a **`new` handler** in the program, operator `new` does not throw `bad_alloc` on failure; rather, it defers the error handling to the `new`-handler function.
- The C++ standard specifies that the `new`-handler function should perform one of the following tasks:
  1. Make more memory available by deleting other dynamically allocated memory (or telling the user to close other applications) and return to operator `new` to attempt to allocate memory again.
  2. Throw an exception of type `bad_alloc`.
  3. Call function `abort` or `exit` (both found in header `<cstdlib>`) to terminate the program.

### 16.11 Class unique_ptr and Dynamic Memory Allocation

- A common programming practice is to allocate dynamic memory, assign the address of that memory to a pointer, use the pointer to manipulate the memory and deallocate the memory with `delete` when the memory is no longer needed.
- If an exception occurs after successful memory allocation but before the `delete` statement executes, a _memory leak_ could occur. The C++ standard provides class template `unique_ptr` in header `<memory>` to deal with this situation.
- An object of class `unique_ptr` maintains a pointer to dynamically allocated memory. When a `unique_ptr` object destructor is called, it performs a `delete` operation on its pointer data member. Class template `unique_ptr` provides overloaded operators `*` and `->` so tht a `unique_ptr` object can be used just as a regular pointer variable is.
- Only one `unique_ptr` at a time can own a dynamically allocated object and the  object cannot be an array. By using its overloaded assignment operator or copy constructor, a `unique_ptr` can transfer ownership of the dynamic memory it manages.
- The last `unique_ptr` object that maintains the pointer to the dynamic memory will delete the memory.

### 16.12 Standard Library Exception Hierarchy

- Immediate derived classes of base-class `exception` include `runtime_error` and `logic_error`, both defined in header `<stdexcept>`. Each of them has several derived classes.
- Also derived from `exception` are the exceptions thrown by c++ operators: `bad_alloc`, `bad_cast`, `bad_typeid`, and `bad_exception`.
- Placing a `catch` handler that catches a base-class object before a `catch` that catches an object of a class derived from that base class is a logic error. The base-class `catch` catches all objects of classes derived from that base class, so the derived-class `catch` will never execute.
- Derived classes for `logic_error` are `invalid_argument`, `length_error`, and `out_of_range`.
- Derived classes for `runtime_error` are `overflow_error` and `underflow_error`.
- Exception classes need not be derived from class `exception`, so catching type `exception` is not guaranteed to `catch` all exceptions a program could encounter.
- To catch all exceptions potentially thrown in a `try` block, use `catch(...)`. One weakness of this approach is tha the type of the caught exception is unknown at compile time. Also, there is no way to refer to the exception object inside the exception handler.
- The standard `exception` hierarchy is a good starting point for creating exceptions. You can build programs that can `throw` standard exceptions, `throw` exceptions derived from the satandard exceptions or `throw` your own exceptions not derived from the standard ones.
- Use `catch(...)` to perform recovery that does not depend on the exception type. The exception can be rethrown to alert more specific enclosing `catch` handlers.

## Chapter 17: File Processing

### 17.1 Introduction

- Storage of data in memory is temporary. Files are used for data persistance - permanent retention of data. Computers store files on **secondary storage devices**.

### 17.2 Files and Streams.

- C++ views each file as a _sequence of bytes_. Each file ends either with an **end-of-file marker** or at a specific byte number recorded in an operating-system-maintained, administrative data structure.
- When a file is opened, an object is created, and a stream is associated with the object.
- To perform file processing in C++, headers <iostream> and <fstream> must be included. 
- Files are _opened_ by creating objects of `basic_ifstream` and `basic_ofstream` stream template specializations.

### 17.3 Creating a Sequential File

- C++ imposes no structure on a file. You must structure files to meet the application's requirements.
- An `ofstream` object is created to open a file for output, and two arguments are passed to the object's constructor: the **filename** and the **file-open mode**. For an `ofstream` object, the mode can be `ios::out` to output data to a file or `ios::app` to append data to the end of a file.
- Existing files opened with mode `ios::out` are **truncated**- all data in the  file is discarded. If the specified file does not yet exist, then the `ofstream` object creates the file using that filename.
- Use  caution when opernin an existing file for output (ios::out), especially when you want to preserve the file's contents, which will be discarded without warning.
- An `ofstream` object can be created without opening a sbpecific file- a file can be attached to the object later. For example, the statement
```
ofstream outClientFile;
```
- creates an `ofstream` object named `outClientFile`. The `ofstream` member function `open` opens a file and attaches it to an existing `ofstream` object as follows:
```
outClientFile.open("clients.dat", ios::out)
```
- Function `exit` is invoked to terminate a program. Argument 0 indicates that the program terminated normally; any other value indicates that the program terminated due to an error.
- Overloaded `ios` member function `operator void *` converts the stream to a pointer, so it can be tested as 0 (the null pointer) or nonzero (any other pointer value). When a pointer is used as a condition, C++ interprets a null pointer in a condition as the `bool` value `false` and interprets a non-null pointer as the `bool` value `true`.
- You can close the `ofstream` object explicitly, using member function `close` in the statement
```
outClientFile.close();
```

### 17.4 Reading Data from a Sequential File

- Creating an `ifstream` object opens a file for input. The `ifstream` constructor can receive the filename and the file open mode as arguments.
- Open a file for input only (using ios::in) if the file's contents should not be modified. This prevents unintentional modification of the file's contents and is another example of the principle of least privilege.
- Objects of class `ifstream` are opened for input by default, so the statement `ifstream inClientFile("clients.txt");` opens the file for input.
- To retrieve data sequentially from a file, programs normally start reading from the  beginning of the file and read all the data consecutively until the desired data is found.
- Both `istream` and `ostream` provide member functions for repositioning the **file-position pointer** (the byte number of the  next byte in the file to be read or written). These member functions are `seekg` and `seekp` (seek get and seek put).
- Each `istream` object has a _get pointer_, and each `ostream` object has a _put pointer_.
- The statement `inClientFile.seekg(0);` repositions the file-position pointer to the beginning of the file attached to `inClientFile`.
- The argument to `seekg` is a `long` integer. A second argument can be specified to indicate the **seek direction**, which can be `ios::beg` for positioning relative to the beginning of a stream, `ios::cur` for positioning to the current position in a stream, or `ios::end` for positioning relative to the end of a stream.
- Member function `tellg` and `tellp` are provided to return the current locations of the _get_ and _put_ pointers.

### 17.5 Updating Sequential Files

- Data that is formatted and written to a sequential file cannot be modified without the risk of destroying other data in the file.
- The formatted input/output model usually is not used to update records in place.

### 17.6 Random-Access Files

- Sequential files are inappropriate for **instant-access applications**, in which a particular record must be located immediately. Common instant-access applications are airline reservation systems, banking systems, and other  **transaction-processing systems** that require rapid access to specific data.
- This kind of required instant access is made possible with **random-access files**. Individual records of a random-access file can be accessed directly (and quickly)  without having to search other records.
- C++ does not impose structure on a file, so the application that wants to use random-access files must create them. The easiest methed is to require that all records in a file be of the _same fixed length_.
- A random-access file  is like a railroad train with many same-size cars - some empty and some with contents.

### 17.7 Creating a Random-Access File

- When a stream is associated with a file, function `write` writes the data _at the location specified by the put file-position pointer_, and function `read` inputs bytes at the location in the file specified by the  "get" file-position pointer.

**Writing Bytes with `ostream` Member Function `write`**

- When writing the integer `number` to a file, instead of using the statement `outFile << number;` which for a four-byte integer could print as few digits as one or as many as 11 (10 digits plus a sign, each requiring a single byte of storage), we can use the statement:

```
outFile.write(reinterpret_cast <const char *> (&number), sizeof(number));
```

which always writes the binary version of the integer `number`'s four bytes. Function `write` treats its first argument as a group of bytes by viewing the object in memory as a `const char *`, which is a pointer to a byte. Starting from that location, function `write` outputs the number of bytes specified by its second argument - an integer of type `size_t`. `istream` function` read` can subsequently be used to read the four bytes back into integer variable `number`.

**Converting Between Pointer Types with the `reinterpret_cast` Operator**

- Most pointers that we pass to function `write` as the first argument are not of type `const char *`. We must convert the pointers to objects of other types to type `const char *`.
- C++ provides the `reinterpret_cast` operator for cases like this in which a pointer of one type must be cast to an _unrelated_ pointer type.
- A `reinterpret_cast` is performed at compile time and soes not change the value of the object to which its operand points. Instead, it requests that the compiler reinterpret the operand as the target type (specifieed in the angle brackets).

- Random-access file-processing programs rarely write a single field to a file. Typically, they write one object of a class at a time.
- It's easy to use `reinterpret_cast` to perform dangerous manipulations that could lead to serious execution-time errors.
- Using `reinterpret_cast` is compiler dependent and can cause programs to behave differently on different platforms. It should not be used unless absolutely necessary.
- A program that reads unformatted data (written by `write`) must be compiled and executed on a system compatible with the program that wrote the data, because different systems may represent internal data differently.

### 17.8 Writing Data Randomly to a Random-Access File

- The combination of `fstream` functions `seekp` and `write` allows us to store data at _exact_ locations in the file. Function `seekp` sets the `put` file-position pointer to a specific position in the file, and function `write` outputs the data.

### 17.9 Reading from a Random-Access File Sequentially

- The `istream` function `read` inputs a specified number of bytes from the current position in the specified stream into an object. Function `read` requires a first argument of type `char *`.
- Sorting using direct-access techniques is relatively fast, compared to the insertion sort we used in Chapter 7. The speed is achieved by making the file large enough to hold every possible record that migh tbe created. This means that the file could be occupied sparsely most of the time, resulting in a waste of storage. This is an example of the _space-time trade-off_: By using large amounts of space, we can develop a much faster sorting algorithm.

### 17.11 Object Serialization

- An object's member functions are _not_ input or output with the object's data; rather, _one copy of the class's member functions remains available internally and is shared by all objects of the class_.
- When object data members are output to a disk file, we lose the object's type information. We store only the vaues of the object's attributes, not type information, on the disk. If the program that reads this data knows the object type to which the data corresponds, the program can read the data into an object of that type as we did in the random-access file examples.
- An interesting problem occurs when we store obejcts of different types in the same file. How can we distinguish them as we read them into a program? The problem is that objects typically do _not_ have type fields.
- One approach is called **object serialization**. A so-called **serialized object** is an objecct represented as a sequence of bytes that includes the object's data as well as information about the object's type and the types of data stored in the object. After a serialized object has been written to a file, it can be read from the file and **deserialized** (the type information and bytes that represent the object ad  its object can be used to recreate te object in memory).
- C++ does not provide a built-in serialization mechanism. There are third party and open source libraries that support object serialization. The Boost C++ libraries provide support for serializing objects in text, binary, and extensible markup language.

## Chapter 18: Class `string` and String Stream Processing

### 18.1 Introduction

- The class template `basic_string` provides typical string-manipulation operations such as copying, searching, etc. The template definitionn and all support facilities are defined in `namespace std`; these include the `typedef` statement
  ```
  typedef basic_string<char> string;
  ```
  that creates the alias type `string` for `basic_string<char>`. A typedef is also provided for the `wchar_t` type (`wstring`). Type `wchar_t` stores characters for supporting other character sets (it's commonly used to represent Unicode).

- To use `string`s, include header `<string>`.
- A `string` object can be initialized with a constructor argument as in
  ```
  string text("Hello"); // creates a string from a const char *
  ```
  or with two constructor arguments as in
  ```
  string name(8, 'x'); // string of 8 'x' characters
  ```
- Class `string` also provides a _default constructor_ (creates an empty string) and a _copy constructor_.
- A `string` also can be initialized in its definition as in
  ```
  string month = "March"; // same as: string month("March");
  ```
  The `=` is not an assignment, it's an _implicit call_ to the `string` _class constructor_, which does the conversion.
- Class `string` provides no conversions from `int` or `char` to `string` in a `string` definition. For example, the definitions
  ```
  string error1 = 'c';
  string error2 = ('u');
  string error3 = 22;
  string error4(8);
  ```
  result in syntax errors. Assigning a single character to a `string` object is permitted in an assignment statement as in
  ```
  string1 = 'n':
  ```
- `string`s are not necessarily null terminated.
- The length of a `string` can be retrieved with member function `length` and with member function `size`.
- The subscript operator `[]` can be used with `string`s to access and modify individual characters. `string`s have a first subscript of 0 and a last subscript of `length()` - 1.
- Most `string` member functions take as arguments a starting subscript location and the number of characters on which to operate.
- The stream extraction operator (`>>`) is overloaded to support strings. The statements
  ```
  string stringObject;
  cin >> stringObject;
  ```
  declare a `string` object and read a `string` obejct from `cin`. Input is delimmited by white-space characters. When a delimiter is encountered, the input operation is terminated. Function `getline` also is overloaded for `string`s. Assuming `string` is a `string`, the statement
  ```
  getline(cin, string);
  ```
  reads a `string` from the keyboard into `string1`. Input is delimited by a newline (`'\n'`), so `getLine` can read a line of text into a `string` object. You can specify an alternate delimiter as the optional third argument to `getline`.

### 18.2 `string` Assignment and Concatenation

- Member function `assign` is used to make a separate copy of a `string` object (both objects become independent).
- Class `string` also provides an overloaded member function `assign` that copies a specified number of characters, as in
  ```
  targetString.assign(sourceString, start, numberOfCharacters);
  ```
  where `sourceString` is the `string` to be copied, `start` is the starting subscript and `numberOfCharacters` is the number of characters to copy.
- Member function `at` provides **checked access** (or **range checking**): going past the end of the `string` throws an `out_of_range` exception. The subscript operator `[]` does not provide check access. This is consistent with its use on arrays.
- Accesing an element beyond the size of the `string` using the subscript operator is an unreported logic error.

### 18.3 Comparing `string`s

- When function `compare` is used to compare `string1` to `string2`:
  The result is 0 if the `string`s are equivalent.
  The result is a positive number if `string1` is **lexicographically** greater than `string2`.
  The result is a negative number if `string1` is lexicographically less than `string2`.

### 18.4 Substrings

- Class `string` provides member function `substr` for retrieving a substring from a `string`. The result is a new `string` object that's copied from the source `string`. The first argument specifies the beginning subscript of the desired substring; the second argument specifies the substring's length.

### 18.5 Swapping strings

- Class `string` provides member function `swap` for swapping `string`s.

### 18.6 string Characteristics

- Class `string` provides member functions for gathering information about a `string`'s size, length, capacity, maximum length, and other characteristics.
- A `string`'s size or length is the number of characters currently stored in the `string`.
- A `string`'s capacity is the number of characters that can be stored in the `string` withoug allocating more memory. The exact capacity of a `string` depends on the immplementation.
- The `maximum size` is the largest possible size a `string` can have. If this value is exceeded, a `length_error` exception is thrown.
- Member function `resize` increases the length of the `string`.

### 18.7 Finding Substrings and Characters in a `string`

- Class `string` provides `const` member functions for finding substrings and characters in a `string`: `find`, `rfind`, `find_first_of`, `find_last_of`, and `first_not_of`.
- If the `string` is not found, the value `string::npos` is returned.

### 18.8 Replacing Charactes in a `string`

- `string` member function `erase` erases everything from and including the starting character to the end of the string.
- `string` member function `replace` replaces all occurrences of a given character with the specified one.

### 18.9 Inserting Characters into a `string`

- Member function `insert` inserts content from one `string` into another one.

### 18.10 Conversion to C-Style Pointer-Based char * Strings

- `string` member function `copy` can be used to copy a `string` object into a `char` array. A null character must be manually added to the array.
- Function `c_str` provides a `const char *` that points to a null terminated C-style string.
- Function `data` returns a non-null terminated C-style character array.
- Not terminating the character array returned by `data` with a null character can lead to execution-time errors.
- Whenever possible, use the more robust `string` class object rather than C-style pointer-based strings.

### 18.11 Iterators

- Class `string` provides iterators for forward and backward traversal of `string`s.
- Iterators provide access to individual characters with syntax that's similar to pointer operations. _Iterators are not range checked_.
- A `const_iterator` is an iterator that cannot modify the `string`, and it is initialized to the beginning of the `string` with the `string` class member function `begin`. Two versions of `begin` exist: one that returns an `iterator` for iterating through a non-`const string` and a `const` version that returns a `const_iterator` for iterating through a `const string`.
- Class `string` member function `end` returns an `iterator` for the position past the last element of a `string`.
- Class `string` provides member functions `rend` and `rbegin` for accessing individual `string` characters in reverse from the end of a `string` toward the beginning. Member functions `rend` and `rbegin` return `reverse_iterators` or `const_reverse_iterators`.
- When the operations involving the iterator should not modify the data being processed, use a `const_iterator`. This is another example of employing the principle of least privilege.

### 18.12 String Stream Processing

- C++ stream I/O includes capabilities for inputting from, and outputting to, `string`s in memory. These capabilities often are referred to as **in-memory I/O** or **string stream processing**.
- Input from a `string` is supported by class `istringstream`. Output to a `string` is supported by class `ostringstream`.
- Programs that use in-memory formatting must include the `<sstream>` and `<iostream>` headers.
- One application of these technique is data validation. A program can read an entire line at a time from the input stream into a `string`. Next, a validation routine can scrutinize the contents of the `string` and correct the data if necessary.
- Outputting to a `string` is a nice way to take advantage of the powerful output formatting capabilities of C++ streams. Data can be prepared in a `string` to mimic the edited screen format. That `string` could be written to a disk file to preserve the screen image.
- An `istringstream` object inputs data from a `string` in memoryy to program variables. Data is stored in an `istringstream` object as characters. Input from the `istringstream` object works identically to input from any file. The end of the `string` is interpreted by the `istringstream` object as end-of-file.

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

## Chapter 20: Custom Templatized Data Structures

### 20.1 Introduction

- This chapter introduces **dynamic data structures** that grow and shrink during execution.
- **Linked lists** are collections of data items logically "lined up in a row"- insertions and removals are made anywhere in a linked list.
- **Stacks** are  importand in compilers and operating systems: Insertions and removals are made only at one end of a stack, its top.
- **Queues** represent wwaiting lines; insertions are made at the back (also referred to as the tail) of a queue and removals are made from the fron (also referred to as the head) of a queue.
- **Binary trees** facilitate high-speed searching and sorting of data and efficient elimination of duplicate data items among other applications.

### 20.2 Self-Referential Classes

- A **self-referential class** contains a member that points to a class object of the same class type. A "`next`" pointer member in a self-referential class is referred to as a **link**.
- Self-referential class objects can be linked together to form useful data structures such as lists, queues, stacks, and trees.
- A null (0) pointer normally indicates the end of a data structure just as the null character ('\0') indicates the end of a string.
- Not setting the link in the last node of a linked data structure to null (0) is a (possibly fatal) logic error.

### 20.3 Dynamic Memory Allocation and Data Structures

- Creating and maintaining dynamic data structures requires dynamic memory allocation, which enables a program to obtain more memory at execution time to hold new nodes. When that memory is no longer needed by the program, the memory can be _released_ so that it can be reused to allocate other objects in the future. The limit for dynamic memory allocation can in theory be as large as the aount of available physical memory in the computer or the amount of available virtual memory in a virtual memory system.
- The `new` operator takes as an argument the type of the object being dynamically allocated and returns a pointer to an object of that type:
```
Node *newPtr = new Node( 10 ); // create Node with data 10
```
- The `delete` operator runs the `Node` destructor and deallocates memory allocated with `new`. To free memory dynamically allocated by the preceding `new`, use the statement
```
delete newPtr;
```
- `newPtr` itself is not deleted; rather the destructor of the `Node` object that `newPtr` points to iis called and  the object's memory is freed. If pointer `newPtr` has the null pointer value 0, the preceding statement has no effect. It is _not_ an error to delete a null pointer.

### 20.4 Linked Lists

- A linked list is a linear collection of self-referential class objects, called **nodes**, connected by **pointer links**. A linked list is accessed  via a pointer to the list's first node. Each subsequent node is accessed via the link-pointer member stored in the precious node. By convenction, the link pointer in the last node of a list is set to null (0) to mark the end of the list.
- Data is stored in a linked list dynamically - each node is created as necessary.
- A node can contain data of any type, including objects of other classes. If nodes contain base-class pointers to base-class and derived-class objects related by inheritance, we can have a linked list of such nodes and process them _polymorphically_  using `virtual` function calls.
- Stack and queues are also **linear data structures**, and  can be viewed as constrained versions of linked lists.
- Trees are **nonlinear data structures**.
- Lists of data can be stored in arrays, but linked lists provide several advantages. A linked list is appropriate when the number of data elements to be represented at one time is _unpredictable_. Lined lists are dynamic, so the length of a list can increase or decrease as necessary. The size of a "conventional" C++ array, however, cannot be altered, because th array size is fixed at compile time. "Conventional" arrays can become full. Linked lists become full only when the system has insufficient memory to satisfy additional dynamic sotrage allocation requests.
- An array can be declared to contain more elements that the number of items expected, but this can waste memory. Linked lists can provide better memory utilization in these situations. Linked lists allow the program to adapt at runtime.
- Class template `vector` implements a dynamically resizable array-based data structure.
- Linked lists can be maintained in sorted order by inserting each new wlement at the proper point in the list. Existing list elements do not need to be moved. Pointers merely need to be updated to point to the correct node.
- Insertion and deletion in a sorted array can be time consuming. A linked list allows efficient insertion operations anywhere in the list.
- THe elements of an array are stored contiguously in memory. This allows immediate access to any element. Linked lists do not afford such immediat direct access to their elements. So accessing individual elements in a linked list can be considerably more expensive than accessing individual elements in an array.
- The selection of a data structure is typically based on the performance of specific operations used by a program and the order in which the data items are maintained in the data structure.
- Using dynamic memroy allocation (instead of fixed-size arrays) for data structures that grow and shrink at execution time can save memory. Keep in mind, however, that pointers occupy space and that dynamic memory allocation incurs the overhead of function calls.
- Assign null(0) to the link member  of a new node. Pointers must be initialized before they're used.

**Circular Linked Lists and Double Linked Lists**

- A **singly linked list** begins with a pointer to the first node, and each node contains a pointer to the next node "in sequence". This list terminates with a node whose pointer member has the value 0. A singly liinked list may be traversed in only _one_ direction.
- A **circular, singly linked list** begins with a pointer to the first node, and each node contains a pointer to the next node. The "last node" does not contain a 0 pointer; rather, the pointer in the last node points back to the first node, thus closing the "circle".
- A **double linked list** allows traversals _both forward and backward_. Such a list is often implemented with two "start pointers": one that pointer to the first element of the list to allow front-to-back traversal, and one that points to the last element to allow back-to-front traversal. Each node has both a forward pointer and a backward pointer.
- In a **circular, doubly linked list**, the forward pointer of the last node points to the first node, and the backward pointer of the first node points to the last node, thus closing the "circle".

### 20.5 Stacks

- A stack data structure allows nodes to be added to the stack and removed from the stack only at the _top_. For this reason, a stack is referred to as a _last-in, first out (LIFO)_ data structure. One way to implement a stack is a constrained version of a linked list. In such an implementation, the link member in the last node of the stack is set to null (zero) to indicate the _bottom_ of the stack.
- The primary member functions used to manipulate a stack are `push` and `pop`. Function `push` _inserts_ a new node at the top of the stack. Function `pop` _removes_ a node from the top of the stack, stores the popped value in a reference variable that's passed to the calling function and returns `true` if the `pop` operation was successful (`false` otherwise).
- When we implement the `Stack`'s member functions, we then have each of these call the appropriate member function of the `List` class- this is referred to as **delegation**.
- The explicit use of `this` is required so the compiler can properly resolve identifiers in template definitions.  A **dependent name** is an identifier that depends on a template parameter. Resolution of dependent names occurs when the template is instantiated. The identifier for a function that takes no arguments in the superclass is a **non-dependent name**. Such identifiers are normallly resolved at the point where the template is defined. If the template has not yet been instantiated, then the code for the function with the non-dependent name does not yet exist and some compilers will generate compilation errors. Adding the explicit use  of `this->` makes the calls to the base class's member functions dependent on the template parameter and ensures that the code will compile properly.

### 20.6 Queues

- A **queue** similar to a supermarket checkout line- the _first_ person in line is serviced  _first_, and other customers enter the line at the _end_ and _wait_ to be serviced. Queue nodes are removed only from the head of the queue and are inserted only at the tail of the queue. For this reason, a queue is referred to as a first-in, first-out (FIFO) data structure. The insert and remove operations are known as **enqueue** and **dequeue**.

### 20.7 Trees

- Linked lists, stacks, and queues are linear data structures. A tree is a nonlinear, two-dimensional data structure. Tree nodes contain two or more links.
- Binary trees are trees whose nodes all contain two links (none, one, or both of which may be null).
- The **rot node** is the first node in a tree. Each link in the root node refers to a **child**. The **left child** is the root node of the **left subtree**. The **right child** is the root node of the **right subtree**.
- The children of a given node are called **sublings**.
- A node with no children is a **leaf node**.
- A **binary search tree** (with no duplicate node values) has the characteristic that the values in any left subtree are _less than the value_ in its **parent node**, and the values in any right subtree _are greater than_ the value in its parent node.
- A binary search tree can be walked through with an **inorder**, **preorder**, and **postorder** **traversals**.
- A node can only be inserted as a leaf node in a binary search tree.
- The inorder traversal of a binary search tree prints the node values in ascending order. The  process of creating a binary search tree actually _sorts_ the data - thus, this process is called the **binary tree sort**.
- The binary search tree facilitates **duplicate elimination**.
- Searching a binary tree for a value that matches a key value is also fast. If the tree is balanced, then each branch contains about half the number of nodes in the tree. Each comparison of a node to the search key eliminates half the nodes. This is called an O(log n) algorithm. So a binary search tree with n elements would require a maximum of log 2 n comparisons either to find a match or to determine that no match exists.
- The level-order traversal of a binary tree visits the nodes of the tree row by row, starting at the root node level. On each levvel of the tree, the nodes are visited from left to right.

## Chapter 21: Bits, Characters, C Strings and `struct`s

### 21.1 Introduction

- C++ structures may contain access specifiers, member function, constructors, and destructors. The only differences between structures and classes in C++ is that structure members default to `public` access and class members default to `private` access when no access specifiers are used, and that structures default to `public` inheritance, whereas classes default to `private` inheritance.

### 21.2 Structure Definitions

- Consider hte following structure definition:

```
struct Card
{
  string face;
  string suit;
} // end struct Card
```

- Keyword `struct` introduces the definition for structure `Card`. The identifier `Card` is the **structure name** and is used in C++ to declare variables of the **structure type**. Data declared within the braces are the sructure's members. 
- Comparing variables of structure types is a compilation error.
- Because the size of data items of a particular type is machine dependent, and because storage alignment considerations are machine dependent, so too is the representation of a structure.

### 21.3 `typedef`

- Keyword `typedef` provides a mechanism for creating synonyms (or aliases) for previously defined data types. Names for structure types are often defined with `typedef` to create shorter, simpler or more readable type names.
- The statement `typedef Card *CardPtr;` defines the new type name CardPtr as a synonym for type `Card *`.
- Synonyms for built-in data types can be created with `typedef` to make programs more portable. For example, a program can use `typedef` to create alias `Integer` for four-byte integers. `Integer` can then be aliased to `int` on systems with four-byte integers and can be aliased to `long int` on systems with two-byte integers where `long int` values occupy four bytes. Then, you simply declare all four-byte integers variables to be of type `Integer`.

### 21.5 Bitwise Operators

- Bitwise operators are used to manipulate the bits of integral operands (char, short, int, and long; both signed and unsigned). Unsigned integers are normally used with the bitwise operators.
- Bitwise data manipulations are machine dependent.
- the bitwise operators are:
  - bitwise AND (`&`)
  - bitwise inclusive OR (`|`)
  - bitwise exclusive OR (`^`)
  - left shift (`<<`)
  - right shift (`>>`)
  - bitwise complement (`~`), also known as the **one's complement**
- Often, the bitwise AND operator is used with an operand called a **mask**. A mask is an integer value with specific bits set to 1. Masks are used to hide some bits in a value whie selecting other bits.
- Using the logical AND operator (`&&`) for the bitwise AND operator (`&`) and vice versa is a logic error.
- Using the logical OR operator (`||`) for the bitwise AND operator (`|`) and vice versa is a logic error.
- The result of shifting a value is undefined if the right operand is negative or if the right operand is greater than or equal to the number of bits in which the left operand is stored.
- the result of right-shifting a signed value is machine dependent. Some machines fill with zeros and others use the sign bit.

### 21.6 Bit Fields

- C++ provides the ability to specify the number of bits in which an integral tpe or `enum` type member of a class or a structure is stured. Such a member is referred to as a **bit field**. Bit fields enable _better memory utilization_ by storing data in the minimum number of bits required. Bit field members must be declared as an integral or enum type.
- Bit fields help conserve storage.
- A bit field is declared by following an integral type or `enum` type with a colon (`:`) and an integer constant representing the **width of the bit field**. The width must be an integer constant:
```
unsigned face : 4;
unsigned suit : 2;
usnigned color : 1;
```
- It's possible to specify an **unnamed bit field**, in which case the field is used as padding in the structure:
```
unsigned a : 13;
unsigned   : 3; // align to next storage-unit boundary
unsigned b : 4;
```
- An **unamed bit field with a zero width** is used to align the next bit field on a new storage-unit boundary:
```
unsigned a : 13;
unsigned   : 0; // algin to next storage-unit boundary
unsigned b : 4; 
```
- Bit-field manipulations are machine-dependent. For example, some computers allow bit fields to cross word boundaries, whereas others do not.
- Attempting to access individual bits of a bit field with subscripting as it they were elements of an array is a compilation error. Bit fields are not "arrays of bits".
- Attempting to take the address of a bit field (the & operator may not be used with bit fields because a pointer can designate only a particular byte in memory and bit fields can start in the middle of a byte) is a compilation error.
- Although bit fields save space, using them can cause the compiler to generate slower-executing machine-language code. This occurs because it takes extra machine-language operations to access only portions of an addressable storage unit. This is one of many examples of the space-time trade-offs that occur in computer science.

### 21.7 Character-Handling Library

- The character-handling library includes several functions that perform usesul tests and manipulations of character data. Each function receives a character- represented as an `int` or `EOF` as an argument. Characters are often manupulated as integers.
- `EOF` has the value of -1 and that some hardware architectures do not allow negative values to be stored in `char` variables.
- When using function from the character-handling library, include the `<cctype>` header.

- `int isdigit(int c)`
- `int isalpha(int c)`
- `int isalnum(int c)`
- `int isxdigit(int c)`  
Returns 1 if c is a hexadecimal digit character.                            |
- `int islower(int c)`
- `int isupper(int c)`  
- `int tolower(int c)`  
- `int toupper(int c)`  
- `int isspace(int c)`  
Returns 1 if c is a white-space character: \n, ' ', \f, \r, \t, \v          |
- `int iscntrl(int c)`  
Returns 1 if c is a control charaacter: \n, \f, \r, \t, \v ,\a, \b
- `int ispunct(int c)`  
Returns i if c is a printing character other than a space, digit or letter.
- `int isprint(int c)`  
Returns 1 if c is a printing character including space.
- `int isgraph(int c)`  
Returns ` if c is a printing character other than space.

### 21.8 Pointer-Based String Manipulation Functions

- The string-handling library provides many useful functions for manipulating string data, comparing strings, searching strings for characters and other strings, tokenizing strings (separating strings into logical pieces such as the separate words in a sentence) and determining the length of strings.
```
char  *strcpy(char *s1, const char *s2);
```
- Copies the sring s2 into character array s1. The  value of s1 is returned.
```
char *strncpy(char *s1, const char  *s2, size_t n);
```
- Copies at most n characters of the string s2 into the character array s1. The value of s1 is returned.
``` 
char *strcat(char *s1, const char *s2);
```
- Appends the string s2 to s1. The first character of s2 overwrites the terminating null character of s1. The value of s1 is returned.
```
char *strncat(char *s1, const char *s2, size_t n);
```
- Appends at most n characters of string s2 to string s1.
```
int strcmp(const char *s1, const char *s2);
```
- Compares the string s2 wwith the string s2. The functions returns a value of zero, less than zero or greater than zero if s1 is equal to, less than, or greater than s2, respectivvely.
```
int strncmp(const char *s1, const char *s2, size_t n);
```
- Compares up to n characters of the string s2 with the string s2.
```
char *strtok(char *s1, const char *s2);
```
- A sequence of calls to strtok breaks string s1 into "tokens"- logical pieces such as words in a line of text.
```
size_t strlen(const char  *s);
```
- Determines the length of string s. The number of characters preceding the terminating null character is returned.

- Forgetting to include the `<string>` header when using functions from the string-handling library causes compilation errors.
- When using `strncpy`, the terminating null character of the second argument (a `char *` string) will not be copied if the number of characters specified by strncpy's third argument is not greater than the second argument's length. In that case, a fatal error may occur if you do not  manually terminate the resulting `char *` string  with a null character.
- Assuming that `strcmp` and `strncmp` return one (a true value) when their arguments  are equal is a logic error. Both functions return zero (C++'s false value) for equality. Therefore, when tersting two strings for equality, the result of the `strcmp` or `strncmp` function should be compared with zero to determine whether the strings are equal.
- Not realizing that `strtok` modifies the string being tokenized, then attempting to use that string as if it were the original unmodified string is a logic error.

### 21.9 Pointer-Based String-Conversion Functions

- The following **string-conversion functions** are available through the **general-utilities library `<cstdlib>`**.

```
double atof(const char *nPtr);
```
- Converts the string nPtr to double. If the string cannot be converted, 0 is returned.
```
int atoi(const char *nPtr);
```
- Converts the string nPtr to int. If the string cannot be converted, 0 is returned.
```
long atol(const char *nPtr);
```
- Converts the string nPtr to long int. If the string cannot be converted, 0 is returned.
```
double strtod(const char *nPtr, char **endPtr);
```
-Converts the string nPtr to double. endPtr is the address of a pointer to the rest of the string after the double. If the string cannot be converted, 0 is returned.
```
double strtol(const char *nPtr, char **endPtr, int base);
```
-Converts th e string nPtr to long. endPtr is the address of a pointer to the rest of the string after the double. If the string cannot be converted, 0 is returned.
```
double strtoul(const char *nPtr, char **endPtr, int base);
```
-Converts th e string nPtr to unsigned long. endPtr is the address of a pointer to the rest of the string after the double. If the string cannot be converted, 0 is returned.

### 21.10 Search Functions of the Pointer-Based String-Handling Library

```
char *strchr(const char *s , int c);
```
- Locates the first occurrence of character c in string s. If c is found, a pointer to c in s is returned. Otherwise, a null pointer is returned.
```
char *strrchr(const char *s, int c);
```
- Searches from the end of string s and locates the last occurrence of character c in string s . If c is found, a pointer to c in string s is returned. Otherwise, a null pointer is returned.
```
size_t strspn(const char *s1, const char *s2);
```
- Determines and returns the length of the initial segment of string s1 consisting only of characters contained in string s2.
```
char *strpbrk(const char *s1, const char *s2);
```
- Locates the first occurrence in string s1 of any character in string s2 . If a character from string s2 is found, a pointer to the character in string s1 is returned. Otherwise, a null pointer is returned.
```
size_t strcspn(const char *s1, const char *s2);
```
- Determines and returns the length of the initial segment of string s1 consisting of characters not contained in string s2 .
```
char *strstr(const char *s1, const char *s2);
```
- Locates the first occurrence in string s1 of string s2 . If the string is found, a pointer to the string in s1 is returned. Otherwise, a null pointer is returned.

### 21.11 Memory Functions of the Pointer-Based String-Handling Library

- The functions treat blocks of memory as arrays of bytes. These functionc can manipulate any block of data.

```
void *memcpy(void *s1, const void *s2, size_t n);
```
- Copies n characters from the object pointed to by s2 into the object pointed to by s1 . A pointer to the resulting object is returned. The area from which characters are copied is not allowed to overlap the area to which characters are copied.

```
void *memmove(void *s1, const void *s2, size_t n);
```
- Copies n characters from the object pointed to by s2 into the object pointed to by s1 . The copy is performed as if the characters were first copied from the object pointed to by s2 into a temporary array, then copied from the temporary array into the object pointed to by s1 . A pointer to the resulting object is returned. The area from which characters are copied is allowed to overlap the area to which characters are copied.

```
int memcmp(const void *s1, const void *s2, size_t n);
```
- Compares the first n characters of the objects pointed to by s1 and s2 . The function returns 0 , less than 0 , or greater than 0 if s1 is equal to, less than or greater than s2, respectively.

```
void *memchr(const void *s, size_t n);
```
- Locates the first occurrence of c (converted to unsigned char ) in the first n characters of the object pointed to by s . If c is found, a pointer to c in the object is returned. Otherwise, 0 is returned.

```
void *memset(void *s, int c, size_t n);
```
- Copies c (converted to unsigned char) into the first n characters of the object pointed to by s. A pointer to the result is returned.

- The pointer parameters to these functions are declared `void *`. A pointer to any data type can be assigned directly to a pointer of type void *. For this reason, these functions can receive pointers to any data type.
- A pointer of type void * cannot be assigned directly to a pointer of any other data type. Because a void * pointer cannot be derefenced, each function receives a size argument that specified the number of characters (bytes) the function will process.
- String-manipulation functions other than memmove that copy characters have undefined results when coying takes place between parts of the same string.

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

