//============================================================================
// Name        : Triangle.h
// Author      : Don Spickler
// Version     : 3/31/2020
// Description : Header file for the Triangle class.
//============================================================================

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle {
private:
  double a;
  double b;
  double c;

public:
  // Constructors
  Triangle();
  Triangle(double s1, double s2, double s3);

  // Accessors
  double getSideA();
  double getSideB();
  double getSideC();

  // Mutators
  void setSideA(double s);
  void setSideB(double s);
  void setSideC(double s);

  // Calculations
  double Perimeter();
  double Area();
  bool isTriangle();
  bool isRight();
  bool isRight(double tol);
};

#endif /* TRIANGLE_H_ */
