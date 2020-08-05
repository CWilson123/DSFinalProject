#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Flight.h"
#include "Airport.h"
#include "AirportHeap.h"
#include "AirportTreeNode.h"
#include "AirportBST.h"

using namespace std;


int main() {
	vector<Flight*> flights = Flight::readFlights();

	int selection;

	cout << endl;
	cout << "WOULD YOU LIKE TO STORE DATA IN A HEAP OR A BST?" << endl;
	cout << "[1] HEAP" << endl;
	cout << "[2] BST" << endl;
	cin >> selection;

	//SELECTION IS HEAP
	if (selection == 1) {
		int airportOrAirline;
		cout << "WOULD YOU LIKE TO LOOK AT DATA BY AIRPORT OR BY AIRLINE?" << endl;
		cout << "[1] AIRPORT" << endl;
		cout << "[2] AIRLINE" << endl;
		cin >> airportOrAirline;

		//SELECTION IS AIRPORT
		if (airportOrAirline == 1) {
			int OorD;
			cout << "WOULD YOU LIKE TO LOOK AT ORIGIN AIRPORTS OR DESTINATION AIRPORTS?" << endl;
			cout << "[1] ORIGIN" << endl;
			cout << "[2] DESTINATION" << endl;
			cin >> OorD;

			//HEAP, AIRPORT, ORIGIN
			if (OorD == 1) {
				int totalOrHour;
				cout << "WOULD YOU LIKE TO LOOK AT TOTAL DELAYS OR DELAYS BY HOUR?" << endl;
				cout << "[1] TOTAL DELAYS" << endl;
				cout << "[2] DELAYS BY HOUR" << endl;
				cin >> totalOrHour;

				//HEAP, AIRPORT, ORIGIN, TOTAL
				if (totalOrHour == 1) {
					vector<Airport*> a = Airport::compileO(flights);
					AirportHeap h;
					for (Airport* i : a) {
						h.push(i);
					}

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;

					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT IS " << h.top()->getName() << " WITH " << h.top()->getTotalDelay() << " MINUTES OF DELAY" << endl;
						h.pop();
					}
				//HEAP, AIRPORT, ORIGIN, HOUR
				} else if (totalOrHour == 2) {
					int hour;

					cout << "WHAT HOUR (0 - 23) WOULD YOU LIKE TO LOOK AT?" << endl;
					cin >> hour;

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;



					vector<Airport*> a = Airport::compileO(flights);
					AirportHeap h;
					for (Airport* i : a) {
						h.push(i, hour);
					}
					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT FOR HOUR " << hour << " IS " << h.top()->getName() << " WITH " << h.top()->getDelayByHour(hour) << " MINUTES OF DELAY" << endl;
						h.pop(hour);
					}
				}
			} else {

				int totalOrHour;
				cout << "WOULD YOU LIKE TO LOOK AT TOTAL DELAYS OR DELAYS BY HOUR?" << endl;
				cout << "[1] TOTAL DELAYS" << endl;
				cout << "[2] DELAYS BY HOUR" << endl;
				cin >> totalOrHour;

				//HEAP, AIRPORT, ORIGIN, TOTAL
				if (totalOrHour == 1) {
					vector<Airport*> a = Airport::compileD(flights);
					AirportHeap h;
					for (Airport* i : a) {
						h.push(i);
					}

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;

					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT IS " << h.top()->getName() << " WITH " << h.top()->getTotalDelay() << " MINUTES OF DELAY" << endl;
						h.pop();
					}
				//HEAP, AIRPORT, ORIGIN, HOUR
				} else if (totalOrHour == 2) {
					int hour;

					cout << "WHAT HOUR (0 - 23) WOULD YOU LIKE TO LOOK AT?" << endl;
					cin >> hour;

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;



					vector<Airport*> a = Airport::compileD(flights);
					AirportHeap h;
					for (Airport* i : a) {
						h.push(i, hour);
					}
					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT FOR HOUR " << hour << " IS " << h.top()->getName() << " WITH " << h.top()->getDelayByHour(hour) << " MINUTES OF DELAY" << endl;
						h.pop(hour);
					}
				}	

			}
		}
	//SELECTION IS BST
	} else if (selection == 2) {
		int airportOrAirline;
		cout << "WOULD YOU LIKE TO LOOK AT DATA BY AIRPORT OR BY AIRLINE?" << endl;
		cout << "[1] AIRPORT" << endl;
		cout << "[2] AIRLINE" << endl;
		cin >> airportOrAirline;

		//BST, AIRPORT
		if (airportOrAirline == 1) {
			int OorD;
			cout << "WOULD YOU LIKE TO LOOK AT ORIGIN AIRPORTS OR DESTINATION AIRPORTS?" << endl;
			cout << "[1] ORIGIN" << endl;
			cout << "[2] DESTINATION" << endl;
			cin >> OorD;

			//BST, AIRPORT, ORIGIN
			if (OorD == 1) {
				int totalOrHour;
				cout << "WOULD YOU LIKE TO LOOK AT TOTAL DELAYS OR DELAYS BY HOUR?" << endl;
				cout << "[1] TOTAL DELAYS" << endl;
				cout << "[2] DELAYS BY HOUR" << endl;
				cin >> totalOrHour;

				//BST, AIRPORT, ORIGIN, TOTAL
				if (totalOrHour == 1) {
					vector<Airport*> a = Airport::compileO(flights);
					AirportBST bst;
					for (Airport* i : a) {
						bst.insert(bst.root, i);
					}
					bst.inorder(bst.root, bst.ordered);
					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;

					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT IS " << bst.ordered[i]->getName() << " WITH " << bst.ordered[i]->getTotalDelay() << " MINUTES OF DELAY" << endl;
					}
				//BST, AIRPORT, ORIGIN, HOUR
				} else if (totalOrHour == 2) {
					int hour;

					cout << "WHAT HOUR (0 - 23) WOULD YOU LIKE TO LOOK AT?" << endl;
					cin >> hour;

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;



					vector<Airport*> a = Airport::compileO(flights);
					AirportBST bst;
					for (Airport* i : a) {
						bst.insert(bst.root, i, hour);
					}
					bst.inorder(bst.root, bst.ordered);
					cout << bst.ordered.size() << endl;
					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT FOR HOUR " << hour << " IS " << bst.ordered[i]->getName() << " WITH " << bst.ordered[i]->getDelayByHour(hour) << " MINUTES OF DELAY" << endl;
					}
				}
			//BST, AIRPORT, DESTINATION
			} else if (OorD == 2) {
				int totalOrHour;
				cout << "WOULD YOU LIKE TO LOOK AT TOTAL DELAYS OR DELAYS BY HOUR?" << endl;
				cout << "[1] TOTAL DELAYS" << endl;
				cout << "[2] DELAYS BY HOUR" << endl;
				cin >> totalOrHour;

				//BST, AIRPORT, DESTINATION, TOTAL
				if (totalOrHour == 1) {
					vector<Airport*> a = Airport::compileD(flights);
					AirportBST bst;
					for (Airport* i : a) {
						bst.insert(bst.root, i);
					}
					bst.inorder(bst.root, bst.ordered);
					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;

					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT IS " << bst.ordered[i]->getName() << " WITH " << bst.ordered[i]->getTotalDelay() << " MINUTES OF DELAY" << endl;
					}
				//HEAP, AIRPORT, DESTINATION, HOUR
				} else if (totalOrHour == 2) {
					int hour;

					cout << "WHAT HOUR (0 - 23) WOULD YOU LIKE TO LOOK AT?" << endl;
					cin >> hour;

					int numAirports;
					cout << "HOW MANY OF THE BEST AIRPORTS (1 - 312) WOULD YOU LIKE TO SEE?" << endl;
					cin >> numAirports;



					vector<Airport*> a = Airport::compileD(flights);
					AirportBST bst;
					for (Airport* i : a) {
						bst.insert(bst.root, i, hour);
					}
					bst.inorder(bst.root, bst.ordered);
					for (int i = 0; i < numAirports; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT FOR HOUR " << hour << " IS " << bst.ordered[i]->getName() << " WITH " << bst.ordered[i]->getDelayByHour(hour) << " MINUTES OF DELAY" << endl;
					}
				}
			}
		}
	}

}