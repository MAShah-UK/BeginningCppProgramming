#include <iostream>
using namespace std;

int main() {
    // Assignment operator: You can assign one or more variables in a row.
    int a {}; // Empty braces initialise variable to 0.
    int b {};
    a = b = 100;
    cout << "a: " << a << " b: " << b << "\n\n";

    // Arithmetic operators: Performs basic math.
    int result = 2 + 3;
    cout << "2 + 3 = " << result << endl;
    result = 5 - 3;
    cout << "5 - 3 = " << result << endl;
    result = 2 * 3;
    cout << "2 * 3 = " << result << endl;
    result = 5 / 2; // result is an int, so the decimals are dropped.
    cout << "5 / 2 = " << result << endl;
    cout << "5 / 2 = " << 5 / 2.0 << endl; // The type of (5 / 2.0) is double via type conversion of the integer.
    result = 5 % 3; // Modulus only works for integers.
    cout << "5 % 3 = " << result << "\n\n";

    const double usd_per_euro {1.19};
    cout << "Welcome to the EUR to USD converter." << endl;
    cout << "Enter the value in EUR: ";
    double euros {0.0};
    cin >> euros;
    double dollars {euros * usd_per_euro};
    cout << euros << " euros is equivalent to " << dollars << " dollars." << "\n\n";

    // Increment/decrement operators: add or subtract 1.
    int inc = 5;
    // Postfix: returns inc, THEN adds one.
    cout << "Inc: " << inc++ << endl;
    cout << "Inc: " << inc << endl;
    inc = 5;
    // Prefix: adds one to inc, THEN returns;
    cout << "Inc: " << ++inc << endl;
    cout << "Inc: " << inc << "\n\n";

    // Type casting/conversion.
    int miles = 10, hours = 3; // Can declare and initialise multiple variables in one line.
    double mph_wrong = miles / hours; // .33 will be dropped, must convert one type to double.
    cout << "Wrong mph calculation: " << mph_wrong << endl;
    double mph = static_cast<double>(miles) / hours; // Static cast tells compiler to convert int to double.
    // double mph = (double) miles / hour // Old C-style cast. Should be avoided as it is unsafe.
    cout << "Correct mph calculation: " << mph << "\n\n";

    // Equality operators: return true or false for an expression.
    bool equal_result {false};
    bool not_equal_result {false};
    int num1 {}, num2 {};

    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;
    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);
    // For Booleans: Displays 1 for true, and 0 for false by default.
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;
    // For Booleans: Displays true, and false instead of 1 and 0.
    cout << boolalpha;
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;
    // This should be false, but due to limited precision, it is not.
    cout << "12.0 + 11.999...: " << (12.0 == 11.9999999999999999999999999999) << "\n\n";

    // Relational operators: Used to determine relationships between numbers.
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;
    cout << "Result of >: " << (num1 > num2) << endl;
    cout << "Result of >=: " << (num1 >= num2) << endl;
    cout << "Result of <: " << (num1 < num2) << endl;
    cout << "Result of <=: " << (num1 <= num2) << endl;

    cout << "Enter a number greater than 10: ";
    cin >> num1;
    cout << num1 << " greater than 10? " << (num1 > 10) << "\n\n";

    // Logical operators: Used to manipulate other boolean expressions.
    cout << "Enter an integer between 10 and 20: ";
    cin >> num1;
    cout << "Is it between 10 and 20? " << (num1 > 10 && num1 < 20) << endl;
    cout << "Is it lesser than 10 or greater than 20? " << (num1 < 10 || num1 > 20) << endl;

    // Compound assignment operators: Simplifies repetitive assignment operations.
    int a = 5;
    a += 5; // a = a + 5. a is now 10.
    a -= 5; // a = a - 5. a is now 5.
    a *= 2; // a = a * 2. a is now 10.
    a /= 2; // a = a / 2. a is now 5.
    a %= 3; // a = a % 3. a is now 2.
    // It also works with bitwise operators.

    

    return 0;
}

/*
 * Challenge 1: Use the assignment operator.
#include <iostream>
using namespace std;
void assignment_operator() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    // Declare num1 as an integer and initialize it to 13.
    int num1 {13};
    // Declare num2 as an integer and initialize it to 0.
    int num2 {0};
    // Assign the value 5 to num1
    num1 = 5;
    // Assign the value of num1 to num2
    num2 = num1;
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << num1 << " " << num2;
}

Challenge 2: Use arithmetic operators.
#include <iostream>
using namespace std;
int arithmetic_operators(int number) {
    int original_number {number};
    //----WRITE YOUR CODE BELOW THIS LINE----
    //-- Multiply number by 2 and assign the result back to number
    number = number * 2;
    //-- Add 9 to number and assign the result back to number
    number = number + 9;
    //-- Subtract 3 from number and assign the result back to number
    number = number - 3;
    //-- Divide number by 2 and assign the result back to number
    number = number / 2;
    //-- Subtract original_number from number and assign the result back to number
    number = number - original_number;
    //-- Take the modulus 3 (%) of number and assign it back to number
    number = number % 3;
    //----WRITE YOUR CODE ABOVE THIS LINE----
    return number;
}


 */