// Textbook example with some minor alterations.
// Date: 1/23/2022

// This program demonstrates a static member variable.

#include <iostream>

#include "Tree.h"

using namespace std;

void printObjectCount(Tree);

int main() {
  // Define three Tree objects.
  Tree oak;
  Tree elm;
  Tree pine;

  Tree treelist[5];
  Tree *treelist2;

  printObjectCount(pine);

  treelist2 = new Tree[10];

  printObjectCount(treelist[2]);

  delete[] treelist2;

  return 0;
}

void printObjectCount(Tree tr) {
  cout << "We have " << tr.getObjectCount() << " trees in our program!\n";
}
