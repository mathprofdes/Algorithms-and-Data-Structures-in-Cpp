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

void alterThing(Thing);
void printThing(Thing &);
void div();

int main() {
  Thing thing1("Jack", 21);
  Thing thing2("Jill", 20);

  for (int i = 0; i < 5; i++)
    thing1.setNumber(i, i);

  for (int i = 0; i < 5; i++)
    thing2.setNumber(i, 10 - i);

  printThing(thing1);
  printThing(thing2);
  div();

  thing1 = thing2;

  printThing(thing1);
  printThing(thing2);
  div();

  thing1.setName("Cinderella");
  thing1.setAge(19);
  for (int i = 0; i < 5; i++)
    thing1.setNumber(i, 2 * i);

  printThing(thing1);
  printThing(thing2);
  div();

  alterThing(thing1);
  printThing(thing1);
  printThing(thing2);

  return 0;
}

/*
 Description: Change position 2 to 12345
 Parameters: t - Thing object
 Return: None
 */

void alterThing(Thing t) { t.setNumber(2, 12345); }

/*
 Description: Prints out the name and age of a Thing
 Parameters: t - Thing object
 Return: None
 */

void printThing(Thing &t) {
  cout << t.getName() << " : " << t.getAge() << " : ";
  for (int i = 0; i < 5; i++)
    cout << t.getNumber(i) << " ";
  cout << " : " << t.getNumbersLocation() << endl;
}

/*
 Description: Prints out a line for a separator.
 Parameters: None
 Return: None
 */

void div() { cout << "\n-----------------------------------\n\n"; }
