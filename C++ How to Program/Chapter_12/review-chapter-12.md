# Self-Review Exercises

**12.1** Fill in the blanks in each of the following:

a) __Inheritance__ is a form of software reuse in which neww classes absorb the data and behaviours of existing classes and embellish these classes with new capabilities. 

b) A base class's __protected__ members can be accessed in the base-class definition, in derived class definitions and in `friends` of the base class.

c) In a __is-a__ relationship, an object of a derived class also can be treated as an object of its base class.

d) In a __has-a__ relationship, a class object has one or more objects of other classes as members.

e) In single inheritance, a class exists in a __hierarchical__ relationship with its derived classes.

f) A base class's __public access__ members are accessible within that base class and anywhere that the program has a handle to an object of that class or one of its derived classes.

g) A base class's `protected` access members have a level of protection between those of `public` and __`private`__ access.

h) C++ provides for __multiple inheritance__, which allows a derived class to inherit from many base classes, even if the base classes are unrelated.

i) When an object of a derived class is instantiated, the base class's __constructor__ is called implicitly or explicitly to do any necessary initialization of the base-class data members in the derived-class object.

j) When deriving a class from a base class with `public` inheritance, `public` members of the base class become __public__ members of the derived class, and `protected` members of the base class become __protected__ members of the derived class.

k) When deriving a class from a base class with `protected` inheritance, `public` members of the base class become __protected__ members of the derived class, and `protected` members of the base class become __protected__ members of the derived class.

**12.2** State whether each of the following is true or false. If false, explain why.

a) Base-class constructors are not inherited by derived classes.

True.

b) A _has-a_ relationship ims implemented via inheritance.

False. It's implemented via composition.

c) A Car class has an _is-a_ relationship with the SteeringWheel and Brakes classes.

False. It has a _has-a_ relationship with those classes.

d) Inheritance encourages the reuse of proven high-quality software.

True.

e) When a derived-class object is detroyed, the destructors are called in the reverse order of the constructors.

True.