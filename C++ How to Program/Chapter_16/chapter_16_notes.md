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
