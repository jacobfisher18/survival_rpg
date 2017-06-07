#include <iostream>
#include <string>
#include "player.hpp"
#include "time.hpp"

using std::cout;
using std::endl;
using std::cin;

//global variables
bool keep_playing = true;
Time game_time(8); //start at 8AM
int days_passed = 0;

std::string format_time(int val); //forward declaration

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
    
    while (keep_playing == true) {
        //Check if it is time to go to bed
        //Possible addition: Options (quit game, view stats, etc.)
        cout << "--------------------------------" << endl;
        cout << "MENU " << game_time.to_string() << ", " << days_passed << " days passed" << endl;
        cout << player.get_name() << " | Health: " << player.get_health() << " | Hunger: " << player.get_hunger() << endl;
        cout << "--------------------------------" << endl;
        cout << "What do you want to do (enter number 1-4): " << endl;
        cout << "\t 1. Gather food" << endl;
        cout << "\t 2. Build Sheter" << endl;
        cout << "\t 3. Fight" << endl;
        cout << "\t 4. Mate" << endl;
        cout << "\t 5. Sleep" << endl;
        cout << "\t 6. Quit" << endl;
        int menu_number;
        cin >> menu_number;
        
        switch (menu_number) {
            case 1:
                player.gather_food();
                game_time.progress();
                break;
            case 2:
                player.build_shelter();
                game_time.progress();
                break;
            case 3:
                player.fight();
                game_time.progress();
                break;
            case 4:
                player.mate();
                game_time.progress();
                break;
            case 5:
                player.sleep();
                game_time.set(8);
                days_passed++;
                break;
            case 6:
                keep_playing = false;
                break;
            default:
                break;
        }
    }
    
    
    return 0;
}