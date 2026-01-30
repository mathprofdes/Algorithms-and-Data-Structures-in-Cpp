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

int main() {
  cout << stuff::x << " " << stuff::y << " " << stuff::z << endl;

  // x = 13; // error
  stuff::x = 7;
  stuff::z = 2 * stuff::x + stuff::y;

  cout << stuff::x << " " << stuff::y << " " << stuff::z << endl;

  return 0;
}
