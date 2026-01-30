/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 2/3/2024
Description: Driver for inheritance exception class examples.
User Interface: None
Notes: This type of structure can be done with any of the system level
exceptions.
*/

#include <exception>
#include <iostream>
#include <vector>

#include "MyErrors.h"

using namespace std;

// Functions to simply throw the exceptions.
void throw1() { throw MyError("Here's my exception, #1."); }
void throw2() { throw MyError2("Here's my exception, #2."); }
void throw3() { throw MyError3("Here's my exception, #3."); }

int main() {
  try {
    throw1();
  } catch (const MyError &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    throw2();
  } catch (const MyError2 &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    throw3();
  } catch (const MyError3 &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    throw2();
  } catch (const runtime_error &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    throw1();
  } catch (const exception &e) {
    cerr << "Caught exception : " << e.what() << endl;
  }

  try {
    throw3();
    vector<int> V = {1, 2, 3, 4, 5};
    int r = V.at(7);
  } catch (const MyError &e) {
    cerr << "Caught exception MyError : " << e.what() << endl;
  } catch (const MyError2 &e) {
    cerr << "Caught exception MyError2 : " << e.what() << endl;
  } catch (const MyError3 &e) {
    cerr << "Caught exception MyError3 : " << e.what() << endl;
  } catch (const runtime_error &e) {
    cerr << "Caught exception runtime_error : " << e.what() << endl;
  } catch (const exception &e) {
    cerr << "Caught general exception: " << e.what() << endl;
  }

  return 0;
}
