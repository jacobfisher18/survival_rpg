#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include "animal.hpp"

using std::string;

class Player {
public:
    Player(string _name, int species_number);
private:
    string name;
    int health;
    int hunger;
    Animal* my_animal; //manages strength, intelligence, vision attributes
    //inventory of food: a data structure of food objects
    //shelter: an object with name, description, sleep value
};

#endif