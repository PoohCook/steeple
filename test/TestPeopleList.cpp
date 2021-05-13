/*
 * File:   TestPeopleList.cpp
 * Author: Pooh
 *
 * Test Suite to validate the implementation of the PeopleList class. Using Boost library
 * because Pooh says every short creature needs a boost
 * 
 * This tets suite includes a performance bracketing test on the PeopleList sort against a 
 * million rows... (PeopleListTest_bigloading)
 * 
 * Created on May 12, 2021
 */

#include <string>
#include <iostream>
#include <chrono>
#include <boost/test/unit_test.hpp>

#include "Person.h"
#include "PeopleList.h"


using namespace std;
using namespace std::chrono;

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

BOOST_AUTO_TEST_CASE( PeopleListTest_bigloading ){
    
    auto begin = high_resolution_clock::now();

    PeopleList peoplelist;
    peoplelist.loadCSV("data/test2.csv");

    BOOST_CHECK_EQUAL(peoplelist.size(), 1000000ul);

    auto mark = high_resolution_clock::now();
    auto load_time_msec = duration_cast<milliseconds>(mark - begin);
    begin = mark;

    peoplelist.sort();

    mark = high_resolution_clock::now();
    auto sort_time_msec = duration_cast<milliseconds>(mark - begin);

    cout << "Load duration: "
         << load_time_msec.count() << " msec " 
         << "Sort duration: "
         << sort_time_msec.count() << " msec "
         << "Size: "
         << peoplelist.size()
         << endl;

    BOOST_TEST( sort_time_msec.count() < 1200 );
}
