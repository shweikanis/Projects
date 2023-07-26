

class String {

	protected:
		int size_;
		char* chars_;
	public:
		String(char*);
		String(const String&);
		~String();
		int size();
		char at(int);
		void at(int, char);
		void print();
};
