#include "time.hpp"

void Time::progress() {
    if (military_hrs < 23)
        military_hrs++;
    else
        military_hrs = 0;
}

std::string Time::to_string() const {
    if (military_hrs == 0) {return "12:00AM";}
    else if (military_hrs < 12) {return (std::to_string(military_hrs) + ":00AM");}
    else if (military_hrs == 12) {return "12:00PM";}
    else if (military_hrs < 24) {return (std::to_string(military_hrs - 12) + ":00PM");}
    else {return "0:00";} //military time was invalid
}

void Time::set(int _military_hrs) {
    military_hrs = _military_hrs;
}