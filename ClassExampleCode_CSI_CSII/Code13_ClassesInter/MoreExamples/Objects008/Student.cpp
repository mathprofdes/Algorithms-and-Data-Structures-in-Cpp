//============================================================================
// Name        : Student.cpp
// Author      : Don Spickler
// Version     : 4/3/2020
// Description : Student object implementation.
//============================================================================

#include <string>

#include "Student.h"

using namespace std;

Student::Student() { cout << "Default constructor " << endl; }

Student::Student(string studentname, int studentID, int numberOfExams,
                 int numberOfQuizzes) {

  cout << "Non default constructor " << studentname << endl;

  name = studentname;
  ID = studentID;
  Exams = new double[numberOfExams];
  Quizzes = new double[numberOfQuizzes];
  numExams = numberOfExams;
  numQuizzes = numberOfQuizzes;
}

Student::~Student() {
  cout << "Destructor " << endl;
  delete[] Exams;
  delete[] Quizzes;
}

void Student::setInfo(string studentname, int studentID, int numberOfExams,
                      int numberOfQuizzes) {
  cout << "Set Info" << studentname << endl;

  name = studentname;
  ID = studentID;
  Exams = new double[numberOfExams];
  Quizzes = new double[numberOfQuizzes];
  numExams = numberOfExams;
  numQuizzes = numberOfQuizzes;
}

void Student::InputExamGrade(int num, double score) {
  if (num < 1 || num > numExams)
    return;

  Exams[num - 1] = score;
}

void Student::InputQuizGrade(int num, double score) {
  if (num < 1 || num > numQuizzes)
    return;

  Quizzes[num - 1] = score;
}

double Student::Average() {
  double sumScores = 0;
  double sumPossible = 0;

  for (int i = 0; i < numExams; i++) {
    sumScores += Exams[i];
    sumPossible += 100;
  }

  for (int i = 0; i < numQuizzes; i++) {
    sumScores += Quizzes[i];
    sumPossible += 10;
  }

  return sumScores / sumPossible * 100;
}

string Student::getName() { return name; }
int Student::getID() { return ID; }
int Student::getNumExams() { return numExams; }
int Student::getNumQuizzes() { return numQuizzes; }
