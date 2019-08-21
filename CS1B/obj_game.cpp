#include "battleship.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

	int main() {
		Fleet myFleet;
		char receivedIntel;
		srand(time(NULL));
		myFleet.deployFleet();
		cout << " The positions of the ships can be learned. y/n?" << endl;
		cin >> receivedIntel;
		if (receivedIntel == 'y')
			myFleet.printFleet();
		do {
			Location shot;
			shot.fire();
			if (myFleet.isHitNSink(shot)) {
				cout << "Hit!" << endl;
			}
			else
				cout << "Missed!" << endl;
			if (receivedIntel == 'y')
				myFleet.printFleet();
		} while (myFleet.operational());
		cout << "Destroyed all of them" << endl;
	}
