//============================================================================
// Name        : Objects003.cpp
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Object Example #3
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

Triangle CreateTriangle() {
  Triangle t;

  do {
    t.setSideA(10 * frand());
    t.setSideB(10 * frand());
    t.setSideC(10 * frand());
  } while (!t.isTriangle());

  return t;
}

void selectionSort(Triangle array[], int size) {
  int minIndex;
  double minValue;

  for (int start = 0; start < (size - 1); start++) {
    minIndex = start;
    minValue = array[start].Area();
    for (int index = start + 1; index < size; index++) {
      if (array[index].Area() < minValue) {
        minValue = array[index].Area();
        minIndex = index;
      }
    }

    Triangle temp = array[minIndex];
    array[minIndex] = array[start];
    array[start] = temp;
  }
}

int main() {
  srand(time(0));

  int numtris = 0;
  cout << "Input the number of triangles: ";
  cin >> numtris;

  Triangle tris[numtris];

  for (int i = 0; i < numtris; i++) {
    tris[i] = CreateTriangle();
  }

  for (int i = 0; i < numtris; i++) {
    DisplayTrangleInfo(tris[i]);
    cout << endl;
  }

  cout << "~~~~~~~~~~~~~~~" << endl;
  cout << endl;

  selectionSort(tris, numtris);

  for (int i = 0; i < numtris; i++) {
    DisplayTrangleInfo(tris[i]);
    cout << endl;
  }

  return 0;
}
