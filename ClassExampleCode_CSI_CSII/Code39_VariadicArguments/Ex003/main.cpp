#include <cstdarg>
#include <iostream>

using namespace std;

template <class T> void printArgs(int count, T items...) {
  cout << __PRETTY_FUNCTION__ << ": " << items << endl;

  va_list valist;
  va_start(valist, items);

  T val = items; // first value.
  cout << val << " ";
  for (int i = 0; i < count - 1; i++) {
    T val = va_arg(valist, T);
    cout << val << " ";
  }
  cout << endl;

  va_end(valist);
}

int main() {
  printArgs(5, 2, 7, 6, 4, 9);
  printArgs(5, "This", "is", "a", "test", "...");

  return 0;
}
