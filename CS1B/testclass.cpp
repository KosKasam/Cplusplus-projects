// testing the implementation of class varArray
// Konstantinos Kasamias
// 04/21/2018

#include <iostream>
#include "vararrayclass.h"

using std::cout; using std::endl; using std::cin;


void testfunc(varArray); // function to test pass-by-value for varArray

int main() {
	varArray a1;
	double number;
	char operation;
	do
	{
		cout << "enter operation [a/r/q] and number: ";
		cin >> operation;
		if (operation == 'a' || operation == 'r') {
			cin >> number;
			if (operation == 'a') {
				a1.addNumber(number);
			}
			else {
				a1. removeNumber(number);
			}
		}
		a1.output();
		cout << endl;
	} while (operation != 'q');
}



// tests pass-by-value for object of class varArray
void testfunc(varArray va) { // copy constructor is invoked on "va"
	cout << "parameter va: ";
	va.output();
} // destructor is invoked when "va" goes out of scope
