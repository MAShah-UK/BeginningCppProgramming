#include "Account.h"
#include "Savings_Account.h"
#include "Account_Helper.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Account*> accounts {
            new Account {"Bob", 100},
            new Account {"Lex", 200},
            new Account {"Max", 300}
    };
    Account_Helper::display_accounts(accounts);
    Account_Helper::deposit_accounts(accounts, 152.55);
    Account_Helper::withdraw_accounts(accounts, 420.00);
    Account_Helper::delete_accounts(accounts);
    std::cout << std::endl;

    std::vector<Account*> savings_accounts {
            new Savings_Account {"Jack", 100, 2.75},
            new Savings_Account {"John", 200},
            new Savings_Account {"Judy", 300, 3.5}
    };
    Account_Helper::display_accounts(savings_accounts);
    Account_Helper::deposit_accounts(savings_accounts, 99.99);
    Account_Helper::withdraw_accounts(savings_accounts, 401.00);
    Account_Helper::delete_accounts(accounts);
    std::cout << std::endl;

    std::vector<Account*> trust_accounts {
            new Trust_Account {"Barry", 1'000, 2.75},
            new Trust_Account {"Henry", 10'000},
            new Trust_Account {"Simon", 100'000, 3.5}
    };
    Account_Helper::display_accounts(trust_accounts);
    Account_Helper::deposit_accounts(trust_accounts, 55'200.00);
    Account_Helper::withdraw_accounts(trust_accounts, 25'000.00);
    Account_Helper::delete_accounts(accounts);
    std::cout << std::endl;

    std::vector<Account*> checking_accounts {
            new Checking_Account {"Bertha", 1'000},
            new Checking_Account {"Peters", 10'000},
            new Checking_Account {"Russel", 100'000}
    };
    Account_Helper::display_accounts(checking_accounts);
    Account_Helper::deposit_accounts(checking_accounts, 75'550.00);
    Account_Helper::withdraw_accounts(checking_accounts, 1'000.00);
    Account_Helper::delete_accounts(accounts);

    return 0;
}