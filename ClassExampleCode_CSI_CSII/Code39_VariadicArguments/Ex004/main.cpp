#include <cstdarg>
#include <initializer_list>
#include <iostream>

using namespace std;

template <class T> void print2(initializer_list<T> list) {
  for (auto elem : list) {
    cout << elem << endl;
  }
}

template <class T> T addUp(initializer_list<T> list) {
  cout << "Number in list = " << list.size() << endl;
  T sum = 0;
  for (auto val : list) {
    sum += val;
  }
  return sum;
}

int main() {
  print2({1, 2, 3, 5, 10});
  cout << addUp({3, 6, 5, 8, 7, 2}) << endl;

  return 0;
}
