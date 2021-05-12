#include <string>
#include <list>

#include "Person.h"
#include "PeopleList.h"

using namespace std;


int main()
{

  PeopleList peoplelist;
  peoplelist.loadCSV("data/test1.csv");

  PeopleList sortedPeople = peoplelist;
  sortedPeople.sort();

  for (Person p : peoplelist) {
        std::cout << "saved: " << p ;
  }

  for (Person p : sortedPeople) {
        std::cout << "sorted: " << p ;
  }

  return 0;
}
