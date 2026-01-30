//============================================================================
// Name        : RationalNumber.cpp
// Author      : Don Spickler
// Version     : 4/4/2020
// Description : Rational number class implementation.
//============================================================================

#include "RationalNumber.h"
#include <string>

/*
 Description: Constructor, sets the number to a/b.
 Parameters:
 a: numerator to fraction
 b: denominator to fraction
 */

RationalNumber::RationalNumber(long a, long b) {
  num = a;
  den = b;
  reduce();
}

/*
 Description: Copy Constructor, sets the number to a/b.
 Parameters:
 obj: right hand side rational number.

 Notes: This is really unneeded since we have nothing dynamically allocated.
 */

RationalNumber::RationalNumber(const RationalNumber &obj) {
  num = obj.num;
  den = obj.den;
  reduce();
}

/*
 Description: Destructor
 Notes: This is really unneeded since we have nothing dynamically allocated.
 */

RationalNumber::~RationalNumber() {}

/*
 Description: Accessor function to return the numerator.
 */

long RationalNumber::getNumerator() { return num; }

/*
 Description: Accessor function to return the denominator.
 */

long RationalNumber::getDenominator() { return den; }

/*
 Description: Mutator function to reset the fraction.
 Parameters:
 a: numerator to fraction
 b: denominator to fraction
 */

void RationalNumber::set(long a, long b) {
  num = a;
  den = b;
  reduce();
}

/*
 Description: Reduces the fraction to lowest terms by finding the GCD
 of the numerator and denominator and dividing both by this GCD.
 The function also makes sure that for negative numbers the numerator
 is negative and the denominator is positive.
 */

void RationalNumber::reduce() {
  if (den < 0) {
    num *= -1;
    den *= -1;
  }

  if (num == 0) {
    den = 1;
  } else {
    long x = abs(num);
    long y = den;

    while (x % y > 0) {
      long temp = y;
      y = x % y;
      x = temp;
    }
    num = num / y;
    den = den / y;
  }
}

/*
 Description: Returns an approximation of the fraction.
 */

double RationalNumber::approx() {
  long n = num;
  long d = den;

  return static_cast<double>(n) / d;
}

/*
 Description: Inverts the fraction. If the fraction is 0 it returns 0.
 */

RationalNumber RationalNumber::invert() {
  if (num == 0)
    return RationalNumber(0, 1);

  long newnum = den;
  long newden = num;
  RationalNumber retval(newnum, newden);
  retval.reduce();

  return retval;
}

/*
 Description: Assignment operator.
 Parameters:
 right: Right hand side fraction.
 Notes: This is really unneeded since we have nothing dynamically allocated.
 */

const RationalNumber RationalNumber::operator=(const RationalNumber &right) {
  num = right.num;
  den = right.den;
  reduce();

  return *this;
}

/*
 Description: Addition operator, returns this + right.
 Parameters:
 right: Right hand side fraction.
 */

RationalNumber RationalNumber::operator+(const RationalNumber &right) {
  long newnum = num * right.den + den * right.num;
  long newden = den * right.den;
  RationalNumber retval(newnum, newden);
  retval.reduce();

  return retval;
}

/*
 Description: Subtraction operator, returns this - right.
 Parameters:
 right: Right hand side fraction.
 */

RationalNumber RationalNumber::operator-(const RationalNumber &right) {
  long newnum = num * right.den - den * right.num;
  long newden = den * right.den;
  RationalNumber retval(newnum, newden);
  retval.reduce();

  return retval;
}

/*
 Description: Multiplication operator, returns this * right.
 Parameters:
 right: Right hand side fraction.
 */

RationalNumber RationalNumber::operator*(const RationalNumber &right) {
  long newnum = num * right.num;
  long newden = den * right.den;
  RationalNumber retval(newnum, newden);
  retval.reduce();

  return retval;
}

/*
 Description: Division operator, returns this / right.  Returns 0 on division by
 0. Parameters: right: Right hand side fraction.
 */

RationalNumber RationalNumber::operator/(const RationalNumber &right) {
  long newnum = num * right.den;
  long newden = den * right.num;

  if (newden == 0)
    return RationalNumber(0, 1);

  RationalNumber retval(newnum, newden);

  return retval;
}

/*
 Description: Power operator, returns this ^ pow.  If the base is 0 the return
 is 0. Parameters: pow: Integer power.
 */

RationalNumber RationalNumber::operator^(int pow) {
  RationalNumber b(num, den);
  RationalNumber zero(0);
  RationalNumber val(1);

  if (b == zero)
    return zero;

  if (pow < 0) {
    pow = -pow;
    b = b.invert();
  }

  for (int i = 0; i < pow; i++) {
    val = val * b;
    val.reduce();
  }
  return val;
}

/*
 Description: Addition operator with a long, returns this + a.
 Parameters:
 a: Right hand side number.
 */

RationalNumber RationalNumber::operator+(long a) {
  RationalNumber rhs(a);
  return *this + rhs;
}

/*
 Description: Subtraction operator with a long, returns this - a.
 Parameters:
 a: Right hand side number.
 */

RationalNumber RationalNumber::operator-(long a) {
  RationalNumber rhs(a);
  return *this - rhs;
}

/*
 Description: Multiplication operator with a long, returns this * a.
 Parameters:
 a: Right hand side number.
 */

RationalNumber RationalNumber::operator*(long a) {
  RationalNumber rhs(a);
  return *this * rhs;
}

/*
 Description: Division operator with a long, returns this * a.
 Returns 0 on division by 0.
 Parameters:
 a: Right hand side number.
 */

RationalNumber RationalNumber::operator/(long a) {
  if (a == 0)
    return RationalNumber(0);

  RationalNumber rhs(a);
  return *this / rhs;
}

/*
 Description: Addition operator with a long, returns a + rhs.
 Parameters:
 a: Left hand side number.
 rhs: Right hand side fraction.
 */

RationalNumber operator+(long a, const RationalNumber &rhs) {
  RationalNumber lhs(a);
  return lhs + rhs;
}

/*
 Description: Subtraction operator with a long, returns a - rhs.
 Parameters:
 a: Left hand side number.
 rhs: Right hand side fraction.
 */

RationalNumber operator-(long a, const RationalNumber &rhs) {
  RationalNumber lhs(a);
  return lhs - rhs;
}

/*
 Description: Multiplication operator with a long, returns a * rhs.
 Parameters:
 a: Left hand side number.
 rhs: Right hand side fraction.
 */

RationalNumber operator*(long a, const RationalNumber &rhs) {
  RationalNumber lhs(a);
  return lhs * rhs;
}

/*
 Description: Division operator with a long, returns a / rhs.
 Returns 0 on division by 0.
 Parameters:
 a: Left hand side number.
 rhs: Right hand side fraction.
 */

RationalNumber operator/(long a, const RationalNumber &rhs) {
  if (rhs.num == 0)
    return RationalNumber(0);

  RationalNumber lhs(a);
  return lhs / rhs;
}

/*
 Description: Addition assignment operator, returns this += rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

void RationalNumber::operator+=(const RationalNumber &rhs) {
  *this = *this + rhs;
}

/*
 Description: Subtraction assignment operator, returns this -= rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

void RationalNumber::operator-=(const RationalNumber &rhs) {
  *this = *this - rhs;
}

/*
 Description: Multiplication assignment operator, returns this *= rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

void RationalNumber::operator*=(const RationalNumber &rhs) {
  *this = *this * rhs;
}

/*
 Description: Division assignment operator, returns this *= rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

void RationalNumber::operator/=(const RationalNumber &rhs) {
  *this = *this / rhs;
}

/*
 Description: Equality operator, returns this == rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator==(const RationalNumber &rhs) {
  return num == rhs.num && den == rhs.den;
}

/*
 Description: Not equal operator, returns this != rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator!=(const RationalNumber &rhs) {
  return !(*this == rhs);
}

/*
 Description: > operator, returns this > rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator>(const RationalNumber &rhs) {
  return (static_cast<double>(num) / den) >
         (static_cast<double>(rhs.num) / rhs.den);
}

/*
 Description: >= operator, returns this >= rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator>=(const RationalNumber &rhs) {
  return (*this > rhs) || (*this == rhs);
}

/*
 Description: < operator, returns this < rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator<(const RationalNumber &rhs) {
  return (static_cast<double>(num) / den) <
         (static_cast<double>(rhs.num) / rhs.den);
}

/*
 Description: <= operator, returns this <= rhs.
 Parameters:
 rhs: Right hand side fraction.
 */

bool RationalNumber::operator<=(const RationalNumber &rhs) {
  return (*this < rhs) || (*this == rhs);
}

/*
 Description: Output stream operator.
 Parameters:
 obj: fraction to be printed.
 strm: output stream reference.
 */

ostream &operator<<(ostream &strm, const RationalNumber &obj) {
  if (obj.den == 1)
    strm << obj.num;
  else
    strm << obj.num << "/" << obj.den;

  return strm;
}

/*
 Description: Input stream operator.
 Parameters:
 obj: fraction to be input.
 strm: input stream reference.
 */

istream &operator>>(istream &strm, RationalNumber &obj) {
  strm >> obj.num;
  strm >> obj.den;
  obj.reduce();

  return strm;
}
