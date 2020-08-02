#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Flight.h"

using namespace std;


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