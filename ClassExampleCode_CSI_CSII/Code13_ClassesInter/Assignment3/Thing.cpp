/*
 Author: Don Spickler
 Creation Date: 1/23/2022
 Last Update: 1/23/2022
 */

#include "Thing.h"

/*
 Description: Constructor
 Parameters:
 n - string for the name.
 a - int for the age.
 */

Thing::Thing(string n, int a) {
  name = n;
  age = a;
  numbers = new int[5];
  for (int i = 0; i < 5; i++)
    numbers[i] = 0;
}

/*
 Description: Destructor
 */

Thing::~Thing() { delete[] numbers; }

/*
 Description: Gets the age of the object.
 Parameters: None
 Return: Age field value.
 */

int Thing::getAge() { return age; }

/*
 Description: Gets the name of the object.
 Parameters: None
 Return: Name field value.
 */

string Thing::getName() { return name; }

/*
 Description: Sets the name of the object.
 Parameters: n - name of the object.
 Return: None
 */

void Thing::setName(string n) { name = n; }

/*
 Description: Sets the age of the object.
 Parameters: a - age of the object.
 Return: None
 */

void Thing::setAge(int a) { age = a; }

/*
 Description: Gets the number stored in the pos position of the array.
 Parameters: pos - position to extract.
 Return: value from the pos position of the array.
 */

int Thing::getNumber(int pos) { return numbers[pos]; }

/*
 Description: Sets the number stored in the pos position of the array to the
 input value. Parameters: pos - position to change. val - new value Return: None
 */

void Thing::setNumber(int pos, int val) { numbers[pos] = val; }

/*
 Description: Gets the pointer to the beginning of the array.
 Parameters: None
 Return: Pointer to the numbers array.
 */

int *Thing::getNumbersLocation() { return numbers; }
