#ifndef food_item_hpp
#define food_item_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <stdlib.h> //for rand

//data for creating food items, including names and restore values
const std::map <std::string, char> foods = {
    {"Blueberry", 2},
    {"Raspberry", 2},
    {"Strawberry", 3},
    {"Carrot", 4},
    {"Banana", 5},
    {"Apple", 5},
    {"Mushroom", 6},
    {"Sugar Cane", 8},
    {"Cocoa Beans", 8},
    {"Peanuts", 8},
    {"Wheat", 10},
    {"Potato", 12},
    {"Melon", 13},
    {"Pumpkin", 13},
    {"Rabbit", 15},
    {"Salmon", 15},
    {"Chicken", 18},
    {"Beef", 18},
};

class Food_item {
public:
    Food_item(); //default constructor, chooses random food
    Food_item(std::string _name, int _restore) : name(_name), restore(_restore) {};
    void print() const;
    int getRestore() const {return restore;};
private:
    std::string name;
    int restore; //how much player hunger the item restores
};

#endif /* food_item_hpp */