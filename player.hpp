#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include "animal.hpp"

//player inherits from animal
class Player : public Animal {
public:
    Player(std::string _name, Species _species) : Animal(_species), name(_name), health(100), hunger(100) {}
    void print() const; //overriding parent's implementation
    void gather_food();
    void build_shelter();
    void fight();
    void mate();
private:
    std::string name;
    int health;
    int hunger;
    //inventory of food: a data structure of food objects
    //shelter: an object with name, description, sleep value
};

#endif