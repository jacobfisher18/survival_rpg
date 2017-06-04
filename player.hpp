#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include "animal.hpp"

using std::string;

//player inherits from animal
class Player : public Animal {
public:
    Player(string _name, Species _species) : Animal(_species), name(_name), health(100), hunger(100) {}
private:
    string name;
    int health;
    int hunger;
    //inventory of food: a data structure of food objects
    //shelter: an object with name, description, sleep value
};

#endif