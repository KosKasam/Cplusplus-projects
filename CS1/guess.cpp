// Random Number Generator
// Konstantinos Kasamias
// 2/08/2018

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

int main()
{
	cout << "I selected a number between 1 and 1000,"
		" what number is it?\n";
	//int myRandGameValue;
	srand(time(nullptr)); // giving random number generator
						  // unpredictable seed
	//srand(1);       // giving predictable seed

	int myRandGameValue = rand() % 1000 + 1, Guess;


	do {
		cin >> Guess;
		if (myRandGameValue > Guess) {
			cout << "Value is too low\n";
		}
		else if (myRandGameValue < Guess) {
			cout << "Value is too high\n";
		}

	} while (myRandGameValue != Guess ||
		cout << "Congratulations!\n" << Guess << endl);
}