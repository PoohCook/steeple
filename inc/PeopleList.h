/*
 * File:   PeopleList.h
 * Author: Pooh
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
#include "People.h"


class PeopleList : public std::list<People>{

public:

    bool loadCSV(std::string path){
        std::ifstream infile( path );
        while (infile)
        {
            std::string s;
            if (!getline( infile, s )) break;

            std::istringstream ss( s );
            People person;
            ss >> person;
            push_back(person);
        }

        return true;
    }

};


#endif  //PeopleList_h