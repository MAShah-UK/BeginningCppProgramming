#pragma once
#include <string>

class Account {
// protected: // Can be directly accessed from derived classes, but it's bad practice.
    std::string name;
    double balance;
public:
    Account();
    Account(const Account &source);
    Account(std::string name, double balance = 0.0);
    ~Account();

    Account &operator=(const Account &rhs);

    const std::string &get_name() const;
    void set_name(const std::string &name);
    double get_balance() const;
    void set_balance(double balance);

    void deposit(double amount);
    void withdraw(double amount);
};