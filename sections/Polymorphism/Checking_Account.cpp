#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {

}

bool Checking_Account::deposit(double amount) {
    if(amount >= DEPOSIT_BONUS_REQUIRED_AMOUNT) {
        amount += DEPOSIT_BONUS;
    }
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) {
    amount -= WITHDRAW_FEE;
    return Account::withdraw(amount);
}