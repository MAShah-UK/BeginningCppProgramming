#pragma once

#include "Account.h"

class Savings_Account : public Account { // Public single class inheritance.
    double interest_rate;
public:
    static constexpr double DEF_INTEREST_RATE = 3.0;

    Savings_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE, double interest_rate = DEF_INTEREST_RATE);
    Savings_Account(const Savings_Account &source);

    Savings_Account &operator=(const Savings_Account &rhs);

    // Overrides base class methods.
    void print(std::ostream &os) const override;
    bool deposit(double amount) override;

    double get_interest_rate() const;
    void set_interest_rate(double interest_rate);
};