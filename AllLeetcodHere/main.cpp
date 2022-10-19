#include <iostream>
#include "Solution03.h"
//#include "Notes.h"

template <typename T>
void printV(vector<T>& v)
{
	for (auto& i : v)
		cout << i << " ";
	cout << endl;
}

template <typename T>
void printVV(vector<vector<T> >& t)
{
	for (auto& i : t)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}

void test()
{
	Solution s;
	vector<vector<int> > v1 = { { 0, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 } };
	vector<vector<int> > v2 = s.highestPeak(v1);
	printVV<int>(v1);
	printVV<int>(v2);
}

int main(void)
{
	
	test();
}
