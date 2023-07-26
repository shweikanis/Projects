#include "sal_class.h"
#include<fstream>
using namespace std;

void opcode_detector(string script, ALI* inst) {

	int size = script.size();
	string op = script.substr(0, 3);
	string arg;
	if (size > 3)
		arg = script.substr(4, size-4-1);
	else 
		arg = "";

	if (op.compare("DEC") == 0)
		DEC dec = DEC(op, arg, inst);
	else if (op.compare("LDA") == 0)
		LDA lda = LDA(op, arg, inst);
	else if (op.compare("LDB") == 0)
		LDB ldb = LDB(op, arg, inst);
	else if (op.compare("LDI") == 0)
		LDI ldi = LDI(op, arg, inst);
	else if (op.compare("STR") == 0)
		STR str = STR(op, arg, inst);
	else if (op.compare("XCH") == 0)
		XCH xch = XCH(op, arg, inst);
	else if (op.compare("JMP") == 0)
		JMP jmp = JMP(op, arg, inst);
	else if (op.compare("JZS") == 0)
		JZS jzs = JZS(op, arg, inst);
	else if (op.compare("JVS") == 0)
		JVS jvs = JVS(op, arg, inst);
	else if (op.compare("ADD") == 0)
		ADD add = ADD(op, arg, inst);
	else if (op.compare("HLT") == 0)
		HLT hlt = HLT(op, arg, inst);
}

int main() {

	ALI* ali = new ALI();
	string input;

	// read file and store lines in a string vector
	cout << "input file name:\n";
	cin >> input;
	ifstream readFile(input);
	vector<string> script;
	while(getline(readFile, input)) 
		script.push_back(input);

	// start looping and executing lines
	cout << "Enter s to execute a single line\n";
	cout << "Enter a to execute all the file\n";
	cout << "Enter q to quit\n";
	cin >> input;

	int cnt = 0;  //count times of iterations to avoid infinite loops
	while (input.compare("q") != 0 && ali->pc() != -1
		&& ali->pc() != -1 && ali->pc() < script.size() && cnt < 1000){
		
		if (input.compare("s") == 0) {
			opcode_detector(script[ali->pc()], ali);
			ali->print();
		}
		else if (input.compare("a") == 0) {
			cout << "a\n";
			while(ali->pc() != -1 && ali->pc() != -1 
				&& ali->pc() < script.size()){
				opcode_detector(script[ali->pc()], ali);
				cnt++;
				if (cnt == 1000) {
					cout << "press y to continue, n to terminate:\n";
					cin >> input;
					if(input.compare("y")==0) cnt = 0;
					else if (input.compare("n") == 0) break;
				}
			}	
			break;
		}	
		cnt++;	
		cout << "input option:\n";
		cin >> input;
	}
	ali->print();	

	return 0;
}
