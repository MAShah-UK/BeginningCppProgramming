#include <iostream>
#include <climits>
#include <cfloat>

// #define directive using in older code to define constant, bad practice now.
// Preprocessor replaces identifier with value.
#define days_in_year 365

using std::cout;
using std::cin;
using std::endl;

// This is a global variable since it's not declared within any block of code.
// It can be access from anywhere in the program.
// Global variables are automatically initialised to 0.
// They should be avoided because they make it difficult to debug the code.
int randomVariable;

int main() {

    // Variables give a name to a location in memory.
    // They have a type, name, and content.
    // They must be declared and then initialised.
    // Form 1:
    int age;
    age = 21;
    // Form 2:
    int lucky_number = 7;
    double miles_driven = 2.2;
    // They're called variables because their content can vary.
    age = 22;

    // Object oriented programming allows us to create custom types.
    // Account franks_account;
    // Person james;

    // There are three declaration and initialisation forms:
    int value1;     // Not recommended: value can be anything/undefined.
    int value2 = 5; // C-like initialisation.
    int value3 (5); // Constructor initialisation.
    int value4 {5}; // C++11 list initialisation.

    // All of the variables defined in this code block are local variables.
    // They are local to main.

    // The compiler checks locally for randomVariable first, then globally.
    // Hence the statement prints 5. To access a global variable use
    // :: without specifying a namespace.
    int randomVariable = 5;
    cout << "Local scope: " << randomVariable << endl; // Outputs 5.
    cout << "Global scope: " << ::randomVariable << endl; // Outputs 0.

    // C++ primitive types:
    // Character types. Represents characters.
    char char1 {'A'};           // 1 byte.
    char16_t char2 {'B'};       // 2 bytes.
    char32_t char3 {'C'};       // 4 bytes.
    wchar_t  char4 {'D'};       // Larger character set.
    // Integral types. Represents whole numbers.
    short short1 {50};          // Or short int. 2 bytes.
    int int1 {-90};              // Or signed int int1 {20}. All integral types signed by default. 2 bytes.
    long long1 {-20005};         // 4 bytes.
    long long longlong1 {20000000010020203}; // 8 bytes.
    unsigned short ushort {233}; // Unsigned types have double the positive range, and none of the negative range.
    unsigned int uint {2000};
    unsigned long ulong {20001231};
    unsigned long long ulonglong {1'023'010'230}; // Can use single quotes for large numbers, must be in between.
    // Floating types. Represents whole numbers and decimals.
    float float1 = -5.5f;               // Precise to 7 decimals. 4 bytes.
    double double1 = 3.14159;           // Precise to 15 decimals. 8 bytes.
    long double longdouble1 = 2.7e2;    // Precise to 19 decimals. 12 bytes. Can use scientific notation.
    // Boolean type. Represents true and false.
    bool bool1 {true};          // 1 byte.

    // Overflow.
    short overflow = 65537; // Overflows since limit is 65536. Result is 1.
    // short overflow2 {65537}; // List initialiser syntax prevents overflow.
    cout << "Overflow: " << overflow << endl;

    // Truncation.
    int truncate = 55.2; // Integer only keeps the integer, and truncates the decimals.
    // int truncate2 {55.2} // List initialiser syntax prevents truncation, or narrowing conversions in general.
    cout << "Truncation: " << truncate << "\n\n";

    // sizeof operator can tell you the size of a type or variable.
    // It gets this information from <climits> and <cfloat>.
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Min/max integer: " << INT_MIN << "/" << INT_MAX << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of truncate variable: " << sizeof(truncate) << endl;
    cout << "Size of truncate variable: " << sizeof truncate << "\n\n";

    // Constants make it clear that a value should never be changed.
    // The compiler enforces this concept.
    const int months_in_year {12};
    const double pi = {3.14159};
    // months_in_year = 13; // Compile time error.
    cout << "#define constant: " << days_in_year << endl;

    cout << "Hell"

    return 0;
}

/*
Challenge 1: Declare and initialise variables via hard coding and cin.
#include <iostream>
#include <string>
using namespace std;
void employee_profile() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    string name;
    int age;
    double hourly_wage = 23.5;
    cin >> name >> age;
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << name << " " << age << " " << hourly_wage;
}

Challenge 2: Process cleaning service order.
#include <iostream>
using namespace std;
int main() {
  const double VAT {0.06};
  const double cost_small {25.0};
  const double cost_large {35.0};
  const int days_valid {30};
  int rooms_small;
  int rooms_large;

  cout << "Hello, welcome to Frank's Carpest Cleaning Server" << "\n\n";

  cout << "Price per small room: £" << cost_small << "\n";
  cout << "Price per large room: £" << cost_large << "\n\n";

  cout << "How many small rooms will you like to clean? ";
  cin >> rooms_small;
  cout << "How many large rooms will you like to clean? ";
  cin >> rooms_large;
  cout << "\n";

  const double cost {rooms_small*cost_small + rooms_large*cost_large};
  const double tax {cost*VAT};
  const double total_cost {cost + tax};

  cout << "Number of small rooms: " << rooms_small << "\n";
  cout << "Number of large rooms: " << rooms_large << "\n";
  cout << "Price per small room: £" << cost_small << "\n";
  cout << "Price per large room: £" << cost_large << "\n";
  cout << "Cost: £" << cost << "\n";
  cout << "Tax: £" << tax << "\n";
  cout << "================================================" << "\n";
  cout << "Total cost: £" << total_cost << "\n";
  cout << "Estimate is valid for " << days_valid << " days";
}

Quiz 1: Data values that do not change while a program executes are ________.
Literals.

Quiz 2: All variables must have a ________ before they are used in a program.
Definition.

Quiz 3: Storage locations in memory are represented by ________.
Variables.

Quiz 4: String literals are always enclosed in ________.
Double quotes "".

Quiz 5: Character literals are always enclosed in ________.
Single quotes ''.

Quiz 6: A variable that can hold only true or false values is of type ________.
bool.

Quiz 7: The following expression determines how many bytes of storage are required
to store a double on your computer:
sizeof(double).

Quiz 8: What is the output  from the following code:
int x;
cout << x << endl;

Undefined.

Quiz 9: Which variable definition is not legal in C++?
int x = 100. (No semi-colon).

Quiz 10: Which line in the following code will generate a compiler error?
#include <iostream>
using namespace std;
int main() {
   const int min_age = 18;
   const int max_age = 35;
   min_age = 21;
   cout << “Minimum age is “ << min_age << endl;
   return 0;
}

The min_age = 21 line.
 */