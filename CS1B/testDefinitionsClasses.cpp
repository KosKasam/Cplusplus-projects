#include "vararrayclass.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

varArray::varArray() {
	int size = 0;
	double *arrayPtr = new double[size];
}

int varArray::check(double number) {
	for (int i = 0; i < size; ++i) {
		if (dArray[i] == number)
			return i;
	}
	return -1;
}

void varArray::addNumber(double number) {
	if (check(number) != -1) {
		return;
	}
	double* improvedArray = new double[size + 1];
	for (int i = 0; i < size; ++i) {
		improvedArray[i] = dArray[i];
	}
	improvedArray[size] = number;
	delete[] dArray;
	dArray = improvedArray;
	size += 1;
}

void varArray::removeNumber(double number) {
	if (check(number) == -1)
		return;
	double *improvement = new double[size - 1];
	bool found = false;
	for (int i = 0; i < size; ++i) {
		//if (check(arrayPtr, number, size)) {
		//improvement[i] = arrayPtr[i];
		if (dArray[i] == number) {
			found = true;
		}
		else if (!found) {
			improvement[i] = dArray[i];
		}
		else {
			improvement[i - 1] = dArray[i];
		}
	}
	--size;
	delete[] dArray;
	dArray = improvement;
}

void varArray::output() {
	for (int i = 0; i < size; ++i) {
		cout << dArray[i] << " ";
	}
}

varArray::varArray(const varArray& org) {
	size = org.size;
	dArray = new double[size];
	for (int i = 0; i< size; ++i) dArray[i] = org.dArray[i];

}

varArray& varArray::operator=(const varArray& number) {
	if (this != &number) {
		size = number.size;
		delete[] dArray;
		dArray = new double[size];
		for (int i = 0; i < size; i++)
			dArray[i] = number.dArray[i];
	}
	return *this;
}

varArray::~varArray() {
	delete[] dArray;
}