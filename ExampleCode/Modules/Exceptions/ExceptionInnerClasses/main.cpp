/*
Author: Don Spickler
Creation Date: 12/17/2022
Last Update: 12/17/2022
Description: Exception style using inner classes.
User Interface: User inputs the width and height of a rectangle.
Notes: Taken in part from the Gaddis text.
*/

#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
  // The width and length for a rectangle.
  int width;
  int length;

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
  } catch (Rectangle::NegativeWidth e) {
    cout << "Error: " << e.getValue() << " is an invalid value for the"
         << " rectangle's width.\n";
  } catch (Rectangle::NegativeLength e) {
    cout << "Error: " << e.getValue() << " is an invalid value for the"
         << " rectangle's length.\n";
  }

  cout << "End of the program.\n";
  return 0;
}
