/*
 * File:   TestPeople.cpp
 * Author: Pooh
 *
 * Created on May 12, 2021
 */


#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "People.h"
#include "PeopleList.h"


using namespace std;

BOOST_AUTO_TEST_CASE( PeopleTest_streamout ){

    People people("Pooh", 42, "hunny");

    std::ostringstream ss;

    ss << people;

    BOOST_TEST(ss.str() == "Name: Pooh, age: 42, likes: hunny\n");

}

BOOST_AUTO_TEST_CASE( PeopleTest_streamin ){

    People people;

    std::string s = "Bunny,43,carrots";
    std::istringstream ss(s);

    ss >> people;

    std::ostringstream so;

    so << people;

    BOOST_TEST(so.str() == "Name: Bunny, age: 43, likes: carrots\n");

}
