// Implementation file for the Vector class
#include "Vector.h"

Vector::Vector(int d) {
  dim = d;
  vec = new double[dim];
  for (int i = 0; i < dim; i++)
    vec[i] = 0;
}

Vector::~Vector() { delete[] vec; }

Vector::Vector(const Vector &obj) {
  dim = obj.dim;
  vec = new double[dim];
  for (int i = 0; i < dim; i++)
    vec[i] = obj.vec[i];
}

void Vector::setComponent(int pos, double val) {
  if (pos < 0 || pos >= dim)
    return;

  vec[pos] = val;
}

double Vector::getComponent(int pos) {
  if (pos < 0 || pos >= dim)
    return 0;

  return vec[pos];
}

const Vector Vector::operator=(const Vector &right) {
  delete[] vec;
  dim = right.dim;
  vec = new double[dim];
  for (int i = 0; i < dim; i++)
    vec[i] = right.vec[i];

  return *this;
}

double &Vector::operator[](const int &pos) {
  if (pos < 0)
    return vec[0];

  if (pos >= dim)
    return vec[dim - 1];

  return vec[pos];
}

Vector Vector::operator+(const Vector &right) {
  if (dim != right.dim) {
    cout << "Vectors must be the same size to add." << endl;
    Vector zero3;
    return zero3;
  }

  Vector temp(dim);

  for (int i = 0; i < dim; i++)
    temp.vec[i] = vec[i] + right.vec[i];

  return temp;
}

Vector Vector::operator-(const Vector &right) {
  if (dim != right.dim) {
    cout << "Vectors must be the same size to subtract." << endl;
    Vector zero3;
    return zero3;
  }

  Vector temp(dim);

  for (int i = 0; i < dim; i++)
    temp.vec[i] = vec[i] - right.vec[i];

  return temp;
}

void Vector::operator+=(const Vector &right) {
  if (dim != right.dim) {
    cout << "Vectors must be the same size to subtract." << endl;
    return;
  }

  for (int i = 0; i < dim; i++)
    vec[i] = vec[i] + right.vec[i];
}

void Vector::operator-=(const Vector &right) {
  if (dim != right.dim) {
    cout << "Vectors must be the same size to subtract." << endl;
    return;
  }

  for (int i = 0; i < dim; i++)
    vec[i] = vec[i] - right.vec[i];
}

Vector Vector::operator*(double d) {
  Vector temp(dim);

  for (int i = 0; i < dim; i++)
    temp.vec[i] = d * vec[i];

  return temp;
}

double Vector::operator*(const Vector &obj) {
  double dotprod = 0;

  if (dim != obj.dim)
    return 0;

  for (int i = 0; i < dim; i++)
    dotprod += vec[i] * obj.vec[i];

  return dotprod;
}

Vector operator*(double d, const Vector &obj) {
  Vector temp(obj.dim);

  for (int i = 0; i < obj.dim; i++)
    temp.vec[i] = d * obj.vec[i];

  return temp;
}

bool Vector::operator>(Vector &right) { return mod() > right.mod(); }

bool Vector::operator<(Vector &right) { return mod() < right.mod(); }

bool Vector::operator==(const Vector &right) {
  if (dim != right.dim)
    return false;

  for (int i = 0; i < dim; i++)
    if (vec[i] != right.vec[i])
      return false;

  return true;
}

double Vector::mod() {
  double sumsq = 0;
  for (int i = 0; i < dim; i++)
    sumsq += vec[i] * vec[i];

  return sqrt(sumsq);
}

ostream &operator<<(ostream &strm, const Vector &obj) {
  strm << "<";
  for (int i = 0; i < obj.dim - 1; i++)
    strm << obj.vec[i] << ", ";
  strm << obj.vec[obj.dim - 1] << ">";

  return strm;
}

istream &operator>>(istream &strm, Vector &obj) {
  for (int i = 0; i < obj.dim; i++)
    strm >> obj.vec[i];

  return strm;
}
