/*
Author: Don Spickler
Creation Date: 1/28/2022
Last Update: 1/28/2022
*/

#include "Die.h"
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
using namespace std;

/*
Description: Constructor, accepts an argument for the number of sides for the
die, and performs a roll.
Parameters: Number of sides to the die.
Return: Nothing
Notes: None
*/

Dice::Die::Die(int numSides) {
  // Get the system time.
  unsigned seed = time(0);

  // Seed the random number generator.
  srand(seed);

  // Set the number of sides.
  sides = numSides;

  // Perform an initial roll.
  roll();
}

/*
Description: The roll member function simulates the rolling of the die.
Parameters: None
Return: None
Notes: None
*/

void Dice::Die::roll() {
  // Constant for the minimum die value
  const int MIN_VALUE = 1; // Minimum die value

  // Get a random value for the die.
  value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

/*
Description: The getSides member function returns the number of for this die.
Parameters: None
Return: Number of sides as an int.
Notes: None
*/

int Dice::Die::getSides() { return sides; }

/*
Description: The getValue member function returns the die's value.
Parameters: None
Return: Current integer value of the roll.
Notes: None
*/

int Dice::Die::getValue() { return value; }
