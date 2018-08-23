#include "Player.h"

int Player::player_count = 0;

int Player::get_player_count() {
    return player_count;
}

Player::Player() { // Default constructor requires zero arguments to be supplied.
    name = "None"; // Inefficient as attributes are being reassigned, not initialised.
    this->health = 0; // this is a pointer to the current object. Identical to health = 0.
    this->xp = 0; // Identical to xp = 0.
}

Player::Player(const Player &source) // Copy constructor creates a copy of another object.
    : Player {source.name, source.health, source.xp} {
    // Create deep copies of all pointers in source.
}

// Move constructor creates a shallow copy of another object,
// and then sets the source's pointers to nullptr.
Player::Player(Player &&source)
    : Player {source.name, source.health, source.xp} {
    // Set all pointers to nullptr in source.
}

// Delegated constructor reuses a pre-existing constructor overload.
Player::Player(string name_val) : Player {name_val, 0, 0} {

}

// Constructor initialiser lists are more efficient than 'initialising' in the body.
Player::Player(string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val} {
    ++player_count;
}

Player::~Player() { // Destructor releases resources.
    // Call delete ptr for every pointer.
    --player_count;
}

const string &Player::get_name() const {
    return name;
}

void Player::set_name(const string &name) {
    Player::name = name;
}

int Player::get_health() const {
    return health;
}

void Player::set_health(int health) {
    Player::health = health;
}

int Player::get_xp() const {
    return xp;
}

void Player::set_xp(int xp) {
    Player::xp = xp;
}
