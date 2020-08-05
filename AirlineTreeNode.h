#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
#include "Airline.h"
using namespace std;
#pragma once

class AirlineTreeNode {
public:
	Airline* val;
	AirlineTreeNode* left = nullptr;
	AirlineTreeNode* right = nullptr;
};