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
