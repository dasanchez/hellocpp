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
