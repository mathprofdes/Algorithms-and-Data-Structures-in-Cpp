//============================================================================
// Name        : Objects008.cpp
// Author      : Don Spickler
// Version     : 4/3/2020
// Description : Object Example 8:  More on Destructors.
//============================================================================

#include <iostream>
#include <vector>

#include "Student.h"

using namespace std;

int main() {
  int num = 0;
  int id = 0;
  string name;

  cout << "Number of students: ";
  cin >> num;

  vector<Student> COSC120(num);

  for (int i = 0; i < num; i++) {
    cout << "Name: ";
    cin >> name;
    cout << "ID: ";
    cin >> id;

    COSC120[i].setInfo(name, id, 3, 5);
  }

  for (int i = 0; i < num; i++) {
    cout << "Student: " << COSC120[i].getName() << endl;
    cout << "ID: " << COSC120[i].getID() << endl;
    COSC120[i].printPointers();
    cout << endl;
  }

  return 0;
}
