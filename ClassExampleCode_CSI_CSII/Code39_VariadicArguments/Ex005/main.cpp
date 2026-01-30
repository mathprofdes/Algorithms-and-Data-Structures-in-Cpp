#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>

#include "Die.h"

using namespace std;

// Base case to the recursion on the add function.
template <class T> double AddNumbers(T t) { return t; }

// Recursive variadic function to add. Note that the types must be numeric.
template <class T, class... U> double AddNumbers(T t, U... args) {
  return t + AddNumbers(args...);
}

// Find the data type from a small set of base types.
template <class T> string getTypeString(T t) {
  if (typeid(t) == typeid(int))
    return "Integer.";
  else if (typeid(t) == typeid(double))
    return "Double.";
  else if (typeid(t) == typeid(char))
    return "Character.";
  else if (typeid(t) == typeid(string))
    return "String.";

  return "Other";
}

// Base case to the recursion on the print function.
template <class T> void print(T t) {
  cout << typeid(t).name() << "  " << t << " - " << getTypeString(t) << endl;
}

// Recursive variadic function. Note that the T does the "casting"
template <class T, class... U> void print(T t, U... args) {
  cout << typeid(t).name() << "  " << t << " - " << getTypeString(t) << endl;
  print(args...);
}

int main() {
  srand(time(0));

  string str = "COSC 220";
  Die D(20);
  print(7, "Gotta love C++", 3.14159, 'a', str, D);

  cout << AddNumbers(4, 6, 7.2, 5, 27, 5 / 4.0, sqrt(2)) << endl;
  cout << AddNumbers(3.14159, 2.718271828, 1.618033988749895) << endl;

  if (typeid(str) == typeid(int))
    cout << "Integer" << endl;
  else
    cout << "Not an integer" << endl;

  if (typeid(str) == typeid(Die))
    cout << "Die" << endl;
  else
    cout << "Not a Die" << endl;

  if (typeid(D) == typeid(Die))
    cout << "Die" << endl;
  else
    cout << "Not a Die" << endl;
}
