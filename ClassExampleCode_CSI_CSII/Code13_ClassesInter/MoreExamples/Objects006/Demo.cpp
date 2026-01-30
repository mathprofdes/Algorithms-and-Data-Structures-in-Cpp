#include "Demo.h"
#include <iostream>

using namespace std;

Demo::Demo(string objname) {
  name = objname;
  cout << "Constructor for " << name << endl;
}

Demo::~Demo() { cout << "Destructor for " << name << endl; }

string Demo::getName() { return name; }
