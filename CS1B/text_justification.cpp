#include <fstream>
#include <string>
#include <iostream>
#include "text_justification.h"

using std::string;
using std::ifstream; using std::ofstream;
using std::cin; using std::cout; using std::endl;

int main() {

	// inputing file name
	cout << "Input file name to print: \n\n";
	string fileNameInput = "unjustified.txt";
	string fileNameOutput = "justified.txt";

	// opening file
	ifstream fin(fileNameInput);
	ofstream fout(fileNameOutput);

	// printing
	string line;
	while (getline(fin, line)) {
		fout << wordSort(line) << endl;
	}
	fin.close();
}
