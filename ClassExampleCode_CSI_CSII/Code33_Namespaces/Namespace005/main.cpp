/*
Author: Don Spickler
Creation Date: 1/28/2022
Last Update: 1/28/2022
Description: Simple example of constructing your own namespaces.
User Interface: None
Notes: None
*/

#include <iostream>
#include <string>

using namespace std;

namespace stuff {
int x = 0;
int y = 3;
int z = 9;

int doSomething(int q) {
  int retval = 0;

  if (q > z)
    retval = x;
  else
    retval = z;

  return retval;
}
} // namespace stuff

int main() {
  cout << stuff::x << " " << stuff::y << " " << stuff::z << endl;

  cout << stuff::doSomething(5) << endl;
  cout << stuff::doSomething(15) << endl;

  return 0;
}
