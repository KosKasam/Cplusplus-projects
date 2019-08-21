// demonstrates call-by-reference parameters.
// Konstantinos Kasamias
// 02/19/2018

#include <iostream>

using std::cout; using std::endl; using std::cin;

void getNumbers(int&, int&, int&); // reads two integers from the keyboard.
void swap(int&, int&, int&); // interchanges first and second parameter.
void showResults(int, int, int); // outputs parameters


int main() {
	int firstNum, secondNum, thirdNum;

	getNumbers(firstNum, secondNum, thirdNum);
	swap(firstNum, secondNum, thirdNum);
	showResults(firstNum, secondNum, thirdNum);
	system("Pause");
}

// reads three integers from user
void getNumbers(int& in1, int& in2, int& in3) {
	cout << "Enter three integers: ";
	cin >> in1 >> in2 >> in3;
}

// interchanges first, second, and third
void swap(int& first, int& second, int& third) {
	if (first>second){
		const int tmp = first;
		first = second;
		second = tmp;
	}
	
	else if (first>third){
		const int tmp = first;
		first = third;
		third = tmp;
	}

	else if (second > third)
	{
		const int tmp = second;
		second = third;
		third = tmp;
	}
	
}

// outputs parameters
void showResults(int out1, int out2, int out3) {
	cout << "In reverse order, the numbers are: "
		<< out1 << " " << out2 << " " << out3 << endl;
}