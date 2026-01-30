//============================================================================
// Name        : BinaryFiles002.cpp
// Author      : Don Spickler
// Version     : 4/18/2020
// Description : Binary File Example #2: Read in large text file and store in
//    a string.
//============================================================================

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char ch;
  fstream file;
  file.open("HGGT.txt", ios::in | ios::binary);

  if (!file) {
    cout << "Error opening file. Program aborting.\n";
    return 0;
  }

  string book = "";
  while (!file.eof()) {
    file.read(&ch, sizeof(ch));
    book += ch;
  }

  cout << "Done Reading File..." << endl;
  file.close();

  cout << book.size() << endl;

  return 0;
}
