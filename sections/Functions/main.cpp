#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// All of the functions must be declared before they are actually used.

// Function prototype / forward declaration.
int add_numbers(int, int); // Parameter names are optional.

void outputWorld() {
    cout << "World";
}

// This void function (procedure) returns nothing and takes no arguments.
void outputHelloWorld() {
    cout << "Hello ";
    outputWorld();
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
    cout << "Using a function to add 3 and 5: " << add_numbers(3, 5) << endl;

    return 0;
}

//This function takes two arguments and returns an integer result.
int add_numbers(int a, int b) {
    // a and b are passed-by-value/copied, so changing them
    // won't affect the variables that were passed in.
    return a + b; // Returned data must match return type.
}

/*
Challenge 1: Use math function in a point-of-sales system.
#include <iostream>
#include <cmath>
using namespace std;
void c_math_functions() {
    double bill_total {102.78};
    int number_of_guests {5};
    //DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    double individual_bill {bill_total/number_of_guests};
    double individual_bill_1 {floor(individual_bill)};
    double individual_bill_2 {ceil(individual_bill)};
    double individual_bill_3 {round(individual_bill*100)/100};
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << "The individual bill at location 1 will be $" << individual_bill_1
         << "\n" << "The individual bill at location 2 will be $" << individual_bill_2 << "\n"
         << "The individual bill at location 3 will be $" << individual_bill_3;
}

Challenge 2: Use functions to convert between temperature units.
#include <iostream>
#include <cmath>
using namespace std;
//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----
double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);
//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----
void temperature_conversion(double fahrenheit_temperature) {
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    double celsius_temperature {fahrenheit_to_celsius(fahrenheit_temperature)};
    double kelvin_temperature {fahrenheit_to_kelvin(fahrenheit_temperature)};
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}
//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----
double fahrenheit_to_celsius(double fahrenheit_temperature) {
    double f2c = 5.0/9.0 * (fahrenheit_temperature-32);
    return round(f2c);
}
double fahrenheit_to_kelvin(double fahrenheit_temperature) {
    double f2k = 5.0/9.0*(fahrenheit_temperature-32) + 273;
    return round(f2k);
}
 */