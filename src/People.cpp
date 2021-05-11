/*
 * File:   People.cpp
 * Author: Pooh
 *
 * Created on May 11, 2021
 */

#include "People.h"

std::ostream& operator<< (std::ostream& o, People const& people)
{
  return o << people.name << " is " << people.age;
}
