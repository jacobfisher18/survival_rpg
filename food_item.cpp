#include "food_item.hpp"

Food_item::Food_item() {
    auto it = foods.begin(); //iterator to beginning of the foods map
    
    std::advance(it, rand() % foods.size()); //advance the iterator to random spot in map
    
    name = it->first;
    restore = it->second;
}

void Food_item::print() const {
    std::cout << name << " (restores " << restore << " hunger)" << std::endl;
}