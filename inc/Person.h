/*
 * File:   Person.h
 * Author: Pooh
 *
 * Description: a class to represent people by name, age, and sweet treat likes
 * The class deviates a bit by being called person but it's not Pooh's style
 * to use a plural to name a class that represents a sigular entity.
 * 
 * liberty was also taken to allow the cake_or_cookie member to encompass being more specific 
 * about what type of cookie
 * 
 * Clean Code Rules
 * 
 * Created on May 11, 2021
 */

 #ifndef Person_H
 #define Person_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <set>

class Person{

public:
  friend std::ostream& operator<< (std::ostream& o, Person const& person);
  friend std::istream& operator>> (std::istream& i, Person& fred);
 
  std::string  name;
  int age;  

private:
  std::string _cake_or_cookie;
  static const std::set<std::string> valid_cc_types;

public:
  Person(){};
  
  Person(std::string  name, int age, std::string cake_or_cookie)
  : name(name), age(age){
    set_cake_or_cookie(cake_or_cookie);
  }

  bool operator< (const Person& p) const {
      return (age < p.age); 
  }

  bool set_cake_or_cookie(std::string c_or_c){
    if(valid_cc_types.find(c_or_c) != valid_cc_types.end()){
      _cake_or_cookie = c_or_c;
      return true;
    }

    return false;
  }
  std::string get_cake_or_cookie(){
    return _cake_or_cookie;
  }

  std::string str(){
    std::ostringstream ss;
    ss << *this;
    return ss.str();
  }

};


#endif  // Person_H