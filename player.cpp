#include "player.hpp"
#include "utility.cpp"

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
    std::cout << "Gathering food depends on your vision attribute (" << vision << ") vision..." << std::endl;
    
    //while total food value is under vision value, generate another random food
    int totalRestore = 0;
    while (totalRestore < vision) {
        Food_item new_food; //use default constructor to generate random food item
        food_inventory.push_back(new_food);
        std::cout << "New food item acquired: ";
        new_food.print();
        totalRestore += new_food.getRestore();
    }
}

void Player::build_shelter() {
    std::cout << "Building your shelter depends on your intelligence attribute (" << intelligence << "% chance of success)..." << std::endl;
    
    //chance of successfully upgrading one level is randomly determined (but based on intelligence)
    int randNum = rand() % 100 + 1; //random number between 1 and 100
    
    //higher intelligence increases the chance of this being true
    if (randNum < intelligence) {
        shelter.upgrade(); //upgrade shelter one level
        std::cout << "Good work! Shelter upgraded to level " << shelter.get_level() << std::endl;
    }
    
    else {
        std::cout << "You failed to upgrade your shelter. Maybe try again when you're intelligence is higher." << std::endl;
    }
}

//our function to compare two food items
bool compare_foods(const Food_item &a, const Food_item &b) {
    return (a.getRestore() < b.getRestore());
}

//eat the food with the minimum restore value
void Player::eat() {
    
    //a function pointer, the comparison object we'll use in our min_element algorithm
    bool (*cmp)(const Food_item &a, const Food_item &b) = &compare_foods;
    
    if (food_inventory.size() > 0) {
        auto min_food = std::min_element(food_inventory.begin(), food_inventory.end(), cmp); //find minimum restore value element
        
        std::cout << "You ate a "; min_food->print();
        
        hunger += min_food->getRestore(); //increase hunger bar
        
        if (hunger > 100)
            hunger = 100; //limit hunger at 100
        
        food_inventory.erase(min_food); //erase the food from the list
        
    }
    
    else {
        std::cout << "You have no food" << std::endl;
    }
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
    
    //50% chance of each attribute increasing
    chance_execute([&](){intelligence++; std::cout << "Intelligence increased to " << intelligence << "!" << std::endl;});
    chance_execute([&](){vision++; std::cout << "Vision increased to " << vision << "!" << std::endl;});
    chance_execute([&](){strength++; std::cout << "Strength increased to " << strength << "!" << std::endl;});
}