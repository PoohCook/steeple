#include <string>
#include <list>

#include "People.h"
#include "PeopleList.h"

using namespace std;


int main()
{

  PeopleList peoplelist;
  peoplelist.loadCSV("data/test1.csv");

  PeopleList sortedPeople = peoplelist;
  sortedPeople.sort();

  for (People p : peoplelist) {
        std::cout << "saved: " << p ;
  }

  for (People p : sortedPeople) {
        std::cout << "sorted: " << p ;
  }

  return 0;
}
