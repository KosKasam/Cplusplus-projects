#include "battleship.h"

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {

	// srand(time(nullptr));

	Ship fleet[fleetSize];

	Location ship;

	int shot;

	cout << "5 Battleships within range, Captain" << endl;

	cout << "You may fire when ready" << endl;

	initialize(fleet);

	deploy(fleet);

	while (operational(fleet) == true) {

		ship = fire();

		shot = check(fleet, ship);

		if (shot == -1)

			cout << "Shot missed!" << endl;

		else if (shot != -1) {

			cout << "Shot has hit the target!" << endl;

			sink(fleet[shot]);

		}

	}

	cout << endl;

	cout << "Fleet has been destroyed, Captain" << endl;

}