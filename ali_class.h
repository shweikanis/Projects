#include <string>
#include <vector>
#include<map>
#include<iostream>

using namespace std;

class ALI{
	protected:
		const int SIZE = 1258;
		const int WORD = 32;
		vector<string> code_vec;
		map<string, long> data_map;
		long a_;
		long b_;
		int pc_;
		bool zeroresult_;
		bool overflow_;

	public:
		ALI();
		~ALI();

		int word();

		void a(int);
		int a();
		
		void b(int);
		int b();

		void increment_pc();
		void set_pc(int);
		int pc();
		
		void set_zeroresult();
		void unset_zeroresult();
		bool zeroresult();

		void set_overflow();
		void unset_overflow();
		bool overflow();

		void code(string);
		void push_to_data(string);
		void assign_to_symbol(string, int);
		int data(string);
		
		void print();
};
