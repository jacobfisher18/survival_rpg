#ifndef animal_hpp
#define animal_hpp

#include <stdio.h>
#include <string>
#include "species.cpp"

class Animal {
public:
    Animal(Species _species, int _intelligence, int _vision, int _strength)
        : species(_species), intelligence(_intelligence), vision(_vision), strength(_strength) {}
    void fight(Animal& enemy);
private:
    int intelligence;
    int vision;
    int strength;
    Species species;
};


#endif /* animal_hpp */
