## Chapter 13: Polymorphism

### 13.1 Introduction

- Polymorphism enables you to "program in the general" rather than "program in the specific"- it enables you to write programs that process objects of classes that are part of the same class hierarchy as if they were all objects of they hierarchy's base class.
- Polymorphism works off base-class pointer handles and base-class reference handles, but not name handles.
- You can design systems that are easily _extensible_: new classes can be added with little or no modification to the general portions of the program, as long as the new classes are part of the inheritance hierarchy theat the program processes generically.

### 13.2 Introduction to Polymorphism: Polymorphic Video Game

- A polymorphic screen manager facilitates adding new classes to a syste with minimal modifications to its code.
- Suppose we want to add objects of class `Mercurian` to our video game: we must build a class `Mercurian` that inherits from `SpaceObject` , but provides its own definition of member function `draw`.
- You can use polymorphism to accomodate additional classes, including ones that were not even envisioned when then system was created.
- Polymorphism enables you to deal in generalities and let the execution-time environment concern itself with the specifics.

### 13.3 Relationships Among Objects in an Inheritance Hierarchy

- If we assign the address of a derived-class object to a base-class pointer, invoking a function via that pointer invokes the base-class functionality in the derived-class object: the type of the handle determines which function is called.
- Assigning the address of a base-class object to a derived-class pointer results in a compilation error.
- If we assign  the address of a derived-class object to a base-class pointer, the base-class pointer  can be used to invoke only the base-class functionality. 
- With public inheritance, an object of a derived class can be treated as an object of its base class. Howerver, we cannot treat a base-class object as an object of any of its derived classes.
- The invoked functionality depends on the  type of the pointer  (or reference) used to invoke the function, not the type of object for which the member function is called.

#### 13.3.3 Derived-Class Member Function Calls via Base-Class Pointers

- The compiler allows us to invoke _only_ base-class member functions off a base-class pointer. If a base-class pointer is aimed at a derived-class object and an attempt is made to acces a derived-class-only-member function, a compilation error will occur.
- The compiler will allow access to derived-class-only members from a base-class pointer that's aimed at a derived-class object _if_ we explicitly cast the base-class pointer to a derived-class pointer: this is known as **downcasting**.
- Downcasting is a potentially dangerous operation.

#### 13.3.4 Virtual Functions

- With `virtual` functions, the type of the object, not the type of the handle used to invoke the member function, determines which version of a `virtual` function to invoke.
- Declare the function in the base class as a `virtual` function, and then override it in each of the derived classes to obtain the desired functionality.
- An overridden function in a derived class has the same signature and return type (prototype) as  the function it overrides in its base class.
- We declare a `virtual` function by preceding the function's prototype with the keyword `virtual` in the base class.
- Once a function is declared `virtual`, it remains `virtual` all the way down the inheritance hierarchy from that point, even if that function is not explicitly declared `virtual` when a derived class overrides it.
- Even though certain functions  are implicitly virtual because of a declaration made higher in the class hierarchy, explicitly declare these functions `virtual` at every level of the class hierarchy to promote program clarity.
- When a derived class chooses not to override a `virtual` function from its base class, the derived class simply inheirts its base class's `virtual` function implementation.
- Choosing the appropriate function to call at execution time (rather than at compile time) is known ad **dynamic binding** or **late binding**.
- When a `virtual` function is called by referencing a specific object by name and using the dot member-selection operator, the function invocation is resolved at compile time (this is called **static binding**) and the `virtual` function that's called is the one defined for (or inherited by) the  class of that particular object- this is not polymorphic behaviour.

### 13.4 Type Fields and `switch` Statements

- One way to determine the type of an object is to use a `switch` statement to check the value of a field in the object. This allows us to distinguish among object types, then invoke an appropriate action for a particular object.
- Using `switch` logic exposes programs to a variety of potential problems.
- Polymorphic programming can eliminate the need for `switch` logic.
- An interesting consequence of using polymorphism is that programs take on a simplified appearance. This simplification facilitiates testing, debugging, and program maintenance.

### 13.5 Abstract Classes and Pure `virtual` Functions

- There are cases in which it's useful to define classes from which you never intend to instantiate any objects. Such classes are called **abstract classes**. We refer to them as **abstract base classes** because they are normally used as base classes in inheritance hierarchies.
- These classes cannot be ussed to instantiate objects, because they are incomplete- derived classes must define the "missing pieces" before objects of these classes can be instantiated.
- Classes that can be used to instantiate objects are called **concrete classes**.

**Pure Virtual Functions** 

A class is made abstract by declaring one or more of its `virtual` functions to be "pure". A **pure virtual function** is specified by placing "= 0" in its declaration, as in

```
virtual void draw() const = 0; // pure virtual function
```

The "=0" is a **pure specifier**. Pure `virtual` functions do not provide implementation.
- A pure virtual function _requires_ the derived class to override the function for that derived class to be concrete; otherwise the derived class remains abstract.
- An abstract class defines a common public interface for the various classes in a class hierarchy. An abstract class contains one or more pure `virtual` functions that concrete derived classes must override. An abstract class also can have data members and concrete functions (including constructors and destructors), which are subject to the normal rules of inheritance by derived classes.
- Although we canot instantiate objects of an abstract base class, we can use the abstract base class to declare pointers and references that can refer to objects of any concrete classes derived from the abstract class.

**Device Drivers and Polymorphism**

- An object-oriented operating system might use an abstract base class to provide an interface appropriate for all device drivers. Then, through inheritance from that abstract base class, derived classes are formed that all operate similarly.
- This architecture allows new devices to be added to a system easily, even after the operating system has been defined.

**Iterators and Polymorphism**

- It's common in object-oriented programming to define an **iterator class** that can traverse all the objects in a container (such as an array). Iterators often are used in polymorphic programming to traverse an array or a linked list of pointers to objects from various levels of a hierarchy. The pointers in such a list are all base-class pointers.

### 13.6 Case Study: Payroll System Using Polymorphism

- We use an abstract class and polymorphism to perform payroll calculations based on the type of employee.
- A derived class can inherit interface and/or implementation from a base class. Hierarchies designed for **implementation inheritance** tend to have their functionality high in the hierarchy, and hierarchies designed for **interface inheritance** tend to have their functionaliity lower in the hierarchy.

### 13.7 Polymorphism, Virtual Functions and Dynamic Binding "Under the Hood"

- The STL components were implemented without polymorphism and virtual functions to avoid the associated execution-time overhead and achieve optimal performance.
- Polymorphism is accomplished through three levels of pointers, i.e., triple indirection. 
- When C++ compiles a class that has one or more `virtual` functions, it buils a **virtual function table (vtable)** for that  class. An executing program uses the _vtable_ to select the proper function implementation each time a `virtual` function of that class is called.
- Any class that has one or more null pointers in its _vtable_ is an abstract class.
- Classes without any null _vtable_ pointers are concrete classes. 

**Three Levels of Pointers to Implement Polymorphism**

- One level is the function pointers in the _vtable_. These point to the actual functions that execute whtn a `virtual` function is invoked.
- Whenever an object of a class with one or more `virtual` functions is instantiated, the compiler attaches to the object a pointer to the _vtable_ for that class. This is the second level of pointers.
- The third level of pointers simply contains the handles to the objects that receive the `virtual` function calls. The handles in this level may also be references.
- The pointer dereferencing operations and memory accesses that occur on every `virtual` function call require some additional execution time. The _vtables_ and the _vtable_ pointers added to the objects require some additional memory.
- Polymorphism, as typically implemented with `virtual` functions and dynamic binding in C++, is efficient. You can use these capabilities with nominal impact on performance.
- Polymorphism's overhead is acceptable for most applications. But in some situations, such as real-time applications with stringent performance requirements, polymorphism's overhead may be too high.

### 13.8 Case Study: Payroll System Using Polymorphism and Runtime Type Information with Downcasting, `dynamic_cast`, `typeid` and `type_info`

- **Runtime type information (RTTI)** and **dynamic casting** enable a program to determine the type of an object at execution time and act on that object accordingly.
= Operator `typeid` returns a reference to ab object of class `type_info` that contains the information about the type of its operand, including the name of that type.
- When invoked, `type_info` member function **name** returns a pointer-based string that contains the type name of the argument passed to `typeid`. The string returned by `type_info` member function `name` may vary by compiler.

### 13.9 Virtual Destructors

- If a derived-class object with a nonvirtual destructor is destroyed explicitly by applying the `delete` operator to a base-class pointer to the object, the C++ standard specifies that the behaviour is undefined.
- The simple solution to this problem is to create a **`virtual` destructor** in the base class. This makes all derived-class destructors `virtual` even they do not have the same name as the base-class destructor.
- The base-class destructor automatically executes after the derived-class destructor.
- If aa class has `virtual` functions, provide a `virtual` destructor, even if one is not required for the class. This ensures that a custom derived-class destructor if there is one) will be invoked when a derived-class object is deleted via a base class pointer.
- Constructors cannot be virtual. Declaring a constructor `virtual` is a compilation error.
