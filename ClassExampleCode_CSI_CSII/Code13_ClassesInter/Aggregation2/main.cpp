/*
 Author: Don Spickler
 Creation Date: 1/25/2022
 Last Update: 1/25/2022
 Description: Testing program for the yahtzee class.
 User Interface: None
 */

#include <iostream>

#include "yahtzee.h"

using namespace std;

int main() {
  // Create a yahtzee hand.
  yahtzee hand;

  // Roll
  hand.roll();

  // Display results.
  cout << "Roll: ";
  hand.printHand();
  cout << endl;

  if (hand.isYahtzee())
    cout << "You have a Yahtzee.\n";
  else
    cout << "You do not have a Yahtzee.\n";

  cout << endl;

  for (int i = 1; i <= 6; i++)
    cout << "The number of " << i << " dice = " << hand.numValues(i) << endl;
  cout << endl;

  // Simulate the continual rolling of the dice until a Yahtzee is rolled.
  int count = 0;
  while (!hand.isYahtzee()) {
    count++;
    hand.roll();
  }

  // Print simulation results.
  cout << "Roll: ";
  hand.printHand();
  cout << endl;

  cout << "Number of rolls needed = " << count << endl;

  return 0;
}
