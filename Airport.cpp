#include "Airport.h"
#include "Flight.h"

Airport::Airport(string name) {
	this->name = name;
	for (int i = 0; i < 24; i++) {
		this->delayByHour[i] = 0;
		this->flightsPerHour[i] = 0;
	}
	this->totalDelay = 0;
	this->numFlights = 0;
}

string Airport::getName() {
	return this->name;
}

void Airport::addFlight(int hour) {
	this->numFlights++;
	this->flightsPerHour[hour]++;
}

vector<Airport*> Airport::compileO(vector<Flight*> flights) {
	cout << "LOADING AIRPORT DATA" << endl;
	vector<Airport*> toReturn;
	for (Flight* i : flights) {
		string flightD = i->origin();
		int index;
		bool found = false;
		for (int j = 0; j < toReturn.size(); j++) {
			if (toReturn[j]->getName() == flightD) {
				found = true;
				index = j;
				break;
			}
		}
		if (!found) {
			Airport* toAdd = new Airport(flightD);
			toAdd->addDelay(i->delay(), i->hour());
			toAdd->addFlight(i->hour());
			toReturn.push_back(toAdd);
		} else {
			toReturn[index]->addDelay(i->delay(), i->hour());
			toReturn[index]->addFlight(i->hour());
		}
	}
	cout << "AIRPORT DATA LOADED" << endl;
	return toReturn;
}

vector<Airport*> Airport::compileD(vector<Flight*> flights) {
	cout << "LOADING AIRPORT DATA" << endl;
	vector<Airport*> toReturn;
	for (Flight* i : flights) {
		string flightD = i->destination();
		int index;
		bool found = false;
		for (int j = 0; j < toReturn.size(); j++) {
			if (toReturn[j]->getName() == flightD) {
				found = true;
				index = j;
				break;
			}
		}
		if (!found) {
			Airport* toAdd = new Airport(flightD);
			toAdd->addDelay(i->delay(), i->hour());
			toAdd->addFlight(i->hour());
			toReturn.push_back(toAdd);
		} else {
			toReturn[index]->addDelay(i->delay(), i->hour());
			toReturn[index]->addFlight(i->hour());
		}
	}
	cout << "AIRPORT DATA LOADED" << endl;
	return toReturn;
}

void Airport::addDelay(float d, int h) {
	this->delayByHour[h] += d;
	this->totalDelay += d;
}

float Airport::getTotalDelay() {
	return this->totalDelay;
}

float Airport::getDelayByHour(int hour) {
	if (hour > 23 || hour < 0) {
		return 0;
	} else {
		return this->delayByHour[hour];
	}
}







