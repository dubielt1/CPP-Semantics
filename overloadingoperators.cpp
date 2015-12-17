#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class stringandint
{
	public:
		friend bool operator> ( stringandint &obj1, stringandint &obj2);
		friend bool operator< ( stringandint &obj1, stringandint &obj2);
		friend bool operator== (stringandint &obj1, stringandint &obj2);
		friend ostream& operator<< (ostream& os, stringandint& output);

		void setexample(string s, int a)
		{
			exs = s;
			ex = a;
		}

		friend void swap(stringandint &lhs, stringandint &rhs)
		{
			swap(lhs.exs, rhs.exs);
			swap(lhs.ex, rhs.ex);
		}

		stringandint& operator= (stringandint rhs)
		{
			swap(*this, rhs);
			return *this;
			
			//this is a pointer to the calling object
			//so you need to dereference it
			//returning (in this instance) a reference
			//to the object (see return type)
		}

		/*stringandint& operator= (stringandint& rhs)
		{
			exs = rhs.exs;
			ex = rhs.ex;
			return *this;
		}*/
		//Option without swap

	private:
		string exs;
		int ex;
};

bool operator> (stringandint &obj1, stringandint &obj2)
{
	return (obj1.ex > obj2.ex ? true : false);
}

bool operator< (stringandint &obj1, stringandint &obj2)
{
	return (!operator> (obj1, obj2));
}

bool operator== (stringandint &obj1, stringandint &obj2)
{
	return (obj1.ex == obj2.ex ? true : false);
}

ostream& operator<<(ostream& os, stringandint& output)
{
	os << output.exs << " " << output.ex;
	return os;
}

int main()
{
	stringandint lhs;
	stringandint rhs;

	lhs.setexample("test", 10);
	rhs.setexample("example", 2);

	if (lhs < rhs) cout << "lhs < rhs\n";
	else cout << "lhs > rhs\n";
	if (lhs == rhs) cout << "lhs == rhs\n";
	else cout << "lhs != rhs\n";

	lhs = rhs; 				//proper assignment
	
	if (lhs == rhs) cout << "lhs == rhs\n";
	else cout << "lhs != rhs\n";

	return 0;
}
