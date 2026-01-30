//============================================================================
// Author      : Don Spickler
// Version     : 4/4/2020
// Description : Objects Example: Operator Overloading
//============================================================================

#include "RationalNumber.h"
#include <iostream>

using namespace std;

int main() {
  RationalNumber a(60, -84);
  RationalNumber b, c, d, e;

  cout << b << endl;
  b.set(1, 2);
  cout << b << endl;

  cout << a << endl;
  cout << a.approx() << endl;
  cout << b.approx() << endl;

  b.set(3, 2);
  cout << 2 * b << endl;
  cout << 4 / b * 3 << endl;
  cout << (b ^ 2) << endl;
  cout << (b ^ 3) << endl;
  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a / b << endl;

  if (a > b)
    cout << "a > b" << endl;

  if (a >= b)
    cout << "a >= b" << endl;

  if (a < b)
    cout << "a < b" << endl;

  if (a <= b)
    cout << "a <= b" << endl;

  if (a == b)
    cout << "a == b" << endl;

  if (a != b)
    cout << "a != b" << endl;

  if (a == a)
    cout << "a == a" << endl;

  cout << "Input a fraction a/b as a b: ";
  cin >> c;
  cout << "Input a fraction a/b as a b: ";
  cin >> d;

  cout << c << "  " << d << endl;
  cout << c + d << endl;
  cout << c - d << endl;
  cout << c * d << endl;
  cout << c / d << endl;

  return 0;
}
