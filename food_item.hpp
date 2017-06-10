#ifndef food_item_hpp
#define food_item_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <stdlib.h> //for rand

const std::map <std::string, char> foods = {{"Strawberry", 3}, {"Raspberry", 4}, {"Blueberry", 4}};

class Food_item {
public:
    Food_item(); //default constructor, chooses random food
    Food_item(std::string _name, int _restore) : name(_name), restore(_restore) {};
    void print() const;
private:
    std::string name;
    int restore; //how much player hunger the item restores
};

#endif /* food_item_hpp */
