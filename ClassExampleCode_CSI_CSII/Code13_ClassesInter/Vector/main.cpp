// This program demonstrates the the Vector class's functions.

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Vector.h"

using namespace std;

void sort(Vector *arr, int size);

int main() {
  Vector v;
  v[0] = -3;
  v[1] = 2;
  v[2] = 5;

  cout << v << endl;
  cout << v.mod() << endl;
  cout << endl;

  Vector w = v;
  cout << w << endl;
  w[2] = 10;
  cout << v << endl;
  cout << w << endl;
  cout << endl;

  Vector z;
  z = v + w;
  cout << z << endl;
  z = v - w;
  cout << z << endl;

  if (v > w)
    cout << "v has a larger modulus than w." << endl;
  else
    cout << "v has a smaller or equal modulus than w." << endl;

  if (v == w)
    cout << "v and w are identical." << endl;
  else
    cout << "v and w are different." << endl;

  v = w;

  if (v == w)
    cout << "v and w are identical." << endl;
  else
    cout << "v and w are different." << endl;

  v.setComponent(0, 25.3);
  cout << v.getComponent(0) << endl;
  cout << endl;

  cout << v << endl;
  cout << 5 * v << endl;
  cout << v * 3 << endl;
  cout << v << endl;

  w[1] = 5.3;
  w[2] = -11.234;
  z = -4 * v + 7 * w;
  cout << z << endl;

  cout << endl;

  Vector *vecs = new Vector[20];
  srand(time(0));

  for (int i = 0; i < 20; i++) {
    vecs[i][0] = 10.0 * rand() / RAND_MAX - 5;
    vecs[i][1] = 10.0 * rand() / RAND_MAX - 5;
    vecs[i][2] = 10.0 * rand() / RAND_MAX - 5;
  }

  for (int i = 0; i < 20; i++)
    cout << vecs[i] << "\t---\t" << vecs[i].mod() << endl;

  sort(vecs, 20);
  cout << endl;

  for (int i = 0; i < 20; i++)
    cout << vecs[i] << "\t---\t" << vecs[i].mod() << endl;

  cout << endl;

  for (int i = 0; i < 20; i++) {
    int dim = rand() % 10 + 1;
    Vector a(dim);
    for (int j = 0; j < dim; j++)
      a[j] = 10.0 * rand() / RAND_MAX - 5;
    vecs[i] = a;
  }

  for (int i = 0; i < 20; i++)
    cout << vecs[i] << endl;

  delete[] vecs;

  return 0;
}

/*
 Description: Sorts the input array into ascending order, using the bubble sort
 algorithm. Parameters: arr - the pointer to the array. size - the size of the
 array Note: Original array is changed to sorted order.
 */

void sort(Vector *arr, int size) {
  for (int i = size - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++) {
      if (arr[j] > arr[j + 1]) {
        Vector temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
}
