#include <iostream>
#include "variableSize.h"

using std::endl; using std::cout; using std::cin;

int main() {
	int size = 0;
	double number;
	double *arrayPtr = new double[size];
	char operation;
	do
	{
		cout << "enter operation [a/r/q] and number: ";
		cin >> operation;
		if (operation == 'a' || operation == 'r') {
			cin >> number;
			if (operation == 'a') {
				addNumber(arrayPtr, number, size);
			}
			else {
				removeNumber(arrayPtr, number, size);
			}
		}
		for (int i = 0; i < size; ++i) {
			cout << arrayPtr[i] << " ";
		}
		cout << endl;
	} while (operation != 'q');
}