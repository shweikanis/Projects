#include "string.h"

class Node {
protected:
        String* value_;
        Node* left_;
        Node* right_;
public:
	Node(String*);
	void value(String*);
	void left(String*);
	void right(String*);
	String* value();
	Node* left();
	Node* right();
};
