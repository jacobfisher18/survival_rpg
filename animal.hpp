#ifndef animal_hpp
#define animal_hpp

#include <stdio.h>
#include <string>

class Animal {
public:
    //Animal(int _intelligence, int _vision, int _strength) : intelligence(_intelligence), vision(_vision), strength(_strength) {}
    virtual void fight(Animal& enemy) = 0; //purely virtual function, must be implemented by child classes
private:
    int intelligence;
    int vision;
    int strength;
};


#endif /* animal_hpp */
