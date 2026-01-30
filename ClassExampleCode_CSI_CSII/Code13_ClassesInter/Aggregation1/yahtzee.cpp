/*
 Name          : yahtzee.cpp
 Author        : Don Spickler
 Creation Date : 1/25/2022
 Last Update   : 1/25/2022
 Description   : Implementation file for the yahtzee class.
 */

#include "yahtzee.h"
#include <iostream>

using namespace std;

/*
 Description: Constructor
 Parameters: None
 Return: None
 Note: This implementation requires the RNG seed to be set in the main, or at
 least before this class is instantiated.  Nothing needs to be done here since
 the array declaration will initialize the 5 dice.
 */

yahtzee::yahtzee() {}

/*
 Description: Rolls the 5 dice.
 Parameters: None
 Return: None
 */

void yahtzee::roll() {
  for (int i = 0; i < 5; i++)
    hand[i].roll();
}

/*
 Description: Prints the current hand to the screen.
 Parameters: None
 Return: None
 */

void yahtzee::printHand() {
  for (int i = 0; i < 5; i++)
    cout << hand[i].getValue() << " ";
}

/*
 Description: Determines if the hand is a yahtzee.
 Parameters: None
 Return: true if the hand is a yahtzee and false otherwise.
 */

bool yahtzee::isYahtzee() {
  bool result = true;
  for (int i = 1; i < 5; i++)
    if (hand[0].getValue() != hand[i].getValue())
      result = false;

  return result;
}

/*
 Description: Returns the number of dice with the value of the input parameter.
 Parameters: val - face value of the dice to be counted.
 Return: The number of dice in the hand with face value of val.
 */

int yahtzee::numValues(int val) {
  int count = 0;
  for (int i = 0; i < 5; i++)
    if (hand[i].getValue() == val)
      count++;

  return count;
}
