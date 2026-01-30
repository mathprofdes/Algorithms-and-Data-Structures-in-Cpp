//============================================================================
// Name        : BinaryFiles008.cpp
// Author      : Don Spickler
// Version     : 4/18/2020
// Description : Binary File Example #8: Reading Files of Structs.
//============================================================================

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>

using namespace std;

struct LifeExpStore {
  char CountryCode[10];
  char CountryName[100];
  char Region[100];
  char IncomeGroup[100];
  char Gender[100];
  int BirthYear;
  double LifeExpectancy;
};

void DisplayLifeInformation(const LifeExpStore &);

int main() {
  fstream dataFile;
  string line;
  struct stat fileInfo;

  if (stat("LifeExpWorldFull.dat", &fileInfo) != 0) {
    cerr << "Error: " << strerror(errno) << endl;
    return (EXIT_FAILURE);
  }

  long filesize = fileInfo.st_size;
  long records = filesize / sizeof(LifeExpStore);

  cout << records << endl;

  dataFile.open("LifeExpWorldFull.dat", ios::in | ios::binary);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  LifeExpStore *LifeExpDataStore = new LifeExpStore[records];
  dataFile.read(reinterpret_cast<char *>(LifeExpDataStore), filesize);
  dataFile.close();

  for (unsigned int i = 0; i < records; i++) {
    DisplayLifeInformation(LifeExpDataStore[i]);
    cout << endl;
  }

  delete[] LifeExpDataStore;

  return 0;
}

void DisplayLifeInformation(const LifeExpStore &lifeexp) {
  cout << "Country:  " << lifeexp.CountryName << " (" << lifeexp.CountryCode
       << ")" << endl;
  cout << "Region:  " << lifeexp.Region << endl;
  cout << "Income Group:  " << lifeexp.IncomeGroup << endl;
  cout << "Gender:  " << lifeexp.Gender << endl;
  cout << "Year of Birth:  " << lifeexp.BirthYear << endl;
  cout << "Life Expectancy:  " << lifeexp.LifeExpectancy << " Years" << endl;
}
