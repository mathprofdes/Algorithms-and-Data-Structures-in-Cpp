/*
Author: Don Spickler
Creation Date: 1/28/2022
Last Update: 2/3/2024
Description: Quick example of some functions in the algorithm library and
iterators for arrays and vectors.
User Interface: None
Notes: None
*/

#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void div(string s = "") {
  cout << "\n--------------------------- " << s << "\n\n";
}

template <class T> void PrintVector(vector<T> M) {
  for (T a : M) {
    cout << a << " ";
  }
  cout << endl;
}

template <class T, int n> void PrintArray(array<T, n> M) {
  for (T a : M) {
    cout << a << " ";
  }
  cout << endl;
}

void pt(int i) { cout << i << " "; }
void sqr(int &i) { i = i * i; }
template <class T> void pt2(T item) { cout << item << " "; }

int main() {
  srand(time(0));

  div("Arrays and array iterators.");
  const int sz = 10;
  array<int, sz> Arr;
  array<int, sz>::iterator Ait;

  for (int i = 0; i < sz; i++)
    Arr[i] = rand() % 10;

  PrintArray<int, sz>(Arr);
  for_each(Arr.begin(), Arr.end(), pt);
  cout << endl;

  Ait = find(Arr.begin(), Arr.end(), 7);
  if (Ait != Arr.end()) {
    cout << "7 was found at position " << (Ait - Arr.begin()) << endl;
  } else {
    cout << "7 was not found." << endl;
  }

  div("Vectors and vector iterators.");
  vector<int> V;
  vector<int>::iterator it;

  for (int i = 0; i < 10; i++)
    V.push_back(rand() % 100);

  PrintVector(V);
  int t = V[4];

  it = find(V.begin(), V.end(), -3);
  if (it != V.end()) {
    cout << "-3 was found at position " << (it - V.begin()) << endl;
  } else {
    cout << "-3 was not found." << endl;
  }

  it = find(V.begin(), V.end(), t);
  if (it != V.end()) {
    cout << t << " was found at position " << (it - V.begin()) << endl;
  } else {
    cout << t << " was not found." << endl;
  }

  if (binary_search(V.begin(), V.end(), -3))
    cout << "-3 was found." << endl;
  else
    cout << "-3 was not found." << endl;

  if (binary_search(V.begin(), V.end(), t))
    cout << t << " was found." << endl;
  else
    cout << t << " was not found." << endl;

  div("Sorting");

  sort(V.begin(), V.end());

  PrintVector(V);
  if (binary_search(V.begin(), V.end(), -3))
    cout << "-3 was found." << endl;
  else
    cout << "-3 was not found." << endl;

  if (binary_search(V.begin(), V.end(), t))
    cout << t << " was found." << endl;
  else
    cout << t << " was not found." << endl;

  div("Counts");

  V.clear();

  for (int i = 0; i < 1000000; i++)
    V.push_back((rand() % 6 + 1) + (rand() % 6 + 1));

  for (int i = 2; i <= 12; i++) {
    int num = count(V.begin(), V.end(), i);
    cout << "The number of " << i << " rolls was " << num << endl;
  }

  div("Maximum and Minimum");

  V.clear();

  for (int i = 0; i < 1000000; i++)
    V.push_back(rand());

  it = max_element(V.begin(), V.end());
  cout << "Maximum = " << (*it) << endl;
  it = min_element(V.begin(), V.end());
  cout << "Minimum = " << (*it) << endl;

  div("For each on vectors and function pointers.");

  V.clear();

  for (int i = 0; i < 10; i++)
    V.push_back(rand() % 100 + 1);

  PrintVector(V);

  for_each(V.begin(), V.end(), pt);
  cout << endl;
  for_each(V.begin() + 3, V.end() - 1, pt);
  cout << endl;
  for_each(V.begin() + 3, V.end() - 1, pt2<int>);
  cout << endl;

  for_each(V.begin(), V.end(), pt);
  cout << endl;
  for_each(V.begin(), V.end(), sqr);
  for_each(V.begin(), V.end(), pt);
  cout << endl;

  div("For each and copy on arrays and function pointers.");

  double A[10];
  double B[10] = {0};

  for (int i = 0; i < 10; i++)
    A[i] = 3.14159 * i;

  for_each(A, A + 10, pt2<double>);
  cout << endl;
  for_each(B, B + 10, pt2<double>);
  cout << endl;
  cout << endl;

  copy(A, A + 10, B);
  for_each(A, A + 10, pt2<double>);
  cout << endl;
  for_each(B, B + 10, pt2<double>);
  cout << endl;
  cout << endl;

  for (int i = 0; i < 10; i++)
    A[i] = 2.718281828459045 * i;

  for_each(A, A + 10, pt2<double>);
  cout << endl;
  for_each(B, B + 10, pt2<double>);
  cout << endl;

  div("Copy backwards and fill.");

  copy_backward(A, A + 10, B);
  for_each(A, A + 10, pt2<double>);
  cout << endl;
  for_each(B, B + 10, pt2<double>);
  cout << endl;
  cout << endl;

  fill(B, B + 10, 0);
  for_each(A, A + 10, pt2<double>);
  cout << endl;
  for_each(B, B + 10, pt2<double>);
  cout << endl;
  cout << endl;

  div("Reverse");

  for_each(A, A + 10, pt2<double>);
  cout << endl;
  reverse(A, A + 10);
  for_each(A, A + 10, pt2<double>);
  cout << endl;
  reverse(A, A + 10);
  for_each(A, A + 10, pt2<double>);
  cout << endl;

  return 0;
}
