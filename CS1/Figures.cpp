// figures program consisting of
// implementation of loops of stars
// Konstantinos Kasamias
// 01/29/2018


#include <iostream>

using std::cout; using std::endl; using std::cin;

int main()
{
	cout << "Input the size of the stars: ";
	int size;
	cin >> size;
	cout << "\n";

	// nested loops
	// produces a square out of stars
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			cout << "*";
		}

		cout << "\n";
	}
	cout << "\n";

	// produces a diagonal line
	// wherein stars fall on values
	// that equal rows and columns
	for (int i = size; i > 0; --i){
		for (int j = 0; j < size - i; ++j){
			cout << " ";
		}
		for (int j = i; j <= i; ++j)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";

	// produces a right triangle 
	// out of stars
	for (int i = 0; i <= size; ++i){
		for (int j = 0; j < i; ++j){
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";

	// produces a second right triangle
	// out of stars
	for (int i = size; i > 0; --i){
		for (int j = 0; j < size - i; ++j){
			cout << " ";
		}
		for (int j = 1; j <= i; ++j)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";

	// produces a hollowed square
	// out of stars
	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			if (j == size)
			{
				cout << "*";
			}
			else if (j == 1)
			{
				cout << "*";
			}
			else if (i == size)
			{
				cout << "*";
			}
			else if (i == 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
 }
