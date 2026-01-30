/*
    Name          : yahtzee.h
    Author        : Don Spickler
    Creation Date : 1/25/2022
    Last Update   : 1/25/2022
    Description   : Specification file for the yahtzee class.  Stores
    an array of five 6-sided dice.  There are rolling, printing, yahtzee
    determination and counter functions.
*/

#ifndef YAHTZEE_H_
#define YAHTZEE_H_

#include "Die.h"

class yahtzee {

private:
  Die hand[5]; // A yahtzee hand, consisting of 5 6-sided dice.

public:
  yahtzee();
  void roll();
  void printHand();
  bool isYahtzee();
  int numValues(int);
};

#endif /* YAHTZEE_H_ */
