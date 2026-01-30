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

  IntegerList numbers2 = numbers;
  numbers2.displayList();

  numbers.setElement(5, 24);
  numbers.setElement(7, -4);
  numbers.setElement(12, 12345);

  numbers.displayList();
  numbers2.displayList();

  IntegerList numbers3(4);
  numbers3.displayList();

  numbers3 = numbers;
  numbers3.displayList();
  numbers.setElement(5, -17);

  numbers3.displayList();
  numbers.displayList();

  return 0;
}
