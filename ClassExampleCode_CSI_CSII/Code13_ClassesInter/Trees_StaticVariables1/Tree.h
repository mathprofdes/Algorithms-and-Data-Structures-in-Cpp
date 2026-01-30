// Textbook example with some minor alterations.
// Date: 1/22/2022

// Specification file for the Tree class

#ifndef TREE_H
#define TREE_H

class Tree {
private:
  static int objectCount; // Static member variable.

public:
  Tree();
  int getObjectCount() const;
};

#endif
