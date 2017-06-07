#include "player.hpp"

using std::cout;
using std::endl;

void Player::print() const {
    cout << "Name: " << name << endl;
    Animal::print(); //Animal's print function
    cout << "Health: " << health << endl;
    cout << "Hunger: " << hunger << endl;
    //print food inventory and shelter
}

void Player::gather_food() {
    //to-do
}

void Player::build_shelter() {
    //to-do
}

void Player::fight() {
    health -= 10; //temp
    cout << "Health decreased by 10" << endl; //temp
    cout << "New health: " << health << endl; //temp
}

void Player::mate() {
    //to-do
}

void Player::sleep() {
    cout << "Sleeping in shelter level " << shelter.get_level() << "..." << endl;
    
    if (health == 100) {
        cout << "No health restored (health already full)" << endl;
    }
    
    else {
        int new_health = health + shelter.restore();
        if (new_health > 100) {new_health = 100;}; //health can't exceed 100
        cout << new_health - health << " health points restored." << endl;
        health = new_health;
        cout << "Your health is now at " << health << endl;
    }
}