#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    // Attributes: define the state of the object.
    string name;
    int health; // Primitive attributes contain garbage data
    int xp;     // if they aren't initialised.

    // Methods: define the behaviour of the object.
    void talk(string dialog) { cout << name << " says: " << dialog << endl; }
    bool is_dead(); // Calling a prototype without a definition will cause a linker error.
};

class Account {
public:
    string name {"Account"}; // Objects will now contain these defaults
    double balance {0.0};    // instead of garbage data.

    bool deposit(double bal) { balance += bal; cout << bal << " deposited." << endl; return true; }
    bool withdraw(double bal) { balance -= bal; cout << bal << " withdrawn." << endl; return true; }
};

int main() {
    Player frank;
    frank.name = "Frank";       // Using dot operator to access attribute.
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there. :)"); // Using dot operator to access method.

    Player hero;

    Player players[3] {frank, hero}; // Copies frank and hero to create new objects.

    Player *enemy {nullptr};
    enemy = new Player;
    (*enemy).name = "Enemy"; // Dot operator syntax with pointers.
    enemy->health = 100;     // Recommend: Arrow/member-of-pointer operator.
    enemy->xp = 15;
    enemy->talk("I will destroy you!");
    // ...
    delete enemy;
    cout << endl;

    Account franks_account;
    franks_account.name = "Frank's Account";
    franks_account.balance = 5000.0;
    franks_account.deposit(1000.0);
    franks_account.withdraw(500.0);

    Account jim_acc;

    return 0;
}

/*
Challenge 1: Create Dog object and initialise it.
#include "Dog.h"
Dog test_dog() {
    Dog spot;
    spot.name = "Spot";
    spot.age = 5;
    return spot;
}
 */