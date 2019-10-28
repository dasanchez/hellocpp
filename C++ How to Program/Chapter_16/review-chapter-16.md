# Self Review Exercises: Chapter 16

**16.1** List five common examples of exceptions.

Invalid argument, length error, out of range, overflow error, and underlfow error.

**16.2** Give several reasons why exception handling techniques should not be used for conventional program control.
- They make harder to identify what constitutes an error.
- They are meant to be used with scenarios that do not present themselves frequently, which could add unnecessary performance issues.
- Additional exceptions make it more dfficult to handle exception cases.

**16.3** Why are exceptions appropriate for dealing with errors produced by library functions?

Because a library function may not handle our specific application.

**16.4** What's a "resource leak"?

When the stack unwinds without deleting a pointer to a resource, the resource may end up in a state where it's no longer accessible (another program, or the same program may not be able  to acquire the resource).

**16.5** If no exceptions are thrown in a `try` block, where does control proceed to after the `try` block completes execution?

Control continues right after the `catch` block(s) following the `try` one.

**16.6** What happens if an exception is thrown outside a `try` block?

The `terminate` function is called.

**16.7** Give a key advantage and a key disadvantage of using `catch(...)`.

Advantage: it will handle any exceptions that have not been identified so far.
Disadvantage: it does not provide a reference to a exception object, so we don't know what kind of exception it is.

**16.8** What happens if no `catch` handler matches the type of a thrown object?

Code returns to the calling function to until an appropriate `catch` block is found, or until control returns to `main`, in which case `terminate` is called.

**16.9** What happens if several handlers match the type of the thrown object?

Only the first one is executed before proceeding with execution after the try/catch block.

**16.10** Why would you specify a base-class type as the type of a `catch` handler, then `throw` objects of derived class types?

We can catch related types of exceptions this way.

**16.11** Suppose a `catch` handler with a precise match to an exception object type is available. Under what circumstances might a different handler be executed for exception objects of that type?

A base-class handler would catch all derived types.

**16.12** Must throwing an exception cause program termination?

It depends on the application. Throwing an exception _will_ terminate the block where the exception was thrown.

**16.13** What happends when a `catch` handler `throws` and exception?

The exception will be processed by the handler associated with the `try` block enclosing the handler that caused the exception.

**16.14** What doe the statement `throw;` do?

It rethrows the exception if it appears in a `catch` handler, otherwise `unexpected` is called.