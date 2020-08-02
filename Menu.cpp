#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Flight.h"
#include "Airport.h"
#include "AirportHeap.h"

using namespace std;


int main() {
	vector<Flight*> flights = Flight::readFlights();

	int selection;

	cout << endl;
	cout << "WOULD YOU LIKE TO LOOK AT AIRPORT DATA OR AIRLINE DATA?" << endl;
	cout << "[1] AIRPORT DATA" << endl;
	cout << "[2] AIRLINE DATA" << endl;
	cout << "[3] EXIT" << endl;
	cin >> selection;


//DALLAS WORKING ON MENU FOR AIRPORT DATA


	if (selection == 1) {
		int totalByHour;
		cout << endl;
		cout << "WOULD YOU LIKE TO LOOK AT AIRPORT DATA IN TOTAL OR BY HOUR?" << endl;
		cout << "[1] TOTAL" << endl;
		cout << "[2] BY HOUR" << endl;
		cin >> totalByHour;
		cout << endl;

		if (totalByHour == 1) {
			int heapOrTree;
			cout << endl;
			cout << "WOULD YOU LIKE TO STORE THE DATA IN A HEAP OR BST?" << endl;
			cout << "[1] HEAP" << endl;
			cout << "[2] BST" << endl;
			cin >> heapOrTree;

			if (heapOrTree == 1) {
				int OorD;
				cout << endl;
				cout << "WOULD YOU LIKE TO LOOK AT ORIGIN DELAYS OR DESTINATION DELAYS?" << endl;
				cout << "[1] ORIGIN DELAYS" << endl;
				cout << "[2] DESTINATION DELAYS" << endl;
				cin >> OorD;

				if (OorD == 1) {
					AirportHeap h;
					vector<Airport*> origins = Airport::compileO(flights);
					for (Airport* i : origins) {
						h.push(i);
					}
					int toSee;
					cout << "PLEASE ENTER HOW MANY AIRPORTS YOU WOULD LIKE TO SEE (1 - 312)" << endl;
					cin >> toSee;

					for (int i = 0; i < toSee; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT IS " << h.heap[0]->getName();
						cout << " WITH " << h.heap[0]->getTotalDelay() << " MINUTES OF DELAY" << endl;
						cout << endl;
						h.pop();
					}
				}
			}

		} else if (totalByHour == 2) {
			int hour;
			cout << "PLEASE ENTER THE HOUR YOU WOULD LIKE TO SEARCH (0 - 23)" << endl;
			cin >> hour;
			cout << endl;

			int heapOrTree;
			cout << "WOULD YOU LIKE TO STORE THE DATA IN A HEAP OR BST?" << endl;
			cout << "[1] HEAP" << endl;
			cout << "[2] BST" << endl;
			cin >> heapOrTree;

			if (heapOrTree == 1) {
				int OorD;
				cout << endl;
				cout << "WOULD YOU LIKE TO LOOK AT ORIGIN DELAYS OR DESTINATION DELAYS?" << endl;
				cout << "[1] ORIGIN DELAYS" << endl;
				cout << "[2] DESTINATION DELAYS" << endl;
				cin >> OorD;

				if (OorD == 1) {
					AirportHeap h;
					vector<Airport*> origins = Airport::compileO(flights);
					for (Airport* i : origins) {
						h.push(i, hour);
					}
					int toSee;
					cout << "PLEASE ENTER HOW MANY AIRPORTS YOU WOULD LIKE TO SEE (1 - 312)" << endl;
					cin >> toSee;

					for (int i = 0; i < toSee; i++) {
						cout << "THE NUMBER " << i + 1 << " AIRPORT FOR HOUR " << hour << " IS " << h.heap[0]->getName();
						cout << " WITH " << h.heap[0]->getTotalDelay() << " MINUTES OF DELAY" << endl;
						cout << endl;
						h.pop(hour);
					}
				}
			}

		}


//END DALLAS WORKING ON AIRPORT DATA


	} else if (selection == 2) {

	}

}
