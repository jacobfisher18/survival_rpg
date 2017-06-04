#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include "animal.hpp"

using std::string;

class player {
public:
    player(string _name) : name(_name), health(100), hunger(100) { } //covered in class: member initialization list, default arguments, etc.
private:
    string name;
    int health;
    int hunger;
    animal my_animal; //manages strength, intelligence, vision attributes
    //inventory of food: a data structure of food objects
    //shelter: an object with name, description, sleep value
};

#endif