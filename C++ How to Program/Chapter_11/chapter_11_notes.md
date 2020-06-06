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
