#include "node.h"

Node::Node(String* v) {
	value_ = v;
	right_ = nullptr;
	left_ = nullptr;
}

void Node::value(String* v) {value_ = v;}
void Node::right(String* v) { right_ = new Node(v);}
void Node::left(String* v) {left_ = new Node(v);}
Node* Node::right() {return right_;}
Node* Node::left() {return left_;}
String* Node::value() {return value_;}
