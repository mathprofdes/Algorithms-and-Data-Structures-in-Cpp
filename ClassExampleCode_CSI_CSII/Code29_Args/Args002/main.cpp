/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Simple example of extracting command-line arguments.
User Interface: ./prog <list of arguments>
Notes: The atoi function is the C version of stoi.  The difference is that
atoi ignores (returns 0) if the input does not represent an integer. The
stoi C++ version will throw an exception in this case.  So if we convert
the accumulator to use stoi we should also include a try-catch block around
the command.
*/

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "You entered " << (argc - 1) << " command line argument(s)." << endl;

  int sum = 0;

  if (argc > 1) {
    for (int count = 1; count < argc; count++)
      sum += atoi(argv[count]);

    cout << "Sum = " << sum << endl;
  }
  return 0;
}
