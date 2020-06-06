## Chapter 12. Object-Oriented Programming: Inheritance

### 12.1 Introduction

- **Inheritance** is a form of software reuse in which you create a class that absorbs an existing class's capabilities, then _customizes_ or enhances them.
- Software reuse saves time during program development by taking advantage of proven, high-quality software.
- You can specify that a new class should **inherit** the members of an existing class. This existing class is called the **base class**, and the new class is called the  **derived class**. A derived class represents a more specialized group of objects.
- C++ offers `public`, `protected`, and `private` inheritance.
- With `public` inheritance, every object of a derived class is also an object of that derived class's base class. 
- We distinguish betwween the **_is-a_ relationship** and the _has-a_ relationship. The is-a relationship represents inheritance. The has-a relationship represents composition.

### 12.2 Base Classes and Derived Classes

- Base classes tenfd to be _more general_ and derived classes tend to be _more specific_.
- Base classes: Student, Shape, Account; Derived classes: GraduateStudent, UndergraduateStudent, Circle, Triangle, Rectangle, Sphere, Cube, CheckingAccount, SavingsAccount.
- Inheritance relationships form **class hierarchies**. A base class exists in a hierarchical relationship with its derived classes. A class becomes either a base class, a derived class, or both.
- With **single inheritance**, a class is derived from _one_base class. With **multiple inheritance**, a derived class inherits from _two or more_ (possibly unrelated) base classes.
- To specify that class `TwoDimensionalShape` is derived from (or inherits from) class `Shape`, the definition could begin as follows:
```
class TwoDimensionalShape : public Shape
```
- This is an example of **`public` inheritace, the most commonly used form.**
- With all forms of inheritance, `private` members of a base class are _not_ accessible directly from that class's derived classes, but these `private` base-class members are still inherited.
- With `public` inheritance, all other base-class members retain their original member access when they become members of the derived class. Through these inherited base-class members, the derived class can manipulate `private` members of  the base class. `friend` functions are _not_ inherited.

### 12.3 `protected` Members

- A base class's `public` members are accessible within its body and anywhere the program has a handle (i.e, a name, reference, or pointer) to an object of that class or one of its derived classes.
- A base class's `private` members are accessible only within its body and to the `friends` of that base class.
- Using `protected` access offers an intermediate level of protection between `public` and `private` access.
- A base class's `protected` members can be accessed within the body of that base class, by members and `friend`s of that base class, and by members and `friend`s of any classes derived from that base class.
- When a derived-class member function _redefines_ a base-class member function, the  base-class member can still be accessed from the derived class by preceding the base-class member name with the base-class name and the scope resolution operator (::).

### 12.4 Relationship between Base Classes and Derived Classes

- Copying and pasting code from one clas to another can spread many physical copies of the same code and can spread errors throughout a system, creating a code-maintenance nightmare.
- To avoid duplicating code, use inheritance, rather than the "copy and paste" approach, in situations where you want one class to "absorb" the data members and member functions of another class.
- With inheritance, the common data members and member functions of all the classes the hierarchy are declared in a base class. When changes are required for these common features, you need to make the changes only in the case class- derived classes then inherit the changes.
- The **base-class initializer syntax** uses a member initializer to pass arguments to the base-class constructor. C++ requires that a derived-class constructor call its base-class constructor to initialize the base-class data members that are inherited into the derived class.
- THe base class's header must be incluses in the derived class's header.
- When base-class data members are decclared as `protected`, derived classes can modify the data directly. 
- Inheriting `protected` data members slightly improves performance, because we can directly access the members without incurring the overhead of calls to set or get member functions.
- In most cases, it's better to use `private` data members to encourage proper software engineering, and leave code optimization issues to the compiler.
- It's appropriate to use the `protected` access specifier when a base class should provide a service only to its derived classes and friends.
- Declaring base-class data members `private`` enables you to change the base-class implementation without having to change derived-class implementations.
- Using a member function to access a data member's value can be slightly slower than accessing the data directly. However, today's optimizing compilers are carefully designed to perform many optimizations implicitly.
- Write code that adheres to proper software engineering principles, and leave optimization to the compiler: "Do not second-guess the compiler".
- The syntax to invoke a redefined base-class member function from a derived class is the base-class name and the scope resolution operator (::) before the base-class member-function name. 
- When a base-class member function is redefined in a derived class, the derived-class version often calls the base-class version to do additional work. Failure to use the :: operator prefixed with the name of the base class when referencing the base class's member function causes infinite recursion.

### 12.5 Constructos and Destructors in Derived Classes

- When a program creates a derived-class object, the derived-class constructor immediately calls the base-class constructor, the base-class constructor executes, then the derived class's member initializers execute and finally the derived-class constructor's body executes. This process cascades up the hierarchy if it contains more than two levels.
- Destructors for derived-class objects are called in the reverse order in which their corresponding constructors are called.
- Base-class constructors, destructors and overloaded assignment operators are _not_ inherited by derived classes. Derived-class constructors, destructors and overloaded assignment operators, however, can call base-class versions.

### 12.6 `public`, `protected` and `private` Inheritance.

| Base-lass member access specifier | public inheritance         | protected inheritance      | private inheritance      |  |
|-----------------------------------|----------------------------|----------------------------|--------------------------|--|
| public                            | public in derived class    | protected in derived class | private in derived class |  |
| protected                         | protected in derived class | protected in derived class | private in derived class |  |
| private                           | hidden in derived class    | hidden in derived class    | hidden in derived class  |  |

- `private` and `protected` inheritance are not _is-a_ relatonships.

### 12.7 Software Engineering with Inheritance

- At the design stage of an object-oriented system, the designer determines that certain classes are closely related. The designer should "factor out" common attributes and behaviours and place these in a base class, then use inheritance to form derived classes.
- Creating a derived class does not affect its base class's source code. Inheritane preserves the integrity of a base class.
