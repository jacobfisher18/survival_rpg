#include "player.hpp"

using std::cout;
using std::endl;

void Player::print() const {
    cout << "Name: " << name << endl;
    Animal::print(); //Animal's print function
    cout << "Health: " << health << endl;
    cout << "Hunger: " << hunger << endl;
    
}