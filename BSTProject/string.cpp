#include "string.h"
#include <iostream>
#include<cstring>

using namespace std;

String::String(char* str) {
	size_ = strlen(str);
	chars_ = new char[size_];
	strcpy(chars_, str);
}

String::String(const String& str) {
	this->size_ = str.size_;
	chars_ = str.chars_;
}

String::~String() {
	if (size_ > 0) chars_ = nullptr;
	size_ = 0;
}
int String::size(){
	return size_;
}

char String::at(int pos){
	return chars_[pos];
}
void String::print(){
	cout << chars_ << " ";
}


