#pragma once

#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

class Account_Helper {
    static constexpr char POUND = 156;
public:
    static void display_accounts(const std::vector<Account> &accounts);
    static void display_accounts(const std::vector<Savings_Account> &accounts);
    static void display_accounts(const std::vector<Trust_Account> &accounts);
    static void display_accounts(const std::vector<Checking_Account> &accounts);

    static void deposit_accounts(std::vector<Account> &accounts, double amount);
    static void deposit_accounts(std::vector<Savings_Account> &accounts, double amount);
    static void deposit_accounts(std::vector<Trust_Account> &accounts, double amount);
    static void deposit_accounts(std::vector<Checking_Account> &accounts, double amount);

    static void withdraw_accounts(std::vector<Account> &accounts, double amount);
    static void withdraw_accounts(std::vector<Savings_Account> &accounts, double amount);
    static void withdraw_accounts(std::vector<Trust_Account> &accounts, double amount);
    static void withdraw_accounts(std::vector<Checking_Account> &accounts, double amount);
};
