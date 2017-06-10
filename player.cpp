#include "player.hpp"

using std::cout;
using std::endl;

void Player::print() const {
    cout << "Name: " << name << endl;
    Animal::print(); //Animal's print function
    cout << "Health: " << health << endl;
    cout << "Hunger: " << hunger << endl;
    cout << "Shelter level: " << shelter.get_level() << endl;
    print_food_inventory();
}

void Player::print_food_inventory() const {
    cout << "--------------------------------" << endl;
    cout << "Food Inventory" << endl;
    for (auto it = food_inventory.begin(); it != food_inventory.end(); ++it) {
        it->print();
    }
    
    if (food_inventory.size() == 0) {
        cout << "No food owned..." << endl;
    }
}

void Player::gather_food() {
    Food_item new_food; //uses default constructor to generate random food item
    food_inventory.push_back(new_food);
    
    cout << "New food item acquired" << endl;
    new_food.print();
}

void Player::build_shelter() {
    shelter.upgrade(); //upgrade shelter one level
    
    cout << "Shelter upgraded to level " << shelter.get_level() << endl;
}

void Player::fight() {
    health -= 10; //temp
    cout << "Health decreased by 10" << endl; //temp
    cout << "New health: " << health << endl; //temp
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