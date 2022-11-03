#include <iostream>
#include <vector>
#include "Solution03.h"
//#include "Notes.h"
using namespace std;

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
	vector<vector<int> > vv = { {1, 2},{4, 3} };
	std::cout << s.minCost(vv) << endl;
}

int main(void)
{
	test();
}

