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
