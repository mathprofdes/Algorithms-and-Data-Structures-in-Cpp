/*
Author: Don Spickler
Creation Date: 1/28/2022
Last Update: 1/28/2022
Description: Simple die class but wrapped in a namespace.
*/

#ifndef DIE_H
#define DIE_H

namespace Dice {

class Die {
private:
  int sides; // Number of sides
  int value; // The die's value

public:
  Die(int);       // Constructor
  void roll();    // Rolls the die
  int getSides(); // Returns the number of sides
  int getValue(); // Returns the die's value
};

} // namespace Dice

#endif
