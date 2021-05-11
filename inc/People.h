/*
 * File:   People.h
 * Author: Pooh
 *
 * Created on May 11, 2021
 */

 #ifndef People_H
 #define People_H

#include <string>
#include <iostream>

class People
{
public:
  friend std::ostream& operator<< (std::ostream& o, People const& people);
 
private:
  std::string  name;
  int age;  
  std::string cake_or_cookie;

public:
  People(std::string  name, int age, std::string cake_or_cookie)
  : name(name), age(age), cake_or_cookie(cake_or_cookie){

  }

};


#endif  // People_H