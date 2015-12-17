#include <iostream>
#include <tuple>

using namespace std;

struct example
{
	int one;
	int two;
	int three;

	example(int a, int b, int c) :
	  one(a), two(b), three(c) {}
};

bool operator<(const example& e, const example& e2)
{
	//temporary tuples of example's member vars
	return tie(e.one, e.two, e.three) < 
	  tie(e2.one, e2.two, e2.three);
}

tuple<int, int, int> multi_variable_return()
{
	int a = 0;
	int b = 1;
	int c = 2;

	return make_tuple(a, b, c);
}

int main()
{

	//using tuple for object comparions
	example e(2, 2, 3);
	example e2(2, 3, 4);

	//see: overloaded < operator
	if (e < e2) cout << "e < e2" << endl;


	//using tuple for multiple return variables from fx
	tuple<int, int, int> multi = multi_variable_return();

	int multi1;	//0
	int multi2;	//1
	int multi3;	//2

	tie(multi1, multi2, multi3) = multi;
	
	cout << endl;

	cout << multi1 << " " << multi2
	  << " " << multi3 << endl;

	return 0;
}
