/*
 * File:   Person.cpp
 * Author: Pooh
 *
 * Created on May 11, 2021
 */

#include "Person.h"

const std::set<std::string> Person::valid_cc_types = { "cake", "cookie", "crumpet" , "scone", "cakes", "cookies"};

std::ostream& operator<< (std::ostream& o, Person const& person)
{
  return o << "Name: " << person.name 
           << ", age: " << person.age 
           << ", likes: " << person._cake_or_cookie 
           << "\n";
}

std::istream& operator>>(std::istream& i, Person& person) {
    std::string line;
    char delim;
    if(std::getline(i, line)) { 
        std::istringstream ss(line);
        std::string c_or_c;
        if(not(std::getline(ss , person.name, ',') >> person.age >> delim >> c_or_c)) {
            i.setstate(std::ios::failbit);
        }
        person.set_cake_or_cookie(c_or_c);
    }
    return i;
}