/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Simple example of extracting command-line arguments.
User Interface: ./prog <list of arguments>
Notes: None
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  cout << "You entered " << (argc - 1) << " command line argument(s)." << endl;

  if (argc > 1) {
    cout << "Here they are:" << endl;
    for (int count = 1; count < argc; count++)
      cout << argv[count] << endl;
  }
  return 0;
}
