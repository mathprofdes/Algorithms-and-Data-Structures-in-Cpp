// Specification file for the Vector class
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

using namespace std;

class Vector {
private:
  double *vec;
  int dim;

public:
  // Constructors and Destructor
  Vector(int d = 3);
  ~Vector();
  Vector(const Vector &obj);

  // Acessors and Mutators
  void setComponent(int, double);
  double getComponent(int);

  // Overloaded operator functions
  Vector operator+(const Vector &);
  Vector operator-(const Vector &);
  void operator+=(const Vector &);
  void operator-=(const Vector &);
  double operator*(const Vector &); // Dot product
  Vector operator*(double);
  friend Vector operator*(double, const Vector &);
  bool operator>(Vector &); //  Compare modulus
  bool operator<(Vector &); //  Compare modulus
  bool operator==(const Vector &);
  const Vector operator=(const Vector &right);
  double &operator[](const int &);

  // Functions
  double mod();

  // Friend functions for streaming.
  friend ostream &operator<<(ostream &, const Vector &);
  friend istream &operator>>(istream &, Vector &);
};

#endif
