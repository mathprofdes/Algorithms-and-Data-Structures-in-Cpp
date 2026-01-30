/*
Author: Don Spickler
Creation Date: 1/28/2022
Last Update: 1/28/2022
Description: Simple example of adding functions to the std namespace.
User Interface: None
Notes: Don't do this.
*/

#include <iostream>
#include <string>

namespace std {
int Double(int q) {
  int retval = 2 * q;
  return retval;
}
} // namespace std

using namespace std;

int main() {
  cout << Double(17) << endl;
  cout << std::Double(25) << endl;

  return 0;
}
