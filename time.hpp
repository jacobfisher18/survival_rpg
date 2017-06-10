#ifndef time_hpp
#define time_hpp

#include <stdio.h>
#include <iostream>

class Time {
public:
    Time(int _military_hrs) : military_hrs(_military_hrs) {};
    
    void progress(int progress_time); //move forward by progress_time hours
    void set(int _military_hrs); //setter
    std::string to_string() const;
    bool operator<(const Time &other_time) const;
private:
    int military_hrs; //0 through 23
};

#endif /* time_hpp */
