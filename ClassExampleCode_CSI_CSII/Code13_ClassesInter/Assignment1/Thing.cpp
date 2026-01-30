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
}

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
