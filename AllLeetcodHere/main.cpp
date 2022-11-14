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
	vector<vector<int> > matrix = { { 9, 9, 4 }, { 6, 6, 8}, { 2, 1, 1 } };
	cout << Solution().longestIncreasingPath(matrix) << endl;
}

int main(void)
{
	test();
}

