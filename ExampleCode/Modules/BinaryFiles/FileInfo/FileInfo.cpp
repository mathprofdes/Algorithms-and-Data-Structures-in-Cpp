//============================================================================
// Name        : FileInfo.cpp
// Author      : Don Spickler
//============================================================================

#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
	struct stat fileInfo;

	if (stat("LifeExpWorld.dat", &fileInfo) != 0) {
		cerr << "Error: " << strerror(errno) << endl;
		return (EXIT_FAILURE);
	}

	cout << "Type:   : ";
	if ((fileInfo.st_mode & S_IFMT) == S_IFDIR) {
		cout << "Directory";
	} else {
		cout << "File";
	}
	cout << endl;

	cout << "Size    : " << fileInfo.st_size << endl;
	cout << "Created : " << ctime(&fileInfo.st_ctime);
	cout << "Modified: " << ctime(&fileInfo.st_mtime);
}

