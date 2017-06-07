#ifndef food_item_hpp
#define food_item_hpp

#include <stdio.h>
#include <string>

class Food_item {
public:
    Food_item(std::string _name, int _restore) : name(_name), restore(_restore) {};
private:
    std::string name;
    int restore; //how much player hunger the item restores
};

#endif /* food_item_hpp */
