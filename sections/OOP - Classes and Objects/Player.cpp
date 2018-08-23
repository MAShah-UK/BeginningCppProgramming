#include "Player.h"

Player::Player() { // Default constructor requires zero arguments.
    name = "None";
    health = 100;
    xp = 10;
}

Player::Player(string name_val) {
    name = name_val;
    health = 100;
    xp = 10;
}

Player::Player(string name_val, int health_val, int xp_val) {
    name = name_val;
    health = health_val;
    xp = xp_val;
}

Player::~Player() { // Destructor releases resources.

}