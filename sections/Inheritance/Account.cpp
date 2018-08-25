#include "Account.h"

#include <iostream>

Account::Account()
    : Account {"Generic Account"} {

}

Account::Account(const Account &source)
    : Account {source.name, source.balance} {

}

Account::Account(std::string name, double balance)
    : name {name}, balance {balance} {
    std::cout << "[" << name << "]" << " Account initialised" << std::endl;
}

Account::~Account() {
    std::cout << "[" << name << "]" << " Account destroyed" << std::endl;
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

void Account::deposit(double amount) {
    std::cout << "[" << name << "]" << " Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "[" << name << "]" << " Account withdraw called with " << amount << std::endl;
}
