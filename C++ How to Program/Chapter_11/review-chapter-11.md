# Self-Review Exercises

**11.1** Fill in the blanks in each of the following:

a) Suppose `a` and `b` are integer variables and  we form the sum `a + b`. Now suppose `c` and `d` are floating-point variables and we form the sum `c + d`. The two `+` operators here are clearly being used for different purposes. This is an example of __operator overloading__.

b) Keyword __operator__ introduces an overloaded-operator function definition.

c) To use operators on class objects, they must be overloaded, with the exception of operators __assignment (=)__, __address (&)__, and __comma (,)__.

d) The __precedence__, __arity__, and __associativity__ of an operator cannot be changed by overloading the operator.

e) The operators that cannot be overloaded are __.__, __.*__, __::__, and __?:__.

f) The __delete__ operator reclaims memory previously allocated by `new`.

**11.2** Explain the multiple meanings of the operators ``<<` and `>>`.

\>> can refer to a right shift operation, or it can act as a stream extraction.  
<< can refer to a left shift operation, or it can act as a stream insertion.

**11.3** In what context might the name `operator/` be used?

Wherever we would like to overload the `/` operator in a given class.

**11.4** True/False: Only existing operators can be overloaded.

True.

**11.5** How does the precedence of an overloaded operator compare with the precedence of the original operator?

They have the same precedence.