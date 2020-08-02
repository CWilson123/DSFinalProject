#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#pragma once


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
	static vector<Flight*> readFlights();
};
