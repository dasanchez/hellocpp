# Self Review Exercises: Chapter 17

**17.1** Fill in the blanks:

a. Member function _close_ of the file streams `fstream`, `ifstream`, and `ofstream` closes a file.

b. The `istream` member function _get_ reads a character from the specified stream.

c. Member function _open_ of the file streams `fstream`, `ifstream` and `ofstream` opens a file.

d. The `istream` member function _read_ is normally used when reading data from a file in random-access applications.

e. Member functions _seekg_ and _seekp_ of `istream` and `ostream` set the file-position pointer to a specific location in an input or output stream, respectively.

**17.2** True or false (if false, explain why):

a. Member function `read` cannot be used to read data from the input object cin.
False. `read` can read from any input stream object derived from `istream`.

b. You must create the `cin`, `cout`, `cerr` and `clog` object explicitly.
False. These objects are created automatically. The `iostream` header includes declarations for each stream object.

c. A program must call function `close` explicitly to close a file associated with an `ifstream`, `ofstream`, or `fstream` object.
False. The files will be closed when destructors for those objects execute. Regardless, it's a good programming practice to close all files explicitly with `close` once they're no longer needed.

d. If the file-position pointer points to a location in a sequential file other than the beginning of the file, the file must be closed and reopened to read from the beginning of the file.
False. We can call function `seekg` or `seekp` to go back to the beginning of the file.

e. The `ostream` member function `write` can write to standard-output stream cout.
True.

f. Data in sequential files is updated without overwriting nearby data.
False. Writing to sequential files can overwrite nearby data if the position is not managed properly. In most cases, sequential file records are not of uniform length.

g. Searching all records in a random-access file to find a specific record is unnecessary.
True

h. Records in random-access files must be of uniform length.
False. Records in a random-access file normally are of uniform length.

i. Member functions `seekp` and `seekg` must seek relative to the beginning of a file.
False. It's possible to seek from the beginning of the ifle, from the end of the file, and from the current position of the file.

**17.3** Assume that each of the following statements applies to the same program.

a. Write a statement that opens file `oldmast.dat` for input; use an `ifstream` object called `inOldMaster`.
```
ifstream inOldMaster("oldmast.dat", ios::in);
```

b. Write a statement that opens file `trans.dat` for input; use an `ifstream` object called `inTransaction`.
```
ifstream inTransaction("trans.dat", ios::in);
```

c. Write a statement that opens file `newmast.dat` for output (and creation); use `ofstream` object `outNewMaster`.
```
ofstream outNewMaster("newmast.dat, ios::out);
```

d. Write a statement that reads a record from the file `oldmast.dat`. The record consists of integer `accountNumber`, string `name` and floating-point `currentBalance`; use `ifstream` object `inOldMaster`.
```
inOldMaster >> accountNumber >> name >> currentBalance;
```

e. Write a statement that reads a reccord from the file `trans.dat`. The record consists of integer `accountNum` and floating-point `dollarAmount`; use `ifstream` object `inTransaction`.
```
inTransaction >> accountNum >> dollarAmount;
```

f. Write a statement that writes a record to the file `newmast.dat`. The record consists of integer `accountNum`, string `name`, and floating-point `currentBalance`; use `ofstream` object `outNewMaster`.
```
outNewMaster << accountNum << " " << name << " " << currentBalance;
```

**17.4** Find the error(s) and show how to correct it (them) in each of the following:

a. File `payables.dat` referred to by `ofstream` object `outPayable` has not been opened.
```
outPayable << account << company << amount << endl;
```
File outPayable must be opened first. Also, a blank space is required between variables:
```
ofstream outPayable("payables.dat", ios::in);
outPayable << account << " " << company << " " << amount;
```

b. The following statement should read a record from the file `payables.dat`. The `ifstream` object `inPayable` refers to this file, and `istream` object `inReceivable` refers to the file `receivables.dat`.
```
inReceivable >> account >> company >> amount;
```
The wrong object is being read from. The `payables.dat` file has opened with the `inPayable` object:
```
inPayable >> account >> company >> amount;
```

c. The file `tools.dat` should be opened to add data to the file without discarding the current data.
```
ofstream outTools("tools.dat", ios::out);
```
To add data to the file, open the file for updating or appending:
```
ofstream outTools("tools.dat", ios::ate);
// ofstream outTools("tools.dat", ios::app); // this would work too
```

**17.5** Fill in the blanks:

a. Computers store large amounts of data on secodary staorage devices such as _hard disks and flash memory_.

b. The standard stream objects declared by header `<iostream>` are _cin_, _cout_, _clog_, and _cerr_.

c. `ostream` member function _put_ outputs a character to the specified  stream.

d. `ostream` member function _write_ is generally used to write data to a randomly accessed file.

e. `istream` member function _seekg_ repositions the file-position pointer in a file.