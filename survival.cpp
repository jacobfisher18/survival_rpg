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
    getline(std::cin, name);
    
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
    std::cout << "This is a survival RPG game." << std::endl;
    std::cout << "You are an animal in the wild, and you need to work hard to survive." << std::endl;
    std::cout << "You have a species, attributes, a food inventory, and a shelter." << std::endl;
    std::cout << "Explore the world, try to thrive, and most importantly, don't let your health or hunger get to 0, or you will die." << std::endl;
    
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
            std::cout << "What do you want to do (enter number of option): " << std::endl;
            std::cout << "\t 1. Gather food (2 hours)" << std::endl;
            std::cout << "\t 2. Build sheter (2 hours)" << std::endl;
            std::cout << "\t 3. Fight (2 hours)" << std::endl;
            std::cout << "\t 4. Eat" << std::endl;
            std::cout << "\t 5. Sleep" << std::endl;
            std::cout << "\t 6. View my stats" << std::endl;
            std::cout << "\t 7. Quit" << std::endl;
            int menu_number;
            std::cin >> menu_number;
            
            switch (menu_number) {
                case 1:
                    player.gather_food();
                    game_time.progress(2);
                    player.decrease_hunger_by(4); //decrease hunger by 2 per hour
                    break;
                case 2:
                    player.build_shelter();
                    game_time.progress(2);
                    player.decrease_hunger_by(4); //decrease hunger by 2 per hour
                    break;
                case 3:
                    player.fight();
                    game_time.progress(2);
                    player.decrease_hunger_by(4); //decrease hunger by 2 per hour
                    break;
                case 4:
                    player.eat(); //doesn't take any time
                    break;
                case 5:
                    player.sleep();
                    game_time.set(8);
                    player.decrease_hunger_by(16); //decrease hunger by 2 per hour
                    days_passed++;
                    break;
                case 6:
                    player.print();
                    break;
                case 7:
                    keep_playing = false;
                    break;
                default:
                    break;
            }
            
            //check for death
            if ((player.get_health() <= 0) || (player.get_hunger() <= 0)) {
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Oops, you died! Your health or hunger got too low." << std::endl;
                keep_playing = false;
            }
        }
    }
    
    return 0;
}