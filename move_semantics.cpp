#include <iostream>
#include <utility>			//utility has std::move()
					//must compile as c++11 for R-value etc.
using namespace std;

class mov
{
	int x;
	string y;

	public:

	mov(int x = 0, string y = "") : x(x), y(y) 
	  {cout << "constructor" << endl;}

	mov(const mov& m) : x(m.x), y(m.y) 
	  {cout << "copy constructor" << endl;}

	mov& operator=(const mov& m)
	{
		cout << "regular assignment" << endl;
		x = m.x;
		y = m.y;
		return *this;
	}

	mov(mov&& m) : x(move(m.x)), y(move(m.y)) 
	  {cout << "Move copy" << endl;}

	mov& operator=(const mov&& m)
	{
		cout << "Move assignment" << endl;
		x = move(m.x);
		y = move(m.y);
		return *this;
	}
};

int main()
{
	//mov(int, string)
	mov a(0, "b");			//ctor
	mov b = a;			//regular copy ctor
	mov c(3, "c");			//ctor
	b = c;				//regular assignment
	mov d;				//ctor				
	d = move(c);			//move assignment
	mov e(move(a));			//move copy

	return 0;
}
