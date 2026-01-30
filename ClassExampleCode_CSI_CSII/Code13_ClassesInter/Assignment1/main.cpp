/*
 Author: Don Spickler
 Creation Date: 1/23/2022
 Last Update: 1/23/2022
 Description: Example program for memberwise assignment of class fields.
 User Interface: None
 */

#include "Thing.h"
#include <iostream>

using namespace std;

void printThing(Thing);
void div();

int main() {
  Thing thing1("Jack", 21);
  Thing thing2("Jill", 20);

  printThing(thing1);
  printThing(thing2);
  div();

  thing1 = thing2;

  printThing(thing1);
  printThing(thing2);
  div();

  thing1.setName("Cinderella");
  thing1.setAge(19);

  printThing(thing1);
  printThing(thing2);

  return 0;
}

/*
 Description: Prints out the name and age of a Thing
 Parameters: t - Thing object
 Return: None
 */

void printThing(Thing t) { cout << t.getName() << " : " << t.getAge() << endl; }

/*
 Description: Prints out a line for a separator.
 Parameters: None
 Return: None
 */

void div() { cout << "\n-----------------------------------\n\n"; }
