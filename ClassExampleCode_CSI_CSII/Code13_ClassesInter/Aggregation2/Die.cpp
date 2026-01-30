/*
 Name          : Die.cpp
 Author        : Don Spickler
 Creation Date : 1/21/2022
 Last Update   : 1/21/2022
 Description   : Implementation file for the Die class.
 */

#include <chrono>
#include <iostream>

#include "Die.h"

using namespace std;
using namespace std::chrono;

/*
 Description: Constructor
 Parameters: numSides - Number of sides to the die.
 Return: None
 Note: This implementation requires the RNG seed to be set in the main, or at
 least before this class is instantiated.
 */

Die::Die(int numSides) {
  // Using a nanoseconds clock, higher resolution so that instances will have a
  // different seed.
  auto seed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                  std::chrono::system_clock::now().time_since_epoch())
                  .count();
  srand(seed);

  // cout << seed << endl;

  // Set the number of sides.
  sides = numSides;

  // Perform an initial roll.
  roll();
}

/*
 Description: Roll function that will roll the die and store the value.
 Parameters: None
 Return: None
 */

void Die::roll() {
  // Get a random value for the die.
  value = (rand() % sides) + MIN_VALUE;
}

/*
 Description: Accessor for the number of sides of the die.
 Parameters: None
 Return: Number of sides of the die.
 */

int Die::getSides() const { return sides; }

/*
 Description: Accessor for the value of the last roll.
 Parameters: None
 Return: Value of the last roll.
 */

int Die::getValue() const { return value; }
