// Pre-processor directive tells the pre-processor program what to do before the compiler runs.
#include <iostream>

// Using directives tells the compiler where to look for identifiers.
// All identifiers within the std namespace will now be available to use directly.
using namespace std;
// This isn't recommended in large programs due to the potential increase in naming conflicts.
// Instead use using declaration to specify exactly what you need.
using std::cout;
using std::endl;

// There are two acceptable signatures for main and each C++ program must use one of them.
// This version accepts arguments passed in via the operating system.
int main(int argc, char *argv[]) {
    // include, main, std, cout, etc are identifiers.
    // int, return, etc are keywords. C++ has around 90.
    // +, #, =, /, <<, etc are operators.
    std::cout << "Hello, world!" << std::endl;

    // std:: no longer required due to using directive/declaration.
    cout << "Outputting string without std:: prefix." << endl;
    return 0;
}