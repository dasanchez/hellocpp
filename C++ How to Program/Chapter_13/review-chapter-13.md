# Self-Review Exercises

**13.1** Fill in the blanks in each of the following:

a) Treating a base-class object as a __derived class object__ can cause errors.

b) Polymorphism helps eliminate __switch__ logic.

c) If a class contains at least one pure `virtual` function, it's an __abstract__ class.

d) Classes from which objects can be instantiated are called __concrete__ classes.

e) Operator __dynamic_cast__ can be used to downcast base-class pointers safely.

f) Operator `typeid` returns a reference to a __type_info__ object.

g) __Polymorphism__ involves using a base-class pointer or reference to invoke `virtual` functions on base-class and derived-class objects.

h) Overridable functions are declared using keyword __virtual__.

i) Casting a bse-class pointer to a derived-class pointer is called __downcasting__.

**13.2** State whether each of the following is true or false. If false, explain why.

a) All `virtual` functions in an abstract base class must be declared as pure `virtual` functions.

False. Only those functions that should be implemented in derived classes must be declared as pure virtual functions.

b) Referring to a derived-class object with a base-class handle is dangerous.

False. This is the right way to use polymorphism. Referring to a base-class object with a derived-class handle is dangerous, though.

c) A class is made abstract by declaring that class `virtual`.

False. A class is made abstract by assigning 0 to a virtual function, making it pure. Classes are never declared `virtual`.

d). If a base class declares a pure `virtual` function, a derived class must implement that function to become a concrete class.

True.

e) Polymorphic programming can eliminate the need for `switch` logic.

True.