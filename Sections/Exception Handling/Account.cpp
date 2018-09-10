#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

#include <iostream>

Account::Account(std::string name, double balance)
        : name {name}, balance {balance} {
    // std::cout << " Account initialised" << std::endl;
    if(balance < 0.0) {
        throw IllegalBalanceException();
    }
}

Account::Account(const Account &source)
    : Account {source.name, source.balance} {

}

Account::~Account() {
    // std::cout << " Account destroyed" << std::endl;
}

Account &Account::operator=(const Account &rhs) {
    name = rhs.name;
    balance = rhs.balance;
    return *this;
}

void Account::print(std::ostream &os) const {
    std::cout << "[" << get_name() << "] " << POUND_SYMBOL << get_balance();
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

void Account::deposit(double amount) {
    if(amount < 0) {
        throw IllegalBalanceException();
    }
    balance += amount;
}

void Account::withdraw(double amount) {
    bool is_valid = (amount > 0 &&
                     balance - amount >= 0);
    if(amount < 0) {
        throw IllegalBalanceException();
    }
    if(balance - amount < 0) {
        throw InsufficientFundsException();
    }
    balance -= amount;
}