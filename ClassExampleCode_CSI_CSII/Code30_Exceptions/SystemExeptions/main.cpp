/*

Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022

This example is just a few short examples of using C++ system exceptions. It
also shows some cases where the system exceptions are not thrown.

The example shows how to throw and catch exceptions that are built into C++.
Note that not all errors can be caught (like in Java).  In particular, streaming
errors are not part of the exception handling system.
 */

#include <cmath>
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

// Simple function that will throw a domain_error if division by 0 is attempted.
template <class T> T divide(T a, T b) {
  if (b == 0)
    throw domain_error("Division by 0");

  return a / b;
}

// Function to get an integer value from the user.  To use the exception
// structure in C++ we get the input as a general string and then use stod and
// stol to do the conversion to numeric values.  These functions will throw
// exceptions if the input is incorrect and hence we can use this to determine
// not only that we had an error but also what type of error we have.

long InputInteger() {
  string strt;
  long t;
  bool valid = false;

  while (!valid) {
    cout << "Input an integer: ";
    getline(cin, strt);

    try {
      double dt = stod(strt);
      t = stol(strt);
      if (dt != t)
        throw domain_error("");

      valid = true;
    } catch (const invalid_argument &e) {
      cerr << "Input was not a numeric type." << endl;
    } catch (const domain_error &e) {
      cerr << "Input was not an integer." << endl;
    } catch (const out_of_range &e) {
      cerr << "Input was too large." << endl;
    } catch (const exception &e) {
      cerr << "There was an unknown error in the input." << endl;
    }
  }

  return t;
}

int main() {

  try {
    cout << divide(7.0, 2.0) << endl;
  } catch (const domain_error &e) {
    cout << e.what() << endl;
  }

  try {
    cout << divide(7.0, 0.0) << endl;
  } catch (const domain_error &e) {
    cout << e.what() << endl;
  }

  try {
    cout << divide(7, 0) << endl;
  } catch (const domain_error &e) {
    cout << e.what() << endl;
  }

  long val = InputInteger();
  cout << val << endl;

  // Does not work, unfortunately.
  try {
    // auto a = 1/0;
  } catch (const exception &e) {
    cerr << "Division by 0." << endl;
  }

  // Does not work either. The sqrt function does not throw an exception if
  // the input creates an "domain" error, it just returns nan.
  try {
    double s = sqrt(-1);
    cout << s << endl;
  } catch (const exception &e) {
    cerr << "Square root of a negative number." << e.what() << endl;
  }

  return 0;
}
