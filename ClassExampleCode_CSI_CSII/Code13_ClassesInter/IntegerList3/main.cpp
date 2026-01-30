// This program demonstrates the IntegerList class.
#include "IntegerList.h"
#include <iostream>

using namespace std;

int main() {
  const int SIZE = 20;
  IntegerList numbers(SIZE);

  for (int x = 0; x < SIZE; x++)
    numbers.setElement(x, x);

  numbers.displayList();

  IntegerList numbers2 = numbers; // Copy Constructor
  numbers2.displayList();

  numbers.setElement(5, 24);
  numbers.setElement(7, -4);
  numbers.setElement(12, 12345);

  numbers.displayList();
  numbers2.displayList();

  cout << endl;

  IntegerList numbers3(4);
  numbers3.displayList();

  numbers3 = numbers; //  Assignment
  numbers3.displayList();
  numbers.setElement(5, -17);

  numbers3.displayList();
  numbers.displayList();

  cout << endl;

  numbers = numbers2 = numbers3;

  numbers.displayList();
  numbers2.displayList();
  numbers3.displayList();

  cout << endl;

  numbers.setElement(0, 12345);
  numbers2.setElement(1, 12345);
  numbers3.setElement(2, 12345);

  numbers.displayList();
  numbers2.displayList();
  numbers3.displayList();

  return 0;
}
