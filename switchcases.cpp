#include <iostream>

using namespace std;

int main()
{
	int swich = 5;

	switch(swich) 
	{
		case 4: cout << "4" << endl;
		case 5: cout << "5" << endl;
		/*switch case FALL-THRU because no break*/
		case 6: cout << swich + 1 << endl;
			break;
		case 7: cout << "7" << endl;
	}

	switch(swich) 
	{
		case 4: cout << "4" << endl;
		case 5: cout << "5" << endl;
			break;
		case 6: cout << swich + 1 << endl;
			break;
		case 7: cout << "7" << endl;
		//default:
	}

	return 0;
}
