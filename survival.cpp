#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

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
    
    //Set up variables, create player object
    
    //Show intro tutorial
    
    //Loop that presents the menu
    return 0;
}
