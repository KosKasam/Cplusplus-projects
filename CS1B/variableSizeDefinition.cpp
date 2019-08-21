#include "variableSize.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;

void output(double *arrayPtr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arrayPtr[i] << " ";
	}
}


int check(double *arrayPtr, double number, int size) {
	for (int i = 0; i < size; ++i) {
		if (arrayPtr[i] == number)
			return i;
	}
	return -1;
}


void addNumber(double *&arrayPtr, double number, int &size) {
	if (check(arrayPtr, number, size) != -1) {
		return;
	}
	double* improvedArray = new double[size + 1];
	for (int i = 0; i < size; ++i) {
		improvedArray[i] = arrayPtr[i];
	}
	improvedArray[size] = number;
	delete[] arrayPtr;
	arrayPtr = improvedArray;
	size += 1;
}


void removeNumber(double *&arrayPtr, double number, int &size) {
	if (check(arrayPtr, number, size) == -1)
		return;
	double *improvement = new double[size - 1];
	bool found = false;
	for (int i = 0; i < size; ++i) {
		//if (check(arrayPtr, number, size)) {
		//improvement[i] = arrayPtr[i];
		if (arrayPtr[i] == number) {
			found = true;
		}
		else if (!found) {
			improvement[i] = arrayPtr[i];
		}
		else {
			improvement[i - 1] = arrayPtr[i];
		}
	}
	--size;
	delete[] arrayPtr;
	arrayPtr = improvement;
}