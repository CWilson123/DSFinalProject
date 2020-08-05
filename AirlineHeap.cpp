#include "AirlineHeap.h"

int AirlineHeap::getParent(int start) {
	if (start == 0) {
		return -1;
	} else {
		return (start - 1) / 2;
	}
}
int AirlineHeap::getLeftChild(int start) {
	if ((start * 2) + 1 > this->heap.size()) {
		return -1;
	} else {
		return (start * 2) + 1;
	}
}
int AirlineHeap::getRightChild(int start) {
	if ((start * 2) + 2 > this->heap.size() - 1) {
		return -1;
	} else {
		return (start * 2) + 2;
	}
}
void AirlineHeap::heapifyDown(int start, int hour) {
	if (start > this->heap.size() - 3 || getLeftChild(start) == -1) {
		return;
	} else {
		if (hour == -1) {
			if (getRightChild(start) == -1) {
				if (this->heap[start]->getTotalDelay() > this->heap[getLeftChild(start)]->getTotalDelay()) {
					Airline* temp = this->heap[start];
					this->heap[start] = this->heap[getLeftChild(start)];
					this->heap[getLeftChild(start)] = temp;
					heapifyDown(getLeftChild(start), hour);
				}
			} else {
				if ((hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getLeftChild(start)]->getTotalDelay()) || (hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getRightChild(start)]->getTotalDelay())) {
					//cout << hour << endl;
					bool leftSmaller = this->heap[getLeftChild(start)]->getTotalDelay() < this->heap[getRightChild(start)]->getTotalDelay();
					if (leftSmaller) {
						Airline* temp = this->heap[start];
						this->heap[start] = this->heap[getLeftChild(start)];
						this->heap[getLeftChild(start)] = temp;
						heapifyDown(getLeftChild(start), hour);
					} else {
						Airline* temp = this->heap[start];
						this->heap[start] = this->heap[getRightChild(start)];
						this->heap[getRightChild(start)] = temp;
						heapifyDown(getRightChild(start), hour);
					}
				}
				
			}
		//CODE FOR SPECIFIC HOUR
		} else {
			if (getRightChild(start) == -1) {
				if (this->heap[start]->getDelayByHour(hour) > this->heap[getLeftChild(start)]->getDelayByHour(hour)) {
					Airline* temp = this->heap[start];
					this->heap[start] = this->heap[getLeftChild(start)];
					this->heap[getLeftChild(start)] = temp;
					heapifyDown(getLeftChild(start), hour);
				} 
			} else {
				if ((hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getLeftChild(start)]->getDelayByHour(hour)) || (hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getRightChild(start)]->getDelayByHour(hour))) {
					bool leftSmaller = this->heap[getLeftChild(start)]->getDelayByHour(hour) < this->heap[getRightChild(start)]->getDelayByHour(hour);
					//cout << hour << endl;
					if (leftSmaller) {
						Airline* temp = this->heap[start];
						this->heap[start] = this->heap[getLeftChild(start)];
						this->heap[getLeftChild(start)] = temp;
						heapifyDown(getLeftChild(start), hour);
					} else {
						Airline* temp = this->heap[start];
						this->heap[start] = this->heap[getRightChild(start)];							this->heap[getRightChild(start)] = temp;
						heapifyDown(getRightChild(start), hour);
					}
				}

			}
		}

	}
}

void AirlineHeap::heapifyUp(int start, int hour) {
	if (getParent(start) == -1) {
		return;
	} else {
		if (hour == -1 && this->heap[start]->getTotalDelay() < this->heap[getParent(start)]->getTotalDelay()) {
			Airline* temp = this->heap[start];
			this->heap[start] = this->heap[getParent(start)];
			this->heap[getParent(start)] = temp;
			heapifyUp(getParent(start));
		} else if (hour != -1 && this->heap[start]->getDelayByHour(hour) < this->heap[getParent(start)]->getDelayByHour(hour)) {
			Airline* temp = this->heap[start];
			//cout << "SWAPPING: " << this->heap[start]->getDelayByHour(hour) << " WITH: " << this->heap[getParent(start)]->getDelayByHour(hour) << endl;
			this->heap[start] = this->heap[getParent(start)];
			this->heap[getParent(start)] = temp;
			heapifyUp(getParent(start), hour);
		}
	}
}
bool AirlineHeap::empty() {
	return this->heap.size() == 0;
}

void AirlineHeap::push(Airline* a, int hour) {
	this->heap.push_back(a);
	heapifyUp(this->heap.size() - 1, hour);
}
void AirlineHeap::pop(int hour) {
	if (!empty()) {
		Airline* temp = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		//cout << "POP IS RUNNING" << endl;
		//delete temp;
		heapifyDown(0, hour);
	}
}


Airline* AirlineHeap::top() {
	return this->heap[0];
}


void AirlineHeap::printHeap() {
	for (Airline* i : this->heap) {
		cout << i->getName() << " " << i->getTotalDelay() << endl;
	}
}




