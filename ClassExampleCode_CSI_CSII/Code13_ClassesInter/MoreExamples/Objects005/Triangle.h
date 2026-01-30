//============================================================================
// Name        : Triangle.h
// Author      : Don Spickler
// Version     : 4/1/2020
// Description : Header file for the Triangle class.
//============================================================================

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle {
private:
  double a;
  double b;
  double c;

  double maxnum(double x, double y) { return (x > y) ? x : y; }

public:
  // Constructors
  Triangle() { a = b = c = 0; }
  Triangle(double s1, double s2, double s3);

  // Accessors
  double getSideA() { return a; }
  double getSideB() { return b; }
  double getSideC() { return c; }

  // Mutators
  void setSideA(double s) { a = maxnum(0, s); }
  void setSideB(double s) { b = maxnum(0, s); }
  void setSideC(double s) { c = maxnum(0, s); }

  // Calculations
  double Perimeter() { return a + b + c; }
  double Area();
  bool isTriangle();
  bool isRight();
  bool isRight(double tol);
};

#endif /* TRIANGLE_H_ */
