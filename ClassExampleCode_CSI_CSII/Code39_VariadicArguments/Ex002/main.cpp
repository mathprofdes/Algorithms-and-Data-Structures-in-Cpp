#include <cstdarg>
#include <iostream>

using namespace std;

template <class T> double average(T num...) {
  va_list valist;
  double sum = 0.0;
  int i;

  cout << valist << endl;
  cout << num << ": ";

  va_start(valist, num);

  for (i = 0; i < num; i++) {
    T item = va_arg(valist, T);
    cout << item << " ";
    sum += item;
  }
  cout << endl;

  va_end(valist);

  return sum / num;
}

int main() {
  double ans = average(4, 2, 3, 4, 5);
  cout << "Average of 2, 3, 4, 5 = " << ans << endl;

  ans = average(3, 5, 10, 15);
  cout << "Average of 5, 10, 15 = " << ans << endl;

  ans = average(3.0, 12.4, 15.9, 7.1);
  cout << "Average of 12.4, 15.9, 7.1 = " << ans << endl;

  cout << "Note problem here:" << endl;
  ans = average(3, 12.4, 15.9, 7.1);
  cout << "Average of 12.4, 15.9, 7.1 = " << ans << endl;
  return 0;
}
