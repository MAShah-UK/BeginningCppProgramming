#include "Account.h"

#include <iostream>

Account::Account(std::string name, double balance)
        : name {name}, balance {balance} {
    // std::cout << " Account initialised" << std::endl;
}

Account::Account(const Account &source)
    : Account {source.name, source.balance} {

}

Account::~Account() {
    // std::cout << " Account destroyed" << std::endl;
}

// Not needed since the compiler does memberwise assignment by default.
Account &Account::operator=(const Account &rhs) {
    name = rhs.name;
    balance = rhs.balance;
    return *this;
}

const std::string &Account::get_name() const {
    return name;
}

void Account::set_name(const std::string &name) {
    Account::name = name;
}

double Account::get_balance() const {
    return balance;
}

void Account::set_balance(double balance) {
    Account::balance = balance;
}

bool Account::deposit(double amount) {
    bool is_valid = (amount > 0);
    if(is_valid) {
        balance += amount;
    }
    return is_valid;
}

bool Account::withdraw(double amount) {
    bool is_valid = (amount > 0 &&
                     balance - amount >= 0);
    if(is_valid) {
        balance -= amount;
    }
    return is_valid;
}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    static constexpr char POUND = 156;
    std::cout << "[" << rhs.get_name() << "] " << POUND << rhs.get_balance();
    return os;
}