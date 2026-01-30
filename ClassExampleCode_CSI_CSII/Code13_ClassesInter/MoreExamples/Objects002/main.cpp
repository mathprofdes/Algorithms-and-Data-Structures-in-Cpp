//============================================================================
// Name        : Objects002.cpp
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Object Example #2
//============================================================================

#include <cstdlib>
#include <ctime>
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

double frand() { return static_cast<double>(rand()) / RAND_MAX; }

int main() {
  srand(time(0));

  int numtris = 0;
  cout << "Input the number of triangles: ";
  cin >> numtris;

  Triangle tris[numtris];

  for (int i = 0; i < numtris; i++) {
    do {
      tris[i].setSideA(10 * frand());
      tris[i].setSideB(10 * frand());
      tris[i].setSideC(10 * frand());
    } while (!tris[i].isTriangle());
  }

  for (int i = 0; i < numtris; i++) {
    DisplayTrangleInfo(tris[i]);
    cout << endl;
  }

  return 0;
}
