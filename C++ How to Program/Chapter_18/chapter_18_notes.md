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
