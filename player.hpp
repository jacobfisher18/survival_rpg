#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include <list>
#include <stdlib.h> //for rand
#include "animal.hpp"
#include "shelter.hpp"
#include "food_item.hpp"

//player inherits from animal
class Player : public Animal {
public:
    Player(std::string _name, Species _species)
    : Animal(_species), name(_name), health(100), hunger(100), shelter(Shelter()) {}
    void print() const; //overriding parent's implementation
    void print_food_inventory() const;
    void gather_food();
    
    void build_shelter();
    void fight();
    void sleep();
    
    std::string get_name() const {return name;} //accessor
    int get_health() const {return health;} //accessor
    int get_hunger() const {return hunger;} //accessor
private:
    std::string name;
    int health;
    int hunger;
    Shelter shelter;
    std::list<Food_item> food_inventory;
};

#endif