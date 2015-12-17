#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void variable_capture()
{
	int captured = 12;

	//modifies captured variable
	//() at end of lambda definition executes the lambda	
	[&captured] () {captured+=12;} ();

	//output: 24
	cout << captured << endl;

}

int main()
{
	//original vector
	vector<int> example = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//destination for modified values
	vector<int> destination(example.size());

	//end is iter to end of input values
	//if size > # of vals resize
	//copies all even values to destination
	//uses lambda as anonymous function
	auto end = copy_if(example.begin(), example.end(), destination.begin(),
	  [] (int example_mem) { return !(example_mem % 2); });

	//resizes
	destination.resize(distance(destination.begin(), end));

	//range-based for loop
	for (const int x: destination) cout << " " << x;
	cout << endl;

	variable_capture();

	return 0;
}
