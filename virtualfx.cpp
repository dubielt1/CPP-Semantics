#include <iostream>
#include <vector>

using namespace std;

class shape
{
	public:
		virtual void draw() = 0; //could have default output
		virtual ~shape() {}
};

class rect: public shape
{
	public:
		void draw() { cout << "Rectangle\n"; }
};

class triangle: public shape
{
	public:
		void draw() { cout << "Triangle\n"; }
};


int main()
{
	shape *example = new rect(); //example is a pointer bc new returns T*

	vector<shape*> shapes;
	shapes.push_back(new rect());
	shapes.push_back(new triangle());

	for (vector<shape*>::iterator i = shapes.begin(); i != shapes.end(); i++)
		(*i)->draw(); //why is draw accessed like this? bc shape*
		//why are the parentheses necessary? order of ops

	return 0;
}
