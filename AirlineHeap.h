#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Flight.h"
#include "Airport.h"
#include "Airline.h"
using namespace std;
#pragma once

class AirlineHeap {
private:
	int getParent(int start);
	int getLeftChild(int start);
	int getRightChild(int start);
	void heapifyDown(int start, int hour = -1);
	void heapifyUp(int start, int hour = -1);
public:
	bool empty();
	void push(Airline* a, int hour = -1);
	void pop(int hour = -1);
	Airline* top();
	void printHeap();
	vector<Airline*> heap;
};