//============================================================================
// Name        : Objects001.cpp
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Object Example #1
//============================================================================

#include <iostream>

#include "Triangle.h"

using namespace std;

int main() {
  double a = 0, b = 0, c = 0;
  cout << "Input the three sides of the triangle: ";
  cin >> a >> b >> c;

  Triangle t1(a, b, c);

  if (t1.isTriangle()) {
    cout << "Perimeter = " << t1.Perimeter() << endl;
    cout << "Area = " << t1.Area() << endl;
    if (t1.isRight())
      cout << "This is a right triangle." << endl;
    else
      cout << "This is not a right triangle." << endl;
  } else
    cout << "This is not a triangle." << endl;

  return 0;
}
