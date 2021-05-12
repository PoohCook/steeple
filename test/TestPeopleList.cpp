/*
 * File:   TestPeopleList.cpp
 * Author: Pooh
 *
 * Created on May 12, 2021
 */

#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "Person.h"
#include "PeopleList.h"


using namespace std;

BOOST_AUTO_TEST_CASE( PeopleListTest_loading ){

    PeopleList peoplelist;
    peoplelist.loadCSV("data/test1.csv");

    BOOST_CHECK_EQUAL(peoplelist.size(), 6ul);

    BOOST_TEST(peoplelist.front().str() == "Name: Pooh, age: 42, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: Rabbit, age: 33, likes: cookies\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: eeyore, age: 35, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: piglet, age: 23, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: owl, age: 65, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: tigger, age: 33, likes: cookies\n" );

}


BOOST_AUTO_TEST_CASE( PeopleListTest_sort ){

    PeopleList peoplelist;
    peoplelist.loadCSV("data/test1.csv");
    peoplelist.sort();

    BOOST_CHECK_EQUAL(peoplelist.size(), 6ul);

    BOOST_TEST(peoplelist.front().str() == "Name: piglet, age: 23, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: Rabbit, age: 33, likes: cookies\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: tigger, age: 33, likes: cookies\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: eeyore, age: 35, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: Pooh, age: 42, likes: cake\n" );
    peoplelist.pop_front();
    BOOST_TEST(peoplelist.front().str() == "Name: owl, age: 65, likes: cake\n" );

}
