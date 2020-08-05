#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
#include "Airport.h"
#include "AirportTreeNode.h"
using namespace std;
#pragma once

class AirportBST {
public:
	bool insert(AirportTreeNode* &root, Airport* a, int hour = -1);
	AirportTreeNode* root = nullptr;
	vector<Airport*> inorder(AirportTreeNode* root, vector<Airport*> &toReturn);
	vector<Airport*> ordered;
};