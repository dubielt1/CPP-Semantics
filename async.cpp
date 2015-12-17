#include <iostream>
#include <future>
#include <functional> //std::ref

//must use -lpthread compiler flag
//short, hacky example of doing something while polling for quit command

using namespace std;

int user_input(char& quit)
{
	while (quit != 'q')
	{
		//cout << ".";
	}
	cout << "quit successfully" << endl;
	return 0;
}

int main()
{
	char q;

	future<int> quit = async(launch::async, user_input, ref(q));
	cin >> q;
	quit.get();
	return 0;

}
