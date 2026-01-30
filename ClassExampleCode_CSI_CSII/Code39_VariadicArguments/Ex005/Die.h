#ifndef DIE_H
#define DIE_H

#include <iostream>
using namespace std;

class Die {
  private:
    int sides;
    int value;

  public:
    Die(int numSides = 6);
    void roll();
    int getSides() const;
    int getValue() const;

    bool operator==(const Die &);
    bool operator!=(const Die &);
    bool operator<(const Die &);

    friend ostream &operator<<(ostream &, const Die &);
};
#endif
