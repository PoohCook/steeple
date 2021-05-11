


#include <iostream>
#include <string>
#include "People.h"

using namespace std;






int main()
{
  std::string value = "Hello Pooh\n";
  cout << value;

  People pooh = People("Pooh Bear", 42, "cake");

  cout << "Hello " << pooh << "\n";

  return 0;
}
