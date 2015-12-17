#include <iostream>
#include <cstdio>	//printf

using namespace std;

//argv[0] is name of executable
int main(int argc, char *argv[])
{
	const char* test = "test";

//	printf("%s\n", argv[1]);
	cout << argv[1] << endl;

	if (string(argv[1]) == test)
		cout << "example" << endl;
	return 0;
}
