#include <iostream>

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
 */