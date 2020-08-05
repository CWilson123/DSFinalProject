#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
#include "Airline.h"
#include "AirlineTreeNode.h"
using namespace std;
#pragma once

class AirlineBST {
public:
	bool insert(AirlineTreeNode* &root, Airline* a, int hour = -1);
	AirlineTreeNode* root = nullptr;
	vector<Airline*> inorder(AirlineTreeNode* root, vector<Airline*> &toReturn);
	vector<Airline*> ordered;
};