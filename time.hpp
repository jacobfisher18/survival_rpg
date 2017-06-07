#ifndef time_hpp
#define time_hpp

#include <stdio.h>
#include <iostream>

class Time {
public:
    Time(int _military_hrs) : military_hrs(_military_hrs) {};
    
    //potential future direction: overload ++ operator instead of progress()
    void progress(); //move forward one hour
    void set(int _military_hrs); //setter
    std::string to_string() const;
private:
    int military_hrs; //0 through 23
    int hrs; //time 1-12
    int am; //whether or not it's the AM
};

#endif /* time_hpp */
