#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
using namespace std;
#pragma once

class Airline {
private:
	string name;
	map<int, float> delayByHour;
	float totalDelay;
public:
	Airline(string name);
	static vector<Airline*> compile(vector<Flight*> flights);
	void addDelay(float d, int h);
	string getName();
	float getTotalDelay();
	float getDelayByHour(int hour);
};