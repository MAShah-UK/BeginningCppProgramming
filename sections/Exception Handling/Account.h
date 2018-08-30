#pragma once
#include <string>
#include "Printable.h"

class Account: public Printable {
// protected: // Can be directly accessed from derived classes, but it's bad practice.
    std::string name;
    double balance;
public:
    // TODO: Should constexpr variables be public? Or should I stick to getters and setters?
    // These are compile time constants.
    static constexpr char DEF_NAME [] {"Generic Account"};
    static constexpr double DEF_BALANCE {0.00};

    Account(std::string name = DEF_NAME, double balance = DEF_BALANCE);
    Account(const Account &source);
    virtual ~Account(); // Ensures that correct destructor is called if base class pointer is deleted.

    Account &operator=(const Account &rhs);

    void print(std::ostream &os) const override;

    const std::string &get_name() const;
    void set_name(const std::string &name);
    double get_balance() const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
};