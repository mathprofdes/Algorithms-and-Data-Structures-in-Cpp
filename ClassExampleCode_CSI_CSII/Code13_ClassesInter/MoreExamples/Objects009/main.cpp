//============================================================================
// Name        : Objects009.cpp
// Author      : Don Spickler
// Version     : 4/4/2020
// Description : Objects Example 9: Operator Overloading.  Example updated
//               from text.
//============================================================================

#include <iostream>

#include "FeetInches.h"
using namespace std;

int main() {
  double d;
  int i;

  FeetInches d1(5, 7);
  FeetInches d2(3);
  FeetInches d3;

  cout << d1 << endl;
  cout << d2 << endl;
  cout << d3 << endl;

  cout << "Enter a distance d1 in feet and inches:" << endl;
  cin >> d1;

  cout << "Enter a distance d2 in feet and inches:" << endl;
  cin >> d2;

  cout << endl;
  cout << d1 + d2 << endl;
  cout << d1 - d2 << endl;

  cout << endl;
  cout << d1++ << endl;
  cout << d1 << endl;
  cout << ++d1 << endl;
  cout << d1 << endl;

  cout << endl;
  if (d1 > d2)
    cout << "d1 > d2" << endl;
  else if (d1 < d2)
    cout << "d1 < d2" << endl;
  else
    cout << "d1 = d2" << endl;

  d = d1;
  i = d1;

  cout << endl;
  cout << "The value " << d1;
  cout << " is equivalent to " << d << " feet" << endl;
  cout << "or " << i << " feet, rounded down." << endl;

  return 0;
}
