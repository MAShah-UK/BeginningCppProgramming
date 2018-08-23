#include "Account.h" // Must include corresponding header file.

// Must specify class name and method via scope resolution operator.
bool Account::withdraw(double amount) {
    if(balance-amount >= 0) {
        balance -= amount;
        cout << amount << " withdrawn." << endl;
    }
    return true;
}

string Account::get_name() {
    return name;
}

void Account::set_name(string name) {
    Account::name = name;
}
