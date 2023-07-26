/*
 *Siham Shweikani
 *CS474
 *Fall 2022
 *project #3
 * C++ Sets
 * */

#include <iostream>
#include "bst.h"

using namespace std;

// Function for finding the union of the two sets
// loops through the nodes of set2 and add its contents in S1 BST
void Union(BST* tree, Node* node) {
	if (node != nullptr) {
		tree->insert(node->value());
		Union(tree, node->left());
		Union(tree, node->right());
	}
}

// Function for finding the intersectionf of the two sets
// loops through the nodes of S2
// checks if it is contained in S2 BST
// if true, adds it to a new temperory BST
void Intersection(BST* tree, Node* a, BST* b) {
	if (a != nullptr) {
		if (b->contain(a->value())) tree->insert(a->value());
		Intersection(tree, a->left(), b);
		Intersection(tree, a->right(), b);
	}
}

// Function returns true of S2 is a proper subset of S1
// loops through the nodes of S2, if all are in S1 returns true
// returns false otherwise
bool Subset(BST* tree, Node* n) {
	if (n != nullptr) {
		if (tree->contain(n->value())) {
			return Subset(tree, n->left()) & Subset(tree, n->right());
		}
		else return false;
	}
	return true;
}

int main() {
	BST* S1 = new BST();
	BST* S2 = new BST();
	
	cout << "Input your choice:\n";
	cout << "e - Erase set S1\n";
	cout << "s - Switch sets\n";
	cout << "b - Find if S2 is a proper subset of S1\n";
	cout << "c - Copy S1 into S2\nl - List S1 and S2\n";
	cout << "a - Add element to S1\n";
	cout << "u - Union S1 and S2 and store in S1\n";
	cout << "i - Intersect S1 and S2 and store in S1\n";
	cout << "q - Quit\n";

	char input;
	cin >> input;
	while (input != 'q') {
		if (input == 'e') S1->clear();
		else if (input == 's') {
			// switch the pointers pf the sets
			BST* temp = S1;
			S1 = S2;
			S2 = temp;
		}	

		else if (input == 'a') {
			// enter the string after entering a
			cout << "Enter the string:\n";
			char* val;
			cin >> val;
			String* str = new String(val);
			S1->insert(str); 
		}
		
		else if (input == 'l') {
			cout << "\nS1: ";
			S1->print_in_order();
			cout << "\nS2: ";
			S2->print_in_order();
			cout << endl;
		}	

		else if (input == 'c') {
			// clear S2 and deep copy from S1
			S2->clear();
			S2 = new BST(*S1);
		}

		else if (input == 'b') {
			// if the size of S2 is greater or equal than S1, then S2 is not a proper set of S21
			if (S1->size() <= S2->size()) 
				cout << "S2 is not proper set from S1\n";
			// if S2 is empty, then it is a proper set of S1
			else if (S2->size() == 0) 
				cout << "S2 is a proper set from S1\n";
			// otherwise, check for elements is S2 and S1 
			else {
				bool result = Subset(S1, S2->root());
				if (result)  cout << "S2 is a proper set from S1\n";
				else  "S2 is not proper set from S1\n";
			}
		}
		else if (input == 'u') {
			Union(S1, S2->root());
		}
		else if (input == 'i') {
			// create a new BST pointer for storing the intersection
			BST* temp = new BST();
			Intersection(temp, S1->root(), S2);
			// set S1 for the new temp BST pointer
			S1->clear();
			S1 = temp;
			// let the pointer point to null
			temp = nullptr;
		}

		cout << "Input your choice:\n";
		cin >> input;
	}
	cout << "\nS1: ";
	S1->print_in_order();
	cout << "\nS2: ";
	S2->print_in_order();
	cout << endl;
	return 0;
}
