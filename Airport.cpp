#include "Airport.h"
#include "Flight.h"

Airport::Airport(string name) {
	this->name = name;
	for (int i = 0; i < 24; i++) {
		this->delayByHour[i] = 0;
	}
	this->totalDelay = 0;
}

string Airport::getName() {
	return this->name;
}

vector<Airport*> Airport::compileO(vector<Flight*> flights) {
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
			toReturn.push_back(toAdd);
		} else {
			toReturn[index]->addDelay(i->delay(), i->hour());
		}
	}
	return toReturn;
}

vector<Airport*> Airport::compileD(vector<Flight*> flights) {
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
			toReturn.push_back(toAdd);
		} else {
			toReturn[index]->addDelay(i->delay(), i->hour());
		}
	}
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







