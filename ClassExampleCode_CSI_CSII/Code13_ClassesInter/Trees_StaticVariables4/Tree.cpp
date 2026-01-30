// Textbook example with some minor alterations.
// Date: 1/23/2022

// Implementation file for the Tree class.
#include "Tree.h"
#include <iostream>

using namespace std;

//  Constructor, increments the objectCount shared value.
Tree::Tree() {
  // 	(*objectCount)++;
  objectCount[0]++;
}

/*
 Description: Accessor function for the objectCount value.
 Parameters: None
 Return: Value of objectCount
 */

int Tree::getObjectCount() const { return objectCount[0]; }

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

void Tree::clean() { delete[] objectCount; }

/*
 Description: Initializer
 Parameters: None
 Return: None
 */

void Tree::build() {
  for (int i = 0; i < 5; i++)
    objectCount[i] = 0;
}

/*
 Description: Viewer for static pointer array.
 Parameters: None
 Return: None
 */

void Tree::view() {
  for (int i = 0; i < 5; i++)
    cout << objectCount[i] << " ";
}

// Definition of the static member variable, objectCount.
int *Tree::objectCount = new int[5];
