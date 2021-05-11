/*
 * File:   People.cpp
 * Author: Pooh
 *
 * Created on May 11, 2021
 */


#include "People.h"


std::ostream& operator<< (std::ostream& o, People const& people)
{
  return o << "Name: " << people.name 
           << ", age: " << people.age 
           << ", likes: " << people.cake_or_cookie 
           << "\n";
}

std::istream& operator>>(std::istream& i, People& people) {
    std::string line;
    char delim;
    if(std::getline(i, line)) { 
        std::istringstream ss(line);

        if(not(std::getline(ss , people.name, ',') >> people.age >> delim >> people.cake_or_cookie)) {
            i.setstate(std::ios::failbit);
        }
    }
    return i;
}