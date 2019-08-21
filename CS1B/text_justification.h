#ifndef TEXT_JUSTIFICATION_H
#define TEXT_JUSTIFICATION_H
#include <string>
#include <fstream>
using std::string; using std::ifstream; using std::ofstream;
void wordSpacing(string &);
void punctSpacing(string &);
void output(const string &);
const int maxLine = 75;
const int minLine = 40;
string wordSort(string &);

#endif TEXT_JUSTIFICATION_H

