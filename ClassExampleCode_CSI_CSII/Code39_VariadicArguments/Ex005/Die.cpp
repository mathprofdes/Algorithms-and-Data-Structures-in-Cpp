#include "Die.h"

using namespace std;

Die::Die(int numSides) {
    sides = numSides;
    roll();
}

void Die::roll() { value = (rand() % sides) + 1; }
int Die::getSides() const { return sides; }
int Die::getValue() const { return value; }
bool Die::operator==(const Die &d2) { return value == d2.value; }
bool Die::operator!=(const Die &d2) { return value != d2.value; }
ostream &operator<<(ostream &strm, const Die &d2) { return strm << d2.value; }
