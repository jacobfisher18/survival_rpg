#ifndef shelter_hpp
#define shelter_hpp

#include <stdio.h>
#include <string>

const int restore_multiplier = 5; //how much each level increases sleep restore value

class Shelter {
public:
    Shelter() : level(1) {};
    void upgrade(); //improves the shelter
    int get_level() const; //private member accessor
    int restore() const; //returns the amount of health one sleep in the shelter restores, calculated from level
private:
    int level; //shelter level, indicates how many times the player has upgraded
};

#endif /* shelter_hpp */
