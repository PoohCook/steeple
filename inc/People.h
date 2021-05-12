/*
 * File:   People.h
 * Author: Pooh
 *
 * Created on May 11, 2021
 */

 #ifndef People_H
 #define People_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


class People{

public:
  friend std::ostream& operator<< (std::ostream& o, People const& people);
  friend std::istream& operator>> (std::istream& i, People& fred);
 
private:
  std::string  name;
  int age;  
  std::string cake_or_cookie;

public:
  People(){};
  
  People(std::string  name, int age, std::string cake_or_cookie)
  : name(name), age(age), cake_or_cookie(cake_or_cookie){

  }

  bool operator< (const People& p) const {
      return (age < p.age); 
  }

  std::string str(){
    std::ostringstream ss;
    ss << *this;
    return ss.str();
  }

};


#endif  // People_H