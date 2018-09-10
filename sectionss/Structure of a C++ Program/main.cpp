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

    // Outputs on the same line since the cursor isn't advanced to next line via endl or \n.
    cout << "Hello";
    cout << "World" << endl;

    // Mixture of endl and \n to advance the cursor.
    cout << "Hello world!" << endl;
    cout << "Hello" << " world!" << endl;
    cout << "Hello" << " world!\n";
    cout << "Hello\nOut\nThere\n\n";

    int num1;
    int num2;
    double num3;

    cout << "Enter first integer: " ;
    // Whitespace is ignored: "123", " 123" and " 123 " are valid.
    // If you enter "123 456" both num1 and num2 will have the data stored in one go,
    // since there are two numbers in the buffer.
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;
    cout << "You entered: " << num1 << " and " << num2 << "\n\n";

    cout << "Enter two integers separated by whitespace: ";
    cin >> num1 >> num2; // Extraction operator can be chained.
    cout << "You entered: " << num1 << " and " << num2 << "\n\n";

    cout << "Enter a double: ";
    // "2", "2.5", "-5.1" are all valid.
    cin >> num3;
    cout << "You entered: " << num3 << "\n\n";

    cout << "Enter a int and a double: ";
    // If you input "10.5" into the buffer, num1 will be 10, num3 will be 0.5.
    cin >> num1 >> num3;
    cout << "You entered: " << num1 << " and " << num3 << "\n\n";

    return 0;
}

/*
Challenge 1: Output "Hi Frank!" to the console.
#include <iostream>
using namespace std;
void say_hi() {
    //--- WRITE YOUR CODE BELOW THIS LINE----
    cout << "Hi Frank!";
    //--- WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 2: Output "Sally has 3 dogs." to the console.
#include <iostream>
using namespace std;
void sallys_dogs() {
    int x {3};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    cout << "Sally has " << x << " dogs.";
    //---- WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 3: Get the user's DOB from the console.
#include <iostream>
using namespace std;
void date_of_birth() {
    int m {};
    int d {};
    int y {};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //---- WRITE YOUR CODE BELOW THIS LINE----
    cin >> m >> d >> y;
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- Do NOT MODIFY THE CODE BELOW THIS LINE----
    cout << m << " " << d << " " << y;
}

Quiz 1: In a C++ program, two forward slash characters “//” are used to indicate.
The beginning of a comment.

Quiz 2: A statement that begins with the # symbol is called a _______.
Preprocessor directive.

Quiz 3: Which of the following is a valid identifier name in C++?
three_stooges.

Quiz 4: What is used to terminate a statement in C++?
A semi-colon.

Quiz 5: What happens if you use a C++ keyword as an identifier name?
The program will not compile.

Quiz 6: Every complete C++ program must have a(n) _______.
Function named main.

Quiz 7: What will the following code display?
cout << "Larry";
cout << "Moe";
cout << Curly";

 LarryMoeCurly.

Quiz 8: The C++ main function must return _______ when the program terminates successfully.
0.

Quiz 9: Which of the following are valid operators in C++?
+, *, >>, <<.

 All of the above.

Quiz 10: What will the following code display?
int three = 3;
cout << “There are “ << “three” << “ stooges” << endl;
cout << “Curly is my favorite of the ” << three << endl;

There are three stooges
Curly is my favorite of the 3
*/