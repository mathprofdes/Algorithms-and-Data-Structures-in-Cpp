//============================================================================
// Name        : BinaryFiles004.cpp
// Author      : Don Spickler
// Version     : 4/18/2020
// Description : Binary File Example #4: Files of unknown size.
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	srand(time(0));

	int num;
	int size = rand() % 10 + 10;
	fstream file;
	vector<int> numbers;

	// Open the file for output in binary mode.
	file.open("numbers.dat", ios::out | ios::binary);

	// Write the contents of the array to the file.
	cout << "Writing the data to the file.  ";
	cout << "Numbers written: "<< size << endl;
	cout << endl;

	for (int i = 0; i < size; i++) {
		num = rand();
		file.write(reinterpret_cast<char*>(&num), sizeof(num));
	}

	// Close the file.
	file.close();

	// Open the file for input in binary mode.
	file.open("numbers.dat", ios::in | ios::binary);

	if (!file) {
		cout << "Error opening file. Program aborting.\n";
		return 0;
	}

	// Read the contents of the file into the array.
	cout << "Now reading the data back into memory.\n";

	file.read(reinterpret_cast<char*>(&num), sizeof(num));
	while (!file.eof()) {
		numbers.push_back(num);
		file.read(reinterpret_cast<char*>(&num), sizeof(num));
	}

	cout << "File size: " << numbers.size() << endl;
	cout << endl;

	// Display the contents of the array.
	for (unsigned int count = 0; count < numbers.size(); count++)
		cout << numbers[count] << endl;

	// Close the file.
	file.close();
	return 0;
}
