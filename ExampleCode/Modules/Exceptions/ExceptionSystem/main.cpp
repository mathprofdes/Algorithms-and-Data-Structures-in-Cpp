/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Driver example for inheritance exception structure.
User Interface: Inputs of rectangle width and height as well as numerator and
denominator for quotient.
Notes: Taken in part from the Gaddis text.
*/

#include <iostream>

#include "Exceptions.h"
#include "Rectangle.h"

using namespace std;

// Function prototypes
double divide(int, int);

int main() {
  // Width and height of a rectangle.
  int width;
  int length;
  int num1, num2;  // To hold two numbers
  double quotient; // To hold the quotient of the numbers

  // Create a Rectangle object.
  Rectangle myRectangle;

  // Get the width and length.
  cout << "Enter the rectangle's width: ";
  cin >> width;
  cout << "Enter the rectangle's length: ";
  cin >> length;

  // Store these values in the Rectangle object.
  try {
    myRectangle.setWidth(width);
    myRectangle.setLength(length);
    cout << "The area of the rectangle is " << myRectangle.getArea() << endl;
  } catch (NegativeNumberException &e) {
    cout << "Error: " << e.message() << endl;
  }

  // Get two numbers.
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  // Divide num1 by num2 and catch any
  // potential exceptions.
  try {
    quotient = divide(num1, num2);
    cout << "The quotient is " << quotient << endl;
  } catch (DivisionByZeroException &e) {
    cout << "Error: " << e.message() << endl;
  }

  cout << "End of the program.\n";
  return 0;
}

/*
Description: Divides inputs and returns the quotient, if division by zero will
throw a DivisionByZeroException exception.
Parameters: Integers numerator and denominator.
Return: double quotient of the numerator and denominator.
Notes: throws DivisionByZeroException
*/
double divide(int numerator, int denominator) {
  if (denominator == 0)
    throw DivisionByZeroException("ERROR: Cannot divide by zero.");

  return static_cast<double>(numerator) / denominator;
}
