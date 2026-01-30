/*
Author: Don Spickler
Creation Date: 12/17/2022
Last Update: 1/27/2022
*/

#include "Rectangle.h"
#include "NegativeNumberException.h"

/*
Description: Sets the width field of the rectangle if it is not negative, throws
an exception if it is.
Parameters: double w for width.
Return: none
Notes: throws an exception of NegativeNumberException type.
*/

void Rectangle::setWidth(double w) {
  if (w >= 0)
    width = w;
  else {
    char badval[100];
    sprintf(badval, "Invalid Value: %f", w);
    throw NegativeNumberException(badval);
  }
}

/*
Description: Sets the length field of the rectangle if it is not negative,
throws an exception if it is.
Parameters: double len for length.
Return: none
Notes: throws an exception of NegativeNumberException type.
*/

void Rectangle::setLength(double len) {
  if (len >= 0)
    length = len;
  else {
    char badval[100];
    sprintf(badval, "Invalid Value: %f", len);
    throw NegativeNumberException(badval);
  }
}
