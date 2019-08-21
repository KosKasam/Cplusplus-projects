// variable size array class
// Konstantinos Kasamias
// 04/21/2017


#ifndef VARARRAY_H_
#define VARARRAY_H_

class varArray {
public:
	varArray(); // void constructor
	int arraySize() const { return size; } // returns the size of the array

	int check(double number); // returns index of element containg "number" or -1 if none
	void addNumber(double);    // adds number to the array
	void removeNumber(double); // deletes the number from the array
	void output();      // prints the values of the array

						// big three
	varArray(const varArray&); // copy constructor
	varArray& operator=(const varArray&); // overloaded assignment
	~varArray(); // destructor

private:
	double *dArray; // pointer to the dynamically allocated array
	int size;   // array size
};

#endif /* VARARRAY_H_ */#pragma once
