#include "ali_class.h"

ALI::ALI() {
	a_= 0;
	b_= 0;
	pc_=0;
	zeroresult_=false;
	overflow_=false;
}
ALI::~ALI() {

}

int ALI::word() {
	return WORD;
}

void ALI::a(int val) {
	a_ = val;
}
int ALI::a() {
	return a_;
}

void ALI::b(int val) {
	b_ = val;
}
int ALI::b() {
	return b_;
}

void ALI::increment_pc() {
	pc_ +=1;
}
void ALI::set_pc(int val) {
	        pc_ = val;
}
int ALI::pc() {
	return pc_;
}

void ALI::set_zeroresult() {
	zeroresult_ = true;
}
void ALI::unset_zeroresult() {
	zeroresult_ = false;
}
bool ALI::zeroresult() {
	return zeroresult_;
}

void ALI::set_overflow() {
	        overflow_ = true;
}
void ALI::unset_overflow() {
	        overflow_ = false;
}
bool ALI::overflow() {
	        return overflow_;
}

void ALI::code(string str) {
	if (code_vec.size() < SIZE) 
		code_vec.push_back(str);
}

void ALI::push_to_data(string str) {
	if (data_map.size() < SIZE) {
		data_map[str];
	}
}
void ALI::assign_to_symbol(string str, int val) {
	data_map[str] = val;
}
int ALI::data(string str){
	return data_map[str];
}

void ALI::print() {
	cout << "---Memory source code---\n";
	for (auto a: code_vec) cout << a << endl;
	cout << endl;
        cout << "---Memory data---\n";
	for (auto &b: data_map) cout << b.first << ": " << b.second << endl;
	cout << endl << "---other data---\n";
	cout << "Accumulator register: " << a_ << endl;
	cout << "Additional register: " << b_ << endl;
	cout << "pc: " << pc_ << endl;
	cout << "Zeroresult bit: " << zeroresult_ << endl;
	cout << "Overflow bit: " << overflow_ << endl;

	cout << "-------------------------------\n\n";
}

