**18.1** Fill in the blanks:

a. Header _string_ must be included for class `string`.
b. Class `string` belongs to the _std_ namespace.
c. Function _erase_ deletes characters from a string.
d. Function _find_ finds the first occurrence of one of a specified set of characters from a string.

**18.2** State which of the following statements are true and which are false. If a statement is false, explain why.

a. Concatenation of string objects can be performed with the addition assignment oper-
ator, `+=`.
True

b. Characters within a string begin at index 0.
True

c. The assignment operator, `=`, copies a string.
True.

d. A C-style string is a string object.
False. A C-style string is a null terminated-pointer and does not provide any services. 

**18.3** Find the error(s) in each of the following, and explain how to correct it (them):

a. string string1(28); // construct string1
   string string2('z'); // construct string2
> The 28 needs to be enclosed by double quotes, just like the z character.

b. // assume std namespace is known
const char *ptr = name.data(); // name is "joe bob"
ptr[3] = '-';
cout << ptr << endl;
> ptr needs to be manually terminated with a '\0' character, and ptr, a const char, cannot be modified. Replace with:
cout << name.substr(0, 3) + "-" + name.substr(4) << endl;

**18.4** Fill in the blanks:
a. Class `string` member function _c_str()_ converts a `string` to a C-style string.
b. Class `string` member function _assign_ is used for assignment.
c. _reverse\_iterator_ is the return type of function `rbegin`.
d. Class `string` member function _substr_ is used to retrieve a substring.

**18.5** True or false:

a. `strings` are always null terminated.
False. C++ strings are not necessarily null terminated: they are objects, not char arrays.

b. Class `string` member function `max_size` returns the maximum size for a `string`.
True.

c. Class `string` member function `at` can through an `out_of_range` exception.
True.

d. Class `string` member function `begin` returns an `iterator`.
True.

**18.6** Find code errors:

a. std::cout << s.data() << std::endl; // s is "hello"
> s.data() is not a null-terminated char array. Instead, use:
cout << s << endl;

b. erase(s.rfind("x"), 1); // s is "xenon"
> The erase function must be called on a string object:
s.erase(s.rfind("x"), 1);

c. string& foo()
{
    string s("Hello");
    return;
} // end function foo
> The function is not returning anything. If we want to pass a variable by reference, we should add it to the arguments list and not the returned varaible.

