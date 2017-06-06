#include "shelter.hpp"

int Shelter::get_level() const {
    return level;
}

void Shelter::upgrade() {
    level++;
}

int Shelter::restore() const {
    return level * restore_multiplier;
}