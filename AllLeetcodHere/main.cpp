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
	string currentState = "++++";
	cout << Solution().canWin_(currentState) << endl;
}

int main(void)
{
	test();
}

