/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 2/3/2024
Description: This program demonstrates the bad_alloc exception.
User Interface: None
Notes: Run this along with a system monitor that tracks system memory.
*/

#include <iostream>
#include <new> // Needed for bad_alloc

using namespace std;

int main() {
  double *ptr = nullptr; // Pointer to double
  long sz = 1000000000;
  char ch;

  try {
    ptr = new double[sz];

    for (long i = 0; i < sz; i++)
      ptr[i] = i;

  } catch (const bad_alloc &e) {
    cout << "Insufficient memory.\n";
  }

  cout << "Wait..." << endl;
  cin >> ch;

  cout << "End Program..." << endl;

  delete[] ptr;

  return 0;
}
