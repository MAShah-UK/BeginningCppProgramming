// Prevents the preprocessor from including the same header file multiple times.
// This method isn't supported by all compilers.
#pragma once
#include <string>
#include <iostream>
using namespace std;

// The corresponding source file is automatically linked, but must include this header.

class Account {
    // Access level of class private by default.
    string name {"Account"}; // Objects will now contain these defaults
    double balance {0.0};    // instead of garbage data.
public:
    // Should use getters and setters to modify/access attributes.
    string get_name();
    void set_name(string name);

    bool deposit(double amount) { // Methods can be declared within the class declaration. Implicitly inline.
        balance += amount;
        cout << amount << " deposited." << endl;
        return true;
    }
    bool withdraw(double amount); // Recommended: Methods can be declared outside of the class declaration.
};
