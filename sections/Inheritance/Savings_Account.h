#pragma once

#include "Account.h"

class Savings_Account : public Account { // Public single class inheritance.
protected:
    double interest_rate;
public:
    Savings_Account();
    Savings_Account(const Savings_Account &source);
    Savings_Account(std::string name, double balance = 0.0, double interest_rate = 3.0);
    ~Savings_Account();

    Savings_Account &operator=(const Savings_Account &rhs);

    void deposit(double amount);
    void withdraw(double amount);
};