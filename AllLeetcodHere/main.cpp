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
	vector<vector<int> > maze = { {0, 0, 1, 0, 0},{0, 0, 0, 0, 0},{0, 0, 0, 1, 0},{1, 1, 0, 1, 1},{0, 0, 0, 0, 0} };
	vector<int> start = { 0, 4 }, destination = { 4, 4 };
	cout << Solution().hasPath(maze, start, destination) << endl;
}

int main(void)
{
	test();
}

