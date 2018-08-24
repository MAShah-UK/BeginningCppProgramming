/*
Challenge 1, 2, and 3: Overload various operators for the given money class.
bool Money::operator==(const Money &rhs) {
    if(this==&rhs ||
       (dollars==rhs.dollars && cents==rhs.cents)) {
        return true;
    }
    return false;
}
bool Money::operator!=(const Money &rhs) {
    return !(*this==rhs);
}
Money operator+(const Money &lhs, const Money &rhs) {
    int dollars {lhs.dollars + rhs.dollars};
    int cents {lhs.cents + rhs.cents};
    return {dollars, cents};
}
std::ostream &operator<<(std::ostream &os, const Money &rhs) {
    os << "dollars: " << rhs.dollars << " cents: " << rhs.cents;
    return os;
}

Challenge 4: Overload various operators for the Mystring class using member methods and non-member functions.
I decided to arbitrarily define some as members, and others as non-members for practice.

Quiz 1: The ________ operator is used by C++ to assign one object to another object.
=

Quiz 2: Providing the ability for a C++ built-in operator to work with user-defined
types is called ________.
operator overloading

Quiz 3: Overloading the C++ assignment operator should be done when the class contains ________.
raw pointers

Quiz 4: If no overloaded assignment operator is provided by the programmer,
C++ will provide default assignment that does _________.
shallow copy / memberwise assignment

Quiz 5: To overload the insertion operator so that you can insert your Test class objects
onto an output stream, you would implement a function with the following prototype:
std::ostream &operator<<(std::ostream &os, const Test &obj);

Quiz 6: When overloading a C++ operator, which of the following statements is true?
All of the above are true:
- The number of operands cannot change.
- Non C++ operators cannot be overloaded.
- Certain C++ operators cannot be overloaded.
- The assignment operator must be overloaded as a member function.

Quiz 7: Most C++ operators can be overloaded as ________ or ________.
member methods, non-member functions

Quiz 8: If we overload the C++ relational operators such as ==, !=, <, >, <=, or >=
we should return the ________ type from the function.
bool

Quiz 9: Often overload operators implemented as non-member
functions are declared as ________ functions.
friend

Quiz 10: What is the correct prototype for the move assignment operator for a class named Test?
Test &Test::operator=(Test &&rhs);
 */