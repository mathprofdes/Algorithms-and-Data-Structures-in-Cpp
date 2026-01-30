//============================================================================
// Name        : Objects004.cpp
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Object Example #4: Pointers to objects and Structs.
//============================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Triangle.h"

using namespace std;

void DisplayTrangleInfo(Triangle *t) {
  cout << "Pointer to the Object Parameter" << endl;

  if (t->isTriangle()) {
    cout << "Side Lengths = (" << t->getSideA() << ", " << t->getSideB() << ", "
         << t->getSideC() << ")" << endl;
    cout << "Perimeter = " << t->Perimeter() << endl;
    cout << "Area = " << t->Area() << endl;
    if (t->isRight())
      cout << "This is a right triangle." << endl;
    else
      cout << "This is not a right triangle." << endl;
  } else
    cout << "This is not a triangle." << endl;
}

void DisplayTrangleInfo(Triangle t) {
  cout << "Object Parameter" << endl;

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

struct Rectangle {
  double width;
  double height;

  double Area() { return width * height; }
};

int main() {
  double a = 0, b = 0, c = 0;
  cout << "Input the three sides of the triangle: ";
  cin >> a >> b >> c;

  Triangle *t1 = new Triangle();
  t1->setSideA(a);
  t1->setSideB(b);
  t1->setSideC(c);

  if (t1->isTriangle()) {
    cout << "Side Lengths = (" << t1->getSideA() << ", " << t1->getSideB()
         << ", " << t1->getSideC() << ")" << endl;
    cout << "Perimeter = " << t1->Perimeter() << endl;
    cout << "Area = " << t1->Area() << endl;
    if (t1->isRight())
      cout << "This is a right triangle." << endl;
    else
      cout << "This is not a right triangle." << endl;
  } else
    cout << "This is not a triangle." << endl;

  cout << endl;

  Triangle *t2 = new Triangle(a + 1, b + 1, c + 1);

  DisplayTrangleInfo(*t2);
  cout << endl;
  DisplayTrangleInfo(t2);

  cout << endl;

  cout << t2->Area() << endl;
  cout << (*t2).Area() << endl;

  cout << endl;

  Triangle t3(4, 3, 6);
  DisplayTrangleInfo(t3);

  cout << t3.Area() << endl;
  cout << (&t3)->Area() << endl;

  delete t1;
  delete t2;
  t1 = nullptr;
  t2 = nullptr;

  Rectangle R1;
  R1.height = 5;
  R1.width = 7;

  cout << endl;
  cout << R1.Area() << endl;
  cout << (&R1)->Area() << endl;

  Rectangle *R2 = new Rectangle();
  R2->height = 4;
  R2->width = 17;

  cout << endl;
  cout << R2->Area() << endl;
  cout << (*R2).Area() << endl;

  delete R2;
  R2 = nullptr;

  return 0;
}
