//============================================================================
// Name        : Student.h
// Author      : Don Spickler
// Version     : 4/3/2020
// Description : Student object declaration.
//============================================================================

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
  string name;
  int ID;
  double *Exams = nullptr;
  double *Quizzes = nullptr;
  int numExams;
  int numQuizzes;

public:
  Student();
  Student(string, int, int, int);
  ~Student();

  string getName();
  int getID();
  int getNumExams();
  int getNumQuizzes();

  void setInfo(string, int, int, int);

  void InputExamGrade(int, double);
  void InputQuizGrade(int, double);

  void printPointers() { cout << Exams << "  " << Quizzes; }

  double Average();
};

#endif /* STUDENT_H_ */
