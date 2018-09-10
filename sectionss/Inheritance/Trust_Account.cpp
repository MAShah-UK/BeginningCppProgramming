#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
    : Savings_Account {name, balance, interest_rate}, withdrawals {} {

}

bool Trust_Account::deposit(double amount) {
    if(amount > DEPOSIT_BONUS_REQUIRED_AMOUNT) {
        amount += DEPOSIT_BONUS;
    }
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    const double withdraw_percentage = amount/get_balance()*100;
    if(withdraw_percentage > MAX_WITHDRAW_PERCENTAGE ||
       withdrawals == MAX_WITHDRAWALS) {
        return false;
    }
    bool is_valid = Account::withdraw(amount);
    if(is_valid) {
        ++withdrawals;
    }
    return is_valid;
}