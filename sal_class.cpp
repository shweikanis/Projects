#include "sal_class.h"

SAL::SAL(string str1, string str2, ALI* inst) {
	opcode = str1;
	arg = str2;
	ali = inst;
	ali->code(opcode + " " + arg);
	execute();
	assign_pc();
}
void SAL::execute(){}
void SAL:: assign_pc(){
	ali->increment_pc();
}

DEC::DEC(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void DEC::execute(){
	ali->push_to_data(arg);
}


LDI::LDI(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void LDI::execute() {
	ali->a(stoi(arg));
}

LDA::LDA(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void LDA::execute() {
	ali->a(ali->data(arg));
}

LDB::LDB(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void LDB::execute() {
	ali->b(ali->data(arg));
}

STR::STR(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void STR::execute() {
	ali->assign_to_symbol(arg, ali->a());
}

XCH::XCH(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void XCH::execute() {
	int tmp = ali->a();
	ali->a(ali->b());
	ali->b(tmp);
}

JMP::JMP(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->assign_pc();
}
void JMP::assign_pc(){
	ali->set_pc(stoi(arg));
}

JZS::JZS(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->assign_pc();
}
void JZS::assign_pc(){
	if (ali->zeroresult()) ali->set_pc(stoi(arg));
}

JVS::JVS(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->assign_pc();
}
void JVS::assign_pc(){
	if (ali->overflow()) ali->set_pc(stoi(arg));
}

ADD::ADD(string str1, string str2, ALI* inst) : SAL(str1, str2, inst){
	this->execute();
}
void ADD::execute(){
	long long l1 = ali->a();
	long long l2 = ali->b();
	long long tmp = l1 + l2;
	int max = pow(2, (ali->word()-1)) -1;
	int min = -pow(2, (ali->word()-1));

	cout << "-.-.-.-..-.-.----.-.-.-.\n";
	cout << "ADD:\n";
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
	cout << "tmp: " << tmp << endl; 
	cout << "-.-.-.-..-.-.----.-.-.-.\n";
	if (tmp > max || tmp < min) ali->set_overflow();
	else ali->unset_overflow();

	if (tmp == 0) ali->set_zeroresult();
	//else ali->unset_zeroresult();

	ali->a(tmp);
}
				     
HLT::HLT(string str1, string str2, ALI* inst) :  SAL(str1, str2, inst){
	this->assign_pc();
}
void HLT::assign_pc(){
	ali->set_pc(-1);
}
