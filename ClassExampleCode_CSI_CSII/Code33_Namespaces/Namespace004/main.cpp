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
} // namespace stuff

namespace stuff2 {
int x = -1;
int y = 7;
int z = 12;
} // namespace stuff2

using namespace stuff;
using namespace stuff2; //  references to x, y, and z are ambiguous...

int main() {
  cout << stuff::x << " " << stuff::y << " " << stuff::z << endl;

  x = 13;
  //	stuff::x = 7;
  stuff::z = 2 * stuff::x + stuff::y;

  cout << stuff::x << " " << stuff::y << " " << stuff::z << endl;
  cout << x << " " << y << " " << z << endl;
  cout << stuff2::x << " " << stuff2::y << " " << stuff2::z << endl;

  return 0;
}
