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

class AirportHeap {
private:
	//vector<Airport*> heap;
	int getParent(int start);
	int getLeftChild(int start);
	int getRightChild(int start);
	void heapifyDown(int start, int hour = -1);
	void heapifyUp(int start, int hour = -1);

public:
	bool empty();
	void push(Airport* a, int hour = -1);
	void pop(int hour = -1);
	Airport* top();
	void printHeap();
	vector<Airport*> heap;
};