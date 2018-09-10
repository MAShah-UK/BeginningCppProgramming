// Prevents the preprocessor from including the same header file multiple times.
// This is the universal method supported by all compilers.
#ifndef OOP_CLASSES_AND_OBJECTS_PLAYER_H
#define OOP_CLASSES_AND_OBJECTS_PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private: // Members can only be access by this class or friends.
    friend void display_player(Player player); // This friend has access to private members.
    // Attributes: define the state of the object.
    static int player_count;
    string name;
    int health; // Primitive attributes contain garbage data
    int xp;     // if they aren't initialised.
public: // Members can be access from anywhere.
    // Methods: define the behaviour of the object.
    static int get_player_count();

    // Constructors/destructor methods run automatically during instantiation/destruction.
    Player();
    Player(const Player &source);
    Player(Player &&source);
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
    ~Player();

    // Getters and setters encapsulate attributes.
    const string &get_name() const;
    void set_name(const string &name);
    int get_health() const;
    void set_health(int health);
    int get_xp() const;
    void set_xp(int xp);

    void talk(string dialog) const {
        cout << name << " says: " << dialog << endl;
    }
    bool is_dead() const; // Calling a prototype without a definition will cause a linker error.
};

#endif //OOP_CLASSES_AND_OBJECTS_PLAYER_H
