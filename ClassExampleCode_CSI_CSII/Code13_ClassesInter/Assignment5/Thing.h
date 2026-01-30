/*
 Author: Don Spickler
 Creation Date: 1/23/2022
 Last Update: 1/23/2022
 Description: Specification of the Thing class, contains fields name and age,
 accessor and mutator functions.
 */

#ifndef THING_H_
#define THING_H_

#include <string>

using namespace std;

class Thing {
private:
  string name;
  int age;
  int *numbers;

public:
  Thing(string n = "", int a = 0);
  ~Thing();
  Thing(const Thing &obj);

  int getAge();
  string getName();
  int getNumber(int);
  int *getNumbersLocation();

  void setName(string);
  void setAge(int);
  void setNumber(int, int);

  const Thing operator=(const Thing &right);
};

#endif /* THING_H_ */
