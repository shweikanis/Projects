#include "bst.h"
#include <iostream>

using namespace std;

// constructor
BST::BST() {
	root_ = nullptr;
	size_ = 0;
}

// copy constructor
// calls the deep copy helper function if the source BSt is not null
BST::BST(const BST& bst) {
	this->size_ = bst.size_;
	if (bst.root_ != nullptr) {
		this->root_ = new Node(bst.root_->value());
		deep_copy(bst.root_, this->root_);
	}
	else this->root_ = nullptr;
}

// Deep copy function
// loops recursively throught the source nodes and sets the copy
void BST::deep_copy(Node* from, Node* to){ 
	if (from->left() != nullptr) {
		to->left(from->left()->value());
		deep_copy(from->left(), to->left());
	}
	if (from->right() != nullptr) {
		to->right(from->right()->value());
		deep_copy(from->right(), to->right());
	}
}

// destructor
// // calls the recursive delete funtion
BST::~BST() {
	size_ = 0;
	if (root_ == nullptr) return;
	recursive_delete(root_);
	root_ = nullptr;
}
// clear function
// calls recursice delete function
void BST::clear() {
	size_ = 0;
	if (root_ == nullptr) return;
	recursive_delete(root_);
	root_ = nullptr;
}
void BST::recursive_delete(Node* n){
	if (n->left() != nullptr) recursive_delete(n->left());
	if (n->right() != nullptr) recursive_delete(n->right());
	delete n;
}

void BST::insert(String* v) {
	if (root_ == nullptr) root_ = new Node(v);	
	else {
		Node* currN = root_;
		Node* prevN = root_;

		while (currN != nullptr) {
			prevN = currN;
			int result = equal(v, currN->value());
			if (result == 0) return;
			if (result == 2) currN = currN->left();
			else currN = currN->right();
		}
		int result = equal(v, prevN->value());
		if (result == 2) prevN->left(v);
		else if (result == 1) prevN->right(v);	
	}
	size_ += 1;
}

// returns 0 if equal strings
// 1 if s1 is bigger
// 2 if s2 is bigger
int BST:: equal(String* s1, String* s2) {
	int equalSize; // set 0 if equale size, 1 if s1 has bigger size, 2 otherwise
	int size;
	if (s1->size() > s2->size()) {
		size = s2->size();
		equalSize = 1;
	}
	else if (s1->size() < s2->size()) {
		equalSize = 2;
		size = s1->size();
	}
	else {
		equalSize = 0;
		size = s1->size();
	}

	for (int i = 0; i < size; i++) {
		if (s1->at(i) > s2->at(i)) return 1;
		else if(s1->at(i) < s2->at(i)) return 2;
	}
	return equalSize;
	
}

bool BST::contain(String* v) {return _contain(v, root_);}
bool BST::_contain(String* v, Node* n) {
	if (n == nullptr) return false;
	int result = equal(v, n->value()); 
	if (result == 2) _contain(v, n->left());
	else if (result == 1) _contain(v, n->right());
	else return true;
}

void BST::print_in_order() {if (root_ != nullptr) _print(root_);}
void BST::_print(Node* n) {
	if (n->left() != nullptr) _print(n->left());
	n->value()->print();
	if (n->right() != nullptr) _print(n->right());

}

Node* BST::root() {return root_;}
int BST::size() {return size_;}
