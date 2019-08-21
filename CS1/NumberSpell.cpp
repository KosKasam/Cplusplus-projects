// demonstrates ability to switch digits and transform them into text form
// Konstantinos Kasamias
// 01/26/2018

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {

	// user inputs number 1-50
	cout << "Input number from 1 to 50: ";
	int number;
	cin >> number;

	const int singles = number % 10;
	const int tens = number / 10;

	if (number > 50 || number < 1) {
		cout << "Please enter a number between 1-50." << endl;
	}
	else
	{
		if (tens == 1) {
			switch (singles) {
			case 0:
				cout << "Ten" << endl; break;
			case 1:
				cout << "Eleven" << endl; break;
			case 2:
				cout << "Twelve" << endl; break;
			case 3:
				cout << "Thirteen" << endl; break;
			case 4:
				cout << "Fourteen" << endl; break;
			case 5:
				cout << "Fifteen" << endl; break;
			case 6:
				cout << "Sixteen" << endl; break;
			case 7:
				cout << "Seventeen" << endl; break;
			case 8:
				cout << "Eighteen" << endl; break;
			case 9:
				cout << "Nineteen" << endl; break;
			}
		}
		else {
			switch (tens) {
			case 2:
				cout << "Twenty"; break;
			case 3:
				cout << "Thirty"; break;
			case 4:
				cout << "Forty"; break;
			case 5:
				cout << "Fifty"; break;
			}
			switch (singles) {
			case 1:
				cout << "one"; break;
			case 2:
				cout << "two"; break; 
			case 3:
				cout << "three"; break;
			case 4:
				cout << "four"; break;
			case 5:
				cout << "five"; break;
			case 6:
				cout << "six"; break;
			case 7:
				cout << "seven"; break; 
			case 8:
				cout << "eight"; break;
			case 9:
				cout << "nine"; break;
			}
			cout << endl;
		}
	}
}
