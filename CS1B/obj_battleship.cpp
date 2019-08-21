#include "battleship.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

Location::Location() {
	x = -1;
	y = '*';
}

void Location::pick() {
	Location tmp;
	tmp.x = rand() % fieldSize + 1;
	//tmp.y = rand() % fieldSize + 1;
	switch (tmp.x) {
	case 1: tmp.y = 'a'; break;
	case 2: tmp.y = 'b'; break;
	case 3: tmp.y = 'c'; break;
	case 4: tmp.y = 'd'; break;
	case 5: tmp.y = 'e'; break;
	}
}

void Location::fire() {
	Location tmp;
	int inputx;
	char inputy;
	cout << "Input an integer 1-5" << endl;
	cin >> inputx;
	cout << "Input a letter a-e" << endl;
	cin >> inputy;
	tmp.x = inputx;
	tmp.y = inputy;
}

void Location::print() const {
	cout << "The Ships are holding at:" << x << y << endl;
}

bool compare(const Location& spotOne, const Location& spotTwo) {
	return (spotOne.x == spotTwo.x && spotOne.y == spotTwo.y);
}

Ship::Ship() {
	for (int i = 0; i<5; i++)
		sunk = false;
}


bool Ship::match(const Location& shipsLocation) const {
	return compare(loc, shipsLocation);
}

void Ship::sink() {
	sunk = true;
}

void Ship::setLocation(const Location& shipsLocation) {
	loc = shipsLocation;
}

void Ship::printShip() const {
	loc.print();
	if (sunk == false)
		cout << "The ship is still floating!" << endl;
	else if (sunk == true)
		cout << "The ship just sunk to the bottom!" << endl;
}

void Fleet::deployFleet() {
	Location spot;
	//spot.Location::Location();
	for (int i = 0; i < fleetSize; ++i) {
		spot.pick();
		ships[i].setLocation(spot);
	}
}

bool Fleet::operational() const {
	for (int i = 0; i < fleetSize; ++i) {
		if (ships[i].isSunk() == false)
			return true;
	}
	return false;
}

bool Fleet::isHitNSink(const Location & shipsLocation) {
	Location tmp = shipsLocation;
	for (int i = 0; i<fleetSize; ++i)
		if (ships[i].match(tmp) == true && ships[i].isSunk() == false) {
			ships[i].sink();
			return true;
		}
		else
			return false;
}

void Fleet::printFleet()const {
	for (int i = 0; i < fleetSize; ++i)
		ships[i].printShip();
}

int Fleet::check(const Location& shipsLocation) const {
	Location tmp;
	for (int i = 0; i <fleetSize; ++i) {
		if (ships[i].match(tmp))
			return true;
		else
			return false;
	}
}