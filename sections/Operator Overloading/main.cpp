#include <iostream>
#include "Mystring.h"

int main() {
    Mystring noargs;
    Mystring overloaded {"Larry"};
    Mystring copy = overloaded;   // Copy constructor is called since this is initialisation NOT reassignment.
    Mystring move {Mystring {"Barry"}};

    Mystring copy_assign = noargs; // Ignore, this also call the copy constructor.
    copy_assign = "Harry"; // Now it calls the constructor, to turn Harry into a Mystring, then calls copy assignment.

    noargs.display();
    std::cout << std::endl;
    overloaded.display();
    std::cout << std::endl;
    copy.display();
    std::cout << std::endl;
    copy_assign.display();
    std::cout << "\n\n";

    std::cout << std::boolalpha
              << "Do the noargs and overloaded variables contain the same data? " << (noargs==overloaded) << std::endl
              << "Do the overloaded and copy variables contain the same data? " << (overloaded==copy) << std::endl
              << "Does the overloaded variable and C-style string constructed instance contain the same data? "
                << (overloaded=="Larry") << std::endl
              << "Result of using the + operator on three Mystring objects: "
                << (overloaded+move+"Harry") << std::endl
              << "Result of using == operator with C-style string as first operand: "
                << ("Larry"==overloaded) << std::endl // Works because == defined as non-member function.
              << "Result of using - operator: " << (-overloaded) << std::endl
              << "Result of using * operator: " << move*3 << "\n\n";
    return 0;
}