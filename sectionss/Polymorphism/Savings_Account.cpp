#include <iostream>
#include "Savings_Account.h"

// Constructors are called from the root class to the most derived class.
// Specifies a base class constructor, otherwise base class default constructor is called.
Savings_Account::Savings_Account(std::string name, double balance, double interest_rate)
        : Account {name, balance}, interest_rate {interest_rate} {
    // std::cout << "[" << get_name() << "]" << " Savings_Account initialised" << std::endl;
}

// Source is sliced from Savings_Account to Account.
Savings_Account::Savings_Account(const Savings_Account &source)
    : Account {source}, interest_rate {source.interest_rate} {
    // std::cout << "[" << get_name() << "]" << " Savings_Account initialised" << std::endl;
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

// Method is overridden from Account.
bool Savings_Account::deposit(double amount) {
    double interest_amount = amount/100.0 * interest_rate;
    amount += interest_amount;
    return Account::deposit(amount); // Call base class version.
}

void Savings_Account::print(std::ostream &os) const {
    std::cout << "[" << get_name() << "] "
              << POUND_SYMBOL << get_balance() << " "
              << get_interest_rate() << '%';
}

double Savings_Account::get_interest_rate() const {
    return interest_rate;
}

void Savings_Account::set_interest_rate(double interest_rate) {
    this->interest_rate = interest_rate;
}
