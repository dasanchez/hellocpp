# Self-Review Exercises

**15.1** Fill in the blanks:

a) Input/output in C++ occurs as **streams** of bytes.
b) The stream manipulators for justification are **left**, **right**, and **internal**.
c) Member function **cout.flags()** can be used to set and reset format state.
d) Most C++ programs that do I/O should include the **<iostream>** header that  containst the declarations for all stream-I/O operations.
e) When using parameterized manipulators, the  header **<iomanip>** must be  included.
f) Header **<fstream>** conatins the declarations required for file processing.
g) The `ostream` member function **write** is used to perform unformatted output.
h) Input operations are supported by class **istream**.
i) Standard error stream outputs are supported by class **cerr or clog**.
j) Output operations are supported by class **ostream**.
k) The symbol for the stream insertion operator is **<<**.
l) The four objects that correspond to the standard devices on the system include **cin**, **cout**, **cerr**, and **clog**.
m) The symbol for the stream extraction operator is **>>**.
n) The stream manipulators **oct**, **hex**, and **dec** specify that integers should be displayed in octal, hexadecimal, and decimal formats, respectively.
o) The **showpos** stream manipulator causes positive numbers to display with a plus sign.

**15.2** True or False. If the answer is _false_, explain why.

a) The stream member function `flags` with a `long` argument sets the `flags` state variable to its argument and returns its previous value.

False. The argument needs a fmtflags argument.

b) The stream insertion operator `<<` and the stream extraction operator `>>` are overloaded to handle all standard data-types - including strings and memory addresses (stream insertion only) -- and all user-defined data types.

False. User-defined data types must overload these operators to work with input and output streams.

c) The stream member function `flags` with no arguments resets the stream's format state.

False. This will only return the current format state, not reset the stream format state.

d) The stream extraction operator `<<` can be overloaded with an operator function that takes an istream reference and a reference to a user-defined type as arguments and returns an `istream reference.

True.

e) The stream insertion operator `>>` can be overloaded with an operator function that takes an `istream` reference and a reference to a user-defined type as arguments and returns an `istream` reference.

False. The stream insertion operator must take and return ostream references.

f) Input with the stream extraction operator `>>` always skips leading white-space characters in the input stream, by default.

True.

g) The stream member function `rdstate` returns the current state of the stream.

True.

h) The `cout` stream normally is connected to the display screen.

True.

i) The stream member function `good` returns `true` if the `bad`, `fail`, and `eof` member functions all return `false`.

True.

j) The `cin` stream normally is connected to the display screen.

False. It is normally connected to the keyboard.

k) If a nonrecoverable error occurs during a stream operation, the `bad` member function will return `true`.

True.

l) Output to `cerr` is unbuffered and output to `clog` is buffered.

True.

m) Stream manipulator `showpoint` forces floating-point values to print with the default six digits of precision unless the precision value has been changed, in which case floating-point values print with the specified precision.

True.

n) The `ostream` member function `put` outputs the specified number of characters.

False. `put` outputs one character. Calls to `put` may be cascaded though.

o) The stream manipulators `dec`, `oct`, and `hex` affecct only the next integer output operation.

False. All three are sticky manipulators.

**15.3** Write a single statement that performs the indicated task:

a) Ouptut the string "Enter your name: ".

cout << "Enter your name: ";

b) Use a stream manipulator that causes the exponent in scienetific notation and the letters in hexadecimal values to print in capital letters.

cout << uppercase;

c) Output the address of the variable `myString` of type `char *`.

cout << static_cast<void *> (myString);

d) Use a stream manipulator to ensure that floating-point values print in scientific notation.

cout << scientific;

e) Output the address in variable `integerPtr` of type `int *`.

cout << integerPtr;

f) Use a stream manipulator suh that, when integer values are output, the integer base for octal and hexadecimal values is displayed.

cout << showbase;

g) Output the value pointed to by `floatPtr` of type `float *`.

cout << *floatPtr;

h) Use a stream member function to set the fill character to '*' for printing in field widths larger than the values being output. Repeat this statement with a stream manipulator.

cout.fill('*');
cout << setfill('*');

i) Output the characters '0' and 'K' in one statement with `ostream` function `put`.

cout.put('0').put('K');

j) Get the value of the next character to input without extracting it from the stream.

cin.peek();

k) Input a single character into variable `charValue` of type `char`, using the istream member function `get` in two different ways.

charValue = cin.get();
cin.get(charValue);

l) Input and discard the next six characters in the input stream.

cin.ignore(6);

m) Use `istream` member function `read` to input 50 characters into `char` array `line`.

cin.read(line, 50);

n) Read 10 characters into character array `name`. Stop reading characters if the  '.' delimiter is encountered. Do not remove the delimiter from the input stream. Write another statement that performs this task and removes the delimiter from the input.

cin.get(name, 10, '.');
cin.getline(name, 10, '.');

o) Use the `istream` member function `gcount` to determine the number  of characters input into character array `line` by the last call to `istream` member function `read`, and output that number of characters, using `ostream` member function `write`.

cout.write(line, cin.gcount());

p) Output 124, 18.376, 'Z', 1000000 and "String", separated by spaces.

cout << 124 << " " << 18.376 << " " << 'Z' << " " << 1000000 
    << " " << "String";

q) Print the current precision setting, using a member function of object `cout`.

cout << cout.precision();

r) Input an integer value into `int` variable `months` and a floating-point value into `float` variable `percentageRate`.

cin >> months >> percentageRate;

s) Print 1.92, 1.925, 1.9258 separated by tabs and with 3 digits of precision, using a stream manipulator.

cout << precision(3) << 1.92 << '\t' << 1.925 << '\t' << 1.9258;
    
t) Print integer 100 in octal, hex, and decimal, using stream manipulators and separated by tabs.

cout << oct << 100 << '\t' << hex << 100 << '\t' << dec << 100;

u) Print integer 100 in decimal, octal and hexadecimal separated by tabs, using a stream manipulator to change the base.

cout << 100 << '\t' << setbase(8) << 100
    << '\t' << setbase(16) << 100;

v) Print 1234 right justified in a 10-digit field.

cout << setw(10) << 1234 << endl;

w) Read characters into character array `line` until the character 'z' is encountered, up to a limit of 20 characters (including a terminating null character). Do not extract the delimiter character from the stream.

cout.getline(line, 20, 'z');

x) Use integer variables x and y to specify the field width and precision used to display the `double` value 87.4573, and display the value.

cout << setw(x) << setprecision(y) << 87.4573;

**15.4** Find and correct code errors. Identify the error in each of the following statements and explain how to correct it.

a) cout << "Value of x <= y is: " << x <= y;

The precedence of the << operator if higher than that of <=. The expression to be evaluated needs to be enclosed in brackets.

b) The following statement should print the integer value of 'c'.

cout << 'c';

Change to static_cast<int>('c');

c) cout << ""A string in quotes"";

Add an escape sequence:

cout << "\"A string in quotes\"";


