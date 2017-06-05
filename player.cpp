#include "player.hpp"

using std::cout;
using std::endl;

void Player::print() const {
    cout << "Name: " << name << endl;
    Animal::print(); //Animal's print function
    cout << "Health: " << health << endl;
    cout << "Hunger: " << hunger << endl;
}

void Player::gather_food() {
    //to-do
}

void Player::build_shelter() {
    //to-do
}

void Player::fight() {
    //to-do
}

void Player::mate() {
    //to-do
}