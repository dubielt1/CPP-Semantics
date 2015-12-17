#include <iostream>
#include <bitset>

using namespace std;

// 3 << 1 says shift bits of int 3 left, by 1 (0011 = 0110)
// 6 >> 1 = 3

// | = bitwise OR (x or y or both, at this bit, has a value of one, else return 0)
//	5 | 6 (0101 | 0110) = 7 (0111)
//	used to turn bit on. If already on, stays on

// ^ = bitwise XOR (Xclusive or, either x or y, at this bit, has a value of one, but not both, else 0)
//	6^3 (0110 ^ 0011) = 5 (0101)
//	used to toggle bits on or off

// 3 & 6 (0011 & 0110) = 2 (0010) (x and y, at this bit has a value of one, else 0)
//	&= ~bit off
//	Query (if (bit & val))
//	Checks if bit is on
//use unsigned int with bitwise operators


bool isodd(int x) { return (x & 1); } //1-T, 0-F

bool isset(int x, int bit) { return (x & (1<<bit)); } //true if bit == 1, by shifting 1 (0001) to desired bit to check

int changestate(int x, int bit) { return (x = (x^1<<bit)); } //toggles [bits 0-7] 

int changeallstate(int x) { return (~x); } //bitwise complement flips all bits

int xpowerof2(int x, int pow) { return (x<<pow); } //multiplies x by a power of 2 [2 ^ pow] (e.g. 10 << 2 = 40) = (10 * 2^2)

int divpowerof2(int x, int div) { return (x>>div); } //divides x by power of 2 [2 ^ div] (e.g. 40 >> 2 = 10) (16 >> 2 = 4) = (16 / 2^2)

int main()
{
	//use unsigned vars with binary operations
	unsigned int a = 23;

	//first byte of a	
	//bitsets show binary representation of variable
	cout << bitset<8>(a) << endl;
	//flips bit at position 2
	a = changestate(a, 1);
	cout << bitset<8>(a) << endl;
	cout << xpowerof2(3, 2) << endl; //3 * 2^2
	cout << divpowerof2(12, 2) << endl; //12 / 2^2
	
	return 0;
}
