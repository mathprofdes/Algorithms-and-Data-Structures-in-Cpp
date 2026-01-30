/*
Author: Don Spickler
Creation Date: 2/3/2024
Last Update: 2/3/2024
Description: Set of simple example classes inheriting off of runtime_error.
Notes: This type of structure can be done with any of the system level
exceptions.
*/

#ifndef _MYERRORS_H_
#define _MYERRORS_H_

#include <exception>
#include <iostream>

using namespace std;

// Full inherited class overriding the what() function.
class MyError : public runtime_error {
protected:
  string message;

public:
  MyError(const string m) : runtime_error("") { message = m; }
  virtual ~MyError() throw() {}
  virtual const char *what() const throw() { return message.c_str(); }
};

// Inherited class using the what() function from runtime_error.
class MyError2 : public runtime_error {
public:
  MyError2(const string m) : runtime_error(m) {}
  virtual ~MyError2() throw() {}
};

// Minimal inherited class.
class MyError3 : public runtime_error {
public:
  MyError3(const string m) : runtime_error(m) {}
};

#endif
