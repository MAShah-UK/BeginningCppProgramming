#include "Account.h"
#include "Savings_Account.h"
#include <iostream>

int main() {
    std::cout << "Creating Account object in stack memory." << std::endl;
    Account acc {"GenAcc1"};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    std::cout << std::endl;

    std::cout << "Creating Account object in heap memory." << std::endl;
    Account *ptr_acc {nullptr};
    ptr_acc = new Account {"GenAcc2"};
    ptr_acc->deposit(1000.0);
    ptr_acc->withdraw(500.0);
    delete ptr_acc;
    std::cout << std::endl;

    std::cout << "Creating Savings_Account object in stack memory." << std::endl;
    Savings_Account savings {"SavAcc1"};
    savings.deposit(2000.0);
    savings.withdraw(500.0);
    std::cout << std::endl;

    std::cout << "Creating Savings_Account object in heap memory." << std::endl;
    Savings_Account *ptr_savings {nullptr};
    ptr_savings = new Savings_Account {"SavAcc2"};
    ptr_savings->deposit(1000.0);
    ptr_savings->withdraw(500.0);
    delete ptr_savings;
    std::cout << std::endl;

    return 0;
}