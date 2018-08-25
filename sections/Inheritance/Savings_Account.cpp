#include <iostream>
#include "Savings_Account.h"

// Constructors are called from the root class to the most derived class.
Savings_Account::Savings_Account()
    : Savings_Account {"Generic Savings Account"} {

}

// Source is sliced from Savings_Account to Account.
Savings_Account::Savings_Account(const Savings_Account &source)
    : Account {source}, interest_rate {source.interest_rate} {

}

// Specifies a base class constructor, otherwise base class default constructor is called.
Savings_Account::Savings_Account(std::string name, double balance, double interest_rate)
    : Account {name, balance}, interest_rate {interest_rate} {
    std::cout << "[" << get_name() << "]" << " Savings_Account initialised" << std::endl;
}

// Destructors are called from the most derived class to the root class.
Savings_Account::~Savings_Account() {
    std::cout << "[" << get_name() << "]" << " Savings_Account destroyed" << std::endl;
}

// Not needed since the compiler does memberwise assignment by default
// for base class then for derived class.
Savings_Account &Savings_Account::operator=(const Savings_Account &rhs) {
    if(this == &rhs) {
        return *this;
    }

    // Must manually call base class version since I defined the
    // derived class version. Compiler won't automatically do it.
    Account::operator=(rhs); // Must specify or call is ambiguous.
    interest_rate = rhs.interest_rate;
    return *this;
}

void Savings_Account::deposit(double amount) {

}

void Savings_Account::withdraw(double amount) {

}
