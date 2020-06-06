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
