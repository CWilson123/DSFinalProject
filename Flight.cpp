#include "Flight.h"

//using namespace std;

Flight::Flight(string airline, string day, string origin, string destination, string hour, string delay, string hasDelay, string early) {
	this->Airline = airline;
	this->Day = stoi(day);
	this->Origin = origin;
	this->Destination = destination;
	this->Hour = stoi(hour);
	this->Delay = stof(delay);
	if (hasDelay == "1") {
		this->HasDelay = true;
	} else {
		this->HasDelay = false;
	}
	if (early == "1") {
		this->Early = true;
	} else {
		this->Early = false;
	}
}

float Flight::delay() {
	return this->Delay;
}

bool Flight::operator>(const Flight &f) {
	if (this->Delay > f.Delay) {
		return true;
	} else {
		return false;
	}
}

bool Flight::operator<(const Flight &f) {
	if (this->Delay < f.Delay) {
		return true;
	} else {
		return false;
	}
}

bool Flight::operator==(const Flight &f) {
	if (this->Delay == f.Delay) {
		return true;
	} else {
		return false;
	}
}

string Flight::airline() {
	return this->Airline;
}

int Flight::day() {
	return this->Day;
}

string Flight::origin() {
	return this->Origin;
}

string Flight::destination() {
	return this->Destination;
}

int Flight::hour() {
	return this->Hour;
}

bool Flight::hasDelay() {
	return this->HasDelay;
}

bool Flight::early() {
	return this->Early;
}










