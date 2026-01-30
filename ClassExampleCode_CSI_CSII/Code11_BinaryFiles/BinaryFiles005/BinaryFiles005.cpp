//============================================================================
// Name        : BinaryFiles005.cpp
// Author      : Don Spickler
// Version     : 4/18/2020
// Description : Binary File Example #5: Files of Structs.
//============================================================================

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LifeExp {
  string CountryCode;
  string CountryName;
  string Region;
  string IncomeGroup;
  string Gender;
  int BirthYear;
  double LifeExpectancy;
};

struct LifeExpStore {
  char CountryCode[10];
  char CountryName[100];
  char Region[100];
  char IncomeGroup[100];
  char Gender[100];
  int BirthYear;
  double LifeExpectancy;
};

string ltrim_copy(string);
string rtrim_copy(string);
string trim_copy(string);

int main() {
  fstream dataFile;
  string line;
  vector<LifeExp> LifeExpData;
  vector<LifeExpStore> LifeExpDataStore;

  // Open File
  dataFile.open("LifeExpWorld.txt", ios::in);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  getline(dataFile, line); // Remove first line of titles.

  // Load File and parse between the tab characters.
  while (getline(dataFile, line)) {
    LifeExp LifeExpCountry;
    int pos = line.find('\t');
    LifeExpCountry.CountryCode = trim_copy(line.substr(0, pos));

    int lastpos = pos;
    pos = line.find('\t', pos + 1);
    LifeExpCountry.CountryName = trim_copy(line.substr(lastpos, pos - lastpos));

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    LifeExpCountry.Region = trim_copy(line.substr(lastpos, pos - lastpos));

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    LifeExpCountry.IncomeGroup = trim_copy(line.substr(lastpos, pos - lastpos));

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    LifeExpCountry.Gender = trim_copy(line.substr(lastpos, pos - lastpos));

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    LifeExpCountry.BirthYear =
        atoi(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    LifeExpCountry.LifeExpectancy = atof(trim_copy(line.substr(pos)).c_str());

    LifeExpData.push_back(LifeExpCountry);
  }
  dataFile.close();

  //  Convert

  for (unsigned int i = 0; i < LifeExpData.size(); i++) {
    LifeExpStore data;
    strcpy(data.CountryCode, LifeExpData[i].CountryCode.c_str());
    strcpy(data.CountryName, LifeExpData[i].CountryName.c_str());
    strcpy(data.Region, LifeExpData[i].Region.c_str());
    strcpy(data.IncomeGroup, LifeExpData[i].IncomeGroup.c_str());
    strcpy(data.Gender, LifeExpData[i].Gender.c_str());
    data.BirthYear = LifeExpData[i].BirthYear;
    data.LifeExpectancy = LifeExpData[i].LifeExpectancy;

    LifeExpDataStore.push_back(data);
  }

  // Save to binary file.
  dataFile.open("LifeExpWorld.dat", ios::out | ios::binary);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  for (unsigned int i = 0; i < LifeExpDataStore.size(); i++) {
    LifeExpStore data = LifeExpDataStore[i];
    dataFile.write(reinterpret_cast<char *>(&data), sizeof(data));
  }

  dataFile.close();

  return 0;
}

// trim from start (copying)
string ltrim_copy(string str) {
  string chars = "\t\n\v\f\r ";
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

// trim from end (copying)
string rtrim_copy(string str) {
  string chars = "\t\n\v\f\r ";
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

// trim (copying)
string trim_copy(string str) { return rtrim_copy(ltrim_copy(str)); }
