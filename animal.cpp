#include "animal.hpp"

using std::cout;
using std::endl;

Animal::Animal(Species _species) : species(_species) {
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

void Animal::print() const {
    cout << "Species: " << get_species_string(species) << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Vision: " << vision << endl;
    cout << "Strength: " << strength << endl;
}

std::string Animal::get_species_string(Species species) const {
    std::string all_species[7] = {
        "Fox",
        "Elephant",
        "Deer",
        "Wildcat",
        "Owl",
        "Bear",
        "Lion"
    };
    
    return all_species[species - 1]; //implicitly casts species to int, shift down 1 because array is 0 indexed
    
}