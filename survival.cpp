#include <iostream>
#include <string>
#include "player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

//global variables
//time of day
//days passed

int main() {
    
    //Display start menu
    cout << "SURVIVAL RPG" << endl;
    cout << "What is your animal name?" << endl;
    string name;
    cin >> name;
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
    Player my_player(name, species, 10, 10, 10); //temp 10, 10, 10
    
    //Show intro tutorial
    
    //Loop that presents the menu
    return 0;
}
