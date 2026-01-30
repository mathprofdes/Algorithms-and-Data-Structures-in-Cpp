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

public:
  Thing(string n = "", int a = 0);

  int getAge();
  string getName();

  void setName(string);
  void setAge(int);
};

#endif /* THING_H_ */
