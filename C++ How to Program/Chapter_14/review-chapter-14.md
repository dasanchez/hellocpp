# Self-Review Exercises

**13.4** State which of the following are _true_ and which are _false_. If _false_, explain why.

a) The template parameters of a function-template definition are used to specify the types of the arguments to the function, to specify the return type of the function and to declare variables within the function.

True.

b) Keywords `typename` and `class` as used with a template type parameter specifically mean "any user-defined class type."

False. They mean "any fundamental type **or** user-defined type".

c) A function template can be overloaded by another function template with the same function name.

True.

d) Template parameter names among different template definitions must be unique.

False. Template parameter names among different function template definitions need not be unique.

e) Each member-function definition outside a class template must begin with a template header.

True.


**134.2** Fill in the blanks in each of the following:

a) Templates enable us to specify, with a single code segment, an entire range of related functions called _function-template specializations_, or an entire range of related classes called _class-template specializations_.

b) All function-template definitions begin with the keyword _template_, followed by a list of template parameters to the function template enclosed in _angle brackets_.

c) The related functions generated from a function template all have the same name, so the compiler uses _overload_ resolution to invoke the proper function.

d) Class templates also are called _parameterized_ types.

e) The _scope resolution_ operator is used with a class-template name to tie each member-function definition to the class template's scope.
