#ifndef animal_hpp
#define animal_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "species.cpp"

//constants that definte what make a low, medium, and high attribute value
const int low_att = 4;
const int med_att = 7;
const int high_att = 10;

class Animal {
public:
    Animal(Species _species);
    void print() const; //print species and attributes
    std::string get_species_string(Species species) const; //get species string given enum
protected:
    //protected variables can be accessed by the child class
    int intelligence;
    int vision;
    int strength;
    Species species;
};

#endif /* animal_hpp */
