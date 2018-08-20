#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// All of the functions must be declared before they are actually used.

// Function prototype / forward declaration.
// The third parameter has a default argument in case one isn't passed in.
int add_numbers(int a, int b, int c = 0); // Parameter names are optional.
double add_numbers(double a, double b, double c = 0, double d = 0);
// const makes it clear that the original array will never be modified.
double find_mean(const double data [], size_t size);
// inline tells the compiler to consider running the code directly without
// a function call. Compilers usually optimise for this anyway.
inline void increment_integer(int&, int);
int counter();
unsigned long long factorial(unsigned long long);
unsigned long long fibonacci(unsigned long long);

void outputWorld() {
    cout << "World";
}

// This void function (procedure) returns nothing and takes no arguments.
void outputHelloWorld() {
    cout << "Hello ";
    outputWorld(); // Can call other functions within functions.
    return; // Optional for procedure.
}

int main() {
    // cmath library contains many functions related to math.
    cout << "2^5 is: " << pow(2.0, 5.0) << endl;
    cout << "5.6 rounded down is: " << floor(5.6) << endl;
    cout << "0.1 rounded up is: " << ceil(0.1) << endl;
    cout << "The size of 90 is: " << sin(90.0) << endl;
    cout << "The square root of 81 is: " << sqrt(81.0) << "\n\n";

    // use cstlib and ctime to generate random numbers.
    cout << "The return random value will be between 0 and " << RAND_MAX << "." << endl;
    srand(time(nullptr)); // Seed for the random number generator.
    int random_number = rand() % 10 + 1;
    cout << "Random number between 1 and 10 is " << random_number << "." << "\n\n";

    // Custom functions: used to modularise code, increase code-reuse, and decrease
    // code duplication. This reduces errors in code.
    cout << "Using procedures to output text: ";
    outputHelloWorld();
    cout << endl;
    // The third argument was optional. It uses the default value.
    cout << "Using a function to add 3 and 5: " << add_numbers(3, 5) << endl;
    // ints auto casted to double.
    cout << "Using a function to add 1, 2, 3, and 4: " << add_numbers(1, 2, 3, 4) << endl;
    // Pass array to function.
    double ages [] {13, 15, 14, 15, 12, 14, 15, 15};
    cout << "Using a function find mean of array: " << find_mean(ages, 8) << endl;
    int value {4};
    increment_integer(value, 1);
    cout << "Using a function to increment a local variable: " << value << endl;
    cout << "Static local variable value 1: " << counter() << endl;
    cout << "Static local variable value 2: " << counter() << "\n\n";

    // Scope limits the visibility of the variable to within a code block.
    string outerScope {"yes"};
    { // Code block creates a scope within a scope.
        string innerScope {"yes"};
        cout << "Can inner code block see outer scope variable? " << outerScope << endl;
        cout << "Can inner code block see inner scope variable? " << innerScope << endl;
    }
    cout << "Can outer code block see outer scope variable? " << outerScope << endl;
    cout << "Can outer code block see inner scope variable? " << "no" << "\n\n";

    // Recursive functions call themselves repeatedly to find the solution.
    cout << "The factorial of 8 is: " << factorial(8) << endl;
    cout << "The fibonacci for 10 is: " << fibonacci(10) << endl;

    return 0;
}

// This function takes three arguments and returns an integer result.
int add_numbers(int a, int b, int c) {
    // The arguments are passed-by-value/copied, so changing them
    // won't affect the original variables that were passed in.
    return a + b + c; // Returned data must match return type.
}

// Function overloading allows defining functions with the same name,
// but modified behaviour.
double add_numbers(double a, double b, double c, double d) {
    return a + b + c + d;
}

// Raw array and array size should be passed together.
double find_mean(const double data [], size_t size) {
    double sum {};
    for(size_t i {}; i < size; i++) {
        sum += data[i];
    }
    double mean = sum/size;
    return mean;
}

// Pass-by-reference doesn't copy the argument. Instead it directly
// references the argument in memory. Changing the parameter changes
// the provided argument directly.
void increment_integer(int &source, int amount) {
    source += amount;
}

int counter() {
    // static variables are initialised the first time the function is called.
    // They then persist until the program ends.
    static int count {};
    count++;
    return count;
}

unsigned long long factorial(unsigned long long n) {
    if(n == 0) {
        return 1; // Base case.
    }
    return n * factorial(n-1); // Recursive case.
}

unsigned long long fibonacci(unsigned long long n) {
    if(n <= 1) {
        return n;
    }
    return factorial(n-1) + fibonacci(n-2);
}

/*
Challenge 1: Use math function in a point-of-sales system.
#include <iostream>
#include <cmath>
using namespace std;
void c_math_functions() {
    double bill_total {102.78};
    int number_of_guests {5};
    double individual_bill {bill_total/number_of_guests};
    double individual_bill_1 {floor(individual_bill)};
    double individual_bill_2 {ceil(individual_bill)};
    double individual_bill_3 {round(individual_bill*100)/100};
    cout << "The individual bill at location 1 will be $" << individual_bill_1
         << "\n" << "The individual bill at location 2 will be $" << individual_bill_2 << "\n"
         << "The individual bill at location 3 will be $" << individual_bill_3;
}

Challenge 2: Use functions to convert between temperature units.
#include <iostream>
#include <cmath>
using namespace std;
double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);
void temperature_conversion(double fahrenheit_temperature) {
    double celsius_temperature {fahrenheit_to_celsius(fahrenheit_temperature)};
    double kelvin_temperature {fahrenheit_to_kelvin(fahrenheit_temperature)};
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to "
         << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}
double fahrenheit_to_celsius(double fahrenheit_temperature) {
    double f2c = 5.0/9.0 * (fahrenheit_temperature-32);
    return round(f2c);
}
double fahrenheit_to_kelvin(double fahrenheit_temperature) {
    double f2k = 5.0/9.0*(fahrenheit_temperature-32) + 273;
    return round(f2k);
}

Challenge 3: Use default arguments to cover the base case for the order.
#include <iostream>
using namespace std;
void print_grocery_list(int apples = 3, int oranges = 7, int mangos = 13);
void modify_grocery_list() {
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7, 11);
}
void print_grocery_list(int apples, int oranges, int mangos) {
    cout << apples << " apples" << "\n" << oranges << " oranges" << "\n" << mangos << " mangos" << "\n";
}

Challenge 4: Use function overloading to calculate the area of a square or rectangle.
#include <iostream>
#include <cmath>
using namespace std;
int find_area(int);
double find_area(double, double);
void area_calc() {
    int square_area = find_area(2);
    double rectangle_area = find_area(4.5, 2.3);
    cout << "The area of the square is " << square_area << "\n" << "The area of the rectangle is "
         << rectangle_area;
}
int find_area(int side_length) {
    return pow(side_length, 2);
}
double find_area(double length, double width) {
    return length*width;
}

Challenge 5: Practice working with arrays passed to methods. Process guest list.
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
string print_guest_list(const string [], size_t);
void clear_guest_list(string [], size_t);
void event_guest_list() {
    string guest_list[] {"Larry", "Moe", "Curly"};
    size_t guest_list_size {3};
    print_guest_list(guest_list, guest_list_size);
    clear_guest_list(guest_list, guest_list_size);
    print_guest_list(guest_list, guest_list_size);
}
string print_guest_list(const string guest_list [], size_t guest_list_size) {
    for (size_t i {0}; i < guest_list_size; i++) {
        cout << guest_list[i] << endl;
    }
    return typeid(guest_list).name();
}
void clear_guest_list(string guest_list [], size_t guest_list_size) {
    for (size_t i {0}; i < guest_list_size; i++) {
        guest_list[i] = " ";
    }
}

Challenge 6: Practice working with pass-by-reference parameters.
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
string print_guest_list(const string&, const string&, const string&);
void clear_guest_list(string&, string&, string&);
void event_guest_list() {
    string guest_1 {"Larry"};
    string guest_2 {"Moe"};
    string guest_3 {"Curly"};
    print_guest_list(guest_1, guest_2, guest_3);
    clear_guest_list(guest_1, guest_2, guest_3);
    print_guest_list(guest_1, guest_2, guest_3);
}
string print_guest_list(const string &guest_1, const string &guest_2, const string &guest_3) {
    cout << guest_1 << endl << guest_2 << endl << guest_3 << endl;
    string test_1 = typeid(guest_1).name(), test_2 = typeid(guest_2).name(), test_3 = typeid(guest_3).name();
    return test_1 + test_2 + test_3;
}
void clear_guest_list(string &guest_1, string &guest_2, string &guest_3) {
    guest_1 = guest_2 = guest_3 = " ";
}

Challenge 7: Use recursion to double balance for n days.
#include <iostream>
#include <iomanip>
using namespace std;
int function_activation_count {0};
double a_penny_doubled_everyday(int days, double amount = 0.01);
void amount_accumulated() {
    double total_amount {a_penny_doubled_everyday(25)};
    cout <<  "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10) << total_amount;
}
double a_penny_doubled_everyday(int days, double amount) {
    function_activation_count++;
    if(days == 1) {
        return amount;
    }
    return a_penny_doubled_everyday(days-1, amount*2);
}
int test_function_activation_count() {
    return function_activation_count;
}

Challenge 8: Rewrite number management system using material from this section.
#include <iostream>
#include <vector>
using namespace std;
void print_menu();
char getInput();
void print_numbers(const vector<int>&);
void add_number(vector<int>&);
void calculate_mean(const vector<int>&);
void find_smallest(const vector<int>&);
void find_largest(const vector<int>&);
int main() {
  cout << "Welcome to the number collector." << "\n\n";
  char input {};
  vector <int> numbers;
  do {
    print_menu();
    input = getInput();
    switch(input) {
      case 'P': {
        print_numbers(numbers);
        break;
      }
      case 'A': {
        add_number(numbers);
        break;
      }
      case 'M': {
        calculate_mean(numbers);
        break;
      }
      case 'S': {
        find_smallest(numbers);
        break;
      }
      case 'L': {
        find_largest(numbers);
        break;
      }
      case 'Q': {
        cout << "Quitting.";
        break;
      }
      default: cout << "Unknown selection, please try again.";
    }
    cout << "\n\n";
  } while (input != 'q' && input != 'Q');
}
void print_menu() {
    cout << "[MENU]" << endl;
    cout << "P - Print numbers..." << endl;
    cout << "A - Add a number..." << endl;
    cout << "M - Calculate mean..." << endl;
    cout << "S - Find smallest number..." << endl;
    cout << "L - Find largest number..." << endl;
    cout << "Q - Quit..." << "\n\n";
}
char getInput() {
  char input {};
  cout << "Pick an option: ";
  cin >> input;
  return toupper(input);
}
void print_numbers(const vector<int> &numbers) {
  if(numbers.size() == 0) {
    cout << "[] - The list is empty.";
  } else {
    cout << "[";
    for(int number : numbers) {
      cout << " " << number;
    }
    cout << " ]";
  }
}
void add_number(vector<int> &numbers) {
  int number_add {};
  cout << "Enter number to add: ";
  cin >> number_add;
  numbers.push_back(number_add);
  cout << number_add << " was added.";
}
void calculate_mean(const vector<int> &numbers) {
    if(numbers.size() > 0) {
    double sum {};
    for(int number : numbers) {
      sum += number;
    }
    const double mean {sum/numbers.size()};
    cout << "The mean is " << mean << ".";
  } else {
    cout << "Error: List is empty.";
  }
}
void find_smallest(const vector<int> &numbers) {
  if(numbers.size() > 0) {
    int number_smallest {};
    if(numbers.size() > 0) {
      number_smallest = numbers.at(0);
    }
    for(int i = 1; i < numbers.size(); i++) {
      if(numbers.at(i) < number_smallest) {
        number_smallest = numbers.at(i);
      }
    }
    cout << "The smallest number is " << number_smallest << ".";
  } else {
    cout << "Error: List is empty.";
  }
}
void find_largest(const vector<int> &numbers) {
  if(numbers.size() > 0) {
    int number_largest {};
    if(numbers.size() > 0) {
      number_largest = numbers.at(0);
    }
    for(int i = 1; i < numbers.size(); i++) {
      if(numbers.at(i) > number_largest) {
        number_largest = numbers.at(i);
      }
    }
    cout << "The largest number is " << number_largest << ".";
  } else {
    cout << "Error: List is empty.";
  }
}

Quiz 1: A function can have ________ parameters.
zero or more

Quiz 2: Variables defined in the body of a function that are
visible only to the function are called ________ variables.
local

Quiz 3: Variables defined in functions whose values persist from
call to call are called ________ variables.
static

Quiz 4: The default manner in which passing parameters to
functions is achieved in C++ ________.
is pass-by-value

Quiz 5: What is displayed by the following code?
#include <iostream>
using namespace std;
void func(int x, int y, int z) {
   x = y + z;
   y = 10;
   x = 20;
}
int main() {
   int a = 10, b = 20, c = 30;
   func(a, b, c);
   cout << a << " " << b << " " <<  c << endl;
   return 0;
}

10 20 30

Quiz 6: What is displayed by the following code?
#include <iostream>
using namespace std;
void func(int &x, int &y, int &z) {
   x = y + z;
   y = 10;
   x = 20;
}
int main() {
   int a = 10, b = 20, c = 30;
   func(a, b, c);
   cout << a << " " << b << " " <<  c << endl;
   return 0;
}

20 10 30

Quiz 7: ________ arguments can be automatically supplied to a function
when no arguments are provided when the function is called.
Default

Quiz 8: When a function calls itself, either directly or indirectly,
this is defined as ________.
recursion

Quiz 9: Before we can call a function in C++, it must be defined or have a ________ provided.
prototype

Quiz 10: Creating multiple versions of the same function name
that accepts different parameters is called ________.
function overloading
 */