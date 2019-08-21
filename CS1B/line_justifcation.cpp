#include "text_justification.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>


using std::cout; using std::cin; using std::endl;
using std::string; using std::ofstream; using std::ifstream;

string wordSort(string &length) {
	srand(time(nullptr));
	string line=length;

	/*cout << "Enter string and hit enter: \n";
	getline(cin,length)*/
	if (line.size() > minLine) {  // line
		punctSpacing(line);
		wordSpacing(line);
	}
	output(line);	
	return line;
}

void punctSpacing(string &line) {

	int pos = -1;
	do {
		pos = line.find_first_of("!?;.,", pos + 1);
		if (pos != string::npos)
			line.insert(pos + 1, " ");
	} while (pos != string::npos);
}

void wordSpacing(string &line) {
	int pos = -1;
	do {
		pos = line.find_first_of(" \t", pos + 1);
		if (pos == string::npos) {
			pos = -1;
		}
		else {
			if (rand() % 2 == 0 ? true : false)
				line.insert(pos + 1, " ");
			line.find_first_not_of(" \t", pos + 1);
		}
	} while (line.size() < maxLine);
}

void output(const string &line) {
	cout << line << /*endl << "size is: " << line.size() <<*/ endl;
}