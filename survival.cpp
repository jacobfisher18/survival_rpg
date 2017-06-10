#include <iostream>
#include <string>
#include "player.hpp"
#include "time.hpp"

//global variables
bool keep_playing = true;
Time game_time(8); //start at 8AM
Time bed_time(21); //player must sleep after 9PM
int days_passed = 0;

std::string format_time(int val); //forward declaration

int main() {
    
    srand((int)time(0)); //set a random seed
    
    //Start Menu: Get name
    std::cout << "--------------------------------" << std::endl;
    std::cout << "SURVIVAL RPG" << std::endl;
    std::cout << "What is your animal name?" << std::endl;
    std::string name;
    std::cin >> name;
    
    //Start Menu: Get species
    std::cout << "--------------------------------" << std::endl;
    std::cout << "SURVIVAL RPG" << std::endl;
    std::cout << "Select a species (enter number 1-4): " << std::endl;
    std::cout << "\t 1. Fox: (medium intelligence, medium vision, medium strength)" << std::endl;
    std::cout << "\t 2. Elephant: (high intelligence, low vision, medium strength)" << std::endl;
    std::cout << "\t 3. Deer: (high intelligence, medium vision, low strength)" << std::endl;
    std::cout << "\t 4. Wildcat: (medium intelligence, high vision, low strength)" << std::endl;
    std::cout << "\t 5. Owl: (low intelligence, high vision, medium strength)" << std::endl;
    std::cout << "\t 6. Bear: (low intelligence, medium vision, high strength)" << std::endl;
    std::cout << "\t 7. Lion: (medium intelligence, low vision, high strength)" << std::endl;
    int species_number;
    std::cin >> species_number;
    Species species = static_cast<Species>(species_number);
    
    //Create player object based on name and species
    Player player(name, species);
    
    //Present intro and tutorial
    std::cout << "--------------------------------" << std::endl;
    std::cout << "SURVIVAL RPG" << std::endl;
    std::cout << "This is a survival RPG game. [insert more intro here]" << std::endl;
    
    //keep going if player hasen't exited
    while (keep_playing == true) {
        
        if (bed_time < game_time) {
            std::cout << "--------------------------------" << std::endl;
            std::cout << "It's past your bed time (enter anything to sleep)" << std::endl;
            std::string temp = "";
            std::cin >> temp;
            player.sleep();
            game_time.set(8);
            days_passed++;
        }
        
        else {
            std::cout << "--------------------------------" << std::endl;
            std::cout << "MENU " << game_time.to_string() << ", " << days_passed << " days passed" << std::endl;
            std::cout << player.get_name() << " | Health: " << player.get_health() << " | Hunger: " << player.get_hunger() << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "What do you want to do (enter number 1-4): " << std::endl;
            std::cout << "\t 1. Gather food" << std::endl;
            std::cout << "\t 2. Build sheter" << std::endl;
            std::cout << "\t 3. Fight" << std::endl;
            std::cout << "\t 4. Sleep" << std::endl;
            std::cout << "\t 5. View my stats" << std::endl;
            std::cout << "\t 6. Quit" << std::endl;
            int menu_number;
            std::cin >> menu_number;
            
            switch (menu_number) {
                case 1:
                    player.gather_food();
                    game_time.progress(2);
                    break;
                case 2:
                    player.build_shelter();
                    game_time.progress(2);
                    break;
                case 3:
                    player.fight();
                    game_time.progress(2);
                    break;
                case 4:
                    player.sleep();
                    game_time.set(8);
                    days_passed++;
                    break;
                case 5:
                    player.print();
                    break;
                case 6:
                    keep_playing = false;
                    break;
                default:
                    break;
            }
        }
    }
    
    return 0;
}