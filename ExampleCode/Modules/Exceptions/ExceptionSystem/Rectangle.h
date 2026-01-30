/*
Author: Don Spickler
Creation Date: 12/17/2022
Last Update: 1/27/2022
Description: Rectangle class structure.
Notes: Taken in part from the Gaddis text.
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  double width;  // The rectangle's width
  double length; // The rectangle's length

public:
  // Default constructor
  Rectangle() {
    width = 0.0;
    length = 0.0;
  }

  // Mutator functions, defined in Rectangle.cpp
  void setWidth(double);
  void setLength(double);

  // Accessor functions
  double getWidth() const { return width; }
  double getLength() const { return length; }
  double getArea() const { return width * length; }
};
#endif
