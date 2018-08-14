#include <iostream>
using namespace std;

int main() {
    // Assignment operator: You can assign one or more variables in a row.
    int a {0};
    int b {0};
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
    cout << "Inc: " << inc << endl;

    // Type conversion.
    int miles = 10;
    int hours = 3;
    double mph_wrong = miles / hours; // .33 will be dropped, must convert one type to double.
    cout << "Wrong mph calculation: " << mph_wrong << endl;
    double mph = static_cast<double>(miles) / hours; // Static cast tells compiler to convert int to double.
    cout << "Correct mph calculation: " << mph << endl;

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