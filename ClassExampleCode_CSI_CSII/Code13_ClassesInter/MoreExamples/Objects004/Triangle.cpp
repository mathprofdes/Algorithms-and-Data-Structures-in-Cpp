//============================================================================
// Name        : Triangle.cpp
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Implementation of the Triangle class.
//============================================================================

#include <cmath>
#include <iostream>

#include "Triangle.h"

using namespace std;

Triangle::Triangle() {
  a = 0;
  b = 0;
  c = 0;

  cout << "Default Constructor" << endl;
}

Triangle::Triangle(double s1, double s2, double s3) {
  if (s1 < 0)
    s1 = 0;
  if (s2 < 0)
    s2 = 0;
  if (s3 < 0)
    s3 = 0;

  a = s1;
  b = s2;
  c = s3;

  cout << "Non-Default Constructor" << endl;
}

double Triangle::getSideA() { return a; }
double Triangle::getSideB() { return b; }
double Triangle::getSideC() { return c; }

void Triangle::setSideA(double s) {
  if (s < 0)
    s = 0;

  a = s;
}

void Triangle::setSideB(double s) {
  if (s < 0)
    s = 0;

  b = s;
}

void Triangle::setSideC(double s) {
  if (s < 0)
    s = 0;

  c = s;
}

double Triangle::Perimeter() { return a + b + c; }

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
