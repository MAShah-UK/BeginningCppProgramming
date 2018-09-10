#include "Account.h"
#include "Savings_Account.h"
#include "Account_Helper.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Account*> savings_accounts {
            new Savings_Account {"Jack", 100, 2.75},
            new Savings_Account {"John", 200},
            new Savings_Account {"Judy", 300, 3.5}
    };
    Account_Helper::display_accounts(savings_accounts);
    Account_Helper::deposit_accounts(savings_accounts, 99.99);
    Account_Helper::withdraw_accounts(savings_accounts, 401.00);
    Account_Helper::delete_accounts(savings_accounts);
    std::cout << std::endl;

    std::vector<Account*> trust_accounts {
            new Trust_Account {"Barry", 1'000, 2.75},
            new Trust_Account {"Henry", 10'000},
            new Trust_Account {"Simon", 100'000, 3.5}
    };
    Account_Helper::display_accounts(trust_accounts);
    Account_Helper::deposit_accounts(trust_accounts, 55'200.00);
    Account_Helper::withdraw_accounts(trust_accounts, 25'000.00);
    Account_Helper::delete_accounts(trust_accounts);
    std::cout << std::endl;

    std::vector<Account*> checking_accounts {
            new Checking_Account {"Bertha", 1'000},
            new Checking_Account {"Peters", 10'000},
            new Checking_Account {"Russel", 100'000}
    };
    Account_Helper::display_accounts(checking_accounts);
    Account_Helper::deposit_accounts(checking_accounts, 75'550.00);
    Account_Helper::withdraw_accounts(checking_accounts, 1'000.00);
    Account_Helper::delete_accounts(checking_accounts);

    return 0;
}

/*
Quiz 1: C++ achieves polymorphism by using ________.
virtual functions

Quiz 2: Virtual functions are very powerful since they are bound at ________.
runtime

Quiz 3: The ________ keyword is used with virtual functions
to tell the compiler that the function is being ________.
override, overridden

Quiz 4: In order to achieve dynamic polymorphism we must reference class objects using ________.
base class pointers/references

Quiz 5: Classes that declare virtual functions should always declare a virtual ________.
destructor

Quiz 6: If a class declares a pure virtual function, then that class is considered ________.
abstract

Quiz 7: Classes with only pure virtual functions are often used in C++ as ________ classes.
interface

Quiz 8: What statement below is NOT true?
Abstract base classes cannot be instantiated - true.
Dynamic polymorphism allows programmers to think more abstractly - true.
Pointers to a base class can be assigned the address of a derived class object - true.
Dynamic polymorphism is more efficient than static binding - false.

Quiz 9: The final specifier is used to ________.
prevent classes being derived and methods being overridden.

Quiz 10: A class that declares a function as ________ expects
it to be overridden in classes derived from it.
virtual
 */