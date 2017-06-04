#include "animal.hpp"

using std::cout;
using std::endl;

Animal::Animal(Species _species) : species(_species) {
    //set attributes based on species
    switch (_species) {
        case Fox:
            intelligence = med_att;
            vision = med_att;
            strength = med_att;
            break;
        case Elephant:
            intelligence = high_att;
            vision = low_att;
            strength = med_att;
            break;
        case Deer:
            intelligence = high_att;
            vision = med_att;
            strength = low_att;
            break;
        case Wildcat:
            intelligence = med_att;
            vision = high_att;
            strength = low_att;
            break;
        case Owl:
            intelligence = low_att;
            vision = high_att;
            strength = med_att;
            break;
        case Bear:
            intelligence = low_att;
            vision = med_att;
            strength = high_att;
            break;
        case Lion:
            intelligence = med_att;
            vision = low_att;
            strength = high_att;
            break;
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