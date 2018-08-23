#include <iostream> // This syntax is used for system file includes.
#include <string>
#include "Player.h" // This syntax is used for local/project file includes.
#include "Account.h"

using namespace std;


int main() {
    Player frank("Frank", 100, 10);
    //frank.name = "Frank";       // Using dot operator to access attribute.
    //frank.health = 100;
    //frank.xp = 10;
    frank.talk("Hi there. :)"); // Using dot operator to access method.

    Player hero("Hero");
    hero.talk("Watch out. I'm the hero.");

    Player players[3] {frank, hero}; // Copies frank and hero to create new objects.

    Player *enemy {nullptr};
    enemy = new Player; // No arguments provided. Uses default constructor.
    //(*enemy).name = "Enemy"; // Dot operator syntax with pointers.
    //enemy->health = 100;     // Recommend: Arrow/member-of-pointer operator.
    //enemy->xp = 15;
    enemy->talk("I will destroy you!");
    // ...
    delete enemy; // Destructor called for Player object that enemy points to.
    cout << endl;

    Account franks_account;
    //franks_account.name = "Frank's Account"; // Should use getters and setters instead - encapsulation.
    //franks_account.balance = 5000.0;
    franks_account.set_name("Frank's Account");
    franks_account.deposit(1000.0);
    franks_account.withdraw(500.0);

    Account jim_acc;

    return 0;
} // Destructor called for all objects on stack.

/*
Challenge 1: Create Dog object and initialise it.
#include "Dog.h"
Dog test_dog() {
    Dog spot;
    spot.name = "Spot";
    spot.age = 5;
    return spot;
}

Challenges 2, 3, and 4: Write getters and setters for Dog class and some additional methods.
class Dog {
    string name;
    int age;
public:
    Dog() {
        name = "None";
        age = 0;
    }

    string get_name() {
        return name;
    }
    void set_name(string new_name) {
        name = new_name;
    }
    int get_age() {
        return age;
    }
    void set_age(int new_age) {
        age = new_age;
    }
    int get_human_years() {
        return age*7;
    }
    string speak() {
        return "Woof";
    }
};
 */