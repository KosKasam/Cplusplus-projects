// finds maximum number input
// demonstrates "iterate and keep track" idiom
// Konstantinos Kasamias
// 1/29/2018

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {

	cout << "Input number [0 to quit]\n: ";
	int n;
	int sum = 0;
	cin >> n;
	
// sets parameter where termination of a contiuned input occurs with 0 
// summates the collective negative amount at once
	while (n != 0) {
		cin >> n;
		if (n < 0) 
			sum += n;
	}
	cout << "Sum: " << sum << endl;
}