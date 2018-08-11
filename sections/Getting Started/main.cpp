#include <iostream>

extern int x;

int main() {
    // Declare integer variable called favourite_number.
    int favourite_number;
    // Use cout with insertion operator to output data to console.
    // "..." represents a string literal.
    std::cout << "Enter you favourite number between 1 and 100: ";
    // Use cin with extraction operator to input data from console.
    std::cin >> favourite_number;
    // Use endl to flush the buffer and move to the next line.
    std::cout << "Amazing that's my favourite number too." << std::endl;

    // Compiler errors: Can't compile code.
    // Syntax error - missing trailing quotation character:
    // std::cout << "Hello world << std::endl;
    // Syntax error - endll is undefined.
    // std::cout << "Hello world" << std::endll;
    // Syntax error - missing semicolon to end statement.
    // std::cout << "Hello world" << std::endl
    // Correct.
    std::cout << "Hello world" << std::endl;

    // Compiler warnings: Can compile code, but potential issue.
    int miles = 0; // Unused variable.
    int miles_driven; // Unused and uninitialized variable.
    // std::cout << miles_driven;

    // Linker error - since x is undefined anywhere.
    // std::cout << x;

    // Syntax error - nothing being returned, but method expects int.
    // return;
    // Semantic error - data returned, but of invalid type.
    // return "Joe";
    // Correct. return 0 to indicate that the program ran as expected.
    return 0;
}

/*
 * Challenge: Create a C++ program that asks the user for the favourite number
 * between 1 and 100. Then read this number from the console.
 */

/*
#include <iostream>

int main() {
   int favourite_number;
   std::cout << "Enter your favourite number between 1 and 100: ";
   std::cin >> favourite_number;
   std::cout << "Amazing. That's my favourite number too." << std::endl;
   std::cout << "No really, " << favourite_number << " is my favourite number.";
   return 0;
}
*/