#include <cstdarg>
#include <iostream>

using namespace std;

double average(int num...) {
  va_list valist;
  double sum = 0.0;
  int i;

  // initialize valist for num number of arguments
  va_start(valist, num);

  // access all the arguments assigned to valist, num is first, this gets the
  // rest.  Note the cast to int as the second parameter.
  for (i = 0; i < num; i++) {
    sum += va_arg(valist, int);
  }

  /* clean memory reserved for valist */
  va_end(valist);

  return sum / num;
}

int main() {
  // Note that for this example the first number is the number of arguments.
  cout << "Average of 2, 3, 4, 5 = " << average(4, 2, 3, 4, 5) << endl;
  cout << "Average of 5, 10, 15 = " << average(3, 5, 10, 15) << endl;
}
