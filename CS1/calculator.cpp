
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	cout << "1.Absolute value\n2.Square Root\n3.Floor\n4.Power"
		"\nSelect An Operation\n";
	int selection;
	cin >> selection;
	cout << "\n";

	while ((selection > 0) && (5 > selection)) {
		if (selection == 1)
		{
			double n;
			cout << "Find the absolute value of\n";
			cin >> n;
			cout << "The result is\n";
			cout << abs(static_cast<double>(n));
			//cout << (double(abs(n)));
			cout << "\n"
				"Select another operation\n";
			cin >> selection;
		}
		else if (selection == 2) {
			double n;
			cout << "Find the square root of\n";
			cin >> n;
			cout << "The result is\n";
			cout << sqrt(static_cast<double>(n));
			cout << "\n"
				"Select another operation\n";
			cin >> selection;
		}

		else if (selection == 3) {
			double n;
			cout << "Find the floor of\n";
			cin >> n;
			cout << "The result is\n";
			cout << floor(static_cast<double>(n))<< endl;
			cout << "Select another operation\n";
			//system("pause");
			cin >> selection;
		}

		else if (selection == 4) {
			cout << "Enter Base\n";
			double n;
			cin >> n;
			cout << "Enter Exponent\n";
			double m;
			cin >> m;
			cout << pow(n, m) << endl;
			cout << "\n"
				"Select another operation\n";
			cin >> selection;
		}
	}
}