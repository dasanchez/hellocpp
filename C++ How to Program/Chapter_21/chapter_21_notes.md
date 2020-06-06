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
