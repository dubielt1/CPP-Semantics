#include <iostream>

using namespace std;

struct example
{
	int examplevar;
};

int main()
{
	example ex;
	//-> operator
	example *classexample = &ex;
	classexample->examplevar = 22;
	cout << "\nClass example ptr: " << classexample->examplevar << endl;
	//22 as expected


	//. operator
	example &refex = ex;
	refex.examplevar = 33;
	cout << "Class example ref: " << refex.examplevar << endl;
	//33 as expected
	cout << "\n";
	

	int num = 5;
	int num2 = 7;
	int &ref = num;
	int *ptr = &num;
	int *ptr2 = &ref; //this is same as *ptr2 = &num
			  //Can't have a pointer to a reference


	cout << "Reference: " << ref << endl; //5 as expected
	cout << "Variable: " << num << endl;  
	cout << "Pointer: " << *ptr <<endl;  //5 as expected

	ref = 4; //change num using reference variable

	cout << "Reference: " << ref << endl; //4 as expected
	cout << "Variable: " << num << endl;  //changed to 4
	cout << "Pointer: " << *ptr << endl;  //points to num, so 4

	*ptr = 10; //change num using pointer variable

	cout << "Reference: " << ref << endl; //references num so 10
	cout << "Variable: " << num << endl;  //changed to 10
	cout << "Pointer: " << *ptr << endl;  //10 as expected

	num = num2;

	cout << "Reference: " << ref << endl; //changed to 7
	cout << "Variable: " << num << endl;  //7
	cout << "Pointer: " << *ptr << endl;  //changed to 7

	cout << "Reference memory: " << &ref << endl; //Address-of operator on a reference
						      //gives the address of the referent
						      //So &ref == &num
	cout << "Pointer memory: " << &ptr << endl;
	cout << "Second pointer mem: " << &ptr2 << endl;
	cout << "Variable memory: " << &num << endl;
	cout << "\n";

	return 0;
}

	
