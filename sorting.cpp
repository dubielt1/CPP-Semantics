#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool issorted(int arr[], int size)
{
	int i = 0;
	int j = 1;

	for (; j < size; i++, j++)
	{
		if (arr[j] < arr[i])
		{
			return false;
		}
	}
	return true;
}

int* bubblesort(int arr[], int size) //compares adjacent indices until sorted -- multiple passes
{
	static bool no_swap = false;
	while (no_swap == false)
	{
		no_swap = issorted(arr, size);
		int i = 0;
		int j = 1;
		int indextemp = 0;
		for (; j < size; i++, j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	return arr;
}

int* insertionsort(int arr[], int size) //beginning at zero, takes current element and sorts it within [0 - i] -- single pass
{					//The "backtracking" or "settling" sort (hint: decrementing)
	int indextemp = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]);
			}
		}
	}

	return arr;
}

int* selectionsort(int arr[], int size) //from [0 - size] finds smallest element and sorts it, then increments [1 - size].. etc.
{					//--single pass
	int min;			
	int indextemp=0;	
	int minindex=0;

	for (int i = 0; i < size; i++)
	{
		min = arr[i]; //default minimum 
		for (int j = i+1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minindex=j; //index of new minimum value
			}
		}
		
		if (min != arr[i]) //if a new minimum is found
		{
			swap(arr[i], arr[minindex]);
		}
		
	}

	return arr;
}

int* mergesort(int arr[], int size)
{
	int half;
	//g++ compiler allows this. Use vector otherwise
	int *results = new int[size];

	if (size < 2)
		return arr;

	if (size % 2 == 0)
		half = size/2;
	else
		half = (size + 1)/2;

	int* lefthalf = new int[half];
	int* righthalf = new int[half];

	memcpy(lefthalf, arr, (half*4));
	memcpy(righthalf, arr+half, (half*4));

	mergesort(lefthalf, half);
	sort(lefthalf, lefthalf + half);
	mergesort(righthalf, half);
	sort(righthalf, righthalf + half);

	merge(lefthalf, lefthalf+half, righthalf, righthalf+half, results);

	return results;
}

int main()
{
	int* test = new int[6];
	int* aptr;
	test[0] = 23;
	test[1] = 4;
	test[2] = 11;
	test[3] = 10;
	test[4] = 6;
	test[5] = 1;
	
	//test = bubblesort(test, 6); works
	//test = insertionsort(test, 6); works
	//test = selectionsort(test, 6); works
	//test = mergesort(test, 6); works

	aptr = test;
        for (unsigned int counter = 0; counter < 6; aptr++, counter++)
                cout << *aptr << " ";

	return 0;
}
