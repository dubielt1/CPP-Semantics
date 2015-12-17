#include <iostream>
#include <array>

using namespace std;

int main()
{
	//array<type, size>
	//has iterators
	//.size()
	//.front and .back
	//.data is pointer to data (decay)
	//.at(index) is range checked, unlike operator[]
	//.fill(const val)

	array<int, 10> nums = 
	  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (const int& num: nums) cout << " " << num;
	cout << endl;

	return 0;
}
