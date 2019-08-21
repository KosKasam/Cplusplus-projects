// testing the implementation of class varArray
// Konstantinos Kasamias
// 04/21/2018

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::cin;
using std::vector;

int main() {
	vector<double> v;
	char operation;
	double number;
	do
	{
		cout << "enter operation [a/r/q] and number: ";
		cin >> operation;
			if (operation == 'a') {
				cin >> number;
				vector<double>::iterator found = std::find(v.begin(), v.end(), number);
				if (found != v.end())
					cout << "";
				else{
					v.insert(found, number);
				}
			} else if (operation == 'r') {
					cin >> number;
					vector<double>::iterator toRemove = std::find(v.begin(), v.end(), number);
					if (toRemove != v.end())
						v.erase(toRemove);
		   }
		cout << "Your numbers: ";
		for (vector<double>::iterator ip = v.begin();
			ip != v.end(); ++ip) {
			cout << *ip << " ";
		}
		cout << endl;
	} while (operation != 'q');
}