/*
Author: Don Spickler
Creation Date: 12/17/2022
Last Update: 12/17/2022
Description: Simple example of exceptions using native data types.
User Interface: Input two integers for a quotient.
Notes: Taken from Gaddis text.
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototypes
double divide(int, int);

int main() {
  int num1, num2;  // To hold two numbers
  double quotient; // To hold the quotient of the numbers

  // Get two numbers.
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  // Divide num1 by num2 and catch any
  // potential exceptions.
  try {
    quotient = divide(num1, num2);
    cout << "The quotient is " << quotient << endl;
  } catch (string exceptionString) {
    cout << exceptionString;
  }

  cout << "End of the program.\n";
  return 0;
}

/*
Description: The divide function divides numerator by denominator. If
denominator is zero, the function throws an exception.
Parameters: integers numerator and denominator.
Return: Quotient of numerator and denominator.
Notes: Exception is of string type.
*/

double divide(int numerator, int denominator) {
  if (denominator == 0) {
    string exceptionString = "ERROR: Cannot divide by zero.\n";
    throw exceptionString;
  }

  return static_cast<double>(numerator) / denominator;
}
