// Textbook example with some minor alterations.
// Date: 1/23/2022

// Implementation file for the Tree class.

#include "Tree.h"

//  Constructor, increments the objectCount shared value.
Tree::Tree() { objectCount++; }

/*
 Description: Accessor function for the objectCount value.
 Parameters: None
 Return: Value of objectCount
 */

int Tree::getObjectCount() const { return objectCount; }

// Definition of the static member variable, objectCount.
int Tree::objectCount = 0;
