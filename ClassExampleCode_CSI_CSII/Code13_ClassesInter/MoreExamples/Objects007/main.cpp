//============================================================================
// Name        : Objects007.cpp
// Author      : Don Spickler
// Version     : 4/3/2020
// Description : Object Example 7:  More on Destructors.
//============================================================================

#include "Student.h"
#include <iostream>

using namespace std;

int main() {
  double val = 0;
  Student stu("John Doe", 123456789, 3, 8);

  for (int i = 0; i < stu.getNumExams(); i++) {
    cout << "Input exam " << (i + 1) << " score: ";
    cin >> val;
    stu.InputExamGrade(i + 1, val);
  }

  for (int i = 0; i < stu.getNumQuizzes(); i++) {
    cout << "Input quiz " << (i + 1) << " score: ";
    cin >> val;
    stu.InputQuizGrade(i + 1, val);
  }

  cout << endl;
  cout << "Student: " << stu.getName() << endl;
  cout << "ID: " << stu.getID() << endl;
  cout << "Average: " << stu.Average() << endl;

  return 0;
}
