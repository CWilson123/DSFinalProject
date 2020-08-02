#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
using namespace std;
#pragma once

class Airport {
private:
	string name;
	map<int, float> delayByHour;
	float totalDelay;

public:
	Airport(string name);
	static vector<Airport*> compileO(vector<Flight*> flights);
	static vector<Airport*> compileD(vector<Flight*> flights);
	void addDelay(float d, int h);
	string getName();
	float getTotalDelay();
	float getDelayByHour(int hour);
};