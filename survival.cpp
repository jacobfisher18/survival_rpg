#include <iostream>
#include <string>
#include "player.hpp"

using std::cout;
using std::endl;
using std::cin;

//global variables
//time of day
//days passed

int main() {
    
    //Start Menu: Get name
    cout << "--------------------------------" << endl;
    cout << "SURVIVAL RPG" << endl;
    cout << "What is your animal name?" << endl;
    std::string name;
    cin >> name;
    
    //Start Menu: Get species
    cout << "--------------------------------" << endl;
    cout << "SURVIVAL RPG" << endl;
    cout << "Select a species (enter number 1-4): " << endl;
    cout << "\t 1. Fox: (medium intelligence, medium vision, medium strength)" << endl;
    cout << "\t 2. Elephant: (high intelligence, low vision, medium strength)" << endl;
    cout << "\t 3. Deer: (high intelligence, medium vision, low strength)" << endl;
    cout << "\t 4. Wildcat: (medium intelligence, high vision, low strength)" << endl;
    cout << "\t 5. Owl: (low intelligence, high vision, medium strength)" << endl;
    cout << "\t 6. Bear: (low intelligence, medium vision, high strength)" << endl;
    cout << "\t 7. Lion: (medium intelligence, low vision, high strength)" << endl;
    int species_number;
    cin >> species_number;
    Species species = static_cast<Species>(species_number);
    
    //Create player object based on name and species
    Player player(name, species);
    
    //Present intro and tutorial
    cout << "--------------------------------" << endl;
    cout << "SURVIVAL RPG" << endl;
    cout << "This is a survival RPG game. [insert more intro here]" << endl;
    
    //Options
    //display information here: time of day, health, hunger
    cout << "--------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "What do you want to do (enter number 1-X): " << endl;
    cout << "\t 1. Gather food" << endl;
    cout << "\t 2. Build Sheter" << endl;
    cout << "\t 3. Fight" << endl;
    cout << "\t 4. Mate" << endl;
    int menu_number;
    cin >> menu_number;
    
    switch (menu_number) {
        case 1:
            player.gather_food();
            break;
        case 2:
            player.build_shelter();
            break;
        case 3:
            player.fight();
            break;
        case 4:
            player.mate();
            break;
        default:
            break;
    }
    
    return 0;
}

void collect() {
    //to implement
}
