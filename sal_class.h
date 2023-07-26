#include <tgmath.h>
#include "ali_class.h"

class SAL{
	protected:
		string arg;
		string opcode;
		ALI* ali;
		void assign_pc();

	public:
		SAL(string, string, ALI*);
//		~SAL();
		void execute();
};

class DEC: public SAL {
	public:
		DEC(string, string, ALI*);
		void execute();
};

class LDI: public SAL{
	public:
		LDI(string, string, ALI*);
		void execute();
};

class LDA: public SAL{
	public:
		LDA(string, string, ALI*);
		void execute();
};

class LDB: public SAL{
	public: 
		LDB(string, string, ALI*);
		void execute();
};

class STR: public SAL{
	public:
		STR(string, string, ALI*);
		void execute();
};

class XCH: public SAL{
	public:
		XCH(string, string, ALI*);
		void execute();
};

class JMP: public SAL{
	public:
		JMP(string, string, ALI*);
	protected:
		void assign_pc();
};

class JZS: public SAL{
	public:
		JZS(string, string, ALI*);
	protected:
		void assign_pc();
};

class JVS: public SAL{
	public:
		JVS(string, string, ALI*);
	protected:
		void assign_pc();
};

class ADD: public SAL{
	public:
		ADD(string, string, ALI*);
		void execute();
};

class HLT: public SAL{
	public:
		HLT(string, string, ALI*);
	protected:
		void assign_pc();
};
