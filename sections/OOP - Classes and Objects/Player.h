// Prevents the preprocessor from including the same header file multiple times.
// This is the universal method supported by all compilers.
#ifndef OOP_CLASSES_AND_OBJECTS_PLAYER_H
#define OOP_CLASSES_AND_OBJECTS_PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private: // Members can only be access by this class or friends.
    // Attributes: define the state of the object.
    string name;
    int health; // Primitive attributes contain garbage data
    int xp;     // if they aren't initialised.
public: // Members can be access from anywhere.
    // Special methods that run automatically during instantiation/destruction.
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
    ~Player();

    // Methods: define the behaviour of the object.
    void talk(string dialog) {
        cout << name << " says: " << dialog << endl;
    }
    bool is_dead(); // Calling a prototype without a definition will cause a linker error.
};

#endif //OOP_CLASSES_AND_OBJECTS_PLAYER_H
