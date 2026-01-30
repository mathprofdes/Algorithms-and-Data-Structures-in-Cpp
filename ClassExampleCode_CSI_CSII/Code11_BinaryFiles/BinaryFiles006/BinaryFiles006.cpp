//============================================================================
// Name        : BinaryFiles006.cpp
// Author      : Don Spickler
// Version     : 4/18/2020
// Description : Binary File Example #6: Reading Files of Structs.
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

void DisplayLifeInformation(const LifeExp &);

int main() {
  fstream dataFile;
  string line;
  vector<LifeExp> LifeExpData;
  vector<LifeExpStore> LifeExpDataStore;

  LifeExp LifeExpCountry;
  LifeExpStore data;

  dataFile.open("LifeExpWorld.dat", ios::in | ios::binary);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  dataFile.read(reinterpret_cast<char *>(&data), sizeof(data));
  while (!dataFile.eof()) {
    LifeExpDataStore.push_back(data);
    dataFile.read(reinterpret_cast<char *>(&data), sizeof(data));
  }

  cout << LifeExpDataStore.size() << endl;

  dataFile.close();

  //  Convert
  for (unsigned int i = 0; i < LifeExpDataStore.size(); i++) {
    LifeExp LifeExpCountry;

    LifeExpCountry.CountryCode = LifeExpDataStore[i].CountryCode;
    LifeExpCountry.CountryName = LifeExpDataStore[i].CountryName;
    LifeExpCountry.Region = LifeExpDataStore[i].Region;
    LifeExpCountry.IncomeGroup = LifeExpDataStore[i].IncomeGroup;
    LifeExpCountry.Gender = LifeExpDataStore[i].Gender;
    LifeExpCountry.BirthYear = LifeExpDataStore[i].BirthYear;
    LifeExpCountry.LifeExpectancy = LifeExpDataStore[i].LifeExpectancy;

    LifeExpData.push_back(LifeExpCountry);
  }

  cout << LifeExpData.size() << endl;

  for (unsigned int i = 0; i < LifeExpData.size(); i++) {
    DisplayLifeInformation(LifeExpData[i]);
    cout << endl;
  }

  return 0;
}

void DisplayLifeInformation(const LifeExp &lifeexp) {
  cout << "Country:  " << lifeexp.CountryName << " (" << lifeexp.CountryCode
       << ")" << endl;
  if (!lifeexp.Region.empty())
    cout << "Region:  " << lifeexp.Region << endl;

  if (!lifeexp.IncomeGroup.empty())
    cout << "Income Group:  " << lifeexp.IncomeGroup << endl;

  cout << "Gender:  " << lifeexp.Gender << endl;
  cout << "Year of Birth:  " << lifeexp.BirthYear << endl;

  if (lifeexp.LifeExpectancy > 0.5)
    cout << "Life Expectancy:  " << lifeexp.LifeExpectancy << " Years" << endl;
  else
    cout << "Life Expectancy:  "
         << "None Given" << endl;
}
