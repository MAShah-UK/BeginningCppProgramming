#pragma once

#include "Account.h"

class Savings_Account : public Account { // Public single class inheritance.
    double interest_rate;
public:
    static constexpr double DEF_INTEREST_RATE = 3.0;

    Savings_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE, double interest_rate = DEF_INTEREST_RATE);
    Savings_Account(const Savings_Account &source);
    ~Savings_Account();

    Savings_Account &operator=(const Savings_Account &rhs);

    double get_interest_rate() const;
    void set_interest_rate(double interest_rate);

    // Redefines base class method.
    bool deposit(double amount) override;
};

std::ostream &operator<<(std::ostream &os, const Savings_Account &rhs);