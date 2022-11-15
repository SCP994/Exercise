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
	vector<vector<int> > grid = { { 1, 1 }, { 3, 4 } };
	cout << Solution().countPaths(grid) << endl;
}

int main(void)
{
	ull a = 859542476;
	int b = a % (ull)(10e9 + 7);
	cout << b << endl;
	test();
}

