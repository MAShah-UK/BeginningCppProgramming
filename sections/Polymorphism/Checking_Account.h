#pragma once

#include <string>
#include "Account.h"

class Checking_Account: public Account {
    static constexpr double DEPOSIT_BONUS {50.00};
    static constexpr double DEPOSIT_BONUS_REQUIRED_AMOUNT {50'000.00};
    static constexpr double WITHDRAW_FEE {1.50};
public:
    Checking_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE);

    // Override ensures that the method signature/return match a base class method.
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};


