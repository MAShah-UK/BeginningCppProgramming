#include "Account_Helper.h"

#include <iostream>

void Account_Helper::display_accounts(const std::vector<Account> &accounts) {
    std::cout << "Accounts:" << std::endl;
    for(const Account &account : accounts) {
        std::cout << '\t' << account << std::endl;
    }
}

void Account_Helper::display_accounts(const std::vector<Savings_Account> &accounts) {
    std::cout << "Savings accounts:" << std::endl;
    for(const Savings_Account &account : accounts) {
        std::cout << '\t' << account << std::endl;
    }
}

void Account_Helper::display_accounts(const std::vector<Trust_Account> &accounts) {
    std::cout << "Trust accounts:" << std::endl;
    for(const Trust_Account &account : accounts) {
        std::cout << '\t' << account << std::endl;
    }
}

void Account_Helper::display_accounts(const std::vector<Checking_Account> &accounts) {
    std::cout << "Checking accounts:" << std::endl;
    for(const Checking_Account &account : accounts) {
        std::cout << '\t' << account << std::endl;
    }
}

void Account_Helper::deposit_accounts(std::vector<Account> &accounts, double amount) {
    std::cout << "Depositing " << POUND << amount << " to accounts:" << std::endl;
    for(Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.deposit(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::deposit_accounts(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "Depositing " << POUND << amount << " to savings accounts:" << std::endl;
    for(Savings_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.deposit(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::deposit_accounts(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "Depositing " << POUND << amount << " to trust accounts:" << std::endl;
    for(Trust_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.deposit(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::deposit_accounts(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "Depositing " << POUND << amount << " to checking accounts:" << std::endl;
    for(Checking_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.deposit(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::withdraw_accounts(std::vector<Account> &accounts, double amount) {
    std::cout << "Withdrawing " << POUND << amount << " from accounts:" << std::endl;
    for(Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.withdraw(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::withdraw_accounts(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "Withdrawing " << POUND << amount << " from savings accounts:" << std::endl;
    for(Savings_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.withdraw(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::withdraw_accounts(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "Withdrawing " << POUND << amount << " from trust accounts:" << std::endl;
    for(Trust_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.withdraw(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}

void Account_Helper::withdraw_accounts(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "Withdrawing " << POUND << amount << " from checking accounts:" << std::endl;
    for(Checking_Account &account : accounts) {
        std::cout << '\t' << "Before: " << account << std::endl;
        account.withdraw(amount);
        std::cout << "\t   " << "After: " << POUND << account.get_balance() << std::endl;
    }
}
