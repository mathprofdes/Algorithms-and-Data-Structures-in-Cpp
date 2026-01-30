/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Since the vector at function throws exceptions for out_of_range
errors we are overriding the [] function to call at and hence incorporate range
checking with the indexing operator [].  Another example of throwing an
exception directly from the function and one that cascades to [] which uses the
at function for the exception.
User Interface: None
Notes: None
*/

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class MyVector : public vector<T> {
public:
  T &operator[](const T &pos) { return this->at(pos); }

  void set(unsigned long pos, T item) {
    if (pos < 0 || pos > this->size()) {
      string message = "vector::_M_range_check: __n (which is ";
      message += to_string(pos);
      message += ") >= this->size() (which is ";
      message += to_string(this->size());
      message += ")";
      throw out_of_range(message);
    }
    (*this)[pos] = item;
  }

  void setItem(unsigned long pos, T item) { (*this)[pos] = item; }
};

int main() {
  vector<int> V;
  for (int i = 1; i <= 5; i++)
    V.push_back(i);

  cout << V.at(3) << endl;
  cout << V[15] << endl;

  try {
    cout << V.at(5) << endl;
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  MyVector<int> M;
  for (int i = 1; i <= 10; i++)
    M.push_back(i);

  cout << M.at(5) << endl;

  try {
    cout << M.at(15) << endl;
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    cout << M[15] << endl;
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    cout << M[-5] << endl;
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  M.set(5, 12345);
  cout << M[5] << endl;

  try {
    M.set(12, 55);
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    M.setItem(12, 55);
  } catch (const out_of_range &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  return 0;
}
