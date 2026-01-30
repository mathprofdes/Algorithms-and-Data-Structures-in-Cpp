#ifndef DEMO_H_
#define DEMO_H_

#include <iostream>

using namespace std;

class Demo {
private:
  string name;

public:
  Demo(string objname); // Constructor
  ~Demo();              // Destructor
  string getName();
};

#endif /* DEMO_H_ */
