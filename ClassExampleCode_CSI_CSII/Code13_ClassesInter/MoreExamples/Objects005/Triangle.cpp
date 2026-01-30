//============================================================================
// Name        : Triangle.cpp
// Author      : Don Spickler
// Version     : 4/1/2020
// Description : Implementation of the Triangle class.
//============================================================================

#include <cmath>

#include "Triangle.h"

Triangle::Triangle(double s1, double s2, double s3) {
  a = maxnum(0, s1);
  b = maxnum(0, s2);
  c = maxnum(0, s3);
}

double Triangle::Area() {
  double p = Perimeter() / 2;
  double area = sqrt(p * (p - a) * (p - b) * (p - c));
  return area;
}

bool Triangle::isTriangle() {
  double longest = a;
  if (b > longest)
    longest = b;
  if (c > longest)
    longest = c;

  double sumshort = a + b + c - longest;
  return sumshort >= longest;
}

bool Triangle::isRight() {
  if (a * a + b * b == c * c)
    return true;
  if (a * a + c * c == b * b)
    return true;
  if (b * b + c * c == a * a)
    return true;

  return false;
}

bool Triangle::isRight(double tol) {
  if (a * a + b * b - c * c < tol)
    return true;
  if (a * a + c * c - b * b < tol)
    return true;
  if (b * b + c * c - a * a < tol)
    return true;

  return false;
}
