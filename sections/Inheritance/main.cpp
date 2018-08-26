#include "Account.h"
#include "Savings_Account.h"
#include "Account_Helper.h"
#include <iostream>
#include <vector>

int main() {
//    std::cout << "Creating Account object in stack memory." << std::endl;
//    Account acc {"GenAcc1"};
//    acc.deposit(2000.0);
//    acc.withdraw(500.0);
//    std::cout << std::endl;
//
//    std::cout << "Creating Account object in heap memory." << std::endl;
//    Account *ptr_acc {nullptr};
//    ptr_acc = new Account {"GenAcc2"};
//    ptr_acc->deposit(1000.0);
//    ptr_acc->withdraw(500.0);
//    delete ptr_acc;
//    std::cout << std::endl;
//
//    std::cout << "Creating Savings_Account object in stack memory." << std::endl;
//    Savings_Account savings {"SavAcc1"};
//    savings.deposit(2000.0);
//    savings.withdraw(500.0);
//    std::cout << std::endl;
//
//    std::cout << "Creating Savings_Account object in heap memory." << std::endl;
//    Savings_Account *ptr_savings {nullptr};
//    ptr_savings = new Savings_Account {"SavAcc2"};
//    ptr_savings->deposit(1000.0);
//    ptr_savings->withdraw(500.0);
//    delete ptr_savings;
//    std::cout << std::endl;

    // Challenge: Create Checking_Account, and Trust_Account classes.
    std::vector<Account> accounts {
        Account {"Bob", 100},
        Account {"Lex", 200},
        Account {"Max", 300}
    };
    Account_Helper::display_accounts(accounts);
    Account_Helper::deposit_accounts(accounts, 152.55);
    Account_Helper::withdraw_accounts(accounts, 420.00);
    std::cout << std::endl;

    std::vector<Savings_Account> savings_accounts {
            Savings_Account {"Jack", 100, 2.75},
            Savings_Account {"John", 200},
            Savings_Account {"Judy", 300, 3.5}
    };
    Account_Helper::display_accounts(savings_accounts);
    Account_Helper::deposit_accounts(savings_accounts, 99.99);
    Account_Helper::withdraw_accounts(savings_accounts, 401.00);
    std::cout << std::endl;

    // Can directly initialise as compile can determine type being initialised.
    std::vector<Trust_Account> trust_accounts {
            {"Barry", 1'000, 2.75},
            {"Henry", 10'000},
            {"Simon", 100'000, 3.5}
    };
    Account_Helper::display_accounts(trust_accounts);
    Account_Helper::deposit_accounts(trust_accounts, 55'200.00);
    Account_Helper::withdraw_accounts(trust_accounts, 25'000.00);
    std::cout << std::endl;

    std::vector<Checking_Account> checking_accounts {
            {"Bertha", 1'000},
            {"Peters", 10'000},
            {"Russel", 100'000}
    };
    Account_Helper::display_accounts(checking_accounts);
    Account_Helper::deposit_accounts(checking_accounts, 75'550.00);
    Account_Helper::withdraw_accounts(checking_accounts, 1'000.00);

    return 0;
}

/*
Quiz 1: ________ is when you derive a new class from an existing class.
Inheritance

Quiz 2: The following base class members are always inherited by a derived class.
Public, protected, and private.

Quiz 3: ________ is when a derived class has 2 or more base classes.
Multiple inheritance

Quiz 4: A public data member of a base class is ________ in
its derived class when using public inheritance.
public

Quiz 5: A private data member of a base class is ________ in
its derived class when using public inheritance.
not accessible

Quiz 6: A collection of classes related with via
inheritance relationships is called a(n) ________.
inheritance hierarchy

Quiz 7: Which statement is NOT always true given the class declarations below?
class A: public B { };
class C: public B { };
class D: public C { };

A is a C.

Quiz 8: Which statement below is NOT true about inheritance?
Inheritance always improves the quality of a design.

Quiz 9: Given the class declarations below. In what order are the class
constructors executed when we create an object of type D?
class A: public B { };
class C: public B { };
class D: public C { };

B > C > D

Quiz 10: Given the class declarations below. In what order are the
class destructors executed when we create an object of type D?
class A: public B { };
class C: public B { };
class D: public C { };

D > C > B.
 */