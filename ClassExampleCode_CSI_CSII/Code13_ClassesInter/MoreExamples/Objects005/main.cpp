//============================================================================
// Name        : Objects005.cpp
// Author      : Don Spickler
// Version     : 4/1/2020
// Description : Object Example #5: Inline Member Functions
//============================================================================

#include <iostream>

#include "Triangle.h"

using namespace std;

void DisplayTrangleInfo(Triangle t) {
  if (t.isTriangle()) {
    cout << "Side Lengths = (" << t.getSideA() << ", " << t.getSideB() << ", "
         << t.getSideC() << ")" << endl;
    cout << "Perimeter = " << t.Perimeter() << endl;
    cout << "Area = " << t.Area() << endl;
    if (t.isRight())
      cout << "This is a right triangle." << endl;
    else
      cout << "This is not a right triangle." << endl;
  } else
    cout << "This is not a triangle." << endl;
}

int main() {
  double a = 0, b = 0, c = 0;
  cout << "Input the three sides of the triangle: ";
  cin >> a >> b >> c;

  Triangle t1(a, b, c);
  DisplayTrangleInfo(t1);
  cout << endl;

  Triangle t2;
  DisplayTrangleInfo(t2);

  return 0;
}
