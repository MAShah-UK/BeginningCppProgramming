// Pre-processor directive tells the pre-processor program what to do before the compiler runs.
#include <iostream>

// There are two acceptable signatures for main and each C++ program must use one of them.
// This version accepts arguments passed in via the operating system.
int main(int argc, char *argv[]) {
    // include, main, std, cout, etc are identifiers.
    // int, return, etc are keywords. C++ has around 90.
    // +, #, =, /, <<, etc are operators.
    std::cout << "Hello, World!" << std::endl;
    return 0;
}