#include "player.hpp"

void Player::print() const {
    std::cout << "Name: " << name << std::endl;
    Animal::print(); //Animal's print function (from parent class)
    std::cout << "Health: " << health << std::endl;
    std::cout << "Hunger: " << hunger << std::endl;
    std::cout << "Shelter level: " << shelter.get_level() << std::endl;
    print_food_inventory();
}

void Player::print_food_inventory() const {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Food Inventory" << std::endl;
    for (auto it = food_inventory.begin(); it != food_inventory.end(); ++it) {
        it->print();
    }
    
    if (food_inventory.size() == 0) {
        std::cout << "No food owned..." << std::endl;
    }
}

void Player::gather_food() {
    std::cout << "Gathering food depends on your vision attribute..." << std::endl;
    
    Food_item new_food; //uses default constructor to generate random food item
    food_inventory.push_back(new_food);
    
    std::cout << "New food item acquired" << std::endl;
    new_food.print();
}

void Player::build_shelter() {
    std::cout << "Building your shelter depends on your intelligence attribute..." << std::endl;
    
    shelter.upgrade(); //upgrade shelter one level
    
    std::cout << "Shelter upgraded to level " << shelter.get_level() << std::endl;
}

void Player::fight() {
    std::cout << "Fighting depends on your strength attribute..." << std::endl;
    
    health -= 10; //temp
    
    std::cout << "Health decreased by 10" << std::endl; //temp
    std::cout << "New health: " << health << std::endl; //temp
}

void Player::sleep() {
    std::cout << "Sleeping in shelter level " << shelter.get_level() << "..." << std::endl;
    
    if (health == 100) {
        std::cout << "No health restored (health already full)" << std::endl;
    }
    
    else {
        int new_health = health + shelter.restore();
        if (new_health > 100) {new_health = 100;}; //health can't exceed 100
        std::cout << new_health - health << " health points restored." << std::endl;
        health = new_health;
        std::cout << "Your health is now at " << health << std::endl;
    }
}