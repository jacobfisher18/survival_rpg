#ifndef animal_hpp
#define animal_hpp

#include <stdio.h>
#include <string>
#include "species.cpp"

//constants that definte what make a low, medium, and high attribute value
const int low_att = 4;
const int med_att = 4;
const int high_att = 4;

class Animal {
public:
    Animal(Species _species) : species(_species) {
        //set attributes based on species
        switch (static_cast<int>(_species)) {
            case 1:
                intelligence = med_att;
                vision = med_att;
                strength = med_att;
            case 2:
                intelligence = high_att;
                vision = low_att;
                strength = med_att;
            case 3:
                intelligence = high_att;
                vision = med_att;
                strength = low_att;
            case 4:
                intelligence = med_att;
                vision = high_att;
                strength = low_att;
            case 5:
                intelligence = low_att;
                vision = high_att;
                strength = med_att;
            case 6:
                intelligence = low_att;
                vision = med_att;
                strength = high_att;
            case 7:
                intelligence = med_att;
                vision = low_att;
                strength = high_att;
            default:
                //default animal values
                intelligence = med_att;
                vision = med_att;
                strength = med_att;
        }
    }
    void fight(Animal& enemy);
private:
    int intelligence;
    int vision;
    int strength;
    Species species;
};

#endif /* animal_hpp */
