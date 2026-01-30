//============================================================================
// Name        : FeetInches.cpp
// Version     : 4/4/2020
// Description : Specification file for the FeetInches class
//============================================================================

#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches {
private:
  int feet;
  int inches;
  void simplify();

public:
  // Constructor
  FeetInches(int f = 0, int i = 0) {
    feet = f;
    inches = i;
    simplify();
  }

  // Mutator functions
  void setFeet(int f) { feet = f; }

  void setInches(int i) {
    inches = i;
    simplify();
  }

  // Accessor functions
  int getFeet() const { return feet; }

  int getInches() const { return inches; }

  // Overloaded operator functions
  FeetInches operator+(const FeetInches &);
  FeetInches operator-(const FeetInches &);
  FeetInches operator++();
  FeetInches operator++(int);
  bool operator>(const FeetInches &);
  bool operator<(const FeetInches &);
  bool operator==(const FeetInches &);

  // Conversion functions
  operator double();
  operator int();

  // Friends
  friend ostream &operator<<(ostream &, const FeetInches &);
  friend istream &operator>>(istream &, FeetInches &);
};

#endif
