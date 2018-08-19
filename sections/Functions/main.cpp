#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// All of the functions must be declared before they are actually used.

// Function prototype / forward declaration.
// The third parameter has a default argument in case one isn't passed in.
int add_numbers(int a, int b, int c = 0); // Parameter names are optional.
double add_numbers(double a, double b, double c = 0, double d = 0);
// const makes it clear that the original array will never be modified.
double find_mean(const double data [], size_t size);

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
 */