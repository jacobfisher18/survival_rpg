#include "player.hpp"

Player::Player(string _name, int species_number) : name(_name), health(100), hunger(100) {
    //set species based on species_number
    switch(species_number) {
        case 1:
            //set member animal variable
            break;
        case 2:
            //set member animal variable
            break;
        case 3:
            //set member animal variable
            break;
        case 4:
            //set member animal variable
            break;
        case 5:
            //set member animal variable
            break;
        case 6:
            //set member animal variable
            break;
        case 7:
            //set member animal variable
            break;
        default: ;
            //use animal 1 by default
    }
}