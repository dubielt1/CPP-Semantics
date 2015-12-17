#include <iostream>
#include <csignal>
#include <cstdlib>

using namespace std;

int main()
{
	//feature to intercept signals raised from program
	//signal(SIGNAL_NAME, pointer to a function)
	//function required to take one int parameter
	signal(SIGINT, 
	  [] (int i) { cout << "\naborting" << endl; exit(0); } );

	while(1)
	{
	}
	
	return 0;
}
