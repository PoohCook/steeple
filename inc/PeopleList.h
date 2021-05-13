/*
 * File:   PeopleList.h
 * Author: Pooh
 *
 * Description: a class to provide a sortable linked list of Person classes. Pooh refrained
 * from coding one more linked list from scratch in his life. std::lsit is a doubly liked 
 * list at it's core and it is unlikely that great improvement can be done upon it's implementation.
 * 
 * The list does provide for it being laodable form a CSV file in order ot streamline the creation 
 * of big load testing
 * 
 * Clean Code Rules
 * 
 * Created on May 11, 2021
 */

#ifndef PeopleList_h
#define PeopleList_h

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Person.h"

class PeopleList : public std::list<Person>{

public:

    bool loadCSV(std::string path){
        std::ifstream infile( path );
        while (infile)
        {
            std::string s;
            if (!getline( infile, s )) break;

            std::istringstream ss( s );
            Person person;
            ss >> person;
            push_back(person);
        }

        return true;
    }

};


#endif  //PeopleList_h