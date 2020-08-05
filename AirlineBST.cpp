#include "AirlineBST.h"

bool AirlineBST::insert(AirlineTreeNode* &root, Airline* a, int hour) {
	if (root == nullptr) {
		AirlineTreeNode* n = new AirlineTreeNode;
		n->val = a;
		root = n;
		return true;
	} else if (hour == -1) {
		if (a->getTotalDelay() <= root->val->getTotalDelay()) {
			insert(root->left, a, hour);
		} else {
			insert(root->right, a, hour);
		}
	} else if (hour != -1) {
		if (a->getDelayByHour(hour) <= root->val->getDelayByHour(hour)) {
			insert(root->left, a, hour);
		} else {
			insert(root->right, a, hour);
		}
	}
}

vector<Airline*> AirlineBST::inorder(AirlineTreeNode* root, vector<Airline*> &toReturn) {
	if (root == nullptr) {
		return toReturn;
	} else {
		inorder(root->left, toReturn);
		//cout << root->val->getName() << " " << root->val->getTotalDelay() << endl;
		toReturn.push_back(root->val);
		inorder(root->right, toReturn);
	}
	return toReturn;
}