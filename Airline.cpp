#include "Airline.h"
#include "Flight.h"

Airline::Airline(string name) {
	this->name = name;
	for (int i = 0; i < 24; i++) {
		this->delayByHour[i] = 0;
	}
	this->totalDelay = 0;
}

string Airline::getName() {
	return this->name;
}

vector<Airline*> Airline::compile(vector<Flight*> flights) {
	cout << "LOADING AIRLINE DATA" << endl;
	vector<Airline*> toReturn;
	for (Flight* i : flights) {
		string airline = i->airline();
		int index;
		bool found = false;
		for (int j = 0; j < toReturn.size(); j++) {
			if (toReturn[j]->getName() == airline) {
				found = true;
				index = j;
				break;
			}
		}
		if (!found) {
			Airline* toAdd = new Airline(airline);
			toAdd->addDelay(i->delay(), i->hour());
			toReturn.push_back(toAdd);
		} else {
			toReturn[index]->addDelay(i->delay(), i->hour());
		}
	}
	cout << "AIRLINE DATA LOADED" << endl;
	return toReturn;
}

void Airline::addDelay(float d, int h) {
	this->delayByHour[h] += d;
	this->totalDelay += d;
}

float Airline::getTotalDelay() {
	return this->totalDelay;
}


float Airline::getDelayByHour(int hour) {
	return this->delayByHour[hour];
}

