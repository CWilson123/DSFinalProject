#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
#include "Airport.h"
using namespace std;
#pragma once

class AirportTreeNode {
public:
	Airport* val;
	AirportTreeNode* left = nullptr;
	AirportTreeNode* right = nullptr;
};