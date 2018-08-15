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
    // Bitwise operators are also supported.



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

Challenge 3: Logical operators and operator precedence.
#include <iostream>
using namespace std;
void logical_operators(int age, bool parental_consent, bool ssn, bool accidents) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if (((age >= 18) || (age > 15 && parental_consent)) && ssn && !accidents)//WRITE ALL YOUR CODE WITHIN THE PARENTHESES
        cout << "Yes, you can work.";
    //----WRITE YOUR CODE ABOVE THIS LINE----
    return;
}

Challenge 4: Compound assignment operators.
#include <iostream>
using namespace std;
int main() {
  const int cents_dollar {100};
  const int cents_quarter {25};
  const int cents_dime {10};
  const int cents_nickel {5};
  const int cents_penny {1};

  int cents_input {};
  int balance {};
  int change_dollars {};
  int change_quarters {};
  int change_dimes {};
  int change_nickels {};
  int change_pennies {};

  cout << "Enter an amount in cents: ";
  cin >> cents_input;
  balance = cents_input;

  change_dollars = balance / cents_dollar;
  balance %= cents_dollar;
  change_quarters = balance / cents_quarter;
  balance %= cents_quarter;
  change_dimes = balance / cents_dime;
  balance %= cents_dime;
  change_nickels = balance / cents_nickel;
  balance %= cents_nickel;
  change_pennies = balance;
  balance = 0;

  cout << "Dollars: " << change_dollars << endl;
  cout << "Quarters: " << change_quarters << endl;
  cout << "Dimes: " << change_dimes << endl;
  cout << "Nickels: " << change_nickels << endl;
  cout << "Pennies: " << change_pennies << endl;
}

Quiz 1: The ________ operator increments the value of its operand by one then uses the value.
Prefix increment.

Quiz 2: The operator used to test two operands for equality is ________.
==

Quiz 3: The operator that represents logical AND is ________.
&&

Quiz 4: The operator that represents logic OR is ________.
||

Quiz 5: If a is 3, b is 5, and c is 7, which of the following are true?
b == 5;             // true
c == (a + b) – 1;   // true
b > 5;              // false
a >= 3;             // true
c <= (a * b) / a;   // false

Quiz 6: a < 10  is called a(n) ________.
Relational expression.

Quiz 7: What will the following code display?
int x = 10, y = 3, z = 6;
cout << (x == y) << " ";
cout << (z <= x) << " ";
cout << (y != z) << " ";
cout << (x > y && z < x) << " ";
cout << (y < x && z < x) << " ";
cout << (x < y || z < 0) << endl;

0 1 1 1 1 0

Quiz 8: What is displayed by the following code?
int amount = 100;
amount += amount * 2;
cout << amount << endl;

300

Quiz 9: What is displayed by the following code?
int x= 5;
int y= -2;
int z = 2;
cout << (x + y * z <= x + z * z - x) << endl;

1 because 1 <= 4 is true.

Quiz 10: What are the values of x, y and z after the following code executes?
double  a = 100;
int b = 12;
int x = b % 3;
double  y = a / b;
int z = a / b;

x = 0, y = 8.33..., z = 8

 */