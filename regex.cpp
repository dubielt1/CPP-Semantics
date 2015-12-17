#include <iostream>
#include <regex>
#include <cassert>

//basic phone number regex

using namespace std;

int main()
{
	string input;
	smatch match_info;

	//use (?: ) for passive group/no backreference
	//that way, " " and "-" don't count as sub matches
	string raw_expr = 
	  R"((\d?(?:\s|-)?\(?\d{3}\)?(?:\s|-)?\d{3}(?:\s|-)?\d{4})+)";

	regex expr(raw_expr);

	cout << "input your phone number: ";
	//getline allows the optional spaces in input
	getline(cin, input);
	
	//abort if pattern doesn't match
	//regex_match requires the whole string matches pattern
	//regex_search returns true if string contains a pattern match
	//search smatch has prefix() and suffix() of a match
	//smatch also has position() and format() e.g. $1
	//and regex iterators for iter over matches
	assert( regex_match(input, match_info, expr) );

	//print sub matches
	//first sub match is matched subtring
	//followed by individual submatches ()
	for(auto s : match_info)
		cout << s << endl;

	return 0;
}
