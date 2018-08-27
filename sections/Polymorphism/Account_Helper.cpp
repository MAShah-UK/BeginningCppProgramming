#include "Account_Helper.h"

#include <iostream>

void Account_Helper::display_accounts(const std::vector<Account*> &accounts) {
    std::cout << "Accounts:" << std::endl;
    for(const Account *const account : accounts) {
        std::cout << '\t' << *account << std::endl;
    }
}

void Account_Helper::deposit_accounts(std::vector<Account*> &accounts, double amount) {
    std::cout << "Depositing " << POUND << amount << " to accounts:" << std::endl;
    for(Account *account : accounts) {
        std::cout << '\t' << "Before: " << *account << std::endl;
        account->deposit(amount);
        std::cout << "\t   " << "After: " << POUND << account->get_balance() << std::endl;
    }
}

void Account_Helper::withdraw_accounts(std::vector<Account*> &accounts, double amount) {
    std::cout << "Withdrawing " << POUND << amount << " from accounts:" << std::endl;
    for(Account *account : accounts) {
        std::cout << '\t' << "Before: " << *account << std::endl;
        account->withdraw(amount);
        std::cout << "\t   " << "After: " << POUND << account->get_balance() << std::endl;
    }
}

void Account_Helper::delete_accounts(std::vector<Account*> &accounts) {
    for(Account *account: accounts) {
        delete account;
    }
    accounts.clear(); // Remove dangling pointers.
}