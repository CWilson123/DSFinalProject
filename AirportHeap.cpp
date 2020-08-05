#include "AirportHeap.h"

int AirportHeap::getParent(int start) {
	if (start == 0) {
		return -1;
	} else {
		return (start - 1) / 2;
	}
}
int AirportHeap::getLeftChild(int start) {
	if ((start * 2) + 1 > this->heap.size()) {
		return -1;
	} else {
		return (start * 2) + 1;
	}
}
int AirportHeap::getRightChild(int start) {
	if ((start * 2) + 2 > this->heap.size() - 1) {
		return -1;
	} else {
		return (start * 2) + 2;
	}
}
void AirportHeap::heapifyDown(int start, int hour) {
	if (start > this->heap.size() - 3 || getLeftChild(start) == -1) {
		return;
	} else {
		if (hour == -1) {
			if (getRightChild(start) == -1) {
				if (this->heap[start]->getTotalDelay() > this->heap[getLeftChild(start)]->getTotalDelay()) {
					Airport* temp = this->heap[start];
					this->heap[start] = this->heap[getLeftChild(start)];
					this->heap[getLeftChild(start)] = temp;
					heapifyDown(getLeftChild(start), hour);
				}
			} else {
				if ((hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getLeftChild(start)]->getTotalDelay()) || (hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getRightChild(start)]->getTotalDelay())) {
					//cout << hour << endl;
					bool leftSmaller = this->heap[getLeftChild(start)]->getTotalDelay() < this->heap[getRightChild(start)]->getTotalDelay();
					if (leftSmaller) {
						Airport* temp = this->heap[start];
						this->heap[start] = this->heap[getLeftChild(start)];
						this->heap[getLeftChild(start)] = temp;
						heapifyDown(getLeftChild(start), hour);
					} else {
						Airport* temp = this->heap[start];
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
					Airport* temp = this->heap[start];
					this->heap[start] = this->heap[getLeftChild(start)];
					this->heap[getLeftChild(start)] = temp;
					heapifyDown(getLeftChild(start), hour);
				} 
			} else {
				if ((hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getLeftChild(start)]->getDelayByHour(hour)) || (hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getRightChild(start)]->getDelayByHour(hour))) {
					bool leftSmaller = this->heap[getLeftChild(start)]->getDelayByHour(hour) < this->heap[getRightChild(start)]->getDelayByHour(hour);
					//cout << hour << endl;
					if (leftSmaller) {
						Airport* temp = this->heap[start];
						this->heap[start] = this->heap[getLeftChild(start)];
						this->heap[getLeftChild(start)] = temp;
						heapifyDown(getLeftChild(start), hour);
					} else {
						Airport* temp = this->heap[start];
						this->heap[start] = this->heap[getRightChild(start)];							this->heap[getRightChild(start)] = temp;
						heapifyDown(getRightChild(start), hour);
					}
				}

			}
		}

	}
}


		/*
		if ((hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getLeftChild(start)]->getTotalDelay()) || (hour == -1 && this->heap[start]->getTotalDelay() > this->heap[getRightChild(start)]->getTotalDelay())) {
			//cout << hour << endl;
			bool leftSmaller = this->heap[getLeftChild(start)]->getTotalDelay() < this->heap[getRightChild(start)]->getTotalDelay();
			if (leftSmaller) {
				Airport* temp = this->heap[start];
				this->heap[start] = this->heap[getLeftChild(start)];
				this->heap[getLeftChild(start)] = temp;
				heapifyDown(getLeftChild(start), hour);
			} else {
				Airport* temp = this->heap[start];
				this->heap[start] = this->heap[getRightChild(start)];
				this->heap[getRightChild(start)] = temp;
				heapifyDown(getRightChild(start), hour);
			}
		} else if ((hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getLeftChild(start)]->getDelayByHour(hour)) || (hour != -1 && this->heap[start]->getDelayByHour(hour) > this->heap[getRightChild(start)]->getDelayByHour(hour))) {
			bool leftSmaller = this->heap[getLeftChild(start)]->getDelayByHour(hour) < this->heap[getRightChild(start)]->getDelayByHour(hour);
			cout << hour << endl;
			if (leftSmaller) {
				Airport* temp = this->heap[start];
				this->heap[start] = this->heap[getLeftChild(start)];
				this->heap[getLeftChild(start)] = temp;
				heapifyDown(getLeftChild(start), hour);
			} else {
				Airport* temp = this->heap[start];
				this->heap[start] = this->heap[getRightChild(start)];
				this->heap[getRightChild(start)] = temp;
				heapifyDown(getRightChild(start), hour);
			}
		}
	*/
void AirportHeap::heapifyUp(int start, int hour) {
	if (getParent(start) == -1) {
		return;
	} else {
		if (hour == -1 && this->heap[start]->getTotalDelay() < this->heap[getParent(start)]->getTotalDelay()) {
			Airport* temp = this->heap[start];
			this->heap[start] = this->heap[getParent(start)];
			this->heap[getParent(start)] = temp;
			heapifyUp(getParent(start));
		} else if (hour != -1 && this->heap[start]->getDelayByHour(hour) < this->heap[getParent(start)]->getDelayByHour(hour)) {
			Airport* temp = this->heap[start];
			//cout << "SWAPPING: " << this->heap[start]->getDelayByHour(hour) << " WITH: " << this->heap[getParent(start)]->getDelayByHour(hour) << endl;
			this->heap[start] = this->heap[getParent(start)];
			this->heap[getParent(start)] = temp;
			heapifyUp(getParent(start), hour);
		}
	}
}
bool AirportHeap::empty() {
	return this->heap.size() == 0;
}

void AirportHeap::push(Airport* a, int hour) {
	this->heap.push_back(a);
	heapifyUp(this->heap.size() - 1, hour);
}
void AirportHeap::pop(int hour) {
	if (!empty()) {
		Airport* temp = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		//cout << "POP IS RUNNING" << endl;
		//delete temp;
		heapifyDown(0, hour);
	}
}


Airport* AirportHeap::top() {
	return this->heap[0];
}


void AirportHeap::printHeap() {
	for (Airport* i : this->heap) {
		cout << i->getName() << " " << i->getTotalDelay() << endl;
	}
}




