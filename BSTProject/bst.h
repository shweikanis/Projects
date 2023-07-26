#include <iostream>
#include "node.h"

class BST{
	protected:
		Node* root_;
		int size_;

	public:
		BST();  // constructor
		BST(const BST&);
		~BST();  // destructor
		void clear();
		void insert(String*);
		bool contain(String*);
		void print_in_order();
		int size();  // size getter
		Node* root();  // root getter
	private:
		bool _contain(String*, Node*);  // helper functions
		int equal(String*, String*);
		void _print(Node*);
		void recursive_delete(Node*);
		void deep_copy(Node*, Node*);
};
