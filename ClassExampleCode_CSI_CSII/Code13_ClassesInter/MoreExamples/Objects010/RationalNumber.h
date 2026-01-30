//============================================================================
// Name        : RationalNumber.h
// Author      : Don Spickler
// Version     : 4/4/2020
// Description : Rational number class declaration.
//============================================================================

#ifndef RATIONALNUNBER_H_
#define RATIONALNUNBER_H_

#include <iostream>
using namespace std;

class RationalNumber {
private:
  long num;
  long den;

public:
  RationalNumber(long a = 0, long b = 1);
  RationalNumber(const RationalNumber &);
  ~RationalNumber();

  long getNumerator();
  long getDenominator();

  void set(long, long);

  void reduce();
  double approx();

  RationalNumber invert();

  const RationalNumber operator=(const RationalNumber &);
  RationalNumber operator+(const RationalNumber &);
  RationalNumber operator-(const RationalNumber &);
  RationalNumber operator*(const RationalNumber &);
  RationalNumber operator/(const RationalNumber &);
  RationalNumber operator^(int);

  RationalNumber operator+(long);
  RationalNumber operator-(long);
  RationalNumber operator*(long);
  RationalNumber operator/(long);

  friend RationalNumber operator+(long, const RationalNumber &);
  friend RationalNumber operator-(long, const RationalNumber &);
  friend RationalNumber operator*(long, const RationalNumber &);
  friend RationalNumber operator/(long, const RationalNumber &);

  void operator+=(const RationalNumber &);
  void operator-=(const RationalNumber &);
  void operator*=(const RationalNumber &);
  void operator/=(const RationalNumber &);

  bool operator==(const RationalNumber &);
  bool operator!=(const RationalNumber &);
  bool operator>(const RationalNumber &);
  bool operator>=(const RationalNumber &);
  bool operator<(const RationalNumber &);
  bool operator<=(const RationalNumber &);

  friend ostream &operator<<(ostream &, const RationalNumber &);
  friend istream &operator>>(istream &, RationalNumber &);
};

#endif /* RATIONALNUNBER_H_ */
