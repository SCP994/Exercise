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
	vector<vector<int> > vs = { {7},{3},{3, 9},{1, 2, 4, 5, 7, 11},{3},{3},{9},{3, 10, 8, 0},{7},{11, 6, 2},{7},{3, 9} };
	cout << s.shortestPathLength(vs) << endl;
}

int main(void)
{
	test();
}

