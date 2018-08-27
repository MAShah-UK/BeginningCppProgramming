#pragma one

#include <string>
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
    static constexpr double DEPOSIT_BONUS {50.00};
    static constexpr double DEPOSIT_BONUS_REQUIRED_AMOUNT {5'000.00};
    static constexpr double MAX_WITHDRAW_PERCENTAGE = 20.0;
    static constexpr int MAX_WITHDRAWALS = 3;

    int withdrawals;
public:
    Trust_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE, double interest_rate = DEF_INTEREST_RATE);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};