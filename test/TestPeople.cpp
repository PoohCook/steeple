/*
 * File:   TestPeople.cpp
 * Author: Pooh
 *
 * Test Suite to validate the implementation of the Person class. Using Boost library
 * because Pooh says every short creature needs a boost
 * 
 * Created on May 12, 2021
 */

#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "Person.h"
#include "PeopleList.h"

using namespace std;

BOOST_AUTO_TEST_CASE( PeopleTest_streamout ){

    Person person("Pooh", 42, "scone");

    std::ostringstream ss;

    ss << person;

    BOOST_CHECK_EQUAL(ss.str(), "Name: Pooh, age: 42, likes: scone\n");
    BOOST_CHECK_EQUAL(person.name, "Pooh");
    BOOST_CHECK_EQUAL(person.age, 42);
    BOOST_CHECK_EQUAL(person.get_cake_or_cookie(), "scone");

}

BOOST_AUTO_TEST_CASE( PeopleTest_streamin ){

    Person person;

    std::string s = "Bunny,43,cake";
    std::istringstream ss(s);

    ss >> person;

    std::ostringstream so;

    so << person;

    BOOST_CHECK_EQUAL(so.str(), "Name: Bunny, age: 43, likes: cake\n");

}


BOOST_AUTO_TEST_CASE( PeopleTest_bad_type ){

    Person person("Pooh", 42, "hunny");

    std::ostringstream ss;

    ss << person;

    BOOST_CHECK_EQUAL(ss.str(), "Name: Pooh, age: 42, likes: \n");
    BOOST_CHECK_EQUAL(person.name, "Pooh");
    BOOST_CHECK_EQUAL(person.age, 42);
    BOOST_CHECK_EQUAL(person.get_cake_or_cookie(), "");

    bool result = person.set_cake_or_cookie("bread");
    BOOST_CHECK_EQUAL(person.get_cake_or_cookie(), "");
    BOOST_CHECK(!result);

    result = person.set_cake_or_cookie("cake");
    BOOST_CHECK_EQUAL(person.get_cake_or_cookie(), "cake");
    BOOST_CHECK(result);

}
