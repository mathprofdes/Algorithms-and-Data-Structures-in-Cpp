//============================================================================
// Name        : Objects006.cpp
// Author      : Don Spickler
// Version     : 4/2/2020
// Description : Object Example #6: Destructors.
//============================================================================

#include "Demo.h"
#include <iostream>

using namespace std;

void fct1(Demo d) {
  cout << "In function 1" << endl;
  cout << "Object transferred: " << d.getName() << endl;
  cout << "Leaving function 1" << endl;
}

void fct2(Demo *d) {
  cout << "In function 2" << endl;
  cout << "Object referenced: " << d->getName() << endl;
  cout << "Leaving function 2" << endl;
}

int main() {
  cout << "Program Start" << endl;

  Demo Obj1("Obj1");
  Demo *Obj2 = new Demo("Obj2");

  cout << "Our Objects: " << Obj1.getName() << "  " << Obj2->getName() << endl;

  cout << endl;
  fct1(Obj1);
  cout << endl;
  fct1(*Obj2);
  cout << endl;

  cout << endl;
  fct2(&Obj1);
  cout << endl;
  fct2(Obj2);
  cout << endl;

  delete Obj2;
  // 	delete Obj2;
  // 	delete Obj1;

  Obj2 = nullptr;

  cout << "Program End" << endl;

  return 0;
}
