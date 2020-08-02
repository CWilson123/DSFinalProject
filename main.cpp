#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Flight {
private:
	string Airline;
	int Day;
	string Origin;
	string Destination;
	int Hour;
	float Delay;
	bool HasDelay;
	bool Early;

public:
	Flight(string airline, string day, string origin, string destination, string hour, string delay, string hasDelay, string early);
	bool operator>(const Flight& f);
	bool operator<(const Flight& f);
	bool operator==(const Flight& f);
	string airline();
	int day();
	string origin();
	string destination();
	int hour();
	float delay();
	bool hasDelay();
	bool early();
};



int main() {
	string airline, origin, destination, header, test, index, day, hour, hasDelay, early, delay, departureTime;
	vector<Flight*> flights;
	int count = 0;

	ifstream file("shortened.csv");
	getline(file, header);
	cout << "READING IN FILE" << endl;
	cout << endl;
	while (file.good()) {
		count++;
		if (count % 45831 == 0) {
			cout << count << "/458311 Lines Read" << endl;
		}
		getline(file, index, ',');
		getline(file, airline, ',');
		getline(file, day, ',');
		getline(file, origin, ',');
		getline(file, destination, ',');
		getline(file, departureTime, ',');
		getline(file, delay, ',');
		getline(file, hasDelay, ',');
		getline(file, early, ',');
		getline(file, hour, '\n');

		Flight* toAdd = new Flight(airline, day, origin, destination, hour, delay, hasDelay, early);
		flights.push_back(toAdd);

		if (index == "469967") {
			break;
		}
	}
	cout << endl;
	cout << "FILE LOADED" << endl;

}
Flight::Flight(string airline, string day, string origin, string destination, string hour, string delay, string hasDelay, string early) {
	this->Airline = airline;
	this->Day = stoi(day);
	this->Origin = origin;
	this->Destination = destination;
	this->Hour = stoi(hour);
	this->Delay = stof(delay);
	if (hasDelay == "1") {
		this->HasDelay = true;
	}
	else {
		this->HasDelay = false;
	}
	if (early == "1") {
		this->Early = true;
	}
	else {
		this->Early = false;
	}
}

float Flight::delay() {
	return this->Delay;
}

bool Flight::operator>(const Flight& f) {
	if (this->Delay > f.Delay) {
		return true;
	}
	else {
		return false;
	}
}

bool Flight::operator<(const Flight& f) {
	if (this->Delay < f.Delay) {
		return true;
	}
	else {
		return false;
	}
}

bool Flight::operator==(const Flight& f) {
	if (this->Delay == f.Delay) {
		return true;
	}
	else {
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








